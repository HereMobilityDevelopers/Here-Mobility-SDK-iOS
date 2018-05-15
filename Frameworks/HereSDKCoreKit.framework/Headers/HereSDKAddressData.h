//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Data object that represents detailed data about an address.
 */
@interface HereSDKAddressData : NSObject

/** The country name */
@property (nonatomic, readonly, nullable) NSString *country;

/** The ISO 3166 Alpha 3 country code */
@property (nonatomic, readonly, nullable) NSString *countryCode;

/** The state (if relevant) */
@property (nonatomic, readonly, nullable) NSString *state;

/** The city */
@property (nonatomic, readonly, nullable) NSString *city;

/** The street name */
@property (nonatomic, readonly, nullable) NSString *street;

/** The house number */
@property (nonatomic, readonly, nullable) NSString *houseNumber;

/** The postal code */
@property (nonatomic, readonly, nullable) NSString *postalCode;
@property (nonatomic, readonly, nullable) NSString *county;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (instancetype)addressDataWithCountry:(NSString *_Nullable)country
                           countryCode:(NSString *_Nullable)countryCode
                                 state:(NSString *_Nullable)state
                                  city:(NSString *_Nullable)city
                                street:(NSString *_Nullable)street
                           houseNumber:(NSString *_Nullable)houseNumber
                               postalCode:(NSString *_Nullable)postalCode
                                county:(NSString *_Nullable)county;

@end

NS_ASSUME_NONNULL_END
