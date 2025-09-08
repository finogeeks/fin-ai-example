//
//  FATEmbedComponentInfo.h
//  FinApplet
//
//  Created by 滔 on 2025/5/15.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATEmbedComponentInfo : NSObject

/// 组件Id
@property (nonatomic, copy) NSString *componentId;


/// 自定义组件的domId，如果需要发送事件给组件，需要传这个id
@property (nonatomic, copy) NSString *domId;


/// 页面id，如果后续需要发送自定义组件事件给小程序，需要传页面id
@property (nonatomic, strong) NSNumber *pageId;

/// 页面path
@property (nonatomic, copy) NSString *pagePath;


/// 小程序信息
@property (nonatomic, strong) FATAppletInfo *appletInfo;

/// 组件tag
@property (nonatomic, copy) NSString *componentTag;

//组件宽度
@property (nonatomic, assign) CGFloat width;

//组件高度
@property (nonatomic, assign) CGFloat height;

/// 组件数据
@property (nonatomic, strong) NSDictionary *dataDic;

@end

NS_ASSUME_NONNULL_END
