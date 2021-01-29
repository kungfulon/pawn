#include <iostream>
#include <fstream>

constexpr uint16_t CELL_SIZE_32 = 0xF1E0;
constexpr uint16_t CELL_SIZE_64 = 0xF1E1;
constexpr uint16_t CELL_SIZE_16 = 0xF1E2;

constexpr uint16_t AMX_FLAG_OVERLAY = (1 << 0);
constexpr uint16_t AMX_FLAG_DEBUG = (1 << 1);
constexpr uint16_t AMX_FLAG_NOCHECKS = (1 << 2);
constexpr uint16_t AMX_FLAG_SLEEP = (1 << 3);
constexpr uint16_t AMX_FLAG_DSEG_INIT = (1 << 5);

struct amx_header {
    uint32_t size;
    uint16_t magic;
    uint8_t file_version;
    uint8_t amx_version;
    uint16_t flags;
    uint16_t defsize;
    uint32_t cod;
    uint32_t dat;
    uint32_t hea;
    uint32_t stp;
    uint32_t cip;
    uint32_t publics;
    uint32_t natives;
    uint32_t libraries;
    uint32_t pubvars;
    uint32_t tags;
    uint32_t nametable;
    uint32_t overlays;
};

struct amx_table {
    uint32_t address;
    uint32_t nameofs;
};

const char *amx_instructions_names[] = {
    "NOP",
    "LOAD.pri",
    "LOAD.alt",
    "LOAD.S.pri",
    "LOAD.S.alt",
    "LREF.S.pri",
    "LREF.S/alt",
    "LOAD.I",
    "LODB.I",
    "CONST.pri",
    "CONST.alt",
    "ADDR.pri",
    "ADDR.alt",
    "STOR",
    "STOR.S",
    "SREF.S",
    "STOR.I",
    "STRB.I",
    "ALIGN.pri",
    "LCTRL",
    "SCTRL",
    "XCHG",
    "PUSH.pri",
    "PUSH.alt",
    "PUSHR.pri",
    "POP.pri",
    "POP.alt",
    "PICK",
    "STACK",
    "HEAP",
    "PROC",
    "RET",
    "RETN",
    "CALL",
    "JUMP",
    "JZER",
    "JNZ",
    "SHL",
    "SHR",
    "SSHR",
    "SHL.C.pri",
    "SHL.C.alt",
    "SMUL",
    "SDIV",
    "ADD",
    "SUB",
    "AND",
    "OR",
    "XOR",
    "NOT",
    "NEG",
    "INVERT",
    "EQ",
    "NEQ",
    "SLESS",
    "SLEQ",
    "SGRTR",
    "SGEQ",
    "INC.pri",
    "INC.alt",
    "INC.I",
    "DEC.pri",
    "DEC.alt",
    "DEC.I",
    "MOVS",
    "CMPS",
    "FILL",
    "HALT",
    "BOUNDS",
    "SYSREQ",
    "SWITCH",
    "SWAP.pri",
    "SWAP.alt",
    "BREAK",
    "CASETBL"
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file>\n";
        return 1;
    }

    std::ifstream f(argv[1], std::ios::binary);
    if (!f) {
        std::cerr << "Unable to open " << argv[1] << "\n";
        return 1;
    }

    amx_header header;
    f.read((char *)&header, sizeof(amx_header));
}
