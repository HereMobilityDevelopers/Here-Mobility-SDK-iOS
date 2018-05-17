/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKDemandKit/HereSDKDemandLocation.h>

/**
 The Transport mode available types.
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandPublicTransportRouteLegTransportMode) {
    /**Public Transport Mode for route leg: Unknown */
    HereSDKDemandPublicTransportRouteLegTransportModeUnknown = 0,
    /**Public Transport Mode for route leg: High speed Train */
    HereSDKDemandPublicTransportRouteLegTransportModeHighSpeedTrain = 1,
    /**Public Transport Mode for route leg: Intercity Train */
    HereSDKDemandPublicTransportRouteLegTransportModeIntercityTrain = 2,
    /**Public Transport Mode for route leg: Inter Regional Train */
    HereSDKDemandPublicTransportRouteLegTransportModeInterRegionalTrain = 3,
    /**Public Transport Mode for route leg: Regional Train */
    HereSDKDemandPublicTransportRouteLegTransportModeRegionalTrain = 4,
    /**Public Transport Mode for route leg: City Train */
    HereSDKDemandPublicTransportRouteLegTransportModeCityTrain = 5,
    /**Public Transport Mode for route leg: Bus */
    HereSDKDemandPublicTransportRouteLegTransportModeBus = 6,
    /**Public Transport Mode for route leg: Ferry */
    HereSDKDemandPublicTransportRouteLegTransportModeFerry = 7,
    /**Public Transport Mode for route leg: Subway */
    HereSDKDemandPublicTransportRouteLegTransportModeSubway = 8,
    /**Public Transport Mode for route leg: Light Rail */
    HereSDKDemandPublicTransportRouteLegTransportModeLightRail = 9,
    /**Public Transport Mode for route leg: Private Bus */
    HereSDKDemandPublicTransportRouteLegTransportModePrivateBus = 10,
    /**Public Transport Mode for route leg: Inclined elevator or funicular */
    HereSDKDemandPublicTransportRouteLegTransportModeInclined = 11,
    /**Public Transport Mode for route leg: Awerial section (e.g. cable car) */
    HereSDKDemandPublicTransportRouteLegTransportModeAerial = 12,
    /**Public Transport Mode for route leg: Bus Rapid */
    HereSDKDemandPublicTransportRouteLegTransportModeBusRapid = 13,
    /**Public Transport Mode for route leg: Monorail */
    HereSDKDemandPublicTransportRouteLegTransportModeMonorail = 14,
    /**Public Transport Mode for route leg: Walk */
    HereSDKDemandPublicTransportRouteLegTransportModeWalk = 15,
};

NS_ASSUME_NONNULL_BEGIN

/**
 A class representing a public transport route leg.
 */
@interface HereSDKDemandPublicTransportRouteLeg : NSObject

/** Mode of transportation */
@property(nonatomic, readonly) HereSDKDemandPublicTransportRouteLegTransportMode transportMode;

/** Duration of the section in seconds */
@property(nonatomic, readonly, nullable) NSNumber *duration;

/** Distance of the section (units set in HereSDKDemandTransitOptions) */
@property(nonatomic, readonly, nullable) NSNumber *distance;

/** If relevant/applicable */
@property(nonatomic, readonly, nullable) NSString *line;

/** The starting point of the route */
@property(nonatomic, readonly) HereSDKDemandLocation *origin;

/** The departure time (if known/applicable) */
@property(nonatomic, readonly, nullable) NSDate *departureTime;

/** The end point of the route */
@property(nonatomic, readonly) HereSDKDemandLocation *destination;

/** Contains the arrival time */
@property(nonatomic, readonly, nullable) NSDate *arrivalTime;

/** Transport operator name. If relevant/applicable */
@property(nonatomic, readonly, nullable) NSString *transportOperator;

/** Return description of transport mode as NSString */
- (NSString *)transportModeDescription;

@end

NS_ASSUME_NONNULL_END

