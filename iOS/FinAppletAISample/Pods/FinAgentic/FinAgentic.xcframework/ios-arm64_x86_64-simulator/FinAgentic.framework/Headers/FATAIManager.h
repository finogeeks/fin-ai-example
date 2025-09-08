#import <Foundation/Foundation.h>
#import "FATAIAgentConfig.h"
#import "FATAITool.h"

@class FATAITool;

NS_ASSUME_NONNULL_BEGIN

@interface FATAIManager : NSObject

@property (nonatomic, strong, readonly) NSMutableArray<FATAIAgentConfig *> *agents;

+ (instancetype)shared;

// Agent管理
- (void)addAgent:(FATAIAgentConfig *)agent;

- (void)updateAgent:(FATAIAgentConfig *)agent;

- (void)deleteAgent:(FATAIAgentConfig *)agent;

- (NSArray<FATAIAgentConfig *> *)getAllAgents;

// 注入 APP 能力的 Action
- (void)registerAPPTool:(FATAITool *)tool;

/// 读取所有已注册的 Action
- (NSDictionary<NSString *, FATAITool *> *)getAllTools;





@end

NS_ASSUME_NONNULL_END
