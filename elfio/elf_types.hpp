/*
Copyright (C) 2001-present by Serge Lamikhov-Center

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#ifndef ELFTYPES_H
#define ELFTYPES_H

#include <elfio/compat.hpp>

#ifdef __cplusplus
namespace ELFIO {
#endif

typedef uint16_t Elf_Half;
typedef uint32_t Elf_Word;
typedef int32_t  Elf_Sword;
typedef uint64_t Elf_Xword;
typedef int64_t  Elf_Sxword;

typedef uint32_t Elf32_Addr;
typedef uint32_t Elf32_Off;
typedef uint64_t Elf64_Addr;
typedef uint64_t Elf64_Off;

typedef Elf_Half  Elf32_Half;
typedef Elf_Half  Elf64_Half;
typedef Elf_Word  Elf32_Word;
typedef Elf_Word  Elf64_Word;
typedef Elf_Sword Elf32_Sword;
typedef Elf_Sword Elf64_Sword;

///////////////////////
// ELF Header Constants

// File type
#define ET_NONE   0
#define ET_REL    1
#define ET_EXEC   2
#define ET_DYN    3
#define ET_CORE   4
#define ET_LOOS   0xFE00
#define ET_HIOS   0xFEFF
#define ET_LOPROC 0xFF00
#define ET_HIPROC 0xFFFF

// Machine number
#define EM_NONE            0  // No machine
#define EM_M32             1  // AT&T WE 32100
#define EM_SPARC           2  // SUN SPARC
#define EM_386             3  // Intel 80386
#define EM_68K             4  // Motorola m68k family
#define EM_88K             5  // Motorola m88k family
#define EM_486             6  // Intel 80486// Reserved for future use
#define EM_860             7  // Intel 80860
#define EM_MIPS            8  // MIPS R3000 (officially, big-endian only)
#define EM_S370            9  // IBM System/370
#define EM_MIPS_RS3_LE     10 // MIPS R3000 little-endian (Deprecated)
#define EM_res011          11 // Reserved
#define EM_res012          12 // Reserved
#define EM_res013          13 // Reserved
#define EM_res014          14 // Reserved
#define EM_PARISC          15 // HPPA
#define EM_res016          16 // Reserved
#define EM_VPP550          17 // Fujitsu VPP500
#define EM_SPARC32PLUS     18 // Sun's "v8plus"
#define EM_960             19 // Intel 80960
#define EM_PPC             20 // PowerPC
#define EM_PPC64           21 // 64-bit PowerPC
#define EM_S390            22 // IBM S/390
#define EM_SPU             23 // Sony/Toshiba/IBM SPU
#define EM_res024          24 // Reserved
#define EM_res025          25 // Reserved
#define EM_res026          26 // Reserved
#define EM_res027          27 // Reserved
#define EM_res028          28 // Reserved
#define EM_res029          29 // Reserved
#define EM_res030          30 // Reserved
#define EM_res031          31 // Reserved
#define EM_res032          32 // Reserved
#define EM_res033          33 // Reserved
#define EM_res034          34 // Reserved
#define EM_res035          35 // Reserved
#define EM_V800            36 // NEC V800 series
#define EM_FR20            37 // Fujitsu FR20
#define EM_RH32            38 // TRW RH32
#define EM_MCORE           39 // Motorola M*Core // May also be taken by Fujitsu MMA
#define EM_RCE             39 // Old name for MCore
#define EM_ARM             40 // ARM
#define EM_OLD_ALPHA       41 // Digital Alpha
#define EM_SH              42 // Renesas (formerly Hitachi) / SuperH SH
#define EM_SPARCV9         43 // SPARC v9 64-bit
#define EM_TRICORE         44 // Siemens Tricore embedded processor
#define EM_ARC             45 // ARC Cores
#define EM_H8_300          46 // Renesas (formerly Hitachi) H8/300
#define EM_H8_300H         47 // Renesas (formerly Hitachi) H8/300H
#define EM_H8S             48 // Renesas (formerly Hitachi) H8S
#define EM_H8_500          49 // Renesas (formerly Hitachi) H8/500
#define EM_IA_64           50 // Intel IA-64 Processor
#define EM_MIPS_X          51 // Stanford MIPS-X
#define EM_COLDFIRE        52 // Motorola Coldfire
#define EM_68HC12          53 // Motorola M68HC12
#define EM_MMA             54 // Fujitsu Multimedia Accelerator
#define EM_PCP             55 // Siemens PCP
#define EM_NCPU            56 // Sony nCPU embedded RISC processor
#define EM_NDR1            57 // Denso NDR1 microprocesspr
#define EM_STARCORE        58 // Motorola Star*Core processor
#define EM_ME16            59 // Toyota ME16 processor
#define EM_ST100           60 // STMicroelectronics ST100 processor
#define EM_TINYJ           61 // Advanced Logic Corp. TinyJ embedded processor
#define EM_X86_64          62 // Advanced Micro Devices X86-64 processor
#define EM_PDSP            63 // Sony DSP Processor
#define EM_PDP10           64 // Digital Equipment Corp. PDP-10
#define EM_PDP11           65 // Digital Equipment Corp. PDP-11
#define EM_FX66            66 // Siemens FX66 microcontroller
#define EM_ST9PLUS         67 // STMicroelectronics ST9+ 8/16 bit microcontroller
#define EM_ST7             68  // STMicroelectronics ST7 8-bit microcontroller
#define EM_68HC16          69  // Motorola MC68HC16 Microcontroller
#define EM_68HC11          70  // Motorola MC68HC11 Microcontroller
#define EM_68HC08          71  // Motorola MC68HC08 Microcontroller
#define EM_68HC05          72  // Motorola MC68HC05 Microcontroller
#define EM_SVX             73  // Silicon Graphics SVx
#define EM_ST19            74  // STMicroelectronics ST19 8-bit cpu
#define EM_VAX             75  // Digital VAX
#define EM_CRIS            76  // Axis Communications 32-bit embedded processor
#define EM_JAVELIN         77  // Infineon Technologies 32-bit embedded cpu
#define EM_FIREPATH        78  // Element 14 64-bit DSP processor
#define EM_ZSP             79  // LSI Logic's 16-bit DSP processor
#define EM_MMIX            80  // Donald Knuth's educational 64-bit processor
#define EM_HUANY           81  // Harvard's machine-independent format
#define EM_PRISM           82  // SiTera Prism
#define EM_AVR             83  // Atmel AVR 8-bit microcontroller
#define EM_FR30            84  // Fujitsu FR30
#define EM_D10V            85  // Mitsubishi D10V
#define EM_D30V            86  // Mitsubishi D30V
#define EM_V850            87  // NEC v850
#define EM_M32R            88  // Renesas M32R (formerly Mitsubishi M32R)
#define EM_MN10300         89  // Matsushita MN10300
#define EM_MN10200         90  // Matsushita MN10200
#define EM_PJ              91  // picoJava
#define EM_OPENRISC        92  // OpenRISC 32-bit embedded processor
#define EM_ARC_A5          93  // ARC Cores Tangent-A5
#define EM_XTENSA          94  // Tensilica Xtensa Architecture
#define EM_VIDEOCORE       95  // Alphamosaic VideoCore processor
#define EM_TMM_GPP         96  // Thompson Multimedia General Purpose Processor
#define EM_NS32K           97  // National Semiconductor 32000 series
#define EM_TPC             98  // Tenor Network TPC processor
#define EM_SNP1K           99  // Trebia SNP 1000 processor
#define EM_ST200           100 // STMicroelectronics ST200 microcontroller
#define EM_IP2K            101 // Ubicom IP2022 micro controller
#define EM_MAX             102 // MAX Processor
#define EM_CR              103 // National Semiconductor CompactRISC
#define EM_F2MC16          104 // Fujitsu F2MC16
#define EM_MSP430          105 // TI msp430 micro controller
#define EM_BLACKFIN        106 // ADI Blackfin
#define EM_SE_C33          107 // S1C33 Family of Seiko Epson processors
#define EM_SEP             108 // Sharp embedded microprocessor
#define EM_ARCA            109 // Arca RISC Microprocessor
#define EM_UNICORE         110 // Microprocessor series from PKU-Unity Ltd.
#define EM_EXCESS          111 // eXcess: 16/32/64-bit configurable embedded CPU
#define EM_DXP             112 // Icera Semiconductor Inc. Deep Execution Processor
#define EM_ALTERA_NIOS2    113 // Altera Nios II soft-core processor
#define EM_CRX             114 // National Semiconductor CRX
#define EM_XGATE           115 // Motorola XGATE embedded processor
#define EM_C166            116 // Infineon C16x/XC16x processor
#define EM_M16C            117 // Renesas M16C series microprocessors
#define EM_DSPIC30F        118 // Microchip Technology dsPIC30F DSignal Controller
#define EM_CE              119 // Freescale Communication Engine RISC core
#define EM_M32C            120 // Renesas M32C series microprocessors
#define EM_res121          121 // Reserved
#define EM_res122          122 // Reserved
#define EM_res123          123 // Reserved
#define EM_res124          124 // Reserved
#define EM_res125          125 // Reserved
#define EM_res126          126 // Reserved
#define EM_res127          127 // Reserved
#define EM_res128          128 // Reserved
#define EM_res129          129 // Reserved
#define EM_res130          130 // Reserved
#define EM_TSK3000         131 // Altium TSK3000 core
#define EM_RS08            132 // Freescale RS08 embedded processor
#define EM_res133          133 // Reserved
#define EM_ECOG2           134 // Cyan Technology eCOG2 microprocessor
#define EM_SCORE           135 // Sunplus Score
#define EM_SCORE7          135 // Sunplus S+core7 RISC processor
#define EM_DSP24           136 // New Japan Radio (NJR) 24-bit DSP Processor
#define EM_VIDEOCORE3      137 // Broadcom VideoCore III processor
#define EM_LATTICEMICO32   138 // RISC processor for Lattice FPGA architecture
#define EM_SE_C17          139 // Seiko Epson C17 family
#define EM_TI_C6000        140 // Texas Instruments TMS320C6000 DSP family
#define EM_TI_C2000        141 // Texas Instruments TMS320C2000 DSP family
#define EM_TI_C5500        142 // Texas Instruments TMS320C55x DSP family
#define EM_res143          143 // Reserved
#define EM_res144          144 // Reserved
#define EM_res145          145 // Reserved
#define EM_res146          146 // Reserved
#define EM_res147          147 // Reserved
#define EM_res148          148 // Reserved
#define EM_res149          149 // Reserved
#define EM_res150          150 // Reserved
#define EM_res151          151 // Reserved
#define EM_res152          152 // Reserved
#define EM_res153          153 // Reserved
#define EM_res154          154 // Reserved
#define EM_res155          155 // Reserved
#define EM_res156          156 // Reserved
#define EM_res157          157 // Reserved
#define EM_res158          158 // Reserved
#define EM_res159          159 // Reserved
#define EM_MMDSP_PLUS      160 // STMicroelectronics 64bit VLIW Data Signal Processor
#define EM_CYPRESS_M8C     161 // Cypress M8C microprocessor
#define EM_R32C            162 // Renesas R32C series microprocessors
#define EM_TRIMEDIA        163 // NXP Semiconductors TriMedia architecture family
#define EM_QDSP6           164 // QUALCOMM DSP6 Processor
#define EM_8051            165 // Intel 8051 and variants
#define EM_STXP7X          166 // STMicroelectronics STxP7x family
#define EM_NDS32           167 // Andes Technology embedded RISC processor family
#define EM_ECOG1           168 // Cyan Technology eCOG1X family
#define EM_ECOG1X          168 // Cyan Technology eCOG1X family
#define EM_MAXQ30          169 // Dallas Semiconductor MAXQ30 Core Micro-controllers
#define EM_XIMO16          170 // New Japan Radio (NJR) 16-bit DSP Processor
#define EM_MANIK           171 // M2000 Reconfigurable RISC Microprocessor
#define EM_CRAYNV2         172 // Cray Inc. NV2 vector architecture
#define EM_RX              173 // Renesas RX family
#define EM_METAG           174 // Imagination Technologies META processor architecture
#define EM_MCST_ELBRUS     175 // MCST Elbrus general purpose hardware architecture
#define EM_ECOG16          176 // Cyan Technology eCOG16 family
#define EM_CR16            177 // National Semiconductor CompactRISC 16-bit processor
#define EM_ETPU            178 // Freescale Extended Time Processing Unit
#define EM_SLE9X           179 // Infineon Technologies SLE9X core
#define EM_L1OM            180 // Intel L1OM
#define EM_INTEL181        181 // Reserved by Intel
#define EM_INTEL182        182 // Reserved by Intel
#define EM_AARCH64         183 // ARM AArch64
#define EM_res184          184 // Reserved by ARM
#define EM_AVR32           185 // Atmel Corporation 32-bit microprocessor family
#define EM_STM8            186 // STMicroeletronics STM8 8-bit microcontroller
#define EM_TILE64          187 // Tilera TILE64 multicore architecture family
#define EM_TILEPRO         188 // Tilera TILEPro multicore architecture family
#define EM_MICROBLAZE      189 // Xilinx MicroBlaze 32-bit RISC soft processor core
#define EM_CUDA            190 // NVIDIA CUDA architecture
#define EM_TILEGX          191 // Tilera TILE-Gx multicore architecture family
#define EM_CLOUDSHIELD     192 // CloudShield architecture family
#define EM_COREA_1ST       193 // KIPO-KAIST Core-A 1st generation processor family
#define EM_COREA_2ND       194 // KIPO-KAIST Core-A 2nd generation processor family
#define EM_ARC_COMPACT2    195 // Synopsys ARCompact V2
#define EM_OPEN8           196 // Open8 8-bit RISC soft processor core
#define EM_RL78            197 // Renesas RL78 family
#define EM_VIDEOCORE5      198 // Broadcom VideoCore V processor
#define EM_78KOR           199 // Renesas 78KOR family
#define EM_56800EX         200 // Freescale 56800EX Digital Signal Controller (DSC)
#define EM_BA1             201 // Beyond BA1 CPU architecture
#define EM_BA2             202 // Beyond BA2 CPU architecture
#define EM_XCORE           203 // XMOS xCORE processor family
#define EM_MCHP_PIC        204 // Microchip 8-bit PIC(r) family
#define EM_INTEL205        205 // Reserved by Intel
#define EM_INTEL206        206 // Reserved by Intel
#define EM_INTEL207        207 // Reserved by Intel
#define EM_INTEL208        208 // Reserved by Intel
#define EM_INTEL209        209 // Reserved by Intel
#define EM_KM32            210 // KM211 KM32 32-bit processor
#define EM_KMX32           211 // KM211 KMX32 32-bit processor
#define EM_KMX16           212 // KM211 KMX16 16-bit processor
#define EM_KMX8            213 // KM211 KMX8 8-bit processor
#define EM_KVARC           214 // KM211 KVARC processor
#define EM_CDP             215 // Paneve CDP architecture family
#define EM_COGE            216 // Cognitive Smart Memory Processor
#define EM_COOL            217 // iCelero CoolEngine
#define EM_NORC            218 // Nanoradio Optimized RISC
#define EM_CSR_KALIMBA     219 // CSR Kalimba architecture family
#define EM_Z80             220 // Zilog Z80
#define EM_VISIUM          221 // Controls and Data Services VISIUMcore processor
#define EM_FT32            222 // FTDI Chip FT32 high performance 32-bit RISC architecture
#define EM_MOXIE           223 // Moxie processor family
#define EM_AMDGPU          224 // AMD GPU architecture
#define EM_RISCV           243 // RISC-V
#define EM_LANAI           244 // Lanai processor
#define EM_CEVA            245 // CEVA Processor Architecture Family
#define EM_CEVA_X2         246 // CEVA X2 Processor Family
#define EM_BPF             247 // Linux BPF – in-kernel virtual machine
#define EM_GRAPHCORE_IPU   248 // Graphcore Intelligent Processing Unit
#define EM_IMG1            249 // Imagination Technologies
#define EM_NFP             250 // Netronome Flow Processor (P)
#define EM_CSKY            252 // C-SKY processor family
#define EM_ARC_COMPACT3_64 253 // "Synopsys ARCv2.3 64-bit";
#define EM_MCS6502         254 // "MOS Technology MCS 6502 processor";
#define EM_ARC_COMPACT3    255 // "Synopsys ARCv2.3 32-bit";
#define EM_KVX             256 // "Kalray VLIW core of the MPPA processor family";
#define EM_65816           257 // "WDC 65816/65C816";
#define EM_LOONGARCH       258 // "Loongson Loongarch";
#define EM_KF32            259 // "ChipON KungFu32";

#define EM_MT                0x2530 // "Morpho Techologies MT processor";
#define EM_ALPHA             0x9026 // "Alpha";
#define EM_WEBASSEMBLY       0x4157 // "Web Assembly";
#define EM_DLX               0x5aa5 // "OpenDLX";
#define EM_XSTORMY16         0xad45 // "Sanyo XStormy16 CPU core";
#define EM_IQ2000            0xFEBA // "Vitesse IQ2000";
#define EM_M32C_OLD          0xFEB0
#define EM_NIOS32            0xFEBB // "Altera Nios";
#define EM_CYGNUS_MEP        0xF00D // "Toshiba MeP Media Engine";
#define EM_ADAPTEVA_EPIPHANY 0x1223 // "Adapteva EPIPHANY";
#define EM_CYGNUS_FRV        0x5441 // "Fujitsu FR-V";
#define EM_S12Z              0x4DEF // "Freescale S12Z";

// File version
#define EV_NONE    0
#define EV_CURRENT 1

// Identification index
#define EI_MAG0       0
#define EI_MAG1       1
#define EI_MAG2       2
#define EI_MAG3       3
#define EI_CLASS      4
#define EI_DATA       5
#define EI_VERSION    6
#define EI_OSABI      7
#define EI_ABIVERSION 8
#define EI_PAD        9
#define EI_NIDENT     16

// Magic number
#define ELFMAG0 0x7F
#define ELFMAG1 'E'
#define ELFMAG2 'L'
#define ELFMAG3 'F'

// File class
#define ELFCLASSNONE 0
#define ELFCLASS32   1
#define ELFCLASS64   2

// Encoding
#define ELFDATANONE 0
#define ELFDATA2LSB 1
#define ELFDATA2MSB 2

// OS extensions
#define ELFOSABI_NONE       0   // No extensions or unspecified
#define ELFOSABI_HPUX       1   // Hewlett-Packard HP-UX
#define ELFOSABI_NETBSD     2   // NetBSD
#define ELFOSABI_LINUX      3   // Linux
#define ELFOSABI_HURD       4   // GNU Hurd
#define ELFOSABI_SOLARIS    6   // Sun Solaris
#define ELFOSABI_AIX        7   // AIX
#define ELFOSABI_IRIX       8   // IRIX
#define ELFOSABI_FREEBSD    9   // FreeBSD
#define ELFOSABI_TRU64      10  // Compaq TRU64 UNIX
#define ELFOSABI_MODESTO    11  // Novell Modesto
#define ELFOSABI_OPENBSD    12  // Open BSD
#define ELFOSABI_OPENVMS    13  // Open VMS
#define ELFOSABI_NSK        14  // Hewlett-Packard Non-Stop Kernel
#define ELFOSABI_AROS       15  // Amiga Research OS
#define ELFOSABI_FENIXOS    16  // The FenixOS highly scalable multi-core OS
#define ELFOSABI_NUXI       17  // Nuxi CloudABI
#define ELFOSABI_OPENVOS    18  // Stratus Technologies OpenVOS
#define ELFOSABI_ARM        97  // ARM
#define ELFOSABI_STANDALONE 255 // Standalone (embedded) application

// 64-255 Architecture-specific value range
// AMDGPU OS for HSA compatible compute kernels
#define ELFOSABI_AMDGPU_HSA 64
// AMDGPU OS for AMD PAL compatible graphics
// shaders and compute kernels
#define ELFOSABI_AMDGPU_PAL 65
// AMDGPU OS for Mesa3D compatible graphics
// shaders and compute kernels
#define ELFOSABI_AMDGPU_MESA3D 66

#define ELFABIVERSION_AMDGPU_HSA_V2 0
#define ELFABIVERSION_AMDGPU_HSA_V3 1
#define ELFABIVERSION_AMDGPU_HSA_V4 2

// AMDGPU specific e_flags
#define EF_AMDGPU_MACH 0x0ff // AMDGPU processor selection mask.
// Indicates if the XNACK target feature is
// enabled for all code contained in the ELF.
#define EF_AMDGPU_XNACK 0x100

#define EF_AMDGPU_FEATURE_XNACK_V2               0x01
#define EF_AMDGPU_FEATURE_TRAP_HANDLER_V2        0x02
#define EF_AMDGPU_FEATURE_XNACK_V3               0x100
#define EF_AMDGPU_FEATURE_SRAMECC_V3             0x200
#define EF_AMDGPU_FEATURE_XNACK_V4               0x300
#define EF_AMDGPU_FEATURE_XNACK_UNSUPPORTED_V4   0x000
#define EF_AMDGPU_FEATURE_XNACK_ANY_V4           0x100
#define EF_AMDGPU_FEATURE_XNACK_OFF_V4           0x200
#define EF_AMDGPU_FEATURE_XNACK_ON_V4            0x300
#define EF_AMDGPU_FEATURE_SRAMECC_V4             0xc00
#define EF_AMDGPU_FEATURE_SRAMECC_UNSUPPORTED_V4 0x000
#define EF_AMDGPU_FEATURE_SRAMECC_ANY_V4         0x400
#define EF_AMDGPU_FEATURE_SRAMECC_OFF_V4         0x800
#define EF_AMDGPU_FEATURE_SRAMECC_ON_V4          0xc00

// AMDGPU processors
#define EF_AMDGPU_MACH_NONE                0x000 // Unspecified processor.
#define EF_AMDGPU_MACH_R600_R600           0x001
#define EF_AMDGPU_MACH_R600_R630           0x002
#define EF_AMDGPU_MACH_R600_RS880          0x003
#define EF_AMDGPU_MACH_R600_RV670          0x004
#define EF_AMDGPU_MACH_R600_RV710          0x005
#define EF_AMDGPU_MACH_R600_RV730          0x006
#define EF_AMDGPU_MACH_R600_RV770          0x007
#define EF_AMDGPU_MACH_R600_CEDAR          0x008
#define EF_AMDGPU_MACH_R600_CYPRESS        0x009
#define EF_AMDGPU_MACH_R600_JUNIPER        0x00a
#define EF_AMDGPU_MACH_R600_REDWOOD        0x00b
#define EF_AMDGPU_MACH_R600_SUMO           0x00c
#define EF_AMDGPU_MACH_R600_BARTS          0x00d
#define EF_AMDGPU_MACH_R600_CAICOS         0x00e
#define EF_AMDGPU_MACH_R600_CAYMAN         0x00f
#define EF_AMDGPU_MACH_R600_TURKS          0x010
#define EF_AMDGPU_MACH_R600_RESERVED_FIRST 0x011
#define EF_AMDGPU_MACH_R600_RESERVED_LAST  0x01f
#define EF_AMDGPU_MACH_R600_FIRST          EF_AMDGPU_MACH_R600_R600
#define EF_AMDGPU_MACH_R600_LAST           EF_AMDGPU_MACH_R600_TURKS

// AMDGCN-based processors.
#define EF_AMDGPU_MACH_AMDGCN_GFX600        0x020
#define EF_AMDGPU_MACH_AMDGCN_GFX601        0x021
#define EF_AMDGPU_MACH_AMDGCN_GFX700        0x022
#define EF_AMDGPU_MACH_AMDGCN_GFX701        0x023
#define EF_AMDGPU_MACH_AMDGCN_GFX702        0x024
#define EF_AMDGPU_MACH_AMDGCN_GFX703        0x025
#define EF_AMDGPU_MACH_AMDGCN_GFX704        0x026
#define EF_AMDGPU_MACH_AMDGCN_RESERVED_0X27 0x027
#define EF_AMDGPU_MACH_AMDGCN_GFX801        0x028
#define EF_AMDGPU_MACH_AMDGCN_GFX802        0x029
#define EF_AMDGPU_MACH_AMDGCN_GFX803        0x02a
#define EF_AMDGPU_MACH_AMDGCN_GFX810        0x02b
#define EF_AMDGPU_MACH_AMDGCN_GFX900        0x02c
#define EF_AMDGPU_MACH_AMDGCN_GFX902        0x02d
#define EF_AMDGPU_MACH_AMDGCN_GFX904        0x02e
#define EF_AMDGPU_MACH_AMDGCN_GFX906        0x02f
#define EF_AMDGPU_MACH_AMDGCN_GFX908        0x030
#define EF_AMDGPU_MACH_AMDGCN_GFX909        0x031
#define EF_AMDGPU_MACH_AMDGCN_GFX90C        0x032
#define EF_AMDGPU_MACH_AMDGCN_GFX1010       0x033
#define EF_AMDGPU_MACH_AMDGCN_GFX1011       0x034
#define EF_AMDGPU_MACH_AMDGCN_GFX1012       0x035
#define EF_AMDGPU_MACH_AMDGCN_GFX1030       0x036
#define EF_AMDGPU_MACH_AMDGCN_GFX1031       0x037
#define EF_AMDGPU_MACH_AMDGCN_GFX1032       0x038
#define EF_AMDGPU_MACH_AMDGCN_GFX1033       0x039
#define EF_AMDGPU_MACH_AMDGCN_GFX602        0x03a
#define EF_AMDGPU_MACH_AMDGCN_GFX705        0x03b
#define EF_AMDGPU_MACH_AMDGCN_GFX805        0x03c
#define EF_AMDGPU_MACH_AMDGCN_RESERVED_0X3D 0x03d
#define EF_AMDGPU_MACH_AMDGCN_GFX1034       0x03e
#define EF_AMDGPU_MACH_AMDGCN_GFX90A        0x03f
#define EF_AMDGPU_MACH_AMDGCN_RESERVED_0X40 0x040
#define EF_AMDGPU_MACH_AMDGCN_RESERVED_0X41 0x041
#define EF_AMDGPU_MACH_AMDGCN_GFX1013       0x042
// First/last AMDGCN-based processors.
#define EF_AMDGPU_MACH_AMDGCN_FIRST EF_AMDGPU_MACH_AMDGCN_GFX600
#define EF_AMDGPU_MACH_AMDGCN_LAST  EF_AMDGPU_MACH_AMDGCN_GFX1013

/////////////////////
// Sections constants

// Section indexes
#define SHN_UNDEF     0
#define SHN_LORESERVE 0xFF00
#define SHN_LOPROC    0xFF00
#define SHN_HIPROC    0xFF1F
#define SHN_LOOS      0xFF20
#define SHN_HIOS      0xFF3F
#define SHN_ABS       0xFFF1
#define SHN_COMMON    0xFFF2
#define SHN_XINDEX    0xFFFF
#define SHN_HIRESERVE 0xFFFF

// Section types
#define SHT_NULL               0
#define SHT_PROGBITS           1
#define SHT_SYMTAB             2
#define SHT_STRTAB             3
#define SHT_RELA               4
#define SHT_HASH               5
#define SHT_DYNAMIC            6
#define SHT_NOTE               7
#define SHT_NOBITS             8
#define SHT_REL                9
#define SHT_SHLIB              10
#define SHT_DYNSYM             11
#define SHT_INIT_ARRAY         14
#define SHT_FINI_ARRAY         15
#define SHT_PREINIT_ARRAY      16
#define SHT_GROUP              17
#define SHT_SYMTAB_SHNDX       18
#define SHT_GNU_ATTRIBUTES     0x6ffffff5
#define SHT_GNU_HASH           0x6ffffff6
#define SHT_GNU_LIBLIST        0x6ffffff7
#define SHT_CHECKSUM           0x6ffffff8
#define SHT_LOSUNW             0x6ffffffa
#define SHT_SUNW_move          0x6ffffffa
#define SHT_SUNW_COMDAT        0x6ffffffb
#define SHT_SUNW_syminfo       0x6ffffffc
#define SHT_GNU_verdef         0x6ffffffd
#define SHT_GNU_verneed        0x6ffffffe
#define SHT_GNU_versym         0x6fffffff
#define SHT_LOOS               0x60000000
#define SHT_HIOS               0x6fffffff
#define SHT_LOPROC             0x70000000
#define SHT_ARM_EXIDX          0x70000001
#define SHT_ARM_PREEMPTMAP     0x70000002
#define SHT_ARM_ATTRIBUTES     0x70000003
#define SHT_ARM_DEBUGOVERLAY   0x70000004
#define SHT_ARM_OVERLAYSECTION 0x70000005
#define SHT_HIPROC             0x7FFFFFFF
#define SHT_LOUSER             0x80000000
#define SHT_HIUSER             0xFFFFFFFF

// Section attribute flags
#define SHF_WRITE            0x1
#define SHF_ALLOC            0x2
#define SHF_EXECINSTR        0x4
#define SHF_MERGE            0x10
#define SHF_STRINGS          0x20
#define SHF_INFO_LINK        0x40
#define SHF_LINK_ORDER       0x80
#define SHF_OS_NONCONFORMING 0x100
#define SHF_GROUP            0x200
#define SHF_TLS              0x400
#define SHF_MASKOS           0x0ff00000
#define SHF_MASKPROC         0xF0000000

// Section group flags
#define GRP_COMDAT   0x1
#define GRP_MASKOS   0x0ff00000
#define GRP_MASKPROC 0xf0000000

// Symbol binding
#define STB_LOCAL    0
#define STB_GLOBAL   1
#define STB_WEAK     2
#define STB_LOOS     10
#define STB_HIOS     12
#define STB_MULTIDEF 13
#define STB_LOPROC   13
#define STB_HIPROC   15

// Values of note segment descriptor types for core files
#define NT_PRSTATUS   1 // Contains copy of prstatus struct
#define NT_FPREGSET   2 // Contains copy of fpregset struct
#define NT_PRPSINFO   3 // Contains copy of prpsinfo struct
#define NT_TASKSTRUCT 4 // Contains copy of task struct
#define NT_AUXV       6 // Contains copy of Elfxx_auxv_t
#define NT_SIGINFO    0x53494749 // Fields of siginfo_t.
#define NT_FILE       0x46494c45 // Description of mapped files.

// Note segments for core files on dir-style procfs systems.
#define NT_PSTATUS      10 // Has a struct pstatus
#define NT_FPREGS       12 // Has a struct fpregset
#define NT_PSINFO       13 // Has a struct psinfo
#define NT_LWPSTATUS    16 // Has a struct lwpstatus_t
#define NT_LWPSINFO     17 // Has a struct lwpsinfo_t
#define NT_WIN32PSTATUS 18 // Has a struct win32_pstatus

// clang-format off

// Note name must be "LINUX"    
#define NT_PRXFPREG             0x46e62b7f // Contains a user_xfpregs_struct;
#define NT_PPC_VMX              0x100      // PowerPC Altivec/VMX registers
#define NT_PPC_VSX              0x102      // PowerPC VSX registers
#define NT_PPC_TAR              0x103      // PowerPC Target Address Register
#define NT_PPC_PPR              0x104      // PowerPC Program Priority Register
#define NT_PPC_DSCR             0x105      // PowerPC Data Stream Control Register
#define NT_PPC_EBB              0x106      // PowerPC Event Based Branch Registers
#define NT_PPC_PMU              0x107      // PowerPC Performance Monitor Registers
#define NT_PPC_TM_CGPR          0x108      // PowerPC TM checkpointed GPR Registers
#define NT_PPC_TM_CFPR          0x109      // PowerPC TM checkpointed FPR Registers
#define NT_PPC_TM_CVMX          0x10a      // PowerPC TM checkpointed VMX Registers
#define NT_PPC_TM_CVSX          0x10b      // PowerPC TM checkpointed VSX Registers
#define NT_PPC_TM_SPR           0x10c      // PowerPC TM Special Purpose Registers
#define NT_PPC_TM_CTAR          0x10d      // PowerPC TM checkpointed TAR
#define NT_PPC_TM_CPPR          0x10e      // PowerPC TM checkpointed PPR
#define NT_PPC_TM_CDSCR         0x10f      // PowerPC TM checkpointed Data SCR
#define NT_386_TLS              0x200      // x86 TLS information
#define NT_386_IOPERM           0x201      // x86 io permissions
#define NT_X86_XSTATE           0x202      // x86 XSAVE extended state
#define NT_X86_CET              0x203      // x86 CET state.
#define NT_S390_HIGH_GPRS       0x300      // S/390 upper halves of GPRs
#define NT_S390_TIMER           0x301      // S390 timer
#define NT_S390_TODCMP          0x302      // S390 TOD clock comparator
#define NT_S390_TODPREG         0x303      // S390 TOD programmable register
#define NT_S390_CTRS            0x304      // S390 control registers
#define NT_S390_PREFIX          0x305      // S390 prefix register
#define NT_S390_LAST_BREAK      0x306      // S390 breaking event address
#define NT_S390_SYSTEM_CALL     0x307      // S390 system call restart data
#define NT_S390_TDB             0x308      // S390 transaction diagnostic block
#define NT_S390_VXRS_LOW        0x309      // S390 vector registers 0-15 upper half
#define NT_S390_VXRS_HIGH       0x30a      // S390 vector registers 16-31
#define NT_S390_GS_CB           0x30b      // s390 guarded storage registers
#define NT_S390_GS_BC           0x30c      // s390 guarded storage broadcast control block
#define NT_ARM_VFP              0x400      // ARM VFP registers
#define NT_ARM_TLS              0x401      // AArch TLS registers
#define NT_ARM_HW_BREAK         0x402      // AArch hardware breakpoint registers
#define NT_ARM_HW_WATCH         0x403      // AArch hardware watchpoint registers
#define NT_ARM_SVE              0x405      // AArch SVE registers.
#define NT_ARM_PAC_MASK         0x406      // AArch pointer authentication code masks
#define NT_ARM_PACA_KEYS        0x407      // ARM pointer authentication address keys
#define NT_ARM_PACG_KEYS        0x408      // ARM pointer authentication generic keys
#define NT_ARM_TAGGED_ADDR_CTRL 0x409      // AArch64 tagged address control (prctl())
#define NT_ARM_PAC_ENABLED_KEYS 0x40a      // AArch64 pointer authentication enabled keys (prctl())
#define NT_ARC_V2               0x600      // ARC HS accumulator/extra registers.
#define NT_LARCH_CPUCFG         0xa00      // LoongArch CPU config registers
#define NT_LARCH_CSR            0xa01      // LoongArch Control State Registers
#define NT_LARCH_LSX            0xa02      // LoongArch SIMD eXtension registers
#define NT_LARCH_LASX           0xa03      // LoongArch Advanced SIMD eXtension registers
#define NT_RISCV_CSR            0x900      // RISC-V Control and Status Registers

// Note name must be "CORE"
#define NT_LARCH_LBT 0xa04 // LoongArch Binary Translation registers

/* The range 0xff000000 to 0xffffffff is set aside for notes that don't
   originate from any particular operating system.  */
#define NT_GDB_TDESC 0xff000000 // Contains copy of GDB's target description XML.
#define NT_MEMTAG    0xff000001 // Contains a copy of the memory tags.
/* ARM-specific NT_MEMTAG types.  */
#define NT_MEMTAG_TYPE_AARCH_MTE 0x400 // MTE memory tags for AArch64.

/* Note segment for SystemTap probes.  */
#define NT_STAPSDT 3

// Note name is "FreeBSD"
#define NT_FREEBSD_THRMISC            7  // Thread miscellaneous info.
#define NT_FREEBSD_PROCSTAT_PROC      8  // Procstat proc data.
#define NT_FREEBSD_PROCSTAT_FILES     9  // Procstat files data.
#define NT_FREEBSD_PROCSTAT_VMMAP     10 // Procstat vmmap data.
#define NT_FREEBSD_PROCSTAT_GROUPS    11 // Procstat groups data.
#define NT_FREEBSD_PROCSTAT_UMASK     12 // Procstat umask data.
#define NT_FREEBSD_PROCSTAT_RLIMIT    13 // Procstat rlimit data.
#define NT_FREEBSD_PROCSTAT_OSREL     14 // Procstat osreldate data.
#define NT_FREEBSD_PROCSTAT_PSSTRINGS 15 // Procstat ps_strings data.
#define NT_FREEBSD_PROCSTAT_AUXV      16 // Procstat auxv data.
#define NT_FREEBSD_PTLWPINFO          17 // Thread ptrace miscellaneous info.

// Note name must start with  "NetBSD-CORE"
#define NT_NETBSDCORE_PROCINFO  1  // Has a struct procinfo
#define NT_NETBSDCORE_AUXV      2  // Has auxv data
#define NT_NETBSDCORE_LWPSTATUS 24 // Has LWPSTATUS data
#define NT_NETBSDCORE_FIRSTMACH 32 // start of machdep note types

// Note name is "OpenBSD"
#define NT_OPENBSD_PROCINFO 10
#define NT_OPENBSD_AUXV     11
#define NT_OPENBSD_REGS     20
#define NT_OPENBSD_FPREGS   21
#define NT_OPENBSD_XFPREGS  22
#define NT_OPENBSD_WCOOKIE  23

// Note name must start with "SPU"
#define NT_SPU 1

// Values of note segment descriptor types for object files
#define NT_VERSION    1 // Contains a version string.
#define NT_ARCH       2 // Contains an architecture string.
#define NT_GO_BUILDID 4 // Contains GO buildid data.

// Values for notes in non-core files using name "GNU"
#define NT_GNU_ABI_TAG         1
#define NT_GNU_HWCAP           2 // Used by ld.so and kernel vDSO.
#define NT_GNU_BUILD_ID        3 // Generated by ld --build-id.
#define NT_GNU_GOLD_VERSION    4 // Generated by gold.
#define NT_GNU_PROPERTY_TYPE_0 5 // Generated by gcc.
// clang-format on

#define NT_GNU_BUILD_ATTRIBUTE_OPEN 0x100
#define NT_GNU_BUILD_ATTRIBUTE_FUNC 0x101

// Symbol types
#define STT_NOTYPE            0
#define STT_OBJECT            1
#define STT_FUNC              2
#define STT_SECTION           3
#define STT_FILE              4
#define STT_COMMON            5
#define STT_TLS               6
#define STT_LOOS              10
#define STT_AMDGPU_HSA_KERNEL 10
#define STT_HIOS              12
#define STT_LOPROC            13
#define STT_HIPROC            15

// Symbol visibility
#define STV_DEFAULT   0
#define STV_INTERNAL  1
#define STV_HIDDEN    2
#define STV_PROTECTED 3

// Undefined name
#define STN_UNDEF 0

// Relocation types
//   X86
#define R_386_NONE               0
#define R_X86_64_NONE            0
#define R_AMDGPU_NONE            0
#define R_386_32                 1
#define R_X86_64_64              1
#define R_AMDGPU_ABS32_LO        1
#define R_386_PC32               2
#define R_X86_64_PC32            2
#define R_AMDGPU_ABS32_HI        2
#define R_386_GOT32              3
#define R_X86_64_GOT32           3
#define R_AMDGPU_ABS64           3
#define R_386_PLT32              4
#define R_X86_64_PLT32           4
#define R_AMDGPU_REL32           4
#define R_386_COPY               5
#define R_X86_64_COPY            5
#define R_AMDGPU_REL64           5
#define R_386_GLOB_DAT           6
#define R_X86_64_GLOB_DAT        6
#define R_AMDGPU_ABS32           6
#define R_386_JMP_SLOT           7
#define R_X86_64_JUMP_SLOT       7
#define R_AMDGPU_GOTPCREL        7
#define R_386_RELATIVE           8
#define R_X86_64_RELATIVE        8
#define R_AMDGPU_GOTPCREL32_LO   8
#define R_386_GOTOFF             9
#define R_X86_64_GOTPCREL        9
#define R_AMDGPU_GOTPCREL32_HI   9
#define R_386_GOTPC              10
#define R_X86_64_32              10
#define R_AMDGPU_REL32_LO        10
#define R_386_32PLT              11
#define R_X86_64_32S             11
#define R_AMDGPU_REL32_HI        11
#define R_X86_64_16              12
#define R_X86_64_PC16            13
#define R_AMDGPU_RELATIVE64      13
#define R_386_TLS_TPOFF          14
#define R_X86_64_8               14
#define R_386_TLS_IE             15
#define R_X86_64_PC8             15
#define R_386_TLS_GOTIE          16
#define R_X86_64_DTPMOD64        16
#define R_386_TLS_LE             17
#define R_X86_64_DTPOFF64        17
#define R_386_TLS_GD             18
#define R_X86_64_TPOFF64         18
#define R_386_TLS_LDM            19
#define R_X86_64_TLSGD           19
#define R_386_16                 20
#define R_X86_64_TLSLD           20
#define R_386_PC16               21
#define R_X86_64_DTPOFF32        21
#define R_386_8                  22
#define R_X86_64_GOTTPOFF        22
#define R_386_PC8                23
#define R_X86_64_TPOFF32         23
#define R_386_TLS_GD_32          24
#define R_X86_64_PC64            24
#define R_386_TLS_GD_PUSH        25
#define R_X86_64_GOTOFF64        25
#define R_386_TLS_GD_CALL        26
#define R_X86_64_GOTPC32         26
#define R_386_TLS_GD_POP         27
#define R_X86_64_GOT64           27
#define R_386_TLS_LDM_32         28
#define R_X86_64_GOTPCREL64      28
#define R_386_TLS_LDM_PUSH       29
#define R_X86_64_GOTPC64         29
#define R_386_TLS_LDM_CALL       30
#define R_X86_64_GOTPLT64        30
#define R_386_TLS_LDM_POP        31
#define R_X86_64_PLTOFF64        31
#define R_386_TLS_LDO_32         32
#define R_386_TLS_IE_32          33
#define R_386_TLS_LE_32          34
#define R_X86_64_GOTPC32_TLSDESC 34
#define R_386_TLS_DTPMOD32       35
#define R_X86_64_TLSDESC_CALL    35
#define R_386_TLS_DTPOFF32       36
#define R_X86_64_TLSDESC         36
#define R_386_TLS_TPOFF32        37
#define R_X86_64_IRELATIVE       37
#define R_386_SIZE32             38
#define R_386_TLS_GOTDESC        39
#define R_386_TLS_DESC_CALL      40
#define R_386_TLS_DESC           41
#define R_386_IRELATIVE          42
#define R_386_GOT32X             43
#define R_X86_64_GNU_VTINHERIT   250
#define R_X86_64_GNU_VTENTRY     251
//   AArch64
#define R_AARCH64_NONE                         0
#define R_AARCH64_P32_ABS32                    1
#define R_AARCH64_P32_COPY                     180
#define R_AARCH64_P32_GLOB_DAT                 181
#define R_AARCH64_P32_JUMP_SLOT                182
#define R_AARCH64_P32_RELATIVE                 183
#define R_AARCH64_P32_TLS_DTPMOD               184
#define R_AARCH64_P32_TLS_DTPREL               185
#define R_AARCH64_P32_TLS_TPREL                186
#define R_AARCH64_P32_TLSDESC                  187
#define R_AARCH64_P32_IRELATIVE                188
#define R_AARCH64_ABS64                        257
#define R_AARCH64_ABS32                        258
#define R_AARCH64_ABS16                        259
#define R_AARCH64_PREL64                       260
#define R_AARCH64_PREL32                       261
#define R_AARCH64_PREL16                       262
#define R_AARCH64_MOVW_UABS_G0                 263
#define R_AARCH64_MOVW_UABS_G0_NC              264
#define R_AARCH64_MOVW_UABS_G1                 265
#define R_AARCH64_MOVW_UABS_G1_NC              266
#define R_AARCH64_MOVW_UABS_G2                 267
#define R_AARCH64_MOVW_UABS_G2_NC              268
#define R_AARCH64_MOVW_UABS_G3                 269
#define R_AARCH64_MOVW_SABS_G0                 270
#define R_AARCH64_MOVW_SABS_G1                 271
#define R_AARCH64_MOVW_SABS_G2                 272
#define R_AARCH64_LD_PREL_LO19                 273
#define R_AARCH64_ADR_PREL_LO21                274
#define R_AARCH64_ADR_PREL_PG_HI21             275
#define R_AARCH64_ADR_PREL_PG_HI21_NC          276
#define R_AARCH64_ADD_ABS_LO12_NC              277
#define R_AARCH64_LDST8_ABS_LO12_NC            278
#define R_AARCH64_TSTBR14                      279
#define R_AARCH64_CONDBR19                     280
#define R_AARCH64_JUMP26                       282
#define R_AARCH64_CALL26                       283
#define R_AARCH64_LDST16_ABS_LO12_NC           284
#define R_AARCH64_LDST32_ABS_LO12_NC           285
#define R_AARCH64_LDST64_ABS_LO12_NC           286
#define R_AARCH64_MOVW_PREL_G0                 287
#define R_AARCH64_MOVW_PREL_G0_NC              288
#define R_AARCH64_MOVW_PREL_G1                 289
#define R_AARCH64_MOVW_PREL_G1_NC              290
#define R_AARCH64_MOVW_PREL_G2                 291
#define R_AARCH64_MOVW_PREL_G2_NC              292
#define R_AARCH64_MOVW_PREL_G3                 293
#define R_AARCH64_LDST128_ABS_LO12_NC          299
#define R_AARCH64_MOVW_GOTOFF_G0               300
#define R_AARCH64_MOVW_GOTOFF_G0_NC            301
#define R_AARCH64_MOVW_GOTOFF_G1               302
#define R_AARCH64_MOVW_GOTOFF_G1_NC            303
#define R_AARCH64_MOVW_GOTOFF_G2               304
#define R_AARCH64_MOVW_GOTOFF_G2_NC            305
#define R_AARCH64_MOVW_GOTOFF_G3               306
#define R_AARCH64_GOTREL64                     307
#define R_AARCH64_GOTREL32                     308
#define R_AARCH64_GOT_LD_PREL19                309
#define R_AARCH64_LD64_GOTOFF_LO15             310
#define R_AARCH64_ADR_GOT_PAGE                 311
#define R_AARCH64_LD64_GOT_LO12_NC             312
#define R_AARCH64_LD64_GOTPAGE_LO15            313
#define R_AARCH64_TLSGD_ADR_PREL21             512
#define R_AARCH64_TLSGD_ADR_PAGE21             513
#define R_AARCH64_TLSGD_ADD_LO12_NC            514
#define R_AARCH64_TLSGD_MOVW_G1                515
#define R_AARCH64_TLSGD_MOVW_G0_NC             516
#define R_AARCH64_TLSLD_ADR_PREL21             517
#define R_AARCH64_TLSLD_ADR_PAGE21             518
#define R_AARCH64_TLSLD_ADD_LO12_NC            519
#define R_AARCH64_TLSLD_MOVW_G1                520
#define R_AARCH64_TLSLD_MOVW_G0_NC             521
#define R_AARCH64_TLSLD_LD_PREL19              522
#define R_AARCH64_TLSLD_MOVW_DTPREL_G2         523
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1         524
#define R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC      525
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0         526
#define R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC      527
#define R_AARCH64_TLSLD_ADD_DTPREL_HI12        528
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12        529
#define R_AARCH64_TLSLD_ADD_DTPREL_LO12_NC     530
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12      531
#define R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC   532
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12     533
#define R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC  534
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12     535
#define R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC  536
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12     537
#define R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC  538
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G1       539
#define R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC    540
#define R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21    541
#define R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC  542
#define R_AARCH64_TLSIE_LD_GOTTPREL_PREL19     543
#define R_AARCH64_TLSLE_MOVW_TPREL_G2          544
#define R_AARCH64_TLSLE_MOVW_TPREL_G1          545
#define R_AARCH64_TLSLE_MOVW_TPREL_G1_NC       546
#define R_AARCH64_TLSLE_MOVW_TPREL_G0          547
#define R_AARCH64_TLSLE_MOVW_TPREL_G0_NC       548
#define R_AARCH64_TLSLE_ADD_TPREL_HI12         549
#define R_AARCH64_TLSLE_ADD_TPREL_LO12         550
#define R_AARCH64_TLSLE_ADD_TPREL_LO12_NC      551
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12       552
#define R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC    553
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12      554
#define R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC   555
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12      556
#define R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC   557
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12      558
#define R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC   559
#define R_AARCH64_TLSDESC_LD_PREL19            560
#define R_AARCH64_TLSDESC_ADR_PREL21           561
#define R_AARCH64_TLSDESC_ADR_PAGE21           562
#define R_AARCH64_TLSDESC_LD64_LO12            563
#define R_AARCH64_TLSDESC_ADD_LO12             564
#define R_AARCH64_TLSDESC_OFF_G1               565
#define R_AARCH64_TLSDESC_OFF_G0_NC            566
#define R_AARCH64_TLSDESC_LDR                  567
#define R_AARCH64_TLSDESC_ADD                  568
#define R_AARCH64_TLSDESC_CALL                 569
#define R_AARCH64_TLSLE_LDST128_TPREL_LO12     570
#define R_AARCH64_TLSLE_LDST128_TPREL_LO12_NC  571
#define R_AARCH64_TLSLD_LDST128_DTPREL_LO12    572
#define R_AARCH64_TLSLD_LDST128_DTPREL_LO12_NC 573
#define R_AARCH64_COPY                         1024
#define R_AARCH64_GLOB_DAT                     1025
#define R_AARCH64_JUMP_SLOT                    1026
#define R_AARCH64_RELATIVE                     1027
#define R_AARCH64_TLS_DTPMOD                   1028
#define R_AARCH64_TLS_DTPMOD64                 1028
#define R_AARCH64_TLS_DTPREL                   1029
#define R_AARCH64_TLS_DTPREL64                 1029
#define R_AARCH64_TLS_TPREL                    1030
#define R_AARCH64_TLS_TPREL64                  1030
#define R_AARCH64_TLSDESC                      1031

// Segment types
#define PT_NULL              0
#define PT_LOAD              1
#define PT_DYNAMIC           2
#define PT_INTERP            3
#define PT_NOTE              4
#define PT_SHLIB             5
#define PT_PHDR              6
#define PT_TLS               7
#define PT_LOOS              0X60000000
#define PT_GNU_EH_FRAME      0X6474E550 // Frame unwind information
#define PT_GNU_STACK         0X6474E551 // Stack flags
#define PT_GNU_RELRO         0X6474E552 // Read only after relocs
#define PT_GNU_PROPERTY      0X6474E553 // GNU property
#define PT_GNU_MBIND_LO      0X6474E555 // Mbind segments start
#define PT_GNU_MBIND_HI      0X6474F554 // Mbind segments finish
#define PT_PAX_FLAGS         0X65041580
#define PT_OPENBSD_RANDOMIZE 0X65A3DBE6
#define PT_OPENBSD_WXNEEDED  0X65A3DBE7
#define PT_OPENBSD_BOOTDATA  0X65A41BE6
#define PT_SUNWBSS           0X6FFFFFFA
#define PT_SUNWSTACK         0X6FFFFFFB
#define PT_HIOS              0X6FFFFFFF
#define PT_LOPROC            0X70000000
#define PT_HIPROC            0X7FFFFFFF

// Segment flags
#define PF_X        1          // Execute
#define PF_W        2          // Write
#define PF_R        4          // Read
#define PF_MASKOS   0x0ff00000 // Unspecified
#define PF_MASKPROC 0xf0000000 // Unspecified

// Dynamic Array Tags
#define DT_NULL            0
#define DT_NEEDED          1
#define DT_PLTRELSZ        2
#define DT_PLTGOT          3
#define DT_HASH            4
#define DT_STRTAB          5
#define DT_SYMTAB          6
#define DT_RELA            7
#define DT_RELASZ          8
#define DT_RELAENT         9
#define DT_STRSZ           10
#define DT_SYMENT          11
#define DT_INIT            12
#define DT_FINI            13
#define DT_SONAME          14
#define DT_RPATH           15
#define DT_SYMBOLIC        16
#define DT_REL             17
#define DT_RELSZ           18
#define DT_RELENT          19
#define DT_PLTREL          20
#define DT_DEBUG           21
#define DT_TEXTREL         22
#define DT_JMPREL          23
#define DT_BIND_NOW        24
#define DT_INIT_ARRAY      25
#define DT_FINI_ARRAY      26
#define DT_INIT_ARRAYSZ    27
#define DT_FINI_ARRAYSZ    28
#define DT_RUNPATH         29
#define DT_FLAGS           30
#define DT_ENCODING        32
#define DT_PREINIT_ARRAY   32
#define DT_PREINIT_ARRAYSZ 33
#define DT_MAXPOSTAGS      34
#define DT_LOOS            0x6000000D
#define DT_HIOS            0x6ffff000
#define DT_GNU_HASH        0x6ffffef5
#define DT_TLSDESC_PLT     0x6ffffef6
#define DT_TLSDESC_GOT     0x6ffffef7
#define DT_GNU_CONFLICT    0x6ffffef8
#define DT_GNU_LIBLIST     0x6ffffef9
#define DT_CONFIG          0x6ffffefa
#define DT_DEPAUDIT        0x6ffffefb
#define DT_AUDIT           0x6ffffefc
#define DT_PLTPAD          0x6ffffefd
#define DT_MOVETAB         0x6ffffefe
#define DT_SYMINFO         0x6ffffeff
#define DT_ADDRRNGHI       0x6ffffeff
#define DT_VERSYM          0x6ffffff0
#define DT_RELACOUNT       0x6ffffff9
#define DT_RELCOUNT        0x6ffffffa
#define DT_FLAGS_1         0x6ffffffb
#define DT_VERDEF          0x6ffffffc
#define DT_VERDEFNUM       0x6ffffffd
#define DT_VERNEED         0x6ffffffe
#define DT_VERNEEDNUM      0x6fffffff
#define DT_LOPROC          0x70000000
#define DT_HIPROC          0x7FFFFFFF

// DT_FLAGS values
#define DF_ORIGIN     0x1
#define DF_SYMBOLIC   0x2
#define DF_TEXTREL    0x4
#define DF_BIND_NOW   0x8
#define DF_STATIC_TLS 0x10

// Legal values for d_tag (dynamic entry type).
#define AT_NULL          0  // End of vector
#define AT_IGNORE        1  // Entry should be ignored
#define AT_EXECFD        2  // File descriptor of program
#define AT_PHDR          3  // Program headers for program
#define AT_PHENT         4  // Size of program header entry
#define AT_PHNUM         5  // Number of program headers
#define AT_PAGESZ        6  // System page size
#define AT_BASE          7  // Base address of interpreter
#define AT_FLAGS         8  // Flags
#define AT_ENTRY         9  // Entry point of program
#define AT_NOTELF        10 // Program is not ELF
#define AT_UID           11 // Real uid
#define AT_EUID          12 // Effective uid
#define AT_GID           13 // Real gid
#define AT_EGID          14 // Effective gid
#define AT_CLKTCK        17 // Frequency of times()
#define AT_PLATFORM      15 // String identifying platform.
#define AT_HWCAP         16 // Hints about processor capabilities.
#define AT_FPUCW         18 // Used FPU control word.
#define AT_DCACHEBSIZE   19 // Data cache block size.
#define AT_ICACHEBSIZE   20 // Instruction cache block size.
#define AT_UCACHEBSIZE   21 // Unified cache block size.
#define AT_IGNOREPPC     22 // Entry should be ignored.
#define AT_SECURE        23 // Boolean, was exec setuid-like?
#define AT_BASE_PLATFORM 24 // String identifying real platforms.
#define AT_RANDOM        25 // Address of 16 random bytes.
#define AT_HWCAP2  26 // More hints about processor capabilities.
#define AT_EXECFN  31 // Filename of executable.
#define AT_SYSINFO 32 // EP to the system call in the vDSO.
#define AT_SYSINFO_EHDR 33 // Start of the ELF header of the vDSO.
#define AT_L1I_CACHESHAPE    34
#define AT_L1D_CACHESHAPE    35
#define AT_L2_CACHESHAPE     36
#define AT_L3_CACHESHAPE     37
#define AT_L1I_CACHESIZE     40
#define AT_L1I_CACHEGEOMETRY 41
#define AT_L1D_CACHESIZE     42
#define AT_L1D_CACHEGEOMETRY 43
#define AT_L2_CACHESIZE      44
#define AT_L2_CACHEGEOMETRY  45
#define AT_L3_CACHESIZE      46

// ELF file header
struct Elf32_Ehdr
{
    unsigned char e_ident[EI_NIDENT];
    Elf_Half      e_type;
    Elf_Half      e_machine;
    Elf_Word      e_version;
    Elf32_Addr    e_entry;
    Elf32_Off     e_phoff;
    Elf32_Off     e_shoff;
    Elf_Word      e_flags;
    Elf_Half      e_ehsize;
    Elf_Half      e_phentsize;
    Elf_Half      e_phnum;
    Elf_Half      e_shentsize;
    Elf_Half      e_shnum;
    Elf_Half      e_shstrndx;
};

struct Elf64_Ehdr
{
    unsigned char e_ident[EI_NIDENT];
    Elf_Half      e_type;
    Elf_Half      e_machine;
    Elf_Word      e_version;
    Elf64_Addr    e_entry;
    Elf64_Off     e_phoff;
    Elf64_Off     e_shoff;
    Elf_Word      e_flags;
    Elf_Half      e_ehsize;
    Elf_Half      e_phentsize;
    Elf_Half      e_phnum;
    Elf_Half      e_shentsize;
    Elf_Half      e_shnum;
    Elf_Half      e_shstrndx;
};

// Section header
struct Elf32_Shdr
{
    Elf_Word   sh_name;
    Elf_Word   sh_type;
    Elf_Word   sh_flags;
    Elf32_Addr sh_addr;
    Elf32_Off  sh_offset;
    Elf_Word   sh_size;
    Elf_Word   sh_link;
    Elf_Word   sh_info;
    Elf_Word   sh_addralign;
    Elf_Word   sh_entsize;
};

struct Elf64_Shdr
{
    Elf_Word   sh_name;
    Elf_Word   sh_type;
    Elf_Xword  sh_flags;
    Elf64_Addr sh_addr;
    Elf64_Off  sh_offset;
    Elf_Xword  sh_size;
    Elf_Word   sh_link;
    Elf_Word   sh_info;
    Elf_Xword  sh_addralign;
    Elf_Xword  sh_entsize;
};

// Segment header
struct Elf32_Phdr
{
    Elf_Word   p_type;
    Elf32_Off  p_offset;
    Elf32_Addr p_vaddr;
    Elf32_Addr p_paddr;
    Elf_Word   p_filesz;
    Elf_Word   p_memsz;
    Elf_Word   p_flags;
    Elf_Word   p_align;
};

struct Elf64_Phdr
{
    Elf_Word   p_type;
    Elf_Word   p_flags;
    Elf64_Off  p_offset;
    Elf64_Addr p_vaddr;
    Elf64_Addr p_paddr;
    Elf_Xword  p_filesz;
    Elf_Xword  p_memsz;
    Elf_Xword  p_align;
};

// Symbol table entry
struct Elf32_Sym
{
    Elf_Word      st_name;
    Elf32_Addr    st_value;
    Elf_Word      st_size;
    unsigned char st_info;
    unsigned char st_other;
    Elf_Half      st_shndx;
};

struct Elf64_Sym
{
    Elf_Word      st_name;
    unsigned char st_info;
    unsigned char st_other;
    Elf_Half      st_shndx;
    Elf64_Addr    st_value;
    Elf_Xword     st_size;
};

#define ELF_ST_BIND( i )    ( ( i ) >> 4 )
#define ELF_ST_TYPE( i )    ( (i)&0xf )
#define ELF_ST_INFO( b, t ) ( ( ( b ) << 4 ) + ( (t)&0xf ) )

#define ELF_ST_VISIBILITY( o ) ( (o)&0x3 )

// Relocation entries
struct Elf32_Rel
{
    Elf32_Addr r_offset;
    Elf_Word   r_info;
};

struct Elf32_Rela
{
    Elf32_Addr r_offset;
    Elf_Word   r_info;
    Elf_Sword  r_addend;
};

struct Elf64_Rel
{
    Elf64_Addr r_offset;
    Elf_Xword  r_info;
};

struct Elf64_Rela
{
    Elf64_Addr r_offset;
    Elf_Xword  r_info;
    Elf_Sxword r_addend;
};

#define ELF32_R_SYM( i )     ( ( i ) >> 8 )
#define ELF32_R_TYPE( i )    ( (unsigned char)( i ) )
#define ELF32_R_INFO( s, t ) ( ( ( s ) << 8 ) + (unsigned char)( t ) )

#define ELF64_R_SYM( i )  ( ( i ) >> 32 )
#define ELF64_R_TYPE( i ) ( (i)&0xffffffffL )
#define ELF64_R_INFO( s, t ) \
    ( ( ( (int64_t)( s ) ) << 32 ) + ( (t)&0xffffffffL ) )

// Dynamic structure
struct Elf32_Dyn
{
    Elf_Sword d_tag;
    union {
        Elf_Word   d_val;
        Elf32_Addr d_ptr;
    } d_un;
};

struct Elf64_Dyn
{
    Elf_Sxword d_tag;
    union {
        Elf_Xword  d_val;
        Elf64_Addr d_ptr;
    } d_un;
};

struct Elfxx_Verneed
{
    Elf_Half vn_version;
    Elf_Half vn_cnt;
    Elf_Word vn_file;
    Elf_Word vn_aux;
    Elf_Word vn_next;
};

struct Elfxx_Vernaux
{
    Elf_Word vna_hash;
    Elf_Half vna_flags;
    Elf_Half vna_other;
    Elf_Word vna_name;
    Elf_Word vna_next;
};

// ELF auxiliary vectors, they are usually run-time information
// being passed to program when the kernel is loading it.
// This is now required,
// because in order to initialize the stack cookie
// to protect against buffer overflows,
// most of libc ask us to have a valid pointer for the AT_RANDOM entry.
// glibc for example crashes if you don't.
// https://sourceware.org/git/?p=glibc.git;a=blob;f=csu/libc-start.c;h=543560f36c33b07a1fbe1b7e4578374fe8007b1f;hb=HEAD#l308
// This is also useful to be able to reconstruct at run-time
// the ELF headers, if ELF headers were erased after loading.
// Although this library is targeted to be parsing files only,
// I assume auxiliary vectors could be also used to get
// more information about the ELF binary at run-time in future.
// The main purpose is also for ELF injectors.
struct Elf32_auxv
{
    uint32_t a_type; // Entry type

    union {
        uint32_t a_val; // Integer value, usually a pointer
    } a_un;
};

struct Elf64_auxv
{
    uint64_t a_type; // Entry type

    union {
        uint64_t a_val; // Integer value, usually a pointer
    } a_un;
};

#ifdef __cplusplus
} // namespace ELFIO
#endif

#endif // ELFTYPES_H
