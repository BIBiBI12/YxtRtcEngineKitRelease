//
//  YxtUserInfo.h
//  YxtRtcEngine
//
//  Created by 朱庆祥 on 2022/2/17.
//

#import <Foundation/Foundation.h>
#import "YxtRtcEngineDefines.h"
NS_ASSUME_NONNULL_BEGIN

@interface YxtUserInfo : NSObject
@property(nonatomic, strong) NSString *uid;
@property(nonatomic, strong) NSString *name;
@property(nonatomic, strong) NSString *roomId;

@end

NS_ASSUME_NONNULL_END

