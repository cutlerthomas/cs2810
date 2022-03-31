#include <stdint.h>
#include "decode.h"

// you should implement all of the functions prototyped in decode.h
// note: we will go over these in detail in class
// be sure to take good notes!

int8_t get_funct3(int32_t inst) {
    return(inst >> 12) & 0x07;
}

int8_t get_rd(int32_t inst) {
    return(inst >> 7) & 0x1f;
}

int8_t get_rs1(int32_t inst) {
    return(inst >> 15) & 0x1f;
}

int32_t get_imm_i(int32_t inst) {
    return(inst >> 20);
}

int32_t get_imm_u(int32_t inst) {
    return(inst & 0xfffff000);
}

int8_t get_funct7(int32_t inst) {
    return(inst >> 25);
}

int8_t get_rs2(int32_t inst) {
    return(inst >> 20) & 0x1f;
}

int32_t get_imm_b(int32_t inst) {
    int32_t imm = ((inst >> 20) & 0xfffff000);
    imm = imm | ((inst << 4) & 0x800);
    imm = imm | ((inst >> 20) & 0x7e0);
    imm = imm | ((inst >> 7) & 0x1e);
    return imm;
}

int32_t get_imm_j(int32_t inst) {
    int32_t imm = ((inst >> 12) & 0xfff00000);
    imm = imm | (inst & 0xff000);
    imm = imm | ((inst >> 9) & 0x800);
    imm = imm | ((inst >> 20) & 0x7f0);
    imm = imm | ((inst >> 20) & 0xe);
    return imm;
}

int32_t get_imm_s(int32_t inst) {
    int32_t imm = ((inst >> 20) & 0xfe0);
    imm = imm | ((inst >> 7) & 0x1f);
    return imm;
}
