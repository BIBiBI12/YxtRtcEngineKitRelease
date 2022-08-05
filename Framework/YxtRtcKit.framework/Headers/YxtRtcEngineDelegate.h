//
//  YxtRtcEngineDelegate.h
//  YxtRtcEngine
//
//  Created by dev on 2022/1/18.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import "YxtRtcEngineDefines.h"
#import "YxtUserInfo.h"
#import "YxtRtcStatistics.h"
@class YxtRtcEngine;
@class YXT_GPUImageOutput;

NS_ASSUME_NONNULL_BEGIN

@protocol YxtRtcEngineDelegate <NSObject>
@required
//错误事件，表示 SDK 抛出的不可恢复的错误，比如进入房间失败或设备开启失败等
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine didOccurError:(YxtErrorCode)errorCode extInfo:(NSDictionary *)extInfo;
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine didOccurWarning:(YxtWarningCode)warningCode extInfo:(NSDictionary *)extInfo;
@optional

- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine didJoinChannel:(NSString *_Nonnull)channel userInfo:(YxtUserInfo *)userInfo elapsed:(NSInteger)elapsed;

/// 离开channel的事件回调
/// @param reson  离开房间原因，0：主动调用 exitRoom 退出房间；1：被服务器踢出当前房间；2：当前房间整个被解散。
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine didLeaveRoomWithReson:(YxtLeaveRoomResonCode)reson;

/// 推流状态改变
/// @param channel channel id
/// @param oldState 上一次状态
/// @param newState 最新状态
/// @param elapseSinceLastState 两次状态变化时间间隔
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine didVideoPublishStateChange:(NSString *_Nonnull)channel oldState:(YxtStreamPublishState)oldState newState:(YxtStreamPublishState)newState elapseSinceLastState:(NSInteger)elapseSinceLastState;

///  远端用户/主播加入回调
///  通信场景下: 远端用户加入
///  直播场景下: 主播用户加入，观众不会触发。 如果在加入之前，
///          已经有主播在频道中了，新加入的用户也会收到已有主播加入频道的回调。
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine didJoinedOfUserInfo:(YxtUserInfo *)userInfo;

/// 远端用户（通信场景）/主播（直播场景）离开当前频道回调
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine didOfflineUserInfo:(YxtUserInfo *)userInfo;

/// 用户角色切换回调
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine onUserChangeRole:(NSString *)uid role:(YxtRoleType)role;

/// 远端用户发布/取消发布流
/// 当您收到 onUserVideoAvailable(userId, NO) 通知时，表示该路远程画面已经被关闭，关闭的原因可能是该用户调用了 muteLocalVideo 或 enableLocalVideo(NO)。
/// @param uid 远端用户id
/// @param available 用户是否发布（或取消发布）了主路视频画面，YES: 发布；NO：取消发布。
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine onUserVideoAvailable:(NSString *)uid available:(BOOL)available;

/// 远端用户发布/取消发布音频流
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine onUserAudioAvailable:(NSString *)uid available:(BOOL)available;

/// 远端用户发布/取消发布辅佐流 （一般为共享流）
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine onUserSubStreamAvailable:(NSString *)uid available:(BOOL)available;

/// 收到首帧渲染事件
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine onFirstVideoFrame:(NSString *)uid width:(int)width height:(int)height;

/// 远端视频尺寸变化
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine onVideoSizeChange:(NSString *)uid width:(int)width height:(int)height;

#pragma mark -- 与云端连接情况的事件回调
/// SDK 与云端的连接已经断开
- (void)rtcEngineOnConnectionLost:(YxtRtcEngine *_Nonnull)engine;

/// SDK 与云端尝试重新连接
- (void)rtcEngineOnTryToReconnect:(YxtRtcEngine *_Nonnull)engine;

/// SDK 与云端的连接已经恢复
- (void)rtcEngineOnConnectionRecovery:(YxtRtcEngine *_Nonnull)engine;

#pragma mark -- 音量信息
/// soundLevel 远端流音量更新回调
/// @param energy energy 音量大小
/// @param uid 用户id
- (void)onSoundLevelUpdate:(double)energy uid:(NSString *)uid;

/// captureSoundLevel 更新回调
/// @param energy 采集音量大小
- (void)onCaptureSoundLevelUpdate:(double)energy;

#pragma mark -- 消息
- (void)rtcEngine:(YxtRtcEngine *_Nonnull)engine
        didReceiveMessage:(NSString*)message
        from:(NSString*)senderId
        isGroupMessage:(BOOL)isGroupMessage;

#pragma mark -- 统计信息
/// 流统计信息回调
/// @param statistics 统计信息
- (void)onStatistics:(YxtRtcStatistics *)statistics;

#pragma mark -- 录制状态
- (void)onRecordState:(YxtRecordState)recordState;

@end

NS_ASSUME_NONNULL_END
