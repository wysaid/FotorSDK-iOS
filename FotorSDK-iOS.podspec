Pod::Spec.new do |s|
  s.name         = 'FotorSDK-iOS'
  s.version      = '0.9.0.1'
  s.summary      = 'FotorSDK is a complete set of photo editing tools.'
  s.description  = <<-DESC
                    FotorSDK is a complete set of photo editing tools comes standard in Fotor’s all-platform SDK.
		    You can select the tools that are best for your app, or use them all.
                   DESC
  s.homepage     = 'https://github.com/Fotor/FotorSDK-iOS/'
  s.license      = 'MIT'
  s.authors      = { 'Dake' => 'chen423@yeah.net', 'ArcRain' => 'planet238@gmail.com', 'wysaid' => 'wysaid@gmail.com' }
  s.social_media_url   = 'http://www.fotor.com/'
  s.platform     = :ios, '6.0'
  s.source       = { :git => 'https://github.com/Fotor/FotorSDK-iOS.git', :tag => '0.9.0.1' }
  s.public_header_files = 'FotorSDK/Headers/*.h'
  s.source_files  = 'FotorSDK/*.a'
  s.resources	 = 'FotorSDK/EIPhotoSDKResources.bundle'
  s.requires_arc = true
end
