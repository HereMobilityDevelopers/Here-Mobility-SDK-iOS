/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <HereSDKMapKit/HereSDKPolyline.h>
#import <HereSDKMapKit/HereSDKMapGeometry.h>

@protocol HereSDKAnnotation;

NS_ASSUME_NONNULL_BEGIN

@class HereSDKMapView;
@class HereSDKPointAnnotationStyle;
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
 Update that mapview failed to load

 @param mapView  mapview that failed to load.
 @param error error
 */
- (void)mapView:(HereSDKMapView *)mapView didFailLoadingMapWithError:(NSError *)error;

/**
 Return annotation style for specific annotation

 @param mapView mapview that has annotation
 @param annotation annotation to style
 @return annotation style
 */
- (nullable HereSDKPointAnnotationStyle *)mapView:(HereSDKMapView *)mapView styleForAnnotation:(id<HereSDKAnnotation>)annotation;

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

@end


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
 The tilt angle of the map "camera", measured in radians from the 0 direction (0 direction = camera is facing the ground).

 Changing the value of this property updates the map view immediately.
 To animate the change, use the `-setTilt:animated:` method instead.
 */
@property (nonatomic) float tilt;

/**
 Changes the tilt angle of the map "camera", and optionally animates the change.

 @param tilt The tilt angle of the map camera, measured in radians.

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
@property (nonatomic, getter=isZoomEnabled) BOOL zoomEnabled;

/**
 The receiver’s delegate, for handling map view changes.

 A map view sends messages to its delegate to notify it of changes to its contents.
 */
@property (nonatomic, weak, nullable) id<HereSDKMapViewDelegate> delegate;
@property (nonatomic, readonly) NSArray<HereSDKPolyline *>* polylines;

- (void)addPolyline:(HereSDKPolyline *)polyline;
- (void)addPolyline:(HereSDKPolyline *)polyline withStyle:(HereSDKFeatureStyle *)style;
- (void)removePolyline:(HereSDKPolyline *)polyline;
- (void)removePolylines:(NSArray<HereSDKPolyline *> *)polylines;

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
 Annotation that represents the user location on map. `nil` if not present.
 */
@property (nullable, nonatomic, readonly) HereSDKUserLocationAnnotation *userLocationAnnotation;

/**
 Shows or hides the user location on the map.

 @param shouldShowUserLocation Boolean value that indicates whether the map should try to display the user’s location.
 */
- (void)showUserLocation:(BOOL)shouldShowUserLocation;

@end

NS_ASSUME_NONNULL_END
