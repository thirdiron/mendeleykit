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

@interface MendeleyDisciplinesAPI : MendeleyObjectAPI
/**
   This method is deprecated. It returns data from a new endpoint. See method below.
   This method gets all registered Mendeley disciplines (and their subdisciplines)
   @param task the cancellable MendeleyTask
   @param completionBlock will return an array of MendeleyDiscipline objects
 */
- (void)disciplinesWithTask:(MendeleyTask *)task
            completionBlock:(MendeleyArrayCompletionBlock)completionBlock __attribute__((deprecated));

/**
 NOTE: this method uses the new and preferred API for obtaining "disciplines" or
 "subject areas". The other method returns the same value, but uses a server side
 redirect to the new API.
 This method gets all registered Elsevier subject areas.
 @param task the cancellable MendeleyTask
 @param completionBlock will return an array of MendeleyDiscipline objects
 */
- (void)subjectAreasWithTask:(MendeleyTask *)task
             completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

@end
