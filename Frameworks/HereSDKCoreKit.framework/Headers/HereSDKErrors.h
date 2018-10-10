/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

extern NSString *const kHereSDKPhoneVerificationDomain;

typedef NS_ENUM (NSUInteger, HereSDKPhoneVerificationError) {
    HereSDKInvalidPhoneNumberErr = 10000,
    HereSDKSMSProviderErr,
    HereSDKInternalErr
};
