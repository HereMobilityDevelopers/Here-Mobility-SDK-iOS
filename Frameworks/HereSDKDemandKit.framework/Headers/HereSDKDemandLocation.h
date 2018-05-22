/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <HereSDKCoreKit/HereSDKCoreKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing a ride's location
 */
@interface HereSDKDemandLocation : NSObject

/** Geographical coordinates of the ride */
@property (nonatomic) CLLocation *point;

/** Address of the location (if available) */
@property (nonatomic, nullable) HereSDKAddressData *address;

/** Free text for specific information of location */
@property (nonatomic, nullable) NSString *freeText;

/**
 Returns HereSDKDemandLocation

 @param location Coordinate object for location
 @param address Optional address object for location

 @return HereSDKDemandLocation
 */
- (instancetype)initWithLocation:(CLLocation *)location address:(nullable HereSDKAddressData *)address freeText:(nullable NSString *)freeText;

/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
