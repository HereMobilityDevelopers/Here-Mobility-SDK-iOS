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

/** first subdivision level below the country */
@property (nonatomic, readonly, nullable) NSString *state;

/** second subdivision level below the country */
@property (nonatomic, readonly, nullable) NSString *county;

/** The city */
@property (nonatomic, readonly, nullable) NSString *city;

/** subdivision level below the city */
@property (nonatomic, readonly, nullable) NSString *district;

/** subdivision level below the district. commonly used in IND */
@property (nonatomic, readonly, nullable) NSString *subDistrict;

/** The street name */
@property (nonatomic, readonly, nullable) NSString *street;

/** house number. depending on regional characteristics, can also be house name */
@property (nonatomic, readonly, nullable) NSString *houseNumber;

/** The postal code */
@property (nonatomic, readonly, nullable) NSString *postalCode;

/** building name. commonly used in HKG */
@property(nonatomic, readonly, nullable) NSString *building;

/** formatted address lines */
@property(nonatomic, readonly, nullable) NSArray<NSString*> *lineArray;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Initializes and returns `HereSDKAddressData`

 @param country localized country name value
 @param countryCode  ISO 3166-alpha-3 country code value
 @param state first subdivision level below the country
 @param county second subdivision level below the country
 @param city primary locality of the address
 @param district subdivision level below the city
 @param subDistrict subdivision level below the district. commonly used in IND
 @param street street name
 @param houseNumber house number. depending on regional characteristics, can also be house name
 @param postalCode postal code
 @param building building name. commonly used in HKG
 @param lineArray formatted address lines
 @return the `HereSDKAddressData` with passed parameters
 */
+ (instancetype)addressDataWithCountry:(NSString *_Nullable)country
                           countryCode:(NSString *_Nullable)countryCode
                                 state:(NSString *_Nullable)state
                                county:(NSString *_Nullable)county
                                  city:(NSString *_Nullable)city
                              district:(NSString *_Nullable)district
                           subDistrict:(NSString *_Nullable)subDistrict
                                street:(NSString *_Nullable)street
                           houseNumber:(NSString *_Nullable)houseNumber
                            postalCode:(NSString *_Nullable)postalCode
                              building:(NSString *_Nullable)building
                             lineArray:(NSArray<NSString*> *)lineArray;

@end

NS_ASSUME_NONNULL_END
