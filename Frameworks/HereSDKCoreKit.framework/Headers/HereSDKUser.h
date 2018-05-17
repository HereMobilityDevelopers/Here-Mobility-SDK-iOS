/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The class Representing a User.
 */
@interface HereSDKUser : NSObject <NSCopying, NSCoding>

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

/** The unique ID of the user. */
@property (nonatomic, readonly) NSString *userId;

/** The expiration date of the hash, since Epoch. */
@property (nonatomic, readonly) NSDate *expiration;

/** Signed hash that contains the userId and expiration date. */
@property (nonatomic, readonly) NSString *verificationHash;

/**
 Creates a 'HereSDKUser' instance

 @param userId The unique ID of the user
 @param expiration The expiration date of the hash, since Epoch
 @param verificationHash Signed hash that contains the userId and expiration date

 @return a new 'HereSDKUser' instance
 */
+ (instancetype)userWithId:(NSString *)userId
                expiration:(NSDate *)expiration
          verificationHash:(NSString *)verificationHash;

@end

NS_ASSUME_NONNULL_END
