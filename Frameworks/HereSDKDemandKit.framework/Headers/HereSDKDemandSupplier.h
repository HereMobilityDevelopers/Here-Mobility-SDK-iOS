/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A ride supplier
 */
@interface HereSDKDemandSupplier : NSObject

/** Supplier ID */
@property(nonatomic, readonly, copy) NSString *supplierId;

/** Supplier's English name */
@property(nonatomic, readonly, copy) NSString *englishName;

/** Supplier's local name (in the local language) */
@property(nonatomic, readonly, copy) NSString *localName;

/** Supplier's logo URL */
@property(nonatomic, readonly, copy) NSString *logoURL;

/** Supplier's phone number */
@property(nonatomic, readonly, copy) NSString *phoneNumber;

/** Supplier's address */
@property(nonatomic, readonly, copy) NSString *address;

@end

NS_ASSUME_NONNULL_END
