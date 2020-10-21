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

#import "MendeleyObjectAPI.h"

__attribute__ ((deprecated))
@interface MendeleyFeedsAPI : MendeleyObjectAPI

/**
 This method is only used when paging through a list of documents on the server.
 All required parameters are provided in the linkURL, which should not be modified
 */
- (void)feedListWithLinkedURL:(NSURL *)linkURL
                             task:(MendeleyTask *)task
                  completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
 obtains a list of feeds for the first page.
 */
- (void)feedListWithQueryParameters:(MendeleyFeedsParameters *)queryParameters
                                   task:(MendeleyTask *)task
                        completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
 obtains feed with a given identifier
 */
- (void)feedWithId:(NSString *)feedId
              task:(MendeleyTask *)task
   completionBlock:(MendeleyObjectCompletionBlock)completionBlock;


/**
 likes a feed item.
 */
- (void)likeFeedWithID:(NSString *)feedID
                  task:(MendeleyTask *)task
       completionBlock:(MendeleyCompletionBlock)completionBlock;

/**
 likes a feed item.
 */
- (void)unlikeFeedWithID:(NSString *)feedID
                    task:(MendeleyTask *)task
         completionBlock:(MendeleyCompletionBlock)completionBlock;

/**
 List of users that like given item.
 */

- (void)likersForFeedWithID:(NSString *)feedID
                      task:(MendeleyTask *)task
           completionBlock:(MendeleyArrayCompletionBlock)completionBlock;


/**
 List of users that have shared given item.
 */

- (void)sharersForFeedWithID:(NSString *)feedID
                        task:(MendeleyTask *)task
             completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

@end
