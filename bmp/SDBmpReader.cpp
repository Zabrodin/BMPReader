//
//  SDBmpReader.cpp
//  bmp
//
//  Created by lex on 05.07.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#include "SDBmpReader.h"

SDBmpReader::SDBmpReader(const char *filename, FILE* file) : FileReader(filename){
    
    _file = file;
}

uint8_t SDBmpReader::read(){
//    uint8_t byte = _file.read();
    return 0;
};

uint8_t SDBmpReader::peek(){
    return _data[_position];
};

int SDBmpReader::available(){
    return _position < _dataSize;
};

bool SDBmpReader::seek(uint32_t pos){
    if (pos < _dataSize) {
        _position = pos;
        return 1;
    }
    return 0;
};

uint32_t SDBmpReader::position(){
    return _position;
};
