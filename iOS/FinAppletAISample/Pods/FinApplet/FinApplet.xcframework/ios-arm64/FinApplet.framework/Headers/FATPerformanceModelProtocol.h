//
//  FATPerformanceModelProtocol.h
//  FinApplet
//
//  Created by luojian on 2022/8/15.
//  Copyright © 2022 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol FATPerformanceModelProtocol <NSObject>

/**
 指标类型
 navigation    路由
 render          渲染
 script            脚本
 */
@property (nonatomic, copy) NSString *entryType;

/**
 指标名称
 
 appLaunch    小程序启动耗时。(entryType: navigation)
 route    路由处理耗时。(entryType: navigation)
 firstRender    页面首次渲染耗时。(entryType: render)
 firstPaint    页面首次绘制(FP)时间点，无 duration。（iOS 不支持）(entryType: render)    2.21.2
 firstContentfulPaint    页面首次内容绘制(FCP)时间点，无 duration。（iOS 14.5 以下版本不支持）(entryType: render)    2.21.2
 largestContentfulPaint    页面最大内容绘制(LCP)时间点，无 duration。（iOS 不支持）(entryType: render)    2.23.1
 evaluateScript    逻辑层 JS 代码注入耗时。(entryType: script)
 downloadPackage    代码包下载耗时。(entryType: loadPackage)    2.24.0
 resourceTiming    视图层资源加载耗时。(entryType: resource)    2.24.0

 */
@property (nonatomic, copy) NSString *name;
/// 指标标签，一般为空。用于区分entryType和name都相同的不同统计打点
@property (nonatomic, copy) NSString *tag;
/// 开始时间，不同指标的具体含义会有差异。
@property (nonatomic, assign) unsigned long long startTime;
/// 耗时 ms。仅对于表示阶段的指标有效。
@property (nonatomic, assign) unsigned long long duration;


/// 转成字典, 对应微信的 PerformanceEntry
/// https://developers.weixin.qq.com/miniprogram/dev/api/base/performance/PerformanceEntry.html
///
- (NSDictionary *)toDictionary;

@end

NS_ASSUME_NONNULL_END
