/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKMapKit/HereSDKAnnotationStyle.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A style class for image annotation style, for styling annotations with
 a specified image.
 */
@interface HereSDKImageAnnotationStyle : HereSDKAnnotationStyle

/**
 Initializer for the image annotation style.

 @param image Image to be used for the annotation.

 @return An image annotation style with image.
 */
+ (instancetype)styleWithImage:(UIImage *)image;

/**
 Image used for displaying the HereSDKPointAnnotation object on the map
 */
@property (nonatomic) UIImage *image;

@end

NS_ASSUME_NONNULL_END
