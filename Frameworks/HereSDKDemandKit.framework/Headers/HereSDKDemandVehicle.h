/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, HereSDKDemandVehicleType)
{
    HereSDKDemandVehicleTypeNotSupplied = 0,
    HereSDKDemandVehicleTypeStandard = 1,
    HereSDKDemandVehicleTypeLimo = 2,
    HereSDKDemandVehicleTypeVan = 3,
    HereSDKDemandVehicleTypeOther = 4,
};

NS_ASSUME_NONNULL_BEGIN

/**
 The ride vehicle
 */
@interface HereSDKDemandVehicle : NSObject

/** Vehicle's license plate number */
@property (nonatomic, readonly) NSString *licensePlateNumber;

/** Vehicle type */
@property (nonatomic, readonly) HereSDKDemandVehicleType vehicleType;

/** Vehicle manufacturer */
@property (nonatomic, readonly) NSString *manufacturer;

/** Vehicle model */
@property (nonatomic, readonly) NSString *model;

/** Vehicle color */
@property (nonatomic, readonly) NSString *color;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
