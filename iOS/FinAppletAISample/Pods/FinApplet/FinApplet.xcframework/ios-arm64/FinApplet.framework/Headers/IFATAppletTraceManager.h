//
//  IFATAppletTraceManager.h
//  FinApplet
//
//  Created by chenfanfang on 2025/2/18.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol IFATAppletTraceManager <NSObject>

/// 上报可回溯日志
/// - Parameters:
///   - filePath: 日志的文件路径
///   - apiServer: ApiServer
///   - appletId: 小程序ID
///   - success: 成功的回调
///   - failure: 失败的回调
///
- (void)reportAppletTraceLog:(NSString *)filePath apiServer:(NSString *)apiServer appletId:(NSString *)appletId success:(void(^)(void))success failure:(void(^)(NSString *errorMessage))failure;

/// 获取所有小程序的可回溯日志文件路径
/// - Parameters:
///   - apiServer: 服务器地址
///   - appletId: 小程序id
///
- (NSArray<NSString *> *)getAppletTraceLogs:(NSString *)apiServer appletId:(NSString *)appletId;

/// 根据可回溯日志文件路径删除可回溯日志文件
/// - Parameter filePath: 可回溯文件日志路径
/// - Parameter complete: 完成的回调
///
- (void)deleteAppletTraceLogFile:(NSString *)filePath complete:(void(^)(void))complete;

/// 清除所有的小程序可回溯日志文件
/// - Parameter complete: 完成的回调
- (void)deleteAllAppletTraceLogFiles:(void(^)(void))complete;

@end

NS_ASSUME_NONNULL_END
