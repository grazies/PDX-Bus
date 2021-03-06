//
//  SimpleAnnotation.h
//  PDX Bus
//
//  Created by Andrew Wallace on 6/24/09.
//



/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


#import <UIKit/UIKit.h>
#import "MapPinColor.h"


@interface SimpleAnnotation : NSObject <MapPinColor> {
	NSString *_pinTitle;
	NSString *_pinSubtitle;
	MKPinAnnotationColor _pinColor;
	CLLocationCoordinate2D coord;
    UIColor *_pinTint;
    double _bearing;
    bool _hasBearing;
}

- (NSString *)title;
- (NSString *)subtitle;
- (MKPinAnnotationColor) getPinColor;
- (void)setCoord:(CLLocationCoordinate2D)value;
- (bool)showActionMenu;
- (void)setBearing:(double)bearing;

@property (nonatomic,retain) NSString *pinTitle;
@property (nonatomic,retain) NSString *pinSubtitle;
@property (nonatomic) MKPinAnnotationColor pinColor;
@property (nonatomic, retain) UIColor *pinTint;


@end
