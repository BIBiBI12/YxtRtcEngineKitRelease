//
//  YxtEnumerates.h
//  Pods
//
//  Created by 朱庆祥 on 2022/1/27.
//

#ifndef YxtEnumerates_h
#define YxtEnumerates_h

/** 角色 */
typedef NS_ENUM(NSUInteger, YxtRoleType) {
    /** 主播 */
    YxtRoleAnchor = 0,
    /** 观众 */
    YxtRoleAudience = 1,
};

/** 场景 */
typedef NS_ENUM(NSUInteger, YxtAppScene) {
    /** 会议场景 */
    YxtAppSceneMeeting = 0,
    /** 视频通话场景 */
    YxtAppSceneVideoCall = 1,
    /** 语音通话场景 */
    YxtAppSceneAudioCall = 2,
    /** 视频互动直播 */
    YxtAppSceneLIVE = 3,
    /** 语音互动直播 */
    YxtAppSceneVoiceChatRoom = 4,
};

/** 视频渲染模式. */
typedef NS_ENUM(NSUInteger, YxtVideoRenderMode) {
    /** 等比缩放，可能有黑边 */
    YxtRtcVideoViewModeScaleAspectFit     = 0,
    /** 等比缩放填充整View，可能有部分被裁减 */
    YxtRtcVideoViewModeScaleAspectFill    = 1,
    /** 填充整个View */
    YxtRtcVideoViewModeScaleToFill        = 2,
};

/** 视频镜像模式 */
typedef NS_ENUM(NSUInteger, YxtVideoMirrorMode) {
  /** 0: (Default) The SDK determines the mirror mode.
   */
  YxtVideoMirrorModeAuto = 0,
  /** 1: Enables mirror mode. */
  YxtVideoMirrorModeEnabled = 1,
  /** 2: Disables mirror mode. */
  YxtVideoMirrorModeDisabled = 2,
};


/** 流类型 */
typedef NS_ENUM(NSUInteger, YxtStreamType) {
    //高清大画面，一般用来传输摄像头的视频数据
    YxtVideoStreamTypeBig = 0,
    //低清小画面：小画面和大画面的内容相互，但是分辨率和码率都比大画面低，因此清晰度也更低。
    YxtVideoStreamTypeSmall = 1,
    //辅流画面：一般用于屏幕分享，同一时间在同一个房间中只允许一个用户发布辅流视频，其他用户必须要等该用户关闭之后才能发布自己的辅流。
    YxtVideoStreamTypeSub = 2,
};

/** 视频分辨率 */
typedef enum {
    YxtResolutionPreset120p    = 1,
    YxtResolutionPreset180p    = 2,
    YxtResolutionPreset240p    = 3,
    YxtResolutionPreset360p    = 4,
    YxtResolutionPreset480p   = 5,
    YxtResolutionPreset720p   = 6,
    YxtResolutionPreset1080p   = 7,
} YxtResolutionPreset;


/** 方法调用返回值 */
typedef NS_OPTIONS(NSInteger, YxtApiCallCode) {
    YxtRtcApiCallCodeSuccess = 0,
    YxtRtcApiCallCodeParamsNil = -1,
    YxtRtcApiCallCodeDisableVideo = -2,
    YxtRtcApiCallCodeDisableAudio = -3,
    YxtRtcApiCallCodeDisablePublish = -4,
    YxtRtcApiCallCodeFailure = -100
};

typedef NS_ENUM(NSInteger, YxtWarningCode) {
    YxtWarningCodeInvalidView = 8,
    YxtWarningCodeSendMessagefail = 9,
};

typedef NS_ENUM(NSInteger, YxtLeaveRoomResonCode) {
    YxtLeaveRoomBySelf = 0,
    YxtLeaveRoomDropBySer = 1,
    YxtLeaveRoomSerDisconnect = 2,
};

typedef NS_ENUM(NSInteger, YxtErrorCode) {
    YxtErrorCodeNoError = 0,
    YxtErrRoomEnterFail = -3301,
    YxtErrRoomLeaveFail = -3302,
    YxtErrSubscriberFail = -3304,
    YxtErrSwitchRoleFail = -3305,
    YxtErrRecordFail = -3306,
    YxtErrControlAsrFail = -3307,
};

typedef NS_ENUM(NSUInteger, YxtStreamPublishState ) {
    YxtStreamPublishIdle = 0,
    YxtStreamPublishNoPublished = 1,
    YxtStreamPublishPublishing = 2,
    YxtStreamPublishPublished = 3,
};

typedef NS_ENUM(NSUInteger, YxtRecordState ) {
    // 停止录制
    YxtRecordStateStopped = 0,
    // 录制中
    YxtRecordStateRecording = 1,
    // 暂停录制
    YxtRecordStatePause = 2,
};

typedef NS_ENUM(NSUInteger, YxtCaptureState ) {
    // 屏幕共享 进程开启
    YxtLocalVideoStreamCaptureStarted = 0,
    // 屏幕共享 进程停止
    YxtLocalVideoStreamCaptureStoped = 1,
    // 屏幕共享 进程异常
    YxtLocalVideoStreamCaptureDisconnected = 2,
};

typedef NS_ENUM(NSUInteger, YxtAudioRoute ) {
    YxtAudioRouteSpeakerphone = 0,
    YxtAudioRouteEarpiece = 1,
};

typedef NS_ENUM(NSUInteger, YxtBeautyStyle ) {
    YxtBeautyNoneStyle = 0,
    YxtBeautyDefaultStyle = 1,
    YxtBeautyStyle2 = 2,
};

typedef NS_ENUM(NSInteger, YxtVideoRotation) {
    YxtVideoRotation_0 = 0,
    YxtVideoRotation_90 = 90,
    YxtVideoRotation_180 = 180,
    YxtVideoRotation_270 = 270,
};

/**重力感应开关*/
typedef NS_ENUM(NSInteger, YxtGSensorMode) {
    YxtGSensorMode_Disable = 0,
    YxtGSensorMode_UIAutoLayout = 1,
};

/** 日志级别 */
typedef enum {
    YxtRtcLogLevel_debug = 2,
    YxtRtcLogLevel_info  = 3,
    YxtRtcLogLevel_warn  = 4,
    YxtRtcLogLevel_error = 5,
} YxtRtcLogLevel;

/** 虚拟背景类型*/
typedef enum {
    // 纯色图
    YxtVirtualBackgroundColor = 0,
    // 背景图为 PNG、JPG 格式的图片
    YxtVirtualBackgroundImg  = 1,
    // 将虚化处理后的背景作为背景图。
    YxtVirtualBackgroundBlur  = 2,
} YxtVirtualBackgroundSourceType;

/** 虚化程度。*/
typedef enum {
    //（默认）自定义背景图的虚化程度为高。用户很难看清背景。
    YxtBlurHigh  = 0,
    // 自定义背景图的虚化程度为中。用户较难看清背景
    YxtBlurMedium  = 1,
    // 自定义背景图的虚化程度为低。用户差不多能看清背景。
    YxtBlurLow = 2,
} YxtBlurDegree;


typedef enum {
    // 只要最后识别结果，省略中间过程
    YxtOnlyResult = 0,
    // 需要中间识别过程
    YxtIntermediateResult = 1,
} YxtAsrResultType;

@interface YxtRtcRoomConfig : NSObject
@property(nonatomic, copy) NSString *appId;
@property(nonatomic, copy) NSString *token;
@property(nonatomic, assign) YxtAppScene scene;
@property(nonatomic, assign) YxtRoleType liveRole;
@end

#endif /* YxtEnumerates_h */
