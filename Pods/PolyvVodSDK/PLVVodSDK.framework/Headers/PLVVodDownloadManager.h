//
//  PLVVodDownloadManager.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/12.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodDownloadInfo.h"
#import "PLVVodVideo.h"
#import "PLVVodLocalVideo.h"

/**
 视频下载管理单例
 */
@interface PLVVodDownloadManager : NSObject

/// 下载目录，默认为 Library/Caches/PolyvVodCache。修改下载目录后，上一个目录的离线视频将无法索引。
@property (nonatomic, copy) NSString *downloadDir;

/// 是否允许使用蜂窝移动网络进行下载，默认 YES
@property (nonatomic, assign) BOOL allowsCellularAccess;

/// 是否启用后台下载，默认 YES
@property (nonatomic, assign) BOOL enableBackgroundDownload;

/// 后台下载会话标识符
//@property (nonatomic, copy, readonly) NSString *sessionId;

/// 添加任务后是否自动启动，默认 NO
@property (nonatomic, assign) BOOL autoStart;

/// 保存的后台下载会话block
@property (nonatomic, copy) void (^backgroundCompletionHandler)(void);

/// 完成所有下载回调
@property (nonatomic, copy) void(^completeBlock)(void);

/// 下载错误回调
@property (nonatomic, copy) void (^downloadErrorHandler)(PLVVodVideo *video, NSError *error);

/**
 PLVVodDownloadManager 共享的静态对象

 @return PLVVodDownloadManager 共享的静态对象
 */
+ (instancetype)sharedManager;

/**
 设置下载目录

 @param downloadDir 设置的下载目录
 @param skipBackup 是否忽略 iCloud 的备份
 @param error 错误回调
 @return 是否成功
 */
- (BOOL)setDownloadDir:(NSString *)downloadDir skipBackup:(BOOL)skipBackup error:(NSError **)error;

/**
 添加至下载队列
 
 添加下载器，仅当 video 错误时，才会报错，quality 错误时，只会警告，并切换到最近的质量进行下载。

 @param video PLVVodVideo 视频对象
 @param quality 视频画质
 @return 下载信息
 */
- (PLVVodDownloadInfo *)downloadVideo:(PLVVodVideo *)video quality:(PLVVodQuality)quality;

/**
 使用后台设置的默认画质添加至下载队列

 @param video PLVVodVideo 视频对象
 @return 下载信息
 */
- (PLVVodDownloadInfo *)downloadVideo:(PLVVodVideo *)video;

/**
 开始队列下载
 */
- (void)startDownload;

/**
 停止队列下载
 */
- (void)stopDownload;

/**
 移除下载任务，并删除对应文件

 @param vid vid
 @param error 错误回调
 */
- (void)removeDownloadWithVid:(NSString *)vid error:(NSError **)error;

/**
 获取所有下载任务信息

 @param completion 完成回调
 */
- (void)requestDownloadInfosWithCompletion:(void (^)(NSArray<PLVVodDownloadInfo *> *downloadInfos))completion;

#pragma mark - 工具方法

/**
 删除指定视频
 
 删除视频，会删除包含 vid 的所有离线资源（与下载任务无关）。

 @param vid vid
 @param error 错误回调
 */
+ (void)removeVideoWithVid:(NSString *)vid error:(NSError **)error;

/**
 删除下载目录下所有资源
 
 删除下载目录下所有离线资源（与下载任务无关）。

 @param error 错误回调
 */
+ (void)removeAllVideoWithError:(NSError **)error;

/**
 获取已下载的本地视频

 @return 一组 PLVVodLocalVideo 对象
 */
- (NSArray<PLVVodLocalVideo *> *)localVideos;

/**
 判断指定视频是否存在本地
 
 指定 vid 视频是否已下载，返回指定 vid 的清晰度，返回 0 则不存在该视频。

 @param vid vid
 @return 指定视频的画质
 */
+ (PLVVodQuality)videoExist:(NSString *)vid;

/**
 兼容 1.x.x 版本的离线视频
 
 注意：
 - 实现兼容的前提是使用相同的下载目录，必须保证与之前版本的下载目录一致；
 - 该方法调用一次即可，多次调用也不会修改文件。
 */
- (void)compatibleWithPreviousVideos;

/**
 
 在AppDelegate 中调用，程序即将结束时，修改并保存下载中视频的下载状态，用于
 程序下次启动后，恢复视频下载状态
 
 */
- (void)applicationWillTerminate;

@end
