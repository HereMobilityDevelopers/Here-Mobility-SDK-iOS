/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

#import <HereSDKDemandKit/HereSDKDemandRoute.h>
#import <HereSDKDemandKit/HereSDKDemandPriceRange.h>
#import <HereSDKDemandKit/HereSDKDemandPriceRange.h>
#import <HereSDKDemandKit/HereSDKDemandCancellationInfo.h>
#import <HereSDKDemandKit/HereSDKDemandBookingConstraints.h>
#import <HereSDKDemandKit/HereSDKDemandTransitOptions.h>

/**
 Type definition for ride offer sort order.
 */
typedef NS_ENUM(NSUInteger, HereDemandRideOffersRequestSortType) {
    /** Sort type: Unknown */
    HereDemandRideOffersRequestSortTypeUnknown = 0,
    /** Sort type: by price (lowest first) */
    HereDemandRideOffersRequestSortTypeByPrice = 1,
    /** Sort type: by ETA (earliest first) */
    HereDemandRideOffersRequestSortType_ByEta  = 2,
};

/**
 Type definition for transport type.
 */
typedef NS_OPTIONS(NSUInteger, HereSDKDemandTransportType)
{
    /** Transport Type: Taxi */
    HereSDKDemandTransportTypeTaxi = 1 << 0,

    /** Transport Type: Public Transport */
    HereSDKDemandTransportTypePublicTransport = 1 << 1,

    /** Transport Type: All */
    HereSDKDemandTransportTypeAll = NSUIntegerMax
};

NS_ASSUME_NONNULL_BEGIN

/**
 A request for ride offers
 */
@interface HereSDKDemandRideOffersRequest : NSObject

/**
 The route for the requested ride.
 */
@property (nonatomic, readonly) HereSDKDemandRoute *route;

/**
 Ride constraints such as:
 - Number of passengers
 - Number of suitcases
 */
@property (nonatomic, readonly, nullable) HereSDKDemandBookingConstraints *constraints;

/**
 Pickup time for a pre-booked ride
 */
@property (nonatomic, readonly, nullable) NSDate *prebookPickupTime;

/**
 Acceptable price range for the rides
 */
@property (nonatomic, readonly, nullable) HereSDKDemandPriceRange *priceRange;

/**
 Sort order for ride offer results
 */
@property (nonatomic, readonly) HereDemandRideOffersRequestSortType sortType;

/**
 A free text note for the passenger
 */
@property (nonatomic, readonly, nullable) NSString *passengerNote;

/**
 Parameters for transit offers.
 */
@property (nonatomic, readonly, nullable) HereSDKDemandTransitOptions *transitOptions;

/**
 Parameters for transport type preference.
 */
@property (nonatomic, readonly) HereSDKDemandTransportType transportTypeFilterMask;

/**
 The client's locale. Complies with the ISO 639-1 standard and defaults to [HereSDKManager userPreferences].locale.
 */
@property (nonatomic, readonly) NSString *locale;

/**
 The maximum number of offers to be returned by the request. Defaults to `0`, which returns all available offers.
 */
@property (nonatomic, readonly) NSUInteger maxOffers;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a request for ride offers

 @param route The route for the requested ride
 @param constraints The constraints for the requested ride
 @param prebookPickupTime The pre-booked time of pickup
 @param priceRange The price range of the requested ride
 @param sortType The sorting order of the ride offers response
 @param passengerNote Free text for passenger notes
 @param transitOptions Added constraints for public transport offers
 @param transportTypeFilter Transport type preference
 */
+ (instancetype)rideOffersWithRoute:(HereSDKDemandRoute *)route
                        constraints:(HereSDKDemandBookingConstraints *_Nullable)constraints
                  prebookPickupTime:(NSDate *_Nullable)prebookPickupTime
                         priceRange:(HereSDKDemandPriceRange *_Nullable)priceRange
                           sortType:(HereDemandRideOffersRequestSortType)sortType
                      passengerNote:(NSString *_Nullable)passengerNote
                     transitOptions:(HereSDKDemandTransitOptions *_Nullable)transitOptions
                transportTypeFilter:(HereSDKDemandTransportType)transportTypeFilter;

/**
 Creates a request for ride offers
 Get all transportation Types in the response

 @param route The route for the requested ride
 @param constraints The constraints for the requested ride
 @param prebookPickupTime The pre-booked time of pickup
 @param priceRange The price range of the requested ride
 @param sortType The sorting order of the ride offers response
 @param passengerNote Free text for passenger notes
 @param transitOptions Added constraints for public transport offers
 */
+ (instancetype)rideOffersWithRoute:(HereSDKDemandRoute *)route
                        constraints:(HereSDKDemandBookingConstraints *_Nullable)constraints
                  prebookPickupTime:(NSDate *_Nullable)prebookPickupTime
                         priceRange:(HereSDKDemandPriceRange *_Nullable)priceRange
                           sortType:(HereDemandRideOffersRequestSortType)sortType
                      passengerNote:(NSString *_Nullable)passengerNote
                     transitOptions:(HereSDKDemandTransitOptions *_Nullable)transitOptions;

/**
 Creates a request for ride offers
 Set the response locale

 @param route The route for the requested ride
 @param constraints The constraints for the requested ride
 @param prebookPickupTime The pre-booked time of pickup
 @param priceRange The price range of the requested ride
 @param sortType The sorting order of the ride offers response
 @param passengerNote Free text for passenger notes
 @param transitOptions Added constraints for public transport offers
 @param locale The client's locale. Complies with the ISO 639-1 standard.
 */
+ (instancetype)rideOffersWithRoute:(HereSDKDemandRoute *)route
                        constraints:(HereSDKDemandBookingConstraints *_Nullable)constraints
                  prebookPickupTime:(NSDate *_Nullable)prebookPickupTime
                         priceRange:(HereSDKDemandPriceRange *_Nullable)priceRange
                           sortType:(HereDemandRideOffersRequestSortType)sortType
                      passengerNote:(NSString *_Nullable)passengerNote
                     transitOptions:(HereSDKDemandTransitOptions *_Nullable)transitOptions
                             locale:(NSString *_Nullable)locale;

/**
 Creates a request for ride offers
 Set the response locale

 @param route The route for the requested ride
 @param constraints The constraints for the requested ride
 @param prebookPickupTime The pre-booked time of pickup
 @param priceRange The price range of the requested ride
 @param sortType The sorting order of the ride offers response
 @param passengerNote Free text for passenger notes
 @param transitOptions Added constraints for public transport offers
 @param transportTypeFilter Transport type preference
 @param locale The client's locale. Complies with the ISO 639-1 standard.
 @param maxOffers The maximum number of offers to be returned by the request.
 */
+ (instancetype)rideOffersWithRoute:(HereSDKDemandRoute *)route
                        constraints:(HereSDKDemandBookingConstraints *_Nullable)constraints
                  prebookPickupTime:(NSDate *_Nullable)prebookPickupTime
                         priceRange:(HereSDKDemandPriceRange *_Nullable)priceRange
                           sortType:(HereDemandRideOffersRequestSortType)sortType
                      passengerNote:(NSString *_Nullable)passengerNote
                     transitOptions:(HereSDKDemandTransitOptions *_Nullable)transitOptions
                transportTypeFilter:(HereSDKDemandTransportType)transportTypeFilter
                             locale:(NSString *_Nullable)locale
                          maxOffers:(NSUInteger)maxOffers;

@end

NS_ASSUME_NONNULL_END
