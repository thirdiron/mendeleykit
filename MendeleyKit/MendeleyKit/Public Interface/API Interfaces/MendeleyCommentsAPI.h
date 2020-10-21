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
@interface MendeleyCommentsAPI : MendeleyObjectAPI

/**
 Get expanded (i.e. with profile information) comments.
 */

- (void)expandedCommentsWithNewsItemID:(NSString *)newsItemID
                                  task:(MendeleyTask *)task
                       completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
 Get single comment.
 */

- (void)commentWithCommentID:(NSString *)commentID
                        task:(MendeleyTask *)task
             completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
 Create new comment.
 */

- (void)createComment:(MendeleyComment *)comment
                 task:(MendeleyTask *)task
      completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
 Edit existing comment.
 */

- (void)updateCommentWithCommentID:(NSString *)commentID
                            update:(MendeleyCommentUpdate *)update
                              task:(MendeleyTask *)task
                   completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
 Delete comment.
 */

- (void)deleteCommentWithCommentID:(NSString *)commentID
                              task:(MendeleyTask *)task
                   completionBlock:(MendeleyCompletionBlock)completionBlock;

@end
