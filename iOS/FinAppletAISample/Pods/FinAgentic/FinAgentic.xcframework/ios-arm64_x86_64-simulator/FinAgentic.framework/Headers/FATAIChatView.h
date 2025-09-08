#import <UIKit/UIKit.h>
#import "FATAIAgent.h"
#import "FATAIChatPayload.h"



NS_ASSUME_NONNULL_BEGIN

@protocol FATAIChatViewDelegate <NSObject>

- (void)openApplet:(NSString *)appId withServer:(NSString *)server;

@end

@interface FATAIChatView : UIView

@property (nonatomic, strong) FATAIAgent *agent;

@property (nonatomic, weak) id<FATAIChatViewDelegate> delegate;

- (instancetype)initWithAgent:(FATAIAgent *)agent;

- (instancetype)initWithAgent:(FATAIAgent *)agent payload:(FATAIChatPayload *)playload;


@end

NS_ASSUME_NONNULL_END
