//
//  PLVVodLocalVideo.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/12.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import "PLVVodVideo.h"

/// 本地视频数据模型（PLVVodVideo 子类）
@interface PLVVodLocalVideo : PLVVodVideo

/// vid
@property (nonatomic, copy, readonly) NSString *vid;

/// 清晰度
@property (nonatomic, assign, readonly) PLVVodQuality quality;

/// 本地路径，hls为m3u8路径
@property (nonatomic, copy, readonly) NSString *path;

/// 文件大小
@property (nonatomic, assign, readonly) NSInteger filesize;

/// 是否为非加密视频
- (BOOL)isPlain;

/// 是否为HLS视频
- (BOOL)isHls;

/**
 获取对应目录的离线视频对象

 @param video 在线视频对象
 @param dir 离线视频目录
 @return 包含传入的 PLVVodVideo 对象信息的新的 PLVVodLocalVideo 对象
 */
+ (instancetype)localVideoWithVideo:(PLVVodVideo *)video dir:(NSString *)dir;
/**
 获取对应目录的离线视频对象

 @param vid vid
 @param dir 离线视频目录
 @return 对应目录的 PLVVodLocalVideo 对象
 */
+ (instancetype)localVideoWithVid:(NSString *)vid dir:(NSString *)dir;

/*:
  获取目录下的离线视频
 
 @param dir 离线视频目录
 @return 对应目录的一组 PLVVodLocalVideo 对象
 */
+ (NSArray<PLVVodLocalVideo *> *)localVideosWithDir:(NSString *)dir;

@end
