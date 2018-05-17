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

/** The county */
@property (nonatomic, readonly, nullable) NSString *county;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Initializes and returns `HereSDKAddressData`

 @param country localized country name value
 @param countryCode  ISO 3166-alpha-3 country code value
 @param state first subdivision level below the country
 @param city primary locality of the address
 @param street street name
 @param houseNumber house number; depending on regional characteristics, can also be house name
 @param postalCode postal code
 @param county second subdivision level below the country
 @return the `HereSDKAddressData` with passed parameters 
 */
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
