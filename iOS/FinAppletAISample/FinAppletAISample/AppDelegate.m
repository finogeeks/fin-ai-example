//
//  AppDelegate.m
//  FinAppletAISample
//
//  Created by chenfanfang on 2025/9/8.
//

#import "AppDelegate.h"
#import <FinApplet/FinApplet.h>
#import <FinAgentic/FinAgentic.h>

/*
 初始化SDK配置。
 注意：bundleid与sdkKey、sdkSecret强相关，所以如果只修改bundleid不改其他配置会导致初始化SDK失败
 */
static NSString *sdkKey1 = @"22LyZEib0gLTQdU3MUauATBwgfnTCJjdr7FCnywmAEM=";
static NSString *sdkSecret1 = @"bdfd76cae24d4313";
static NSString *apiServer1 = @"https://api.finclip.com";

static NSString *sdkKey2 = @"";
static NSString *sdkSecret2 = @"";
static NSString *apiServer2 = @"";

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NSMutableArray *storeArrayM = [NSMutableArray array];
    FATStoreConfig *storeConfig1 = [[FATStoreConfig alloc] init];
    storeConfig1.sdkKey = sdkKey1;
    storeConfig1.sdkSecret = sdkSecret1;
    storeConfig1.apiServer = apiServer1;
    storeConfig1.cryptType = FATApiCryptTypeSM;
    [storeArrayM addObject:storeConfig1];
    
    /*
     如果有多个服务器，也可以多注册一组配置，但是要注意多个配置都成功时,初始化SDK才会成功
     */
//    FATStoreConfig *storeConfig2 = [[FATStoreConfig alloc] init];
//    storeConfig2.sdkKey = sdkKey2;
//    storeConfig2.sdkSecret = sdkSecret2;
//    storeConfig2.apiServer = apiServer2;
//    storeConfig2.cryptType = FATApiCryptTypeSM;
//    [storeArrayM addObject:storeConfig2];
       
    FATConfig *config = [FATConfig configWithStoreConfigs:storeArrayM];
    config.openAI = YES;
    /*
     注意：小程序的其他操作必须放在FATClient初始化之后，否则失效！！！
     */
    BOOL result = [[FATClient sharedClient] initWithConfig:config error:nil];
    NSLog(@"注册SDK%@！！！！", result? @"成功" : @"失败");
    // 需要添加至App中的代码--end
    
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
