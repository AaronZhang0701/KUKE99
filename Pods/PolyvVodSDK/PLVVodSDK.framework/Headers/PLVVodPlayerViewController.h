//
//  PLVVodPlayerViewController.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/9.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLVVodVideo.h"
#import "PLVVodLocalVideo.h"
#import "PLVVodPlayerSkinProtocol.h"
#import "PLVVodAdPlayerViewController.h"

/// 拉伸模式
typedef NS_ENUM(NSInteger, PLVVodMovieScalingMode) {
	PLVVodMovieScalingModeNone,
	PLVVodMovieScalingModeAspectFit,
	PLVVodMovieScalingModeAspectFill,
	PLVVodMovieScalingModeFill
};

/// 播放状态
typedef NS_ENUM(NSInteger, PLVVodPlaybackState) {
	PLVVodPlaybackStateStopped,
	PLVVodPlaybackStatePlaying,
	PLVVodPlaybackStatePaused,
	PLVVodPlaybackStateInterrupted,
	PLVVodPlaybackStateSeekingForward,
	PLVVodPlaybackStateSeekingBackward
};

/// 加载状态
typedef NS_OPTIONS(NSUInteger, PLVVodLoadState) {
	PLVVodLoadStateUnknown        = 0,
	PLVVodLoadStatePlayable       = 1 << 0,
	PLVVodLoadStatePlaythroughOK  = 1 << 1, // Playback will be automatically started in this state when shouldAutoplay is YES
	PLVVodLoadStateStalled        = 1 << 2, // Playback will be automatically paused in this state, if started
};

/// 手势识别类型
typedef NS_ENUM(NSInteger, PLVVodGestureType) {
	//// 未知
	PLVVodGestureTypeUnknown,
	/// 点击
	PLVVodGestureTypeTap,
	/// 双击
	PLVVodGestureTypeDoubleTap,
	/// 左滑
	PLVVodGestureTypeLeftPan,
	/// 右滑
	PLVVodGestureTypeRightPan,
	/// 左侧上滑
	PLVVodGestureTypeLeftSideUpPan,
	/// 左侧下滑
	PLVVodGestureTypeLeftSideDownPan,
	/// 右侧上滑
	PLVVodGestureTypeRightSideUpPan,
	/// 右侧下滑
	PLVVodGestureTypeRightSideDownPan
};

@class PLVMarquee;

/// 主视频播放器
@interface PLVVodPlayerViewController : UIViewController

/// 覆盖图层
@property (nonatomic, strong) UIView *maskView;

/// video 模型
@property (nonatomic, strong) PLVVodVideo *video;

/// 当前清晰度
@property (nonatomic, assign, readonly) PLVVodQuality quality;

/// 用户播放时间
@property (nonatomic, assign, readonly) NSTimeInterval viewerWatchDuration;

/// 用户停留时间
@property (nonatomic, assign, readonly) NSTimeInterval viewerStayDuration;

/// 其他 viewlog 参数，param1~param5 和 key1~key3 参数值需要 UrlSafeBase64 编码
@property (nonatomic, strong) NSDictionary<NSString *, id> *viewlogExtraParams;

/// 本地视频优先播放，默认为 YES
@property (nonatomic, assign) BOOL localPrior;

/// 是否为本地播放
@property (nonatomic, assign) BOOL localPlayback;

/// 是否允许后台播放
@property (nonatomic, assign) BOOL enableBackgroundPlayback;

/// 是否播放片头，默认 NO
@property (nonatomic, assign) BOOL enableTeaser;
/// 片头播放状态
@property (nonatomic, assign, readonly) PLVVodAssetState teaserState;

/// 是否开启广告，默认 NO
@property (nonatomic, assign) BOOL enableAd;
/// 广告播放器
@property (nonatomic, strong, readonly) PLVVodAdPlayerViewController *adPlayer;

/// 是否开启记忆播放位置，默认 NO
@property (nonatomic, assign) BOOL rememberLastPosition;

/// 拉伸模式
@property (nonatomic, assign) PLVVodMovieScalingMode scalingMode;

/// 路由线路，仅对加密视频有效，传入 POVVodVideo 对象中 availableRouteLines 数组的元素
@property (nonatomic, copy) NSString *routeLine;

/// 播放控制
@property (nonatomic, strong) IBOutlet id<PLVVodPlayerSkinProtocol> playerControl;

/// 识别手势类型
@property (nonatomic, assign, readonly) PLVVodGestureType gestureType;
/// 手势识别回调
@property (nonatomic, copy) void (^gestureCallback)(PLVVodPlayerViewController *player, UIGestureRecognizer *recognizer, PLVVodGestureType gestureType);
/// 手势识别时忽略的视图
@property (nonatomic, strong) NSArray *doNotReceiveGestureViews;

/// 跑马灯
@property (nonatomic, strong) PLVMarquee *marquee;

#pragma mark - 播放

/// 自动播放，默认 YES
@property (nonatomic, assign) BOOL autoplay;

/// 播放速度
@property (nonatomic, assign) double playbackRate;

/// 播放音量
@property (nonatomic, assign) double playbackVolume;

/// 开始播放时间
@property (nonatomic, assign) NSTimeInterval startPlaybackTime;

/// 当前播放时间
@property (nonatomic, assign) NSTimeInterval currentPlaybackTime;

/// 媒体时长
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/// 可播放时长
@property (nonatomic, assign, readonly) NSTimeInterval playableDuration;

/// 是否就绪播放
@property (nonatomic, assign, readonly) BOOL preparedToPlay;
/// 是否就绪播放回调
@property (nonatomic, copy) void (^preparedToPlayHandler)(PLVVodPlayerViewController *player);

/// 播放状态
@property (nonatomic, assign, readonly) PLVVodPlaybackState playbackState;
/// 播放状态回调
@property (nonatomic, copy) void (^playbackStateHandler)(PLVVodPlayerViewController *player);

/// 播放模式
@property (nonatomic, assign) PLVVodPlaybackMode playbackMode;
/// 播放模式回调
@property (nonatomic, copy) void (^playbackModeHandler)(PLVVodPlayerViewController *player);
// 更新播放模式更新成功回调
- (void)playbackModeDidChange;
- (void)updateAudioCoverAnimation:(BOOL)isPlaying;

/// 加载状态
@property (nonatomic, assign, readonly) PLVVodLoadState loadState;
/// 加载状态回调
@property (nonatomic, copy) void (^loadStateHandler)(PLVVodPlayerViewController *player);

/// 是否播放结束
@property (nonatomic, assign, readonly) BOOL reachEnd;
/// 播放结束回调
@property (nonatomic, copy) void (^reachEndHandler)(PLVVodPlayerViewController *player);

/// 是否正在载入回调
@property (nonatomic, copy) void (^loadingHandler)(BOOL isLoading);

/// 当前是否全屏
@property (nonatomic, assign, readonly) BOOL fullscreen;

/// 播放器错误回调
@property (nonatomic, copy) void (^playerErrorHandler)(PLVVodPlayerViewController *player, NSError *error);
/**
 指定/切换 PLVVodVideo 对象，及其清晰度

 @param video PLVVodVideo 对象
 @param quality 清晰度
 */
- (void)setVideo:(PLVVodVideo *)video quality:(PLVVodQuality)quality;

/**
 切换码率，若码率不符合则自动切换到附近的清晰度

 @param quality 清晰度
 */
- (void)switchQuality:(PLVVodQuality)quality;

/// 播放
- (void)play;

/// 暂停
- (void)pause;

/// 当前时刻的截图
- (UIImage *)snapshot;

/// 旋转设备到指定方向
+ (void)rotateOrientation:(UIInterfaceOrientation)orientation;

/// 播放时间显示字符串，子类中重写该方法，可实现自定义播放器时间显示
- (NSString *)timeDescription;

#pragma mark - IBAction

/// 播放或暂停 Action
- (IBAction)playPauseAction:(UIButton *)sender;

/// 播放进度滑杆 TouchDown Action
- (IBAction)playbackSliderTouchDownAction:(UISlider *)sender;

/// 播放进度滑杆 ValueChange Action
- (IBAction)playbackSliderValueChangeAction:(UISlider *)sender;

/// 播放进度滑杆 TouchUpCancel Action
- (IBAction)playbackSliderTouchUpCancelAction:(UISlider *)sender;

/// 亮度滑杆调节 Action
- (IBAction)brightnessAction:(UISlider *)sender;

/// 音量滑杆调节 Action
- (IBAction)volumeAction:(UISlider *)sender;

/**
 添加播放器到占位视图上

 `placeholderView` 为竖屏时的占位视图，该视图需要先布局，播放器会参照该视图的布局而进行竖屏的布局。
 
 @param placeholderView 竖屏状态时的占位视图
 @param rootViewController 播放器所在页面的 UIViewController 对象
 */
- (void)addPlayerOnPlaceholderView:(UIView *)placeholderView rootViewController:(UIViewController *)rootViewController;

@end
