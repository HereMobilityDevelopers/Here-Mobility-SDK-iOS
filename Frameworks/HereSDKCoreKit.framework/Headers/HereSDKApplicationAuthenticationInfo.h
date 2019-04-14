/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The class for authenticating the application.
 */
@interface HereSDKApplicationAuthenticationInfo : NSObject

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

/** The creation time of this info **/
@property (nonatomic, readonly) NSDate *creationTime;

/**
 * The verification hash of the authInfo. Should be created in the following format:
 * hs384(appId + "." + `creationTime`), signed with the application secret.
 */
@property (nonatomic, readonly) NSString *verificationHash;


/**
 Creates a `HereSDKApplicationAuthenticationInfo` instance
HereSDKManager
 @param creationTime the creation time of the `verificationHash`
 @param verificationHash the `verificationHash`
 @return a new `HereSDKApplicationAuthenticationInfo` instance
 */
+ (instancetype)applicationAuthenticationInfoWithCreationTime:(NSDate *)creationTime
                                             verificationHash:(NSString *)verificationHash;

@end

NS_ASSUME_NONNULL_END
