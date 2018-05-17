/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for of geocoding result types
 */
typedef NS_OPTIONS (NSUInteger, HereSDKGeocodeResultType) {
    /** Geocode Result type: Unknown */
    HereSDKGeocodeResultTypeUnknown = 0,

    /** Geocode Result type: Address (e.g. "121 Main Street, Smithsville, CA 20289, USA") */
    HereSDKGeocodeResultTypeAddress = 1 << 0,
    /** Geocode Result type: Place name (e.g. "General Hospital") */
    HereSDKGeocodeResultTypePlace   = 1 << 1,

    /** Geocode Result type: Any (Address or Place) */
    HereSDKGeocodeResultTypeAll     = NSUIntegerMax
};
