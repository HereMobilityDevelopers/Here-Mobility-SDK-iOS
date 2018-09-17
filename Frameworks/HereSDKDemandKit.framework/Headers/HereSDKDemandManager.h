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
#import <HereSDKDemandKit/HereSDKDemandVerticalsCoverageRequest.h>
#import <HereSDKDemandKit/HereSDKDemandVerticalsCoverageResponse.h>

NS_ASSUME_NONNULL_BEGIN


/**
 A completion block for ride updates.
 Will contain either one of the parameters.

 @param ride ride updated
 @param statusLog ride status update
 @param location ride location update
 @param error error returned from ride updates
 */
typedef void (^HereSDKDemandRideUpdateBlock)(HereSDKDemandRide *_Nullable ride, HereSDKDemandRideStatusLog *_Nullable statusLog, HereSDKDemandRideLocation *_Nullable location, NSError *_Nullable error);

/**
 A completion block for ride cancellation
 Will contain either one of the parameters.

 @param cancellationInfo cancellation info for a ride
 @param error error returned from cancellation request
 */
typedef void (^HereSDKDemandRideCancellationBlock)(HereSDKDemandCancellationInfo *_Nullable cancellationInfo, NSError *_Nullable error);

/**
 * A factory class for HereSDKDemandClient.
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
 An object conforming to the HereSDKDemandRidesUpdatesDelegate method that receives
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
 Starts monitoring a ride.

 @param rideId The ride's identifier.
 @param handler The handler for receiving updates.
 */
- (void)registerUpdatesForRide:(NSString *)rideId withHandler:(HereSDKDemandRideUpdateBlock)handler;

/**
 Stops monitoring a ride

 @param rideId The ride's identifier.
 */
- (void)unregisterUpdatesForRide:(NSString *)rideId;

/**
 Request ride offers that match a given request.

 @param request The HereSDKDemandRideOffersRequest object containing the ride constraints (e.g. numbers of passengers and suitcases).
 @param handler The block that will handle the response.
 */
- (void)requestRide:(HereSDKDemandRideOffersRequest *)request withHandler:(void(^)(NSArray<id<HereSDKDemandRideOfferProtocol>> *_Nullable offers, NSError *_Nullable error))handler;

/**
 Create a new ride object with the given offer ID.

 @param request The HereSDKDemandRideRequest object containing the offerId.
 @param handler The block that will handle the response.
 */
- (void)createRideWithRequest:(HereSDKDemandRideRequest *)request withHandler:(void(^)(HereSDKDemandRide *_Nullable ride, NSError *_Nullable error))handler;

/**
 Query for rides with the given statuses and update time.

 @param query The HereSDKDemandRideQuery object containing the filters on ride statuses and update time.
 @param handler The block that will handle the response.
 */
- (void)getRides:(HereSDKDemandRideQuery *)query withHandler:(void(^)(HereSDKDemandQueryRidesResponse *ridesResponse, NSError *_Nullable error))handler;

/**
 Cancel a ride related to a given request.

 @param request The HereSDKDemandCancelRideRequest object representing the ride to be cancelled.
 @param handler The block that will handle the response.
 */
- (void)cancelRideWithRequest:(HereSDKDemandCancelRideRequest *)request withHandler:(HereSDKDemandRideCancellationBlock)handler;

/**
 Get a ride by rideId.

 @param rideId The ID of the ride to retrieve.
 @param handler The block that will handle the response.
 */
- (void)getRideWithRequest:(NSString *)rideId withHandler:(void(^)(HereSDKDemandRide *_Nullable ride, NSError *_Nullable error))handler;

/**
 Get the verticals coverage available at a specific location
 This request will return a mask of all available TransitTypes at the given location.

 @param request The HereSDKDemandVerticalsCoverageRequest object.
 @param handler The block that will handle the response.
 */
- (void)getVerticalsCoverageWithRequest:(HereSDKDemandVerticalsCoverageRequest *)request withHandler:(void(^)(HereSDKDemandVerticalsCoverageResponse *_Nullable verticalsCoverageResponse, NSError *_Nullable error))handler;


@end

NS_ASSUME_NONNULL_END
