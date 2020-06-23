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

public enum CacheFileError: Error
{
    case fileNotFound
}

open class MendeleyAnalyticsCacheManager: NSObject
{
    var preferredBatchSize = 50
    let maxBatchSize = 1000
    var eventHeader = [kMendeleyRESTRequestContentType : kMendeleyRESTRequestJSONType]
    
    open var cacheFilePath: String{
        get{
            let dirPaths = NSSearchPathForDirectoriesInDomains(.documentDirectory,
                .userDomainMask, true)
            
            let docsDir = dirPaths[0] as NSString
            let path = docsDir.appendingPathComponent("MendeleyAnalyticsEvents.cache")
            return path
        }
    }
    
    open func addMendeleyAnalyticsEvent(_ event:MendeleyAnalyticsEvent)
    {
        var currentEvents = eventsFromArchive()
        currentEvents.append(event)
        
        
        eventsToArchive(currentEvents)
        if preferredBatchSize < currentEvents.count || maxBatchSize < currentEvents.count
        {
            sendAndClearAnalyticsEvents({ (success, error) -> Void in
                if success
                {
                    self.clearCache()
                }
            })
        }
    }

    open func addMendeleyAnalyticsEvents(_ events:[MendeleyAnalyticsEvent])
    {
        var currentEvents = eventsFromArchive()
        currentEvents += events
        eventsToArchive(currentEvents)
        if preferredBatchSize < currentEvents.count || maxBatchSize < currentEvents.count
        {
            sendAndClearAnalyticsEvents({ (success, error) -> Void in
                if success
                {
                    self.clearCache()
                }
            })
        }
    }
    
    open func sendAndClearAnalyticsEvents(_ completionHandler: MendeleyCompletionBlock?)
    {
        // Need to filter out events with no name or no origin identity/version
        // The API now rejects requests without those values,
        // and the previous version of this library would not serialize them properly,
        // hence accumulating invalid events in the cache.
        let events = eventsFromArchive().filter {
            $0.name != nil && $0.origin[kMendeleyAnalyticsJSONOriginIdentity] != nil && $0.origin[kMendeleyAnalyticsJSONOriginVersion] != nil
        }

        if 0 == events.count
        {
            if nil != completionHandler
            {
                completionHandler!(true, nil)
            }
            return
        }
        
        let sdk = MendeleyKit.sharedInstance()
        if (sdk?.isAuthenticated)!
        {
            MendeleyOAuthTokenHelper.refreshToken(refreshBlock: { (success, error) -> Void in
                let blockExecutor = MendeleyBlockExecutor(completionBlock: completionHandler)
                if success
                {
                    let kit = MendeleyKitConfiguration.sharedInstance()
                    let baseURL = kit?.baseAPIURL
                    let provider = kit?.networkProvider
                    let modeller = MendeleyModeller.sharedInstance()
                    let task = MendeleyTask()
                    do{
                        let data = try modeller.jsonObject(fromModelOrModels: events) as Data
                        
                        provider?.invokePOST(baseURL, api: kMendeleyAnalyticsAPIEventsBatch, additionalHeaders: self.eventHeader, jsonData: data, authenticationRequired: true, task: task, completionBlock: { (response, responseError ) -> Void in
                            if nil != response
                            {
                                do{
                                    let helper = MendeleyKitHelper()
                                    try helper.isSuccess(for: response!)
                                    self.clearCache()
                                    blockExecutor?.execute(with: true, error: nil)
                                }catch let responseFault as NSError
                                {
                                    blockExecutor?.execute(with: false, error: responseFault)
                                }
                                catch{
                                    let innerError = NSError(code: MendeleyErrorCode.responseTypeUnknownErrorCode)
                                    blockExecutor?.execute(with: false, error: innerError)
                                }
                            }
                            else
                            {
                                blockExecutor?.execute(with: false, error: responseError!)
                            }
                            
                        })
                    }catch let jsonError as NSError
                    {
                        blockExecutor?.execute(with: false, error: jsonError)
                    }
                    catch{
                        let jsonError = NSError(code: MendeleyErrorCode.jsonTypeNotMappedToModelErrorCode)
                        blockExecutor?.execute(with: false, error: jsonError)
                    }
                }
                else
                {
                    blockExecutor?.execute(with: false, error: error)
                }
            })
        }
        else
        {
            let error = NSError(code: MendeleyErrorCode.unauthorizedErrorCode)
            if nil != completionHandler
            {
                completionHandler!(false, error)
            }
        }
    }
    
    open func clearCache()
    {
        let path = cacheFilePath
        let fileManager = FileManager.default
        if fileManager.fileExists(atPath: path)
        {
            do{
                try fileManager.removeItem(atPath: path)
            }catch let error as NSError
            {
                print("\(error.localizedDescription)")
            }
            catch{
                
            }
        }
        
    }
    
    public func eventsFromArchive() -> [MendeleyAnalyticsEvent]
    {
        let path = cacheFilePath
        let fileManager = FileManager.default
        if fileManager.fileExists(atPath: path)
        {
            let data = NSKeyedUnarchiver.unarchiveObject(withFile: path)
            if nil != data
            {
                return data as! [MendeleyAnalyticsEvent]
            }
        }
        return [MendeleyAnalyticsEvent]()
    }
    
    public func eventsToArchive(_ events: [MendeleyAnalyticsEvent])
    {
        let path = cacheFilePath
        NSKeyedArchiver.archiveRootObject(events, toFile: path)
    }
    
}
