/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>

/**
 A rectangular area as measured on a two-dimensional map projection on the planet.
 The rectangle's location and size are determined by its "origin corner" (its bottom-left corner),
 and its width and height as measured in degrees.
 */
typedef struct {
    CLLocationCoordinate2D origin;
    CGSize size;
} HereSDKMapRect;

/**
 Creates a new HereSDKMapRect from the given origin coordinates and size dimensions.

 @param latitude The origin coordinate latitude value (latitude of the rectangle's top-left corner)
 @param longitude The origin coordinate longitude value (longitude of the rectangle's top-left corner)
 @param width The width of the rectangle in degrees.
 @param height The height of the rectangle in degrees.

 @return A map rectangle with the specified values.
 */
extern HereSDKMapRect HereSDKMapRectMake(double latitude, double longitude, double width, double height);

/**
 Creates an invalid HereSDKMapRect.
 */
extern HereSDKMapRect HereSDKMapRectInvalid(void);

/**
 Returns a Boolean value indicating whether the two HereSDKMapRect objects are equal (in both size and location)

 @param rect1 The first map rectangle.
 @param rect2 The second map rectangle.

 @return `YES` if the rectangles are exactly the same or
 `NO` if the origin point or size values are different.
 */
extern BOOL HereSDKMapRectEqualToRect(HereSDKMapRect rect1, HereSDKMapRect rect2);

/**
 Returns minimum longitude of the specified HereSDKMapRect

 @param rect The rectangle object
 @return The minimum longitude
 */
extern double HereSDKMapRectGetMinLongitude(HereSDKMapRect rect);

/**
 Returns minimum latitude of the specified HereSDKMapRect

 @param rect The rectangle object
 @return the minimum latitude
 */
extern double HereSDKMapRectGetMinLatitude(HereSDKMapRect rect);

/**
 Returns the mid-point longitude of the specified HereSDKMapRect

 @param rect The rectangle object
 @return the The mid-point longitude
 */
extern double HereSDKMapRectGetMidLongitude(HereSDKMapRect rect);

/**
 Returns the midPoint latitude of the specified HereSDKMapRect

 @param rect The rectangle object
 @return The mid-point latitude
 */
extern double HereSDKMapRectGetMidLatitude(HereSDKMapRect rect);

/**
 Returns maximum longitude of the specified HereSDKMapRect

 @param rect The rectangle object
 @return The maximum longitude
 */
extern double HereSDKMapRectGetMaxLongitude(HereSDKMapRect rect);

/**
 Returns maximum latitude of the specified HereSDKMapRect

 @param rect The rectangle object
 @return The maximum latitude
 */
extern double HereSDKMapRectGetMaxLatitude(HereSDKMapRect rect);

/**
 Returns the width of the specified HereSDKMapRect

 @param rect The rectangle object
 @return The rectangle's width
 */
extern double HereSDKMapRectGetWidth(HereSDKMapRect rect);

/**
 Returns the height of the specified HereSDKMapRect

 @param rect The rectangle object
 @return The rectangle's height
 */
extern double HereSDKMapRectGetHeight(HereSDKMapRect rect);

/**
 Returns a Boolean value indicating whether the HereSDKMapRect is valid

 @param rect The rectangle object to test
 @return `YES` if the rectangle is valid. `NO` otherwise.
 */
extern bool HereSDKMapRectIsValid(HereSDKMapRect rect);

/**
 Returns CLLocationCoordinate2D that represents the center of the HereSDKMapRect.

 @param rect The rectangle object
 @return CLLocationCoordinate2D of the center point
 */
extern CLLocationCoordinate2D HereSDKMapRectGetCenter(HereSDKMapRect rect);

NS_ASSUME_NONNULL_BEGIN

/**
 Class used to generate map geometries
 */
@interface HereSDKMapGeometry: NSObject

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Returns the minimal HereSDKMapRect that contains all the points in the given points array.

 @param points array of points that the rectangle must contain
 @param error reference to `NSError`
 @return A HereSDKMapRect that contains all the points. If HereSDKMapRect is invalid, an error is generated in the referenced NSError object.
 */
+ (HereSDKMapRect)minMapRectContainingPoints:(NSArray<CLLocation *> *)points error:(out NSError ** _Nullable)error;

@end

NS_ASSUME_NONNULL_END
