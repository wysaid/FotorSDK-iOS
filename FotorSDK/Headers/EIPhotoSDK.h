//
//  EIPhotoSDKLibrary.h
//  EIPhotoSDKLibrary
//
//  Created by ChenQi on 14-3-21.
//  Copyright (c) 2014年 Everimaging. All rights reserved.
//

#import "EIPhotoSDKSession.h"
#import "EIPhotoSDKContext.h"
#import "EIPhotoSDKEditorController.h"
#import "EIPhotoEditorCustomization.h"


typedef enum {
    kEIStatusOK = 0,
    kEIStatusEditorConflict,
    kEIStatusContextBusy,
    kEIStatusInvalidImage,
    kEIStatusHugeImage,
    
} EIPhotoSDKStatus;


NS_CLASS_AVAILABLE_IOS(6_0) @interface EIPhotoSDK : NSObject


/**
 @brief	editor controller
 
 @param image [IN] full screen image
 
 @return nil, if another editor is opened or any context is rendering
 */
+ (EIPhotoSDKEditorController *)photoEditorControllerWithImage:(UIImage *)image error:(NSError **)outError;


/**
 @return The SDK version number.
 */
+ (NSString *)versionString;

/**
 @brief
 
 Configures the SDK's API Key. You must provide this before instantiating any
 instance of SDK. Not doing so will provie a default API Key of EIPhotoSDK. All API keys
 are validated with Fotor's server.
 
 @param apiKey [IN] your app's API key
 */
+ (void)setApiKey:(NSString *)apiKey;

/**
 @brief	enable in-app purchase of store
 in-app purchase is enabled by default
 
 @param enable [IN] YES: enable, NO: disable
 */
+ (void)enableInAppPurchase:(BOOL)enable;


@end