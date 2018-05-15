/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for of geocoding result types

 - HereSDKGeocodeResultTypeUnknown: Unknown
 - HereSDKGeocodeResultTypeAddress: Address (e.g. "121 Main Street, Smithsville, CA 20289, USA")
 - HereSDKGeocodeResultTypePlace: Place name (e.g. "General Hospital")
 */
typedef NS_OPTIONS (NSUInteger, HereSDKGeocodeResultType) {
    HereSDKGeocodeResultTypeUnknown = 0,

    HereSDKGeocodeResultTypeAddress = 1 << 0,
    HereSDKGeocodeResultTypePlace   = 1 << 1,

    HereSDKGeocodeResultTypeAll     = NSUIntegerMax
};
