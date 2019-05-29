/***************************************************************
 * Copyright © 2019 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import <HereSDKDemandKit/HereSDKDemandPaymentMethod.h>

/**
 Type definition for credit card brands.
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandCreditCardBrand) {
    /** Credit card brand: Mastercard */
    HereSDKDemandCreditCardBrandMastercard = 0,
    /** Credit card brand: Visa */
    HereSDKDemandCreditCardBrandVisa,
    /** Credit card brand: American Express */
    HereSDKDemandCreditCardBrandAmex,
    /** Credit card brand: Diners */
    HereSDKDemandCreditCardBrandDiners,
    /** Credit card brand: Discover */
    HereSDKDemandCreditCardBrandDiscover,
    /** Credit card brand: Maestro */
    HereSDKDemandCreditCardBrandMaestro,
    /** Other credit card brand */
    HereSDKDemandCreditCardBrandOther = 100,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A payment method class containing credit card information.
 */
@interface HereSDKDemandCreditCard : HereSDKDemandPaymentMethod

/** Last 4 digits of the credit card number */
@property (nonatomic, readonly) NSString *lastDigits;

/** Name of the cardholder */
@property (nonatomic, readonly) NSString *cardholderName;

/** The brand of the credit card */
@property (nonatomic, readonly) HereSDKDemandCreditCardBrand brand;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
