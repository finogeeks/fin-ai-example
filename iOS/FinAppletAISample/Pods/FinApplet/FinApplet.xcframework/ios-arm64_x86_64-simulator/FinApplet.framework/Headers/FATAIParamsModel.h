//
//  FATAIParamsModel.h
//  FinApplet
//
//  Created by chenfanfang on 2025/8/23.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSDictionary<NSString *, id> * _Nullable (^FATToolHandler)(NSDictionary<NSString *, id> *params);


@interface FATAIParamsModel : NSObject


/** webview中的内容 */
@property (nonatomic, copy) NSString *webviewContent;

/** 事件列表 */
@property (nonatomic, strong) NSArray *toolArray;

/** 内置的prompt，固定提示词 */
@property (nonatomic, copy) NSString *prompt;

//显示到chatUI的消息内容
@property (nonatomic, copy) NSString *message;

@end

NS_ASSUME_NONNULL_END
