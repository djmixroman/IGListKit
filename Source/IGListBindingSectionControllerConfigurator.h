// 
// Copyright (c) 2016-present, Facebook, Inc.
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree. An additional grant
// of patent rights can be found in the PATENTS file in the same directory.
//
// GitHub:
// https://github.com/Instagram/IGListKit
// 
// Documentation:
// https://instagram.github.io/IGListKit/
//

#import <Foundation/Foundation.h>

@protocol IGListDiffable;

/**
 This list binding section controller configurator uses a object from method:
 @code - (NSArray<id<IGListDiffable>> *)sectionController:(IGListBindingSectionController *)sectionController
                                viewModelsForObject:(id)object
 @endcode
 and can create the array of view models via the `IGListBindable` protocol.
 
 It can help to take out model translation logic from your list binding section controller.

 Objective-C usage example:
 @code
 - (NSArray<id<IGListDiffable>> *)getDiffableViewModelsArray {
     if ([self.object isKindOfClass:[AudioSectionViewModel class]]) {
        return [AudioConfigurator configureAudioViewModelsWithObject:self.object];
     }
     return nil;
 }
 @endcode
 
 Swift usage example:
 @code
 override public func getDiffableViewModelsArray() -> [ListDiffable] {
     switch object {
     case is AudioSectionViewModel:
        return AudioConfigurator.configureAudioViewModels(with: object)
 
     default:
        return [ListDiffable]()
     }
 }
 @endcode
 */
NS_SWIFT_NAME(ListBindingSectionControllerConfigurator)
@interface IGListBindingSectionControllerConfigurator : NSObject

/**
 Generate the array of view models via the `IGListBindable` protocol from stored object.
 
 @attention You must to override this method!

 @return The array of view models via the `IGListBindable` protocol.
 */
- (NSArray<id<IGListDiffable>> *)getDiffableViewModelsArray;


/**
 Create a new list binding section controller configurator with object from method:
 @code - (NSArray<id<IGListDiffable>> *)sectionController:(IGListBindingSectionController *)sectionController
                                viewModelsForObject:(id)object
 @endcode
 
 @return A new list binding section controller configurator.
 */
- (instancetype)initWithObject:(id)object;

/**
 Unavailable
 */
- (instancetype)init NS_UNAVAILABLE;

/**
 Unavailable
 */
+ (instancetype)new NS_UNAVAILABLE;

@end
