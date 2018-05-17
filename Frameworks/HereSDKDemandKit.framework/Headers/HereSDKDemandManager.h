/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import <HereSDKDemandKit/HereSDKDemandRidesUpdatesProtocol.h>

#import <HereSDKDemandKit/HereSDKDemandRideOffersRequest.h>
#import <HereSDKDemandKit/HereSDKDemandRideOfferProtocol.h>
#import <HereSDKDemandKit/HereSDKDemandRideRequest.h>
#import <HereSDKDemandKit/HereSDKDemandCancelRideRequest.h>
#import <HereSDKDemandKit/HereSDKDemandRideLocation.h>
#import <HereSDKDemandKit/HereSDKDemandRideQuery.h>
#import <HereSDKDemandKit/HereSDKDemandQueryRidesResponse.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A factory class for 'HereSDKDemandClient'.
 */
@interface HereSDKDemandManager : NSObject

/**
 Returns the shared demand manager.
 */
@property (class, nonatomic, readonly) HereSDKDemandManager *sharedManager;

/**
 Returns the current HERE SDK version.
 */
@property (class, nonatomic, readonly) NSString *version;

# pragma mark - demand client

/**
 An object conforming to the `HereSDKDemandRidesUpdatesDelegate` method that receives
 messages related to the open rides updates.
 */
@property (weak, nonatomic, readonly) id<HereSDKDemandRidesUpdatesDelegate> ridesUpdatesDelegate;

/**
 Starts monitoring all open rides.

 @param delegate The delegate that will receive ride updates.
 */
- (void)registerForRidesUpdatesWithDelegate:(id<HereSDKDemandRidesUpdatesDelegate>)delegate;

/**
 Stops monitoring open rides
 */
- (void)unregisterForRidesUpdates;

/**
 Request ride offers that match a given request

 @param request The 'HereSDKDemandRideOffersRequest' object containing the ride constraints (e.g. numbers of passengers and suitcases).
 @param handler The block that will handle the response.
 */
- (void)requestRide:(HereSDKDemandRideOffersRequest *)request withHandler:(void(^)(NSArray<id<HereSDKDemandRideOfferProtocol>> *_Nullable offers, NSError *_Nullable error))handler;

/**
 Create a new ride object with the given offer ID.

 @param request The 'HereSDKDemandRideRequest' object containing the offerId.
 @param handler The block that will handle the response.
 */
- (void)createRideWithRequest:(HereSDKDemandRideRequest *)request withHandler:(void(^)(HereSDKDemandRide *_Nullable ride, NSError *_Nullable error))handler;

/**
 Query for rides with the given statuses and update time.

 @param query The 'HereSDKDemandRideQuery' object containing the filters on ride statuses and update time.
 @param handler The block that will handle the response.
 */
- (void)getRides:(HereSDKDemandRideQuery *)query withHandler:(void(^)(HereSDKDemandQueryRidesResponse *ridesResponse, NSError *_Nullable error))handler;

/**
 Cancel a ride related to a given request.

 @param request The 'HereSDKDemandCancelRideRequest' object representing the ride to be cancelled.
 @param handler The block that will handle the response.
 */
- (void)cancelRideWithRequest:(HereSDKDemandCancelRideRequest *)request withHandler:(void(^)(NSError *_Nullable error))handler;

/**
 Get a ride by rideId.

 @param rideId The ID of the ride to retrieve.
 @param handler The block that will handle the response.
 */
- (void)getRideWithRequest:(NSString *)rideId withHandler:(void(^)(HereSDKDemandRide *_Nullable ride, NSError *_Nullable error))handler;

@end

NS_ASSUME_NONNULL_END
