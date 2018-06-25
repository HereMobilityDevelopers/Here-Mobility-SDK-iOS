//
/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import <HereSDKMapKit/HereSDKRouteManeuver.h>
#import <HereSDKMapKit/HereSDKPolyline.h>

/**
 Part of the route between two consecutive waypoints
 */
@interface HereSDKRouteLeg : NSObject

/**
 Polyline of the route leg
 */
@property (nonatomic, readonly) HereSDKPolyline *polyline;
/**
 Distance of the leg (in the units requested in HereSDKRouteRequest)
 */
@property (nonatomic, readonly) float distance;
/**
 Estimated travel time for the leg, in seconds
 */
@property (nonatomic, readonly) float travelTime;
/**
 Index of the first point of the leg in the route geometry
 */
@property (nonatomic, readonly) uint32_t firstPointIndex;
/**
 Index of the last point of the leg in the route's polyline
 */
@property (nonatomic, readonly) uint32_t lastPointIndex;
/**
 Maneuvers (turns, exits, etc.) in a leg of the route
 */
@property (nonatomic, readonly) NSArray<HereSDKRouteManeuver *> *maneuvers;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end
