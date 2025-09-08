#import <Foundation/Foundation.h>
#import "FATAIAgentConfig.h"
#import "AGUIBaseEvent.h"
#import "FATAITool.h"

@class FATAIAgent;

typedef void (^AgentConnectCallback)(BOOL success, NSError *error);
typedef void (^AgentEventMessageHandler)(AGUIBaseEvent *event);

typedef NS_ENUM(NSInteger, AgentState) {
    AgentStateDisconnected,
    AgentStateConnecting,
    AgentStateConnected
};

@class EventSource;

@interface FATAIAgent : NSObject

@property (nonatomic, strong, readonly) FATAIAgentConfig *config;
@property (nonatomic, assign, readonly) AgentState state;
@property (nonatomic, strong) NSMutableDictionary<NSString *, NSString *> *headers;
@property (nonatomic, strong) NSDictionary *appletInfo;
@property (nonatomic, strong, readonly) EventSource *eventSource;

//收到agent数据
@property (nonatomic, copy) AgentEventMessageHandler onEventMessage;
//请求结果
@property (nonatomic, copy) AgentConnectCallback onConnect;

- (instancetype)initWithConfig:(FATAIAgentConfig *)config;

- (void)disconnect;

- (void)sendMessage:(NSString *)message;

- (void)senMessage:(NSString *)message withContent:(NSString *)content;

- (void)addHeaders:(NSDictionary<NSString *, NSString *> *)headers;

// 注册Tool
- (void)registerTool:(FATAITool *)action;
/// 通过名称获取已注册的 Tool（仅检索当前 Agent 注册的 Tool）
- (FATAITool *)getToolByName:(NSString *)toolName;
 

/// 发送工具执行成功结果（仅携带 result）
- (void)sendToolSuccess:(NSString *)toolCallId
                 result:(nullable NSDictionary<NSString *, id> *)resultDic;

/// 发送工具执行失败结果（仅携带 error）
- (void)sendToolFailure:(NSString *)toolCallId
                   error:(nullable NSString *)error;
                      



@end
