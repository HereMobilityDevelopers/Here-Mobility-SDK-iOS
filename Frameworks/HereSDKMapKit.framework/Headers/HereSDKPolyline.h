/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKMapKit/HereSDKMapFeature.h>
#import <HereSDKMapKit/HereSDKPolylineStyle.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Geometric shape of continuous line composed of one or more line segments
 */
@interface HereSDKPolyline : HereSDKMapFeature

/**
 This function generates a polyline from the given point list.

 @param points An array of CLLocation objects
 @return The HereSDKPolyline created from the given points
 */
+ (instancetype)polylineWithPoints:(NSArray<CLLocation *> *)points;

@end

NS_ASSUME_NONNULL_END
