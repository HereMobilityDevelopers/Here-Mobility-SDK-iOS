//
/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 A Class for getting verticals coverage request.
 */
@interface HereSDKDemandVerticalsCoverageRequest : NSObject

/**
 The coordinates of the location, where we will get the coverage response.
 */
@property (readonly) CLLocationCoordinate2D coordinate;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a verticals coverage request

 @param coordinate The coordinates of the location, where we will get the coverage response.
 */
+ (instancetype)verticalsCoverageRequestWithCoordinate:(CLLocationCoordinate2D) coordinate;


@end

NS_ASSUME_NONNULL_END
