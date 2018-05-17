/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 Type definition for vehicle type
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandVehicleType)
{
    /** Vehicle type: not supplied */
    HereSDKDemandVehicleTypeNotSupplied = 0,
    /** Vehicle type: standard */
    HereSDKDemandVehicleTypeStandard = 1,
    /** Vehicle type: limo */
    HereSDKDemandVehicleTypeLimo = 2,
    /** Vehicle type: van */
    HereSDKDemandVehicleTypeVan = 3,
    /** Vehicle type: other */
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

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
