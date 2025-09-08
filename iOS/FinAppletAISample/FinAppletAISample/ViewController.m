//
//  ViewController.m
//  FinAppletAISample
//
//  Created by chenfanfang on 2025/9/8.
//

#import "ViewController.h"
#import <FinApplet/FinApplet.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (IBAction)openOfficialDemo:(id)sender {
    FATAppletRequest *request = [[FATAppletRequest alloc] init];
    request.appletId = @"5f72e3559a6a7900019b5baa";//官方示例小程序
    [[FATClient sharedClient] startAppletWithRequest:request InParentViewController:self completion:^(BOOL result, FATError *error) {
        if (result) {
            NSLog(@"打开小程序成功");
        } else {
            NSLog(@"打开小程序失败:%@", error);
        }
    } closeCompletion:^{
        NSLog(@"关闭小程序完成");
    }];
}

@end
