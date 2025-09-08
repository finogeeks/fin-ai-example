#import <Foundation/Foundation.h>

@interface FATAIAgentConfig : NSObject
@property (nonatomic, copy) NSString *agentId;
@property (nonatomic, copy) NSString *name;
@property (nonatomic, copy) NSString *url;
@property (nonatomic, copy) NSString *desc;
@property (nonatomic, copy) NSDictionary *customHeaders;
- (instancetype)initWithId:(NSString *)agentId
                     name:(NSString *)name
                      url:(NSString *)url;
@end
