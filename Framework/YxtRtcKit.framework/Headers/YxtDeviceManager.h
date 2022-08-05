//
//  YxtDeviceManager.h
//  YxtRtcEngine
//
//  Created by 朱庆祥 on 2022/2/16.
//

#import <Foundation/Foundation.h>
#import "YxtRtcEngineDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface YxtDeviceManager : NSObject

/// 切换前后摄像头
/// @param frontCamera 前/后
- (BOOL)switchCamera:(BOOL)frontCamera;

/// 是否为前置摄像头
- (BOOL)isFrontCamera;

/// 设置扬声器/听筒 播放
- (BOOL)setAudioRoute:(YxtAudioRoute)route;

@end

NS_ASSUME_NONNULL_END
