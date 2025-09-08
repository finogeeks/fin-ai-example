//
//  FATCustomEmbedViewProtocol.h
//  FinApplet
//
//  Created by 滔 on 2025/5/19.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATEmbedComponentInfo.h"
#import "FATEmbedComponentEvent.h"

NS_ASSUME_NONNULL_BEGIN

/// 小程序自定义同层组件代理
@protocol FATCustomEmbedViewProtocol <NSObject>

@optional

/// 自定义组件更新
/// - Parameters:
///   - componentInfo: 组件更新的参数
///   - completion: 更新完成回调，必须触发
- (void)onUpdate:(FATEmbedComponentInfo *)componentInfo withCompletion:(void (^)(void))completion;



/// 自定义组件被删除，可以在这个方法里做一些清理逻辑
/// - Parameter completion: 完成回调，必须触发
- (void)onRemoveWithCompletion:(void (^)(void))completion;


/// 收到小程序发送给自定义组件的事件
/// - Parameters:
///   - event: 事件
///   - completion: 处理完成回调，必须触发，回调数据可以为nil
- (void)receiveComponentEvent:(FATEmbedComponentEvent *)event completion:(void (^)(NSDictionary * _Nullable resDic))completion;

@end

NS_ASSUME_NONNULL_END
