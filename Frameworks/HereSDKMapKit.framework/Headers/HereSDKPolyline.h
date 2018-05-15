/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import <HereSDKMapKit/HereSDKFeatureStyle.h>
#import <HereSDKMapKit/HereSDKMapGeometry.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Geometric shape of continuous line composed of one or more line segments
 */
@interface HereSDKPolyline : NSObject <NSCopying>

/**
 Points that the polyline consists of
 */
@property (nonatomic, readonly) NSArray<CLLocation *> *points;

/**
 To set this property, use addPolyline:withStyle on MapView.
 */
@property (nonatomic, readonly) HereSDKFeatureStyle *style;

/**
 Bounding box of the polyline
 */
@property (nonatomic, readonly) HereSDKMapRect boundingBox;

/**
 This function generates a polyline from the given point list.

 @param points An array of CLLocation objects
 @return The HereSDKPolyline created from the given points
 */
+ (instancetype)polylineWithPoints:(NSArray<CLLocation *> *)points;

/**
 This function generates a polyline from the given point list.

 @param points An array of CLLocation objects
 @return The HereSDKPolyline created from the given points
 */
- (instancetype)initWithPoints:(NSArray<CLLocation * > *)points NS_DESIGNATED_INITIALIZER;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
