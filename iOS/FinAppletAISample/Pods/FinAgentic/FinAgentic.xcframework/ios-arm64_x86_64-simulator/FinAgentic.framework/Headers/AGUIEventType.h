// AGUIEventType.h
// AG-UI Protocol Objective-C SDK

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AGUIEventType) {
    AGUIEventTypeTextMessageStart,
    AGUIEventTypeTextMessageContent,
    AGUIEventTypeTextMessageEnd,
    AGUIEventTypeTextMessageChunk,
    AGUIEventTypeThinkingTextMessageStart,
    AGUIEventTypeThinkingTextMessageContent,
    AGUIEventTypeThinkingTextMessageEnd,
    AGUIEventTypeToolCallStart,
    AGUIEventTypeToolCallArgs,
    AGUIEventTypeToolCallEnd,
    AGUIEventTypeToolCallChunk,
    AGUIEventTypeToolCallResult,
    AGUIEventTypeThinkingStart,
    AGUIEventTypeThinkingEnd,
    AGUIEventTypeStateSnapshot,
    AGUIEventTypeStateDelta,
    AGUIEventTypeMessagesSnapshot,
    AGUIEventTypeRaw,
    AGUIEventTypeCustom,
    AGUIEventTypeRunStarted,
    AGUIEventTypeRunFinished,
    AGUIEventTypeRunError,
    AGUIEventTypeStepStarted,
    AGUIEventTypeStepFinished
};

typedef NS_ENUM(NSInteger, FATAGCustomEventType) {
    FATAGCustomEventTypeUnknown = 0,
    FATAGCustomEventTypeRecommend,
    FATAGCustomEventTypeButton,
    FATAGCustomEventTypeAlert,
    FATAGCustomEventTypeShare
};

NSString *AGUIEventTypeToString(AGUIEventType type);
AGUIEventType AGUIEventTypeFromString(NSString *str);

NSString *FATAGCustomEventTypeToString(FATAGCustomEventType type);
FATAGCustomEventType FATAGCustomEventTypeFromString(NSString *str);
