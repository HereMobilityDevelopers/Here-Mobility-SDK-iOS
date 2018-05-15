//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, HereSDKDemandTransitType)
{
    HereSDKDemandTransitTypeTaxi = 0,
    HereSDKDemandTransitTypePublicTransport = 1,
};

@protocol HereSDKDemandRideOfferProtocol <NSObject>

- (HereSDKDemandTransitType)getTransitType;

@end

NS_ASSUME_NONNULL_END
