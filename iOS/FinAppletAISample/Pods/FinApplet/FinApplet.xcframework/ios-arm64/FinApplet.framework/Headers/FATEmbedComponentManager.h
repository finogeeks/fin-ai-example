//
//  FATEmbedComponentManager.h
//  FinApplet
//
//  Created by 滔 on 2025/5/15.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATEmbedComponentManager : NSObject


/// 发送自定义组件事件给小程序
/// - Parameters:
///   - eventName: 事件名称
///   - appletId: 小程序id，不传的话会取发送给当前运行的小程序
///   - paramString: 事件参数
///   - pageId: 页面id，不传的话会使用当前页面
///   - componentId: 组件的domId
///   - handler: 事件结果回调
- (void)sendEvent:(NSString *)eventName applet:(NSString *)appletId paramString:(NSString *)paramString pageId:(NSNumber *)pageId componentDomId:(NSString *) componentDomId handler:(void (^)(id result, NSError *error))handler;


/// 获取自定义同层组件
/// - Parameters:
///   - appletId: 小程序id，不传的话，会去当前小程序获取同层组件
///   - pageId: 页面id，不传的话，会去小程序最上层页面去获取同层组件
///   - componentId: 同层组件id
- (UIView *)getEmbedComponent:(NSString * _Nullable)appletId pageId:(NSString * _Nullable)pageId componentId:(NSString *)componentId;

/// 宿主APP删除自定义同层组件
/// - Parameters:
///   - appletId: 小程序id，不传的话，会删除当前小程序里的同层组件
///   - pageId: 页面id，不传的话，会删除小程序最上层页面去的同层组件
///   - componentId: 同层组件id
- (BOOL)removeEmbedComponent:(NSString * _Nullable)appletId pageId:(NSString * _Nullable)pageId componentId:(NSString *)componentId;


@end

NS_ASSUME_NONNULL_END
