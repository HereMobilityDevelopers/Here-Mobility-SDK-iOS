Pod::Spec.new do |s|

  s.name         = 'HereSDKMapKit'
  s.version      = '1.2.2'
  s.summary      = 'HERE Mobility SDK for comprehensive map capabilities and services'

  s.license      = {
                     :type => 'Commercial',
                     :text => "HERE Technologies"
                   }

  s.description  = <<-DESC
                   Context-aware, sophisticated, real-time and reliable map services 
                   include search, rendering, routing, and turn-by-turn guidance 
                   on interactive maps with intelligent matching and functionalities 
                   such as zoom and location information.
                   DESC

  s.homepage     = "https://developer.here.com/"
  s.author       = "Here Technologies"

  s.platform     = :ios, '9.0'

  s.requires_arc = true
  s.vendored_frameworks = "Frameworks/#{s.name}.framework"

  s.source       = { :git => "https://github.com/HereMobilityDevelopers/Here-Mobility-SDK-iOS.git", :tag => "map_#{s.version}" }

  s.dependency 'HereSDKCoreKit', '1.2.2'

end