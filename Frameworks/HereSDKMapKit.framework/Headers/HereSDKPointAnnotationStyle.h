/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKMapKit/HereSDKAnnotationStyle.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A style class for point annotation style, for styling annotations with
 a colored circle.
 */
@interface HereSDKPointAnnotationStyle : HereSDKAnnotationStyle

/**
 Initializer for the point annotation style.

 @param radius Radius of the annotation circle in points.

 @return A point annotation style with set radius.
 */
+ (instancetype)styleWithRadius:(CGFloat)radius;

/**
 Radius of the point annotation in points.
 */
@property (nonatomic) CGFloat radius;

/**
 Point annotaion outline color. Default is `nil`.
 */
@property (nullable, nonatomic) UIColor *borderColor;

/**
 Width in points of the point annotation outline. Default is `0`.
 */
@property (nonatomic) NSUInteger borderWidth;

@end

NS_ASSUME_NONNULL_END
