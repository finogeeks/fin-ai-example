//
//  FATAppletH5PublicDelegate.h
//  FinApplet
//
//  Created by chenfanfang on 2025/8/21.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"


NS_ASSUME_NONNULL_BEGIN

/// H5页面通用性的代理协议
@protocol FATAppletH5CommonDelegate <NSObject>

@optional

/// 小程序中的web-view组件、H5应用 对应的网页URL变化的回调
/// - Parameters:
///   - appletInfo: 小程序信息
///   - url: 变化的URL信息
///   - isBlocked: 当前URL是否被禁用
///   - pagePath: 当前页面在小程序中的路径。（H5应用这个值为nil）
- (void)applet:(FATAppletInfo *)appletInfo urlChange:(NSString *)url isBlocked:(BOOL)isBlocked pagePath:(NSString *)pagePath;

@end

NS_ASSUME_NONNULL_END
