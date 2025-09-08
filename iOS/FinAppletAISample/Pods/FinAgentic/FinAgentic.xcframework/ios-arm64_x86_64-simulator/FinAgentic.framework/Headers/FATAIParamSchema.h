//
//  FATAIParamSchema.h
//  FinAgentic
//
//  Schema model for action parameters (JSON Schema-like minimal subset)
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 属性 Schema，映射为 JSON 里的每个 property 定义
/// 形如：{ "type": "string", "enum": [ ... ], "description": "..." }
typedef NS_ENUM(NSInteger, FATAIPropertyType) {
    FATAIPropertyTypeString,
    FATAIPropertyTypeNumber,
    FATAIPropertyTypeInteger,
    FATAIPropertyTypeBoolean,
    FATAIPropertyTypeArray,
    FATAIPropertyTypeObject,
    FATAIPropertyTypeNull,
};

@interface FATAIPropertyValue : NSObject
@property (nonatomic, assign) FATAIPropertyType type; // 强类型，序列化为字符串
@property (nonatomic, copy, nullable) NSArray<id> *enumValues; // 可为 NSString/NSNumber
@property (nonatomic, copy, nullable) NSString *descText; // 对应 description
@property (nonatomic, copy, nullable) NSDictionary<NSString *, FATAIPropertyValue *> *properties;

- (NSDictionary<NSString *, id> *)toJSON;
+ (nullable instancetype)fromJSON:(NSDictionary<NSString *, id> *)json;

/// 工具方法：类型与字符串互转
+ (NSString *)stringFromType:(FATAIPropertyType)type;
+ (BOOL)parseTypeString:(NSString *)str outType:(FATAIPropertyType *)outType;
@end

/// 顶层参数 Schema，仅保留 properties 和 required
@interface FATAIParamSchema : NSObject
@property (nonatomic, copy, nullable) NSDictionary<NSString *, FATAIPropertyValue *> *properties;
@property (nonatomic, copy, nullable) NSArray<NSString *> *required;

- (NSDictionary<NSString *, id> *)toJSON;
+ (nullable instancetype)fromJSON:(NSDictionary<NSString *, id> *)json;
@end

NS_ASSUME_NONNULL_END
