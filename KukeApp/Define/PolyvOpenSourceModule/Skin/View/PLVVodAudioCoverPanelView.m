//
//  PLVVodAudioCoverPanelView.m
//  PolyvVodSDKDemo
//
//  Created by 李长杰 on 2018/5/28.
//  Copyright © 2018年 POLYV. All rights reserved.
//

#import "PLVVodAudioCoverPanelView.h"
#import <YYKit/YYKit.h>

@interface PLVVodAudioCoverPanelView ()

@property (weak, nonatomic) IBOutlet UIView *audioCoverContainerView;
@property (weak, nonatomic) IBOutlet UIImageView *audioCoverContainerBackgroundImageView;

@property (weak, nonatomic) IBOutlet UIImageView *audioCoverImage;

@end

@implementation PLVVodAudioCoverPanelView

- (void)awakeFromNib {
    [super awakeFromNib];
    
    self.audioCoverImage.layer.cornerRadius = 60;
    self.audioCoverImage.layer.masksToBounds = YES;
}

- (void)setCoverUrl:(NSString *)url {
    
    [self.audioCoverContainerBackgroundImageView setImageWithURL:[NSURL URLWithString:url] placeholder:nil];
//    [self.audioCoverContainerBackgroundImageView yy_setImageWithURL:[NSURL URLWithString:url] placeholder:nil];
    [self.audioCoverImage setImageWithURL:[NSURL URLWithString:url] placeholder:nil];
}

- (void)switchToPlayMode:(PLVVodPlaybackMode)mode {
    if (mode == PLVVodPlaybackModeAudio) {
        self.audioCoverContainerView.hidden = NO;
    } else {
        self.audioCoverContainerView.hidden = YES;
    }
}

- (void)startRotate {
    if ([self.audioCoverImage.layer.animationKeys count] == 0) {
        CABasicAnimation *animation = [CABasicAnimation animationWithKeyPath:@"transform.rotation.z"];
        animation.beginTime = CACurrentMediaTime();
        animation.duration = 15;
        animation.repeatCount = UIViewAnimationOptionRepeat;
        animation.fromValue = @(0.0);
        animation.toValue = @(2 * M_PI);
        [self.audioCoverImage.layer addAnimation:animation forKey:@"rotate"];
    }
}

- (void)stopRotate {
    if ([self.audioCoverImage.layer.animationKeys count] != 0) {
        [self.audioCoverImage.layer removeAllAnimations];
    }
}

@end
