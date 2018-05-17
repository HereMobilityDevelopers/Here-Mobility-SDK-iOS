//
/***************************************************************
 * Copyright © 2017 HERE Global B.V. All rights reserved. *
 **************************************************************/

#import <Foundation/Foundation.h>

/**
 The direction of the maneuver action.  For turns, it represents the turn direction.
 For departure/arrival, it indicates the position's side of the street in the current direction of travel.
 */
typedef NS_ENUM(NSInteger, HereSDKRouteLegManeuverDirection) {
    /** Maneuver direction: unknown */
    HereSDKRouteLegManeuverDirectionUnknownDirection,
    /** Maneuver direction: straight */
    HereSDKRouteLegManeuverDirectionStraight,
    /** Maneuver direction: slight right */
    HereSDKRouteLegManeuverDirectionSlightRight,
    /** Maneuver direction: right */
    HereSDKRouteLegManeuverDirectionRight,
    /** Maneuver direction: sharp right */
    HereSDKRouteLegManeuverDirectionSharpRight,
    /** Maneuver direction: slight left */
    HereSDKRouteLegManeuverDirectionSlightLeft,
    /** Maneuver direction: left */
    HereSDKRouteLegManeuverDirectionLeft,
    /** Maneuver direction: sharp left */
    HereSDKRouteLegManeuverDirectionSharpLeft,
    /** Maneuver direction: u-turn */
    HereSDKRouteLegManeuverDirectionUTurn,
};

/**
 The maneuver action
 */
typedef NS_ENUM(NSInteger, HereSDKRouteLegManeuverAction) {
    /** Maneuver action: unknown */
    HereSDKRouteLegManeuverActionUnknownAction,
    /** Maneuver action: depart */
    HereSDKRouteLegManeuverActionDepart,
    /** Maneuver action: arrive */
    HereSDKRouteLegManeuverActionArrive,
    /** Maneuver action: turn */
    HereSDKRouteLegManeuverActionTurn,
    /** Maneuver action: continue */
    HereSDKRouteLegManeuverActionContinue,
    /** Maneuver action: exit */
    HereSDKRouteLegManeuverActionExit,
    /** Maneuver action: on-ramp */
    HereSDKRouteLegManeuverActionRamp,
    /** Maneuver action: fork */
    HereSDKRouteLegManeuverActionFork,
    /** Maneuver action: merge */
    HereSDKRouteLegManeuverActionMerge,
    /** Maneuver action: street name change */
    HereSDKRouteLegManeuverActionNameChange,
    /** Maneuver action: circle */
    HereSDKRouteLegManeuverActionTrafficCircle,
    /** Maneuver action: ferry */
    HereSDKRouteLegManeuverActionFerry,
    /** Maneuver action: roundabout (NOTE: Roundabouts are smaller than traffic circles, and meant to be driven through at lower speeds.) */
    HereSDKRouteLegManeuverActionRoundAbout,
};

/**
 A maneuver in a leg of the route
 */
@interface HereSDKRouteManeuver : NSObject

/**
 Distance of the leg (in the units requested in HereSDKRouteRequest)
 */
@property (nonatomic, readonly) float distance;
/**
 Estimated travel time for the leg, in seconds
 */
@property (nonatomic, readonly) float travelTime;
/**
 Index of the first point of the leg in the route geometry
 */
@property (nonatomic, readonly) uint32_t firstPointIndex;
/**
 Index of the last point of the leg in the route geometry
 */
@property (nonatomic, readonly) uint32_t lastPointIndex;
/**
 Instruction text, e.g. "Turn right onto Main Street"
 */
@property (nonatomic, readonly) NSString *instruction;
/**
 The maneuver action
 */
@property (nonatomic, readonly) HereSDKRouteLegManeuverAction action;
/**
 The maneuver direction. For turns, this is the turn direction.
 For departure/arrival, this is the position's side of the street in the current direction of travel.
 */
@property (nonatomic, readonly) HereSDKRouteLegManeuverDirection direction;
/**
 For roundabouts or traffic circles, indicates the number of the exit to take. A value of 0 means that exit information is not available and should not be used.
 */
@property (nonatomic, readonly) UInt32 roundaboutExitNumber;
/**
 Primary road name for the maneuver.
 */
@property (nonatomic, readonly) NSString *roadName;
/**
 Primary road numbers, if available, of the maneuver
 */
@property (nonatomic, readonly) NSArray<NSString *> *roadsNumberArray;
/**
 Sign text indicating the direction a driver should follow.
 */
@property (nonatomic, readonly) NSArray<NSString *> *signsInfoArray;
/**
 The number of items in @c signInfoArray without causing the array to be created.
 */
@property (nonatomic, readonly) NSArray<NSString *> *exitsInfoArray;

@end
