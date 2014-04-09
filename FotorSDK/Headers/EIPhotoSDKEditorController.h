//
//  EIPhotoSDKEditorController.h
//  EIPhotoSDK
//
//  Created by ChenQi on 13-12-20.
//  Copyright (c) 2013年 Everimaging. All rights reserved.
//

#import <Foundation/Foundation.h>

@class EIPhotoSDKEditorController;
@protocol EIPhotoSDKEditorControllerDelegate <NSObject>
@optional

/**
 Implement this method to be notified when the user presses the "Done" button.
 
 The edited image is passed via the `image` parameter. The size of this image may
 not be equivalent to the size of the input image, if the input image is larger
 than the maximum image size supported by the SDK.
 call `supportedCanvasImagePixelSize` in EIPhotoSDKSession to check the maximum supported image size.
 
 
 @param editor The photo editor controller.
 @param image The edited image.
 
 */
- (void)photoEditor:(EIPhotoSDKEditorController *)editor didFinishedWithImage:(UIImage *)image;

/**
 Implement this method to be notified when the user presses the "Cancel" button.
 
 @param editor The photo editor controller.
 */
- (void)photoEditorDidCancel:(EIPhotoSDKEditorController *)editor;

@end


@class EIPhotoSDKSession;
NS_CLASS_AVAILABLE_IOS(6_0) @interface EIPhotoSDKEditorController : UINavigationController

@property(nonatomic,weak) id<EIPhotoSDKEditorControllerDelegate> editorDelegate;

- (EIPhotoSDKSession *)session;

@end
