#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 用于 FATAIChatView 初始化后，向 Agent 发送数据的载荷模型
@interface FATAIChatPayload : NSObject

@property (nonatomic, copy, nullable) NSString *message;  // 发送的消息文本
@property (nonatomic, copy, nullable) NSString *prompt;   // 预置提示词
@property (nonatomic, copy, nullable) NSString *content;  // 附加内容（上下文、页面内容等）

/// 便利构造
+ (instancetype)requestWithMessage:(nullable NSString *)message
                            prompt:(nullable NSString *)prompt
                           content:(nullable NSString *)content;

/// 指定初始化
- (instancetype)initWithMessage:(nullable NSString *)message
                          prompt:(nullable NSString *)prompt
                         content:(nullable NSString *)content NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// 转换为可直接用于网络发送的字典
- (NSDictionary<NSString *, id> *)toDictionary;

@end

NS_ASSUME_NONNULL_END
