#define MAXCOLORS 1

//
//  AllRailStationView.h
//  PDX Bus
//
//  Created by Andrew Wallace on 10/5/10.
//  Copyright 2010. All rights reserved.
//



/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */



#import <Foundation/Foundation.h>
#import "TableViewWithToolbar.h"
#import "ReturnStopId.h"
#import "Stop.h"
#import "Hotspot.h"


#define kSearchItemStation  @"org.teleportaloo.pdxbus.station"

@interface AllRailStationView : TableViewWithToolbar <ReturnStop> {
	HOTSPOT *_hotSpots;
}

- (void)generateArrays;
+ (RAILLINES)railLines:(int)index;
- (void)indexStations;

@end
