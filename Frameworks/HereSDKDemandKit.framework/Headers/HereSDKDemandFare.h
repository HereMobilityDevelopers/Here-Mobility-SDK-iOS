/***************************************************************
 * Copyright © 2019 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKDemandKit/HereSDKDemandFareItem.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class containing detailed fare information
 */
@interface HereSDKDemandFare : NSObject

/** An itemized list of fare items */
@property (nonatomic, readonly) NSArray<HereSDKDemandFareItem *> *items;

/** ISO 4217 Currency Code, for example: "USD", "EUR", "JPY" */
@property (nonatomic, readonly) NSString *currencyCode;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
