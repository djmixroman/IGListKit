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

#import "IGListBindingSectionControllerConfigurator.h"
#import "IGListDiffable.h"
#import "IGListAssert.h"

@interface IGListBindingSectionControllerConfigurator ()

@property (nonatomic, strong) id object;

@end

@implementation IGListBindingSectionControllerConfigurator

- (instancetype)initWithObject:(id)object {
    if (self = [super init]) {
        _object = object;
    }
    return self;
}

- (NSArray<id<IGListDiffable>> *)getDiffableViewModelsArray {
    IGFailAssert(@"Method must be overwritten");
    return nil;
}

@end
