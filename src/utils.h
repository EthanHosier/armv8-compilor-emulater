#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "consts.h"

int readBinaryFile(char *filename, uint32_t *output, int *instructionCount);

typedef struct {
    bool negative;
    bool zero;
    bool carry;
    bool overflow;
} PState;
typedef struct {
    uint64_t generalPurpose[GENERAL_PURPOSE_REGISTERS];
    uint64_t programCounter;
    PState pState;
    uint8_t primaryMemory[MEMORY_SIZE_BYTES];
} SystemState;

void initialiseSystemState(SystemState *state);

void getBits(uint32_t instruction, bool *bits);

void printInstructions(uint32_t instructions[], int numberOfInstructions);

void printInstruction(bool bits[]);

int invalidInstruction(void);

uint64_t ror64(uint64_t, int);

uint32_t ror32(uint32_t, int);

uint64_t asr64(uint64_t, int);

uint32_t asr32(uint32_t, int);

int getMemAddress(bool bits[]);

uint16_t getBitsSubset(const bool bits[], int msb, int lsb);

void updateBitsSubset(bool bits[], int newBits, int msb, int lsb);

#endif
