//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKDemandKit/HereSDKDemandKit.h>
#import <HereSDKDemandKit/HereSDKDemandRideOfferProtocol.h>
#import <HereSDKDemandKit/HereSDKDemandPublicTransportRouteLeg.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereSDKDemandPublicTransportRideOffer : HereSDKDemandRideOffer <HereSDKDemandRideOfferProtocol>

/** number of transfers */
@property(nonatomic, readonly) uint32_t transfers;

/** A list of transportation sections for the route */
@property(nonatomic, readonly) NSArray<HereSDKDemandPublicTransportRouteLeg*> *sectionsArray;

@end

NS_ASSUME_NONNULL_END
