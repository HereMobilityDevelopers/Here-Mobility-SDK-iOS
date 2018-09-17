/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type definition for transit type
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandTransitType)
{
    /** Transit Type: Taxi */
    HereSDKDemandTransitTypeTaxi = (1 << 0),
    /** Transit Type: Public Transport */
    HereSDKDemandTransitTypePublicTransport = (1 << 1),
};

/**
 Class that defines demand ride offer
 */
@protocol HereSDKDemandRideOfferProtocol <NSObject>

/**
 Returns transit type

 @return transit type
 */
- (HereSDKDemandTransitType)getTransitType;

@end

NS_ASSUME_NONNULL_END
