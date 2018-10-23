/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

extern NSString *const kHereSDKPhoneVerificationDomain;
extern NSString *const kHereSDKNetworkDomain;

typedef NS_ENUM (NSInteger, HereSDKPhoneVerificationError) {
    HereSDKInvalidPhoneNumberErr = 10000,
    HereSDKSMSProviderErr,
    HereSDKInternalErr
};

/**
 Type definition for network error types
 */
typedef NS_ENUM (NSInteger, HereSDKNetworkError) {
    /** Network not available */
    HereSDKNetworkNotAvailableErr = 10100,
    /** Sending data failed */
    HereSDKSendingDataFailedErr,
    /** User auth info wasn't supplied. */
    HereSDKUserNotDefinedErr,
    /** Phone number wasn't verified. */
    HereSDKPhoneVerificationErr
};
