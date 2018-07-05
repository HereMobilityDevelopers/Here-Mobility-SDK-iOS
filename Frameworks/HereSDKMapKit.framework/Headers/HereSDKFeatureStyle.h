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
 Fill color of the feature. Default is `UIColor.blueColor`.
 */
@property (nonatomic) UIColor *color;

/**
 Feature outline color. Default is `nil`.
 */
@property (nullable, nonatomic) UIColor *borderColor;

/**
 Width in points of the feature outline. Default is `0`.
 */
@property (nonatomic) NSUInteger borderWidth;

@end

NS_ASSUME_NONNULL_END

