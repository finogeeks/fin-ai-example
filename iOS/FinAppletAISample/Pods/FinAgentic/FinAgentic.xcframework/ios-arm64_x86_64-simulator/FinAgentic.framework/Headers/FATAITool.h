//
//  FATAITool.h
//  FinAgentic
//
//  Created by 滔 on 2025/8/21.
//

#import <Foundation/Foundation.h>
#import "FATAIParamSchema.h"

NS_ASSUME_NONNULL_BEGIN

@interface FATAIToolResult : NSObject

@property (nonatomic, assign) BOOL result; // YES 成功 / NO 失败
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *data; // 执行后的返回数据（可为 nil）

+ (instancetype)successWithData:(nullable NSDictionary<NSString *, id> *)data;
+ (instancetype)failureWithData:(nullable NSDictionary<NSString *, id> *)data;

@end

@interface FATAITool : NSObject

@property (nonatomic, copy) NSString *toolName;

@property (nonatomic, copy) NSString *descText;

@property (nonatomic, strong, nullable) FATAIParamSchema *paramsSchema;

/// 处理器在主线程或调用线程执行，由调用方保证线程模型
@property (nonatomic, copy) FATAIToolResult * _Nullable (^handler)(NSDictionary<NSString *, id> *params);

/// 便利构造器
+ (instancetype)toolWithName:(NSString *)toolName
                        desc:(NSString *)descText
                paramsSchema:(FATAIParamSchema * _Nullable)paramsSchema
                      handler:(FATAIToolResult * _Nullable (^)(NSDictionary<NSString *, id> *params))handler;

/// 设计化初始化方法
- (instancetype)initWithToolName:(NSString *)toolName
                      desc:(NSString *)descText
              paramsSchema:(FATAIParamSchema * _Nullable)paramsSchema
                    handler:(FATAIToolResult * _Nullable (^)(NSDictionary<NSString *, id> *params))handler NS_DESIGNATED_INITIALIZER;

/// 执行处理器
- (FATAIToolResult * _Nullable)executeWithParams:(NSDictionary<NSString *, id> *)params;

@end

NS_ASSUME_NONNULL_END
