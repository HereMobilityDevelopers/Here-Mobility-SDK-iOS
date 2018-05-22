/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An object that stores color and width values
 */
@interface HereSDKFeatureStyle : NSObject <NSCopying>

/**
 Color of HereSDKFeatureStyle
 */
@property (nonatomic) UIColor *color;
/**
 Width n points of HereSDKFeatureStyle (the width with which the feature image will be displayed)
 */
@property (nonatomic) NSInteger width;

/**
 Initializes and returns HereSDKFeatureStyle

 @param width The width value of HereSDKFeatureStyle object
 @param color The color value of HereSDKFeatureStyle object
 @return The HereSDKFeatureStyle object
 */
- (instancetype)initWithWidth:(NSInteger)width color:(UIColor *)color NS_DESIGNATED_INITIALIZER;
/**
 Initializes and returns HereSDKFeatureStyle

 @param width The width value of HereSDKFeatureStyle object
 @param color The color value of HereSDKFeatureStyle object
 @return The HereSDKFeatureStyle object
 */
+ (instancetype)styleWithWidth:(NSInteger)width color:(UIColor *)color;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

