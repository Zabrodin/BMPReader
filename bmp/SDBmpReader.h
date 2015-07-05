//
//  SDBmpReader.h
//  bmp
//
//  Created by lex on 05.07.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#ifndef __bmp__SDBmpReader__
#define __bmp__SDBmpReader__

#include <stdio.h>
#include "FileReader.h"

class SDBmpReader : public  FileReader{
private:
    uint8_t* _data;
    uint32_t _dataSize;
    uint32_t _position;
    FILE*   _file;
public:
    SDBmpReader(const char *filename, FILE* file);
    uint8_t read();
    uint8_t peek();
    int available();
    bool seek(uint32_t pos);
    uint32_t position();
};

#endif /* defined(__bmp__SDBmpReader__) */
