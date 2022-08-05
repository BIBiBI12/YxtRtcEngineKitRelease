//
//  YxtRtcAVConfig.h
//  AFNetworking
//
//  Created by 朱庆祥 on 2022/2/11.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "YxtRtcEngineDefines.h"

NS_ASSUME_NONNULL_BEGIN

// 视频编码配置
@interface YxtRtcVideoEncoderConfig : NSObject

/**  视频编码输出分辨率 */
@property (assign) YxtResolutionPreset videoEncodeResolution;
/**  视频帧率 */
@property (assign) int videoFps;
/**  最小视频码率 */
@property (assign) int minVideoBitrate;
/**  最大视频码率 */
@property (assign) int maxVideoBitrate;
/**  摄像头方向 */
@property(assign) AVCaptureDevicePosition devicePosition;

@end

// 音频编码配置
@interface YxtRtcAudioEncoderConfig : NSObject


@end


NS_ASSUME_NONNULL_END
