//
/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface HereSDKTimeZoneResponse : NSObject

/** The location time zone. */
@property(nonatomic, readonly) NSTimeZone *timeZone;

/** Offset, in seconds, from UTC to local time, including DST offset. */
@property(nonatomic, readonly) NSTimeInterval offsetWithDst;

/** Offset, in seconds, from UTC to local time, without DST offset. */
@property(nonatomic, readonly) NSTimeInterval offsetWithoutDst;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
