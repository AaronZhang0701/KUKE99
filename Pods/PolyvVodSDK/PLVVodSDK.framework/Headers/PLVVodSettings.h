//
//  PLVVodSettings.h
//  PolyvVodSDK
//
//  Created by BqLin on 2017/10/9.
//  Copyright © 2017年 POLYV. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PLVVodConstans.h"

/// SDK 版本
extern NSString * const PLVVodSdkVersion;

@interface PLVVodSettings : NSObject

/// userid
@property (nonatomic, copy, readonly) NSString *userid;

/// readtoken
@property (nonatomic, copy, readonly) NSString *readtoken;

/// writetoken
@property (nonatomic, copy, readonly) NSString *writetoken;

/// secretkey
@property (nonatomic, copy, readonly) NSString *secretkey;

/// 终端用户id
@property (nonatomic, copy) NSString *viewerId;

/// 终端用户昵称
@property (nonatomic, copy) NSString *viewerName;

/// 终端用户播放令牌额外参数
@property (nonatomic, copy) NSString *viewerTokenExtraParam;

/// 是否启用多账户，默认 NO。开启后可播放、下载除了配置的账号以外的其他账号的非加密视频。
@property (nonatomic, assign, getter=isMutilAccount) BOOL mutilAccount;

/// 日志输出等级，默认 PLVVodLogLevelWithoutDebug
@property (nonatomic, assign) PLVVodLogLevel logLevel;

/// 是否启动 HTTPDNS，默认 NO。使用该功能，需开启允许 http 请求。
@property (nonatomic, assign) BOOL enableHttpDNS;

/// 错误回调
@property (nonatomic, copy) void (^settingErrorHandler)(NSError *error);

/**
 获取 PLVVodSettings 静态对象

 @return PLVVodSettings 静态对象
 */
+ (instancetype)sharedSettings;

/**
 通过 userid、readtoken、writetoken、secretkey 配置账号

 @param userid userid
 @param readtoken readtoken
 @param writetoken writetoken
 @param secretkey secretkey
 @return 新的 PLVVodSettings 静态对象
 */
+ (instancetype)settingsWithUserid:(NSString *)userid readtoken:(NSString *)readtoken writetoken:(NSString *)writetoken secretkey:(NSString *)secretkey;

/**
 使用加密串配置账号

 @param configString 加密串
 @param error 解密、配置过程的错误
 @return 新的 PLVVodSettings 静态对象
 */
+ (instancetype)settingsWithConfigString:(NSString *)configString error:(NSError **)error ;
/**
 使用加密串、加密秘钥、加密向量配置账号

 @param configString 加密串
 @param key 加密秘钥
 @param iv 加密向量
 @param error 解密、配置过程的错误
 @return 新的 PLVVodSettings 静态对象
 */
+ (instancetype)settingsWithConfigString:(NSString *)configString key:(NSString *)key iv:(NSString *)iv error:(NSError **)error;

@end
