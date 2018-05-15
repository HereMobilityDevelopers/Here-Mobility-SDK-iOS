/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class containing details of a ride's price
 */
@interface HereSDKDemandPrice : NSObject

/** The price's numeric amount */
@property (nonatomic, readonly) NSDecimalNumber *amount;

/** The price's ISO 4217 currency code */
@property (nonatomic, readonly) NSString *currency;

@end

NS_ASSUME_NONNULL_END

