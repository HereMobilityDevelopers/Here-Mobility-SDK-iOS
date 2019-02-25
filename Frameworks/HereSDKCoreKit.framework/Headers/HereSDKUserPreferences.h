//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** Class representing user preferences of the SDK */
@interface HereSDKUserPreferences : NSObject

/** The client's locale. */
@property(nonatomic, readonly) NSLocale *locale;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates HereSDKUserPreferences object

 @param locale The client's locale.
 */
+ (instancetype)userPreferencesWithLocale:(NSLocale *)locale;

@end

NS_ASSUME_NONNULL_END
