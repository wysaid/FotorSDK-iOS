//
//  EIPhotoEditorCustomization.h
//  EIPhotoSDK
//
//  Created by ChenQi on 13-12-10.
//  Copyright (c) 2013年 Everimaging. All rights reserved.
//

#import <UIKit/UIKit.h>


extern NSString *const kEIEnhance; /**< Auto Enhance */
extern NSString *const kEIBaseAdjust; /**< Base Adjust */
extern NSString *const kEIAdvanceAdjust; /**< Advance Adjust */
extern NSString *const kEICrop; /**< Crop */
extern NSString *const kEITiltshift; /**< Tiltshift */
extern NSString *const kEIScene; /**< Scene */
extern NSString *const kEIEffect; /**< Effect */
extern NSString *const kEIFrame; /**< Frame */
extern NSString *const kEISticker; /**< Sticker */
extern NSString *const kEIText; /**< Text */
extern NSString *const kEIRotate; /**< Rotate */


/**
 @brief	all settings below are non-inheritable
 */
NS_CLASS_AVAILABLE_IOS(6_0) @interface EIPhotoEditorCustomization : NSObject

/**
 Sets the type and order of tools to be presented by the editor.
 
 The valid tool keys are:
 
 kEIEnhance,
 kEIBaseAdjust,
 kEIAdvanceAdjust,
 kEICrop,
 kEITiltshift,
 kEIScene,
 kEIEffect,
 kEIFrame,
 kEISticker,
 kEIText,
 kEIRotate,
 
 @param toolOrder An NSArray containing NSString values represented by one of the tool keys
 */
+ (void)setToolOrder:(NSArray *)toolOrder;

/**
 This property sets the UIStatusBarStyle of the Editor
 
 @param statusBarStyle The status bar style to use.
 */
+ (void)setStatusBarStyle:(UIStatusBarStyle)statusBarStyle NS_AVAILABLE_IOS(7_0);

/**
 default is YES
 
 @param hidden [IN] YES:hide status bar, NO:show status bar
 */
+ (void)setStatusBarHidden:(BOOL)hidden;

/**
 Configures the orientations the editor can have on the iPad form factor.
 
 On the iPhone form factor, orientation is always portrait.
 On the ipad form factor, default orientationMask is UIInterfaceOrientationMaskAll
 */
+ (void)setSupportedIpadOrientationMask:(UIInterfaceOrientationMask)orientationMask;

@end
