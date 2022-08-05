//
//  YxtBeautyManager.h
//  YxtRtcEngine
//
//  Created by 朱庆祥 on 2022/3/2.
//

#import <Foundation/Foundation.h>
#import "YxtRtcEngineDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface YxtBeautyManager : NSObject

- (void)openBeauty:(BOOL)open;

// 功能正常 但后期会改动 建议不要使用
//- (void)changeBeautyStyle:(YxtBeautyStyle)beautyStyle;

// [0,1] 0.5 为原始饱和度
- (void)setFilterSaturation:(float)saturation;

// 设置滤镜磨皮程度 [0,1] 0 为原始
- (void)setFilterBuffing:(float)buffing;

// 设置美白程度 [0,1] 0 为原始
- (void)setWhitenessLevel:(float)whitenessLevel;

@end

NS_ASSUME_NONNULL_END
