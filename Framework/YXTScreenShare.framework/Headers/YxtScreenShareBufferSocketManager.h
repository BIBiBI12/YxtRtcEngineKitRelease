//
//  KTScreenShareBufferSocketManager.m
//  KTScreenShare
//
//  Created by 朱庆祥 on 2022/8/2.
//


#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>

NS_ASSUME_NONNULL_BEGIN

@interface YxtScreenShareBufferSocketManager : NSObject

@property(nonatomic, copy) void (^getBuffer)(CMSampleBufferRef sampleBuffer);

+ (YxtScreenShareBufferSocketManager *)sharedManager;
- (void)stopSocket;
- (void)setupSocket;

@end

NS_ASSUME_NONNULL_END
