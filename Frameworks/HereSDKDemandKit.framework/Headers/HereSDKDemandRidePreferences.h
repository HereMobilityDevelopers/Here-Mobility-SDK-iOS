//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


/**
 Preferences of a ride.
 */
@interface HereSDKDemandRidePreferences : NSObject

/**
 Specifies if messages about the ride will be sent to the passenger. Default is false.
 */
@property(nonatomic, readonly) BOOL subscribeToMessages;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a ride preferences

 @param subscribeToMessages Specifies if messages about the ride will be sent to the passenger.
 */
+(instancetype)ridePreferencesWithSubscribeToMessages:(BOOL)subscribeToMessages;

@end

NS_ASSUME_NONNULL_END
