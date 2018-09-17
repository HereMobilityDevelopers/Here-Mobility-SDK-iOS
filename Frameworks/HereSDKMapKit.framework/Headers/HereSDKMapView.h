/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <HereSDKMapKit/HereSDKPolyline.h>
#import <HereSDKMapKit/HereSDKPolygon.h>
#import <HereSDKMapKit/HereSDKMapGeometry.h>

@protocol HereSDKAnnotation;

NS_ASSUME_NONNULL_BEGIN

@class HereSDKMapView;
@class HereSDKAnnotationStyle;
@class HereSDKUserLocationAnnotation;

/**
 Protocol for receiving map view updates.
 */
@protocol HereSDKMapViewDelegate <NSObject>
@optional

/**
 Update that mapview finished loading (its definition)

 @param mapView mapview that finished loading
 */
- (void)mapViewDidFinishLoadingMap:(HereSDKMapView *)mapView;

/**
 Return annotation style for specific annotation

 @param mapView mapview that has annotation
 @param annotation annotation to style
 @return annotation style
 */
- (nullable HereSDKAnnotationStyle *)mapView:(HereSDKMapView *)mapView styleForAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 Update that user location was updated on mapview

 @param mapView mapview that present user location
 @param userLocationAnnotation userLocationAnnotation that has been updated
 */
- (void)mapView:(HereSDKMapView *)mapView didUpdateUserLocationAnnotation:(HereSDKUserLocationAnnotation *)userLocationAnnotation;

/**
 Update that mapview recognized a long press gesture

 @param mapView mapview that recognized the long press gesture
 @param location CLLocation of the gesture 
 */
- (void)mapView:(HereSDKMapView *)mapView didRecognizeLongPressGestureForLocation:(CLLocation *)location;

/**
 Update that mapview recognized a tap gesture

 @param mapView mapview that recognized the tap gesture
 @param location CLLocation of the gesture
 */
- (void)mapView:(HereSDKMapView *)mapView didTapLocation:(CLLocation *)location;

/**
 Tells the receiver an annotation was tapped

 @param mapView mapview that has annotation
 @param annotation annotation that was tapped
 */
- (void)mapView:(HereSDKMapView *)mapView didTapAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 Tells the receiver an annotation was long tapped

 @param mapView mapview that has annotation
 @param annotation annotation that was long tapped
 */
- (void)mapView:(HereSDKMapView *)mapView didLongTapAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 Returns a Boolean value indicating whether the annotation is able to display extra information in a callout bubble.

 This method is called after an annotation is selected, before any callout is displayed for the annotation.

 If the return value is `YES`, a callout view is shown when the user taps on an annotation, selecting it. The default callout displays the annotation’s `title` and `subtitle`. You can customize the callout’s contents by implementing the -`mapView:calloutViewForAnnotation:` method.

 If the return value is `NO`, or if this method is absent from the delegate, or if the annotation lacks a title or subtitle or the `mapView:calloutViewForAnnotation:` is absent from the delegate or returns `nil`, the annotation will not show a callout even when selected.
 */
- (BOOL)mapView:(HereSDKMapView *)mapView annotationCanShowCallout:(id<HereSDKAnnotation>)annotation;

/**
 Returns a callout view to display for the given annotation.

 If this method is present in the delegate, it must return a new instance of a view dedicated to display the callout. The returned view will be configured by the map view.

 If this method is absent from the delegate, or if it returns `nil`, a standard, two-line, bubble-like callout view is displayed by default.
 */
- (nullable UIView *)mapView:(HereSDKMapView *)mapView calloutViewForAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 Tells the receiver an annotation was selected and presented its view on the map

 @param mapView mapview that has annotation
 @param annotation annotation that was selected
 */
- (void)mapView:(HereSDKMapView *)mapView didSelectAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 Tells the receiver an annotation was deselected and its view on the map was hidden

 @param mapView mapview that has annotation
 @param annotation annotation that was deselected
 */
- (void)mapView:(HereSDKMapView *)mapView didDeselectAnnotation:(id<HereSDKAnnotation>)annotation;

@end

/**
 Position of the compass indicator in the map view.
 */
typedef NS_ENUM (NSUInteger, HereSDKMapCompassPosition) {
    /** Compass position in the top right corner of the view */
    HereSDKMapCompassPositionTopRight = 0,
    /** Compass position in the top left corner of the view */
    HereSDKMapCompassPositionTopLeft,
    /** Compass position in the bottom left corner of the view */
    HereSDKMapCompassPositionBottomLeft,
    /** Compass position in the bottom right corner of the view */
    HereSDKMapCompassPositionBottomRight
};

/**
 Visibility of the compass indicator in the map view.
 */
typedef NS_ENUM (NSUInteger, HereSDKMapCompassVisibility) {
    /** Compass indicator is visible when the mapView's rotation
     changes from North (0) */
    HereSDKMapCompassVisibilityWhenRotated = 0,
    /** Compass indicator is always visible */
    HereSDKMapCompassVisibilityAlways,
    /** Compass indicator is never visible */
    HereSDKMapCompassVisibilityNone
};

/**
 * A UIView subclass for displaying a geographical map
 */
@interface HereSDKMapView : UIView

/**
 The geographic coordinates at the center of the map view.

 Changing the value of this property centers the map on the new coordinates
 without changing the current zoom level.

 Changing the value of this property updates the map view immediately.
 To change the view with a gradual animation, use the `-setCenterCoordinate:animated:` method instead.
 */
@property (nonatomic) CLLocationCoordinate2D centerCoordinate;

/**
 Changes the center coordinate of the map and optionally animates the change.

 Changing the center coordinate centers the map on the new coordinate without
 changing the current zoom level.

 @param coordinate The new center coordinate for the map.
 @param animated Specify `YES` if you want the map view to scroll to the new
 location, or `NO` if you want the map to display the new location immediately.
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;

/**
 The zoom level of the map view.

 Zoom levels range from 0 (farthest camera) to 21 (closest camera)
 Changing the value of this property changes the zoom level of the map without changing the center coordinate.

 Changing the value of this property updates the map view immediately.
 To animate the change in zoom, use the `-setZoom:animated:` method instead.
 */
@property (nonatomic) float zoom;

/**
 Changes the zoom level of the map and optionally animates the change.

 Changes the zoom level of the map without changing the center coordinate.

 @param zoom The new zoom level for the map.
 @param animated Specify `YES` if you want the map view animate to the new zoom level,
 or `NO` if you want the map to display the new zoom level immediately.
 */
- (void)setZoom:(float)zoom animated:(BOOL)animated;

/**
 The rotation of the map, measured in radians clockwise from true north.

 The value `0` means that the top edge of the map view corresponds to true north.

 Changing the value of this property updates the map view immediately.
 To animate the change, use the `-setRotation:animated:` method instead.
 */
@property (nonatomic) float rotation;

/**
 Changes the rotation of the map and optionally animates the change.

 @param rotation The rotation of the map, measured in radians clockwise from true north.
 @param animated Specify `YES` to animate the change to the new rotation,
 or `NO` to display the new rotation immediately.
 */
- (void)setRotation:(float)rotation animated:(BOOL)animated;

/**
 The max tilt angle of the map "camera", measured in radians. Default is 1.309 radians (75 degrees).

 Changing the value of the property limits user interaction for tilt. If the current
 map tilt exceeds the new `maxTilt`, the map tilt is adjusted immediately.
 To animate the change, use the `-setMaxTilt:animated:` method instead.
 */
@property (nonatomic) float maxTilt;

/**
 Changes the maximum tilt angle of the map "camera", measured in radians.

 @param maxTilt The maximum tilt angle of the map camera, measured in radians. Will be clamped between
 0 and 90 degrees (1.5708 radians)
 @param animated Specify `YES`, if the map should animate to an adjusted tilt after setting a smaller `maxTilt`
 than the current tilt angle of the map
 */
- (void)setMaxTilt:(float)maxTilt animated:(BOOL)animated;

/**
 The tilt angle of the map "camera", measured in radians from the 0 direction (0 direction = camera is facing the ground).

 Changing the value of this property updates the map view immediately.
 To animate the change, use the `-setTilt:animated:` method instead.

 Can not exceed `maxTilt`.
 */
@property (nonatomic) float tilt;

/**
 Changes the tilt angle of the map "camera", and optionally animates the change.

 @param tilt The tilt angle of the map camera, measured in radians. Can not exceed `maxTilt`.

 @param animated Specify `YES` to animate to the change to the new tilt angle,
 or `NO` to display the new tilt angle immediately.
 */
- (void)setTilt:(float)tilt animated:(BOOL)animated;

/**
 A Boolean value that determines whether the user may zoom the map in and
 out, changing the zoom level.

 When this property is set to `YES` (the default) the user may zoom the map
 in and out by pinching two fingers or by double tapping (tapping with two fingers).

 This property controls only user interactions with the map.
 If the property is set to `NO`, you can still change the map zoom programmatically.
 */
@property (nonatomic, getter=isZoomEnabled) IBInspectable BOOL zoomEnabled;

/**
 A Boolean value that determines whether the user may tilt the map back and forth, changing the tilt level.

 When this property is set to `YES` (the default) the user may tilt the map
 back and forth by draging with two fingers.

 This property controls only user interactions with the map.
 If the property is set to `NO`, you can still change the map tilt programmatically.
 */
@property (nonatomic, getter=isTiltEnabled) IBInspectable BOOL tiltEnabled;

/**
 A Boolean value that determines whether the user may rotate the map, changing the rotation level.

 When this property is set to `YES` (the default) the user may rotate the map
 by rotating with two fingers.

 This property controls only user interactions with the map.
 If the property is set to `NO`, you can still change the map rotation programmatically.
 */
@property (nonatomic, getter=isRotationEnabled) IBInspectable BOOL rotationEnabled;

/**
 A Boolean value that determines whether the user may drag/scroll the map, changing the map region.

 When this property is set to `YES` (the default) the user may scroll the map
 by dragging/swiping with one finger.

 This property controls only user interactions with the map.
 If the property is set to `NO`, you can still change the map position programmatically.
 */
@property (nonatomic, getter=isScrollEnabled) IBInspectable BOOL scrollEnabled;

/**
 The receiver’s delegate, for handling map view changes.

 A map view sends messages to its delegate to notify it of changes to its contents.
 */
@property (nonatomic, weak, nullable) id<HereSDKMapViewDelegate> delegate;


@property (nonatomic, readonly) NSArray<HereSDKPolyline *>* polylines;

- (void)addPolyline:(HereSDKPolyline *)polyline;
- (void)addPolyline:(HereSDKPolyline *)polyline withStyle:(HereSDKPolylineStyle *)style;
- (void)removePolyline:(HereSDKPolyline *)polyline;
- (void)removePolylines:(NSArray<HereSDKPolyline *> *)polylines;


@property (nonatomic, readonly) NSArray<HereSDKPolygon *>* polygons;

- (void)addPolygon:(HereSDKPolygon *)polygon;
- (void)addPolygon:(HereSDKPolygon *)polygon withStyle:(HereSDKFeatureStyle *)style;
- (void)removePolygon:(HereSDKPolygon *)polygon;
- (void)removePolygons:(NSArray<HereSDKPolygon *> *)polygons;

/**
 Changes the receiver’s viewport to fit the given coordinate bounds,
 optionally animating the change.

 @param mapRect The bounds that the viewport will show in its entirety.
 @param animated Specify `YES` to animate the change by smoothly scrolling and zooming,
 or `NO` to immediately display the given bounds.

 @return `YES`, if coordinate bounds are valid and can be set.
 Otherwise returns `NO`. The method returns immediately.
 */
- (BOOL)setVisibleMapRect:(HereSDKMapRect)mapRect animated:(BOOL)animated;

/**
 Changes the receiver’s viewport to fit the given coordinate bounds with
 additional padding on each side, optionally animating the change.

 @param mapRect The bounds that the viewport will show in its entirety.
 @param insets The minimum padding (in screen points) that will be visible around the given coordinate bounds.
 @param animated Specify `YES` to animate the change by smoothly scrolling and zooming,
 or `NO` to immediately display the given bounds.

 @return `YES`, if coordinate bounds are valid and can be set.
 Otherwise returns `NO`. The method returns immediately.
 */
- (BOOL)setVisibleMapRect:(HereSDKMapRect)mapRect edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated;

/**
 Annotations array that allows you to add your content with specific map locations.
 */
@property (nonatomic, readonly) NSArray<id<HereSDKAnnotation>> *annotations;

/**
 Adds the specified annotation to the map view

 @param annotation Annotation to be added to the annotations array
 */
- (void)addAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 Removes the specified annotation from the map view.

 @param annotation Annotation to be removed from the annotations array
 */
- (void)removeAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 A set of currently selected annotations;
 */
@property (nonatomic, readonly) NSSet<id<HereSDKAnnotation>> *selectedAnnotations;

/**
 Selects the specified annotation and displays a selected view for it.

 If the annotation doesn't provide a title or subtitle or the mapView's delegate
 does not provide a `selectedViewForAnnotation`, this method does nothing.

 @param annotation Annotation to be selected
 */
- (void)selectAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 Deselects the specified annotation and hides the selected view for it. If the
 annotation is currently not selected, this method does nothing.

 @param annotation Annotation to be deselected
 */
- (void)deselectAnnotation:(id<HereSDKAnnotation>)annotation;

/**
 Annotation that represents the user location on map. `nil` if not present.
 */
@property (nullable, nonatomic, readonly) HereSDKUserLocationAnnotation *userLocationAnnotation;

/**
 Shows or hides the user location on the map.

 @param shouldShowUserLocation Boolean value that indicates whether the map should try to display the user’s location.
 */
- (void)showUserLocation:(BOOL)shouldShowUserLocation;

/**
 Setting this value, changes the visibility of the compass indicator in the map view.
 Default is `HereSDKMapCompassVisibiltyWhenRotated`.
 */
@property (nonatomic) HereSDKMapCompassVisibility compassVisibilty;

/**
 Setting this value, adjusts the position of the compass indicator in the map view.
 Default is `HereSDKMapCompassPositionTopRight`.
 */
@property (nonatomic) HereSDKMapCompassPosition compassPosition;

/**
 Setting this value, updates the compass indicator with a custom image.

 @param compassImage The image for the compass indicator. If this value is `nil`,
 the compass will use the standard compass image.

 @Note: to remove the compass, use the `compassVisibility` property.
 */
- (void)setCompassImage:(nullable UIImage *)compassImage;

/**
 Adjusts the inset of map accessory views (like the compass indicator view).
 */
@property (nonatomic) UIEdgeInsets contentInsets;

@end


//
// MARK: Parametrized animation methods extension
//

/**
 Animation curve type to be used when animating map properties
 */
typedef NS_ENUM(NSUInteger, HereSDKMapAnimationCurve) {
    /** Linear animation ease type */
    HereSDKMapAnimationCurveLinear = 0,
    /** Cube animation ease type */
    HereSDKMapAnimationCurveCubic,
    /** Quint animation ease type */
    HereSDKMapAnimationCurveQuint,
    /** Sine animation ease type */
    HereSDKMapAnimationCurveSine,
};

/**
 * A category for more granular animation control
 */
@interface HereSDKMapView (Animations)

// centerCoordinate

/**
 Changes the center coordinate of the map with the specified duration and `HereSDKAnimationCurveCubic` animation type.

 Changing the center coordinate centers the map on the new coordinate without
 changing the current zoom level.

 @param coordinate The new center coordinate for the map.
 @param duration The time interval/duration of the animation.
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate
               withDuration:(NSTimeInterval)duration;

/**
 Changes the center coordinate of the map with the specified duration and animation
 type.

 Changing the center coordinate centers the map on the new coordinate without
 changing the current zoom level.

 @param coordinate The new center coordinate for the map.
 @param duration The time interval/duration of the animation.
 @param animationCurve The animation type for the change. Defines the animation curve
 and ease type for the change.
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate
               withDuration:(NSTimeInterval)duration
             animationCurve:(HereSDKMapAnimationCurve)animationCurve;

// zoom

/**
 Changes the zoom level of the map with the specified duration and `HereSDKAnimationCurveCubic` animation type.

 Changes the zoom level of the map without changing the center coordinate.

 @param zoom The new zoom level for the map.
 @param duration The time interval/duration of the animation.
 */
- (void)setZoom:(float)zoom
   withDuration:(NSTimeInterval)duration;

/**
 Changes the zoom level of the map with the specified duration and animation
 type.

 Changes the zoom level of the map without changing the center coordinate.

 @param zoom The new zoom level for the map.
 @param duration The time interval/duration of the animation.
 @param animationCurve The animation type for the change. Defines the animation curve
 and ease type for the change.
 */
- (void)setZoom:(float)zoom
   withDuration:(NSTimeInterval)duration
 animationCurve:(HereSDKMapAnimationCurve)animationCurve;

// rotation

/**
 Changes the rotation of the map with the specified duration and `HereSDKAnimationCurveCubic` animation type.

 Changes the rotation of the map without changing the center coordinate.

 @param rotation The rotation of the map, measured in radians clockwise from true north.
 @param duration The time interval/duration of the animation.
 */
- (void)setRotation:(float)rotation
       withDuration:(NSTimeInterval)duration;

/**
 Changes the rotation of the map with the specified duration and animation
 type.

 Changes the rotation of the map without changing the center coordinate.

 @param rotation The rotation of the map, measured in radians clockwise from true north.
 @param duration The time interval/duration of the animation.
 @param animationCurve The animation type for the change. Defines the animation curve
 and ease type for the change.
 */
- (void)setRotation:(float)rotation
       withDuration:(NSTimeInterval)duration
     animationCurve:(HereSDKMapAnimationCurve)animationCurve;

// tilt

/**
 Changes the tilt angle of the map "camera" with the specified duration and `HereSDKAnimationCurveCubic` animation type.

 Changes the rotation of the map without changing the center coordinate.

 @param tilt The tilt angle of the map camera, measured in radians. Can not exceed `maxTilt`.
 @param duration The time interval/duration of the animation.
 */
- (void)setTilt:(float)tilt
   withDuration:(NSTimeInterval)duration;

/**
 Changes the tilt angle of the map "camera" with the specified duration and animation
 type.

 Changes the rotation of the map without changing the center coordinate.

 @param tilt The tilt angle of the map camera, measured in radians. Can not exceed `maxTilt`.
 @param duration The time interval/duration of the animation.
 @param animationCurve The animation type for the change. Defines the animation curve
 and ease type for the change.
 */
- (void)setTilt:(float)tilt
   withDuration:(NSTimeInterval)duration
 animationCurve:(HereSDKMapAnimationCurve)animationCurve;

// mapRect

/**
 Changes the receiver’s viewport to fit the given coordinate bounds with
 additional padding on each side with the specified duration and `HereSDKAnimationCurveCubic` animation type.

 @param mapRect The bounds that the viewport will show in its entirety.
 @param insets The minimum padding (in screen points) that will be visible around the given coordinate bounds.
 @param duration The time interval/duration of the animation.

 @return `YES`, if coordinate bounds are valid and can be set.
 Otherwise returns `NO`. The method returns immediately.
 */
- (BOOL)setVisibleMapRect:(HereSDKMapRect)mapRect
              edgePadding:(UIEdgeInsets)insets
             withDuration:(NSTimeInterval)duration;

/**
 Changes the receiver’s viewport to fit the given coordinate bounds with
 additional padding on each side with the specified duration and animation
 type.

 @param mapRect The bounds that the viewport will show in its entirety.
 @param insets The minimum padding (in screen points) that will be visible around the given coordinate bounds.
 @param duration The time interval/duration of the animation.
 @param animationCurve The animation type for the change. Defines the animation curve
 and ease type for the change.

 @return `YES`, if coordinate bounds are valid and can be set.
 Otherwise returns `NO`. The method returns immediately.
 */
- (BOOL)setVisibleMapRect:(HereSDKMapRect)mapRect
              edgePadding:(UIEdgeInsets)insets
             withDuration:(NSTimeInterval)duration
           animationCurve:(HereSDKMapAnimationCurve)animationCurve;


@end

NS_ASSUME_NONNULL_END
