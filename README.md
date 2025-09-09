<p align="center">
    <a href="https://www.finclip.com?from=github">
    <img width="auto" src="https://www.finclip.com/mop/document/images/logo.png">
    </a>
</p>

<p align="center"> 
    <strong>FinClip AI iOS 集成示例</strong></br>
<p>
<p align="center"> 
        本项目展示如何在 iOS 应用中集成 FinApplet SDK 并启用 AI 功能
<p>

<p align="center"> 
	👉 <a href="https://www.finclip.com?from=github">https://www.finclip.com/</a> 👈
</p>

<div align="center">

<a href="#"><img src="https://img.shields.io/badge/%E4%B8%93%E5%B1%9E%E5%BC%80%E5%8F%91%E8%80%85-20000%2B-brightgreen"></a>
<a href="#"><img src="https://img.shields.io/badge/%E5%B7%B2%E4%B8%8A%E6%9E%B6%E5%B0%8F%E7%A8%8B%E5%BA%8F-6000%2B-blue"></a>
<a href="#"><img src="https://img.shields.io/badge/%E5%B7%B2%E9%9B%86%E6%88%90%E5%B0%8F%E7%A8%8B%E5%BA%8F%E5%BA%94%E7%94%A8-75%2B-yellow"></a>
<a href="#"><img src="https://img.shields.io/badge/%E5%AE%9E%E9%99%85%E8%A6%86%E7%9B%96%E7%94%A8%E6%88%B7-2500%20%E4%B8%87%2B-orange"></a>

<a href="https://www.zhihu.com/org/finchat"><img src="https://img.shields.io/badge/FinClip--lightgrey?logo=zhihu&style=social"></a>
<a href="https://www.finclip.com/blog/"><img src="https://img.shields.io/badge/FinClip%20Blog--lightgrey?logo=ghost&style=social"></a>



</div>

<p align="center">

<div align="center">

[官方网站](https://www.finclip.com/) | [示例小程序](https://www.finclip.com/#/market) | [开发文档](https://www.finclip.com/mop/document/) | [部署指南](https://www.finclip.com/mop/document/introduce/quickStart/cloud-server-deployment-guide.html) | [SDK 集成指南](https://www.finclip.com/mop/document/introduce/quickStart/intergration-guide.html) | [API 列表](https://www.finclip.com/mop/document/develop/api/overview.html) | [组件列表](https://www.finclip.com/mop/document/develop/component/overview.html) | [隐私承诺](https://www.finclip.com/mop/document/operate/safety.html)

</div>

-----
## 🤔 FinClip 是什么?

有没有**想过**，开发好的微信小程序能放在自己的 APP 里直接运行，只需要开发一次小程序，就能在不同的应用中打开它，是不是很不可思议？

有没有**试过**，在自己的 APP 中引入一个 SDK ，应用中不仅可以打开小程序，还能自定义小程序接口，修改小程序样式，是不是觉得更不可思议？

这就是 FinClip ，就是有这么多不可思议！

## 🤖 FinApplet AI 功能

FinApplet SDK 从 2.49.x 版本开始支持 AI 功能，允许小程序调用 AI 相关的 API 接口，实现智能化的用户体验。

## 📱 iOS 项目结构

本示例项目使用 Objective-C 开发，展示了 FinApplet SDK 的 AI 功能集成方法。

### 项目目录说明
```
iOS/FinAppletAISample/
├── FinAppletAISample/           # 主工程目录
│   ├── AppDelegate.m            # SDK 初始化和 AI 功能配置
│   ├── ViewController.m         # 打开小程序的示例代码
│   └── ...
├── Podfile                      # CocoaPods 依赖配置
└── Pods/                        # 依赖库目录
```

## ⚙️ iOS 集成步骤

### 第一步：配置 Podfile 依赖

在 Podfile 中添加 FinApplet SDK 依赖，注意需要使用支持 AI 功能的版本（2.49.x 及以上）：

```ruby
platform :ios, '15.0'
source 'https://git.finogeeks.com/cocoapods/FinPods'
source 'https://mirrors.tuna.tsinghua.edu.cn/git/CocoaPods/Specs.git'

target 'FinAppletAISample' do
  use_frameworks!
  
  # 使用支持 AI 功能的 SDK 版本
  pod 'FinApplet', '2.49.8-dev20250908v11'
end
```

执行 `pod install` 安装依赖。

### 第二步：初始化 SDK 并启用 AI 功能

在 `AppDelegate.m` 的 `application:didFinishLaunchingWithOptions:` 方法中初始化 SDK：

```objc
#import <FinApplet/FinApplet.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // 配置服务器信息
    NSMutableArray *storeArrayM = [NSMutableArray array];
    FATStoreConfig *storeConfig = [[FATStoreConfig alloc] init];
    storeConfig.sdkKey = @"您的sdkKey";
    storeConfig.sdkSecret = @"您的sdkSecret";
    storeConfig.apiServer = @"https://api.finclip.com";
    storeConfig.cryptType = FATApiCryptTypeSM; // 使用国密加密
    [storeArrayM addObject:storeConfig];
    
    // 创建配置并启用 AI 功能
    FATConfig *config = [FATConfig configWithStoreConfigs:storeArrayM];
    config.openAI = YES;  // 🔑 关键：启用 AI 功能
    
    // 初始化 SDK
    BOOL result = [[FATClient sharedClient] initWithConfig:config error:nil];
    NSLog(@"SDK 初始化%@！", result ? @"成功" : @"失败");
    
    return YES;
}
```

### 第三步：打开支持 AI 的小程序

在 `ViewController.m` 中实现打开小程序的功能：

```objc
#import <FinApplet/FinApplet.h>

- (IBAction)openApplet:(id)sender {
    FATAppletRequest *request = [[FATAppletRequest alloc] init];
    request.appletId = @"小程序ID";
    
    [[FATClient sharedClient] startAppletWithRequest:request 
                         InParentViewController:self 
                                     completion:^(BOOL result, FATError *error) {
        if (result) {
            NSLog(@"打开小程序成功");
        } else {
            NSLog(@"打开小程序失败: %@", error);
        }
    } closeCompletion:^{
        NSLog(@"小程序已关闭");
    }];
}
```

## 🔑 关键配置说明

### AI 功能启用
- **重要**：必须设置 `config.openAI = YES` 才能启用 AI 功能
- SDK 版本要求：2.49.x 或更高版本
- 小程序端需要相应的 AI API 调用权限

### SDK 初始化参数
- `sdkKey` 和 `sdkSecret`：从 FinClip 管理后台获取
- `apiServer`：服务器地址，默认为 `https://api.finclip.com`
- `cryptType`：加密类型，推荐使用 `FATApiCryptTypeSM`（国密）

### 多服务器配置（可选）
如需连接多个服务器，可以添加多个 `FATStoreConfig`：

```objc
// 第二个服务器配置
FATStoreConfig *storeConfig2 = [[FATStoreConfig alloc] init];
storeConfig2.sdkKey = @"另一个sdkKey";
storeConfig2.sdkSecret = @"另一个sdkSecret";
storeConfig2.apiServer = @"另一个服务器地址";
[storeArrayM addObject:storeConfig2];
```

## 📋 注意事项

1. **Bundle ID 关联**：SDK 的 `sdkKey` 和 `sdkSecret` 与应用的 Bundle ID 强关联，修改 Bundle ID 需要重新申请密钥
2. **初始化时机**：所有小程序相关操作必须在 SDK 初始化成功后进行
3. **iOS 版本要求**：最低支持 iOS 15.0
4. **AI 功能权限**：需要在 FinClip 管理后台为小程序配置相应的 AI API 调用权限

## 🔐 获取 SDK 密钥

- **SDK KEY** 和 **SDK SECRET** 可以从 [FinClip](https://finclip.com/#/home) 获取，点 [这里](https://finclip.com/#/register) 注册账号
- 进入平台后，在「应用管理」页面添加你自己的包名后，点击「复制」即可获得 key/secret/apiserver 字段
- **小程序 ID** 是管理后台上架的小程序 APP ID，需要在「小程序管理」中创建并在「应用管理」中关联
> 小程序 ID 与微信小程序 ID 不一样（这里特指 FinClip 平台的 ID）

## 🧪 示例项目运行

1. 克隆本仓库到本地
2. 进入 iOS 项目目录：`cd iOS/FinAppletAISample`
3. 安装依赖：`pod install`
4. 打开 `FinAppletAISample.xcworkspace`
5. 修改 `AppDelegate.m` 中的 SDK 配置信息
6. 运行项目到真机或模拟器

## 📋 集成文档
[点击这里](https://www.finclip.com/mop/document/introduce/quickStart/intergration-guide.html#_1-ios-%E5%BF%AB%E9%80%9F%E9%9B%86%E6%88%90) 查看 iOS 快速集成文档


## 🔗 常用链接
以下内容是您在 FinClip 进行开发与体验时，常见的问题与指引信息

- [FinClip 官网](https://www.finclip.com/#/home)
- [示例小程序](https://www.finclip.com/#/market)
- [文档中心](https://www.finclip.com/mop/document/)
- [SDK 部署指南](https://www.finclip.com/mop/document/introduce/quickStart/intergration-guide.html)
- [小程序代码结构](https://www.finclip.com/mop/document/develop/guide/structure.html)
- [iOS 集成指引](https://www.finclip.com/mop/document/runtime-sdk/ios/ios-integrate.html)
- [Android 集成指引](https://www.finclip.com/mop/document/runtime-sdk/android/android-integrate.html)
- [Flutter 集成指引](https://www.finclip.com/mop/document/runtime-sdk/flutter/flutter-integrate.html)

## ☎️ 联系我们
微信扫描下面二维码，关注官方公众号 **「凡泰极客」**，获取更多精彩内容。<br>
<img width="150px" src="https://www.finclip.com/mop/document/images/ic_qr.svg">

微信扫描下面二维码，加入官方微信交流群，获取更多精彩内容。<br>
<img width="150px" src="https://www-cdn.finclip.com/images/qrcode/qrcode_shequn_text.png">

## Stargazers
[![Stargazers repo roster for @finogeeks/finclip-ios-demo](https://reporoster.com/stars/finogeeks/finclip-ios-demo)](https://github.com/finogeeks/finclip-ios-demo/stargazers)

## Forkers
[![Forkers repo roster for @finogeeks/finclip-ios-demo](https://reporoster.com/forks/finogeeks/finclip-ios-demo)](https://github.com/finogeeks/finclip-ios-demo/network/members)
