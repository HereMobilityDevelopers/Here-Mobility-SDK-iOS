Pod::Spec.new do |s|

  s.name         = 'HereSDKDemandKit'
  s.version      = '1.1.9'
  s.summary      = 'HERE Mobility SDK for connecting to the Mobility Marketplace'

  s.license      = {
                     :type => 'Commercial',
                     :text => "HERE Technologies"
                   }

  s.description  = <<-DESC
                   Allows users of your app to connect their ride demand with 
                   supply from within your interface, including requesting a 
                   ride offer, booking or canceling a ride, and updating along 
                   the journey. 
                   DESC

  s.homepage     = "https://developer.here.com/"
  s.author       = "Here Technologies"

  s.platform     = :ios, '9.0'

  s.requires_arc = true
  s.vendored_frameworks = "Frameworks/#{s.name}.framework"

  s.source       = { :git => "https://github.com/HereMobilityDevelopers/Here-Mobility-SDK-iOS.git", :tag => "demand_#{s.version}" }

  s.dependency 'HereSDKCoreKit', '1.1.9'

end