/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKMapKit/HereSDKRoutePoint.h>
#import <HereSDKMapKit/HereSDKGeocodeResultType.h>
#import <HereSDKCoreKit/HereSDKAddressData.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Geocoding request result
 */
@interface HereSDKGeocodeResult : NSObject

/**
 Opaque ID of the result in the response list. Required.
 */
@property (nonatomic, readonly) NSString *resultId;

/**
 Title of the result to display to the end user. Always provided for place results; optional otherwise.
 */
@property (nonatomic, readonly, nullable) NSString *title;

/**
 Address information for the result. Always provided for address results; optional otherwise.
 */
@property (nonatomic, readonly) NSString *address;

/**
 Type of result
 */
@property (nonatomic, readonly) HereSDKGeocodeResultType resultType;

/**
 URI that refers to a resource with details for the result (e.g. the location's web site). Optional.
 */
@property (nonatomic, readonly, nullable) NSString *addressId;

/**
 Data object that represents detailed data about an address. Optional.
 */
@property (nonatomic, readonly, nullable) HereSDKAddressData *addressData;

/**
 Position to display the result.
 */
@property (nonatomic, readonly) HereSDKRoutePoint *center;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
