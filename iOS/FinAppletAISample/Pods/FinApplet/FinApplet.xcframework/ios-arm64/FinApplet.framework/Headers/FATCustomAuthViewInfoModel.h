//
//  FATCustomAuthViewInfoModel.h
//  FinApplet
//
//  Created by chenfanfang on 2025/7/25.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"
#import "FATConstant.h"


NS_ASSUME_NONNULL_BEGIN

@interface FATCustomAuthViewInfoModel : NSObject

/// 权限类型
@property (nonatomic, assign) FATAuthorizationType scopeType;

/// 权限名称, 比如:scope.userLocation
@property (nonatomic, copy) NSString *scopeName;

/// 权限描述（也就是申请权限的标题）
@property (nonatomic, copy) NSString *scopeDesc;

/// 权限详细描述（也就是申请权限向用户说明的详细的描述）
@property (nonatomic, copy) NSString *scopeDetailDesc;

/// 自定义隐私协议文档名
@property (nonatomic, copy) NSString *customPrivacyDocName;

/// 自定义隐私协议文URL地址
@property (nonatomic, copy) NSString *customPrivacyDocUrl;

/// 当前的控制器, 显示的自定义弹窗可以添加在当前的控制器上
@property (nonatomic, strong) UIViewController *currentController;


@end

NS_ASSUME_NONNULL_END
