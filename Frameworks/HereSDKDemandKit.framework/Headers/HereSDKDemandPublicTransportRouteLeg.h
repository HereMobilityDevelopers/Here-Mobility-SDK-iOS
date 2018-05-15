//
 /***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>
#import <HereSDKDemandKit/HereSDKDemandLocation.h>

/**
 The Transport mode available types.
 - HereSDKDemandPublicTransportRouteLegTransportModeUnknown: type unknown
 - HereSDKDemandPublicTransportRouteLegTransportModeHighSpeedTrain: High speed train
 - HereSDKDemandPublicTransportRouteLegTransportModeIntercityTrain: Intercity Train
 - HereSDKDemandPublicTransportRouteLegTransportModeInterRegionalTrain: Inter Regional Train
 - HereSDKDemandPublicTransportRouteLegTransportModeRegionalTrain: Regional Train
 - HereSDKDemandPublicTransportRouteLegTransportModeCityTrain: City Train
 - HereSDKDemandPublicTransportRouteLegTransportModeBus: Bus
 - HereSDKDemandPublicTransportRouteLegTransportModeFerry: Ferry
 - HereSDKDemandPublicTransportRouteLegTransportModeSubway: Subway
 - HereSDKDemandPublicTransportRouteLegTransportModeLightRail: Light Rail
 - HereSDKDemandPublicTransportRouteLegTransportModePrivateBus: Private Bus
 - HereSDKDemandPublicTransportRouteLegTransportModeInclined: Inclined elevator or funicular
 - HereSDKDemandPublicTransportRouteLegTransportModeAerial: Aerial section (e.g. cable car)
 - HereSDKDemandPublicTransportRouteLegTransportModeBusRapid: Bus Rapid
 - HereSDKDemandPublicTransportRouteLegTransportModeMonorail: Monorail
 - HereSDKDemandPublicTransportRouteLegTransportModeWalk: Walk
 */
typedef NS_ENUM(NSUInteger, HereSDKDemandPublicTransportRouteLegTransportMode) {
    HereSDKDemandPublicTransportRouteLegTransportModeUnknown = 0,
    HereSDKDemandPublicTransportRouteLegTransportModeHighSpeedTrain = 1,
    HereSDKDemandPublicTransportRouteLegTransportModeIntercityTrain = 2,
    HereSDKDemandPublicTransportRouteLegTransportModeInterRegionalTrain = 3,
    HereSDKDemandPublicTransportRouteLegTransportModeRegionalTrain = 4,
    HereSDKDemandPublicTransportRouteLegTransportModeCityTrain = 5,
    HereSDKDemandPublicTransportRouteLegTransportModeBus = 6,
    HereSDKDemandPublicTransportRouteLegTransportModeFerry = 7,
    HereSDKDemandPublicTransportRouteLegTransportModeSubway = 8,
    HereSDKDemandPublicTransportRouteLegTransportModeLightRail = 9,
    HereSDKDemandPublicTransportRouteLegTransportModePrivateBus = 10,
    HereSDKDemandPublicTransportRouteLegTransportModeInclined = 11,
    HereSDKDemandPublicTransportRouteLegTransportModeAerial = 12,
    HereSDKDemandPublicTransportRouteLegTransportModeBusRapid = 13,
    HereSDKDemandPublicTransportRouteLegTransportModeMonorail = 14,
    HereSDKDemandPublicTransportRouteLegTransportModeWalk = 15,
};

NS_ASSUME_NONNULL_BEGIN

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

