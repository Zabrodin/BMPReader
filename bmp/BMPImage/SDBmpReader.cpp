//
//  SDBmpReader.cpp
//  bmp
//
//  Created by lex on 05.07.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#include "SDBmpReader.h"

SDBmpReader::SDBmpReader(const char *filename, File* file) : FileReader(filename){
    
    _file = file;
}

uint8_t SDBmpReader::read(){
    uint8_t byteData = _file->read();
    return byteData;
};

uint8_t SDBmpReader::peek(){
    uint8_t byteData = _file->peek();
    return byteData;
};

int SDBmpReader::available(){
    return _file->available();
};

bool SDBmpReader::seek(uint32_t pos){
    return _file->seek(pos);
};

uint32_t SDBmpReader::position(){
    return _file->position();
};
