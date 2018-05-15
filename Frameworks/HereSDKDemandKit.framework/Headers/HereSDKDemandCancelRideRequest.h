//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A Class for cancelling a ride request.
 */
@interface HereSDKDemandCancelRideRequest : NSObject

/**
 The ID of the ride to be cancelled.
 */
@property(nonatomic, readonly) NSString *rideId;

/**
 The cancellation reason.
 */
@property(nonatomic, readonly, nullable) NSString *cancelReason;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a ride cancellation request

 @param rideId The ID of the ride to be cancelled
 @param cancelReason The cancellation reason
 */
+(instancetype)cancelRideWithRideId:(NSString *)rideId cancelReason:(NSString *_Nullable)cancelReason;
-(instancetype)initWithRideId:(NSString *)rideId cancelReason:(NSString *_Nullable)cancelReason;

@end

NS_ASSUME_NONNULL_END
