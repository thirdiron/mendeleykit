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

@class MendeleyDocumentParameters;

@interface MendeleyDocumentsAPI : MendeleyObjectAPI
/**
   @name MendeleyDocumentsAPI
   This class provides access methods to the REST documents API
   All of the methods are accessed via MendeleyKit.
   Developers should use the methods provided in MendeleyKit rather
   than the methods listed here.
 */

/**
   This method is only used when paging through a list of documents on the server.
   All required parameters are provided in the linkURL, which should not be modified
 */
- (void)documentListWithLinkedURL:(NSURL *)linkURL
                             task:(MendeleyTask *)task
                  completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   obtains a list of documents for the first page.
 */
- (void)documentListWithQueryParameters:(MendeleyDocumentParameters *)queryParameters
                                   task:(MendeleyTask *)task
                        completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   obtains the first page of authored documents for another user.
 */
- (void)authoredDocumentListForUserWithProfileID:(NSString *)profileID
                                 queryParameters:(MendeleyDocumentParameters *)queryParameters
                                            task:(MendeleyTask *)task
                                 completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   obtains a document for given ID from the library
 */
- (void)documentWithDocumentID:(NSString *)documentID
                          task:(MendeleyTask *)task
               completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
   This method returns a catalog document for a given catalog ID
 */
- (void)catalogDocumentWithCatalogID:(NSString *)catalogID
                                task:(MendeleyTask *)task
                     completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
   This method obtains a list of documents based on a filter. The filter should not be nil or empty
 */
- (void)catalogDocumentWithParameters:(MendeleyCatalogParameters *)queryParameters
                                 task:(MendeleyTask *)task
                      completionBlock:(MendeleyArrayCompletionBlock)completionBlock;
/**
   this creates a document based on the mendeley object model provided in the argument.
   The server will respond with the JSON data structure for the new object
 */
- (void)createDocument:(MendeleyDocument *)mendeleyDocument
                  task:(MendeleyTask *)task
       completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
   modify/update a document with ID. The server will return a JSON object with the updated data
 */
- (void)updateDocument:(MendeleyDocument *)updatedMendeleyDocument
                  task:(MendeleyTask *)task
       completionBlock:(MendeleyObjectCompletionBlock)completionBlock;


/**
   this method will remove a document with given ID permanently. The document data cannot be retrieved.
   However, the user will be able to get a list of permanently removed IDs
 */
- (void)deleteDocumentWithID:(NSString *)documentID
                        task:(MendeleyTask *)task
             completionBlock:(MendeleyCompletionBlock)completionBlock;

/**
   This method will move a document of given ID into the trash on the server. Data in trash can be restored
   (as opposed to using the deleteDocumentWithID:completionBlock: method which permanently removes them)
 */
- (void)trashDocumentWithID:(NSString *)documentID
                       task:(MendeleyTask *)task
            completionBlock:(MendeleyCompletionBlock)completionBlock;

/**
   This method returns a list of document IDs that were permanently deleted. The list of deleted IDs will be kept on
   the server for a limited period of time.
 */
- (void)deletedDocumentsSince:(NSDate *)deletedSince
                      groupID:(NSString *)groupID
                         task:(MendeleyTask *)task
              completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   This method obtains a list for a given page link of 'trashed' documents
   based on a list of query parameters.
   All required parameters are provided in the linkURL, which should not be modified
 */
- (void)trashedDocumentListWithLinkedURL:(NSURL *)linkURL
                                    task:(MendeleyTask *)task
                         completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   This method obtains a list for the 'first' page of 'trashed' documents
   based on a list of query parameters.
 */
- (void)trashedDocumentListWithQueryParameters:(MendeleyDocumentParameters *)queryParameters
                                          task:(MendeleyTask *)task
                               completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   this method will remove a trashed document with given ID permanently.
   The document data cannot be retrieved.
   However, the user will be able to get a list of permanently removed IDs
 */
- (void)deleteTrashedDocumentWithID:(NSString *)documentID
                               task:(MendeleyTask *)task
                    completionBlock:(MendeleyCompletionBlock)completionBlock;

/**
   this method will restore a trashed document.
   In essence this means the document must be retrieved using the /documents API
 */
- (void)restoreTrashedDocumentWithID:(NSString *)documentID
                                task:(MendeleyTask *)task
                     completionBlock:(MendeleyCompletionBlock)completionBlock;


/**
   obtains a document for given ID from the library
 */
- (void)trashedDocumentWithDocumentID:(NSString *)documentID
                                 task:(MendeleyTask *)task
                      completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
   Method to obtain the supported document types (e.g. journal, book etc)
 */
- (void)documentTypesWithTask:(MendeleyTask *)task
              completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   Method to obtain the supported identifier types (e.g. pmid, doi, arXiv etc)
 */
- (void)identifierTypesWithTask:(MendeleyTask *)task
                completionBlock:(MendeleyArrayCompletionBlock)completionBlock;

/**
   uploads a file from a location and returns a Mendeley Document in the completion handler
 */
- (void)documentFromFileWithURL:(NSURL *)fileURL
                       mimeType:(NSString *)mimeType
                           task:(MendeleyTask *)task
                completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
 Method clones document metadata to a new group/lib. The returned metadata contain the user document metadata including the document ID for the cloned document
 @param documentID the document to be cloned
 @param groupID the target group ID. Use nil if you want to clone to the users' library. In this case the profile ID must be provided
 @param folderID the target folder ID.
 @param profileID must be provided if the groupID is nil (this means clone to user library). Otherwise values are ignored
 @param task the task
 @param completionBlock the completion block
 */
- (void)cloneDocumentWithID:(NSString *)documentID
                    groupID:(NSString *)groupID
                   folderID:(NSString *)folderID
                  profileID:(NSString *)profileID
                       task:(MendeleyTask *)task
            completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

/**
 Method clones files associated with a document from source to target.
 The target document must exist - otherwise the completionBlock will return an error
 @param sourceDocumentID the source document with files
 @param targetDocumentID the target document ID
 @param task the task
 @param completionBlock the completion block
 */
- (void)cloneDocumentFiles:(NSString *)sourceDocumentID
          targetDocumentID:(NSString *)targetDocumentID
                      task:(MendeleyTask *)task
           completionBlock:(MendeleyCompletionBlock)completionBlock;


/**
 Method clones document metadata to a new group/lib. It also clones any associated files from source to target document
 The returned metadata contain the user document metadata including the document ID for the cloned document
 @param documentID the document to be cloned
 @param groupID the target group ID. Use nil if you want to clone to the users' library. In this case the profile ID must be provided
 @param folderID the target folder ID.
 @param profileID must be provided if the groupID is nil (this means clone to user library). Otherwise values are ignored
 @param task the task
 @param completionBlock the completion block
 */
- (void)cloneDocumentAndFiles:(NSString *)documentID
                      groupID:(NSString *)groupID
                     folderID:(NSString *)folderID
                    profileID:(NSString *)profileID
                         task:(MendeleyTask *)task
              completionBlock:(MendeleyObjectCompletionBlock)completionBlock;

@end
