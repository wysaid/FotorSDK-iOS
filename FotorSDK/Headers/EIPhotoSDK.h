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


@end