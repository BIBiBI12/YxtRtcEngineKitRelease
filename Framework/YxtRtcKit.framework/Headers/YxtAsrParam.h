//
//  YxtAsrParam.h
//  YxtRtcKit
//
//  Created by 朱庆祥 on 2022/10/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface YxtAsrParam : NSObject

@property(nonatomic, assign, readonly) BOOL status; 

@property(nonatomic, assign) BOOL tingwu; //听悟多路模式  默认 NO

@property(nonatomic, assign) BOOL intermediateResult; //中间结果

@property(nonatomic, assign) BOOL punctuationPrediction; //标点

@property(nonatomic, assign) BOOL inverseTextNormalization; //执行数字转换

@property(nonatomic, assign) BOOL semanticSentenceDetection; //语义断句

@property(nonatomic, assign) int maxSentenceSilence; //200～6000, 静音断句阈值

@property(nonatomic, assign) BOOL enableWords; //词语模式

@property(nonatomic, assign) BOOL enableIgnoreSentenceTimeout; //是否忽略实时识别中的单句识别超时

@property(nonatomic, assign) BOOL isfluency; //是否对识别文本进行顺滑(去除语气词,重复说等)

@end

NS_ASSUME_NONNULL_END
