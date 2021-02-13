#ifndef meon_chunk_h
#define meon_chunk_h

#include "common.h"
#include "value.h"

typedef enum
{
    OP_CONSTANT,
    OP_RETURN
} OpCode;

typedef struct
{
    int offset;
    int line;
} LineStart;

typedef struct
{
    int size;
    int maxSize;
    uint8_t *code;
    ValueArr constants;

    int lineSize;
    int lineMaxSize;
    LineStart *lines;
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t b, int line);
void freeChunk(Chunk *chunk);

int addConstant(Chunk *chunk, Value value);
int getLine(Chunk *chunk, int instruction);

#endif