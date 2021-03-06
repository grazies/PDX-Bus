//
//  RssView.m
//  PDX Bus
//
//  Created by Andrew Wallace on 4/4/10.



/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


#import "RssView.h"
#import "CellLabel.h"
#import "WebViewController.h"
#import "DebugLogging.h"

#define kGettingRss @"getting RSS feed"

@implementation RssView

@synthesize rssData = _rssData;
@synthesize rssUrl	= _rssUrl;

- (void)dealloc {
	self.rssData = nil;
	self.rssUrl = nil;
	[super dealloc];
}

#pragma mark Data fetchers

- (void)fetchRss:(id) arg
{	
	NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
	[self.backgroundTask.callbackWhenFetching backgroundStart:1 title:kGettingRss];
	
    self.rssData = [[[RssXML alloc] init] autorelease];
	[self.rssData startParsing:self.rssUrl];

    [self.backgroundTask.callbackWhenFetching backgroundCompleted:self];
	[pool release];
}


- (void) fetchRssInBackground:(id<BackgroundTaskProgress>) callback url:(NSString*)rssUrl
{
	self.rssUrl = rssUrl;
	self.backgroundTask.callbackWhenFetching = callback;
	
	[NSThread detachNewThreadSelector:@selector(fetchRss:) toTarget:self withObject:nil];
}

#pragma mark View methods

-(void)loadView
{
	[super loadView];
	self.title = self.rssData.title;
}

- (void)viewDidLoad {
	[super viewDidLoad];
}


- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
}

#pragma mark UI helpers

- (UILabel *)create_UITextView
{
	CGRect frame = CGRectMake(0.0, 0.0, 100.0, 100.0);
	
	UILabel *textView = [[[UILabel alloc] initWithFrame:frame] autorelease];
    textView.textColor = [UIColor blackColor];
    textView.font = [self getParagraphFont];
	//    textView.delegate = self;
	//	textView.editable = NO;
    textView.backgroundColor = [UIColor whiteColor];
	textView.lineBreakMode =   NSLineBreakByWordWrapping;
	textView.adjustsFontSizeToFitWidth = YES;
	textView.numberOfLines = 0;
	
	return textView;
}

#pragma mark Tableview methods

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section 
{
	return nil;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
	return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	if ([self.rssData safeItemCount] > 0)
	{
		return [self.rssData safeItemCount];
	}
	return 1;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
	if ([self.rssData safeItemCount] > 0)
	{
		RssLink *link = [self.rssData itemAtIndex:indexPath.row];
		
		return [link getTimeHeight:self.screenInfo.screenWidth] + 3 * VGAP +[self getTextHeight:link.title font:[self getParagraphFont]];
	}
	
	return [self getTextHeight:[self.rssData fullErrorMsg] font:[self getParagraphFont]];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath 
{
	if (indexPath.row < [self.rssData safeItemCount])
	{
		RssLink *link = [self.rssData itemAtIndex:indexPath.row];
	
		NSString *MyIdentifier = [link cellReuseIdentifier:[NSString stringWithFormat:@"RssLabel%f", [self getTextHeight:link.title 
																													font:[self getParagraphFont]]] 
													 width:self.screenInfo.screenWidth];
		
		UITableViewCell *cell = (UITableViewCell *)[tableView dequeueReusableCellWithIdentifier:MyIdentifier];
		if (cell == nil) {
			cell = [link tableviewCellWithReuseIdentifier:MyIdentifier width:self.screenInfo.screenWidth font:[self getParagraphFont]];
			
			cell.selectionStyle = UITableViewCellSelectionStyleBlue;
			cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
		}
		
		[link populateCell:cell];
		
		[cell setAccessibilityLabel:[link title]];
		
		return cell;
	}
	else {
		NSString *MyIdentifier = [NSString stringWithFormat:@"RssLabel"];
		
		CellLabel *cell = (CellLabel *)[tableView dequeueReusableCellWithIdentifier:MyIdentifier];
		if (cell == nil) {
			cell = [[[CellLabel alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:MyIdentifier] autorelease];
			cell.view = [self create_UITextView];
		}
		
		((UILabel*)cell.view).text = [self.rssData fullErrorMsg];
		
		cell.selectionStyle = UITableViewCellSelectionStyleBlue;
		
		if ([self.rssData gotData])
		{
			cell.accessoryType = UITableViewCellAccessoryNone;
		}
		else {
			cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
		}
		return cell;
	}
	return nil;

}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
	
	if (indexPath.row < [self.rssData safeItemCount])
	{
        WebViewController *webPage = [[WebViewController alloc] init];
        RssLink *link = [self.rssData itemAtIndex:indexPath.row];
        if (self.gotoOriginalArticle)
        {
            [webPage setURLmobile:link.link full:link.link];
        }
        else
        {
            [webPage setRssItem:link title:self.rssData.title];
            webPage.rssLinks = self.rssData.itemArray;
            webPage.rssLinkItem = indexPath.row;
        }
		[webPage displayPage:[self navigationController] animated:YES itemToDeselect:self];
		[webPage release];
	}
	else if (![self.rssData gotData])
	{
		[self networkTips:nil networkError:self.rssData.errorMsg];
        [self clearSelection];
	}
}



@end
