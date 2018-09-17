//
/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Type definition for vertical coverage.
 */
typedef NS_OPTIONS(NSUInteger, HereSDKDemandVerticalType)
{
    /** Vertical Type: Taxi */
    HereSDKDemandVerticalTypeTaxi = (1 << 0),
    /** Vertical Type: Public Transport */
    HereSDKDemandVerticalTypePublicTransport = (1 << 1),
};

@interface HereSDKDemandVerticalsCoverageResponse : NSObject

@property (nonatomic, readonly) HereSDKDemandVerticalType verticalTypeMask;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
