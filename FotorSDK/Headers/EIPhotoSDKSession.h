//
//  EIPhotoSDKSession.h
//  EIPhotoSDK
//
//  Created by yanhe on 12/10/13.
//  Copyright (c) 2013年 Everimaging. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 @brief	EIPhotoSDKSession closed notification
 
 when editor's sesstion is closed (by pressing "Cancel" or "Done" button),
 this notification is posted with editor's EIPhotoSDKSession object, before any
 EIPhotoSDKContext related to the session begin to render.
 */
extern NSString *const kEIPhotoEditorSessionCancelledNotification;

@class EIPhotoSDKContext;
/**
 @brief	A session tracks and stores all user
 actions taken in the EIPhotoEditorController it was obtained from.
 */
NS_CLASS_AVAILABLE_IOS(6_0) @interface EIPhotoSDKSession : NSObject

/** Specifies whether the session is still open.
 
 Value will be YES if the generating EIPhotoSDKEditorController has not been dismissed.
 */
@property(nonatomic,assign,readonly) BOOL opened;
/** Specifies if the session has been cancelled.
 
 Value will be YES if the user has invalided all actions by pressing "Cancel" in the generating EIPhotoSDKEditorController.
 */
@property(nonatomic,assign,readonly) BOOL cancelled;
/** Specifies whether the session contains any actions.
 
 Value will be YES if the user has modified the image in the generating EIPhotoSDKEditorController.
 */
@property(nonatomic,assign,readonly) BOOL modified;




/**
 @brief	The maximum pixel size, canvas image (the screen image which rendered in real time ) can be render
 
 @return The maximum size (measured in pixels)
 */
+ (size_t)supportedCanvasImagePixelSize;


/**
 Generates a new EIPhotoSDKContext.
 
 Contexts may be used to replay the session's actions on images. See EIPhotoSDKContext for more information.
 
 @param image The image to generate the context with.
 @return A new photo editor context.
 
 @warning Calling this method from any thread other in the main thread may result in undefined behavior.
 */
- (EIPhotoSDKContext *)createContextWithImage:(UIImage *)image NS_RETURNS_RETAINED;

/**
 Generates a new EIPhotoSDKContext with a maximum size.
 
 @param image The image to generate the context with.
 @param size The maximum size the context should render the image at.
 @return A new photo editor context that can be used to replay the session's actions. See EIPhotoSDKContext.
 
 @warning Calling this method from any thread other in the main thread may result in undefined behavior.
 */
- (EIPhotoSDKContext *)createContextWithImage:(UIImage *)image maxPixelSize:(CGFloat)size NS_RETURNS_RETAINED;

@end
