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
#import "MendeleySyncInfo.h"
#import "MendeleyModels.h"
#import "MendeleyGlobals.h"

@interface MendeleyBlockExecutor : NSObject

/**
   @name MendeleyBlockExecutor
   There are 3 types of completionBlocks in the SDK. This class is a helper/wrapper
   to ensure that the blocks are executed on the main thread.
   The class must be initialised with one of the 3 init<completionBlockType> methods provided
 */

/**
 */
- (instancetype)initWithArrayCompletionBlock:(MendeleyArrayCompletionBlock)arrayCompletionBlock;

/**
 */
- (instancetype)initWithStringArrayCompletionBlock:(MendeleyStringArrayCompletionBlock)stringArrayCompletionBlock;

/**
 */
- (instancetype)initWithCompletionBlock:(MendeleyCompletionBlock)completionBlock;

/**
 */
- (instancetype)initWithObjectCompletionBlock:(MendeleyObjectCompletionBlock)objectCompletionBlock;

/**
 */
- (instancetype)initWithDictionaryCompletionBlock:(MendeleyDictionaryResponseBlock)dictionaryCompletionBlock;

/**
 */
- (instancetype)initWithBinaryDataCompletionBlock:(MendeleyBinaryDataCompletionBlock)binaryDataCompletionBlock;

/**
 */
- (instancetype)initWithOAuthCompletionBlock:(MendeleyOAuthCompletionBlock)oauthCompletionBlock;

/**
   executes the MendeleyArrayCompletionBlock on the main thread
 */
- (void)executeWithArray:(NSArray *)array
                syncInfo:(MendeleySyncInfo *)syncInfo
                   error:(NSError *)error;


/**
   executes the MendeleyCompletionBlock on the main thread
 */
- (void)executeWithBool:(BOOL)success error:(NSError *)error;

/**
   executes the MendeleyObjectCompletionBlock on the main thread
 */
- (void)executeWithMendeleyObject:(MendeleySecureObject *)mendeleyObject
                         syncInfo:(MendeleySyncInfo *)syncInfo
                            error:(NSError *)error;

/**
   executes the MendeleyDictionaryCompletionBlock on the main thread
 */
- (void)executeWithDictionary:(NSDictionary *)dictionary error:(NSError *)error;

/**
   executes the MendeleyDictionaryCompletionBlock on the main thread
 */
- (void)executeWithBinaryData:(NSData *)binaryData error:(NSError *)error;

/**
   executes the MendeleyOAuthCompletionBlock on the main thread
 */
- (void)executeWithCredentials:(MendeleyOAuthCredentials *)credentials error:(NSError *)error;

@end
