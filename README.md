<!-- Getting Started Guide for the HERE Mobility SDK for iOS -->

<!-- Contains code samples in Swift and Objective-C -->

# HERE Mobility SDK for iOS

Version 1.1.0

<br />

* * *

<br />

<!-- Date -->
**August, 2018**

<br />

<!-- Legal Disclaimer and Copyright notice -->
> Copyright © 2018, HERE Technologies. All rights reserved. The software, information and all other materials contain in this documentation are confidential and proprietary information of HERE Technologies and are protected by applicable copyright legislation. The disclosure of information contained herein does not constitute any license or authorization to use or disclose information, ideas or concepts presented. No part of this documentation may be disclosed to any third party, copied, reproduced or stored on any type of media or used in any way by any party without the express prior, written consent of Here Technologies. This software, information and all other materials contain in this documentation are provided "as-is" and without warranties of any kind, either express or implied, including, but not limited to, the implied warranties of merchantability, fitness for a particular purpose, satisfactory quality and non-infringement. HERE Technologies does not warrant that the content is error free and HERE Technologies does not warrant or make any representations regarding the quality, correctness, accuracy, or reliability of the content.  

<br />

* * *

<br />

<!-- Table of contents with links to different sections -->

1. [Introduction](#1-introduction)
	1. [Mobility Package](#11-mobility-package)
	2. [Map Services Package](#12-map-services-package)
2. [Pre-requisites](#2-pre-requisites)
	1. [Operating System](#21-operating-system)
	2. [3rd Party Packages](#22-3rd-party-packages) 
3. [Getting Started](#3-getting-started)
	1. [Obtaining HERE Credentials for Your App](#31-obtaining-here-credentials-for-your-app)
	2. [Adding the HERE Mobility SDK to your App](#32-adding-the-here-mobility-sdk-to-your-app)
	3. [Initializing the HERE Mobility SDK](#33-initializing-the-here-mobility-sdk)
	4. [Requesting Location Access Permission](#34-requesting-location-access-permission)
	5. [Using the HERE Sandbox Platform](#35-using-the-here-sandbox-platform)
4. [API Reference](#4-api-reference)

<br />

* * *

<br />

<!-- Introduction to the different SDK modules and prerequisites -->

## 1. Introduction

The HERE Mobility SDK helps you create apps with rich and dynamic mobility functionality. The SDK accesses the HERE Mobility Marketplace, a centralized platform for managing mobility data using intelligent algorithms. 

The HERE Mobility SDK contains 2 packages:

* **Mobility**
* **Map Services**

You can use any combination of these packages. There is no dependency between the different packages. You will need to include the Core package (_CoreKit_) in your project. 

<br />

### 1.1. Mobility Package

The Mobility package (_DemandKit_) allows your app’s users to manage passenger rides anywhere in the world, supplied through the HERE Mobility Marketplace. This includes requesting ride offers, booking and canceling rides, and updating a ride’s status.  


### 1.2. Map Services Package

The Map Services package (_MapKit_) provides comprehensive map capabilities, including: 

* Searching for locations by address or name
* Dynamic rendering of map display
* Point-to-point route calculation

<br />

* * *

<br />

## 2. Pre-requisites

### 2.1. Operating System

HERE Mobility SDK version 1.1.0 supports iOS version **9.0** or later.

### 2.2. 3rd Party Packages
* [gRPC](https://github.com/grpc/grpc)
* [Tangram ES](https://github.com/tangrams/tangram-es)

<br />

* * *

<br />

## 3. Getting Started

### 3.1. Obtaining HERE Credentials for Your App

To use the HERE Mobility SDK, you’ll need a unique app ID and app secret. To obtain these credentials, contact us at [mobility_developers@here.com](mailto:mobility_developers@here.com).

Please include the following information in your email: 

* Full name
* Phone
* Application name
* Bundle Identifier

### 3.2. Adding the HERE Mobility SDK to your App

We recommend adding the HERE Mobility SDK(s) to your application by using [**CocoaPods**](https://cocoapods.org/). CocoaPods provides a simple, versioned dependency management system that automates the tedious and error-prone aspects of manually configuring libraries and frameworks.

To set up your local CocoaPods environment and import the desired HERE Mobility SDK modules into your project:

**1.** Run the following shell commands:

<!-- Cocoapods sample code -->

```
$ sudo gem install cocoapods
$ pod init
```

**2.** In the root directory of your project, create a `Podfile` and add the source for the HERE Mobility SDK repository to the beginning of the file, as follows:

```ruby
source 'https://github.com/HereMobilityDevelopers/Here-Mobility-SDK-iOS.git'
```

Also add the default CocoaPods spec repo source

```ruby
source 'https://github.com/CocoaPods/Specs.git'
```

Add 'use_frameworks!' to Podfile as HereSDK is dynamic framework

```ruby
use_frameworks!
```

**3.** Depending on the HERE Mobility SDK packages you want to use, add any or all of the following pods to the `Podfile` (optionally, you can specify which versions to add):

```ruby
pod 'HereSDKDemandKit', '~>1.1.0'
pod 'HereSDKMapKit', '~>1.1.0'
```

**4.** Complete the installation by performing the following commands:

```
$ pod repo update
$ pod install
```

These instructions will setup your local CocoaPods environment and import the desired HERE Mobility SDK modules into your project.

### 3.3. Initializing the HERE Mobility SDK

The SDK's `HereSDKManager` uses credentials from your app's `Info.plist` file to initialize.
If the `appId` is missing from the file, the SDK will fail to initialize.

#### 3.3.1 Configuring your app's Info.plist

1. In Xcode, right-click your project's `Info.plist` file and select **Open As** -> **Source Code**.
2. Insert the following XML snippet into the body of your file just before the final `</dict>` element.

```xml
<key>HereMobilitySDKAppId</key>
<string>{your-app-id}</string>
```

Replace `{your-app-id}` with your app's ID, that you've obtained from HERE.

In your app's `UIApplicationDelegate` method `didFinishLaunchingWithOptions:` call the method to initialize and configure the HereSDK.

The following sections provide examples for how to initialize and configure the SDK in Swift and Objective-C.

**_Swift_**
<!-- Swift sample code for initializing the SDK -->

```swift
import HereSDKCoreKit

func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {

	HereSDKManager.configure()

	return true
}
```

**_Objective-C_**
<!-- Objective-C sample code for initializing the SDK -->

```obj-c
#import <HereSDKCoreKit/HereSDKCoreKit.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    [HereSDKManager configure];

    return YES;
}
```

#### 3.3.2 Authenticating App Users
In order to make Here SDK API calls on behalf of your users (e.g. book rides), you must first "prove" us that they are indeed your users by signing their username with your Secret Key. The recommended procedure is to have your backend server do this when the user logs in, and send the signed "hash" to the app. Once the app has the hash, it should pass it to the SDK like so:

**_Swift_**
<!-- Swift sample code for setting User -->

```swift
import HereSDKCoreKit

HereSDKManager.shared?.user = HereSDKUser(id: userId, expiration: Date(timeIntervalSince1970: TimeInterval(expiration)), verificationHash: hashString!)
```

**_Objective-C_**
<!-- Objective-C sample code for setting User -->

```obj-c
#import <HereSDKCoreKit/HereSDKCoreKit.h>

HereSDKManager.sharedManager.user = [HereSDKUser userWithId:userId expiration:[NSDate dateWithTimeIntervalSince1970:expiration] verificationHash: hashedString];
```

_**Note:**_ For reference on how to generate a signed hash (given the secret key) please check [iOS sampleApp project](https://github.com/HereMobilityDevelopers/Here-Mobility-SDK-iOS-SampleApp) (function `generateUserCredentialsWithUser` in `AppDelegate`).

### 3.4. Requesting Location Access Permission

When running the HERE Mobility SDK on iOS, it is mandatory to ask the user for location access permissions in your application flow. After displaying an explanation of why you need location access permission, display a location manager dialog to request location access.

_Notes:_

* Your application's `Info.plist` should also contain descriptions explaining location usage for the `NSLocationWhenInUseUsageDescription` and `NSLocationAlwaysUsageDescription` keys. 
* Some SDK features, such as detecting Personal Points of Interest, work better when **_`Always`_** access is granted.


The following sections provide examples for how to request access in Swift and Objective-C.

**_Swift_**
<!-- Swift sample code for requesting location permissions -->

```swift
import CoreLocation

let locationManager: CLLocationManager = CLLocationManager()

// request location authorization for when application is active
locationManager.requestWhenInUseAuthorization()

// or for allowing location access even when application is not active
locationManager.requestAlwaysAuthorization()
```

**_Objective-C_**
<!-- Objective-C sample code for requesting location permissions -->

```obj-c
#import <CoreLocation/CoreLocation.h>

CLLocationManager *locationManager = [CLLocationManager new];

// request location authorization for when application is active
[locationManager requestWhenInUseauthorization];

// or for allowing location access even when application is not active
[locationManager requestAlwaysAuthorization];
```

### 3.5. Using the HERE Sandbox Platform

You can use the HERE Mobility Sandbox platform to develop and test your app’s functionality without calling the production platform. Requests to the sandbox environment are ephemeral (do not change the platform’s state).

The HERE Mobility service directs your app’s calls to the sandbox or production environment according to the app key you provide (there is no need to use different endpoints).

<br />

* * *

<br />

## 4. API Reference

For detailed information about HERE Mobility SDK functions, please refer to the [Here Mobility API reference](https://heremobilitydevelopers.github.io/Here-Mobility-SDK-iOS/). 



