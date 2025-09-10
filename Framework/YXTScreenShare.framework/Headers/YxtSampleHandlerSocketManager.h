//
//  KTSampleHandlerSocketManager.m
//  KTScreenShare
//
//  Created by 朱庆祥 on 2022/8/2.
//


#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol YxtSampleHandlerSocketManagerDelegate <NSObject>

@required
- (void)screenShareFinishBroadcastWithError:(NSError *)error;
@end

@interface YxtSampleHandlerSocketManager : NSObject

@property (nonatomic, weak) id<YxtSampleHandlerSocketManagerDelegate> delegate;

+ (YxtSampleHandlerSocketManager *)sharedManager;

- (void)processSampleBuffer:(CMSampleBufferRef)sampleBuffer
                   withType:(RPSampleBufferType)sampleBufferType;


- (void)broadcastStartedWithSetupInfo:(NSDictionary<NSString *,NSObject *> *)setupInfo;

- (void)broadcastPaused;

- (void)broadcastResumed;

- (void)broadcastFinished;

@end

NS_ASSUME_NONNULL_END
