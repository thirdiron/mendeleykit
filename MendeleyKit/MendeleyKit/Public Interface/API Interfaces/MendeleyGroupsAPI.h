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
#import "MendeleyGroup.h"

@interface MendeleyGroupsAPI : MendeleyObjectAPI
/**
   @name MendeleyGroupsAPI
   This class provides access methods to the REST groups API
   All of the methods are accessed via MendeleyKit.
   Developers should use the methods provided in MendeleyKit rather
   than the methods listed here.
 */

/**
 */
- (void)groupListWithQueryParameters:(MendeleyGroupParameters *)queryParameters
                            iconType:(MendeleyIconType)iconType
                                task:(MendeleyTask *)task
                     completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   This method is only used when paging through a list of groups on the server.
   All required parameters are provided in the linkURL, which should not be modified
 */
- (void)groupListWithLinkedURL:(NSURL *)linkURL
                      iconType:(MendeleyIconType)iconType
                          task:(MendeleyTask *)task
               completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
 */
- (void)groupWithGroupID:(NSString *)groupID
                iconType:(MendeleyIconType)iconType
                    task:(MendeleyTask *)task
         completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
 */
- (void)groupMemberListWithGroupID:(NSString *)groupID
                        parameters:(MendeleyGroupParameters *)queryParameters
                              task:(MendeleyTask *)task
                   completionBlock:(MendeleyArrayCompletionBlock)completionBlock;



/**
   Obtain a list of groups where the logged in user is a member
   If provided, it will include the square icon for the group
 */
- (void)groupListWithQueryParameters:(MendeleyGroupParameters *)queryParameters
                                task:(MendeleyTask *)task
                     completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   This method is only used when paging through a list of groups on the server.
   All required parameters are provided in the linkURL, which should not be modified
 */
- (void)groupListWithLinkedURL:(NSURL *)linkURL
                          task:(MendeleyTask *)task
               completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   Obtain details for the group identified by the given groupID
 */
- (void)groupWithGroupID:(NSString *)groupID
                    task:(MendeleyTask *)task
         completionBlock:(MendeleyObjectCompletionBlock)completionBlock;


/**
   Obtains a group icon for a specified MendeleyGroup and icon type (maybe standard, square, original) as NSData
 */
- (void)groupIconForGroup:(MendeleyGroup *)group
                 iconType:(MendeleyIconType)iconType
                     task:(MendeleyTask *)task
          completionBlock:(MendeleyBinaryDataCompletionBlock)completionBlock;


/**
   Obtains a group icon based on the given link URL string as NSData
 */
- (void)groupIconForIconURLString:(NSString *)iconURLString
                             task:(MendeleyTask *)task
                  completionBlock:(MendeleyBinaryDataCompletionBlock)completionBlock;

@end
