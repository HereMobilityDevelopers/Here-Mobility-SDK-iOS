/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing a price range
 */
@interface HereSDKDemandPriceRange : NSObject

/**The maximum numeric value of the price range */
@property (nonatomic, readonly) NSDecimalNumber *upperBound;

/** The minimum numeric value of the price range */
@property (nonatomic, readonly) NSDecimalNumber *lowerBound;

/** The price range's ISO 4217 currency code */
@property (nonatomic, readonly) NSString *currency;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a 'HereSDKDemandPriceRange' instance with given parameters.

 @param upperBound The maximum numeric value of the price range
 @param lowerBound The minimum numeric value of the price range
 @param currency The price range's ISO 4217 currency code

 @return A new instance of 'HereSDKDemandPriceRange'
 */
+(instancetype)priceRangeWithUpperBound:(NSDecimalNumber *)upperBound lowerBound:(NSDecimalNumber *)lowerBound currency:(NSString *)currency;

@end

NS_ASSUME_NONNULL_END
