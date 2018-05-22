/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKMapKit/HereSDKAnnotation.h>

/**
 An annotation that persists with user location on HereSDKMapView
 */
@interface HereSDKUserLocationAnnotation : NSObject <HereSDKAnnotation>

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end
