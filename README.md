FotorSDK-iOS
============

[FotorSDK](https://github.com/Fotor/FotorSDK-iOS.git) is a complete set of photo editing tools comes standard in Fotor’s all-platform SDK. You can select the tools that are best for your app, or use them all.

Get more info and downloads of FotorSDK (for iOS and Android) via [the FotorSDK mobile portal](https://github.com/Fotor)

[Click here for **official documentation for FotorSDK-iOS**](https://github.com/Fotor/FotorSDK-iOS/wiki/API-Documentation)


Installing
---

The easiest way to use FotorSDK is to add all the files in the FotorSDK-iOS group (or directory) into your app with "Create groups for any added folders" option of Xcode. 

Add the following frameworks to your project (Build Phases > Link Binary With Libraries): `AssetsLibrary`, `AVFoundation`, `CoreGraphics`, `CoreMedia`, `GLKit`, `OpenGLES`, `libsdtc++.6.0.9.dylib` or (`libsdtc++.dylib` if necessary), `ImageIO`, `libsqlite`, `CoreData`, `StoreKit`, `MobileCoreServices`, `CoreTelephony`, `SystemConfiguration`, `libz`.

Add the linker flags to your project (Build Settings > Linking > other Linker Flags): `-ObjC`.

[Detail Illustration Description](https://github.com/Fotor/FotorSDK-iOS/wiki/Linking-FotoSDK-Into-Your-Own-App)

##### Or git submodule

Alternatively, you should be able to setup a [git submodule](http://git-scm.com/docs/git-submodule) and reference the files in your Xcode project.

`git submodule add https://github.com/Fotor/FotorSDK-iOS.git`

<!--
##### Or CocoaPods
 
[CocoaPods](http://cocoapods.org/) is a dependency manager for Objective-C projects.

`pod 'FotorSDK-iOS'`
-->

Usage
---
Getting started with FotorSDK-iOS is very simple. After initializing an instance of EIPhotoSDKEditorController with a UIImage and setting a proper delegate, you can use the instance as a normal UIViewController. [Demo apps](https://github.com/koluray/ImageEditor-ios)


```  objc

#import "EIPhotoSDK.h"

@interface ViewController() <EIPhotoSDKEditorControllerDelegate>
{
	NSMutableArray *_editorSessions;
}

@end

- (void)launchPhotoEditorWithImage:(UIImage *)editingResImage highResolutionImage:(UIImage *)highResImage
{
    EIPhotoSDKEditorController *ctrler = [EIPhotoSDK photoEditorControllerWithImage:editingResImage error:NULL];
    ctrler.editorDelegate = self;
    
    // If you want output a high resolution image, create the high resolution context with the image and the
    // photo editor by un-commenting the lines below.
    
    // Note: This is optional
    
    //if (nil != highResImage) {
    //    [self setupHighResContextForPhotoEditor:ctrler withImage:highResImage];
    //}
    
    // Make the photo editor to user.
    [self presentViewController:ctrler animated:YES completion:nil];
}

- (void)setupHighResContextForPhotoEditor:(EIPhotoSDKEditorController *)photoEditor withImage:(UIImage *)highResImage
{
    // Capture a reference to the editor's session, which internally tracks user actions on a photo.
    EIPhotoSDKSession *session = [photoEditor session];
    [_editorSessions addObject:session];
    
    EIPhotoSDKContext *context = [session createContextWithImage:highResImage];
    [context renderWithBegin:nil complete:^(UIImage *result, BOOL completed) {
        if (nil != result) {
            // Get the high resolution result image from here 
        }
    }];
}

```

If you are working with UIImagePickerController, here's some sample code you can use for free.

```  objc

#pragma mark - UIImageController delegate

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    NSURL *assetURL = info[UIImagePickerControllerReferenceURL];
    void(^completion)(void)  = ^(void){
        
        ALAssetsLibrary *assetsLibrary = [[ALAssetsLibrary alloc] init];
        [assetsLibrary assetForURL:assetURL resultBlock:^(ALAsset *asset) {
            if (asset){
                UIImage *screenImage = [self editingResImageForAsset:asset];
                UIImage *fullResolutionImage = [self highResImageForAsset:asset];
                [self launchPhotoEditorWithImage:screenImage highResolutionImage:fullResolutionImage];
                _noPhotoView.hidden = YES;
            }
        } failureBlock:^(NSError *error) {
            [[[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Error", nil)
                                        message:NSLocalizedString(@"Please enable access to your device's photos.", nil)
                                       delegate:nil
                              cancelButtonTitle:NSLocalizedString(@"OK", nil)
                              otherButtonTitles:nil] show];
        }];
    };
    
    [self dismissViewControllerAnimated:YES completion:completion];
}


#pragma mark - ALAssets Helper Methods

- (UIImage *)editingResImageForAsset:(ALAsset *)asset
{
    CGImageRef image = [[asset defaultRepresentation] fullScreenImage];
    return [UIImage imageWithCGImage:image scale:1.0 orientation:UIImageOrientationUp];
}

- (UIImage *)highResImageForAsset:(ALAsset*)asset
{
    ALAssetRepresentation * representation = [asset defaultRepresentation];
    
    CGImageRef image = [representation fullResolutionImage];
    UIImageOrientation orientation = (UIImageOrientation)[representation orientation];
    CGFloat scale = [representation scale];
    
    return [UIImage imageWithCGImage:image scale:scale orientation:orientation];
}


```

After an image has been edited, the editor will call delegate's `photoEditor:didFinishedWithImage:` method. The delegate's method is required to receive the edited image.

```  objc

#pragma mark - EIPhotoSDKEditorControllerDelegate

- (void)photoEditor:(EIPhotoSDKEditorController *)editor didFinishedWithImage:(UIImage *)image
{
    //Got screen size edited image from here
    _imageView.image = image;
    [editor dismissViewControllerAnimated:YES completion:nil];
}

```

Additionally, the optional delegate's method photoEditorDidCancel: will be called when image editing is cancelled by the user.
For more detail,  please see [Demo apps](https://github.com/koluray/ImageEditor-ios).


Customizing
---

##### Menu customization

Editor menu tools can be customized by using [EIPhotoEditorCustomization's setToolOrder](https://github.com/Fotor/FotorSDK-iOS/wiki) method.

```  objc

- (void)setPhotoEditorCustomizationOptions
{
    /*
    // set status bar hidden here, when editor opened
    [EIPhotoEditorCustomization setStatusBarHidden:NO];
     */
    
    /*
    // set status bar style when status bar not hide, only available for iOS7 and later
    [EIPhotoEditorCustomization setStatusBarStyle:UIStatusBarStyleLightContent];
     */

    /*
    // set supported orientation on ipad, default is UIInterfaceOrientationMaskAll
    if (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad) {
        [EIPhotoEditorCustomization setSupportedIpadOrientationMask:UIInterfaceOrientationMaskLandscape];
    }
     */
    
    // set editor toolbar supported module, you can specify all the moduls in EIPhotoEditorCustomization in any order, or skip any of them
    [EIPhotoEditorCustomization setToolOrder:@[kEIEnhance, kEIScene, kEIBaseAdjust, kEIAdvanceAdjust, kEIEffect, kEIRotate, kEICrop, kEIFrame, kEISticker, kEIText, kEITiltshift]];
}

```

then you update the `launchPhotoEditorWithImage:highResolutionImage:` method like this:

```  objc

- (void)launchPhotoEditorWithImage:(UIImage *)editingResImage highResolutionImage:(UIImage *)highResImage
{
 // Customize the editor's apperance. The customization options really only need to be set once in this case since they are never changing, so we used dispatch once here.
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        [self setPhotoEditorCustomizationOptions];
    });
    
    [_editorSessions removeAllObjects];
    
    EIPhotoSDKEditorController *ctrler = [EIPhotoSDK photoEditorControllerWithImage:editingResImage error:NULL];
    ctrler.editorDelegate = self;
    
    // If a high res image is passed, create the high res context with the image and the photo editor.
    if (nil != highResImage) {
        [self setupHighResContextForPhotoEditor:ctrler withImage:highResImage];
    }
    
    // Present the photo editor.
    [self presentViewController:ctrler animated:YES completion:nil];
}

```


###### Specify Output image size

You can set Output image size with [EIPhotoSDKContext's createContextWithImage:maxPixelSize:error](https://github.com/Fotor/FotorSDK-iOS/wiki) method

``` objc

- (void)setupHighResContextForPhotoEditor:(EIPhotoSDKEditorController *)photoEditor withImage:(UIImage *)highResImage
{
    // Capture a reference to the editor's session, which internally tracks user actions on a photo.
    EIPhotoSDKSession *session = [photoEditor session];
    [_editorSessions addObject:session];
    
    NSError *error = nil;
    EIPhotoSDKContext *context = [session createContextWithImage:highResImage maxPixelSize:MAXFLOAT error:&error];
    [context renderWithBegin:nil complete:^(UIImage *result, BOOL completed) {
        if (nil != result) {
            // now, you got the result image 
        }
    }];
}

```

TODO
---

**Draw, Color splash**

**Real time effect camera**

**Dynamic sticker**


Credits
---

**Design, coding:** [Dake](https://github.com/dake), [ArcRain](https://github.com/ArcRain), [wysaid](https://github.com/wysaid)

**Powered by [**fotor**](http://www.fotor.com)**

License
---
FotorSDK-iOS is released under the MIT License, see [LICENSE](LICENSE).
