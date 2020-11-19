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

static NSString * const MendeleyErrorDomainMultiple = @"*.error";
static NSString * const MendeleyDetailedErrorsKey = @"KMendeleyDetailedErrors";


typedef NS_ENUM (NSInteger, MendeleyReservedErrorCode) {
    MendeleyErrorUnknown = 0,
    MendeleyErrorMultipleErrors = NSIntegerMax
};

@protocol MendeleyUserInfoProvider <NSObject>
/**
   Returns the userInfo for a given error code
 */
- (NSDictionary *)userInfoWithErrorCode:(NSInteger)errorCode;

@end

@interface MendeleyErrorManager : NSObject
/**
   returns a singleton MendeleyErrorManager instance
 */
+ (instancetype)sharedInstance;

/**
 * add an error user info builder for a specific error domain. Raises an exception if the helper is nil, or if the errorDomain is nil or empty
 */
- (void)addUserInfoHelper:(id <MendeleyUserInfoProvider> )helper
              errorDomain:(NSString *)errorDomain;

/**
 * remove the user info builder for a specific errorDomain. Does anything if the domain does not exists. Raises an exception if the errorDomain is nil or empty
 */
- (void)removeUserInfoHelperWithErrorDomain:(NSString *)errorDomain;

/**
 * create an NSError object whit a given errorDomain and errorCode. Raises an exception if the errorDomain is nil, empty, does not exist or the errorCode is not recognized as an error for the given domain
 */
- (NSError *)errorWithDomain:(NSString *)errorDomain
                        code:(NSInteger)errorCode;

/**
 *  create an NSError object whose user info contains a list of the given errors. If one of the given errors is nil, the result error is the other one, nil if both are nil
 */
- (NSError *)errorFromOriginalError:(NSError *)originalError
                              error:(NSError *)secondError;

@end
