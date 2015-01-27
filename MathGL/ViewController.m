//
//  ViewController.m
//  MathGL
//
//  Created by administrator on 15/1/26.
//  Copyright (c) 2015年 zhangmin. All rights reserved.
//

#import "ViewController.h"
#import "mgl_test.h"
#include "mgl_bigmap.h"
#import "ImageHelper.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        struct mgl_bigmap *bitmap=alloca(sizeof(struct mgl_bigmap));
        test(bitmap);
        //NSData *data=[NSData dataWithBytes:imageData length:strlen(imageData)];
        UIImage*image=[ImageHelper convertBitmapRGBA8ToUIImage:bitmap->data withWidth:bitmap->width withHeight:bitmap->height];
//        UIImage*image=[[UIImage alloc]initWithContentsOfFile:fileName];
        dispatch_async(dispatch_get_main_queue(), ^{
            UIImageView *imageView=[[UIImageView alloc]initWithFrame:CGRectMake(0, 100, self.view.frame.size.width, 400)];
            imageView.image=image;
            [self.view addSubview:imageView];
        });
    });
    
    
    
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
