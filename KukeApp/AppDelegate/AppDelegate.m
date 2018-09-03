//
//  AppDelegate.m
//  KukeApp
//
//  Created by iOSDeveloper on 2018/8/9.
//  Copyright © 2018年 zhangming. All rights reserved.
//

#import "AppDelegate.h"
#import "AppDelegate+UMShare.h"
#import "ViewController.h"
#import "AppDelegate+Jpush.h"

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //注意在里面  先初始化应用窗口 再初始化友盟  最后设置根控制器
    [self initWindow];
    //初始化友盟分享
    [self setupUSharePlatforms];
    //初始化极光
    [self setupWithJpushOption:launchOptions];
    //初始化保利威
    [self initPLVVod];
    //初始化app服务
    [self initService];
    //初始化用户系统
    [self initUserManager];
    //广告页
    [AppManager appStart];
//    NSString *zm = @"234";
//    NSLog(@"%@",[zm zm_md5String]);


//    NSString *videoId = @"12343768";
//    NSMutableDictionary *parmDic = [NSMutableDictionary dictionary];
//    [parmDic setObject:@"70969736" forKey:@"partner_id"];
//    [parmDic setObject:[NSNumber numberWithInt:[videoId intValue]] forKey:@"video_id"];
//    [parmDic setObject:[NSNumber numberWithInt:0] forKey:@"expires_in"];
//    [parmDic setObject:[NSNumber numberWithInt:1534155197] forKey:@"timestamp"];
//    [parmDic setObject:@"5d856dbe803ecce68f6340bd0a683c8d" forKey:@"sign"];
//
//    NSString *s = @"partner_id=70969736&video_id=12357595&expires_in=0&timestamp=1534155197&partner_key=2GVjCLyDA/Gfyppm8KvcqmH3NQPceaWvfKQj7zTjh9C7SwIO+uqRK5gJois2QLW7z9cn/W+IXNyFN1R75pf6NdvEyJqIqMWDdSMdbptWW1vzwMF4pXMK5NFtJKXw2syg";
//
//    NSLog(@"%@",[s md5]);
////    NSDictionary *dict = @{@"partner_id":@"70969736", @"video_id":@"12343768", @"expires_in":@"0", @"timestamp":@"1534155197", @"sign":@"5d856dbe803ecce68f6340bd0a683c8d"};
//
//
//    [ZMNetworkHelper POST:@"/openapi/video/getPlayerToken" parameters:parmDic cache:true responseCache:^(id responseCache) {
//        NSLog(@"%@",responseCache);
//
//    } success:^(id responseObject) {
//        NSLog(@"%@",responseObject);
//    } failure:^(NSError *error) {
//        NSLog(@"%@",error);
//    }];
//
//
//
//
//
//
//
//        NSURL *url = [NSURL URLWithString:@"http://api.baijiayun.com/openapi/video/getPlayerToken"];
//        NSData *postData = [[NSString stringWithFormat:@"partner_id=70969736&sign=5d856dbe803ecce68f6340bd0a683c8d&video_id=12343768&expires_in=0&timestamp=1534155197"] dataUsingEncoding:NSUTF8StringEncoding];
//        NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
//        //设置请求方式
//        request.HTTPMethod = @"POST";
//        //设置请求参数
//        request.HTTPBody = postData;
//
//        [NSURLConnection sendAsynchronousRequest:request queue:[NSOperationQueue mainQueue] completionHandler:^(NSURLResponse * _Nullable response, NSData * _Nullable data, NSError * _Nullable connectionError) {
//            NSLog(@"123456");
//        }];
//
//        NSLog(@"123456");

    
   
    
    
    // Override point for customization after application launch.
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
