//
//  YxtRtcEngine.h
//  YxtRtcEngine
//
//  Created by dev on 2022/1/7.
//

#import <Foundation/Foundation.h>
#import "YxtRtcEngineDelegate.h"
#import "YxtRtcVideoCanvas.h"
#import "YxtRtcEngineDefines.h"
#import "YxtDeviceManager.h"
#import "YxtBeautyManager.h"
#import "YxtRtcAVConfig.h"
#import "YxtVirtualBackgroundSource.h"

NS_ASSUME_NONNULL_BEGIN

@interface YxtRtcEngine : NSObject

#pragma mark  Core
/// 创建 YxtRtcEngine 实例
/// @param appId 为 app 开发者签发的 App ID
/// @param delegate YxtRtcEngineDelegate
+ (instancetype _Nonnull)sharedEngineWithAppId:(NSString *_Nonnull)appId
        delegate:(id<YxtRtcEngineDelegate> _Nullable)delegate;

/// 销毁 YxtRtcEngine 实例
+ (void)destroy;

/// 加入房间
/// @param config 房间配置
- (int)joinRoomByConfig:(YxtRtcRoomConfig *)config;

/// 离开房间
- (int)leaveRoom;

/// 切换角色
/// @param liveRole 直播角色
- (void)switchRole:(YxtRoleType)liveRole;

#pragma mark Audio

/// 关闭本地音频采集
/// @param enable 开启/关闭
- (int)enableLocalAudio:(BOOL)enable;

/**
   暂停/恢复 本地音频推流

   @param mute true 暂停，false 恢复。默认 false
   @discussion 此api仅仅是暂停/恢复 推视频流，本地预览的视频不受影响
 */
- (void)muteLocalAudio:(BOOL)mute;

/**
   暂停/恢复 音频流
   关闭后，不会有流量消耗
   @param mute true 暂停，false 恢复。默认 false
   @discussion 此api仅仅是暂停/恢复 推音频流，音频采集不受影响
 */
- (void)muteRemoteAudio:(NSString *)uid mute:(BOOL)mute;

/// 暂停/恢复  音频流 仍会有流量消耗
/// @param uid 人员ID
- (void)enableRemoteAudio:(NSString *)uid enable:(BOOL)enable;

#pragma mark Video

- (int)enableLocalVideo:(BOOL)enabled;

/// 暂停/恢复 推本地视频流
/// @param mute 暂停/恢复
- (void)muteLocalVideo:(BOOL)mute;

/// 设置本地预览视图
- (int)setupLocalVideo:(YxtRtcVideoCanvas *_Nullable)local;

/// 设置远端视图
- (int)setupRemoteVideo:(YxtRtcVideoCanvas* _Nonnull)remote;

/// 停止远端视频
- (int)stopRemoteView:(NSString *)uid streamType:(YxtStreamType)streamType;

/// 暂停/恢复 远端视频
- (void)muteRemoteVideo:(NSString *)uid mute:(BOOL)mute streamType:(YxtStreamType)streamType;

/// 暂停/恢复 所有远端视频
- (void)muteAllRemoteVideo:(BOOL)mute;

/// 暂停/恢复 所有远端音频
- (void)muteAllRemoteAudio:(BOOL)mute;

/// 暂停/恢复 渲染远端流
- (void)enableRemoteVideo:(NSString *)uid enable:(BOOL)enable streamType:(YxtStreamType)streamType;

/// 开始本地预览
- (YxtApiCallCode)startPreview;

/// 停止本地预览
- (YxtApiCallCode)stopPreview;

/// 开关相机采集器
- (YxtApiCallCode)enableCamera:(BOOL)enable;

/// 设置视频编码配置
- (void)setVideoEncoderParam:(YxtRtcVideoEncoderConfig *)param;

/// 开始推流
- (YxtApiCallCode)startPublish;

/// 设置视频编码器输出的画面方向
/// 该设置不影响本地画面的预览方向，但会影响房间中其他用户所观看到（以及云端录制文件）的画面方向。 当用户将手机或 Pad 上下颠倒时，由于摄像头的采集方向没有变，所以房间中其他用户所看到的画面会变成上下颠倒的， 在这种情况下，您可以通过调用该接口将 SDK 编码出的画面方向旋转180度，如此一来，房间中其他用户所看到的画面可保持正常的方向。
/// @param rotation    目前支持0和180两个旋转角度，默认值：TRTCVideoRotation_0，即不旋转。
- (BOOL)setVideoEncoderRotation:(YxtVideoRotation)rotation;

//设置重力感应的适配模式(1.0.11)
//您可以通过本接口实现如下这种友好的交互体验： 当用户将手机或 Pad 上下颠倒时，由于摄像头的采集方向没有变，所以房间中其他用户所看到的画面会变成上下颠倒的， 在这种情况下，您可以通过调用该接口让 SDK 根据设备陀螺仪的朝向自动调整本地画面和编码器输出画面的旋转方向，以使远端观众可以看到正常朝向的画面。
- (void)setGSensorMode:(YxtGSensorMode)mode;

/// 停止推流
- (void)stopPublish;

#pragma mark -- Channel
/// 获取查询channel内人员信息
- (void)getChannelUserInfo:(NSString *)channelId
                 onSuccess:(void (^)(NSDictionary *data))onSuccess
                 onFailure:(void (^)(NSError *error))onFailure;

#pragma mark Message
/// 发送消息给房间所有人
- (void)send:(NSString*)message;

/// 发送消息给房间单个人员
- (void)send:(NSString*)message
        to:(NSString*)uid;
#pragma mark -- VirtualBackground
/// 开启/关闭虚拟背景
/// 返回值
/// 0: 方法调用成功。
/// < 0: 方法调用失败。
/// -1：自定义的背景图不存在
/// -2：设备不支持使用虚拟背景
/// -3：未引入segmentationExtension
/// PS:    使用前 请引用用引入  pod 'YxtRtcKit/segmentationExtension'  测试阶段
- (int)enableVirtualBackground:(BOOL)enable backData:(YxtVirtualBackgroundSource* _Nullable)backData;

/// 设备是否支持虚拟背景
/// 该功能对设备性能要求较高,推荐你在搭载如下芯片的设备上使用:
/// 搭载 A9 及以上芯片的如下设备：
/// iPhone 6S 及以上
/// iPad Air 第三代及以上
/// iPad 第五代及以上
/// iPad Pro 第一代及以上
/// iPad mini 第五代及以上
- (BOOL)deviceIsSupportVirtualBackground;

#pragma mark -- Record
/// 开始录制
- (void)startRecord;

/// 停止录制
- (void)stopRecord;

/// 暂停录制
- (void)pauseRecord;

/// 恢复录制
- (void)resumeRecord;

#pragma mark -- Other
/// 获取skd版本
+ (NSString *)getSdkVersion;

/// 获取设备管理
- (YxtDeviceManager *)getDeviceManager;

/// 获取美颜管理
- (YxtBeautyManager *)getBeautyManager;

/// 启动文件日志   默认关闭状态
/// 最多同时存在10个日志，超过10个会删除最早的日志
/// 单个日志最大为10m，日志超过10m后，会被压缩成zip文件，并创建新的log文件继续写入
/// @param path 存放日志的文件夹路径 ，path不能为空，否则无法写入日志
+ (void)startLogWithPath:(NSString *)path;

/// 写入日志信息
+ (void)log:(NSString *)log level:(YxtRtcLogLevel)level;

/// 获取日志路径数组 (ps:查看最新的日志，可以取array.lastObject,最早的日志越靠前)
+ (NSArray <NSURL *>*)getlogFiles:(NSString *)logPath;

@end

NS_ASSUME_NONNULL_END
