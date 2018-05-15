//
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

@property (nonatomic, readonly) NSString *userId;
@property (nonatomic, readonly) NSDate *expiration;
@property (nonatomic, readonly) NSString *verificationHash;

+ (instancetype)userWithId:(NSString *)userId
                           expiration:(NSDate *)expiration
                                 verificationHash:(NSString *)verificationHash;

@end

NS_ASSUME_NONNULL_END
