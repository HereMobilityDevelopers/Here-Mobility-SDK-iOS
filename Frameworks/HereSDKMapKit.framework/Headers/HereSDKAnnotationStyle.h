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
 An abstract superclass for annotation styles. To not be used directly.
 Use either `HereSDKPointAnnotationStyle` or `HereSDKImageAnnotationStyle`
 */
@interface HereSDKAnnotationStyle : NSObject

/**
 Styling anchor type for HereSDKPointAnnotation
 */
@property (nonatomic) HereSDKAnnotationAnchor anchor;

/**
 Tint color for HereSDKPointAnnotation. Default is white.
 */
@property (nonatomic) UIColor *tintColor;

/**
 A boolean value if the point annotation should be rendered flat
 with the map, or always facing the camera. Default is `NO`.
 */
@property (nonatomic) BOOL flat;

/**
 Annotation offset in points in screen-space.

 An offset of {x:10, y:20} will move the annotation 10 points to the right
 and 20 points down on the screen, while an offset of {x:-10, y:-20} will
 move the annotation 10 points to the left and 20 points up on the screen.
 
 Default is {0, 0}.
 */
@property (nonatomic) CGPoint offset;

/**
 A boolean value if the annotatio is tappable. If set to true, when tapping
 the annotation on the mapView, the mapView:didTapAnnotation: delegate callback
 will be called with this annotation.

 Default is 'YES'.
 */
@property (nonatomic) BOOL interactive;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
