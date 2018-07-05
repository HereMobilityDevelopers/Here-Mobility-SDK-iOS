/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKMapKit/HereSDKFeatureStyle.h>

/**
 Type definitions for polyline width units.
 */
typedef NS_ENUM(NSUInteger, HereSDKPolylineWidthUnits) {
    /** The width of polylines is in points */
    HereSDKPolylineWidthUnitsPoints = 0,
    /** The width of polylines is in meters, and changes in proportion with the map. */
    HereSDKPolylineWidthUnitsMeters,
};

/**
 Type definitions for the style of the polyline's ends.
 */
typedef NS_ENUM(NSUInteger, HereSDKPolylineCapStyle) {
    /**
     The line ends with a straight line, at its end vertex
     */
    HereSDKPolylineCapStyleButt = 0,
    /**
     The line ends with a straight line, half its width
     from its end vertex
     */
    HereSDKPolylineCapStyleSquare,
    /**
     The line ends with a semicircle around its end vertex
     */
    HereSDKPolylineCapStyleRound
};

/**
 Type definitions for the style of the polyline's corners.
 */
typedef NS_ENUM(NSUInteger, HereSDKPolylineJoinStyle) {
    /**
     Sharp/pointy corner.
     */
    HereSDKPolylineJoinStyleMiter = 0,
    /**
     The corner is cut off
     */
    HereSDKPolylineJoinStyleBevel,
    /**
     Rounded corner join
     */
    HereSDKPolylineJoinStyleRound
};

NS_ASSUME_NONNULL_BEGIN

/**
 An object that stores the style for polyline features
 */
@interface HereSDKPolylineStyle : HereSDKFeatureStyle

/**
 Width of the feature. Default unit is points and default value is 5.
 */
@property (nonatomic) NSUInteger width;

/**
 Units for width of polyline. Default is `HereSDKPolylineWidthUnitsPoints`.

 If HereSDKPolylineWidthUnitsMeters, the width of polylines changes in
 proportion with the map.
 */
@property (nonatomic) HereSDKPolylineWidthUnits widthUnits;

/**
 Cap style for the polyline. Default is `HereSDKPolylineCapStyleButt`.
 */
@property (nonatomic) HereSDKPolylineCapStyle capStyle;

/**
 Join style for the polyline. Default is `HereSDKPolylineJoinStyleMiter`.
 */
@property (nonatomic) HereSDKPolylineJoinStyle joinStyle;

/**
 Miter limit for the polyline's joins. Applied if the joinStyle is `HereSDKPolylineJoinStyleMiter`,
 otherwise has no effect. Default is `3`.
 */
@property (nonatomic) NSUInteger miterLimit;

@end

NS_ASSUME_NONNULL_END
