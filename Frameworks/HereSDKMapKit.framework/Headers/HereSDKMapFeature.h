/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import <HereSDKMapKit/HereSDKFeatureStyle.h>
#import <HereSDKMapKit/HereSDKMapGeometry.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Abstract class, use instances of subclasses `HereSDKPolygon` and `HereSDKPolyline`
 */
@interface HereSDKMapFeature : NSObject <NSCopying>

/**
 Points that the feature consists of
 */
@property (nonatomic, readonly) NSArray<CLLocation *> *points;

/**
 The current style of the feature
 */
@property (nonatomic, readonly) HereSDKFeatureStyle *style;

/**
 Bounding box of the feature
 */
@property (nonatomic, readonly) HereSDKMapRect boundingBox;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
