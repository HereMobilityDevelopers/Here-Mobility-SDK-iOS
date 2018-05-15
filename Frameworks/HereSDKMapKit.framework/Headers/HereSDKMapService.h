/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKMapKit/HereSDKRoute.h>
#import <HereSDKMapKit/HereSDKRouteRequest.h>
#import <HereSDKMapKit/HereSDKGeocodeResult.h>
#import <HereSDKCoreKit/HereSDKCoreKit.h>

@class CLLocation;

NS_ASSUME_NONNULL_BEGIN

/**
 A block to be called to handle a geocoding response.

 @param results An array of HereSDKGeocodeResult objects
 @param error Error returned
 */
typedef void (^HereSDKGeocodeCompletionHandler)(NSArray<HereSDKGeocodeResult *> *_Nullable results, NSError * _Nullable error);

/**
 The HereSDKMapService class provides services for route & geocoding queries.
 */
@interface HereSDKMapService : NSObject

/**
 Requests routes that meet the constraints in the HereSDKRouteRequest object.

 @param routeRequest Route constraints that the results must comply with
 @param handler Block for handling route results
 */
- (void)getRoutesWithRequest:(HereSDKRouteRequest *)routeRequest andHandler:(void(^)(NSArray<HereSDKRoute *> *_Nullable routes, NSError * _Nullable error))handler;

/**
 Submits a reverse-geocoding request (coordinates to place names) for the specified location.

 @param location Location coordinates to reverse-geocode
 @param handler Block for handling reverse-geocoding results
 */
- (void)reverseGeocodeLocation:(CLLocation *)location andHandler:(HereSDKGeocodeCompletionHandler)handler;

/**
 Submits a forward-geocoding request (place name to coordinates) for the specified location and query.

 @param query String that contains the address or place name to geocode
 @param location Approximate location of the target location
 @param handler Block for handling geocoding results
 */
- (void)geocodeQuery:(NSString *)query forlocation:(CLLocation *)location andHandler:(HereSDKGeocodeCompletionHandler)handler;

/**
 Submits a forward-geocoding request for the specified query, location, countryCode and type (address and/or place name).

 @param query String that contains the address or place name to geocode
 @param location Approximate location of the target location
 @param resultType A bitmask value of the types of results that should be returned (see HereSDKGeocodeResultType.h)
 @param countryCode ISO 3166 Alpha 3 country code used to filter results.
 @param handler Block for handling geocoding results
 */
- (void)geocodeQuery:(NSString *)query forlocation:(CLLocation *)location resultType:(HereSDKGeocodeResultType)resultType countryCode:(NSString *)countryCode andHandler:(HereSDKGeocodeCompletionHandler)handler;

/**
 Submits a forward-geocoding request for places in the area of the given location

 @param location Location in the desired area of the results
 @param handler Block for handling geocoding results
 */
- (void)nearbyPlacesForLocation:(CLLocation *)location andHandler:(HereSDKGeocodeCompletionHandler)handler;

/**
 Get detailed info about a specific address. After calling {@link geocodeQuery}, use the href field from
 {@link HereSDKGeocodeResult} as the addressId to retrieve the info.

 @param addressId The address for which to get the details
 @param handler Block for handling address details results
 */
- (void)getAddressDataWithAddressId:(NSString *)addressId andHandler:(void(^)(HereSDKAddressData *_Nullable addressData, NSError * _Nullable error))handler;

@end

NS_ASSUME_NONNULL_END

