//
//  FATEmbedComponentEvent.h
//  FinApplet
//
//  Created by 滔 on 2025/5/15.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATEmbedComponentEvent : NSObject

/// 组件ID
@property (nonatomic, copy) NSString *componentId;


/// 小程序信息
@property (nonatomic, strong) FATAppletInfo *appletInfo;

/// 页面id
@property (nonatomic, strong) NSNumber *pageId;

/// 页面path
@property (nonatomic, copy) NSString *pagePath;


/// 事件
@property (nonatomic, copy) NSString *eventName;

/// 事件参数
@property (nonatomic, strong) NSDictionary *eventData;
@end

NS_ASSUME_NONNULL_END
