/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Options for the location of the HereSDKAnnotationAnchor.
 (The image anchor is the point on the annotation image that is placed over the location coordinates on the map.)
 */
typedef NS_ENUM(NSInteger, HereSDKAnnotationAnchor) {
    /** The styling will be anchor center. */
    HereSDKAnnotationAnchorCenter = 0,
    /** The styling will be anchor top. */
    HereSDKAnnotationAnchorTop,
    /** The styling will be anchor bottom. */
    HereSDKAnnotationAnchorBottom,
    /** The styling will be anchor left. */
    HereSDKAnnotationAnchorLeft,
    /** The styling will be anchor right. */
    HereSDKAnnotationAnchorRight,
    /** The styling will be anchor top left. */
    HereSDKAnnotationAnchorTopLeft,
    /** The styling will be anchor top right. */
    HereSDKAnnotationAnchorTopRight,
    /** The styling will be anchor bottom left. */
    HereSDKAnnotationAnchorBottomLeft,
    /** The styling will be anchor bottom right. */
    HereSDKAnnotationAnchorBottomRight
};

/**
 An object used to style HereSDKPointAnnotation
 */
@interface HereSDKPointAnnotationStyle : NSObject

/**
 Image used for displaying the HereSDKPointAnnotation object on the map
 */
@property (nonatomic) UIImage *image;

/**
 Styling anchor type for HereSDKPointAnnotation
 */
@property (nonatomic) HereSDKAnnotationAnchor anchor;

/**
 Returns HereSDKPointAnnotationStyle used for styling HereSDKPointAnnotation

 @param image The image to use for displaying the annotation on the map
 @param anchor The anchor type
 @return HereSDKPointAnnotationStyle
 */
- (instancetype)initWithImage:(UIImage *)image anchor:(HereSDKAnnotationAnchor)anchor NS_DESIGNATED_INITIALIZER;

/**
 Returns HereSDKPointAnnotationStyle used for styling HereSDKPointAnnotation

 @param image The image to use for displaying the annotation on the map
 @return HereSDKPointAnnotationStyle
 */
+ (instancetype)styleWithImage:(UIImage *)image;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
