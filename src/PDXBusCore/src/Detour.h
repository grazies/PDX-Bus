//
//  Detour.h
//  PDX Bus
//



/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


#import <UIKit/UIKit.h>

#define kDetourCellHeight 170.0

@interface Detour : NSObject {
	NSString *_routeDesc;
	NSString *_detourDesc;
	NSString *_route;
}

+ (UILabel *)create_UITextView:(UIFont*)font;

@property (nonatomic,retain) NSString *routeDesc;
@property (nonatomic,retain) NSString *detourDesc;
@property (nonatomic,retain) NSString *route;

@end
