//
//  YxtRtcStatistics.h
//  YxtRtcEngine
//
//  Created by 朱庆祥 on 2022/2/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KTRtcLocalStatistics : NSObject

@property (nonatomic, assign) int fps;

@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;

@property (nonatomic, copy) NSString *ip;

/** 当前视频发送码率 */
@property (nonatomic, copy) NSString *videoBitrate;
@property (nonatomic, assign) double videoBitrateValue;

/** 当前音频发送码率 */
@property (nonatomic, copy) NSString *audioBitrate;
@property (nonatomic, assign) double audioBitrateValue;

/** 丢包率 */
@property (nonatomic, assign) double packetsLossRate;

/** 视频丢包率 */
@property (nonatomic, copy) NSString *videoPacketsLossRate;

/** 音频丢包率 */
@property (nonatomic, copy) NSString *audioPacketsLossRate;

/** 视频发送信息 */
@property (nonatomic, strong) NSDictionary *videoInfo;

/** 音频发送信息 */
@property (nonatomic, strong) NSDictionary *audioInfo;

@end

@interface KTRtcRemoteStatistics : NSObject

@property (nonatomic, assign) int fps;

@property (nonatomic, assign) int width;
@property (nonatomic, assign) int height;

@property (nonatomic, copy) NSString *ip;

/** 当前视频流接受码率 */
@property (nonatomic, copy) NSString *videoBitrate;
@property (nonatomic, assign) double videoBitrateValue;

/** 当前音频流接受码率 */
@property (nonatomic, copy) NSString *audioBitrate;
@property (nonatomic, assign) double audioBitrateValue;

/** 丢包率 */
@property (nonatomic, assign) double packetsLossRate;

/** 视频丢包率 */
@property (nonatomic, copy) NSString *videoPacketsLossRate;

/** 音频丢包率 */
@property (nonatomic, copy) NSString *audioPacketsLossRate;

/** 视频接受信息 */
@property (nonatomic, strong) NSDictionary *videoInfo;

/** 音频接受信息 */
@property (nonatomic, strong) NSDictionary *audioInfo;

@property (nonatomic, assign) double rtt;

@end


@interface YxtRtcStatistics : NSObject

/** uid */
@property (nonatomic, copy) NSString *uid;

/** 是否是本地流 */
@property (nonatomic, assign) BOOL isLocalStream;

/** 延时 */
@property (nonatomic, copy) NSString *rtt;

/** 网络连接情况 */
@property (nonatomic, strong) NSDictionary *videoBwe;

/** 本地流统计信息 */
@property (nonatomic, strong) KTRtcLocalStatistics *localStatistics;

/** 远端流统计信息 */
@property (nonatomic, strong) KTRtcRemoteStatistics *remoteStatistics;

@property (nonatomic, copy) NSString *send_index;
@property (nonatomic, copy) NSString *send_a;
@property (nonatomic, copy) NSString *send_ak;
@property (nonatomic, copy) NSString *send_v;
@property (nonatomic, copy) NSString *send_vk;
@property (nonatomic, copy) NSString *send_N;

@property (nonatomic, copy) NSString *recv_index;
@property (nonatomic, copy) NSString *recv_a;
@property (nonatomic, copy) NSString *recv_ak;
@property (nonatomic, copy) NSString *recv_v;
@property (nonatomic, copy) NSString *recv_vk;
@property (nonatomic, copy) NSString *recv_N;

@end

NS_ASSUME_NONNULL_END
