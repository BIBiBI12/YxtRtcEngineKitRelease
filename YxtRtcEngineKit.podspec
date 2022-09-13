
Pod::Spec.new do |s|
  s.name = "YxtRtcEngineKit"
  s.version = "1.0.28"
  s.summary = "音视频SDK"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"YxtRtcEngineKit"=>"me_zqx@163.com"}
  s.homepage = "https://me_zqx.coding.net/p/yunxuetang/d/YxtRtcKit/git/tree/master/LICENSE"
  s.description = "TODO: Add long description of the pod here."
 
  s.xcconfig = {"VALID_ARCHS"=>"arm64"}
  
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.source           = { :git => 'https://e.coding.net/me_zqx/yunxuetang/YxtRtcEngineRelease.git', :tag => "#{s.version}" }
  s.ios.deployment_target    = '9.0'
  s.default_subspec = 'Core'

  s.subspec 'Core' do |ss|
       ss.ios.vendored_framework   = 'Framework/YxtRtcKit.framework'
       ss.frameworks = 'UIKit', 'MediaPlayer', 'AVFoundation', 'WebKit', 'AudioToolbox', 'VideoToolbox', 'CoreGraphics', 'GLKit', 'SystemConfiguration','OpenGLES', 'CoreMedia', 'QuartzCore'
       ss.libraries = "c++"
  end

  s.subspec 'ScreenShareExtension' do |ss|
       ss.ios.vendored_framework   = 'Framework/YXTScreenShare.framework'
       ss.frameworks = 'ReplayKit'
       ss.libraries = "c++"

  end

  # s.subspec 'SegmentationExtension' do |ss|
  #     ss.ios.vendored_framework   = 'Framework/SegmentationExtension.framework'
  #     ss.dependency 'MLKitSegmentationSelfie', '~> 1.0.0-beta8'

  # end



end
