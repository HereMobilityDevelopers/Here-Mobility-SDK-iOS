/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKMapKit/HereSDKAnnotation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Class that defines the basic properties for all shape-based objects.
 */
@interface HereSDKShape : NSObject <HereSDKAnnotation>

/**
 The coordinate point of the annotation.
 */
@property (nonatomic) CLLocationCoordinate2D coordinate;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
