Pod::Spec.new do |s|

  s.name         = 'HereSDKCoreKit'
  s.version      = '2.0.0'
  s.summary      = 'HERE Mobility SDK Core functionality'

  s.license      = {
                     :type => 'Commercial',
                     :text => "HERE Technologies"
                   }

  s.description  = <<-DESC
                   The Here SDK for iOS CoreKit framework provides: 
                   * authentication/api key validation 
                   * core functionality 
                   * analytics
                   DESC

  s.homepage     = "https://developer.here.com/"
  s.author       = "Here Technologies"

  s.platform     = :ios, '9.0'

  s.requires_arc = true
  s.vendored_frameworks = "Frameworks/#{s.name}.framework"

  s.source       = { :git => "https://github.com/HereMobilityDevelopers/Here-Mobility-SDK-iOS.git", :tag => "core_#{s.version}" }

  s.dependency 'gRPC-ProtoRPC', '~> 1.15.0'
  s.dependency 'Protobuf', '~> 3.6.0'

end