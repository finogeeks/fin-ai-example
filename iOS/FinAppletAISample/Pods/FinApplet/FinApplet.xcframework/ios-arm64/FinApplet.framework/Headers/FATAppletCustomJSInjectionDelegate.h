//
//  FATCustomJSInjectionDelegate.h
//  FinApplet
//
//  Created by chenfanfang on 2025/8/6.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FATAppletCustomJSInjectionDelegate <NSObject>

@optional

/// 获取需要注入的js内容的字符串列表
/// - Parameter appInfo: 小程序信息
///
- (NSArray<NSString *> *)getJSContentList:(FATAppletInfo *)appInfo;


@end

NS_ASSUME_NONNULL_END
