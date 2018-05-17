/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for logging levels
 */
typedef NS_ENUM (NSUInteger, HereSDKLoggingLevel) {
    /** No logs */
    HereSDKLoggingLevelNone = 0,
    /** Logs with Error level */
    HereSDKLoggingLevelError,
    /** Logs with Warning and Error levels */
    HereSDKLoggingLevelWarning,
    /** Logs with Info, Warning and Error levels */
    HereSDKLoggingLevelInfo
};
