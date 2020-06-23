/*
******************************************************************************
* Copyright (C) 2014-2017 Elsevier/Mendeley.
*
* This file is part of the Mendeley iOS SDK.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*  http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*****************************************************************************
*/

import Foundation

@objc open class MendeleyAnalyticsEvent: MendeleySecureObject
{
    @objc open var name:String!
    @objc open var timestamp = Date()
    @objc open var profileID: String!
    @objc open var session_ID: String!
    @objc open var profile_uuid: String!
    @objc open var origin = [kMendeleyAnalyticsJSONOriginOS : kOriginOS,
        kMendeleyAnalyticsJSONOriginType: kOriginType]
    @objc public var properties = [String:Any]()
    
    public var duration_milliseconds: Int? {
        get {
            return properties[kMendeleyAnalyticsJSONDuration] as? Int
        }
        set {
            properties[kMendeleyAnalyticsJSONDuration] = newValue
        }
    }

    public init(name: String) {
        super.init()
        self.name = name
    }
    
    public required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }
}
