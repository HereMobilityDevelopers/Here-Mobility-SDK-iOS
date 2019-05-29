/***************************************************************
 * Copyright © 2019 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for fare items
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandFareItemType) {
    /** Unknown */
    HereSDKDemandFareItemTypeUnknown = 0,

    /** The base fare */
    HereSDKDemandFareItemTypeBaseFare,

    /** The tax */
    HereSDKDemandFareItemTypeTax,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A fare item class containing the amount and currency information
 */
@interface HereSDKDemandFareItem : NSObject

/** The numeric amount */
@property (nonatomic, readonly) NSDecimalNumber *amount;

/** The type of the fare item */
@property (nonatomic, readonly) HereSDKDemandFareItemType type;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
