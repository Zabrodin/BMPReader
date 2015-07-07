//
//  BmpReader.cpp
//  bmp
//
//  Created by Alexey Zabrodin on 30.06.15.
//  Copyright (c) 2015 Alexey Zabodin. All rights reserved.
//

#include "BmpReader.h"


BmpReader::BmpReader(FileReader* fileReader){
    _fileReader = fileReader;
    
    uint8_t* ptrBitMapFileHeader = (uint8_t*)&_bitMapFileHeader;
    int bitMapHeaderSize = sizeof(BitMapFileHeader);
    _fileReader->seek(0);
    for (int currentByte = 0; currentByte < bitMapHeaderSize; currentByte++) {
        ptrBitMapFileHeader[currentByte] = _fileReader->read();
    }
    
    uint8_t* ptrBitMapInfoFileHeader = (uint8_t*)&_bitMapInfoHeader;
    int bitMapInfoFileHeaderSize = sizeof(BitMapInfoHeader);
//    _fileReader->seek(bitMapHeaderSize);
    for (int currentByte = 0; currentByte < bitMapInfoFileHeaderSize; currentByte++) {
        ptrBitMapInfoFileHeader[currentByte] = _fileReader->read();
    }

    
}


uint32_t BmpReader::height (void){
    return _bitMapInfoHeader.biHeight;
}

uint32_t BmpReader::width  (void){
    return _bitMapInfoHeader.biWidth;
}

uint16_t BmpReader::pixel565 (int xPosition, int yPosition){
    uint16_t pixel;
    uint8_t* byte = (uint8_t*) &pixel;
    if (_fileReader->seek(_bitMapFileHeader.bfOffBits + _bitMapInfoHeader.biWidth * (height() - 1 - yPosition) * sizeof(pixel) + xPosition * sizeof(pixel))) {
        byte[0] = _fileReader->read();
        byte[1] = _fileReader->read();
    }
    
    return pixel;
}
