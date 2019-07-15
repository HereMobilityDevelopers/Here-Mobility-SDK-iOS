/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKMapKit/HereSDKPolyline.h>
#import <HereSDKMapKit/HereSDKRouteLeg.h>
#import <HereSDKMapKit/HereSDKRoutePoint.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A response to a routeRequest
 */
@interface HereSDKRoute : NSObject
/**
 Polyline of the entire route
 */
@property (nonatomic, readonly) HereSDKPolyline *polyline;
/**
 Geometry points of the route
 */
@property (nonatomic, readonly) NSArray<HereSDKRoutePoint *> *points;
/**
 Legs of the route
 */
@property (nonatomic, readonly) NSArray<HereSDKRouteLeg *> *routeLegs;
/**
 Distance of the entire route (in the units requested in HereSDKRouteRequest)
 */
@property (nonatomic, readonly) float distance;
/**
 Estimated travel time for the entire route, in seconds
 */
@property (nonatomic, readonly) float travelTime;
/**
 BCP47 compliant language code to use for text instructions. An error is returned if there are no matching supported languages. Optional; defaults to en-us.
 */
@property (nonatomic, readonly) NSString *language;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

