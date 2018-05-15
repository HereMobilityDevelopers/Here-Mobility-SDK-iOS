/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <CoreLocation/CLLocation.h>
#import <HereSDKMapKit/HereSDKShape.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An annotation object tied to the specified point on the map.
 */
@interface HereSDKPointAnnotation : HereSDKShape

/**
 Creates a new HereSDKPointAnnotation instance with the given coordinates.

 @param coordinate The origin coordinates of the display object.

 @return A new HereSDKPointAnnotation object.
 */
- (instancetype)initWithCoordinate:(CLLocationCoordinate2D)coordinate NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
