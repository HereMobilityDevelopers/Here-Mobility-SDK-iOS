/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/** Domain of NSError objects related to demand request errors */
extern NSErrorDomain const kHereSDKDemandErrorDomain;

/**
 Type definition for demand client error types, returned as the error code of NSError objects
 */
typedef NS_ERROR_ENUM(kHereSDKDemandErrorDomain, HereSDKDemandClientError) {
    /** Internal error */
    HereSDKDemandClientErrorInternal = 40000,

    // Request offers errors

    /** The supplied coordinates are invalid */
    HereSDKDemandClientErrorInvalidCoordinate,

    /** The provided date is not valid - either in the past, or too far in the future */
    HereSDKDemandClientErrorInvalidDate,

    /** The max walking distance is not valid - accepted range between 0 and 6000 */
    HereSDKDemandClientErrorInvalidMaxWalkingDistancePublicTransport,

    /** The max transfers value is not valid - maximum allowed is 6 */
    HereSDKDemandClientErrorInvalidMaxTransfersPublicTransport,

    // Create ride errors

    /** The offer is no longer valid */
    HereSDKDemandClientErrorOfferExpired,
};
