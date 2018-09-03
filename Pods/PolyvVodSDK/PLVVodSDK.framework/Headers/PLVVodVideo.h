//
//  PLVVodVideo.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/9.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodConstans.h"
#import "PLVVodAd.h"

/// 视频数据模型
@interface PLVVodVideo : NSObject

/// 视频 id
@property (nonatomic, copy, readonly) NSString *vid;

/// 视频标题
@property (nonatomic, copy, readonly) NSString *title;

/// 可用清晰度数量
@property (nonatomic, assign, readonly) int qualityCount;

/// 默认播放清晰度
@property (nonatomic, assign) PLVVodQuality preferredQuality;

/// 视频时长
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/// 源文件大小
@property (nonatomic, assign, readonly) NSInteger sourcefilesize;

/// 各码率视频大小
@property (nonatomic, strong, readonly) NSArray<NSNumber *> *filesizes;

/// 视频快照URL
@property (nonatomic, copy) NSString *snapshot;

/// 源文件播放
@property (nonatomic, assign, readonly) BOOL keepSource;

/// 分类id
@property (nonatomic, copy, readonly) NSString *categoryId;

/// 分类树
@property (nonatomic, strong, readonly) NSArray *categoryTree;

/// 是否存在问答
@property (nonatomic, assign, readonly) BOOL interactive;

/// 视频字幕（srtKey: srtUrl）
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *srts;

/// 广告信息
@property (nonatomic, strong) NSArray<PLVVodAd *> *ads;

/// 片头URL
@property (nonatomic, copy) NSString *teaser;

/// 片头播放时长
@property (nonatomic, assign) NSTimeInterval teaserDuration;

/// 是否显示片头
@property (nonatomic, assign) BOOL teaserShow;

/// 可用线路
@property (nonatomic, strong, readonly) NSArray<NSString *> *availableRouteLines;

/// 若视频不合法，可以从该属性获取不合法原因，否则为空
@property (nonatomic, strong) NSError *error;

@property (nonatomic, copy, readonly) NSString *aac_link;

/// 视频或账号是否可用
- (BOOL)available;

/// 视频是否为非加密视频
- (BOOL)isPlain;

/// 视频是否为hls视频
- (BOOL)isHls;

/// 是否能够切换音视频模式
- (BOOL)canSwithPlaybackMode;

/**
 请求获取 PLVVodVideo 模型对象
 
 @param vid vid
 @param completion PLVVodVideo 模型对象
 */
+ (void)requestVideoWithVid:(NSString *)vid completion:(void (^)(PLVVodVideo *video, NSError *error))completion;

#pragma mark - 内部接口

/// status 视频状态
@property (nonatomic, assign) int status;

/// outflow 账户是否超流量
@property (nonatomic, assign) BOOL outflow;

/// timeoutflow 账户是否过期
@property (nonatomic, assign) BOOL timeoutflow;

/// hlsIndex 视频主索引URL
@property (nonatomic, copy) NSString *hlsIndex;

/// hls 视频子索引URL
@property (nonatomic, strong) NSArray<NSString *> *hlsVideos;

/// mp4 videolink 各码率非加密资源 URL
@property (nonatomic, strong) NSArray<NSString *> *plainVideos;

/// packageUrl ts打包
@property (nonatomic, strong) NSArray<NSString *> *tsPackages;

/// 加密常量
@property (nonatomic, copy) NSString *constKey;

/// ts host
@property (nonatomic, copy) NSString *tsHost;

@end
