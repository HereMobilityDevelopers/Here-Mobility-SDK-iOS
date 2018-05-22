/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <UIKit/UIKit.h>
#import <HereSDKCoreKit/HereSDKUser.h>

#import <HereSDKCoreKit/HereSDKLoggingLevel.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The class for configuring the Here Mobility SDK.
 */
@interface HereSDKManager : NSObject

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

/**
 * The shared HereSDKManager instance.
 * The first time the sharedManager is required, it is initialized with credentials from the app's Info.plist file.
 * Make sure the Info.plist includes correct values for keys HereMobilitySDKAppId and HereMobilitySDKAppSecret
 * If either of the credentials is missing, the SDK initialization fails, and the results are undefined.

 * @return The shared HereSDKManager instance.  nil if either credential is missing.
 */
@property (class, nonatomic, readonly, nullable) HereSDKManager *sharedManager;

/**
 * Returns a HereSDKUser instance.

 * Holds user credentials data
 * To log out, set this property to nil
 */
@property (nonatomic, readwrite, nullable) HereSDKUser *user;

/**
 * Tells the SDK to begin a fetch operation, if it has data to download.
 * To be called from application:performFetchWithCompletionHandler, if the application's `background fetch` mode is enabled.
 *
 * @param completionHandler The block to execute when the download operation is complete. This block is called with the fetch result value that describes the results of the SDK download operation.
 */
- (void)performFetchWithCompletionHandler:(nonnull void (^)(UIBackgroundFetchResult result))completionHandler;

/**
 * Configures the global that determines whether network calls can be made over a cellular connection. The default is `NO`.

 * @param allow a boolean flag, Set to `YES` to allow network calls should be allowed.  Set to `YES` to allow network calls to be made over a cellular connection, or to 'NO' to prevent it.
 */
+ (void)allowCellularAccess:(BOOL)allow;

/**
 * Configures the global log level setting, which determines the level of logs that are printed to the console.

 * @param loggingLevel The level of logs that are printed to the console.
 */
+ (void)configureLoggingLevel:(HereSDKLoggingLevel)loggingLevel;

/**
 * Configures the HereSDK and starts its services. This method should be called after the app is launched
 * and before using HereSDK services.
 */
+ (void)configure;

/**
 * Returns the SDK Version
 */
+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END
