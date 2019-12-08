#ifndef SIMD_H
#define SIMD_H

#include "cpu/instruction.h"

// Opcode naming standard:
//  MG[d|q]: MMX register operand, encoded by the REG field
//  ME[d|q]: MMX register or memory operand, encoded by the R/M field
//  E[d|q]: GPR or memory operand, encoded by the R/M field
//  G[d|q]: GPR, encoded by the REG field
//  XG[d|q|o]: XMM register operand, encoded by the REG field
//  XE[d|q|o]: XMM register or memory operand, encoded by the R/M field
enum {
    // 0F 10
    MOVUPS_XGoXEo,
    MOVSS_XGdXEd,
    MOVSD_XGqXEq,

    // 0F 11
    MOVUPS_XEoXGo,
    MOVSS_XEdXGd,
    MOVSD_XEqXGq,
    
    // 0F 12
    MOVHLPS_XGqXEq,
    MOVLPS_XGqXEq,

    // 0F 13
    //MOVLPS_XEqXGq, // This appears to do exactly the same thing as MOVSD_XEqXGq
    
    // 0F 14
    UNPCKLPS_XGoXEq,
    UNPCKLPD_XGoXEo,
    
    // 0F 15
    UNPCKHPS_XGoXEq,
    UNPCKHPD_XGoXEo,

    // 0F 16
    MOVLHPS_XGqXEq,
    MOVHPS_XGqXEq,

    // 0F 17
    MOVHPS_XEqXGq
};

enum {
    MOVAPS_XGoXEo,
    MOVAPS_XEoXGo,
    CVTPI2PS_XGqMEq,
    CVTSI2SS_XGdEd,
    CVTPI2PD_XGoMEq,
    CVTSI2SD_XGqMEd,
    CVTPS2PI_MGqXEq,
    CVTSS2SI_GdXEd,
    CVTPD2PI_MGqXEo,
    CVTSD2SI_GdXEq,
    UCOMISS_XGdXEd,
    UCOMISD_XGqXEq
};

enum {
    // 0F 50
    MOVMSKPS_GdXEo,
    MOVMSKPD_GdXEo,

    // 0F 51
    SQRTPS_XGoXEo,
    SQRTSS_XGdXEd,
    SQRTPD_XGoXEo,
    SQRTSD_XGqXEq,
    
    // 0F 52
    RSQRTPS_XGoXEo,
    RSQRTSS_XGdXEd,

    // 0F 53
    RCPPS_XGoXEo,
    RCPSS_XGdXEd,

    // 0F 54
    ANDPS_XGoXEo,

    // 0F 55
    ANDNPS_XGoXEo,

    // 0F 56
    ORPS_XGoXEo,

    // 0F 57
    XORPS_XGoXEo
};

enum {
    // 0F 60
    PUNPCKLBW_MGqMEq,
    PUNPCKLBW_XGoXEo,
    // 0F 61
    PUNPCKLWD_MGqMEq,
    PUNPCKLWD_XGoXEo,
    // 0F 62
    PUNPCKLDQ_MGqMEq,
    PUNPCKLDQ_XGoXEo,
    // 0F 63
    PACKSSWB_MGqMEq,
    PACKSSWB_XGoXEo,
    // 0F 64
    PCMPGTB_MGqMEq,
    PCMPGTB_XGoXEo,
    // 0F 65
    PCMPGTW_MGqMEq,
    PCMPGTW_XGoXEo,
    // 0F 66
    PCMPGTD_MGqMEq,
    PCMPGTD_XGoXEo,
    // 0F 67
    PACKUSWB_MGqMEq,
    PACKUSWB_XGoXEo
};

enum {
    // 0F 68
    PUNPCKHBW_MGqMEq,
    PUNPCKHBW_XGoXEo,
    // 0F 69
    PUNPCKHWD_MGqMEq,
    PUNPCKHWD_XGoXEo,
    // 0F 6A
    PUNPCKHDQ_MGqMEq,
    PUNPCKHDQ_XGoXEo,
    // 0F 6B
    PACKSSDW_MGqMEq,
    PACKSSDW_XGoXEo,
    // 66 0F 6C
    PUNPCKLQDQ_XGoXEo,
    // 66 0F 6D
    PUNPCKHQDQ_XGoXEo,
    // 0F 6E
    MOVD_MGdEd,
    MOVD_XGdEd,
    // 0F 6F
    MOVQ_MGqMEq,
    MOVDQA_XGoXEo,
    MOVDQU_XGoXEo,

    // Bad opcodes
    OP_68_6F_INVALID
};

enum {
    // 0F 70
    PSHUFW_MGqMEqIb,
    PSHUFLW_XGoXEoIb,
    PSHUFHW_XGoXEoIb,
    PSHUFD_XGoXEoIb,
    // 0F 71 - 0F 73
    PSHIFT_MGqIb, // PS[L|R][A|L][W|D|Q]
    PSHIFT_XEoIb, // PS[L|R][A|L][W|D|Q]

    // 0F 74
    PCMPEQB_MGqMEq,
    PCMPEQB_XGoXEo,
    // 0F 75
    PCMPEQW_MGqMEq,
    PCMPEQW_XGoXEo,
    // 0F 76
    PCMPEQD_MGqMEq,
    PCMPEQD_XGoXEo
};

enum {
    PSHIFT_PSRLW,
    PSHIFT_PSRAW,
    PSHIFT_PSLLW,
    
    PSHIFT_PSRLD,
    PSHIFT_PSRAD,
    PSHIFT_PSLLD,

    PSHIFT_PSRLQ,
    PSHIFT_PSRLDQ,
    PSHIFT_PSLLQ,
    PSHIFT_PSLLDQ
};

enum {
    // 0F D1
    PSRLW_MGqMEq,
    PSRLW_XGoXEo,
    // 0F D2
    PSRLD_MGqMEq,
    PSRLD_XGoXEo,
    // 0F D3
    PSRLQ_MGqMEq,
    PSRLQ_XGoXEo,
    // 0F D4
    PADDQ_MGqMEq,
    PADDQ_XGoXEo,
    // 0F D5
    PMULLW_MGqMEq,
    PMULLW_XGoXEo,
    // 0F D6
    MOVQ_XEqXGq,
    MOVQ2DQ_XGoMEq,
    MOVDQ2Q_MGqXEo,
    // 0F D7
    PMOVMSKB_GdMEq,
    PMOVMSKB_GdXEo
};

enum {
    // 0F D8
    PSUBUSB_MGqMEq,
    PSUBUSB_XGoXEo,
    // 0F D9
    PSUBUSW_MGqMEq,
    PSUBUSW_XGoXEo,
    // 0F DA
    PMINUB_MGqMEq,
    PMINUB_XGoXEo,
    // 0F DB
    PAND_MGqMEq,
    PAND_XGoXEo,
    // 0F DC
    PADDUSB_MGqMEq,
    PADDUSB_XGoXEo,
    // 0F DD
    PADDUSW_MGqMEq,
    PADDUSW_XGoXEo,
    // 0F DA
    PMAXUB_MGqMEq,
    PMAXUB_XGoXEo,
    // 0F DB
    PANDN_MGqMEq,
    PANDN_XGoXEo
};

enum {
    // 0F E8
    PSUBSB_MGqMEq,
    PSUBSB_XGoXEo,
    // 0F E9
    PSUBSW_MGqMEq,
    PSUBSW_XGoXEo,
    // 0F EA
    PMINSW_MGqMEq,
    PMINSW_XGoXEo,
    // 0F EB
    POR_MGqMEq,
    POR_XGoXEo,
    // 0F EC
    PADDSB_MGqMEq,
    PADDSB_XGoXEo,
    // 0F ED
    PADDSW_MGqMEq,
    PADDSW_XGoXEo,
    // 0F EE
    PMAXSW_MGqMEq,
    PMAXSW_XGoXEo,
    // 0F EF
    PXOR_MGqMEq,
    PXOR_XGoXEo
};

int cpu_sse_exception(void);

int cpu_emms(void);
int execute_0F10_17(struct decoded_instruction* i);
int execute_0F28_2F(struct decoded_instruction* i);
int execute_0F50_57(struct decoded_instruction* i);
int execute_0F60_67(struct decoded_instruction* i);
int execute_0F68_6F(struct decoded_instruction* i);
int execute_0F70_76(struct decoded_instruction* i);
int execute_0FD0_D7(struct decoded_instruction* i);
int execute_0FE8_EF(struct decoded_instruction* i);

#endif