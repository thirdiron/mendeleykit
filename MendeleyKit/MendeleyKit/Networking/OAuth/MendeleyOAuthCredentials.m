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

#import "MendeleyOAuthCredentials.h"
#import "MendeleyOAuthConstants.h"
#import "MendeleyObjectHelper.h"

@interface MendeleyOAuthCredentials ()
@property (nonatomic, strong) NSDate *currentDate;
@end

@implementation MendeleyOAuthCredentials
- (id)init
{
    self = [super init];
    if (nil != self)
    {
        _currentDate = [NSDate date];
    }
    return self;
}

- (NSDictionary *)authenticationHeader
{
    return @{ @"Authorization" : [NSString stringWithFormat:@"Bearer %@", self.access_token] };
}

- (BOOL)oauthCredentialIsExpired
{
    NSDate *expiryDate = [self.currentDate dateByAddingTimeInterval:[self.expires_in doubleValue]];

    return [expiryDate compare:[NSDate date]] == NSOrderedAscending;
}

#pragma mark NSSecureCoding protocol

+ (BOOL)supportsSecureCoding
{
    return YES;
}

- (void)encodeWithCoder:(NSCoder *)encoder
{
    [encoder encodeObject:self.refresh_token forKey:NSStringFromSelector(@selector(refresh_token))];
    [encoder encodeObject:self.currentDate forKey:NSStringFromSelector(@selector(currentDate))];
    [encoder encodeObject:self.token_type forKey:NSStringFromSelector(@selector(token_type))];
    [encoder encodeObject:self.access_token forKey:NSStringFromSelector(@selector(access_token))];
    [encoder encodeObject:self.expires_in forKey:NSStringFromSelector(@selector(expires_in))];
}

- (id)initWithCoder:(NSCoder *)decoder
{
    self = [super init];
    if (nil != self)
    {
        [self decodeWithDecoder:decoder];
    }
    return self;
}

#pragma mark -
#pragma mark private

- (void)decodeWithDecoder:(NSCoder *)decoder
{
    self.refresh_token = [decoder decodeObjectOfClass:NSString.class forKey:NSStringFromSelector(@selector(refresh_token))];
    self.currentDate = [decoder decodeObjectOfClass:NSDate.class forKey:NSStringFromSelector(@selector(currentDate))];
    self.token_type = [decoder decodeObjectOfClass:NSString.class forKey:NSStringFromSelector(@selector(token_type))];
    self.access_token = [decoder decodeObjectOfClass:NSString.class forKey:NSStringFromSelector(@selector(access_token))];
    self.expires_in = [decoder decodeObjectOfClass:NSNumber.class forKey:NSStringFromSelector(@selector(expires_in))];
}

@end
