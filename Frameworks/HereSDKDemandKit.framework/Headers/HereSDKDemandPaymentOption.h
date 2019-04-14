/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for payment options.
 */
typedef NS_OPTIONS(NSUInteger, HereSDKDemandPaymentOption)
{
    /** Payment Option: Offline only */
    HereSDKDemandPaymentOptionOffline = (1 << 0),
    /** Payment Option: Online only */
    HereSDKDemandPaymentOptionOnline = (1 << 1),


    /** Payment Option: Offline and online */
    HereSDKDemandPaymentOptionAll = NSUIntegerMax
};
