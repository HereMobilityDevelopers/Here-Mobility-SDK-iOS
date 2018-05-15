//
/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 A point is the route geometry construct. Represents a point position.
 */
@interface HereSDKRoutePoint : NSObject

/**
 Latitude in decimal degrees
 */
@property (nonatomic) double latitude;

/**
 Longitude in decimal degrees
 */
@property (nonatomic) double longitude;

/**
 Indicates the vertical stacking of points that reside at the same latitude and longitude. Optional.
 */
@property (nonatomic) int32_t zLevel;

/**
 Elevation in meters above sea-level.  Optional.
 */
@property (nonatomic) double  elevation;

@end
