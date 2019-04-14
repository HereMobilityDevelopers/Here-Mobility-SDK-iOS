/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class containing passenger details
 */
@interface HereSDKDemandPassenger : NSObject

/** Passenger's name */
@property (nonatomic, readonly) NSString *name;

/**
  The phone number of the passenger.
  A valid phone number format is E.164 as describe at https://en.wikipedia.org/wiki/E.164.

  E.164 general format must contain only digits split as follows:
  - Country code (max 3 digits)
  - Subscriber number (max 12 digits)
 */
@property (nonatomic, readonly) NSString *phoneNumber;

/** Passenger's photo URL */
@property (nonatomic, readonly, nullable) NSString *photoURL;

/** Passenger's email */
@property (nonatomic, readonly, nullable) NSString *email;

/**
 Creates a HereSDKDemandPassenger instance.

 @param name The passenger's name
 @param phoneNumber The passenger's phone number
 @param photoUrl The passenger's photo URL
 @param email The passenger's email

 @return a new HereSDKDemandPassenger instance
 */
+ (instancetype)passengerWithName:(NSString *)name phoneNumber:(NSString *)phoneNumber photoUrl:(NSString *_Nullable)photoUrl email:(NSString *_Nullable)email;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END

