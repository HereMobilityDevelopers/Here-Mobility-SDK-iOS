/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <HereSDKDemandKit/HereSDKDemandRideOffer.h>
#import <HereSDKDemandKit/HereSDKDemandRideOfferProtocol.h>
#import <HereSDKDemandKit/HereSDKDemandPublicTransportRouteLeg.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing a public transport ride offer, returned in response to requestRide.
 */
@interface HereSDKDemandPublicTransportRideOffer : HereSDKDemandRideOffer <HereSDKDemandRideOfferProtocol>

/** number of transfers */
@property(nonatomic, readonly) uint32_t transfers;

/** A list of transportation legs for the route */
@property(nonatomic, readonly) NSArray<HereSDKDemandPublicTransportRouteLeg*> *sectionsArray;

@end

NS_ASSUME_NONNULL_END
