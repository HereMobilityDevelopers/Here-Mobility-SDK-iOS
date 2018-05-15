/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An abstract class that represents an annotation object.
 You can create annotation objects to indicate a specific point on the map.
 */
@protocol HereSDKAnnotation <NSObject>

@required

/**
 The coordinate point of the annotation.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

@end

NS_ASSUME_NONNULL_END
