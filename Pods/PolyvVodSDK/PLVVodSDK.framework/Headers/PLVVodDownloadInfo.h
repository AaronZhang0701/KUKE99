//
//  PLVVodDownloadInfo.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/12.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodConstans.h"
#import "PLVVodVideo.h"
/**
 下载状态
 */
typedef NS_ENUM(NSInteger, PLVVodDownloadState) {
	/// 下载准备中
	PLVVodDownloadStatePreparing,	// 准备
	/// 下载器准备就绪，下载任务已创建
	PLVVodDownloadStateReady,		// 就绪，下载任务已创建
	/// 正在下载
	PLVVodDownloadStateRunning,		// 正在下载
	/// 停止下载中
	PLVVodDownloadStateStopping,	// 正在停止
	/// 下载已停止
	PLVVodDownloadStateStopped,		// 停止下载
	/// 下载成功
	PLVVodDownloadStateSuccess,		// 下载成功
	/// 下载失败，失败错误信息可从 `error` 属性获取
	PLVVodDownloadStateFailed		// 下载失败
};
/**
 PLVVodDownloadState 本地字符串

 @param state 下载状态
 @return 描述字符串
 */
NS_INLINE NSString *NSStringFromPLVVodDownloadState(PLVVodDownloadState state) {
	NSString *string = nil;
	switch (state) {
		case PLVVodDownloadStatePreparing:{
			string = @"准备";
		}break;
		case PLVVodDownloadStateReady:{
			string = @"就绪";
		}break;
		case PLVVodDownloadStateRunning:{
			string = @"下载中";
		}break;
		case PLVVodDownloadStateStopping:{
			string = @"停止中";
		}break;
		case PLVVodDownloadStateStopped:{
			string = @"停止";
		}break;
		case PLVVodDownloadStateSuccess:{
			string = @"成功";
		}break;
		case PLVVodDownloadStateFailed:{
			string = @"失败";
		}break;
		default:{}break;
	}
	return string;
}

@interface PLVVodDownloadInfo : NSObject

/// PLVVodVideo 对象
@property (nonatomic, strong, readonly) PLVVodVideo *video;

/// vid 便捷属性
@property (nonatomic, copy, readonly) NSString *vid;

/// 清晰度
@property (nonatomic, assign, readonly) PLVVodQuality quality;

/// 下载状态
@property (nonatomic, assign, readonly) PLVVodDownloadState state;
@property (nonatomic, copy) void (^stateDidChangeBlock)(PLVVodDownloadInfo *info);

/// 下载速率（单位：byte/s）
@property (nonatomic, assign, readonly) double bytesPerSeconds;
@property (nonatomic, copy) void (^bytesPerSecondsDidChangeBlock)(PLVVodDownloadInfo *info);

/// 下载进度（0-1）
@property (nonatomic, assign, readonly) double progress;
@property (nonatomic, copy) void (^progressDidChangeBlock)(PLVVodDownloadInfo *info);

/// 下载错误
@property (nonatomic, strong, readonly) NSError *error;

/// 队列ID
@property (nonatomic, assign, readonly) NSInteger downloadId;

@end
