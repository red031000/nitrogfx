// SPDX-License-Identifier: GPL-3.0-or-later AND MIT
/* Copyright (C) 2018 huderlem, 2021-2026 red031000
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdint.h>
#include <stdbool.h>

struct GbaToPngOptions {
    char *paletteFilePath;
    int bitDepth;
    bool hasTransparency;
    int width;
    int colsPerChunk;
    int rowsPerChunk;
    int palIndex;
};

struct PngToGbaOptions {
    int numTiles;
    int bitDepth;
    int colsPerChunk;
    int rowsPerChunk;
    char *embedName;
};

struct PngToNtrOptions {
    char *cellFilePath;
    bool cellSnap;
    int numTiles;
    int tilesWide;
    int bitDepth;
    int colsPerChunk;
    int rowsPerChunk;
    bool clobberSize;
    bool byteOrder;
    bool version101;
    bool sopc;
    bool scan;
    bool wrongSize;
    bool handleEmpty;
    bool vramTransfer;
    int mappingType;
    uint32_t encodeMode;
    bool convertTo4Bpp;
    int rotate;
    bool noSkip;
};

struct NtrToPngOptions {
    char *paletteFilePath;
    char *cellFilePath;
    bool cellSnap;
    bool noSkip;
    int bitDepth;
    bool hasTransparency;
    int width;
    int colsPerChunk;
    int rowsPerChunk;
    int palIndex;
    bool handleEmpty;
    uint32_t encodeMode;
    bool convertTo8Bpp;
    bool verbose;
};

struct CellVramTransferData {
    int sourceDataOffset;
    int size;
};

struct Attr0 {
    int YCoordinate;
    bool Rotation;
    bool SizeDisable;
    int Mode;
    bool Mosaic;
    int Colours;
    int Shape;
};

struct Attr1 {
    int XCoordinate;
    int RotationScaling;
    int Size;
};

struct Attr2 {
    int CharName;
    int Priority;
    int Palette;
};

struct OAM {
    struct Attr0 attr0;
    struct Attr1 attr1;
    struct Attr2 attr2;
};

struct CellAttributes {
    bool hFlip; // 1 << 8
    bool vFlip; // 1 << 9
    bool hvFlip; // 1 << 10
    bool boundingRect; // 1 << 11
    int boundingSphereRadius; // 1 << 0 (6 bits);
};

struct Cell {
    struct CellAttributes attributes;
    short maxX;
    short maxY;
    short minX;
    short minY;
    short oamCount;
    struct OAM *oam;
};

struct JsonToCellOptions {
    bool labelEnabled;
    bool dontPadKbec;
    bool extended;
    bool vramTransferEnabled;
    bool ucatEnabled;
    int mappingType;
    int cellCount;
    struct Cell **cells;
    int vramTransferMaxSize;
    struct CellVramTransferData **transferData;
    char **labels;
    int labelCount;
    int *ucatCellAttributes;
};

struct JsonToScreenOptions {
    int height;
    int width;
    unsigned short *data;
    int bitdepth;
};

struct FrameData {
    int resultId;
    short frameDelay;
    int resultOffset;
};

struct SequenceData {
    short frameCount;
    short loopStartFrame;
    short animationElement;
    short animationType;
    int playbackMode;
    struct FrameData **frameData;
};

struct AnimationDataSRT {
    short index;
    unsigned short rotation;
    int scaleX;
    int scaleY;
    short positionX;
    short positionY;
};

struct AnimationDataT {
    short index;
    //unsigned short rotation;
    short positionX;
    short positionY;
};

struct AnimationResults {
    short resultType;
    bool padded;
    union {
        short index;
        struct AnimationDataSRT dataSrt;
        struct AnimationDataT dataT;
    };
};

struct UaatData {
    int *sequenceAttributes;
    int *frameAttributes;
};

struct JsonToAnimationOptions {
    bool multiCell;
    short sequenceCount;
    short frameCount;
    struct SequenceData **sequenceData;
    struct AnimationResults **animationResults;
    bool labelEnabled;
    char **labels;
    int labelCount;
    short resultCount;
    bool uaatEnabled;
    struct UaatData uaatData;
};

struct NtrFontOptions {
    char *metadataFilePath;
    bool useSubscreenPalette;
};

struct NtrFontMetadata {
    uint32_t size;
    uint32_t widthTableOffset;
    uint32_t numGlyphs;
    uint8_t maxWidth;
    uint8_t maxHeight;
    uint8_t glyphWidth;
    uint8_t glyphHeight;

    uint8_t *glyphWidthTable;
};

#endif // OPTIONS_H
