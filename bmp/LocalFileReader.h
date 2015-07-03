//
//  LocalFileReader.h
//  bmp
//
//  Created by Alexey Zabrodin on 30.06.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#ifndef __bmp__LocalFileReader__
#define __bmp__LocalFileReader__

#include <stdio.h>
#include "FileReader.h"

class LocalFileReader : public  FileReader{
private:
    uint8_t* _data;
    uint32_t _dataSize;
    uint32_t _position;
public:
    LocalFileReader(const char *filename, uint8_t* data, uint16_t dataSize);
    uint8_t read();
    uint8_t peek();
    int available();
    bool seek(uint32_t pos);
    uint32_t position();

};

#endif /* defined(__bmp__LocalFileReader__) */
