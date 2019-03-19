//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class HereSDKTimeZoneResponse;

NS_ASSUME_NONNULL_BEGIN

/**
 The Time Zone service provides NSTimeZone and time offset data for a coordinate.
 */
@interface HereSDKTimeZoneService : NSObject

/**
 Requests a HereSDKTimeZoneResponse for the specified coordinate.

 @param coordinate Coordinate to request time zone for. Required.
 */
- (void)timeZoneAtCoordinate:(CLLocationCoordinate2D)coordinate handler:(void (^) (HereSDKTimeZoneResponse * _Nullable response, NSError * _Nullable error))handler;

@end

NS_ASSUME_NONNULL_END
