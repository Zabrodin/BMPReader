//
//  SandFileReader.h
//  bmp
//
//  Created by Alexey Zabrodin on 30.06.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SandFileReader : NSObject
{
    NSString*   _fileName;
    NSData*     _data;
    uint32_t    _size;
}
@property(readonly)NSString*    fileName;
@property(readonly)uint8_t*     data;
@property(readonly)NSUInteger   dataSize;
-(instancetype)initWithFileName:(NSString*) fileName;
@end
