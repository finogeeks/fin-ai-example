//
//  FATAppletInteractionDelegate.h
//  FinApplet
//  小程序中用户交互的代理方法
//  Created by 滔 on 2025/2/26.
//  Copyright © 2025 finogeeks. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "FATAppletInfo.h"
#import "FATMediaInfo.h"

@protocol FATAppletInteractionDelegate <NSObject>

@optional

///  小程序中图片组件、previweImage、preivewMedia中多媒体长按事件，可根据多媒体信息选择性处理该事件，如果不处理该事件，返回NO，处理的话返回YES
/// - Parameters:
///   - appletInfo: 小程序信息
///   - meidaInfo: 多媒体信息，可能是网络图片/视频、沙盒路径图片/视频
- (BOOL)applet:(FATAppletInfo *)appletInfo handleImageLongPressed:(FATMediaInfo *)mediaInfo;

///  小程序中文字长按事件，如果不处理该事件，返回NO，处理的话返回YES
/// - Parameters:
///   - appletInfo: 小程序信息
///   - text: 长按选中的文字
- (BOOL)applet:(FATAppletInfo *)appletInfo handleTextLongPressed:(NSString *)text;

@end
