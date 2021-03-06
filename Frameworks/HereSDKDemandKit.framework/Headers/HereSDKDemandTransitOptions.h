/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Class representing public transit ride options 
 */
@interface HereSDKDemandTransitOptions : NSObject

/** Maximum number of changes or transfers allowed in a route. Default is unlimited. Range is 0-6.*/
@property(nonatomic, readonly, nullable) NSNumber *maxTransfers;

/** Specifies a maximum walking distance. Default is 2000. Range is 0-6000.*/
@property(nonatomic, readonly, nullable) NSNumber *maxWalkingDistance;

/** The client's locale. Complies with the ISO 639-1 standard and defaults to [HereSDKManager userPreferences].locale.*/
@property(nonatomic, readonly) NSString *locale;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates HereSDKDemandTransitOptions object

 @param maxTransfers The Maximum number of changes or transfers allowed in a route
 @param maxWalkingDistance Specifies a maximum walking distance
 @param locale The client's locale. Complies with the ISO 639-1 standard and defaults to [HereSDKManager userPreferences].locale.
 */
+(instancetype)transitOptionsWithMaxTransfers:(NSNumber *_Nullable)maxTransfers  maxWalkingDistance:(NSNumber *_Nullable)maxWalkingDistance locale:(NSString *_Nullable)locale;

@end

NS_ASSUME_NONNULL_END
