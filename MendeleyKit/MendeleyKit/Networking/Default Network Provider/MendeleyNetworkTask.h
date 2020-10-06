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

#import <Foundation/Foundation.h>
#import "MendeleyGlobals.h"
/**
   @name MendeleyNetworkTask
 */
@interface MendeleyNetworkTask : NSObject  <NSURLSessionTaskDelegate>
@property (strong, nonatomic) NSURLResponse *response;
@property (nonatomic, strong, readonly) NSNumber *taskID;
@property (copy, nonatomic, readonly) MendeleyResponseCompletionBlock completionBlock;

/**
   initialises a network task
 */
- (instancetype)initTaskWithRequest:(NSURLRequest *)request
                            session:(NSURLSession *)session
                    completionBlock:(MendeleyResponseCompletionBlock)completionBlock;

/**
   executes a tasks
 */
- (void)executeTask;

/**
   cancels a task
 */
- (void)cancelTaskWithCompletionBlock:(MendeleyCompletionBlock)completionBlock;

@end

/**
   @name MendeleyNetworkUploadTask
 */
@interface MendeleyNetworkUploadTask : MendeleyNetworkTask
@property (copy, nonatomic, readonly) MendeleyResponseProgressBlock progressBlock;

/**
   @param request request
   @param session session
   @param fileURL location of file to be uploaded
   @param progressBlock progress block
   @param completionBlock completion block
 */
- (instancetype)initUploadTaskWithRequest:(NSURLRequest *)request
                                  session:(NSURLSession *)session
                                  fileURL:(NSURL *)fileURL
                            progressBlock:(MendeleyResponseProgressBlock)progressBlock
                          completionBlock:(MendeleyResponseCompletionBlock)completionBlock;


@end

/**
   @name MendeleyNetworkDownloadTask
 */
@interface MendeleyNetworkDownloadTask : MendeleyNetworkTask
@property (copy, nonatomic, readonly) NSURL *fileURL;
@property (copy, nonatomic, readonly) MendeleyResponseProgressBlock progressBlock;

/**
   initialises a MendeleyNetworkDownloadTask
   @param request request
   @param session session
   @param fileURL download file location
   @param progressBlock progress block
   @param completionBlock completion block
 */
- (instancetype)initDownloadTaskWithRequest:(NSURLRequest *)request
                                    session:(NSURLSession *)session
                                    fileURL:(NSURL *)fileURL
                              progressBlock:(MendeleyResponseProgressBlock)progressBlock
                            completionBlock:(MendeleyResponseCompletionBlock)completionBlock;

/**
   Adds a NSURLSessionDownloadTask to the object for execution
 */
- (void)addRealDownloadTask:(NSURLSessionDownloadTask *)downloadTask;


@end

