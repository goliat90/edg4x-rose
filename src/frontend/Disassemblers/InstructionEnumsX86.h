/* Enum constants for Intel x86 architectures */

#ifndef ROSE_ENUMS_X86
#define ROSE_ENUMS_X86

#include "AssemblerX86Init.h"   /* A big enum whose members are all possible x86 instructions. */

/** Intel x86 instruction size constants. */
enum X86InstructionSize 
{
  x86_insnsize_none,
  x86_insnsize_16,              /**< Instruction is for a 16-bit architecture. */
  x86_insnsize_32,              /**< Instruction is for a 32-bit architecture. */
  x86_insnsize_64               /**< Instruction is for a 64-bit architecture. */
};

/** Intel x86 major register numbers */
enum X86RegisterClass 
{
  x86_regclass_gpr,             /**< Minors are X86GeneralPurposeRegister (ax,cx,dx,bx,sp,bp,si,di,r8..r15) */
  x86_regclass_segment,         /**< Minors are X86SegmentRegister (es,cs,ss,ds,fs,gs) */
  x86_regclass_cr,              /**< Control registers; Minors are 0-4, 8 */
  x86_regclass_dr,              /**< Debug registers; Minors are 0-7 */
  x86_regclass_st,              /**< Floating point stack or MM registers; Minors are 0-7 */
  x86_regclass_xmm,             /**< 128-bit xmmN; Minors are 0-7. */
  x86_regclass_ip,              /**< Instruction pointer; Only allowed minor is zero. */
  x86_regclass_flags            /**< Status flags. */
};

/** Intel x86 segment registers. */
enum X86SegmentRegister 
{
    x86_segreg_es       = 0,    // Numbering is based on Intel documentation
    x86_segreg_cs       = 1,
    x86_segreg_ss       = 2,
    x86_segreg_ds       = 3,
    x86_segreg_fs       = 4,
    x86_segreg_gs       = 5,
    x86_segreg_none = 16 /* For unspecified segment overrides */
};

/** Intel x86 general purpose registers */
enum X86GeneralPurposeRegister 
{
    x86_gpr_ax          = 0,    // Numbering is based on Intel documentation
    x86_gpr_cx          = 1,
    x86_gpr_dx          = 2,
    x86_gpr_bx          = 3,
    x86_gpr_sp          = 4,
    x86_gpr_bp          = 5,
    x86_gpr_si          = 6,
    x86_gpr_di          = 7,
    x86_gpr_r8          = 8,
    x86_gpr_r9          = 9,
    x86_gpr_r10         = 10,
    x86_gpr_r11         = 11,
    x86_gpr_r12         = 12,
    x86_gpr_r13         = 13,
    x86_gpr_r14         = 14,
    x86_gpr_r15         = 15,
};

/** Intel x86 ST-related registers.  These are the 8 80-bit floating point registers. */
enum X86StRegister {
    x86_st_0            = 0,
    x86_st_1            = 1,
    x86_st_2            = 2,
    x86_st_3            = 3,
    x86_st_4            = 4,
    x86_st_5            = 5,
    x86_st_6            = 6,
    x86_st_7            = 7,
    x86_st_nregs        = 8,                            // number of ST registers
};

/** Minor numbers for x86_regclass_flag. */
enum X86Flags {
    x86_flags_status     = 0,                           // general-purpose status flags
    x86_flags_fpstatus   = 1,                           // floating-point status flags
    x86_flags_fptag      = 2,                           // floating-point tag register
    x86_flags_fpctl      = 3,                           // floating-point control register
    x86_flags_mxcsr      = 4,                           // SSE control and status register
};

/** Intel x86 status flags. These are the bit offsets in the x86_flags_status register. */
enum X86Flag 
{
    x86_flag_cf         = 0,
    x86_flag_pf         = 2,
    x86_flag_af         = 4,
    x86_flag_zf         = 6,
    x86_flag_sf         = 7,
    x86_flag_tf         = 8,
    x86_flag_if         = 9,
    x86_flag_df         = 10,
    x86_flag_of         = 11,
    x86_flag_iopl       = 12,   /* 2 bits, 12 and 13 */
    x86_flag_nt         = 14,
    x86_flag_rf         = 16,
    x86_flag_vm         = 17,
    x86_flag_ac         = 18,
    x86_flag_vif        = 19,
    x86_flag_vip        = 20,
    x86_flag_id         = 21
};

/** Intel x86 branch prediction types. */
enum X86BranchPrediction 
{
    x86_branch_prediction_none,
    x86_branch_prediction_taken,
    x86_branch_prediction_not_taken
};

/** Intel x86 instruction repeat prefix. */
enum X86RepeatPrefix 
{
    x86_repeat_none,            /**< No repeat prefix */
    x86_repeat_repne,           /**< Repeat not equal prefix 0xf2 */
    x86_repeat_repe             /**< Repeat equal prefix 0xf3 */
};

#if 0
/** DEPRECATED.  This enum was once used to hold the same information that's now held by the offset and nbits data members of
 *  the RegisterDescriptor struct, except it was able to describe only predetermined parts of the physical register.  Do not
 *  use this enum. Instead, use RegisterDescriptor or pass an actual offset and size.  Deprecated 2010-10-11. */
enum X86PositionInRegister {
    x86_regpos_unknown,         /**< DEPRECATED unknown (error or unitialized value) */
    x86_regpos_low_byte,        /**< DEPRECATED 1st byte of register (bits 0-7), only for GPRs */
    x86_regpos_high_byte,       /**< DEPRECATED 2nd byte of register (bits 8-15), only for ax,bx,cx,dx */
    x86_regpos_word,            /**< DEPRECATED 16 bit part of register, only for GPRs, CR0, CR8? */
    x86_regpos_dword,           /**< DEPRECATED lower 32 bit part of register, only for GPRs */
    x86_regpos_qword,           /**< DEPRECATED lower 64 bit part of register, only for GPRs */
    x86_regpos_all              /**< DEPRECATED the full register is used (default value), only value allowed for segregs and st */
};
#endif

#endif
