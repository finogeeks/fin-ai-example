//
//  FATEmbedComponentDelegate.h
//  FinApplet
//
//  Created by 滔 on 2025/5/15.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATEmbedComponentInfo.h"
#import "FATEmbedComponentEvent.h"
#import "FATCustomEmbedViewProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/// 小程序自定义同层组件代理
@protocol FATEmbedComponentDelegate <NSObject>

@optional

/// 收到创建自定义组件事件
/// - Parameters:
///   - componentInfo: 自定义组件信息，会包含小程序信息、页面id、页面path等参数
///   - completion: 创建完成回调，返回自定义组件视图
- (void)onCreateEmbedComponent:(FATEmbedComponentInfo *)componentInfo completion:(void (^)(UIView<FATCustomEmbedViewProtocol> * _Nullable componentView))completion;


@end

NS_ASSUME_NONNULL_END
