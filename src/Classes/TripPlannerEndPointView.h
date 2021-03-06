//
//  TripPlannerEndPoint.h
//  PDX Bus
//
//  Created by Andrew Wallace on 6/27/09.
//



/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


#import <UIKit/UIKit.h>
#import "TableViewWithToolbar.h"
#import "XMLTrips.h"
#import "EditableTableViewCell.h"
#import "ReturnStopId.h"
#import <AddressBookUI/ABPeoplePickerNavigationController.h>
#import "CellTextField.h"
#import "CellTextView.h"
#import "TripReturnUserRequest.h"
#import "TripPlannerBaseView.h"


@interface TripPlannerEndPointView: TripPlannerBaseView <EditableTableViewCellDelegate, ReturnStopId, ABPeoplePickerNavigationControllerDelegate> {
	
	bool                _from;
	UITextField *       _placeNameField;
	bool                keyboardUp;
	CellTextField *     _editCell;
	UIViewController *  _popBackTo;
	
}

@property (nonatomic) bool from;
@property (nonatomic, retain) UITextField *placeNameField;
@property (nonatomic, retain) CellTextField *editCell;
@property (nonatomic, retain) UIViewController *popBackTo;


- (UITextField *)createTextField_Rounded;
- (void)cellDidEndEditing:(EditableTableViewCell *)cell;
- (void) browseForStop;
- (void) selectFromRailMap;
- (void) selectedStop:(NSString *)stopId;
- (UIViewController*) getController;
- (void)gotPlace:(NSString *)place setUiText:(bool)setText additionalInfo:(NSString *)info;
- (void)cancelAction:(id)sender;
- (TripEndPoint *)endPoint;
- (void)initEndPoint;
- (void)nextScreen;
- (void)initTakMeHome:(TripUserRequest *)req;


@end
