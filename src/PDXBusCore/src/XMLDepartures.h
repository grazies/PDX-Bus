//
//  XMLDepartures.h
//  TriMetTimes
//



/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


#import "TriMetXML.h"
#import "DepartureTrip.h"
#import "StopDistanceData.h"
// #import <MapKit/MkAnnotation.h>
// #import "MapPinColor.h"
#import "DepartureTimesDataProvider.h"
#import "XMLStreetcarPredictions.h"

@class DepartureTimes;
@class DepartureData;


@interface XMLDepartures : TriMetXML {
	DepartureData *_currentDepartureObject;
	DepartureTrip *_currentTrip;
    
	TriMetTime	_queryTime;

	NSString *_locDesc;
	NSString *_locLat;
	NSString *_locLng;
	NSString *_locid;
	NSString *_locDir;
	NSString *_blockFilter;
	NSString *_sectionTitle;
	
	StopDistanceData *_distance;
    NSMutableData *_streetcarData;
    bool _firstOnly;
}

@property (nonatomic, retain) StopDistanceData *distance;
@property (nonatomic, retain) NSString *locDesc;
@property (nonatomic, retain) NSString *locid;
@property (nonatomic, retain) CLLocation *loc;
@property (nonatomic, retain) NSString *locDir;
@property (nonatomic, retain) NSString *blockFilter;
@property (nonatomic, retain) NSString *sectionTitle;
@property (nonatomic)         TriMetTime queryTime;
@property (nonatomic, retain) DepartureData *currentDepartureObject;
@property (nonatomic, retain) DepartureTrip *currentTrip;
@property (nonatomic, retain) NSMutableData *streetcarData;
@property (nonatomic)         bool firstOnly;


- (BOOL)getDeparturesForLocation:(NSString *)location;
- (BOOL)getDeparturesForLocation:(NSString *)location block:(NSString*)block;
- (void)reload;
+ (void)clearCache;

@end
