//
/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 The type of transport to to use en route

 - HereSDKRouteProfileCar: Car transport
 */
typedef NS_ENUM(NSInteger, HereSDKRouteProfile) {
    HereSDKRouteProfileCar,
};

/**
 The route measurement units
 */
typedef NS_ENUM(NSInteger, HereSDKRouteMeasurementType) {
    /** Measurement type: metric (kilometers, meters) */
    HereSDKRouteMeasurementTypeMetric,
    /** Measurement type: imperial (miles, feet) */
    HereSDKRouteMeasurementTypeImperial,
};

NS_ASSUME_NONNULL_BEGIN

/**
 Route Request
 */
@interface HereSDKRouteRequest : NSObject <NSCopying>

/**
 An array of points used for the route request

 points.firstObject = route start
 points.lastObject = route end
 */
@property (nonatomic, readonly) NSArray<CLLocation *> * points;

/**
 A Boolean flag indicating whether multiple routes should be produced for the route request if available.

 Default is `NO`.
 */
@property (nonatomic) BOOL requestAlternativeRoutes;
/**
 The type of transport to which the route should apply

 Default is HereSDKRouteProfileCar.
 */
@property (nonatomic) HereSDKRouteProfile routeProfile;
/**
 The route measurement units (Metric or Imperial)

 Default is HereSDKRouteMeasurementTypeMetric.
 */
@property (nonatomic) HereSDKRouteMeasurementType routeMeasurementType;

/**
 BCP47 language code to use for text instructions. An error is returned if there are no matching supported languages. Optional; defaults to en-us.
 */
@property(nonatomic, nullable) NSString *language;

/**
 Return the route request object that contains at least two locations (the start and end points) of the route. This parameter must not be nil.
 @param points which contain the location of the route
 @return A new HereSDKRouteRequest object or `nil`, if points parameter is invalid.
 */
- (nullable instancetype)initWithPoints:(NSArray<CLLocation *> *)points;

/**
 Return the route request object that contains the start destination and end destination of the route. Those parameters must not be nil.

 @param start start destination
 @param end end destination
 @return A new HereSDKRouteRequest object
 */
- (instancetype)initWithStart:(CLLocation *)start andEnd:(CLLocation *)end;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
