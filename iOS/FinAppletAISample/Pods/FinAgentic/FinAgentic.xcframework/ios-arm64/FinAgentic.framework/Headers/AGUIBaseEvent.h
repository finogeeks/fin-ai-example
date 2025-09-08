// AGUIBaseEvent.h
// AG-UI Protocol Objective-C SDK

#import <Foundation/Foundation.h>
#import "AGUIEventType.h"

@interface AGUIBaseEvent : NSObject
@property (nonatomic, assign) AGUIEventType type;
@property (nonatomic, strong, nullable) NSNumber *timestamp;
- (NSDictionary *_Nullable)toDictionary;
+ (instancetype _Nullable )fromDictionary:(NSDictionary *_Nonnull)dict;
@end

// --- Event subclasses ---

@interface ToolCallStartEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *toolCallId;
@property (nonatomic, copy) NSString *toolCallName;
- (instancetype)initWithToolCallId:(NSString *)toolCallId toolCallName:(NSString *)toolCallName;
@end

@interface ToolCallArgsEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *toolCallId;
@property (nonatomic, strong) NSDictionary *arguments;
- (instancetype)initWithToolCallId:(NSString *)toolCallId arguments:(NSDictionary *)arguments;
@end

@interface ToolCallEndEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *toolCallId;
- (instancetype)initWithToolCallId:(NSString *)toolCallId;
@end

@interface RunFinishedEvent : AGUIBaseEvent
@end

@interface StateDeltaEvent : AGUIBaseEvent
@property (nonatomic, strong) NSDictionary *delta;
- (instancetype)initWithDelta:(NSDictionary *)delta;
@end

@interface StateSnapshotEvent : AGUIBaseEvent
@property (nonatomic, strong) NSDictionary *snapshot;
- (instancetype)initWithSnapshot:(NSDictionary *)snapshot;
@end

@interface TextMessageStartEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *messageId;
@property (nonatomic, copy) NSString *role;
- (instancetype)initWithMessageId:(NSString *)messageId role:(NSString *)role;
@end

@interface TextMessageContentEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *messageId;
@property (nonatomic, copy) NSString *content;
- (instancetype)initWithMessageId:(NSString *)messageId content:(NSString *)content;
@end

@interface TextMessageEndEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *messageId;
- (instancetype)initWithMessageId:(NSString *)messageId;
@end

@interface StepStartedEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *stepId;
@property (nonatomic, copy) NSString *descriptionText;
- (instancetype)initWithStepId:(NSString *)stepId descriptionText:(NSString *)descriptionText;
@end

@interface RunErrorEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *errorMessage;
- (instancetype)initWithErrorMessage:(NSString *)errorMessage;
@end

@interface FATAGCustomEvent : AGUIBaseEvent
@property (nonatomic, copy) NSString *name;
@property (nonatomic, strong) NSDictionary *valueDic;
@property (nonatomic, assign) FATAGCustomEventType customEventType;
- (instancetype)initWithName:(NSString *)name valueDic:(NSDictionary *)valueDic;
@end
