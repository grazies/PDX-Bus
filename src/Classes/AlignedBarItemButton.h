//
//  AlignedBarItemButton.h
//  PDX Bus
//
//  Created by Andrew Wallace on 2/1/14.
//  Copyright (c) 2014 Teleportaloo. All rights reserved.
//



/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


#import <UIKit/UIKit.h>

@interface AlignedBarItemButton : UIButton
{
    bool _right;
}

+ (bool)iOS7;
+ (UIButton*)suitableButtonRight:(bool)right;

@property (nonatomic) bool right;
@end
