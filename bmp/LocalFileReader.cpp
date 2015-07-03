//
//  LocalFileReader.cpp
//  bmp
//
//  Created by Alexey Zabrodin on 30.06.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#include "LocalFileReader.h"

LocalFileReader::LocalFileReader(const char *filename, uint8_t* data, uint16_t dataSize) : FileReader(filename){
    
    _data = data;
    _dataSize = dataSize;
    
}

uint8_t LocalFileReader::read(){
    uint8_t byte = _data[_position];
    _position++;
    return byte;
};

uint8_t LocalFileReader::peek(){
    return _data[_position];
};

int LocalFileReader::available(){
    return _position < _dataSize;
};

bool LocalFileReader::seek(uint32_t pos){
    if (pos < _dataSize) {
        _position = pos;
        return 1;
    }
    return 0;
};

uint32_t LocalFileReader::position(){
    return _position;
};
