//
//  YxtRtcVideoCanvas.h
//  YxtRtcEngine
//
//  Created by 朱庆祥 on 2022/1/27.
//

#import <UIKit/UIKit.h>
#import "YxtRtcEngineDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface YxtRtcVideoCanvas : NSObject

@property(nonatomic, strong) UIView * _Nullable view;

@property(assign, nonatomic) YxtVideoRenderMode renderMode;

@property(nonatomic, nonatomic) NSString* _Nullable channelId;

@property(assign, nonatomic) YxtVideoMirrorMode mirrorMode;

@property(nonatomic, assign) YxtStreamType streamType;

@property(nonatomic, copy) NSString *_Nullable Id;

@end

NS_ASSUME_NONNULL_END
