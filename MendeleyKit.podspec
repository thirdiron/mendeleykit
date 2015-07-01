Pod::Spec.new do |s|

  s.name         = "MendeleyKitiOS"
  s.version      = "1.0.9"
  s.summary      = "The Mendeley Objective C client SDK."

  s.description  = <<-DESC
                   # MendeleyKit
                   The open source Mendeley Objective C Kit.

                   ## Features
                   * Access to Mendeley REST API endpoints and handling of JSON responses
                   * Provide model classes for essential Mendeley objects such as Mendeley documents
                   * OAuth2 authentication and login as well as automatic handling of access refresh
                   DESC

  s.homepage     = "https://github.com/Mendeley/mendeleykit"

  s.license      = 'Apache Licence, Version 2.0'

  s.authors      = { "Mendeley iOS" => "ios@mendeley.com"}
  s.requires_arc  = true

  s.source       = { :git => "https://github.com/Mendeley/mendeleykit.git"}
  s.header_dir   = 'MendeleyKitiOS.framework/Headers'
  s.module_name  = 'MendeleyKitiOS'
#  s.module_map = 'MendeleyKit/MendeleyKitiOS/module.modulemap'
  s.ios.deployment_target = '8.0'
  s.osx.deployment_target = '10.8'

  s.source_files  = 'MendeleyKit', 'MendeleyKit/**/*.{h,m,swift}'
  s.exclude_files = 'MendeleyKit/MendeleyKitTests', 'MendeleyKit/MendeleyKitExample', 'MendeleyKit/MendeleyKitiOSTests'

  s.ios.exclude_files = 'MendeleyKit/MendeleyKitOSX'
  s.osx.exclude_files = 'MendeleyKit/**/UIKit/*.{h,m}', 'MendeleyKit/MendeleyKitiOS'
  s.ios.frameworks  = 'MobileCoreServices', 'SystemConfiguration', 'Security', 'Foundation'
  s.ios.vendored_frameworks = 'MendeleyKitiOS/MendeleyKitiOS.framework'
  s.osx.frameworks  = 'Foundation', 'CoreFoundation', 'AppKit', 'Security', 'WebKit', 'CoreServices'

  s.prefix_header_contents = <<-EOS
  #ifdef __OBJC__
    #import <Security/Security.h>
    #if __IPHONE_OS_VERSION_MIN_REQUIRED
      #import <SystemConfiguration/SystemConfiguration.h>
      #import <MobileCoreServices/MobileCoreServices.h>
    #else
      #import <SystemConfiguration/SystemConfiguration.h>
      #import <CoreServices/CoreServices.h>
    #endif
    #import <MendeleyKitiOS/MendeleyKitiOS.h>
  #endif /* __OBJC__*/
  EOS

end
