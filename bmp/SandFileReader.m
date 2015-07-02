//
//  SandFileReader.m
//  bmp
//
//  Created by Alexey Zabrodin on 30.06.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#import "SandFileReader.h"

@implementation SandFileReader
- (instancetype)initWithFileName:(NSString*) fileName;
{
    self = [super init];
    if (self) {
        _fileName = fileName;
        
        NSFileManager *fileManager = [NSFileManager defaultManager];
        NSString *documentsDirectory = [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject];
        NSString *actualfilePath = [documentsDirectory stringByAppendingPathComponent:fileName];
        if ([fileManager isReadableFileAtPath:actualfilePath]) {
            NSLog(@"readable");
            _data = [fileManager contentsAtPath:actualfilePath];
//            NSLog(@"%@",[[NSString alloc]initWithData:_data encoding:NSUTF8StringEncoding]);
        }
    }
    return self;
}

-(uint8_t *)data
{
    return (uint8_t *)_data.bytes;
}

-(int)dataSize
{
    return _data.length;
}

@end
