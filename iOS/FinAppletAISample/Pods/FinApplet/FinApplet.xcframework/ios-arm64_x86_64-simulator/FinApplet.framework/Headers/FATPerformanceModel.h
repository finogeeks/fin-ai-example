//
//  FATPerformanceModel.h
//  FinApplet
//
//  Created by luojian on 2022/8/3.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATPerformanceModelProtocol.h"

@interface FATPerformanceModel : NSObject <FATPerformanceModelProtocol>

/// 页面路径。仅 render 和 navigation 类型指标有效。
@property (nonatomic, copy) NSString *path;
/// 页面跳转来源页面路径。仅 route 指标有效。
@property (nonatomic, copy) NSString *referrerPath;
/// path 对应页面实例 Id（随机生成，不保证递增）。仅 render/navigation 指标有效。
@property (nonatomic, assign) unsigned long long pageId;
/// referrerPath对应页面实例 Id（随机生成，不保证递增）。仅 route 指标有效。
@property (nonatomic, assign) unsigned long long referrerPageId;
/// 路由真正响应开始时间。仅 navigation 类型指标有效。
@property (nonatomic, assign) long navigationStart;
/// 路由详细类型，与小程序路由方法对应。仅 navigation 类型指标有效。
@property (nonatomic, copy) NSString *navigationType;
/// 分包名，主包表示为 APP (2.21.2 开始)。仅 evaluateScript 指标有效。
@property (nonatomic, copy) NSString *moduleName;
/// 包大小。仅 downloadPackage 指标有效。
@property (nonatomic, assign) unsigned long long packageSize;
/// 包名称
@property (nonatomic, copy) NSString *packageName;
/// 基础库大小
@property (nonatomic, assign) unsigned long long frameworkSize;
/// 按需要注入的加载时间
@property (nonatomic, assign) unsigned long long lazyLoadTime;
/// 内存占用
@property (nonatomic, assign) double memoryUse;
/// 注入文件列表。仅 evaluateScript 指标有效。
@property (nonatomic, strong) NSArray<NSString *> *fileList;
/// 渲染层代码注入完成时间。仅 firstRender 指标有效。
@property (nonatomic, strong) NSNumber *viewLayerReadyTime;
/// 首次渲染参数从逻辑层发出的时间。仅 firstRender 指标有效。 init关键字，改成大写的
@property (nonatomic, strong) NSNumber *InitDataSendTime;
/// 首次渲染参数在渲染层收到的时间。仅 firstRender 指标有效。 init关键字，改成大写的
@property (nonatomic, strong) NSNumber *InitDataRecvTime;
/// 渲染层执行渲染开始时间。仅 firstRender 指标有效。
@property (nonatomic, strong) NSNumber *viewLayerRenderStartTime;
/// 渲染层执行渲染结束时间。仅 firstRender 指标有效。
@property (nonatomic, strong) NSNumber *viewLayerRenderEndTime;

//resource的指标参数


/// 资源路径。仅 resourceTiming 指标有效。
@property (nonatomic, copy) NSString *uri;

/// 初始化性能条目的资源类型。仅 resourceTiming 指标有效。
@property (nonatomic, copy) NSString *InitiatorType;

/// 解析域名开始时间。仅 resourceTiming 指标有效。
@property (nonatomic, strong) NSNumber *domainLookupStart;

/// 解析域名结束时间。仅 resourceTiming 指标有效。
@property (nonatomic, strong) NSNumber *domainLookupEnd;



/// 中文描述信息
- (NSString *)chineseSimpleDescription;

@end
