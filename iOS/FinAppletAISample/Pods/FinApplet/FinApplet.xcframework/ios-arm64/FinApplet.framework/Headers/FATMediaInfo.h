//
//  FATImageInfo.h
//  FinApplet
//
//  Created by 滔 on 2025/2/26.
//  Copyright © 2025 finogeeks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, FATAppletMediaType) {
    FATAppletImageType = 0,
    FATAppletVideoType
};

@interface FATMediaInfo : NSObject
//多媒体类型，图片或视频
@property (nonatomic, assign) FATAppletMediaType mediaType;
//多媒体文件路径，可能是网络资源或沙盒路径
@property (nonatomic, copy) NSString *mediaUrl;
@end

NS_ASSUME_NONNULL_END
