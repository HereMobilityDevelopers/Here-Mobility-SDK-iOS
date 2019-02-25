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

/** The client's locale. If not specified, defaults to [HereSDKManager userPreferences].locale */
@property(nonatomic, readonly) NSLocale *messagesLocale;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a ride preferences

 @param subscribeToMessages Specifies if messages about the ride will be sent to the passenger.
 */
+ (instancetype)ridePreferencesWithSubscribeToMessages:(BOOL)subscribeToMessages;

/**
 Creates a ride preferences

 @param subscribeToMessages Specifies if messages about the ride will be sent to the passenger.
 @param messagesLocale The client's locale in which the messages will be sent to the passenger.
 */
+ (instancetype)ridePreferencesWithSubscribeToMessages:(BOOL)subscribeToMessages
                                    withMessagesLocale:(NSLocale *)messagesLocale;

@end

NS_ASSUME_NONNULL_END
