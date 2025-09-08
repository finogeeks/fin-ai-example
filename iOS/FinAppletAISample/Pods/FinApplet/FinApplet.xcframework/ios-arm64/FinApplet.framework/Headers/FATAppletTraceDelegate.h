//
//  FATAppletTraceDelegate.h
//  FinApplet
//
//  Created by chenfanfang on 2025/2/12.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 小程序可回溯的代理
@protocol FATAppletTraceDelegate <NSObject>

@optional

/// 请求用户的授权，是否同意开启可回溯功能
/// - Parameter completion: 完成的回到 enableTrace: true 代表同意开启可回溯功能
- (void)requestUserAuthorization:(void (^)(BOOL enableTrace))completion;

@end

NS_ASSUME_NONNULL_END
