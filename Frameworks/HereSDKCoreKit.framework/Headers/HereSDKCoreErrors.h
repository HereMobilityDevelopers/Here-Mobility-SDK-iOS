/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/** Domain of NSError objects related to phone verification errors */
extern NSErrorDomain const kHereSDKPhoneVerificationDomain;

/** Domain of NSError objects related to generic network errors */
extern NSErrorDomain const kHereSDKNetworkDomain;

/** Domain of NSError objects related to TimeZoneService errors */
extern NSErrorDomain const kHereSDKTimeZoneServiceDomain;

/** Domain of NSError objects related to Auth errors */
extern NSErrorDomain const kHereSDKAuthDomain;

/**
 Type definition for phone verification error types, returned as the error code of NSError objects
 */
typedef NS_ERROR_ENUM(kHereSDKPhoneVerificationDomain, HereSDKPhoneVerificationError) {
    /** Provided phone number was invalid or an incorrect format */
    HereSDKPhoneVerificationErrorInvalidPhoneNumber = 10000,
    /** The SMS provider returned an error */
    HereSDKPhoneVerificationErrorSMSProviderError,
    /** Internal error */
    HereSDKPhoneVerificationErrorInternal,
};

/**
 Type definition for network error types, returned as the error code of NSError objects
 */
typedef NS_ERROR_ENUM (kHereSDKNetworkDomain, HereSDKNetworkError) {
    /** Network not available */
    HereSDKNetworkErrorNotAvailable = 10100,
    /** Sending data failed */
    HereSDKNetworkErrorSendingFailed,
    /** User auth info wasn't supplied. */
    HereSDKNetworkErrorUserNotDefined,
    /** User authentication expired. */
    HereSDKNetworkErrorAuthExpired,
    /** Phone number wasn't verified. */
    HereSDKNetworkErrorPhoneNotVerified,
};

/**
 Type definition for TimeZoneService error types, returned as the error code of NSError objects
 */
typedef NS_ERROR_ENUM (kHereSDKTimeZoneServiceDomain, HereSDKTimeZoneServiceError) {
    /** Timezone not found */
    HereSDKTimeZoneNotFound = 10201,
    /** Coordinate not valid */
    HereSDKTimeZoneCoordinateNotValid,
};

/**
 Type definition for auth error types, returned as the error code of NSError objects
 */
typedef NS_ERROR_ENUM(kHereSDKAuthDomain, HereSDKAuthError) {
    /** Provided arguments was invalid or an incorrect format */
    HereSDKAuthErrorInvalidArgument = 10300,
    /** Internal error */
    HereSDKAuthErrorInternal,
    /** general auth error */
    HereSDKAuthenticationError
};

