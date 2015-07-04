//
//  ViewController.m
//  bmp
//
//  Created by Alexey Zabrodin on 30.06.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#import "MainViewController.h"
#import "SandFileReader.h"
#include "LocalFileReader.h"
#include "BmpReader.h"
#include "FileReader.h"

@interface MainViewController ()

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"Main";
    self.view.backgroundColor = [UIColor yellowColor];
    
    NSString* fileName = @"4pixel2.bmp";
    SandFileReader* sandFileReader = [[SandFileReader alloc]initWithFileName:fileName];
    LocalFileReader* localFileReader = new LocalFileReader(fileName.fileSystemRepresentation, sandFileReader.data, sandFileReader.dataSize);
    BmpReader* bmpReader = new BmpReader(localFileReader);
    NSLog(@"with: %llu, height: %llu",bmpReader->width(), bmpReader->height());
    NSLog(@"%0xb, %0xd, %0xd, %0xd", bmpReader->pixel565(0, 0), bmpReader->pixel565(1, 0), bmpReader->pixel565(0, 1), bmpReader->pixel565(1, 1));

//  0x001f - Blue
//  0x07e0 - Green
//  0xf800 - Red
}

@end
