//
//  YxtVirtualBackgroundSource.h
//  YxtRtcKit
//
//  Created by 朱庆祥 on 2022/5/18.
//

#import <UIKit/UIKit.h>
#import "YxtRtcEngineDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface YxtVirtualBackgroundSource : NSObject
@property(nonatomic, assign) YxtVirtualBackgroundSourceType backgroundSourceType;
@property(nonatomic, strong) UIColor *color;
@property(nonatomic, strong) UIImage *backgroundImg;
@property(nonatomic, assign) YxtBlurDegree blurDegree;
@end

NS_ASSUME_NONNULL_END
