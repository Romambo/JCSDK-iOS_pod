//
//  JC_unityAdApi.h
//  Unity-iPhone
//
//  Created by MS on 2020/9/2.
//

#import <Foundation/Foundation.h>

typedef void (^unityBlock)(BOOL showUnityTime);
NS_ASSUME_NONNULL_BEGIN

#if defined (__cplusplus)


extern "C"
{

/// Intersitial Ads isReady
bool isReadyIntersitial();

/// show Intersitial Ads
void showIntersitial();

/// rewardVideo Ads isReady
bool isReadyRewardVideo();

/// show rewardVideo Ads
void showRewardVideo();

/// isReady - banner
bool isReadyBanner();

/// show banner Ads
void showBannerView();

/// remove banner Ads
void removeBannerView();

/// Send Event UMeng、talkingData
/// @param event event
/// @param jsonEventInfo key-value converted json string, if there is no content to pass, you can set a null value
void sendEvent(char *event,char *jsonEventInfo);

}

#endif

#if defined (__cplusplus)

#endif



@interface JC_unityAdApi : NSObject
+(instancetype)getInstance;


/// Initialize sdk
/// @param isOpenLog Log Switch YES/NO
/// @param isShow  YES/NO
/// @param block block
-(void)initJCSDKWithLog:(BOOL)isOpenLog isFirstShowSplash:(BOOL)isShow splashClose:(unityBlock)block;
@end

NS_ASSUME_NONNULL_END
