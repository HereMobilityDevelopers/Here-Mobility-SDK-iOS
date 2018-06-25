/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKMapKit/HereSDKMapFeature.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereSDKPolygon : HereSDKMapFeature

/**
 This function generates a polygon from the given point list.

 @param points An array of CLLocation objects (minimum 3 points)
 @return The HereSDKPolygon created from the given points, or `nil` if not enough
 points
 */
+ (nullable instancetype)polygonWithPoints:(NSArray<CLLocation *> *)points;

@end

NS_ASSUME_NONNULL_END
