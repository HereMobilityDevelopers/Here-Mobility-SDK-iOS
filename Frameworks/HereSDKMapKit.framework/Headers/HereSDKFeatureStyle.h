/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An object that stores the style for map features
 */
@interface HereSDKFeatureStyle : NSObject <NSCopying>

/**
 Generates the feature style with the given color.

 @param color The fill color for the feature.

 @return A featureStyle object with set feature color.
 */
+ (instancetype)styleWithColor:(UIColor *)color;

/**
 Fill color of the feature
 */
@property (nonatomic) UIColor *color;

/**
 Feature outline color
 */
@property (nullable, nonatomic) UIColor *borderColor;

/**
 Width in points of the feature outline
 */
@property (nonatomic) NSUInteger borderWidth;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

