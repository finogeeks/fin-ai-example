//
//  FATAppletInteractionManager.h
//  FinApplet
//
//  Created by 滔 on 2025/7/7.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FATAppletInteractionManager : NSObject


/**
 * 在指定小程序在更多按钮上显示/隐藏小红点
 * @param show  是否显示
 * @param appletId 小程序id，不传的话，会获取当前小程序
 */
- (BOOL)setMoreButtonBadgeVisible:(BOOL)show forApplet:(NSString * _Nullable)appletId;


@end

NS_ASSUME_NONNULL_END
