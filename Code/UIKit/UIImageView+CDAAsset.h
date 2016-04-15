//
//  UIImageView+CDAAsset.h
//  ContentfulSDK
//
//  Created by Boris Bügling on 13/03/14.
//
//

#if __has_feature(modules)
@import UIKit;
#else
#import <UIKit/UIKit.h>
#endif

#import <ContentfulDeliveryAPI/CDAPersistedAsset.h>
#import "CDAAsset.h"

typedef void(^CDAImageCompletionBlock)(CDAAsset * __nonnull, UIImage * __nullable image);

/**
 Convenience category on `UIImageView` which allows asynchronously setting its image from a given
 Asset.
 
 Attempting non-sensical operations like using an Asset pointing to a video will throw exceptions.
 */
@interface UIImageView (CDAAsset)

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background.
 *
 *  @param asset An Asset pointing to an image.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithAsset:(CDAAsset* __nonnull)asset;

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background.
 *
 *  @param asset An Asset pointing to an image.
 *  @param size             The desired size of the image. It will be resized by the server.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithAsset:(CDAAsset* __nonnull)asset size:(CGSize)size;

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background.
 *
 *  @param asset An Asset pointing to an image.
 *  @param size             The desired size of the image. It will be resized by the server.
 *  @param format The desired image format (e.g. PNG, JPEG, Original)
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
- (void)cda_setImageWithAsset:(CDAAsset * __nonnull)asset size:(CGSize)size format:(CDAImageFormat)format;

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background.
 *
 *  @param asset An Asset pointing to an image.
 *  @param size             The desired size of the image. It will be resized by the server.
 *  @param quality The quality of the desired image
 *  @param format The desired image format (e.g. PNG, JPEG, Original)
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
- (void)cda_setImageWithAsset:(CDAAsset * __nonnull)asset size:(CGSize)size quality:(CGFloat)quality format:(CDAImageFormat)format;

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background. Until the image is loaded,
 *  the `placeholderImage` is displayed.
 *
 *  @param asset            An Asset pointing to an image.
 *  @param placeholderImage An alternative image which will be displayed until `asset` is loaded.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithAsset:(CDAAsset* __nonnull)asset
            placeholderImage:(UIImage* __nullable)placeholderImage;

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background. Until the image is loaded,
 *  the `placeholderImage` is displayed.
 *
 *  @param asset            An Asset pointing to an image.
 *  @param size             The desired size of the image. It will be resized by the server.
 *  @param placeholderImage An alternative image which will be displayed until `asset` is loaded.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithAsset:(CDAAsset* __nonnull)asset
                        size:(CGSize)size
            placeholderImage:(UIImage* __nullable)placeholderImage;

- (void)cda_setImageWithAsset:(CDAAsset * __nonnull)asset
                         size:(CGSize)size
             placeholderImage:(UIImage* __nullable)placeholderImage
                      quality:(CGFloat)quality
                       format:(CDAImageFormat)format;

- (void)cda_setImageWithAsset:(CDAAsset * __nonnull)asset
                         size:(CGSize)size
             placeholderImage:(UIImage* __nullable)placeholderImage
                      quality:(CGFloat)quality
                       format:(CDAImageFormat)format
                   completion:(CDAImageCompletionBlock __nullable)completion;

/**
 *  Loads an image for the given Asset, and returns it in the completion block, This does not set the image of the UIImageView.
 *
 *  This will happen asynchronously in the background. Until the image is loaded,
 *  the `placeholderImage` is displayed.
 *
 *  @param asset            An Asset pointing to an image.
 *  @param size             The desired size of the image. It will be resized by the server.
 *  @param quality          The desired quality of the image.
 *  @param format           The desired image format.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
- (NSURLSessionDataTask * __nonnull)cda_loadImageWithAsset:(CDAAsset * __nonnull)asset size:(CGSize)size quality:(CGFloat)quality format:(CDAImageFormat)format completion:(CDAImageCompletionBlock __nullable)completion;

/**
 *  Set this image view's image to the image file retrieved from the given Asset.
 *
 *  This will happen asynchronously in the background. Until the image is loaded,
 *  the `placeholderImage` is displayed.
 *
 *  @param asset            An Asset pointing to an image.
 *  @param client           The client object to use for requests to Contentful.
 *  @param size             The desired size of the image. It will be resized by the server.
 *  @param placeholderImage An alternative image which will be displayed until `asset` is loaded.
 *  @exception NSIllegalArgumentException If the Asset is pointing to an image.
 */
-(void)cda_setImageWithPersistedAsset:(id<CDAPersistedAsset> __nonnull)asset
                               client:(CDAClient* __nonnull)client
                                 size:(CGSize)size
                     placeholderImage:(UIImage * __nullable)placeholderImage;

/** @name Use Offline Caching */

/** Enable automatic disk caching of any image loaded by one of the Asset category methods. */
@property (nonatomic) BOOL offlineCaching_cda;

@end
