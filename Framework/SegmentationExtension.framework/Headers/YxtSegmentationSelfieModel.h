//
//  YxtSegmentationSelfieModel.h
//  YxtRtcKit
//
//  Created by 朱庆祥 on 2022/4/2.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface YxtSegmentationSelfieModel : NSObject

- (CVImageBufferRef)sampleBuffer:(CMSampleBufferRef)sampleBuffer isFront:(BOOL)isFront;

- (CVPixelBufferRef)resultsInsampleBuffer:(CMSampleBufferRef)sampleBuffer
                              isFront:(BOOL)isFront
                                error:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
