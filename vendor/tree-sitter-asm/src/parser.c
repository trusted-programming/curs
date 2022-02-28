#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#ifdef _MSC_VER
#pragma optimize("", off)
#elif defined(__clang__)
#pragma clang optimize off
#elif defined(__GNUC__)
#pragma GCC optimize ("O0")
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 432
#define ALIAS_COUNT 0
#define TOKEN_COUNT 417
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 6
#define PRODUCTION_ID_COUNT 1

enum {
  sym__line_break = 1,
  aux_sym_comment_token1 = 2,
  aux_sym_comment_token2 = 3,
  anon_sym_COLON = 4,
  anon_sym_adc = 5,
  anon_sym_adcx = 6,
  anon_sym_add = 7,
  anon_sym_addb = 8,
  anon_sym_addl = 9,
  anon_sym_addq = 10,
  anon_sym_addr32 = 11,
  anon_sym_addsd = 12,
  anon_sym_addss = 13,
  anon_sym_addw = 14,
  anon_sym_adox = 15,
  anon_sym_aesdec = 16,
  anon_sym_aesdeclast = 17,
  anon_sym_aesenc = 18,
  anon_sym_aesenclast = 19,
  anon_sym_aeskeygenassist = 20,
  anon_sym_and = 21,
  anon_sym_andb = 22,
  anon_sym_andl = 23,
  anon_sym_andn = 24,
  anon_sym_andpd = 25,
  anon_sym_andps = 26,
  anon_sym_andq = 27,
  anon_sym_andw = 28,
  anon_sym_blendvps = 29,
  anon_sym_bsf = 30,
  anon_sym_bsr = 31,
  anon_sym_bswap = 32,
  anon_sym_bt = 33,
  anon_sym_btl = 34,
  anon_sym_btr = 35,
  anon_sym_bts = 36,
  anon_sym_cbtw = 37,
  anon_sym_cltd = 38,
  anon_sym_cltq = 39,
  anon_sym_cmova = 40,
  anon_sym_cmovae = 41,
  anon_sym_cmovb = 42,
  anon_sym_cmovbe = 43,
  anon_sym_cmove = 44,
  anon_sym_cmovg = 45,
  anon_sym_cmovge = 46,
  anon_sym_cmovl = 47,
  anon_sym_cmovle = 48,
  anon_sym_cmovne = 49,
  anon_sym_cmovns = 50,
  anon_sym_cmovo = 51,
  anon_sym_cmovp = 52,
  anon_sym_cmovs = 53,
  anon_sym_cmp = 54,
  anon_sym_cmpb = 55,
  anon_sym_cmpl = 56,
  anon_sym_cmpq = 57,
  anon_sym_cmpw = 58,
  anon_sym_comisd = 59,
  anon_sym_comiss = 60,
  anon_sym_cpuid = 61,
  anon_sym_cqto = 62,
  anon_sym_cvtsd2ss = 63,
  anon_sym_cvtsi2sd = 64,
  anon_sym_cvtsi2sdl = 65,
  anon_sym_cvtsi2sdq = 66,
  anon_sym_cvtsi2ss = 67,
  anon_sym_cvtsi2ssl = 68,
  anon_sym_cvtss2sd = 69,
  anon_sym_cvttsd2si = 70,
  anon_sym_cvttss2si = 71,
  anon_sym_cwtd = 72,
  anon_sym_cwtl = 73,
  anon_sym_data16 = 74,
  anon_sym_dec = 75,
  anon_sym_div = 76,
  anon_sym_divl = 77,
  anon_sym_divq = 78,
  anon_sym_divsd = 79,
  anon_sym_divss = 80,
  anon_sym_endbr64 = 81,
  anon_sym_femms = 82,
  anon_sym_fildl = 83,
  anon_sym_fldt = 84,
  anon_sym_fmulp = 85,
  anon_sym_fs = 86,
  anon_sym_fstpl = 87,
  anon_sym_gs = 88,
  anon_sym_idiv = 89,
  anon_sym_idivl = 90,
  anon_sym_imul = 91,
  anon_sym_inc = 92,
  anon_sym_incl = 93,
  anon_sym_insb = 94,
  anon_sym_insl = 95,
  anon_sym_kmovw = 96,
  anon_sym_knotw = 97,
  anon_sym_lea = 98,
  anon_sym_leaveq = 99,
  anon_sym_lock = 100,
  anon_sym_maxsd = 101,
  anon_sym_maxss = 102,
  anon_sym_mfence = 103,
  anon_sym_minsd = 104,
  anon_sym_minss = 105,
  anon_sym_mov = 106,
  anon_sym_movabs = 107,
  anon_sym_movapd = 108,
  anon_sym_movaps = 109,
  anon_sym_movb = 110,
  anon_sym_movbe = 111,
  anon_sym_movd = 112,
  anon_sym_movdqa = 113,
  anon_sym_movdqu = 114,
  anon_sym_movhlps = 115,
  anon_sym_movhps = 116,
  anon_sym_movl = 117,
  anon_sym_movq = 118,
  anon_sym_movsb = 119,
  anon_sym_movsbl = 120,
  anon_sym_movsbq = 121,
  anon_sym_movsbw = 122,
  anon_sym_movsd = 123,
  anon_sym_movslq = 124,
  anon_sym_movss = 125,
  anon_sym_movswl = 126,
  anon_sym_movswq = 127,
  anon_sym_movups = 128,
  anon_sym_movw = 129,
  anon_sym_movzbl = 130,
  anon_sym_movzbq = 131,
  anon_sym_movzbw = 132,
  anon_sym_movzwl = 133,
  anon_sym_mul = 134,
  anon_sym_mulb = 135,
  anon_sym_mull = 136,
  anon_sym_mulq = 137,
  anon_sym_mulsd = 138,
  anon_sym_mulss = 139,
  anon_sym_mulw = 140,
  anon_sym_mulx = 141,
  anon_sym_neg = 142,
  anon_sym_negl = 143,
  anon_sym_negq = 144,
  anon_sym_nop = 145,
  anon_sym_nopl = 146,
  anon_sym_nopw = 147,
  anon_sym_not = 148,
  anon_sym_notl = 149,
  anon_sym_notw = 150,
  anon_sym_or = 151,
  anon_sym_orb = 152,
  anon_sym_orl = 153,
  anon_sym_orq = 154,
  anon_sym_orw = 155,
  anon_sym_outsb = 156,
  anon_sym_outsl = 157,
  anon_sym_packuswb = 158,
  anon_sym_paddd = 159,
  anon_sym_paddq = 160,
  anon_sym_paddw = 161,
  anon_sym_palignr = 162,
  anon_sym_pand = 163,
  anon_sym_pandn = 164,
  anon_sym_pblendw = 165,
  anon_sym_pclmulhqhqdq = 166,
  anon_sym_pclmullqhqdq = 167,
  anon_sym_pclmullqlqdq = 168,
  anon_sym_pcmpeqb = 169,
  anon_sym_pcmpeqd = 170,
  anon_sym_pcmpgtd = 171,
  anon_sym_pextrb = 172,
  anon_sym_pextrq = 173,
  anon_sym_pextrw = 174,
  anon_sym_pinsrb = 175,
  anon_sym_pinsrd = 176,
  anon_sym_pinsrw = 177,
  anon_sym_pmaddubsw = 178,
  anon_sym_pmaddwd = 179,
  anon_sym_pmovmskb = 180,
  anon_sym_pmuludq = 181,
  anon_sym_pop = 182,
  anon_sym_popcnt = 183,
  anon_sym_por = 184,
  anon_sym_prefetcht0 = 185,
  anon_sym_prefetcht1 = 186,
  anon_sym_pshufb = 187,
  anon_sym_pshufd = 188,
  anon_sym_pshufhw = 189,
  anon_sym_pshuflw = 190,
  anon_sym_pslld = 191,
  anon_sym_pslldq = 192,
  anon_sym_psllq = 193,
  anon_sym_psrad = 194,
  anon_sym_psrld = 195,
  anon_sym_psrldq = 196,
  anon_sym_psrlq = 197,
  anon_sym_psrlw = 198,
  anon_sym_psubb = 199,
  anon_sym_psubd = 200,
  anon_sym_psubq = 201,
  anon_sym_psubusb = 202,
  anon_sym_psubusw = 203,
  anon_sym_punpckhbw = 204,
  anon_sym_punpckhdq = 205,
  anon_sym_punpckhqdq = 206,
  anon_sym_punpckhwd = 207,
  anon_sym_punpcklbw = 208,
  anon_sym_punpckldq = 209,
  anon_sym_punpcklqdq = 210,
  anon_sym_punpcklwd = 211,
  anon_sym_push = 212,
  anon_sym_pushq = 213,
  anon_sym_pxor = 214,
  anon_sym_re = 215,
  anon_sym_rep = 216,
  anon_sym_repnz = 217,
  anon_sym_repz = 218,
  anon_sym_retq = 219,
  anon_sym_rex = 220,
  anon_sym_rex_DOTB = 221,
  anon_sym_rex_DOTRB = 222,
  anon_sym_rex_DOTRXB = 223,
  anon_sym_rex_DOTW = 224,
  anon_sym_rex_DOTWB = 225,
  anon_sym_rex_DOTWRB = 226,
  anon_sym_rex_DOTWRXB = 227,
  anon_sym_rex_DOTXB = 228,
  anon_sym_rol = 229,
  anon_sym_roll = 230,
  anon_sym_ror = 231,
  anon_sym_rorl = 232,
  anon_sym_rorx = 233,
  anon_sym_sar = 234,
  anon_sym_sarl = 235,
  anon_sym_sarx = 236,
  anon_sym_sbb = 237,
  anon_sym_seta = 238,
  anon_sym_setae = 239,
  anon_sym_setb = 240,
  anon_sym_setbe = 241,
  anon_sym_sete = 242,
  anon_sym_setg = 243,
  anon_sym_setge = 244,
  anon_sym_setl = 245,
  anon_sym_setle = 246,
  anon_sym_setne = 247,
  anon_sym_setnp = 248,
  anon_sym_setns = 249,
  anon_sym_seto = 250,
  anon_sym_setp = 251,
  anon_sym_sha1msg1 = 252,
  anon_sym_sha1msg2 = 253,
  anon_sym_sha1nexte = 254,
  anon_sym_sha1rnds4 = 255,
  anon_sym_shl = 256,
  anon_sym_shld = 257,
  anon_sym_shll = 258,
  anon_sym_shlq = 259,
  anon_sym_shlx = 260,
  anon_sym_shr = 261,
  anon_sym_shrd = 262,
  anon_sym_shrl = 263,
  anon_sym_shrq = 264,
  anon_sym_shrx = 265,
  anon_sym_shufpd = 266,
  anon_sym_shufps = 267,
  anon_sym_ss = 268,
  anon_sym_sub = 269,
  anon_sym_subb = 270,
  anon_sym_subl = 271,
  anon_sym_subpd = 272,
  anon_sym_subq = 273,
  anon_sym_subsd = 274,
  anon_sym_subss = 275,
  anon_sym_subw = 276,
  anon_sym_test = 277,
  anon_sym_testb = 278,
  anon_sym_testl = 279,
  anon_sym_tzcnt = 280,
  anon_sym_ucomisd = 281,
  anon_sym_ucomiss = 282,
  anon_sym_ud2 = 283,
  anon_sym_unpckhpd = 284,
  anon_sym_vaesenc = 285,
  anon_sym_vaesenclast = 286,
  anon_sym_vblendps = 287,
  anon_sym_vblendvps = 288,
  anon_sym_vbroadcasti128 = 289,
  anon_sym_vbroadcasti32x4 = 290,
  anon_sym_vbroadcastss = 291,
  anon_sym_vcvtusi2sd = 292,
  anon_sym_vdivsd = 293,
  anon_sym_vextracti128 = 294,
  anon_sym_vextracti32x4 = 295,
  anon_sym_vinsertf128 = 296,
  anon_sym_vinserti128 = 297,
  anon_sym_vinserti32x4 = 298,
  anon_sym_vinserti64x4 = 299,
  anon_sym_vmovapd = 300,
  anon_sym_vmovaps = 301,
  anon_sym_vmovd = 302,
  anon_sym_vmovdqa = 303,
  anon_sym_vmovdqa32 = 304,
  anon_sym_vmovdqa64 = 305,
  anon_sym_vmovdqu = 306,
  anon_sym_vmovdqu32 = 307,
  anon_sym_vmovdqu64 = 308,
  anon_sym_vmovq = 309,
  anon_sym_vmovsd = 310,
  anon_sym_vmovss = 311,
  anon_sym_vmovups = 312,
  anon_sym_vmulsd = 313,
  anon_sym_vpackusdw = 314,
  anon_sym_vpaddb = 315,
  anon_sym_vpaddd = 316,
  anon_sym_vpaddq = 317,
  anon_sym_vpaddw = 318,
  anon_sym_vpalignr = 319,
  anon_sym_vpand = 320,
  anon_sym_vpblendd = 321,
  anon_sym_vpblendmd = 322,
  anon_sym_vpbroadcastd = 323,
  anon_sym_vpbroadcastq = 324,
  anon_sym_vpclmulhqhqdq = 325,
  anon_sym_vpclmulhqlqdq = 326,
  anon_sym_vpclmullqhqdq = 327,
  anon_sym_vpclmullqlqdq = 328,
  anon_sym_vpcmpgtd = 329,
  anon_sym_vpcmpltud = 330,
  anon_sym_vperm2f128 = 331,
  anon_sym_vperm2i128 = 332,
  anon_sym_vpermd = 333,
  anon_sym_vpermi2d = 334,
  anon_sym_vpermq = 335,
  anon_sym_vpermt2d = 336,
  anon_sym_vpextrw = 337,
  anon_sym_vpinsrb = 338,
  anon_sym_vpinsrd = 339,
  anon_sym_vpinsrq = 340,
  anon_sym_vpinsrw = 341,
  anon_sym_vpmaddubsw = 342,
  anon_sym_vpmaddwd = 343,
  anon_sym_vpmullw = 344,
  anon_sym_vpmuludq = 345,
  anon_sym_vpor = 346,
  anon_sym_vprord = 347,
  anon_sym_vprorq = 348,
  anon_sym_vpshufb = 349,
  anon_sym_vpshufd = 350,
  anon_sym_vpslld = 351,
  anon_sym_vpslldq = 352,
  anon_sym_vpsllq = 353,
  anon_sym_vpsllw = 354,
  anon_sym_vpsrld = 355,
  anon_sym_vpsrldq = 356,
  anon_sym_vpsrlq = 357,
  anon_sym_vpsrlw = 358,
  anon_sym_vpsubd = 359,
  anon_sym_vpsubq = 360,
  anon_sym_vpsubusw = 361,
  anon_sym_vpsubw = 362,
  anon_sym_vpunpckhdq = 363,
  anon_sym_vpunpckhqdq = 364,
  anon_sym_vpunpckhwd = 365,
  anon_sym_vpunpckldq = 366,
  anon_sym_vpunpcklqdq = 367,
  anon_sym_vpunpcklwd = 368,
  anon_sym_vpxor = 369,
  anon_sym_vpxord = 370,
  anon_sym_vshufi32x4 = 371,
  anon_sym_vshufi64x2 = 372,
  anon_sym_vshufps = 373,
  anon_sym_vsubsd = 374,
  anon_sym_vucomisd = 375,
  anon_sym_vucomiss = 376,
  anon_sym_vunpckhpd = 377,
  anon_sym_vunpckhps = 378,
  anon_sym_vunpcklpd = 379,
  anon_sym_vunpcklps = 380,
  anon_sym_vxorps = 381,
  anon_sym_vzeroall = 382,
  anon_sym_vzeroupper = 383,
  anon_sym_xchg = 384,
  anon_sym_xgetbv = 385,
  anon_sym_xor = 386,
  anon_sym_xorl = 387,
  anon_sym_xorpd = 388,
  anon_sym_xorps = 389,
  anon_sym_xorw = 390,
  anon_sym_COMMA = 391,
  anon_sym_ = 392,
  anon_sym_callq = 393,
  anon_sym_ja = 394,
  anon_sym_jae = 395,
  anon_sym_jb = 396,
  anon_sym_jbe = 397,
  anon_sym_je = 398,
  anon_sym_jg = 399,
  anon_sym_jge = 400,
  anon_sym_jl = 401,
  anon_sym_jle = 402,
  anon_sym_jmp = 403,
  anon_sym_jmpq = 404,
  anon_sym_jne = 405,
  anon_sym_jno = 406,
  anon_sym_jns = 407,
  anon_sym_jo = 408,
  anon_sym_jp = 409,
  anon_sym_jrcxz = 410,
  anon_sym_js = 411,
  anon_sym_notrack = 412,
  aux_sym_address_token1 = 413,
  aux_sym_operand_token1 = 414,
  aux_sym_fn_token1 = 415,
  sym_two_bytes = 416,
  sym_prog = 417,
  sym_comment = 418,
  sym__line = 419,
  sym_opcode = 420,
  sym_instruction = 421,
  sym_callq = 422,
  sym_address = 423,
  sym_operand = 424,
  sym_fn = 425,
  aux_sym_prog_repeat1 = 426,
  aux_sym__line_repeat1 = 427,
  aux_sym_instruction_repeat1 = 428,
  aux_sym_address_repeat1 = 429,
  aux_sym_operand_repeat1 = 430,
  aux_sym_fn_repeat1 = 431,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym__line_break] = "_line_break",
  [aux_sym_comment_token1] = "comment_token1",
  [aux_sym_comment_token2] = "comment_token2",
  [anon_sym_COLON] = ":",
  [anon_sym_adc] = "adc",
  [anon_sym_adcx] = "adcx",
  [anon_sym_add] = "add",
  [anon_sym_addb] = "addb",
  [anon_sym_addl] = "addl",
  [anon_sym_addq] = "addq",
  [anon_sym_addr32] = "addr32",
  [anon_sym_addsd] = "addsd",
  [anon_sym_addss] = "addss",
  [anon_sym_addw] = "addw",
  [anon_sym_adox] = "adox",
  [anon_sym_aesdec] = "aesdec",
  [anon_sym_aesdeclast] = "aesdeclast",
  [anon_sym_aesenc] = "aesenc",
  [anon_sym_aesenclast] = "aesenclast",
  [anon_sym_aeskeygenassist] = "aeskeygenassist",
  [anon_sym_and] = "and",
  [anon_sym_andb] = "andb",
  [anon_sym_andl] = "andl",
  [anon_sym_andn] = "andn",
  [anon_sym_andpd] = "andpd",
  [anon_sym_andps] = "andps",
  [anon_sym_andq] = "andq",
  [anon_sym_andw] = "andw",
  [anon_sym_blendvps] = "blendvps",
  [anon_sym_bsf] = "bsf",
  [anon_sym_bsr] = "bsr",
  [anon_sym_bswap] = "bswap",
  [anon_sym_bt] = "bt",
  [anon_sym_btl] = "btl",
  [anon_sym_btr] = "btr",
  [anon_sym_bts] = "bts",
  [anon_sym_cbtw] = "cbtw",
  [anon_sym_cltd] = "cltd",
  [anon_sym_cltq] = "cltq",
  [anon_sym_cmova] = "cmova",
  [anon_sym_cmovae] = "cmovae",
  [anon_sym_cmovb] = "cmovb",
  [anon_sym_cmovbe] = "cmovbe",
  [anon_sym_cmove] = "cmove",
  [anon_sym_cmovg] = "cmovg",
  [anon_sym_cmovge] = "cmovge",
  [anon_sym_cmovl] = "cmovl",
  [anon_sym_cmovle] = "cmovle",
  [anon_sym_cmovne] = "cmovne",
  [anon_sym_cmovns] = "cmovns",
  [anon_sym_cmovo] = "cmovo",
  [anon_sym_cmovp] = "cmovp",
  [anon_sym_cmovs] = "cmovs",
  [anon_sym_cmp] = "cmp",
  [anon_sym_cmpb] = "cmpb",
  [anon_sym_cmpl] = "cmpl",
  [anon_sym_cmpq] = "cmpq",
  [anon_sym_cmpw] = "cmpw",
  [anon_sym_comisd] = "comisd",
  [anon_sym_comiss] = "comiss",
  [anon_sym_cpuid] = "cpuid",
  [anon_sym_cqto] = "cqto",
  [anon_sym_cvtsd2ss] = "cvtsd2ss",
  [anon_sym_cvtsi2sd] = "cvtsi2sd",
  [anon_sym_cvtsi2sdl] = "cvtsi2sdl",
  [anon_sym_cvtsi2sdq] = "cvtsi2sdq",
  [anon_sym_cvtsi2ss] = "cvtsi2ss",
  [anon_sym_cvtsi2ssl] = "cvtsi2ssl",
  [anon_sym_cvtss2sd] = "cvtss2sd",
  [anon_sym_cvttsd2si] = "cvttsd2si",
  [anon_sym_cvttss2si] = "cvttss2si",
  [anon_sym_cwtd] = "cwtd",
  [anon_sym_cwtl] = "cwtl",
  [anon_sym_data16] = "data16",
  [anon_sym_dec] = "dec",
  [anon_sym_div] = "div",
  [anon_sym_divl] = "divl",
  [anon_sym_divq] = "divq",
  [anon_sym_divsd] = "divsd",
  [anon_sym_divss] = "divss",
  [anon_sym_endbr64] = "endbr64",
  [anon_sym_femms] = "femms",
  [anon_sym_fildl] = "fildl",
  [anon_sym_fldt] = "fldt",
  [anon_sym_fmulp] = "fmulp",
  [anon_sym_fs] = "fs",
  [anon_sym_fstpl] = "fstpl",
  [anon_sym_gs] = "gs",
  [anon_sym_idiv] = "idiv",
  [anon_sym_idivl] = "idivl",
  [anon_sym_imul] = "imul",
  [anon_sym_inc] = "inc",
  [anon_sym_incl] = "incl",
  [anon_sym_insb] = "insb",
  [anon_sym_insl] = "insl",
  [anon_sym_kmovw] = "kmovw",
  [anon_sym_knotw] = "knotw",
  [anon_sym_lea] = "lea",
  [anon_sym_leaveq] = "leaveq",
  [anon_sym_lock] = "lock",
  [anon_sym_maxsd] = "maxsd",
  [anon_sym_maxss] = "maxss",
  [anon_sym_mfence] = "mfence",
  [anon_sym_minsd] = "minsd",
  [anon_sym_minss] = "minss",
  [anon_sym_mov] = "mov",
  [anon_sym_movabs] = "movabs",
  [anon_sym_movapd] = "movapd",
  [anon_sym_movaps] = "movaps",
  [anon_sym_movb] = "movb",
  [anon_sym_movbe] = "movbe",
  [anon_sym_movd] = "movd",
  [anon_sym_movdqa] = "movdqa",
  [anon_sym_movdqu] = "movdqu",
  [anon_sym_movhlps] = "movhlps",
  [anon_sym_movhps] = "movhps",
  [anon_sym_movl] = "movl",
  [anon_sym_movq] = "movq",
  [anon_sym_movsb] = "movsb",
  [anon_sym_movsbl] = "movsbl",
  [anon_sym_movsbq] = "movsbq",
  [anon_sym_movsbw] = "movsbw",
  [anon_sym_movsd] = "movsd",
  [anon_sym_movslq] = "movslq",
  [anon_sym_movss] = "movss",
  [anon_sym_movswl] = "movswl",
  [anon_sym_movswq] = "movswq",
  [anon_sym_movups] = "movups",
  [anon_sym_movw] = "movw",
  [anon_sym_movzbl] = "movzbl",
  [anon_sym_movzbq] = "movzbq",
  [anon_sym_movzbw] = "movzbw",
  [anon_sym_movzwl] = "movzwl",
  [anon_sym_mul] = "mul",
  [anon_sym_mulb] = "mulb",
  [anon_sym_mull] = "mull",
  [anon_sym_mulq] = "mulq",
  [anon_sym_mulsd] = "mulsd",
  [anon_sym_mulss] = "mulss",
  [anon_sym_mulw] = "mulw",
  [anon_sym_mulx] = "mulx",
  [anon_sym_neg] = "neg",
  [anon_sym_negl] = "negl",
  [anon_sym_negq] = "negq",
  [anon_sym_nop] = "nop",
  [anon_sym_nopl] = "nopl",
  [anon_sym_nopw] = "nopw",
  [anon_sym_not] = "not",
  [anon_sym_notl] = "notl",
  [anon_sym_notw] = "notw",
  [anon_sym_or] = "or",
  [anon_sym_orb] = "orb",
  [anon_sym_orl] = "orl",
  [anon_sym_orq] = "orq",
  [anon_sym_orw] = "orw",
  [anon_sym_outsb] = "outsb",
  [anon_sym_outsl] = "outsl",
  [anon_sym_packuswb] = "packuswb",
  [anon_sym_paddd] = "paddd",
  [anon_sym_paddq] = "paddq",
  [anon_sym_paddw] = "paddw",
  [anon_sym_palignr] = "palignr",
  [anon_sym_pand] = "pand",
  [anon_sym_pandn] = "pandn",
  [anon_sym_pblendw] = "pblendw",
  [anon_sym_pclmulhqhqdq] = "pclmulhqhqdq",
  [anon_sym_pclmullqhqdq] = "pclmullqhqdq",
  [anon_sym_pclmullqlqdq] = "pclmullqlqdq",
  [anon_sym_pcmpeqb] = "pcmpeqb",
  [anon_sym_pcmpeqd] = "pcmpeqd",
  [anon_sym_pcmpgtd] = "pcmpgtd",
  [anon_sym_pextrb] = "pextrb",
  [anon_sym_pextrq] = "pextrq",
  [anon_sym_pextrw] = "pextrw",
  [anon_sym_pinsrb] = "pinsrb",
  [anon_sym_pinsrd] = "pinsrd",
  [anon_sym_pinsrw] = "pinsrw",
  [anon_sym_pmaddubsw] = "pmaddubsw",
  [anon_sym_pmaddwd] = "pmaddwd",
  [anon_sym_pmovmskb] = "pmovmskb",
  [anon_sym_pmuludq] = "pmuludq",
  [anon_sym_pop] = "pop",
  [anon_sym_popcnt] = "popcnt",
  [anon_sym_por] = "por",
  [anon_sym_prefetcht0] = "prefetcht0",
  [anon_sym_prefetcht1] = "prefetcht1",
  [anon_sym_pshufb] = "pshufb",
  [anon_sym_pshufd] = "pshufd",
  [anon_sym_pshufhw] = "pshufhw",
  [anon_sym_pshuflw] = "pshuflw",
  [anon_sym_pslld] = "pslld",
  [anon_sym_pslldq] = "pslldq",
  [anon_sym_psllq] = "psllq",
  [anon_sym_psrad] = "psrad",
  [anon_sym_psrld] = "psrld",
  [anon_sym_psrldq] = "psrldq",
  [anon_sym_psrlq] = "psrlq",
  [anon_sym_psrlw] = "psrlw",
  [anon_sym_psubb] = "psubb",
  [anon_sym_psubd] = "psubd",
  [anon_sym_psubq] = "psubq",
  [anon_sym_psubusb] = "psubusb",
  [anon_sym_psubusw] = "psubusw",
  [anon_sym_punpckhbw] = "punpckhbw",
  [anon_sym_punpckhdq] = "punpckhdq",
  [anon_sym_punpckhqdq] = "punpckhqdq",
  [anon_sym_punpckhwd] = "punpckhwd",
  [anon_sym_punpcklbw] = "punpcklbw",
  [anon_sym_punpckldq] = "punpckldq",
  [anon_sym_punpcklqdq] = "punpcklqdq",
  [anon_sym_punpcklwd] = "punpcklwd",
  [anon_sym_push] = "push",
  [anon_sym_pushq] = "pushq",
  [anon_sym_pxor] = "pxor",
  [anon_sym_re] = "re",
  [anon_sym_rep] = "rep",
  [anon_sym_repnz] = "repnz",
  [anon_sym_repz] = "repz",
  [anon_sym_retq] = "retq",
  [anon_sym_rex] = "rex",
  [anon_sym_rex_DOTB] = "rex.B",
  [anon_sym_rex_DOTRB] = "rex.RB",
  [anon_sym_rex_DOTRXB] = "rex.RXB",
  [anon_sym_rex_DOTW] = "rex.W",
  [anon_sym_rex_DOTWB] = "rex.WB",
  [anon_sym_rex_DOTWRB] = "rex.WRB",
  [anon_sym_rex_DOTWRXB] = "rex.WRXB",
  [anon_sym_rex_DOTXB] = "rex.XB",
  [anon_sym_rol] = "rol",
  [anon_sym_roll] = "roll",
  [anon_sym_ror] = "ror",
  [anon_sym_rorl] = "rorl",
  [anon_sym_rorx] = "rorx",
  [anon_sym_sar] = "sar",
  [anon_sym_sarl] = "sarl",
  [anon_sym_sarx] = "sarx",
  [anon_sym_sbb] = "sbb",
  [anon_sym_seta] = "seta",
  [anon_sym_setae] = "setae",
  [anon_sym_setb] = "setb",
  [anon_sym_setbe] = "setbe",
  [anon_sym_sete] = "sete",
  [anon_sym_setg] = "setg",
  [anon_sym_setge] = "setge",
  [anon_sym_setl] = "setl",
  [anon_sym_setle] = "setle",
  [anon_sym_setne] = "setne",
  [anon_sym_setnp] = "setnp",
  [anon_sym_setns] = "setns",
  [anon_sym_seto] = "seto",
  [anon_sym_setp] = "setp",
  [anon_sym_sha1msg1] = "sha1msg1",
  [anon_sym_sha1msg2] = "sha1msg2",
  [anon_sym_sha1nexte] = "sha1nexte",
  [anon_sym_sha1rnds4] = "sha1rnds4",
  [anon_sym_shl] = "shl",
  [anon_sym_shld] = "shld",
  [anon_sym_shll] = "shll",
  [anon_sym_shlq] = "shlq",
  [anon_sym_shlx] = "shlx",
  [anon_sym_shr] = "shr",
  [anon_sym_shrd] = "shrd",
  [anon_sym_shrl] = "shrl",
  [anon_sym_shrq] = "shrq",
  [anon_sym_shrx] = "shrx",
  [anon_sym_shufpd] = "shufpd",
  [anon_sym_shufps] = "shufps",
  [anon_sym_ss] = "ss",
  [anon_sym_sub] = "sub",
  [anon_sym_subb] = "subb",
  [anon_sym_subl] = "subl",
  [anon_sym_subpd] = "subpd",
  [anon_sym_subq] = "subq",
  [anon_sym_subsd] = "subsd",
  [anon_sym_subss] = "subss",
  [anon_sym_subw] = "subw",
  [anon_sym_test] = "test",
  [anon_sym_testb] = "testb",
  [anon_sym_testl] = "testl",
  [anon_sym_tzcnt] = "tzcnt",
  [anon_sym_ucomisd] = "ucomisd",
  [anon_sym_ucomiss] = "ucomiss",
  [anon_sym_ud2] = "ud2",
  [anon_sym_unpckhpd] = "unpckhpd",
  [anon_sym_vaesenc] = "vaesenc",
  [anon_sym_vaesenclast] = "vaesenclast",
  [anon_sym_vblendps] = "vblendps",
  [anon_sym_vblendvps] = "vblendvps",
  [anon_sym_vbroadcasti128] = "vbroadcasti128",
  [anon_sym_vbroadcasti32x4] = "vbroadcasti32x4",
  [anon_sym_vbroadcastss] = "vbroadcastss",
  [anon_sym_vcvtusi2sd] = "vcvtusi2sd",
  [anon_sym_vdivsd] = "vdivsd",
  [anon_sym_vextracti128] = "vextracti128",
  [anon_sym_vextracti32x4] = "vextracti32x4",
  [anon_sym_vinsertf128] = "vinsertf128",
  [anon_sym_vinserti128] = "vinserti128",
  [anon_sym_vinserti32x4] = "vinserti32x4",
  [anon_sym_vinserti64x4] = "vinserti64x4",
  [anon_sym_vmovapd] = "vmovapd",
  [anon_sym_vmovaps] = "vmovaps",
  [anon_sym_vmovd] = "vmovd",
  [anon_sym_vmovdqa] = "vmovdqa",
  [anon_sym_vmovdqa32] = "vmovdqa32",
  [anon_sym_vmovdqa64] = "vmovdqa64",
  [anon_sym_vmovdqu] = "vmovdqu",
  [anon_sym_vmovdqu32] = "vmovdqu32",
  [anon_sym_vmovdqu64] = "vmovdqu64",
  [anon_sym_vmovq] = "vmovq",
  [anon_sym_vmovsd] = "vmovsd",
  [anon_sym_vmovss] = "vmovss",
  [anon_sym_vmovups] = "vmovups",
  [anon_sym_vmulsd] = "vmulsd",
  [anon_sym_vpackusdw] = "vpackusdw",
  [anon_sym_vpaddb] = "vpaddb",
  [anon_sym_vpaddd] = "vpaddd",
  [anon_sym_vpaddq] = "vpaddq",
  [anon_sym_vpaddw] = "vpaddw",
  [anon_sym_vpalignr] = "vpalignr",
  [anon_sym_vpand] = "vpand",
  [anon_sym_vpblendd] = "vpblendd",
  [anon_sym_vpblendmd] = "vpblendmd",
  [anon_sym_vpbroadcastd] = "vpbroadcastd",
  [anon_sym_vpbroadcastq] = "vpbroadcastq",
  [anon_sym_vpclmulhqhqdq] = "vpclmulhqhqdq",
  [anon_sym_vpclmulhqlqdq] = "vpclmulhqlqdq",
  [anon_sym_vpclmullqhqdq] = "vpclmullqhqdq",
  [anon_sym_vpclmullqlqdq] = "vpclmullqlqdq",
  [anon_sym_vpcmpgtd] = "vpcmpgtd",
  [anon_sym_vpcmpltud] = "vpcmpltud",
  [anon_sym_vperm2f128] = "vperm2f128",
  [anon_sym_vperm2i128] = "vperm2i128",
  [anon_sym_vpermd] = "vpermd",
  [anon_sym_vpermi2d] = "vpermi2d",
  [anon_sym_vpermq] = "vpermq",
  [anon_sym_vpermt2d] = "vpermt2d",
  [anon_sym_vpextrw] = "vpextrw",
  [anon_sym_vpinsrb] = "vpinsrb",
  [anon_sym_vpinsrd] = "vpinsrd",
  [anon_sym_vpinsrq] = "vpinsrq",
  [anon_sym_vpinsrw] = "vpinsrw",
  [anon_sym_vpmaddubsw] = "vpmaddubsw",
  [anon_sym_vpmaddwd] = "vpmaddwd",
  [anon_sym_vpmullw] = "vpmullw",
  [anon_sym_vpmuludq] = "vpmuludq",
  [anon_sym_vpor] = "vpor",
  [anon_sym_vprord] = "vprord",
  [anon_sym_vprorq] = "vprorq",
  [anon_sym_vpshufb] = "vpshufb",
  [anon_sym_vpshufd] = "vpshufd",
  [anon_sym_vpslld] = "vpslld",
  [anon_sym_vpslldq] = "vpslldq",
  [anon_sym_vpsllq] = "vpsllq",
  [anon_sym_vpsllw] = "vpsllw",
  [anon_sym_vpsrld] = "vpsrld",
  [anon_sym_vpsrldq] = "vpsrldq",
  [anon_sym_vpsrlq] = "vpsrlq",
  [anon_sym_vpsrlw] = "vpsrlw",
  [anon_sym_vpsubd] = "vpsubd",
  [anon_sym_vpsubq] = "vpsubq",
  [anon_sym_vpsubusw] = "vpsubusw",
  [anon_sym_vpsubw] = "vpsubw",
  [anon_sym_vpunpckhdq] = "vpunpckhdq",
  [anon_sym_vpunpckhqdq] = "vpunpckhqdq",
  [anon_sym_vpunpckhwd] = "vpunpckhwd",
  [anon_sym_vpunpckldq] = "vpunpckldq",
  [anon_sym_vpunpcklqdq] = "vpunpcklqdq",
  [anon_sym_vpunpcklwd] = "vpunpcklwd",
  [anon_sym_vpxor] = "vpxor",
  [anon_sym_vpxord] = "vpxord",
  [anon_sym_vshufi32x4] = "vshufi32x4",
  [anon_sym_vshufi64x2] = "vshufi64x2",
  [anon_sym_vshufps] = "vshufps",
  [anon_sym_vsubsd] = "vsubsd",
  [anon_sym_vucomisd] = "vucomisd",
  [anon_sym_vucomiss] = "vucomiss",
  [anon_sym_vunpckhpd] = "vunpckhpd",
  [anon_sym_vunpckhps] = "vunpckhps",
  [anon_sym_vunpcklpd] = "vunpcklpd",
  [anon_sym_vunpcklps] = "vunpcklps",
  [anon_sym_vxorps] = "vxorps",
  [anon_sym_vzeroall] = "vzeroall",
  [anon_sym_vzeroupper] = "vzeroupper",
  [anon_sym_xchg] = "xchg",
  [anon_sym_xgetbv] = "xgetbv",
  [anon_sym_xor] = "xor",
  [anon_sym_xorl] = "xorl",
  [anon_sym_xorpd] = "xorpd",
  [anon_sym_xorps] = "xorps",
  [anon_sym_xorw] = "xorw",
  [anon_sym_COMMA] = ",",
  [anon_sym_] = " ",
  [anon_sym_callq] = "callq",
  [anon_sym_ja] = "ja",
  [anon_sym_jae] = "jae",
  [anon_sym_jb] = "jb",
  [anon_sym_jbe] = "jbe",
  [anon_sym_je] = "je",
  [anon_sym_jg] = "jg",
  [anon_sym_jge] = "jge",
  [anon_sym_jl] = "jl",
  [anon_sym_jle] = "jle",
  [anon_sym_jmp] = "jmp",
  [anon_sym_jmpq] = "jmpq",
  [anon_sym_jne] = "jne",
  [anon_sym_jno] = "jno",
  [anon_sym_jns] = "jns",
  [anon_sym_jo] = "jo",
  [anon_sym_jp] = "jp",
  [anon_sym_jrcxz] = "jrcxz",
  [anon_sym_js] = "js",
  [anon_sym_notrack] = "notrack",
  [aux_sym_address_token1] = "address_token1",
  [aux_sym_operand_token1] = "operand_token1",
  [aux_sym_fn_token1] = "fn_token1",
  [sym_two_bytes] = "two_bytes",
  [sym_prog] = "prog",
  [sym_comment] = "comment",
  [sym__line] = "_line",
  [sym_opcode] = "opcode",
  [sym_instruction] = "instruction",
  [sym_callq] = "callq",
  [sym_address] = "address",
  [sym_operand] = "operand",
  [sym_fn] = "fn",
  [aux_sym_prog_repeat1] = "prog_repeat1",
  [aux_sym__line_repeat1] = "_line_repeat1",
  [aux_sym_instruction_repeat1] = "instruction_repeat1",
  [aux_sym_address_repeat1] = "address_repeat1",
  [aux_sym_operand_repeat1] = "operand_repeat1",
  [aux_sym_fn_repeat1] = "fn_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym__line_break] = sym__line_break,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [aux_sym_comment_token2] = aux_sym_comment_token2,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_adc] = anon_sym_adc,
  [anon_sym_adcx] = anon_sym_adcx,
  [anon_sym_add] = anon_sym_add,
  [anon_sym_addb] = anon_sym_addb,
  [anon_sym_addl] = anon_sym_addl,
  [anon_sym_addq] = anon_sym_addq,
  [anon_sym_addr32] = anon_sym_addr32,
  [anon_sym_addsd] = anon_sym_addsd,
  [anon_sym_addss] = anon_sym_addss,
  [anon_sym_addw] = anon_sym_addw,
  [anon_sym_adox] = anon_sym_adox,
  [anon_sym_aesdec] = anon_sym_aesdec,
  [anon_sym_aesdeclast] = anon_sym_aesdeclast,
  [anon_sym_aesenc] = anon_sym_aesenc,
  [anon_sym_aesenclast] = anon_sym_aesenclast,
  [anon_sym_aeskeygenassist] = anon_sym_aeskeygenassist,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_andb] = anon_sym_andb,
  [anon_sym_andl] = anon_sym_andl,
  [anon_sym_andn] = anon_sym_andn,
  [anon_sym_andpd] = anon_sym_andpd,
  [anon_sym_andps] = anon_sym_andps,
  [anon_sym_andq] = anon_sym_andq,
  [anon_sym_andw] = anon_sym_andw,
  [anon_sym_blendvps] = anon_sym_blendvps,
  [anon_sym_bsf] = anon_sym_bsf,
  [anon_sym_bsr] = anon_sym_bsr,
  [anon_sym_bswap] = anon_sym_bswap,
  [anon_sym_bt] = anon_sym_bt,
  [anon_sym_btl] = anon_sym_btl,
  [anon_sym_btr] = anon_sym_btr,
  [anon_sym_bts] = anon_sym_bts,
  [anon_sym_cbtw] = anon_sym_cbtw,
  [anon_sym_cltd] = anon_sym_cltd,
  [anon_sym_cltq] = anon_sym_cltq,
  [anon_sym_cmova] = anon_sym_cmova,
  [anon_sym_cmovae] = anon_sym_cmovae,
  [anon_sym_cmovb] = anon_sym_cmovb,
  [anon_sym_cmovbe] = anon_sym_cmovbe,
  [anon_sym_cmove] = anon_sym_cmove,
  [anon_sym_cmovg] = anon_sym_cmovg,
  [anon_sym_cmovge] = anon_sym_cmovge,
  [anon_sym_cmovl] = anon_sym_cmovl,
  [anon_sym_cmovle] = anon_sym_cmovle,
  [anon_sym_cmovne] = anon_sym_cmovne,
  [anon_sym_cmovns] = anon_sym_cmovns,
  [anon_sym_cmovo] = anon_sym_cmovo,
  [anon_sym_cmovp] = anon_sym_cmovp,
  [anon_sym_cmovs] = anon_sym_cmovs,
  [anon_sym_cmp] = anon_sym_cmp,
  [anon_sym_cmpb] = anon_sym_cmpb,
  [anon_sym_cmpl] = anon_sym_cmpl,
  [anon_sym_cmpq] = anon_sym_cmpq,
  [anon_sym_cmpw] = anon_sym_cmpw,
  [anon_sym_comisd] = anon_sym_comisd,
  [anon_sym_comiss] = anon_sym_comiss,
  [anon_sym_cpuid] = anon_sym_cpuid,
  [anon_sym_cqto] = anon_sym_cqto,
  [anon_sym_cvtsd2ss] = anon_sym_cvtsd2ss,
  [anon_sym_cvtsi2sd] = anon_sym_cvtsi2sd,
  [anon_sym_cvtsi2sdl] = anon_sym_cvtsi2sdl,
  [anon_sym_cvtsi2sdq] = anon_sym_cvtsi2sdq,
  [anon_sym_cvtsi2ss] = anon_sym_cvtsi2ss,
  [anon_sym_cvtsi2ssl] = anon_sym_cvtsi2ssl,
  [anon_sym_cvtss2sd] = anon_sym_cvtss2sd,
  [anon_sym_cvttsd2si] = anon_sym_cvttsd2si,
  [anon_sym_cvttss2si] = anon_sym_cvttss2si,
  [anon_sym_cwtd] = anon_sym_cwtd,
  [anon_sym_cwtl] = anon_sym_cwtl,
  [anon_sym_data16] = anon_sym_data16,
  [anon_sym_dec] = anon_sym_dec,
  [anon_sym_div] = anon_sym_div,
  [anon_sym_divl] = anon_sym_divl,
  [anon_sym_divq] = anon_sym_divq,
  [anon_sym_divsd] = anon_sym_divsd,
  [anon_sym_divss] = anon_sym_divss,
  [anon_sym_endbr64] = anon_sym_endbr64,
  [anon_sym_femms] = anon_sym_femms,
  [anon_sym_fildl] = anon_sym_fildl,
  [anon_sym_fldt] = anon_sym_fldt,
  [anon_sym_fmulp] = anon_sym_fmulp,
  [anon_sym_fs] = anon_sym_fs,
  [anon_sym_fstpl] = anon_sym_fstpl,
  [anon_sym_gs] = anon_sym_gs,
  [anon_sym_idiv] = anon_sym_idiv,
  [anon_sym_idivl] = anon_sym_idivl,
  [anon_sym_imul] = anon_sym_imul,
  [anon_sym_inc] = anon_sym_inc,
  [anon_sym_incl] = anon_sym_incl,
  [anon_sym_insb] = anon_sym_insb,
  [anon_sym_insl] = anon_sym_insl,
  [anon_sym_kmovw] = anon_sym_kmovw,
  [anon_sym_knotw] = anon_sym_knotw,
  [anon_sym_lea] = anon_sym_lea,
  [anon_sym_leaveq] = anon_sym_leaveq,
  [anon_sym_lock] = anon_sym_lock,
  [anon_sym_maxsd] = anon_sym_maxsd,
  [anon_sym_maxss] = anon_sym_maxss,
  [anon_sym_mfence] = anon_sym_mfence,
  [anon_sym_minsd] = anon_sym_minsd,
  [anon_sym_minss] = anon_sym_minss,
  [anon_sym_mov] = anon_sym_mov,
  [anon_sym_movabs] = anon_sym_movabs,
  [anon_sym_movapd] = anon_sym_movapd,
  [anon_sym_movaps] = anon_sym_movaps,
  [anon_sym_movb] = anon_sym_movb,
  [anon_sym_movbe] = anon_sym_movbe,
  [anon_sym_movd] = anon_sym_movd,
  [anon_sym_movdqa] = anon_sym_movdqa,
  [anon_sym_movdqu] = anon_sym_movdqu,
  [anon_sym_movhlps] = anon_sym_movhlps,
  [anon_sym_movhps] = anon_sym_movhps,
  [anon_sym_movl] = anon_sym_movl,
  [anon_sym_movq] = anon_sym_movq,
  [anon_sym_movsb] = anon_sym_movsb,
  [anon_sym_movsbl] = anon_sym_movsbl,
  [anon_sym_movsbq] = anon_sym_movsbq,
  [anon_sym_movsbw] = anon_sym_movsbw,
  [anon_sym_movsd] = anon_sym_movsd,
  [anon_sym_movslq] = anon_sym_movslq,
  [anon_sym_movss] = anon_sym_movss,
  [anon_sym_movswl] = anon_sym_movswl,
  [anon_sym_movswq] = anon_sym_movswq,
  [anon_sym_movups] = anon_sym_movups,
  [anon_sym_movw] = anon_sym_movw,
  [anon_sym_movzbl] = anon_sym_movzbl,
  [anon_sym_movzbq] = anon_sym_movzbq,
  [anon_sym_movzbw] = anon_sym_movzbw,
  [anon_sym_movzwl] = anon_sym_movzwl,
  [anon_sym_mul] = anon_sym_mul,
  [anon_sym_mulb] = anon_sym_mulb,
  [anon_sym_mull] = anon_sym_mull,
  [anon_sym_mulq] = anon_sym_mulq,
  [anon_sym_mulsd] = anon_sym_mulsd,
  [anon_sym_mulss] = anon_sym_mulss,
  [anon_sym_mulw] = anon_sym_mulw,
  [anon_sym_mulx] = anon_sym_mulx,
  [anon_sym_neg] = anon_sym_neg,
  [anon_sym_negl] = anon_sym_negl,
  [anon_sym_negq] = anon_sym_negq,
  [anon_sym_nop] = anon_sym_nop,
  [anon_sym_nopl] = anon_sym_nopl,
  [anon_sym_nopw] = anon_sym_nopw,
  [anon_sym_not] = anon_sym_not,
  [anon_sym_notl] = anon_sym_notl,
  [anon_sym_notw] = anon_sym_notw,
  [anon_sym_or] = anon_sym_or,
  [anon_sym_orb] = anon_sym_orb,
  [anon_sym_orl] = anon_sym_orl,
  [anon_sym_orq] = anon_sym_orq,
  [anon_sym_orw] = anon_sym_orw,
  [anon_sym_outsb] = anon_sym_outsb,
  [anon_sym_outsl] = anon_sym_outsl,
  [anon_sym_packuswb] = anon_sym_packuswb,
  [anon_sym_paddd] = anon_sym_paddd,
  [anon_sym_paddq] = anon_sym_paddq,
  [anon_sym_paddw] = anon_sym_paddw,
  [anon_sym_palignr] = anon_sym_palignr,
  [anon_sym_pand] = anon_sym_pand,
  [anon_sym_pandn] = anon_sym_pandn,
  [anon_sym_pblendw] = anon_sym_pblendw,
  [anon_sym_pclmulhqhqdq] = anon_sym_pclmulhqhqdq,
  [anon_sym_pclmullqhqdq] = anon_sym_pclmullqhqdq,
  [anon_sym_pclmullqlqdq] = anon_sym_pclmullqlqdq,
  [anon_sym_pcmpeqb] = anon_sym_pcmpeqb,
  [anon_sym_pcmpeqd] = anon_sym_pcmpeqd,
  [anon_sym_pcmpgtd] = anon_sym_pcmpgtd,
  [anon_sym_pextrb] = anon_sym_pextrb,
  [anon_sym_pextrq] = anon_sym_pextrq,
  [anon_sym_pextrw] = anon_sym_pextrw,
  [anon_sym_pinsrb] = anon_sym_pinsrb,
  [anon_sym_pinsrd] = anon_sym_pinsrd,
  [anon_sym_pinsrw] = anon_sym_pinsrw,
  [anon_sym_pmaddubsw] = anon_sym_pmaddubsw,
  [anon_sym_pmaddwd] = anon_sym_pmaddwd,
  [anon_sym_pmovmskb] = anon_sym_pmovmskb,
  [anon_sym_pmuludq] = anon_sym_pmuludq,
  [anon_sym_pop] = anon_sym_pop,
  [anon_sym_popcnt] = anon_sym_popcnt,
  [anon_sym_por] = anon_sym_por,
  [anon_sym_prefetcht0] = anon_sym_prefetcht0,
  [anon_sym_prefetcht1] = anon_sym_prefetcht1,
  [anon_sym_pshufb] = anon_sym_pshufb,
  [anon_sym_pshufd] = anon_sym_pshufd,
  [anon_sym_pshufhw] = anon_sym_pshufhw,
  [anon_sym_pshuflw] = anon_sym_pshuflw,
  [anon_sym_pslld] = anon_sym_pslld,
  [anon_sym_pslldq] = anon_sym_pslldq,
  [anon_sym_psllq] = anon_sym_psllq,
  [anon_sym_psrad] = anon_sym_psrad,
  [anon_sym_psrld] = anon_sym_psrld,
  [anon_sym_psrldq] = anon_sym_psrldq,
  [anon_sym_psrlq] = anon_sym_psrlq,
  [anon_sym_psrlw] = anon_sym_psrlw,
  [anon_sym_psubb] = anon_sym_psubb,
  [anon_sym_psubd] = anon_sym_psubd,
  [anon_sym_psubq] = anon_sym_psubq,
  [anon_sym_psubusb] = anon_sym_psubusb,
  [anon_sym_psubusw] = anon_sym_psubusw,
  [anon_sym_punpckhbw] = anon_sym_punpckhbw,
  [anon_sym_punpckhdq] = anon_sym_punpckhdq,
  [anon_sym_punpckhqdq] = anon_sym_punpckhqdq,
  [anon_sym_punpckhwd] = anon_sym_punpckhwd,
  [anon_sym_punpcklbw] = anon_sym_punpcklbw,
  [anon_sym_punpckldq] = anon_sym_punpckldq,
  [anon_sym_punpcklqdq] = anon_sym_punpcklqdq,
  [anon_sym_punpcklwd] = anon_sym_punpcklwd,
  [anon_sym_push] = anon_sym_push,
  [anon_sym_pushq] = anon_sym_pushq,
  [anon_sym_pxor] = anon_sym_pxor,
  [anon_sym_re] = anon_sym_re,
  [anon_sym_rep] = anon_sym_rep,
  [anon_sym_repnz] = anon_sym_repnz,
  [anon_sym_repz] = anon_sym_repz,
  [anon_sym_retq] = anon_sym_retq,
  [anon_sym_rex] = anon_sym_rex,
  [anon_sym_rex_DOTB] = anon_sym_rex_DOTB,
  [anon_sym_rex_DOTRB] = anon_sym_rex_DOTRB,
  [anon_sym_rex_DOTRXB] = anon_sym_rex_DOTRXB,
  [anon_sym_rex_DOTW] = anon_sym_rex_DOTW,
  [anon_sym_rex_DOTWB] = anon_sym_rex_DOTWB,
  [anon_sym_rex_DOTWRB] = anon_sym_rex_DOTWRB,
  [anon_sym_rex_DOTWRXB] = anon_sym_rex_DOTWRXB,
  [anon_sym_rex_DOTXB] = anon_sym_rex_DOTXB,
  [anon_sym_rol] = anon_sym_rol,
  [anon_sym_roll] = anon_sym_roll,
  [anon_sym_ror] = anon_sym_ror,
  [anon_sym_rorl] = anon_sym_rorl,
  [anon_sym_rorx] = anon_sym_rorx,
  [anon_sym_sar] = anon_sym_sar,
  [anon_sym_sarl] = anon_sym_sarl,
  [anon_sym_sarx] = anon_sym_sarx,
  [anon_sym_sbb] = anon_sym_sbb,
  [anon_sym_seta] = anon_sym_seta,
  [anon_sym_setae] = anon_sym_setae,
  [anon_sym_setb] = anon_sym_setb,
  [anon_sym_setbe] = anon_sym_setbe,
  [anon_sym_sete] = anon_sym_sete,
  [anon_sym_setg] = anon_sym_setg,
  [anon_sym_setge] = anon_sym_setge,
  [anon_sym_setl] = anon_sym_setl,
  [anon_sym_setle] = anon_sym_setle,
  [anon_sym_setne] = anon_sym_setne,
  [anon_sym_setnp] = anon_sym_setnp,
  [anon_sym_setns] = anon_sym_setns,
  [anon_sym_seto] = anon_sym_seto,
  [anon_sym_setp] = anon_sym_setp,
  [anon_sym_sha1msg1] = anon_sym_sha1msg1,
  [anon_sym_sha1msg2] = anon_sym_sha1msg2,
  [anon_sym_sha1nexte] = anon_sym_sha1nexte,
  [anon_sym_sha1rnds4] = anon_sym_sha1rnds4,
  [anon_sym_shl] = anon_sym_shl,
  [anon_sym_shld] = anon_sym_shld,
  [anon_sym_shll] = anon_sym_shll,
  [anon_sym_shlq] = anon_sym_shlq,
  [anon_sym_shlx] = anon_sym_shlx,
  [anon_sym_shr] = anon_sym_shr,
  [anon_sym_shrd] = anon_sym_shrd,
  [anon_sym_shrl] = anon_sym_shrl,
  [anon_sym_shrq] = anon_sym_shrq,
  [anon_sym_shrx] = anon_sym_shrx,
  [anon_sym_shufpd] = anon_sym_shufpd,
  [anon_sym_shufps] = anon_sym_shufps,
  [anon_sym_ss] = anon_sym_ss,
  [anon_sym_sub] = anon_sym_sub,
  [anon_sym_subb] = anon_sym_subb,
  [anon_sym_subl] = anon_sym_subl,
  [anon_sym_subpd] = anon_sym_subpd,
  [anon_sym_subq] = anon_sym_subq,
  [anon_sym_subsd] = anon_sym_subsd,
  [anon_sym_subss] = anon_sym_subss,
  [anon_sym_subw] = anon_sym_subw,
  [anon_sym_test] = anon_sym_test,
  [anon_sym_testb] = anon_sym_testb,
  [anon_sym_testl] = anon_sym_testl,
  [anon_sym_tzcnt] = anon_sym_tzcnt,
  [anon_sym_ucomisd] = anon_sym_ucomisd,
  [anon_sym_ucomiss] = anon_sym_ucomiss,
  [anon_sym_ud2] = anon_sym_ud2,
  [anon_sym_unpckhpd] = anon_sym_unpckhpd,
  [anon_sym_vaesenc] = anon_sym_vaesenc,
  [anon_sym_vaesenclast] = anon_sym_vaesenclast,
  [anon_sym_vblendps] = anon_sym_vblendps,
  [anon_sym_vblendvps] = anon_sym_vblendvps,
  [anon_sym_vbroadcasti128] = anon_sym_vbroadcasti128,
  [anon_sym_vbroadcasti32x4] = anon_sym_vbroadcasti32x4,
  [anon_sym_vbroadcastss] = anon_sym_vbroadcastss,
  [anon_sym_vcvtusi2sd] = anon_sym_vcvtusi2sd,
  [anon_sym_vdivsd] = anon_sym_vdivsd,
  [anon_sym_vextracti128] = anon_sym_vextracti128,
  [anon_sym_vextracti32x4] = anon_sym_vextracti32x4,
  [anon_sym_vinsertf128] = anon_sym_vinsertf128,
  [anon_sym_vinserti128] = anon_sym_vinserti128,
  [anon_sym_vinserti32x4] = anon_sym_vinserti32x4,
  [anon_sym_vinserti64x4] = anon_sym_vinserti64x4,
  [anon_sym_vmovapd] = anon_sym_vmovapd,
  [anon_sym_vmovaps] = anon_sym_vmovaps,
  [anon_sym_vmovd] = anon_sym_vmovd,
  [anon_sym_vmovdqa] = anon_sym_vmovdqa,
  [anon_sym_vmovdqa32] = anon_sym_vmovdqa32,
  [anon_sym_vmovdqa64] = anon_sym_vmovdqa64,
  [anon_sym_vmovdqu] = anon_sym_vmovdqu,
  [anon_sym_vmovdqu32] = anon_sym_vmovdqu32,
  [anon_sym_vmovdqu64] = anon_sym_vmovdqu64,
  [anon_sym_vmovq] = anon_sym_vmovq,
  [anon_sym_vmovsd] = anon_sym_vmovsd,
  [anon_sym_vmovss] = anon_sym_vmovss,
  [anon_sym_vmovups] = anon_sym_vmovups,
  [anon_sym_vmulsd] = anon_sym_vmulsd,
  [anon_sym_vpackusdw] = anon_sym_vpackusdw,
  [anon_sym_vpaddb] = anon_sym_vpaddb,
  [anon_sym_vpaddd] = anon_sym_vpaddd,
  [anon_sym_vpaddq] = anon_sym_vpaddq,
  [anon_sym_vpaddw] = anon_sym_vpaddw,
  [anon_sym_vpalignr] = anon_sym_vpalignr,
  [anon_sym_vpand] = anon_sym_vpand,
  [anon_sym_vpblendd] = anon_sym_vpblendd,
  [anon_sym_vpblendmd] = anon_sym_vpblendmd,
  [anon_sym_vpbroadcastd] = anon_sym_vpbroadcastd,
  [anon_sym_vpbroadcastq] = anon_sym_vpbroadcastq,
  [anon_sym_vpclmulhqhqdq] = anon_sym_vpclmulhqhqdq,
  [anon_sym_vpclmulhqlqdq] = anon_sym_vpclmulhqlqdq,
  [anon_sym_vpclmullqhqdq] = anon_sym_vpclmullqhqdq,
  [anon_sym_vpclmullqlqdq] = anon_sym_vpclmullqlqdq,
  [anon_sym_vpcmpgtd] = anon_sym_vpcmpgtd,
  [anon_sym_vpcmpltud] = anon_sym_vpcmpltud,
  [anon_sym_vperm2f128] = anon_sym_vperm2f128,
  [anon_sym_vperm2i128] = anon_sym_vperm2i128,
  [anon_sym_vpermd] = anon_sym_vpermd,
  [anon_sym_vpermi2d] = anon_sym_vpermi2d,
  [anon_sym_vpermq] = anon_sym_vpermq,
  [anon_sym_vpermt2d] = anon_sym_vpermt2d,
  [anon_sym_vpextrw] = anon_sym_vpextrw,
  [anon_sym_vpinsrb] = anon_sym_vpinsrb,
  [anon_sym_vpinsrd] = anon_sym_vpinsrd,
  [anon_sym_vpinsrq] = anon_sym_vpinsrq,
  [anon_sym_vpinsrw] = anon_sym_vpinsrw,
  [anon_sym_vpmaddubsw] = anon_sym_vpmaddubsw,
  [anon_sym_vpmaddwd] = anon_sym_vpmaddwd,
  [anon_sym_vpmullw] = anon_sym_vpmullw,
  [anon_sym_vpmuludq] = anon_sym_vpmuludq,
  [anon_sym_vpor] = anon_sym_vpor,
  [anon_sym_vprord] = anon_sym_vprord,
  [anon_sym_vprorq] = anon_sym_vprorq,
  [anon_sym_vpshufb] = anon_sym_vpshufb,
  [anon_sym_vpshufd] = anon_sym_vpshufd,
  [anon_sym_vpslld] = anon_sym_vpslld,
  [anon_sym_vpslldq] = anon_sym_vpslldq,
  [anon_sym_vpsllq] = anon_sym_vpsllq,
  [anon_sym_vpsllw] = anon_sym_vpsllw,
  [anon_sym_vpsrld] = anon_sym_vpsrld,
  [anon_sym_vpsrldq] = anon_sym_vpsrldq,
  [anon_sym_vpsrlq] = anon_sym_vpsrlq,
  [anon_sym_vpsrlw] = anon_sym_vpsrlw,
  [anon_sym_vpsubd] = anon_sym_vpsubd,
  [anon_sym_vpsubq] = anon_sym_vpsubq,
  [anon_sym_vpsubusw] = anon_sym_vpsubusw,
  [anon_sym_vpsubw] = anon_sym_vpsubw,
  [anon_sym_vpunpckhdq] = anon_sym_vpunpckhdq,
  [anon_sym_vpunpckhqdq] = anon_sym_vpunpckhqdq,
  [anon_sym_vpunpckhwd] = anon_sym_vpunpckhwd,
  [anon_sym_vpunpckldq] = anon_sym_vpunpckldq,
  [anon_sym_vpunpcklqdq] = anon_sym_vpunpcklqdq,
  [anon_sym_vpunpcklwd] = anon_sym_vpunpcklwd,
  [anon_sym_vpxor] = anon_sym_vpxor,
  [anon_sym_vpxord] = anon_sym_vpxord,
  [anon_sym_vshufi32x4] = anon_sym_vshufi32x4,
  [anon_sym_vshufi64x2] = anon_sym_vshufi64x2,
  [anon_sym_vshufps] = anon_sym_vshufps,
  [anon_sym_vsubsd] = anon_sym_vsubsd,
  [anon_sym_vucomisd] = anon_sym_vucomisd,
  [anon_sym_vucomiss] = anon_sym_vucomiss,
  [anon_sym_vunpckhpd] = anon_sym_vunpckhpd,
  [anon_sym_vunpckhps] = anon_sym_vunpckhps,
  [anon_sym_vunpcklpd] = anon_sym_vunpcklpd,
  [anon_sym_vunpcklps] = anon_sym_vunpcklps,
  [anon_sym_vxorps] = anon_sym_vxorps,
  [anon_sym_vzeroall] = anon_sym_vzeroall,
  [anon_sym_vzeroupper] = anon_sym_vzeroupper,
  [anon_sym_xchg] = anon_sym_xchg,
  [anon_sym_xgetbv] = anon_sym_xgetbv,
  [anon_sym_xor] = anon_sym_xor,
  [anon_sym_xorl] = anon_sym_xorl,
  [anon_sym_xorpd] = anon_sym_xorpd,
  [anon_sym_xorps] = anon_sym_xorps,
  [anon_sym_xorw] = anon_sym_xorw,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_] = anon_sym_,
  [anon_sym_callq] = anon_sym_callq,
  [anon_sym_ja] = anon_sym_ja,
  [anon_sym_jae] = anon_sym_jae,
  [anon_sym_jb] = anon_sym_jb,
  [anon_sym_jbe] = anon_sym_jbe,
  [anon_sym_je] = anon_sym_je,
  [anon_sym_jg] = anon_sym_jg,
  [anon_sym_jge] = anon_sym_jge,
  [anon_sym_jl] = anon_sym_jl,
  [anon_sym_jle] = anon_sym_jle,
  [anon_sym_jmp] = anon_sym_jmp,
  [anon_sym_jmpq] = anon_sym_jmpq,
  [anon_sym_jne] = anon_sym_jne,
  [anon_sym_jno] = anon_sym_jno,
  [anon_sym_jns] = anon_sym_jns,
  [anon_sym_jo] = anon_sym_jo,
  [anon_sym_jp] = anon_sym_jp,
  [anon_sym_jrcxz] = anon_sym_jrcxz,
  [anon_sym_js] = anon_sym_js,
  [anon_sym_notrack] = anon_sym_notrack,
  [aux_sym_address_token1] = aux_sym_address_token1,
  [aux_sym_operand_token1] = aux_sym_operand_token1,
  [aux_sym_fn_token1] = aux_sym_fn_token1,
  [sym_two_bytes] = sym_two_bytes,
  [sym_prog] = sym_prog,
  [sym_comment] = sym_comment,
  [sym__line] = sym__line,
  [sym_opcode] = sym_opcode,
  [sym_instruction] = sym_instruction,
  [sym_callq] = sym_callq,
  [sym_address] = sym_address,
  [sym_operand] = sym_operand,
  [sym_fn] = sym_fn,
  [aux_sym_prog_repeat1] = aux_sym_prog_repeat1,
  [aux_sym__line_repeat1] = aux_sym__line_repeat1,
  [aux_sym_instruction_repeat1] = aux_sym_instruction_repeat1,
  [aux_sym_address_repeat1] = aux_sym_address_repeat1,
  [aux_sym_operand_repeat1] = aux_sym_operand_repeat1,
  [aux_sym_fn_repeat1] = aux_sym_fn_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym__line_break] = {
    .visible = false,
    .named = true,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_token2] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_adc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_adcx] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_add] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_addb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_addl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_addq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_addr32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_addsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_addss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_addw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_adox] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_aesdec] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_aesdeclast] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_aesenc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_aesenclast] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_aeskeygenassist] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_andb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_andl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_andn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_andpd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_andps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_andq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_andw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_blendvps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bsf] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bsr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bswap] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_btl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_btr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bts] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cbtw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cltd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cltq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmova] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovae] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovbe] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmove] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovge] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovle] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovne] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovns] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovo] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmovs] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmpb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmpl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmpq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cmpw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_comisd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_comiss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cpuid] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cqto] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvtsd2ss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvtsi2sd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvtsi2sdl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvtsi2sdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvtsi2ss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvtsi2ssl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvtss2sd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvttsd2si] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cvttss2si] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cwtd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cwtl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_data16] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_dec] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_div] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_divl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_divq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_divsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_divss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_endbr64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_femms] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fildl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fldt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fmulp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fs] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fstpl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_gs] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_idiv] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_idivl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_imul] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_inc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_incl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_insb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_insl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_kmovw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_knotw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_lea] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_leaveq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_lock] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_maxsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_maxss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mfence] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_minsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_minss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mov] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movabs] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movapd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movaps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movbe] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movdqa] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movdqu] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movhlps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movhps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movsb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movsbl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movsbq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movsbw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movslq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movswl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movswq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movups] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movzbl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movzbq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movzbw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_movzwl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mul] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mulb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mull] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mulq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mulsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mulss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mulw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mulx] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_neg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_negl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_negq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nopl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_nopw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_not] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_notl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_notw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_orb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_orl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_orq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_orw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_outsb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_outsl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_packuswb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_paddd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_paddq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_paddw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_palignr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pand] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pandn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pblendw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pclmulhqhqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pclmullqhqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pclmullqlqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pcmpeqb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pcmpeqd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pcmpgtd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pextrb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pextrq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pextrw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pinsrb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pinsrd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pinsrw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pmaddubsw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pmaddwd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pmovmskb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pmuludq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_popcnt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_por] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_prefetcht0] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_prefetcht1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pshufb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pshufd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pshufhw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pshuflw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pslld] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pslldq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psllq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psrad] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psrld] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psrldq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psrlq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psrlw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psubb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psubd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psubq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psubusb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_psubusw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_punpckhbw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_punpckhdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_punpckhqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_punpckhwd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_punpcklbw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_punpckldq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_punpcklqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_punpcklwd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_push] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pushq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pxor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_re] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rep] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_repnz] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_repz] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_retq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex_DOTB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex_DOTRB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex_DOTRXB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex_DOTW] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex_DOTWB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex_DOTWRB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex_DOTWRXB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rex_DOTXB] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rol] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_roll] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ror] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rorl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_rorx] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sar] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sarl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sarx] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sbb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_seta] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setae] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setbe] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sete] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setge] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setle] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setne] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setnp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setns] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_seto] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_setp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sha1msg1] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sha1msg2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sha1nexte] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sha1rnds4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shld] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shll] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shlq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shlx] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shrd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shrl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shrq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shrx] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shufpd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_shufps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sub] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_subb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_subl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_subpd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_subq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_subsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_subss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_subw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_test] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_testb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_testl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_tzcnt] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ucomisd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ucomiss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ud2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_unpckhpd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vaesenc] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vaesenclast] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vblendps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vblendvps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vbroadcasti128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vbroadcasti32x4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vbroadcastss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vcvtusi2sd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vdivsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vextracti128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vextracti32x4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vinsertf128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vinserti128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vinserti32x4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vinserti64x4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovapd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovaps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovdqa] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovdqa32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovdqa64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovdqu] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovdqu32] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovdqu64] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmovups] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vmulsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpackusdw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpaddb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpaddd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpaddq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpaddw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpalignr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpand] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpblendd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpblendmd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpbroadcastd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpbroadcastq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpclmulhqhqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpclmulhqlqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpclmullqhqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpclmullqlqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpcmpgtd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpcmpltud] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vperm2f128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vperm2i128] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpermd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpermi2d] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpermq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpermt2d] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpextrw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpinsrb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpinsrd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpinsrq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpinsrw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpmaddubsw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpmaddwd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpmullw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpmuludq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vprord] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vprorq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpshufb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpshufd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpslld] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpslldq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsllq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsllw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsrld] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsrldq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsrlq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsrlw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsubd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsubq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsubusw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpsubw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpunpckhdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpunpckhqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpunpckhwd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpunpckldq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpunpcklqdq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpunpcklwd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpxor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vpxord] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vshufi32x4] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vshufi64x2] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vshufps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vsubsd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vucomisd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vucomiss] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vunpckhpd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vunpckhps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vunpcklpd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vunpcklps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vxorps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vzeroall] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_vzeroupper] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xchg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xgetbv] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xor] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xorl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xorpd] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xorps] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_xorw] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_callq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ja] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jae] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jb] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jbe] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_je] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jge] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jle] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jmp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jmpq] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jne] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jno] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jns] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jo] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jp] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_jrcxz] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_js] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_notrack] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_address_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_operand_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_fn_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_two_bytes] = {
    .visible = true,
    .named = true,
  },
  [sym_prog] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__line] = {
    .visible = false,
    .named = true,
  },
  [sym_opcode] = {
    .visible = true,
    .named = true,
  },
  [sym_instruction] = {
    .visible = true,
    .named = true,
  },
  [sym_callq] = {
    .visible = true,
    .named = true,
  },
  [sym_address] = {
    .visible = true,
    .named = true,
  },
  [sym_operand] = {
    .visible = true,
    .named = true,
  },
  [sym_fn] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_prog_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__line_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_instruction_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_address_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_operand_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_fn_repeat1] = {
    .visible = false,
    .named = false,
  },
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 7,
  [21] = 5,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
};

static inline bool aux_sym_fn_token1_character_set_1(int32_t c) {
  return (c < 'A'
    ? (c < '.'
      ? (c < '('
        ? (c >= '$' && c <= '&')
        : c <= ',')
      : (c <= '.' || (c >= '0' && c <= '>')))
    : (c <= '[' || (c < 'a'
      ? (c < '_'
        ? c == ']'
        : c <= '_')
      : (c <= '{' || c == '}'))));
}

static inline bool aux_sym_fn_token1_character_set_2(int32_t c) {
  return (c < 'A'
    ? (c < '.'
      ? (c < '('
        ? (c >= '$' && c <= '&')
        : c <= ',')
      : (c <= '.' || (c < '>'
        ? (c >= '0' && c <= '<')
        : c <= '>')))
    : (c <= '[' || (c < 'a'
      ? (c < '_'
        ? c == ']'
        : c <= '_')
      : (c <= '{' || c == '}'))));
}

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(618);
      if (lookahead == '#') ADVANCE(621);
      if (lookahead == ',') ADVANCE(1010);
      if (lookahead == ':') ADVANCE(623);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == '-' ||
          lookahead == '/') ADVANCE(1034);
      if (lookahead == '&' ||
          lookahead == ';' ||
          lookahead == '[' ||
          lookahead == ']') ADVANCE(1035);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(1033);
      if (lookahead == '$' ||
          lookahead == '%' ||
          ('(' <= lookahead && lookahead <= '>') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('g' <= lookahead && lookahead <= '{') ||
          lookahead == '}') ADVANCE(1034);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(619);
      if (lookahead == '#') ADVANCE(621);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == 'a') ADVANCE(149);
      if (lookahead == 'b') ADVANCE(323);
      if (lookahead == 'c') ADVANCE(69);
      if (lookahead == 'd') ADVANCE(80);
      if (lookahead == 'e') ADVANCE(362);
      if (lookahead == 'f') ADVANCE(239);
      if (lookahead == 'g') ADVANCE(475);
      if (lookahead == 'i') ADVANCE(150);
      if (lookahead == 'j') ADVANCE(70);
      if (lookahead == 'k') ADVANCE(352);
      if (lookahead == 'l') ADVANCE(240);
      if (lookahead == 'm') ADVANCE(71);
      if (lookahead == 'n') ADVANCE(241);
      if (lookahead == 'o') ADVANCE(455);
      if (lookahead == 'p') ADVANCE(72);
      if (lookahead == 'r') ADVANCE(242);
      if (lookahead == 's') ADVANCE(73);
      if (lookahead == 't') ADVANCE(250);
      if (lookahead == 'u') ADVANCE(135);
      if (lookahead == 'v') ADVANCE(82);
      if (lookahead == 'x') ADVANCE(127);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(1)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(616);
      END_STATE();
    case 2:
      if (lookahead == '\n') ADVANCE(619);
      if (lookahead == '#') ADVANCE(621);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (lookahead == '$' ||
          lookahead == '%' ||
          ('(' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '>') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= '{') ||
          lookahead == '}') ADVANCE(1034);
      END_STATE();
    case 3:
      if (lookahead == '\n') ADVANCE(619);
      if (lookahead == '#') ADVANCE(621);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (aux_sym_fn_token1_character_set_1(lookahead)) ADVANCE(1035);
      END_STATE();
    case 4:
      if (lookahead == '\n') ADVANCE(620);
      if (lookahead == ' ') ADVANCE(1011);
      if (lookahead == '#') ADVANCE(621);
      if (lookahead == ',') ADVANCE(1010);
      if (lookahead == '=') ADVANCE(62);
      if (lookahead == '\t' ||
          lookahead == '\r') SKIP(4)
      if (lookahead == '$' ||
          lookahead == '%' ||
          ('(' <= lookahead && lookahead <= ':') ||
          ('<' <= lookahead && lookahead <= '>') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= '{') ||
          lookahead == '}') ADVANCE(1034);
      END_STATE();
    case 5:
      if (lookahead == ' ') ADVANCE(1012);
      if (lookahead == ',') ADVANCE(1010);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r') SKIP(5)
      if (lookahead == '$' ||
          lookahead == '%' ||
          ('(' <= lookahead && lookahead <= ':') ||
          lookahead == '<' ||
          lookahead == '>' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= '{') ||
          lookahead == '}') ADVANCE(1034);
      END_STATE();
    case 6:
      if (lookahead == '0') ADVANCE(804);
      if (lookahead == '1') ADVANCE(805);
      END_STATE();
    case 7:
      if (lookahead == '1') ADVANCE(357);
      END_STATE();
    case 8:
      if (lookahead == '1') ADVANCE(53);
      END_STATE();
    case 9:
      if (lookahead == '1') ADVANCE(871);
      if (lookahead == '2') ADVANCE(872);
      END_STATE();
    case 10:
      if (lookahead == '1') ADVANCE(21);
      END_STATE();
    case 11:
      if (lookahead == '1') ADVANCE(23);
      END_STATE();
    case 12:
      if (lookahead == '1') ADVANCE(24);
      END_STATE();
    case 13:
      if (lookahead == '1') ADVANCE(25);
      if (lookahead == '3') ADVANCE(34);
      if (lookahead == '6') ADVANCE(52);
      END_STATE();
    case 14:
      if (lookahead == '1') ADVANCE(27);
      if (lookahead == '3') ADVANCE(35);
      END_STATE();
    case 15:
      if (lookahead == '1') ADVANCE(28);
      if (lookahead == '3') ADVANCE(37);
      END_STATE();
    case 16:
      if (lookahead == '2') ADVANCE(902);
      END_STATE();
    case 17:
      if (lookahead == '2') ADVANCE(630);
      END_STATE();
    case 18:
      if (lookahead == '2') ADVANCE(272);
      if (lookahead == 'd') ADVANCE(952);
      if (lookahead == 'i') ADVANCE(32);
      if (lookahead == 'q') ADVANCE(954);
      if (lookahead == 't') ADVANCE(33);
      END_STATE();
    case 19:
      if (lookahead == '2') ADVANCE(923);
      END_STATE();
    case 20:
      if (lookahead == '2') ADVANCE(926);
      END_STATE();
    case 21:
      if (lookahead == '2') ADVANCE(55);
      END_STATE();
    case 22:
      if (lookahead == '2') ADVANCE(991);
      END_STATE();
    case 23:
      if (lookahead == '2') ADVANCE(56);
      END_STATE();
    case 24:
      if (lookahead == '2') ADVANCE(57);
      END_STATE();
    case 25:
      if (lookahead == '2') ADVANCE(58);
      END_STATE();
    case 26:
      if (lookahead == '2') ADVANCE(603);
      END_STATE();
    case 27:
      if (lookahead == '2') ADVANCE(59);
      END_STATE();
    case 28:
      if (lookahead == '2') ADVANCE(60);
      END_STATE();
    case 29:
      if (lookahead == '2') ADVANCE(517);
      END_STATE();
    case 30:
      if (lookahead == '2') ADVANCE(498);
      END_STATE();
    case 31:
      if (lookahead == '2') ADVANCE(499);
      END_STATE();
    case 32:
      if (lookahead == '2') ADVANCE(195);
      END_STATE();
    case 33:
      if (lookahead == '2') ADVANCE(196);
      END_STATE();
    case 34:
      if (lookahead == '2') ADVANCE(604);
      END_STATE();
    case 35:
      if (lookahead == '2') ADVANCE(607);
      END_STATE();
    case 36:
      if (lookahead == '2') ADVANCE(521);
      END_STATE();
    case 37:
      if (lookahead == '2') ADVANCE(608);
      END_STATE();
    case 38:
      if (lookahead == '2') ADVANCE(511);
      END_STATE();
    case 39:
      if (lookahead == '2') ADVANCE(525);
      END_STATE();
    case 40:
      if (lookahead == '3') ADVANCE(17);
      END_STATE();
    case 41:
      if (lookahead == '3') ADVANCE(26);
      if (lookahead == '6') ADVANCE(51);
      END_STATE();
    case 42:
      if (lookahead == '4') ADVANCE(700);
      END_STATE();
    case 43:
      if (lookahead == '4') ADVANCE(874);
      END_STATE();
    case 44:
      if (lookahead == '4') ADVANCE(924);
      END_STATE();
    case 45:
      if (lookahead == '4') ADVANCE(927);
      END_STATE();
    case 46:
      if (lookahead == '4') ADVANCE(990);
      END_STATE();
    case 47:
      if (lookahead == '4') ADVANCE(917);
      END_STATE();
    case 48:
      if (lookahead == '4') ADVANCE(918);
      END_STATE();
    case 49:
      if (lookahead == '4') ADVANCE(914);
      END_STATE();
    case 50:
      if (lookahead == '4') ADVANCE(909);
      END_STATE();
    case 51:
      if (lookahead == '4') ADVANCE(610);
      END_STATE();
    case 52:
      if (lookahead == '4') ADVANCE(605);
      END_STATE();
    case 53:
      if (lookahead == '6') ADVANCE(693);
      END_STATE();
    case 54:
      if (lookahead == '6') ADVANCE(42);
      END_STATE();
    case 55:
      if (lookahead == '8') ADVANCE(950);
      END_STATE();
    case 56:
      if (lookahead == '8') ADVANCE(951);
      END_STATE();
    case 57:
      if (lookahead == '8') ADVANCE(915);
      END_STATE();
    case 58:
      if (lookahead == '8') ADVANCE(916);
      END_STATE();
    case 59:
      if (lookahead == '8') ADVANCE(913);
      END_STATE();
    case 60:
      if (lookahead == '8') ADVANCE(908);
      END_STATE();
    case 61:
      if (lookahead == '=') ADVANCE(622);
      END_STATE();
    case 62:
      if (lookahead == '=') ADVANCE(61);
      END_STATE();
    case 63:
      if (lookahead == 'B') ADVANCE(840);
      if (lookahead == 'R') ADVANCE(64);
      if (lookahead == 'W') ADVANCE(843);
      if (lookahead == 'X') ADVANCE(65);
      END_STATE();
    case 64:
      if (lookahead == 'B') ADVANCE(841);
      if (lookahead == 'X') ADVANCE(66);
      END_STATE();
    case 65:
      if (lookahead == 'B') ADVANCE(847);
      END_STATE();
    case 66:
      if (lookahead == 'B') ADVANCE(842);
      END_STATE();
    case 67:
      if (lookahead == 'B') ADVANCE(845);
      if (lookahead == 'X') ADVANCE(68);
      END_STATE();
    case 68:
      if (lookahead == 'B') ADVANCE(846);
      END_STATE();
    case 69:
      if (lookahead == 'a') ADVANCE(1039);
      if (lookahead == 'b') ADVANCE(1042);
      if (lookahead == 'l') ADVANCE(529);
      if (lookahead == 'm') ADVANCE(385);
      if (lookahead == 'o') ADVANCE(354);
      if (lookahead == 'p') ADVANCE(559);
      if (lookahead == 'q') ADVANCE(547);
      if (lookahead == 'v') ADVANCE(530);
      if (lookahead == 'w') ADVANCE(531);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('c' <= lookahead && lookahead <= 'f')) ADVANCE(1036);
      END_STATE();
    case 70:
      if (lookahead == 'a') ADVANCE(1014);
      if (lookahead == 'b') ADVANCE(1016);
      if (lookahead == 'e') ADVANCE(1018);
      if (lookahead == 'g') ADVANCE(1019);
      if (lookahead == 'l') ADVANCE(1021);
      if (lookahead == 'm') ADVANCE(396);
      if (lookahead == 'n') ADVANCE(243);
      if (lookahead == 'o') ADVANCE(1028);
      if (lookahead == 'p') ADVANCE(1029);
      if (lookahead == 'r') ADVANCE(136);
      if (lookahead == 's') ADVANCE(1031);
      END_STATE();
    case 71:
      if (lookahead == 'a') ADVANCE(602);
      if (lookahead == 'f') ADVANCE(252);
      if (lookahead == 'i') ADVANCE(378);
      if (lookahead == 'o') ADVANCE(575);
      if (lookahead == 'u') ADVANCE(324);
      END_STATE();
    case 72:
      if (lookahead == 'a') ADVANCE(133);
      if (lookahead == 'b') ADVANCE(348);
      if (lookahead == 'c') ADVANCE(337);
      if (lookahead == 'e') ADVANCE(606);
      if (lookahead == 'i') ADVANCE(363);
      if (lookahead == 'm') ADVANCE(84);
      if (lookahead == 'o') ADVANCE(398);
      if (lookahead == 'r') ADVANCE(244);
      if (lookahead == 's') ADVANCE(285);
      if (lookahead == 'u') ADVANCE(377);
      if (lookahead == 'x') ADVANCE(383);
      END_STATE();
    case 73:
      if (lookahead == 'a') ADVANCE(456);
      if (lookahead == 'b') ADVANCE(100);
      if (lookahead == 'e') ADVANCE(532);
      if (lookahead == 'h') ADVANCE(75);
      if (lookahead == 's') ADVANCE(887);
      if (lookahead == 'u') ADVANCE(101);
      END_STATE();
    case 74:
      if (lookahead == 'a') ADVANCE(717);
      END_STATE();
    case 75:
      if (lookahead == 'a') ADVANCE(7);
      if (lookahead == 'l') ADVANCE(875);
      if (lookahead == 'r') ADVANCE(880);
      if (lookahead == 'u') ADVANCE(273);
      END_STATE();
    case 76:
      if (lookahead == 'a') ADVANCE(857);
      if (lookahead == 'b') ADVANCE(859);
      if (lookahead == 'e') ADVANCE(861);
      if (lookahead == 'g') ADVANCE(862);
      if (lookahead == 'l') ADVANCE(864);
      if (lookahead == 'n') ADVANCE(246);
      if (lookahead == 'o') ADVANCE(869);
      if (lookahead == 'p') ADVANCE(870);
      END_STATE();
    case 77:
      if (lookahead == 'a') ADVANCE(659);
      if (lookahead == 'b') ADVANCE(661);
      if (lookahead == 'e') ADVANCE(663);
      if (lookahead == 'g') ADVANCE(664);
      if (lookahead == 'l') ADVANCE(666);
      if (lookahead == 'n') ADVANCE(247);
      if (lookahead == 'o') ADVANCE(670);
      if (lookahead == 'p') ADVANCE(671);
      if (lookahead == 's') ADVANCE(672);
      END_STATE();
    case 78:
      if (lookahead == 'a') ADVANCE(732);
      if (lookahead == 'u') ADVANCE(733);
      END_STATE();
    case 79:
      if (lookahead == 'a') ADVANCE(922);
      if (lookahead == 'u') ADVANCE(925);
      END_STATE();
    case 80:
      if (lookahead == 'a') ADVANCE(1043);
      if (lookahead == 'e') ADVANCE(1038);
      if (lookahead == 'i') ADVANCE(574);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('b' <= lookahead && lookahead <= 'f')) ADVANCE(1036);
      END_STATE();
    case 81:
      if (lookahead == 'a') ADVANCE(8);
      END_STATE();
    case 82:
      if (lookahead == 'a') ADVANCE(255);
      if (lookahead == 'b') ADVANCE(350);
      if (lookahead == 'c') ADVANCE(582);
      if (lookahead == 'd') ADVANCE(305);
      if (lookahead == 'e') ADVANCE(609);
      if (lookahead == 'i') ADVANCE(365);
      if (lookahead == 'm') ADVANCE(390);
      if (lookahead == 'p') ADVANCE(92);
      if (lookahead == 's') ADVANCE(292);
      if (lookahead == 'u') ADVANCE(148);
      if (lookahead == 'x') ADVANCE(387);
      if (lookahead == 'z') ADVANCE(256);
      END_STATE();
    case 83:
      if (lookahead == 'a') ADVANCE(400);
      END_STATE();
    case 84:
      if (lookahead == 'a') ADVANCE(216);
      if (lookahead == 'o') ADVANCE(583);
      if (lookahead == 'u') ADVANCE(341);
      END_STATE();
    case 85:
      if (lookahead == 'a') ADVANCE(141);
      END_STATE();
    case 86:
      if (lookahead == 'a') ADVANCE(166);
      if (lookahead == 'l') ADVANCE(167);
      END_STATE();
    case 87:
      if (lookahead == 'a') ADVANCE(145);
      END_STATE();
    case 88:
      if (lookahead == 'a') ADVANCE(344);
      if (lookahead == 'u') ADVANCE(409);
      END_STATE();
    case 89:
      if (lookahead == 'a') ADVANCE(220);
      END_STATE();
    case 90:
      if (lookahead == 'a') ADVANCE(224);
      END_STATE();
    case 91:
      if (lookahead == 'a') ADVANCE(526);
      END_STATE();
    case 92:
      if (lookahead == 'a') ADVANCE(146);
      if (lookahead == 'b') ADVANCE(351);
      if (lookahead == 'c') ADVANCE(349);
      if (lookahead == 'e') ADVANCE(469);
      if (lookahead == 'i') ADVANCE(379);
      if (lookahead == 'm') ADVANCE(99);
      if (lookahead == 'o') ADVANCE(459);
      if (lookahead == 'r') ADVANCE(391);
      if (lookahead == 's') ADVANCE(294);
      if (lookahead == 'u') ADVANCE(381);
      if (lookahead == 'x') ADVANCE(392);
      END_STATE();
    case 93:
      if (lookahead == 'a') ADVANCE(516);
      END_STATE();
    case 94:
      if (lookahead == 'a') ADVANCE(411);
      if (lookahead == 'd') ADVANCE(921);
      if (lookahead == 'q') ADVANCE(928);
      if (lookahead == 's') ADVANCE(178);
      if (lookahead == 'u') ADVANCE(416);
      END_STATE();
    case 95:
      if (lookahead == 'a') ADVANCE(524);
      END_STATE();
    case 96:
      if (lookahead == 'a') ADVANCE(518);
      END_STATE();
    case 97:
      if (lookahead == 'a') ADVANCE(519);
      END_STATE();
    case 98:
      if (lookahead == 'a') ADVANCE(520);
      END_STATE();
    case 99:
      if (lookahead == 'a') ADVANCE(237);
      if (lookahead == 'u') ADVANCE(329);
      END_STATE();
    case 100:
      if (lookahead == 'b') ADVANCE(856);
      END_STATE();
    case 101:
      if (lookahead == 'b') ADVANCE(888);
      END_STATE();
    case 102:
      if (lookahead == 'b') ADVANCE(713);
      if (lookahead == 'l') ADVANCE(714);
      END_STATE();
    case 103:
      if (lookahead == 'b') ADVANCE(107);
      END_STATE();
    case 104:
      if (lookahead == 'b') ADVANCE(738);
      if (lookahead == 'd') ADVANCE(742);
      if (lookahead == 'l') ADVANCE(425);
      if (lookahead == 's') ADVANCE(744);
      if (lookahead == 'w') ADVANCE(330);
      END_STATE();
    case 105:
      if (lookahead == 'b') ADVANCE(331);
      if (lookahead == 'w') ADVANCE(332);
      END_STATE();
    case 106:
      if (lookahead == 'b') ADVANCE(775);
      if (lookahead == 'l') ADVANCE(776);
      END_STATE();
    case 107:
      if (lookahead == 'b') ADVANCE(818);
      if (lookahead == 'd') ADVANCE(819);
      if (lookahead == 'q') ADVANCE(820);
      if (lookahead == 'u') ADVANCE(491);
      END_STATE();
    case 108:
      if (lookahead == 'b') ADVANCE(183);
      END_STATE();
    case 109:
      if (lookahead == 'b') ADVANCE(791);
      if (lookahead == 'q') ADVANCE(792);
      if (lookahead == 'w') ADVANCE(793);
      END_STATE();
    case 110:
      if (lookahead == 'b') ADVANCE(794);
      if (lookahead == 'd') ADVANCE(795);
      if (lookahead == 'w') ADVANCE(796);
      END_STATE();
    case 111:
      if (lookahead == 'b') ADVANCE(806);
      if (lookahead == 'd') ADVANCE(807);
      if (lookahead == 'h') ADVANCE(589);
      if (lookahead == 'l') ADVANCE(590);
      END_STATE();
    case 112:
      if (lookahead == 'b') ADVANCE(934);
      if (lookahead == 'd') ADVANCE(935);
      if (lookahead == 'q') ADVANCE(936);
      if (lookahead == 'w') ADVANCE(937);
      END_STATE();
    case 113:
      if (lookahead == 'b') ADVANCE(788);
      if (lookahead == 'd') ADVANCE(789);
      END_STATE();
    case 114:
      if (lookahead == 'b') ADVANCE(821);
      if (lookahead == 'w') ADVANCE(822);
      END_STATE();
    case 115:
      if (lookahead == 'b') ADVANCE(957);
      if (lookahead == 'd') ADVANCE(958);
      if (lookahead == 'q') ADVANCE(959);
      if (lookahead == 'w') ADVANCE(960);
      END_STATE();
    case 116:
      if (lookahead == 'b') ADVANCE(968);
      if (lookahead == 'd') ADVANCE(969);
      END_STATE();
    case 117:
      if (lookahead == 'b') ADVANCE(777);
      END_STATE();
    case 118:
      if (lookahead == 'b') ADVANCE(799);
      END_STATE();
    case 119:
      if (lookahead == 'b') ADVANCE(466);
      END_STATE();
    case 120:
      if (lookahead == 'b') ADVANCE(478);
      if (lookahead == 'p') ADVANCE(174);
      END_STATE();
    case 121:
      if (lookahead == 'b') ADVANCE(579);
      END_STATE();
    case 122:
      if (lookahead == 'b') ADVANCE(595);
      if (lookahead == 'd') ADVANCE(429);
      if (lookahead == 'q') ADVANCE(219);
      if (lookahead == 'w') ADVANCE(199);
      END_STATE();
    case 123:
      if (lookahead == 'b') ADVANCE(596);
      if (lookahead == 'd') ADVANCE(430);
      if (lookahead == 'q') ADVANCE(222);
      if (lookahead == 'w') ADVANCE(200);
      END_STATE();
    case 124:
      if (lookahead == 'b') ADVANCE(507);
      END_STATE();
    case 125:
      if (lookahead == 'b') ADVANCE(510);
      END_STATE();
    case 126:
      if (lookahead == 'b') ADVANCE(515);
      END_STATE();
    case 127:
      if (lookahead == 'c') ADVANCE(284);
      if (lookahead == 'g') ADVANCE(259);
      if (lookahead == 'o') ADVANCE(457);
      END_STATE();
    case 128:
      if (lookahead == 'c') ADVANCE(711);
      if (lookahead == 's') ADVANCE(102);
      END_STATE();
    case 129:
      if (lookahead == 'c') ADVANCE(314);
      END_STATE();
    case 130:
      if (lookahead == 'c') ADVANCE(635);
      END_STATE();
    case 131:
      if (lookahead == 'c') ADVANCE(637);
      END_STATE();
    case 132:
      if (lookahead == 'c') ADVANCE(904);
      END_STATE();
    case 133:
      if (lookahead == 'c') ADVANCE(319);
      if (lookahead == 'd') ADVANCE(154);
      if (lookahead == 'l') ADVANCE(303);
      if (lookahead == 'n') ADVANCE(155);
      END_STATE();
    case 134:
      if (lookahead == 'c') ADVANCE(317);
      END_STATE();
    case 135:
      if (lookahead == 'c') ADVANCE(394);
      if (lookahead == 'd') ADVANCE(16);
      if (lookahead == 'n') ADVANCE(403);
      END_STATE();
    case 136:
      if (lookahead == 'c') ADVANCE(601);
      END_STATE();
    case 137:
      if (lookahead == 'c') ADVANCE(369);
      END_STATE();
    case 138:
      if (lookahead == 'c') ADVANCE(291);
      END_STATE();
    case 139:
      if (lookahead == 'c') ADVANCE(316);
      END_STATE();
    case 140:
      if (lookahead == 'c') ADVANCE(318);
      END_STATE();
    case 141:
      if (lookahead == 'c') ADVANCE(315);
      END_STATE();
    case 142:
      if (lookahead == 'c') ADVANCE(91);
      END_STATE();
    case 143:
      if (lookahead == 'c') ADVANCE(320);
      END_STATE();
    case 144:
      if (lookahead == 'c') ADVANCE(248);
      END_STATE();
    case 145:
      if (lookahead == 'c') ADVANCE(549);
      END_STATE();
    case 146:
      if (lookahead == 'c') ADVANCE(322);
      if (lookahead == 'd') ADVANCE(170);
      if (lookahead == 'l') ADVANCE(312);
      if (lookahead == 'n') ADVANCE(171);
      END_STATE();
    case 147:
      if (lookahead == 'c') ADVANCE(97);
      END_STATE();
    case 148:
      if (lookahead == 'c') ADVANCE(395);
      if (lookahead == 'n') ADVANCE(405);
      END_STATE();
    case 149:
      if (lookahead == 'd') ADVANCE(1037);
      if (lookahead == 'e') ADVANCE(1041);
      if (lookahead == 'n') ADVANCE(151);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(1036);
      END_STATE();
    case 150:
      if (lookahead == 'd') ADVANCE(304);
      if (lookahead == 'm') ADVANCE(564);
      if (lookahead == 'n') ADVANCE(128);
      END_STATE();
    case 151:
      if (lookahead == 'd') ADVANCE(640);
      END_STATE();
    case 152:
      if (lookahead == 'd') ADVANCE(657);
      if (lookahead == 'q') ADVANCE(658);
      END_STATE();
    case 153:
      if (lookahead == 'd') ADVANCE(691);
      if (lookahead == 'l') ADVANCE(692);
      END_STATE();
    case 154:
      if (lookahead == 'd') ADVANCE(163);
      END_STATE();
    case 155:
      if (lookahead == 'd') ADVANCE(782);
      END_STATE();
    case 156:
      if (lookahead == 'd') ADVANCE(631);
      if (lookahead == 's') ADVANCE(632);
      END_STATE();
    case 157:
      if (lookahead == 'd') ADVANCE(644);
      if (lookahead == 's') ADVANCE(645);
      END_STATE();
    case 158:
      if (lookahead == 'd') ADVANCE(680);
      END_STATE();
    case 159:
      if (lookahead == 'd') ADVANCE(698);
      if (lookahead == 's') ADVANCE(699);
      END_STATE();
    case 160:
      if (lookahead == 'd') ADVANCE(720);
      if (lookahead == 's') ADVANCE(721);
      END_STATE();
    case 161:
      if (lookahead == 'd') ADVANCE(723);
      if (lookahead == 's') ADVANCE(724);
      END_STATE();
    case 162:
      if (lookahead == 'd') ADVANCE(757);
      if (lookahead == 's') ADVANCE(758);
      END_STATE();
    case 163:
      if (lookahead == 'd') ADVANCE(778);
      if (lookahead == 'q') ADVANCE(779);
      if (lookahead == 'w') ADVANCE(780);
      END_STATE();
    case 164:
      if (lookahead == 'd') ADVANCE(570);
      END_STATE();
    case 165:
      if (lookahead == 'd') ADVANCE(810);
      if (lookahead == 'q') ADVANCE(812);
      END_STATE();
    case 166:
      if (lookahead == 'd') ADVANCE(813);
      END_STATE();
    case 167:
      if (lookahead == 'd') ADVANCE(814);
      if (lookahead == 'q') ADVANCE(816);
      if (lookahead == 'w') ADVANCE(817);
      END_STATE();
    case 168:
      if (lookahead == 'd') ADVANCE(891);
      END_STATE();
    case 169:
      if (lookahead == 'd') ADVANCE(893);
      if (lookahead == 's') ADVANCE(894);
      END_STATE();
    case 170:
      if (lookahead == 'd') ADVANCE(112);
      END_STATE();
    case 171:
      if (lookahead == 'd') ADVANCE(939);
      END_STATE();
    case 172:
      if (lookahead == 'd') ADVANCE(1007);
      if (lookahead == 's') ADVANCE(1008);
      END_STATE();
    case 173:
      if (lookahead == 'd') ADVANCE(678);
      if (lookahead == 's') ADVANCE(679);
      END_STATE();
    case 174:
      if (lookahead == 'd') ADVANCE(727);
      if (lookahead == 's') ADVANCE(728);
      END_STATE();
    case 175:
      if (lookahead == 'd') ADVANCE(885);
      if (lookahead == 's') ADVANCE(886);
      END_STATE();
    case 176:
      if (lookahead == 'd') ADVANCE(419);
      END_STATE();
    case 177:
      if (lookahead == 'd') ADVANCE(912);
      END_STATE();
    case 178:
      if (lookahead == 'd') ADVANCE(929);
      if (lookahead == 's') ADVANCE(930);
      END_STATE();
    case 179:
      if (lookahead == 'd') ADVANCE(932);
      END_STATE();
    case 180:
      if (lookahead == 'd') ADVANCE(966);
      if (lookahead == 'q') ADVANCE(967);
      END_STATE();
    case 181:
      if (lookahead == 'd') ADVANCE(970);
      if (lookahead == 'q') ADVANCE(972);
      if (lookahead == 'w') ADVANCE(973);
      END_STATE();
    case 182:
      if (lookahead == 'd') ADVANCE(974);
      if (lookahead == 'q') ADVANCE(976);
      if (lookahead == 'w') ADVANCE(977);
      END_STATE();
    case 183:
      if (lookahead == 'd') ADVANCE(978);
      if (lookahead == 'q') ADVANCE(979);
      if (lookahead == 'u') ADVANCE(505);
      if (lookahead == 'w') ADVANCE(981);
      END_STATE();
    case 184:
      if (lookahead == 'd') ADVANCE(993);
      END_STATE();
    case 185:
      if (lookahead == 'd') ADVANCE(790);
      END_STATE();
    case 186:
      if (lookahead == 'd') ADVANCE(798);
      END_STATE();
    case 187:
      if (lookahead == 'd') ADVANCE(900);
      if (lookahead == 's') ADVANCE(901);
      END_STATE();
    case 188:
      if (lookahead == 'd') ADVANCE(919);
      if (lookahead == 's') ADVANCE(920);
      END_STATE();
    case 189:
      if (lookahead == 'd') ADVANCE(193);
      END_STATE();
    case 190:
      if (lookahead == 'd') ADVANCE(683);
      if (lookahead == 's') ADVANCE(686);
      END_STATE();
    case 191:
      if (lookahead == 'd') ADVANCE(688);
      END_STATE();
    case 192:
      if (lookahead == 'd') ADVANCE(903);
      END_STATE();
    case 193:
      if (lookahead == 'd') ADVANCE(940);
      if (lookahead == 'm') ADVANCE(201);
      END_STATE();
    case 194:
      if (lookahead == 'd') ADVANCE(948);
      END_STATE();
    case 195:
      if (lookahead == 'd') ADVANCE(953);
      END_STATE();
    case 196:
      if (lookahead == 'd') ADVANCE(955);
      END_STATE();
    case 197:
      if (lookahead == 'd') ADVANCE(962);
      END_STATE();
    case 198:
      if (lookahead == 'd') ADVANCE(994);
      if (lookahead == 's') ADVANCE(995);
      END_STATE();
    case 199:
      if (lookahead == 'd') ADVANCE(826);
      END_STATE();
    case 200:
      if (lookahead == 'd') ADVANCE(830);
      END_STATE();
    case 201:
      if (lookahead == 'd') ADVANCE(941);
      END_STATE();
    case 202:
      if (lookahead == 'd') ADVANCE(949);
      END_STATE();
    case 203:
      if (lookahead == 'd') ADVANCE(996);
      if (lookahead == 's') ADVANCE(997);
      END_STATE();
    case 204:
      if (lookahead == 'd') ADVANCE(998);
      if (lookahead == 's') ADVANCE(999);
      END_STATE();
    case 205:
      if (lookahead == 'd') ADVANCE(911);
      END_STATE();
    case 206:
      if (lookahead == 'd') ADVANCE(984);
      END_STATE();
    case 207:
      if (lookahead == 'd') ADVANCE(987);
      END_STATE();
    case 208:
      if (lookahead == 'd') ADVANCE(942);
      if (lookahead == 'q') ADVANCE(943);
      END_STATE();
    case 209:
      if (lookahead == 'd') ADVANCE(119);
      END_STATE();
    case 210:
      if (lookahead == 'd') ADVANCE(29);
      if (lookahead == 'i') ADVANCE(38);
      if (lookahead == 's') ADVANCE(36);
      END_STATE();
    case 211:
      if (lookahead == 'd') ADVANCE(588);
      END_STATE();
    case 212:
      if (lookahead == 'd') ADVANCE(258);
      if (lookahead == 'e') ADVANCE(367);
      if (lookahead == 'k') ADVANCE(245);
      END_STATE();
    case 213:
      if (lookahead == 'd') ADVANCE(427);
      END_STATE();
    case 214:
      if (lookahead == 'd') ADVANCE(533);
      END_STATE();
    case 215:
      if (lookahead == 'd') ADVANCE(428);
      END_STATE();
    case 216:
      if (lookahead == 'd') ADVANCE(164);
      END_STATE();
    case 217:
      if (lookahead == 'd') ADVANCE(584);
      END_STATE();
    case 218:
      if (lookahead == 'd') ADVANCE(327);
      END_STATE();
    case 219:
      if (lookahead == 'd') ADVANCE(431);
      END_STATE();
    case 220:
      if (lookahead == 'd') ADVANCE(147);
      END_STATE();
    case 221:
      if (lookahead == 'd') ADVANCE(597);
      END_STATE();
    case 222:
      if (lookahead == 'd') ADVANCE(432);
      END_STATE();
    case 223:
      if (lookahead == 'd') ADVANCE(433);
      if (lookahead == 'q') ADVANCE(226);
      if (lookahead == 'w') ADVANCE(206);
      END_STATE();
    case 224:
      if (lookahead == 'd') ADVANCE(142);
      END_STATE();
    case 225:
      if (lookahead == 'd') ADVANCE(434);
      if (lookahead == 'q') ADVANCE(227);
      if (lookahead == 'w') ADVANCE(207);
      END_STATE();
    case 226:
      if (lookahead == 'd') ADVANCE(435);
      END_STATE();
    case 227:
      if (lookahead == 'd') ADVANCE(436);
      END_STATE();
    case 228:
      if (lookahead == 'd') ADVANCE(437);
      END_STATE();
    case 229:
      if (lookahead == 'd') ADVANCE(438);
      END_STATE();
    case 230:
      if (lookahead == 'd') ADVANCE(439);
      END_STATE();
    case 231:
      if (lookahead == 'd') ADVANCE(440);
      END_STATE();
    case 232:
      if (lookahead == 'd') ADVANCE(441);
      END_STATE();
    case 233:
      if (lookahead == 'd') ADVANCE(442);
      END_STATE();
    case 234:
      if (lookahead == 'd') ADVANCE(443);
      END_STATE();
    case 235:
      if (lookahead == 'd') ADVANCE(492);
      END_STATE();
    case 236:
      if (lookahead == 'd') ADVANCE(572);
      END_STATE();
    case 237:
      if (lookahead == 'd') ADVANCE(236);
      END_STATE();
    case 238:
      if (lookahead == 'd') ADVANCE(30);
      if (lookahead == 's') ADVANCE(31);
      END_STATE();
    case 239:
      if (lookahead == 'e') ADVANCE(1040);
      if (lookahead == 'i') ADVANCE(339);
      if (lookahead == 'l') ADVANCE(214);
      if (lookahead == 'm') ADVANCE(562);
      if (lookahead == 's') ADVANCE(705);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(1036);
      END_STATE();
    case 240:
      if (lookahead == 'e') ADVANCE(74);
      if (lookahead == 'o') ADVANCE(129);
      END_STATE();
    case 241:
      if (lookahead == 'e') ADVANCE(276);
      if (lookahead == 'o') ADVANCE(397);
      END_STATE();
    case 242:
      if (lookahead == 'e') ADVANCE(834);
      if (lookahead == 'o') ADVANCE(325);
      END_STATE();
    case 243:
      if (lookahead == 'e') ADVANCE(1025);
      if (lookahead == 'o') ADVANCE(1026);
      if (lookahead == 's') ADVANCE(1027);
      END_STATE();
    case 244:
      if (lookahead == 'e') ADVANCE(274);
      END_STATE();
    case 245:
      if (lookahead == 'e') ADVANCE(612);
      END_STATE();
    case 246:
      if (lookahead == 'e') ADVANCE(866);
      if (lookahead == 'p') ADVANCE(867);
      if (lookahead == 's') ADVANCE(868);
      END_STATE();
    case 247:
      if (lookahead == 'e') ADVANCE(668);
      if (lookahead == 's') ADVANCE(669);
      END_STATE();
    case 248:
      if (lookahead == 'e') ADVANCE(722);
      END_STATE();
    case 249:
      if (lookahead == 'e') ADVANCE(873);
      END_STATE();
    case 250:
      if (lookahead == 'e') ADVANCE(504);
      if (lookahead == 'z') ADVANCE(137);
      END_STATE();
    case 251:
      if (lookahead == 'e') ADVANCE(366);
      END_STATE();
    case 252:
      if (lookahead == 'e') ADVANCE(364);
      END_STATE();
    case 253:
      if (lookahead == 'e') ADVANCE(424);
      END_STATE();
    case 254:
      if (lookahead == 'e') ADVANCE(426);
      if (lookahead == 'g') ADVANCE(555);
      END_STATE();
    case 255:
      if (lookahead == 'e') ADVANCE(528);
      END_STATE();
    case 256:
      if (lookahead == 'e') ADVANCE(470);
      END_STATE();
    case 257:
      if (lookahead == 'e') ADVANCE(380);
      END_STATE();
    case 258:
      if (lookahead == 'e') ADVANCE(130);
      END_STATE();
    case 259:
      if (lookahead == 'e') ADVANCE(548);
      END_STATE();
    case 260:
      if (lookahead == 'e') ADVANCE(472);
      END_STATE();
    case 261:
      if (lookahead == 'e') ADVANCE(553);
      END_STATE();
    case 262:
      if (lookahead == 'e') ADVANCE(465);
      END_STATE();
    case 263:
      if (lookahead == 'e') ADVANCE(370);
      END_STATE();
    case 264:
      if (lookahead == 'e') ADVANCE(611);
      END_STATE();
    case 265:
      if (lookahead == 'e') ADVANCE(372);
      END_STATE();
    case 266:
      if (lookahead == 'e') ADVANCE(368);
      END_STATE();
    case 267:
      if (lookahead == 'e') ADVANCE(376);
      END_STATE();
    case 268:
      if (lookahead == 'f') ADVANCE(649);
      if (lookahead == 'r') ADVANCE(650);
      if (lookahead == 'w') ADVANCE(83);
      END_STATE();
    case 269:
      if (lookahead == 'f') ADVANCE(111);
      END_STATE();
    case 270:
      if (lookahead == 'f') ADVANCE(299);
      END_STATE();
    case 271:
      if (lookahead == 'f') ADVANCE(116);
      END_STATE();
    case 272:
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'i') ADVANCE(11);
      END_STATE();
    case 273:
      if (lookahead == 'f') ADVANCE(410);
      END_STATE();
    case 274:
      if (lookahead == 'f') ADVANCE(261);
      END_STATE();
    case 275:
      if (lookahead == 'f') ADVANCE(12);
      if (lookahead == 'i') ADVANCE(13);
      END_STATE();
    case 276:
      if (lookahead == 'g') ADVANCE(761);
      END_STATE();
    case 277:
      if (lookahead == 'g') ADVANCE(1003);
      END_STATE();
    case 278:
      if (lookahead == 'g') ADVANCE(9);
      END_STATE();
    case 279:
      if (lookahead == 'g') ADVANCE(371);
      END_STATE();
    case 280:
      if (lookahead == 'g') ADVANCE(374);
      END_STATE();
    case 281:
      if (lookahead == 'g') ADVANCE(556);
      if (lookahead == 'l') ADVANCE(558);
      END_STATE();
    case 282:
      if (lookahead == 'g') ADVANCE(257);
      END_STATE();
    case 283:
      if (lookahead == 'h') ADVANCE(831);
      END_STATE();
    case 284:
      if (lookahead == 'h') ADVANCE(277);
      END_STATE();
    case 285:
      if (lookahead == 'h') ADVANCE(560);
      if (lookahead == 'l') ADVANCE(335);
      if (lookahead == 'r') ADVANCE(86);
      if (lookahead == 'u') ADVANCE(103);
      END_STATE();
    case 286:
      if (lookahead == 'h') ADVANCE(122);
      if (lookahead == 'l') ADVANCE(123);
      END_STATE();
    case 287:
      if (lookahead == 'h') ADVANCE(223);
      if (lookahead == 'l') ADVANCE(225);
      END_STATE();
    case 288:
      if (lookahead == 'h') ADVANCE(444);
      if (lookahead == 'l') ADVANCE(452);
      END_STATE();
    case 289:
      if (lookahead == 'h') ADVANCE(418);
      END_STATE();
    case 290:
      if (lookahead == 'h') ADVANCE(445);
      END_STATE();
    case 291:
      if (lookahead == 'h') ADVANCE(537);
      END_STATE();
    case 292:
      if (lookahead == 'h') ADVANCE(561);
      if (lookahead == 'u') ADVANCE(126);
      END_STATE();
    case 293:
      if (lookahead == 'h') ADVANCE(446);
      if (lookahead == 'l') ADVANCE(447);
      END_STATE();
    case 294:
      if (lookahead == 'h') ADVANCE(563);
      if (lookahead == 'l') ADVANCE(338);
      if (lookahead == 'r') ADVANCE(340);
      if (lookahead == 'u') ADVANCE(108);
      END_STATE();
    case 295:
      if (lookahead == 'h') ADVANCE(413);
      if (lookahead == 'l') ADVANCE(414);
      END_STATE();
    case 296:
      if (lookahead == 'h') ADVANCE(448);
      if (lookahead == 'l') ADVANCE(449);
      END_STATE();
    case 297:
      if (lookahead == 'h') ADVANCE(450);
      if (lookahead == 'l') ADVANCE(451);
      END_STATE();
    case 298:
      if (lookahead == 'h') ADVANCE(453);
      if (lookahead == 'l') ADVANCE(454);
      END_STATE();
    case 299:
      if (lookahead == 'i') ADVANCE(41);
      if (lookahead == 'p') ADVANCE(484);
      END_STATE();
    case 300:
      if (lookahead == 'i') ADVANCE(689);
      END_STATE();
    case 301:
      if (lookahead == 'i') ADVANCE(690);
      END_STATE();
    case 302:
      if (lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 303:
      if (lookahead == 'i') ADVANCE(279);
      END_STATE();
    case 304:
      if (lookahead == 'i') ADVANCE(577);
      END_STATE();
    case 305:
      if (lookahead == 'i') ADVANCE(581);
      END_STATE();
    case 306:
      if (lookahead == 'i') ADVANCE(158);
      END_STATE();
    case 307:
      if (lookahead == 'i') ADVANCE(15);
      if (lookahead == 's') ADVANCE(489);
      END_STATE();
    case 308:
      if (lookahead == 'i') ADVANCE(503);
      END_STATE();
    case 309:
      if (lookahead == 'i') ADVANCE(508);
      END_STATE();
    case 310:
      if (lookahead == 'i') ADVANCE(522);
      END_STATE();
    case 311:
      if (lookahead == 'i') ADVANCE(512);
      END_STATE();
    case 312:
      if (lookahead == 'i') ADVANCE(280);
      END_STATE();
    case 313:
      if (lookahead == 'i') ADVANCE(39);
      END_STATE();
    case 314:
      if (lookahead == 'k') ADVANCE(719);
      END_STATE();
    case 315:
      if (lookahead == 'k') ADVANCE(1032);
      END_STATE();
    case 316:
      if (lookahead == 'k') ADVANCE(286);
      END_STATE();
    case 317:
      if (lookahead == 'k') ADVANCE(289);
      END_STATE();
    case 318:
      if (lookahead == 'k') ADVANCE(295);
      END_STATE();
    case 319:
      if (lookahead == 'k') ADVANCE(565);
      END_STATE();
    case 320:
      if (lookahead == 'k') ADVANCE(287);
      END_STATE();
    case 321:
      if (lookahead == 'k') ADVANCE(118);
      END_STATE();
    case 322:
      if (lookahead == 'k') ADVANCE(573);
      END_STATE();
    case 323:
      if (lookahead == 'l') ADVANCE(251);
      if (lookahead == 's') ADVANCE(268);
      if (lookahead == 't') ADVANCE(652);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(1036);
      END_STATE();
    case 324:
      if (lookahead == 'l') ADVANCE(753);
      END_STATE();
    case 325:
      if (lookahead == 'l') ADVANCE(848);
      if (lookahead == 'r') ADVANCE(850);
      END_STATE();
    case 326:
      if (lookahead == 'l') ADVANCE(710);
      END_STATE();
    case 327:
      if (lookahead == 'l') ADVANCE(702);
      END_STATE();
    case 328:
      if (lookahead == 'l') ADVANCE(706);
      END_STATE();
    case 329:
      if (lookahead == 'l') ADVANCE(343);
      END_STATE();
    case 330:
      if (lookahead == 'l') ADVANCE(745);
      if (lookahead == 'q') ADVANCE(746);
      END_STATE();
    case 331:
      if (lookahead == 'l') ADVANCE(749);
      if (lookahead == 'q') ADVANCE(750);
      if (lookahead == 'w') ADVANCE(751);
      END_STATE();
    case 332:
      if (lookahead == 'l') ADVANCE(752);
      END_STATE();
    case 333:
      if (lookahead == 'l') ADVANCE(288);
      END_STATE();
    case 334:
      if (lookahead == 'l') ADVANCE(1001);
      END_STATE();
    case 335:
      if (lookahead == 'l') ADVANCE(165);
      END_STATE();
    case 336:
      if (lookahead == 'l') ADVANCE(423);
      END_STATE();
    case 337:
      if (lookahead == 'l') ADVANCE(358);
      if (lookahead == 'm') ADVANCE(399);
      END_STATE();
    case 338:
      if (lookahead == 'l') ADVANCE(181);
      END_STATE();
    case 339:
      if (lookahead == 'l') ADVANCE(218);
      END_STATE();
    case 340:
      if (lookahead == 'l') ADVANCE(182);
      END_STATE();
    case 341:
      if (lookahead == 'l') ADVANCE(566);
      END_STATE();
    case 342:
      if (lookahead == 'l') ADVANCE(401);
      END_STATE();
    case 343:
      if (lookahead == 'l') ADVANCE(592);
      if (lookahead == 'u') ADVANCE(215);
      END_STATE();
    case 344:
      if (lookahead == 'l') ADVANCE(334);
      END_STATE();
    case 345:
      if (lookahead == 'l') ADVANCE(298);
      END_STATE();
    case 346:
      if (lookahead == 'l') ADVANCE(514);
      END_STATE();
    case 347:
      if (lookahead == 'l') ADVANCE(415);
      if (lookahead == 'p') ADVANCE(479);
      END_STATE();
    case 348:
      if (lookahead == 'l') ADVANCE(263);
      END_STATE();
    case 349:
      if (lookahead == 'l') ADVANCE(359);
      if (lookahead == 'm') ADVANCE(402);
      END_STATE();
    case 350:
      if (lookahead == 'l') ADVANCE(265);
      if (lookahead == 'r') ADVANCE(386);
      END_STATE();
    case 351:
      if (lookahead == 'l') ADVANCE(267);
      if (lookahead == 'r') ADVANCE(393);
      END_STATE();
    case 352:
      if (lookahead == 'm') ADVANCE(388);
      if (lookahead == 'n') ADVANCE(389);
      END_STATE();
    case 353:
      if (lookahead == 'm') ADVANCE(18);
      END_STATE();
    case 354:
      if (lookahead == 'm') ADVANCE(308);
      END_STATE();
    case 355:
      if (lookahead == 'm') ADVANCE(477);
      END_STATE();
    case 356:
      if (lookahead == 'm') ADVANCE(500);
      END_STATE();
    case 357:
      if (lookahead == 'm') ADVANCE(496);
      if (lookahead == 'n') ADVANCE(264);
      if (lookahead == 'r') ADVANCE(375);
      END_STATE();
    case 358:
      if (lookahead == 'm') ADVANCE(567);
      END_STATE();
    case 359:
      if (lookahead == 'm') ADVANCE(571);
      END_STATE();
    case 360:
      if (lookahead == 'm') ADVANCE(309);
      END_STATE();
    case 361:
      if (lookahead == 'm') ADVANCE(311);
      END_STATE();
    case 362:
      if (lookahead == 'n') ADVANCE(209);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(1036);
      END_STATE();
    case 363:
      if (lookahead == 'n') ADVANCE(502);
      END_STATE();
    case 364:
      if (lookahead == 'n') ADVANCE(144);
      END_STATE();
    case 365:
      if (lookahead == 'n') ADVANCE(527);
      END_STATE();
    case 366:
      if (lookahead == 'n') ADVANCE(217);
      END_STATE();
    case 367:
      if (lookahead == 'n') ADVANCE(131);
      END_STATE();
    case 368:
      if (lookahead == 'n') ADVANCE(132);
      END_STATE();
    case 369:
      if (lookahead == 'n') ADVANCE(535);
      END_STATE();
    case 370:
      if (lookahead == 'n') ADVANCE(211);
      END_STATE();
    case 371:
      if (lookahead == 'n') ADVANCE(463);
      END_STATE();
    case 372:
      if (lookahead == 'n') ADVANCE(176);
      END_STATE();
    case 373:
      if (lookahead == 'n') ADVANCE(536);
      END_STATE();
    case 374:
      if (lookahead == 'n') ADVANCE(464);
      END_STATE();
    case 375:
      if (lookahead == 'n') ADVANCE(235);
      END_STATE();
    case 376:
      if (lookahead == 'n') ADVANCE(189);
      END_STATE();
    case 377:
      if (lookahead == 'n') ADVANCE(404);
      if (lookahead == 's') ADVANCE(283);
      END_STATE();
    case 378:
      if (lookahead == 'n') ADVANCE(497);
      END_STATE();
    case 379:
      if (lookahead == 'n') ADVANCE(509);
      END_STATE();
    case 380:
      if (lookahead == 'n') ADVANCE(95);
      END_STATE();
    case 381:
      if (lookahead == 'n') ADVANCE(407);
      END_STATE();
    case 382:
      if (lookahead == 'o') ADVANCE(681);
      END_STATE();
    case 383:
      if (lookahead == 'o') ADVANCE(458);
      END_STATE();
    case 384:
      if (lookahead == 'o') ADVANCE(88);
      END_STATE();
    case 385:
      if (lookahead == 'o') ADVANCE(576);
      if (lookahead == 'p') ADVANCE(673);
      END_STATE();
    case 386:
      if (lookahead == 'o') ADVANCE(89);
      END_STATE();
    case 387:
      if (lookahead == 'o') ADVANCE(474);
      END_STATE();
    case 388:
      if (lookahead == 'o') ADVANCE(580);
      END_STATE();
    case 389:
      if (lookahead == 'o') ADVANCE(544);
      END_STATE();
    case 390:
      if (lookahead == 'o') ADVANCE(578);
      if (lookahead == 'u') ADVANCE(346);
      END_STATE();
    case 391:
      if (lookahead == 'o') ADVANCE(468);
      END_STATE();
    case 392:
      if (lookahead == 'o') ADVANCE(462);
      END_STATE();
    case 393:
      if (lookahead == 'o') ADVANCE(90);
      END_STATE();
    case 394:
      if (lookahead == 'o') ADVANCE(360);
      END_STATE();
    case 395:
      if (lookahead == 'o') ADVANCE(361);
      END_STATE();
    case 396:
      if (lookahead == 'p') ADVANCE(1023);
      END_STATE();
    case 397:
      if (lookahead == 'p') ADVANCE(764);
      if (lookahead == 't') ADVANCE(767);
      END_STATE();
    case 398:
      if (lookahead == 'p') ADVANCE(801);
      if (lookahead == 'r') ADVANCE(803);
      END_STATE();
    case 399:
      if (lookahead == 'p') ADVANCE(254);
      END_STATE();
    case 400:
      if (lookahead == 'p') ADVANCE(651);
      END_STATE();
    case 401:
      if (lookahead == 'p') ADVANCE(704);
      END_STATE();
    case 402:
      if (lookahead == 'p') ADVANCE(281);
      END_STATE();
    case 403:
      if (lookahead == 'p') ADVANCE(134);
      END_STATE();
    case 404:
      if (lookahead == 'p') ADVANCE(139);
      END_STATE();
    case 405:
      if (lookahead == 'p') ADVANCE(140);
      END_STATE();
    case 406:
      if (lookahead == 'p') ADVANCE(328);
      END_STATE();
    case 407:
      if (lookahead == 'p') ADVANCE(143);
      END_STATE();
    case 408:
      if (lookahead == 'p') ADVANCE(480);
      END_STATE();
    case 409:
      if (lookahead == 'p') ADVANCE(421);
      END_STATE();
    case 410:
      if (lookahead == 'p') ADVANCE(175);
      END_STATE();
    case 411:
      if (lookahead == 'p') ADVANCE(188);
      END_STATE();
    case 412:
      if (lookahead == 'p') ADVANCE(481);
      END_STATE();
    case 413:
      if (lookahead == 'p') ADVANCE(203);
      END_STATE();
    case 414:
      if (lookahead == 'p') ADVANCE(204);
      END_STATE();
    case 415:
      if (lookahead == 'p') ADVANCE(482);
      END_STATE();
    case 416:
      if (lookahead == 'p') ADVANCE(483);
      END_STATE();
    case 417:
      if (lookahead == 'p') ADVANCE(485);
      END_STATE();
    case 418:
      if (lookahead == 'p') ADVANCE(192);
      END_STATE();
    case 419:
      if (lookahead == 'p') ADVANCE(487);
      if (lookahead == 'v') ADVANCE(420);
      END_STATE();
    case 420:
      if (lookahead == 'p') ADVANCE(488);
      END_STATE();
    case 421:
      if (lookahead == 'p') ADVANCE(262);
      END_STATE();
    case 422:
      if (lookahead == 'q') ADVANCE(838);
      END_STATE();
    case 423:
      if (lookahead == 'q') ADVANCE(1013);
      END_STATE();
    case 424:
      if (lookahead == 'q') ADVANCE(718);
      END_STATE();
    case 425:
      if (lookahead == 'q') ADVANCE(743);
      END_STATE();
    case 426:
      if (lookahead == 'q') ADVANCE(113);
      END_STATE();
    case 427:
      if (lookahead == 'q') ADVANCE(800);
      END_STATE();
    case 428:
      if (lookahead == 'q') ADVANCE(964);
      END_STATE();
    case 429:
      if (lookahead == 'q') ADVANCE(824);
      END_STATE();
    case 430:
      if (lookahead == 'q') ADVANCE(828);
      END_STATE();
    case 431:
      if (lookahead == 'q') ADVANCE(825);
      END_STATE();
    case 432:
      if (lookahead == 'q') ADVANCE(829);
      END_STATE();
    case 433:
      if (lookahead == 'q') ADVANCE(982);
      END_STATE();
    case 434:
      if (lookahead == 'q') ADVANCE(985);
      END_STATE();
    case 435:
      if (lookahead == 'q') ADVANCE(983);
      END_STATE();
    case 436:
      if (lookahead == 'q') ADVANCE(986);
      END_STATE();
    case 437:
      if (lookahead == 'q') ADVANCE(785);
      END_STATE();
    case 438:
      if (lookahead == 'q') ADVANCE(786);
      END_STATE();
    case 439:
      if (lookahead == 'q') ADVANCE(787);
      END_STATE();
    case 440:
      if (lookahead == 'q') ADVANCE(944);
      END_STATE();
    case 441:
      if (lookahead == 'q') ADVANCE(945);
      END_STATE();
    case 442:
      if (lookahead == 'q') ADVANCE(946);
      END_STATE();
    case 443:
      if (lookahead == 'q') ADVANCE(947);
      END_STATE();
    case 444:
      if (lookahead == 'q') ADVANCE(290);
      END_STATE();
    case 445:
      if (lookahead == 'q') ADVANCE(228);
      END_STATE();
    case 446:
      if (lookahead == 'q') ADVANCE(229);
      END_STATE();
    case 447:
      if (lookahead == 'q') ADVANCE(230);
      END_STATE();
    case 448:
      if (lookahead == 'q') ADVANCE(231);
      END_STATE();
    case 449:
      if (lookahead == 'q') ADVANCE(232);
      END_STATE();
    case 450:
      if (lookahead == 'q') ADVANCE(233);
      END_STATE();
    case 451:
      if (lookahead == 'q') ADVANCE(234);
      END_STATE();
    case 452:
      if (lookahead == 'q') ADVANCE(293);
      END_STATE();
    case 453:
      if (lookahead == 'q') ADVANCE(296);
      END_STATE();
    case 454:
      if (lookahead == 'q') ADVANCE(297);
      END_STATE();
    case 455:
      if (lookahead == 'r') ADVANCE(770);
      if (lookahead == 'u') ADVANCE(545);
      END_STATE();
    case 456:
      if (lookahead == 'r') ADVANCE(853);
      END_STATE();
    case 457:
      if (lookahead == 'r') ADVANCE(1005);
      END_STATE();
    case 458:
      if (lookahead == 'r') ADVANCE(833);
      END_STATE();
    case 459:
      if (lookahead == 'r') ADVANCE(965);
      END_STATE();
    case 460:
      if (lookahead == 'r') ADVANCE(109);
      END_STATE();
    case 461:
      if (lookahead == 'r') ADVANCE(110);
      END_STATE();
    case 462:
      if (lookahead == 'r') ADVANCE(988);
      END_STATE();
    case 463:
      if (lookahead == 'r') ADVANCE(781);
      END_STATE();
    case 464:
      if (lookahead == 'r') ADVANCE(938);
      END_STATE();
    case 465:
      if (lookahead == 'r') ADVANCE(1002);
      END_STATE();
    case 466:
      if (lookahead == 'r') ADVANCE(54);
      END_STATE();
    case 467:
      if (lookahead == 'r') ADVANCE(115);
      END_STATE();
    case 468:
      if (lookahead == 'r') ADVANCE(180);
      END_STATE();
    case 469:
      if (lookahead == 'r') ADVANCE(353);
      if (lookahead == 'x') ADVANCE(554);
      END_STATE();
    case 470:
      if (lookahead == 'r') ADVANCE(384);
      END_STATE();
    case 471:
      if (lookahead == 'r') ADVANCE(591);
      END_STATE();
    case 472:
      if (lookahead == 'r') ADVANCE(543);
      END_STATE();
    case 473:
      if (lookahead == 'r') ADVANCE(87);
      END_STATE();
    case 474:
      if (lookahead == 'r') ADVANCE(412);
      END_STATE();
    case 475:
      if (lookahead == 's') ADVANCE(707);
      END_STATE();
    case 476:
      if (lookahead == 's') ADVANCE(210);
      if (lookahead == 't') ADVANCE(506);
      END_STATE();
    case 477:
      if (lookahead == 's') ADVANCE(701);
      END_STATE();
    case 478:
      if (lookahead == 's') ADVANCE(726);
      END_STATE();
    case 479:
      if (lookahead == 's') ADVANCE(735);
      END_STATE();
    case 480:
      if (lookahead == 's') ADVANCE(747);
      END_STATE();
    case 481:
      if (lookahead == 's') ADVANCE(1000);
      END_STATE();
    case 482:
      if (lookahead == 's') ADVANCE(734);
      END_STATE();
    case 483:
      if (lookahead == 's') ADVANCE(931);
      END_STATE();
    case 484:
      if (lookahead == 's') ADVANCE(992);
      END_STATE();
    case 485:
      if (lookahead == 's') ADVANCE(648);
      END_STATE();
    case 486:
      if (lookahead == 's') ADVANCE(682);
      END_STATE();
    case 487:
      if (lookahead == 's') ADVANCE(906);
      END_STATE();
    case 488:
      if (lookahead == 's') ADVANCE(907);
      END_STATE();
    case 489:
      if (lookahead == 's') ADVANCE(910);
      END_STATE();
    case 490:
      if (lookahead == 's') ADVANCE(106);
      END_STATE();
    case 491:
      if (lookahead == 's') ADVANCE(114);
      END_STATE();
    case 492:
      if (lookahead == 's') ADVANCE(43);
      END_STATE();
    case 493:
      if (lookahead == 's') ADVANCE(599);
      END_STATE();
    case 494:
      if (lookahead == 's') ADVANCE(160);
      END_STATE();
    case 495:
      if (lookahead == 's') ADVANCE(313);
      END_STATE();
    case 496:
      if (lookahead == 's') ADVANCE(278);
      END_STATE();
    case 497:
      if (lookahead == 's') ADVANCE(161);
      END_STATE();
    case 498:
      if (lookahead == 's') ADVANCE(300);
      END_STATE();
    case 499:
      if (lookahead == 's') ADVANCE(301);
      END_STATE();
    case 500:
      if (lookahead == 's') ADVANCE(321);
      END_STATE();
    case 501:
      if (lookahead == 's') ADVANCE(310);
      END_STATE();
    case 502:
      if (lookahead == 's') ADVANCE(461);
      END_STATE();
    case 503:
      if (lookahead == 's') ADVANCE(173);
      END_STATE();
    case 504:
      if (lookahead == 's') ADVANCE(534);
      END_STATE();
    case 505:
      if (lookahead == 's') ADVANCE(593);
      END_STATE();
    case 506:
      if (lookahead == 's') ADVANCE(238);
      END_STATE();
    case 507:
      if (lookahead == 's') ADVANCE(594);
      END_STATE();
    case 508:
      if (lookahead == 's') ADVANCE(187);
      END_STATE();
    case 509:
      if (lookahead == 's') ADVANCE(467);
      END_STATE();
    case 510:
      if (lookahead == 's') ADVANCE(598);
      END_STATE();
    case 511:
      if (lookahead == 's') ADVANCE(190);
      END_STATE();
    case 512:
      if (lookahead == 's') ADVANCE(198);
      END_STATE();
    case 513:
      if (lookahead == 's') ADVANCE(177);
      END_STATE();
    case 514:
      if (lookahead == 's') ADVANCE(179);
      END_STATE();
    case 515:
      if (lookahead == 's') ADVANCE(184);
      END_STATE();
    case 516:
      if (lookahead == 's') ADVANCE(538);
      END_STATE();
    case 517:
      if (lookahead == 's') ADVANCE(486);
      END_STATE();
    case 518:
      if (lookahead == 's') ADVANCE(539);
      END_STATE();
    case 519:
      if (lookahead == 's') ADVANCE(540);
      END_STATE();
    case 520:
      if (lookahead == 's') ADVANCE(541);
      END_STATE();
    case 521:
      if (lookahead == 's') ADVANCE(191);
      END_STATE();
    case 522:
      if (lookahead == 's') ADVANCE(542);
      END_STATE();
    case 523:
      if (lookahead == 's') ADVANCE(221);
      END_STATE();
    case 524:
      if (lookahead == 's') ADVANCE(501);
      END_STATE();
    case 525:
      if (lookahead == 's') ADVANCE(205);
      END_STATE();
    case 526:
      if (lookahead == 's') ADVANCE(546);
      END_STATE();
    case 527:
      if (lookahead == 's') ADVANCE(260);
      END_STATE();
    case 528:
      if (lookahead == 's') ADVANCE(266);
      END_STATE();
    case 529:
      if (lookahead == 't') ADVANCE(152);
      END_STATE();
    case 530:
      if (lookahead == 't') ADVANCE(476);
      END_STATE();
    case 531:
      if (lookahead == 't') ADVANCE(153);
      END_STATE();
    case 532:
      if (lookahead == 't') ADVANCE(76);
      END_STATE();
    case 533:
      if (lookahead == 't') ADVANCE(703);
      END_STATE();
    case 534:
      if (lookahead == 't') ADVANCE(896);
      END_STATE();
    case 535:
      if (lookahead == 't') ADVANCE(899);
      END_STATE();
    case 536:
      if (lookahead == 't') ADVANCE(802);
      END_STATE();
    case 537:
      if (lookahead == 't') ADVANCE(6);
      END_STATE();
    case 538:
      if (lookahead == 't') ADVANCE(636);
      END_STATE();
    case 539:
      if (lookahead == 't') ADVANCE(638);
      END_STATE();
    case 540:
      if (lookahead == 't') ADVANCE(307);
      END_STATE();
    case 541:
      if (lookahead == 't') ADVANCE(905);
      END_STATE();
    case 542:
      if (lookahead == 't') ADVANCE(639);
      END_STATE();
    case 543:
      if (lookahead == 't') ADVANCE(275);
      END_STATE();
    case 544:
      if (lookahead == 't') ADVANCE(587);
      END_STATE();
    case 545:
      if (lookahead == 't') ADVANCE(490);
      END_STATE();
    case 546:
      if (lookahead == 't') ADVANCE(208);
      END_STATE();
    case 547:
      if (lookahead == 't') ADVANCE(382);
      END_STATE();
    case 548:
      if (lookahead == 't') ADVANCE(121);
      END_STATE();
    case 549:
      if (lookahead == 't') ADVANCE(302);
      END_STATE();
    case 550:
      if (lookahead == 't') ADVANCE(460);
      END_STATE();
    case 551:
      if (lookahead == 't') ADVANCE(473);
      END_STATE();
    case 552:
      if (lookahead == 't') ADVANCE(249);
      END_STATE();
    case 553:
      if (lookahead == 't') ADVANCE(138);
      END_STATE();
    case 554:
      if (lookahead == 't') ADVANCE(471);
      END_STATE();
    case 555:
      if (lookahead == 't') ADVANCE(185);
      END_STATE();
    case 556:
      if (lookahead == 't') ADVANCE(194);
      END_STATE();
    case 557:
      if (lookahead == 't') ADVANCE(568);
      END_STATE();
    case 558:
      if (lookahead == 't') ADVANCE(569);
      END_STATE();
    case 559:
      if (lookahead == 'u') ADVANCE(306);
      END_STATE();
    case 560:
      if (lookahead == 'u') ADVANCE(269);
      END_STATE();
    case 561:
      if (lookahead == 'u') ADVANCE(270);
      END_STATE();
    case 562:
      if (lookahead == 'u') ADVANCE(342);
      END_STATE();
    case 563:
      if (lookahead == 'u') ADVANCE(271);
      END_STATE();
    case 564:
      if (lookahead == 'u') ADVANCE(326);
      END_STATE();
    case 565:
      if (lookahead == 'u') ADVANCE(493);
      END_STATE();
    case 566:
      if (lookahead == 'u') ADVANCE(213);
      END_STATE();
    case 567:
      if (lookahead == 'u') ADVANCE(333);
      END_STATE();
    case 568:
      if (lookahead == 'u') ADVANCE(495);
      END_STATE();
    case 569:
      if (lookahead == 'u') ADVANCE(202);
      END_STATE();
    case 570:
      if (lookahead == 'u') ADVANCE(124);
      if (lookahead == 'w') ADVANCE(186);
      END_STATE();
    case 571:
      if (lookahead == 'u') ADVANCE(345);
      END_STATE();
    case 572:
      if (lookahead == 'u') ADVANCE(125);
      if (lookahead == 'w') ADVANCE(197);
      END_STATE();
    case 573:
      if (lookahead == 'u') ADVANCE(523);
      END_STATE();
    case 574:
      if (lookahead == 'v') ADVANCE(695);
      END_STATE();
    case 575:
      if (lookahead == 'v') ADVANCE(725);
      END_STATE();
    case 576:
      if (lookahead == 'v') ADVANCE(77);
      END_STATE();
    case 577:
      if (lookahead == 'v') ADVANCE(708);
      END_STATE();
    case 578:
      if (lookahead == 'v') ADVANCE(94);
      END_STATE();
    case 579:
      if (lookahead == 'v') ADVANCE(1004);
      END_STATE();
    case 580:
      if (lookahead == 'v') ADVANCE(586);
      END_STATE();
    case 581:
      if (lookahead == 'v') ADVANCE(513);
      END_STATE();
    case 582:
      if (lookahead == 'v') ADVANCE(557);
      END_STATE();
    case 583:
      if (lookahead == 'v') ADVANCE(356);
      END_STATE();
    case 584:
      if (lookahead == 'v') ADVANCE(417);
      END_STATE();
    case 585:
      if (lookahead == 'w') ADVANCE(656);
      END_STATE();
    case 586:
      if (lookahead == 'w') ADVANCE(715);
      END_STATE();
    case 587:
      if (lookahead == 'w') ADVANCE(716);
      END_STATE();
    case 588:
      if (lookahead == 'w') ADVANCE(784);
      END_STATE();
    case 589:
      if (lookahead == 'w') ADVANCE(808);
      END_STATE();
    case 590:
      if (lookahead == 'w') ADVANCE(809);
      END_STATE();
    case 591:
      if (lookahead == 'w') ADVANCE(956);
      END_STATE();
    case 592:
      if (lookahead == 'w') ADVANCE(963);
      END_STATE();
    case 593:
      if (lookahead == 'w') ADVANCE(980);
      END_STATE();
    case 594:
      if (lookahead == 'w') ADVANCE(797);
      END_STATE();
    case 595:
      if (lookahead == 'w') ADVANCE(823);
      END_STATE();
    case 596:
      if (lookahead == 'w') ADVANCE(827);
      END_STATE();
    case 597:
      if (lookahead == 'w') ADVANCE(933);
      END_STATE();
    case 598:
      if (lookahead == 'w') ADVANCE(961);
      END_STATE();
    case 599:
      if (lookahead == 'w') ADVANCE(117);
      END_STATE();
    case 600:
      if (lookahead == 'x') ADVANCE(634);
      END_STATE();
    case 601:
      if (lookahead == 'x') ADVANCE(613);
      END_STATE();
    case 602:
      if (lookahead == 'x') ADVANCE(494);
      END_STATE();
    case 603:
      if (lookahead == 'x') ADVANCE(46);
      END_STATE();
    case 604:
      if (lookahead == 'x') ADVANCE(47);
      END_STATE();
    case 605:
      if (lookahead == 'x') ADVANCE(48);
      END_STATE();
    case 606:
      if (lookahead == 'x') ADVANCE(550);
      END_STATE();
    case 607:
      if (lookahead == 'x') ADVANCE(49);
      END_STATE();
    case 608:
      if (lookahead == 'x') ADVANCE(50);
      END_STATE();
    case 609:
      if (lookahead == 'x') ADVANCE(551);
      END_STATE();
    case 610:
      if (lookahead == 'x') ADVANCE(22);
      END_STATE();
    case 611:
      if (lookahead == 'x') ADVANCE(552);
      END_STATE();
    case 612:
      if (lookahead == 'y') ADVANCE(282);
      END_STATE();
    case 613:
      if (lookahead == 'z') ADVANCE(1030);
      END_STATE();
    case 614:
      if (lookahead == 'z') ADVANCE(836);
      END_STATE();
    case 615:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(615)
      if (aux_sym_fn_token1_character_set_2(lookahead)) ADVANCE(1035);
      END_STATE();
    case 616:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(1036);
      END_STATE();
    case 617:
      if (eof) ADVANCE(618);
      if (lookahead == ':') ADVANCE(623);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(617)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(1033);
      END_STATE();
    case 618:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 619:
      ACCEPT_TOKEN(sym__line_break);
      if (lookahead == '\n') ADVANCE(619);
      END_STATE();
    case 620:
      ACCEPT_TOKEN(sym__line_break);
      if (lookahead == '\n') ADVANCE(620);
      if (lookahead == ' ') ADVANCE(1011);
      END_STATE();
    case 621:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(621);
      END_STATE();
    case 622:
      ACCEPT_TOKEN(aux_sym_comment_token2);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(622);
      END_STATE();
    case 623:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 624:
      ACCEPT_TOKEN(anon_sym_adc);
      if (lookahead == 'x') ADVANCE(625);
      END_STATE();
    case 625:
      ACCEPT_TOKEN(anon_sym_adcx);
      END_STATE();
    case 626:
      ACCEPT_TOKEN(anon_sym_add);
      if (lookahead == 'b') ADVANCE(627);
      if (lookahead == 'l') ADVANCE(628);
      if (lookahead == 'q') ADVANCE(629);
      if (lookahead == 'r') ADVANCE(40);
      if (lookahead == 's') ADVANCE(156);
      if (lookahead == 'w') ADVANCE(633);
      END_STATE();
    case 627:
      ACCEPT_TOKEN(anon_sym_addb);
      END_STATE();
    case 628:
      ACCEPT_TOKEN(anon_sym_addl);
      END_STATE();
    case 629:
      ACCEPT_TOKEN(anon_sym_addq);
      END_STATE();
    case 630:
      ACCEPT_TOKEN(anon_sym_addr32);
      END_STATE();
    case 631:
      ACCEPT_TOKEN(anon_sym_addsd);
      END_STATE();
    case 632:
      ACCEPT_TOKEN(anon_sym_addss);
      END_STATE();
    case 633:
      ACCEPT_TOKEN(anon_sym_addw);
      END_STATE();
    case 634:
      ACCEPT_TOKEN(anon_sym_adox);
      END_STATE();
    case 635:
      ACCEPT_TOKEN(anon_sym_aesdec);
      if (lookahead == 'l') ADVANCE(93);
      END_STATE();
    case 636:
      ACCEPT_TOKEN(anon_sym_aesdeclast);
      END_STATE();
    case 637:
      ACCEPT_TOKEN(anon_sym_aesenc);
      if (lookahead == 'l') ADVANCE(96);
      END_STATE();
    case 638:
      ACCEPT_TOKEN(anon_sym_aesenclast);
      END_STATE();
    case 639:
      ACCEPT_TOKEN(anon_sym_aeskeygenassist);
      END_STATE();
    case 640:
      ACCEPT_TOKEN(anon_sym_and);
      if (lookahead == 'b') ADVANCE(641);
      if (lookahead == 'l') ADVANCE(642);
      if (lookahead == 'n') ADVANCE(643);
      if (lookahead == 'p') ADVANCE(157);
      if (lookahead == 'q') ADVANCE(646);
      if (lookahead == 'w') ADVANCE(647);
      END_STATE();
    case 641:
      ACCEPT_TOKEN(anon_sym_andb);
      END_STATE();
    case 642:
      ACCEPT_TOKEN(anon_sym_andl);
      END_STATE();
    case 643:
      ACCEPT_TOKEN(anon_sym_andn);
      END_STATE();
    case 644:
      ACCEPT_TOKEN(anon_sym_andpd);
      END_STATE();
    case 645:
      ACCEPT_TOKEN(anon_sym_andps);
      END_STATE();
    case 646:
      ACCEPT_TOKEN(anon_sym_andq);
      END_STATE();
    case 647:
      ACCEPT_TOKEN(anon_sym_andw);
      END_STATE();
    case 648:
      ACCEPT_TOKEN(anon_sym_blendvps);
      END_STATE();
    case 649:
      ACCEPT_TOKEN(anon_sym_bsf);
      END_STATE();
    case 650:
      ACCEPT_TOKEN(anon_sym_bsr);
      END_STATE();
    case 651:
      ACCEPT_TOKEN(anon_sym_bswap);
      END_STATE();
    case 652:
      ACCEPT_TOKEN(anon_sym_bt);
      if (lookahead == 'l') ADVANCE(653);
      if (lookahead == 'r') ADVANCE(654);
      if (lookahead == 's') ADVANCE(655);
      END_STATE();
    case 653:
      ACCEPT_TOKEN(anon_sym_btl);
      END_STATE();
    case 654:
      ACCEPT_TOKEN(anon_sym_btr);
      END_STATE();
    case 655:
      ACCEPT_TOKEN(anon_sym_bts);
      END_STATE();
    case 656:
      ACCEPT_TOKEN(anon_sym_cbtw);
      END_STATE();
    case 657:
      ACCEPT_TOKEN(anon_sym_cltd);
      END_STATE();
    case 658:
      ACCEPT_TOKEN(anon_sym_cltq);
      END_STATE();
    case 659:
      ACCEPT_TOKEN(anon_sym_cmova);
      if (lookahead == 'e') ADVANCE(660);
      END_STATE();
    case 660:
      ACCEPT_TOKEN(anon_sym_cmovae);
      END_STATE();
    case 661:
      ACCEPT_TOKEN(anon_sym_cmovb);
      if (lookahead == 'e') ADVANCE(662);
      END_STATE();
    case 662:
      ACCEPT_TOKEN(anon_sym_cmovbe);
      END_STATE();
    case 663:
      ACCEPT_TOKEN(anon_sym_cmove);
      END_STATE();
    case 664:
      ACCEPT_TOKEN(anon_sym_cmovg);
      if (lookahead == 'e') ADVANCE(665);
      END_STATE();
    case 665:
      ACCEPT_TOKEN(anon_sym_cmovge);
      END_STATE();
    case 666:
      ACCEPT_TOKEN(anon_sym_cmovl);
      if (lookahead == 'e') ADVANCE(667);
      END_STATE();
    case 667:
      ACCEPT_TOKEN(anon_sym_cmovle);
      END_STATE();
    case 668:
      ACCEPT_TOKEN(anon_sym_cmovne);
      END_STATE();
    case 669:
      ACCEPT_TOKEN(anon_sym_cmovns);
      END_STATE();
    case 670:
      ACCEPT_TOKEN(anon_sym_cmovo);
      END_STATE();
    case 671:
      ACCEPT_TOKEN(anon_sym_cmovp);
      END_STATE();
    case 672:
      ACCEPT_TOKEN(anon_sym_cmovs);
      END_STATE();
    case 673:
      ACCEPT_TOKEN(anon_sym_cmp);
      if (lookahead == 'b') ADVANCE(674);
      if (lookahead == 'l') ADVANCE(675);
      if (lookahead == 'q') ADVANCE(676);
      if (lookahead == 'w') ADVANCE(677);
      END_STATE();
    case 674:
      ACCEPT_TOKEN(anon_sym_cmpb);
      END_STATE();
    case 675:
      ACCEPT_TOKEN(anon_sym_cmpl);
      END_STATE();
    case 676:
      ACCEPT_TOKEN(anon_sym_cmpq);
      END_STATE();
    case 677:
      ACCEPT_TOKEN(anon_sym_cmpw);
      END_STATE();
    case 678:
      ACCEPT_TOKEN(anon_sym_comisd);
      END_STATE();
    case 679:
      ACCEPT_TOKEN(anon_sym_comiss);
      END_STATE();
    case 680:
      ACCEPT_TOKEN(anon_sym_cpuid);
      END_STATE();
    case 681:
      ACCEPT_TOKEN(anon_sym_cqto);
      END_STATE();
    case 682:
      ACCEPT_TOKEN(anon_sym_cvtsd2ss);
      END_STATE();
    case 683:
      ACCEPT_TOKEN(anon_sym_cvtsi2sd);
      if (lookahead == 'l') ADVANCE(684);
      if (lookahead == 'q') ADVANCE(685);
      END_STATE();
    case 684:
      ACCEPT_TOKEN(anon_sym_cvtsi2sdl);
      END_STATE();
    case 685:
      ACCEPT_TOKEN(anon_sym_cvtsi2sdq);
      END_STATE();
    case 686:
      ACCEPT_TOKEN(anon_sym_cvtsi2ss);
      if (lookahead == 'l') ADVANCE(687);
      END_STATE();
    case 687:
      ACCEPT_TOKEN(anon_sym_cvtsi2ssl);
      END_STATE();
    case 688:
      ACCEPT_TOKEN(anon_sym_cvtss2sd);
      END_STATE();
    case 689:
      ACCEPT_TOKEN(anon_sym_cvttsd2si);
      END_STATE();
    case 690:
      ACCEPT_TOKEN(anon_sym_cvttss2si);
      END_STATE();
    case 691:
      ACCEPT_TOKEN(anon_sym_cwtd);
      END_STATE();
    case 692:
      ACCEPT_TOKEN(anon_sym_cwtl);
      END_STATE();
    case 693:
      ACCEPT_TOKEN(anon_sym_data16);
      END_STATE();
    case 694:
      ACCEPT_TOKEN(anon_sym_dec);
      END_STATE();
    case 695:
      ACCEPT_TOKEN(anon_sym_div);
      if (lookahead == 'l') ADVANCE(696);
      if (lookahead == 'q') ADVANCE(697);
      if (lookahead == 's') ADVANCE(159);
      END_STATE();
    case 696:
      ACCEPT_TOKEN(anon_sym_divl);
      END_STATE();
    case 697:
      ACCEPT_TOKEN(anon_sym_divq);
      END_STATE();
    case 698:
      ACCEPT_TOKEN(anon_sym_divsd);
      END_STATE();
    case 699:
      ACCEPT_TOKEN(anon_sym_divss);
      END_STATE();
    case 700:
      ACCEPT_TOKEN(anon_sym_endbr64);
      END_STATE();
    case 701:
      ACCEPT_TOKEN(anon_sym_femms);
      END_STATE();
    case 702:
      ACCEPT_TOKEN(anon_sym_fildl);
      END_STATE();
    case 703:
      ACCEPT_TOKEN(anon_sym_fldt);
      END_STATE();
    case 704:
      ACCEPT_TOKEN(anon_sym_fmulp);
      END_STATE();
    case 705:
      ACCEPT_TOKEN(anon_sym_fs);
      if (lookahead == 't') ADVANCE(406);
      END_STATE();
    case 706:
      ACCEPT_TOKEN(anon_sym_fstpl);
      END_STATE();
    case 707:
      ACCEPT_TOKEN(anon_sym_gs);
      END_STATE();
    case 708:
      ACCEPT_TOKEN(anon_sym_idiv);
      if (lookahead == 'l') ADVANCE(709);
      END_STATE();
    case 709:
      ACCEPT_TOKEN(anon_sym_idivl);
      END_STATE();
    case 710:
      ACCEPT_TOKEN(anon_sym_imul);
      END_STATE();
    case 711:
      ACCEPT_TOKEN(anon_sym_inc);
      if (lookahead == 'l') ADVANCE(712);
      END_STATE();
    case 712:
      ACCEPT_TOKEN(anon_sym_incl);
      END_STATE();
    case 713:
      ACCEPT_TOKEN(anon_sym_insb);
      END_STATE();
    case 714:
      ACCEPT_TOKEN(anon_sym_insl);
      END_STATE();
    case 715:
      ACCEPT_TOKEN(anon_sym_kmovw);
      END_STATE();
    case 716:
      ACCEPT_TOKEN(anon_sym_knotw);
      END_STATE();
    case 717:
      ACCEPT_TOKEN(anon_sym_lea);
      if (lookahead == 'v') ADVANCE(253);
      END_STATE();
    case 718:
      ACCEPT_TOKEN(anon_sym_leaveq);
      END_STATE();
    case 719:
      ACCEPT_TOKEN(anon_sym_lock);
      END_STATE();
    case 720:
      ACCEPT_TOKEN(anon_sym_maxsd);
      END_STATE();
    case 721:
      ACCEPT_TOKEN(anon_sym_maxss);
      END_STATE();
    case 722:
      ACCEPT_TOKEN(anon_sym_mfence);
      END_STATE();
    case 723:
      ACCEPT_TOKEN(anon_sym_minsd);
      END_STATE();
    case 724:
      ACCEPT_TOKEN(anon_sym_minss);
      END_STATE();
    case 725:
      ACCEPT_TOKEN(anon_sym_mov);
      if (lookahead == 'a') ADVANCE(120);
      if (lookahead == 'b') ADVANCE(729);
      if (lookahead == 'd') ADVANCE(731);
      if (lookahead == 'h') ADVANCE(347);
      if (lookahead == 'l') ADVANCE(736);
      if (lookahead == 'q') ADVANCE(737);
      if (lookahead == 's') ADVANCE(104);
      if (lookahead == 'u') ADVANCE(408);
      if (lookahead == 'w') ADVANCE(748);
      if (lookahead == 'z') ADVANCE(105);
      END_STATE();
    case 726:
      ACCEPT_TOKEN(anon_sym_movabs);
      END_STATE();
    case 727:
      ACCEPT_TOKEN(anon_sym_movapd);
      END_STATE();
    case 728:
      ACCEPT_TOKEN(anon_sym_movaps);
      END_STATE();
    case 729:
      ACCEPT_TOKEN(anon_sym_movb);
      if (lookahead == 'e') ADVANCE(730);
      END_STATE();
    case 730:
      ACCEPT_TOKEN(anon_sym_movbe);
      END_STATE();
    case 731:
      ACCEPT_TOKEN(anon_sym_movd);
      if (lookahead == 'q') ADVANCE(78);
      END_STATE();
    case 732:
      ACCEPT_TOKEN(anon_sym_movdqa);
      END_STATE();
    case 733:
      ACCEPT_TOKEN(anon_sym_movdqu);
      END_STATE();
    case 734:
      ACCEPT_TOKEN(anon_sym_movhlps);
      END_STATE();
    case 735:
      ACCEPT_TOKEN(anon_sym_movhps);
      END_STATE();
    case 736:
      ACCEPT_TOKEN(anon_sym_movl);
      END_STATE();
    case 737:
      ACCEPT_TOKEN(anon_sym_movq);
      END_STATE();
    case 738:
      ACCEPT_TOKEN(anon_sym_movsb);
      if (lookahead == 'l') ADVANCE(739);
      if (lookahead == 'q') ADVANCE(740);
      if (lookahead == 'w') ADVANCE(741);
      END_STATE();
    case 739:
      ACCEPT_TOKEN(anon_sym_movsbl);
      END_STATE();
    case 740:
      ACCEPT_TOKEN(anon_sym_movsbq);
      END_STATE();
    case 741:
      ACCEPT_TOKEN(anon_sym_movsbw);
      END_STATE();
    case 742:
      ACCEPT_TOKEN(anon_sym_movsd);
      END_STATE();
    case 743:
      ACCEPT_TOKEN(anon_sym_movslq);
      END_STATE();
    case 744:
      ACCEPT_TOKEN(anon_sym_movss);
      END_STATE();
    case 745:
      ACCEPT_TOKEN(anon_sym_movswl);
      END_STATE();
    case 746:
      ACCEPT_TOKEN(anon_sym_movswq);
      END_STATE();
    case 747:
      ACCEPT_TOKEN(anon_sym_movups);
      END_STATE();
    case 748:
      ACCEPT_TOKEN(anon_sym_movw);
      END_STATE();
    case 749:
      ACCEPT_TOKEN(anon_sym_movzbl);
      END_STATE();
    case 750:
      ACCEPT_TOKEN(anon_sym_movzbq);
      END_STATE();
    case 751:
      ACCEPT_TOKEN(anon_sym_movzbw);
      END_STATE();
    case 752:
      ACCEPT_TOKEN(anon_sym_movzwl);
      END_STATE();
    case 753:
      ACCEPT_TOKEN(anon_sym_mul);
      if (lookahead == 'b') ADVANCE(754);
      if (lookahead == 'l') ADVANCE(755);
      if (lookahead == 'q') ADVANCE(756);
      if (lookahead == 's') ADVANCE(162);
      if (lookahead == 'w') ADVANCE(759);
      if (lookahead == 'x') ADVANCE(760);
      END_STATE();
    case 754:
      ACCEPT_TOKEN(anon_sym_mulb);
      END_STATE();
    case 755:
      ACCEPT_TOKEN(anon_sym_mull);
      END_STATE();
    case 756:
      ACCEPT_TOKEN(anon_sym_mulq);
      END_STATE();
    case 757:
      ACCEPT_TOKEN(anon_sym_mulsd);
      END_STATE();
    case 758:
      ACCEPT_TOKEN(anon_sym_mulss);
      END_STATE();
    case 759:
      ACCEPT_TOKEN(anon_sym_mulw);
      END_STATE();
    case 760:
      ACCEPT_TOKEN(anon_sym_mulx);
      END_STATE();
    case 761:
      ACCEPT_TOKEN(anon_sym_neg);
      if (lookahead == 'l') ADVANCE(762);
      if (lookahead == 'q') ADVANCE(763);
      END_STATE();
    case 762:
      ACCEPT_TOKEN(anon_sym_negl);
      END_STATE();
    case 763:
      ACCEPT_TOKEN(anon_sym_negq);
      END_STATE();
    case 764:
      ACCEPT_TOKEN(anon_sym_nop);
      if (lookahead == 'l') ADVANCE(765);
      if (lookahead == 'w') ADVANCE(766);
      END_STATE();
    case 765:
      ACCEPT_TOKEN(anon_sym_nopl);
      END_STATE();
    case 766:
      ACCEPT_TOKEN(anon_sym_nopw);
      END_STATE();
    case 767:
      ACCEPT_TOKEN(anon_sym_not);
      if (lookahead == 'l') ADVANCE(768);
      if (lookahead == 'r') ADVANCE(85);
      if (lookahead == 'w') ADVANCE(769);
      END_STATE();
    case 768:
      ACCEPT_TOKEN(anon_sym_notl);
      END_STATE();
    case 769:
      ACCEPT_TOKEN(anon_sym_notw);
      END_STATE();
    case 770:
      ACCEPT_TOKEN(anon_sym_or);
      if (lookahead == 'b') ADVANCE(771);
      if (lookahead == 'l') ADVANCE(772);
      if (lookahead == 'q') ADVANCE(773);
      if (lookahead == 'w') ADVANCE(774);
      END_STATE();
    case 771:
      ACCEPT_TOKEN(anon_sym_orb);
      END_STATE();
    case 772:
      ACCEPT_TOKEN(anon_sym_orl);
      END_STATE();
    case 773:
      ACCEPT_TOKEN(anon_sym_orq);
      END_STATE();
    case 774:
      ACCEPT_TOKEN(anon_sym_orw);
      END_STATE();
    case 775:
      ACCEPT_TOKEN(anon_sym_outsb);
      END_STATE();
    case 776:
      ACCEPT_TOKEN(anon_sym_outsl);
      END_STATE();
    case 777:
      ACCEPT_TOKEN(anon_sym_packuswb);
      END_STATE();
    case 778:
      ACCEPT_TOKEN(anon_sym_paddd);
      END_STATE();
    case 779:
      ACCEPT_TOKEN(anon_sym_paddq);
      END_STATE();
    case 780:
      ACCEPT_TOKEN(anon_sym_paddw);
      END_STATE();
    case 781:
      ACCEPT_TOKEN(anon_sym_palignr);
      END_STATE();
    case 782:
      ACCEPT_TOKEN(anon_sym_pand);
      if (lookahead == 'n') ADVANCE(783);
      END_STATE();
    case 783:
      ACCEPT_TOKEN(anon_sym_pandn);
      END_STATE();
    case 784:
      ACCEPT_TOKEN(anon_sym_pblendw);
      END_STATE();
    case 785:
      ACCEPT_TOKEN(anon_sym_pclmulhqhqdq);
      END_STATE();
    case 786:
      ACCEPT_TOKEN(anon_sym_pclmullqhqdq);
      END_STATE();
    case 787:
      ACCEPT_TOKEN(anon_sym_pclmullqlqdq);
      END_STATE();
    case 788:
      ACCEPT_TOKEN(anon_sym_pcmpeqb);
      END_STATE();
    case 789:
      ACCEPT_TOKEN(anon_sym_pcmpeqd);
      END_STATE();
    case 790:
      ACCEPT_TOKEN(anon_sym_pcmpgtd);
      END_STATE();
    case 791:
      ACCEPT_TOKEN(anon_sym_pextrb);
      END_STATE();
    case 792:
      ACCEPT_TOKEN(anon_sym_pextrq);
      END_STATE();
    case 793:
      ACCEPT_TOKEN(anon_sym_pextrw);
      END_STATE();
    case 794:
      ACCEPT_TOKEN(anon_sym_pinsrb);
      END_STATE();
    case 795:
      ACCEPT_TOKEN(anon_sym_pinsrd);
      END_STATE();
    case 796:
      ACCEPT_TOKEN(anon_sym_pinsrw);
      END_STATE();
    case 797:
      ACCEPT_TOKEN(anon_sym_pmaddubsw);
      END_STATE();
    case 798:
      ACCEPT_TOKEN(anon_sym_pmaddwd);
      END_STATE();
    case 799:
      ACCEPT_TOKEN(anon_sym_pmovmskb);
      END_STATE();
    case 800:
      ACCEPT_TOKEN(anon_sym_pmuludq);
      END_STATE();
    case 801:
      ACCEPT_TOKEN(anon_sym_pop);
      if (lookahead == 'c') ADVANCE(373);
      END_STATE();
    case 802:
      ACCEPT_TOKEN(anon_sym_popcnt);
      END_STATE();
    case 803:
      ACCEPT_TOKEN(anon_sym_por);
      END_STATE();
    case 804:
      ACCEPT_TOKEN(anon_sym_prefetcht0);
      END_STATE();
    case 805:
      ACCEPT_TOKEN(anon_sym_prefetcht1);
      END_STATE();
    case 806:
      ACCEPT_TOKEN(anon_sym_pshufb);
      END_STATE();
    case 807:
      ACCEPT_TOKEN(anon_sym_pshufd);
      END_STATE();
    case 808:
      ACCEPT_TOKEN(anon_sym_pshufhw);
      END_STATE();
    case 809:
      ACCEPT_TOKEN(anon_sym_pshuflw);
      END_STATE();
    case 810:
      ACCEPT_TOKEN(anon_sym_pslld);
      if (lookahead == 'q') ADVANCE(811);
      END_STATE();
    case 811:
      ACCEPT_TOKEN(anon_sym_pslldq);
      END_STATE();
    case 812:
      ACCEPT_TOKEN(anon_sym_psllq);
      END_STATE();
    case 813:
      ACCEPT_TOKEN(anon_sym_psrad);
      END_STATE();
    case 814:
      ACCEPT_TOKEN(anon_sym_psrld);
      if (lookahead == 'q') ADVANCE(815);
      END_STATE();
    case 815:
      ACCEPT_TOKEN(anon_sym_psrldq);
      END_STATE();
    case 816:
      ACCEPT_TOKEN(anon_sym_psrlq);
      END_STATE();
    case 817:
      ACCEPT_TOKEN(anon_sym_psrlw);
      END_STATE();
    case 818:
      ACCEPT_TOKEN(anon_sym_psubb);
      END_STATE();
    case 819:
      ACCEPT_TOKEN(anon_sym_psubd);
      END_STATE();
    case 820:
      ACCEPT_TOKEN(anon_sym_psubq);
      END_STATE();
    case 821:
      ACCEPT_TOKEN(anon_sym_psubusb);
      END_STATE();
    case 822:
      ACCEPT_TOKEN(anon_sym_psubusw);
      END_STATE();
    case 823:
      ACCEPT_TOKEN(anon_sym_punpckhbw);
      END_STATE();
    case 824:
      ACCEPT_TOKEN(anon_sym_punpckhdq);
      END_STATE();
    case 825:
      ACCEPT_TOKEN(anon_sym_punpckhqdq);
      END_STATE();
    case 826:
      ACCEPT_TOKEN(anon_sym_punpckhwd);
      END_STATE();
    case 827:
      ACCEPT_TOKEN(anon_sym_punpcklbw);
      END_STATE();
    case 828:
      ACCEPT_TOKEN(anon_sym_punpckldq);
      END_STATE();
    case 829:
      ACCEPT_TOKEN(anon_sym_punpcklqdq);
      END_STATE();
    case 830:
      ACCEPT_TOKEN(anon_sym_punpcklwd);
      END_STATE();
    case 831:
      ACCEPT_TOKEN(anon_sym_push);
      if (lookahead == 'q') ADVANCE(832);
      END_STATE();
    case 832:
      ACCEPT_TOKEN(anon_sym_pushq);
      END_STATE();
    case 833:
      ACCEPT_TOKEN(anon_sym_pxor);
      END_STATE();
    case 834:
      ACCEPT_TOKEN(anon_sym_re);
      if (lookahead == 'p') ADVANCE(835);
      if (lookahead == 't') ADVANCE(422);
      if (lookahead == 'x') ADVANCE(839);
      END_STATE();
    case 835:
      ACCEPT_TOKEN(anon_sym_rep);
      if (lookahead == 'n') ADVANCE(614);
      if (lookahead == 'z') ADVANCE(837);
      END_STATE();
    case 836:
      ACCEPT_TOKEN(anon_sym_repnz);
      END_STATE();
    case 837:
      ACCEPT_TOKEN(anon_sym_repz);
      END_STATE();
    case 838:
      ACCEPT_TOKEN(anon_sym_retq);
      END_STATE();
    case 839:
      ACCEPT_TOKEN(anon_sym_rex);
      if (lookahead == '.') ADVANCE(63);
      END_STATE();
    case 840:
      ACCEPT_TOKEN(anon_sym_rex_DOTB);
      END_STATE();
    case 841:
      ACCEPT_TOKEN(anon_sym_rex_DOTRB);
      END_STATE();
    case 842:
      ACCEPT_TOKEN(anon_sym_rex_DOTRXB);
      END_STATE();
    case 843:
      ACCEPT_TOKEN(anon_sym_rex_DOTW);
      if (lookahead == 'B') ADVANCE(844);
      if (lookahead == 'R') ADVANCE(67);
      END_STATE();
    case 844:
      ACCEPT_TOKEN(anon_sym_rex_DOTWB);
      END_STATE();
    case 845:
      ACCEPT_TOKEN(anon_sym_rex_DOTWRB);
      END_STATE();
    case 846:
      ACCEPT_TOKEN(anon_sym_rex_DOTWRXB);
      END_STATE();
    case 847:
      ACCEPT_TOKEN(anon_sym_rex_DOTXB);
      END_STATE();
    case 848:
      ACCEPT_TOKEN(anon_sym_rol);
      if (lookahead == 'l') ADVANCE(849);
      END_STATE();
    case 849:
      ACCEPT_TOKEN(anon_sym_roll);
      END_STATE();
    case 850:
      ACCEPT_TOKEN(anon_sym_ror);
      if (lookahead == 'l') ADVANCE(851);
      if (lookahead == 'x') ADVANCE(852);
      END_STATE();
    case 851:
      ACCEPT_TOKEN(anon_sym_rorl);
      END_STATE();
    case 852:
      ACCEPT_TOKEN(anon_sym_rorx);
      END_STATE();
    case 853:
      ACCEPT_TOKEN(anon_sym_sar);
      if (lookahead == 'l') ADVANCE(854);
      if (lookahead == 'x') ADVANCE(855);
      END_STATE();
    case 854:
      ACCEPT_TOKEN(anon_sym_sarl);
      END_STATE();
    case 855:
      ACCEPT_TOKEN(anon_sym_sarx);
      END_STATE();
    case 856:
      ACCEPT_TOKEN(anon_sym_sbb);
      END_STATE();
    case 857:
      ACCEPT_TOKEN(anon_sym_seta);
      if (lookahead == 'e') ADVANCE(858);
      END_STATE();
    case 858:
      ACCEPT_TOKEN(anon_sym_setae);
      END_STATE();
    case 859:
      ACCEPT_TOKEN(anon_sym_setb);
      if (lookahead == 'e') ADVANCE(860);
      END_STATE();
    case 860:
      ACCEPT_TOKEN(anon_sym_setbe);
      END_STATE();
    case 861:
      ACCEPT_TOKEN(anon_sym_sete);
      END_STATE();
    case 862:
      ACCEPT_TOKEN(anon_sym_setg);
      if (lookahead == 'e') ADVANCE(863);
      END_STATE();
    case 863:
      ACCEPT_TOKEN(anon_sym_setge);
      END_STATE();
    case 864:
      ACCEPT_TOKEN(anon_sym_setl);
      if (lookahead == 'e') ADVANCE(865);
      END_STATE();
    case 865:
      ACCEPT_TOKEN(anon_sym_setle);
      END_STATE();
    case 866:
      ACCEPT_TOKEN(anon_sym_setne);
      END_STATE();
    case 867:
      ACCEPT_TOKEN(anon_sym_setnp);
      END_STATE();
    case 868:
      ACCEPT_TOKEN(anon_sym_setns);
      END_STATE();
    case 869:
      ACCEPT_TOKEN(anon_sym_seto);
      END_STATE();
    case 870:
      ACCEPT_TOKEN(anon_sym_setp);
      END_STATE();
    case 871:
      ACCEPT_TOKEN(anon_sym_sha1msg1);
      END_STATE();
    case 872:
      ACCEPT_TOKEN(anon_sym_sha1msg2);
      END_STATE();
    case 873:
      ACCEPT_TOKEN(anon_sym_sha1nexte);
      END_STATE();
    case 874:
      ACCEPT_TOKEN(anon_sym_sha1rnds4);
      END_STATE();
    case 875:
      ACCEPT_TOKEN(anon_sym_shl);
      if (lookahead == 'd') ADVANCE(876);
      if (lookahead == 'l') ADVANCE(877);
      if (lookahead == 'q') ADVANCE(878);
      if (lookahead == 'x') ADVANCE(879);
      END_STATE();
    case 876:
      ACCEPT_TOKEN(anon_sym_shld);
      END_STATE();
    case 877:
      ACCEPT_TOKEN(anon_sym_shll);
      END_STATE();
    case 878:
      ACCEPT_TOKEN(anon_sym_shlq);
      END_STATE();
    case 879:
      ACCEPT_TOKEN(anon_sym_shlx);
      END_STATE();
    case 880:
      ACCEPT_TOKEN(anon_sym_shr);
      if (lookahead == 'd') ADVANCE(881);
      if (lookahead == 'l') ADVANCE(882);
      if (lookahead == 'q') ADVANCE(883);
      if (lookahead == 'x') ADVANCE(884);
      END_STATE();
    case 881:
      ACCEPT_TOKEN(anon_sym_shrd);
      END_STATE();
    case 882:
      ACCEPT_TOKEN(anon_sym_shrl);
      END_STATE();
    case 883:
      ACCEPT_TOKEN(anon_sym_shrq);
      END_STATE();
    case 884:
      ACCEPT_TOKEN(anon_sym_shrx);
      END_STATE();
    case 885:
      ACCEPT_TOKEN(anon_sym_shufpd);
      END_STATE();
    case 886:
      ACCEPT_TOKEN(anon_sym_shufps);
      END_STATE();
    case 887:
      ACCEPT_TOKEN(anon_sym_ss);
      END_STATE();
    case 888:
      ACCEPT_TOKEN(anon_sym_sub);
      if (lookahead == 'b') ADVANCE(889);
      if (lookahead == 'l') ADVANCE(890);
      if (lookahead == 'p') ADVANCE(168);
      if (lookahead == 'q') ADVANCE(892);
      if (lookahead == 's') ADVANCE(169);
      if (lookahead == 'w') ADVANCE(895);
      END_STATE();
    case 889:
      ACCEPT_TOKEN(anon_sym_subb);
      END_STATE();
    case 890:
      ACCEPT_TOKEN(anon_sym_subl);
      END_STATE();
    case 891:
      ACCEPT_TOKEN(anon_sym_subpd);
      END_STATE();
    case 892:
      ACCEPT_TOKEN(anon_sym_subq);
      END_STATE();
    case 893:
      ACCEPT_TOKEN(anon_sym_subsd);
      END_STATE();
    case 894:
      ACCEPT_TOKEN(anon_sym_subss);
      END_STATE();
    case 895:
      ACCEPT_TOKEN(anon_sym_subw);
      END_STATE();
    case 896:
      ACCEPT_TOKEN(anon_sym_test);
      if (lookahead == 'b') ADVANCE(897);
      if (lookahead == 'l') ADVANCE(898);
      END_STATE();
    case 897:
      ACCEPT_TOKEN(anon_sym_testb);
      END_STATE();
    case 898:
      ACCEPT_TOKEN(anon_sym_testl);
      END_STATE();
    case 899:
      ACCEPT_TOKEN(anon_sym_tzcnt);
      END_STATE();
    case 900:
      ACCEPT_TOKEN(anon_sym_ucomisd);
      END_STATE();
    case 901:
      ACCEPT_TOKEN(anon_sym_ucomiss);
      END_STATE();
    case 902:
      ACCEPT_TOKEN(anon_sym_ud2);
      END_STATE();
    case 903:
      ACCEPT_TOKEN(anon_sym_unpckhpd);
      END_STATE();
    case 904:
      ACCEPT_TOKEN(anon_sym_vaesenc);
      if (lookahead == 'l') ADVANCE(98);
      END_STATE();
    case 905:
      ACCEPT_TOKEN(anon_sym_vaesenclast);
      END_STATE();
    case 906:
      ACCEPT_TOKEN(anon_sym_vblendps);
      END_STATE();
    case 907:
      ACCEPT_TOKEN(anon_sym_vblendvps);
      END_STATE();
    case 908:
      ACCEPT_TOKEN(anon_sym_vbroadcasti128);
      END_STATE();
    case 909:
      ACCEPT_TOKEN(anon_sym_vbroadcasti32x4);
      END_STATE();
    case 910:
      ACCEPT_TOKEN(anon_sym_vbroadcastss);
      END_STATE();
    case 911:
      ACCEPT_TOKEN(anon_sym_vcvtusi2sd);
      END_STATE();
    case 912:
      ACCEPT_TOKEN(anon_sym_vdivsd);
      END_STATE();
    case 913:
      ACCEPT_TOKEN(anon_sym_vextracti128);
      END_STATE();
    case 914:
      ACCEPT_TOKEN(anon_sym_vextracti32x4);
      END_STATE();
    case 915:
      ACCEPT_TOKEN(anon_sym_vinsertf128);
      END_STATE();
    case 916:
      ACCEPT_TOKEN(anon_sym_vinserti128);
      END_STATE();
    case 917:
      ACCEPT_TOKEN(anon_sym_vinserti32x4);
      END_STATE();
    case 918:
      ACCEPT_TOKEN(anon_sym_vinserti64x4);
      END_STATE();
    case 919:
      ACCEPT_TOKEN(anon_sym_vmovapd);
      END_STATE();
    case 920:
      ACCEPT_TOKEN(anon_sym_vmovaps);
      END_STATE();
    case 921:
      ACCEPT_TOKEN(anon_sym_vmovd);
      if (lookahead == 'q') ADVANCE(79);
      END_STATE();
    case 922:
      ACCEPT_TOKEN(anon_sym_vmovdqa);
      if (lookahead == '3') ADVANCE(19);
      if (lookahead == '6') ADVANCE(44);
      END_STATE();
    case 923:
      ACCEPT_TOKEN(anon_sym_vmovdqa32);
      END_STATE();
    case 924:
      ACCEPT_TOKEN(anon_sym_vmovdqa64);
      END_STATE();
    case 925:
      ACCEPT_TOKEN(anon_sym_vmovdqu);
      if (lookahead == '3') ADVANCE(20);
      if (lookahead == '6') ADVANCE(45);
      END_STATE();
    case 926:
      ACCEPT_TOKEN(anon_sym_vmovdqu32);
      END_STATE();
    case 927:
      ACCEPT_TOKEN(anon_sym_vmovdqu64);
      END_STATE();
    case 928:
      ACCEPT_TOKEN(anon_sym_vmovq);
      END_STATE();
    case 929:
      ACCEPT_TOKEN(anon_sym_vmovsd);
      END_STATE();
    case 930:
      ACCEPT_TOKEN(anon_sym_vmovss);
      END_STATE();
    case 931:
      ACCEPT_TOKEN(anon_sym_vmovups);
      END_STATE();
    case 932:
      ACCEPT_TOKEN(anon_sym_vmulsd);
      END_STATE();
    case 933:
      ACCEPT_TOKEN(anon_sym_vpackusdw);
      END_STATE();
    case 934:
      ACCEPT_TOKEN(anon_sym_vpaddb);
      END_STATE();
    case 935:
      ACCEPT_TOKEN(anon_sym_vpaddd);
      END_STATE();
    case 936:
      ACCEPT_TOKEN(anon_sym_vpaddq);
      END_STATE();
    case 937:
      ACCEPT_TOKEN(anon_sym_vpaddw);
      END_STATE();
    case 938:
      ACCEPT_TOKEN(anon_sym_vpalignr);
      END_STATE();
    case 939:
      ACCEPT_TOKEN(anon_sym_vpand);
      END_STATE();
    case 940:
      ACCEPT_TOKEN(anon_sym_vpblendd);
      END_STATE();
    case 941:
      ACCEPT_TOKEN(anon_sym_vpblendmd);
      END_STATE();
    case 942:
      ACCEPT_TOKEN(anon_sym_vpbroadcastd);
      END_STATE();
    case 943:
      ACCEPT_TOKEN(anon_sym_vpbroadcastq);
      END_STATE();
    case 944:
      ACCEPT_TOKEN(anon_sym_vpclmulhqhqdq);
      END_STATE();
    case 945:
      ACCEPT_TOKEN(anon_sym_vpclmulhqlqdq);
      END_STATE();
    case 946:
      ACCEPT_TOKEN(anon_sym_vpclmullqhqdq);
      END_STATE();
    case 947:
      ACCEPT_TOKEN(anon_sym_vpclmullqlqdq);
      END_STATE();
    case 948:
      ACCEPT_TOKEN(anon_sym_vpcmpgtd);
      END_STATE();
    case 949:
      ACCEPT_TOKEN(anon_sym_vpcmpltud);
      END_STATE();
    case 950:
      ACCEPT_TOKEN(anon_sym_vperm2f128);
      END_STATE();
    case 951:
      ACCEPT_TOKEN(anon_sym_vperm2i128);
      END_STATE();
    case 952:
      ACCEPT_TOKEN(anon_sym_vpermd);
      END_STATE();
    case 953:
      ACCEPT_TOKEN(anon_sym_vpermi2d);
      END_STATE();
    case 954:
      ACCEPT_TOKEN(anon_sym_vpermq);
      END_STATE();
    case 955:
      ACCEPT_TOKEN(anon_sym_vpermt2d);
      END_STATE();
    case 956:
      ACCEPT_TOKEN(anon_sym_vpextrw);
      END_STATE();
    case 957:
      ACCEPT_TOKEN(anon_sym_vpinsrb);
      END_STATE();
    case 958:
      ACCEPT_TOKEN(anon_sym_vpinsrd);
      END_STATE();
    case 959:
      ACCEPT_TOKEN(anon_sym_vpinsrq);
      END_STATE();
    case 960:
      ACCEPT_TOKEN(anon_sym_vpinsrw);
      END_STATE();
    case 961:
      ACCEPT_TOKEN(anon_sym_vpmaddubsw);
      END_STATE();
    case 962:
      ACCEPT_TOKEN(anon_sym_vpmaddwd);
      END_STATE();
    case 963:
      ACCEPT_TOKEN(anon_sym_vpmullw);
      END_STATE();
    case 964:
      ACCEPT_TOKEN(anon_sym_vpmuludq);
      END_STATE();
    case 965:
      ACCEPT_TOKEN(anon_sym_vpor);
      END_STATE();
    case 966:
      ACCEPT_TOKEN(anon_sym_vprord);
      END_STATE();
    case 967:
      ACCEPT_TOKEN(anon_sym_vprorq);
      END_STATE();
    case 968:
      ACCEPT_TOKEN(anon_sym_vpshufb);
      END_STATE();
    case 969:
      ACCEPT_TOKEN(anon_sym_vpshufd);
      END_STATE();
    case 970:
      ACCEPT_TOKEN(anon_sym_vpslld);
      if (lookahead == 'q') ADVANCE(971);
      END_STATE();
    case 971:
      ACCEPT_TOKEN(anon_sym_vpslldq);
      END_STATE();
    case 972:
      ACCEPT_TOKEN(anon_sym_vpsllq);
      END_STATE();
    case 973:
      ACCEPT_TOKEN(anon_sym_vpsllw);
      END_STATE();
    case 974:
      ACCEPT_TOKEN(anon_sym_vpsrld);
      if (lookahead == 'q') ADVANCE(975);
      END_STATE();
    case 975:
      ACCEPT_TOKEN(anon_sym_vpsrldq);
      END_STATE();
    case 976:
      ACCEPT_TOKEN(anon_sym_vpsrlq);
      END_STATE();
    case 977:
      ACCEPT_TOKEN(anon_sym_vpsrlw);
      END_STATE();
    case 978:
      ACCEPT_TOKEN(anon_sym_vpsubd);
      END_STATE();
    case 979:
      ACCEPT_TOKEN(anon_sym_vpsubq);
      END_STATE();
    case 980:
      ACCEPT_TOKEN(anon_sym_vpsubusw);
      END_STATE();
    case 981:
      ACCEPT_TOKEN(anon_sym_vpsubw);
      END_STATE();
    case 982:
      ACCEPT_TOKEN(anon_sym_vpunpckhdq);
      END_STATE();
    case 983:
      ACCEPT_TOKEN(anon_sym_vpunpckhqdq);
      END_STATE();
    case 984:
      ACCEPT_TOKEN(anon_sym_vpunpckhwd);
      END_STATE();
    case 985:
      ACCEPT_TOKEN(anon_sym_vpunpckldq);
      END_STATE();
    case 986:
      ACCEPT_TOKEN(anon_sym_vpunpcklqdq);
      END_STATE();
    case 987:
      ACCEPT_TOKEN(anon_sym_vpunpcklwd);
      END_STATE();
    case 988:
      ACCEPT_TOKEN(anon_sym_vpxor);
      if (lookahead == 'd') ADVANCE(989);
      END_STATE();
    case 989:
      ACCEPT_TOKEN(anon_sym_vpxord);
      END_STATE();
    case 990:
      ACCEPT_TOKEN(anon_sym_vshufi32x4);
      END_STATE();
    case 991:
      ACCEPT_TOKEN(anon_sym_vshufi64x2);
      END_STATE();
    case 992:
      ACCEPT_TOKEN(anon_sym_vshufps);
      END_STATE();
    case 993:
      ACCEPT_TOKEN(anon_sym_vsubsd);
      END_STATE();
    case 994:
      ACCEPT_TOKEN(anon_sym_vucomisd);
      END_STATE();
    case 995:
      ACCEPT_TOKEN(anon_sym_vucomiss);
      END_STATE();
    case 996:
      ACCEPT_TOKEN(anon_sym_vunpckhpd);
      END_STATE();
    case 997:
      ACCEPT_TOKEN(anon_sym_vunpckhps);
      END_STATE();
    case 998:
      ACCEPT_TOKEN(anon_sym_vunpcklpd);
      END_STATE();
    case 999:
      ACCEPT_TOKEN(anon_sym_vunpcklps);
      END_STATE();
    case 1000:
      ACCEPT_TOKEN(anon_sym_vxorps);
      END_STATE();
    case 1001:
      ACCEPT_TOKEN(anon_sym_vzeroall);
      END_STATE();
    case 1002:
      ACCEPT_TOKEN(anon_sym_vzeroupper);
      END_STATE();
    case 1003:
      ACCEPT_TOKEN(anon_sym_xchg);
      END_STATE();
    case 1004:
      ACCEPT_TOKEN(anon_sym_xgetbv);
      END_STATE();
    case 1005:
      ACCEPT_TOKEN(anon_sym_xor);
      if (lookahead == 'l') ADVANCE(1006);
      if (lookahead == 'p') ADVANCE(172);
      if (lookahead == 'w') ADVANCE(1009);
      END_STATE();
    case 1006:
      ACCEPT_TOKEN(anon_sym_xorl);
      END_STATE();
    case 1007:
      ACCEPT_TOKEN(anon_sym_xorpd);
      END_STATE();
    case 1008:
      ACCEPT_TOKEN(anon_sym_xorps);
      END_STATE();
    case 1009:
      ACCEPT_TOKEN(anon_sym_xorw);
      END_STATE();
    case 1010:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 1011:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == '\n') ADVANCE(620);
      if (lookahead == ' ') ADVANCE(1011);
      END_STATE();
    case 1012:
      ACCEPT_TOKEN(anon_sym_);
      if (lookahead == ' ') ADVANCE(1012);
      END_STATE();
    case 1013:
      ACCEPT_TOKEN(anon_sym_callq);
      END_STATE();
    case 1014:
      ACCEPT_TOKEN(anon_sym_ja);
      if (lookahead == 'e') ADVANCE(1015);
      END_STATE();
    case 1015:
      ACCEPT_TOKEN(anon_sym_jae);
      END_STATE();
    case 1016:
      ACCEPT_TOKEN(anon_sym_jb);
      if (lookahead == 'e') ADVANCE(1017);
      END_STATE();
    case 1017:
      ACCEPT_TOKEN(anon_sym_jbe);
      END_STATE();
    case 1018:
      ACCEPT_TOKEN(anon_sym_je);
      END_STATE();
    case 1019:
      ACCEPT_TOKEN(anon_sym_jg);
      if (lookahead == 'e') ADVANCE(1020);
      END_STATE();
    case 1020:
      ACCEPT_TOKEN(anon_sym_jge);
      END_STATE();
    case 1021:
      ACCEPT_TOKEN(anon_sym_jl);
      if (lookahead == 'e') ADVANCE(1022);
      END_STATE();
    case 1022:
      ACCEPT_TOKEN(anon_sym_jle);
      END_STATE();
    case 1023:
      ACCEPT_TOKEN(anon_sym_jmp);
      if (lookahead == 'q') ADVANCE(1024);
      END_STATE();
    case 1024:
      ACCEPT_TOKEN(anon_sym_jmpq);
      END_STATE();
    case 1025:
      ACCEPT_TOKEN(anon_sym_jne);
      END_STATE();
    case 1026:
      ACCEPT_TOKEN(anon_sym_jno);
      END_STATE();
    case 1027:
      ACCEPT_TOKEN(anon_sym_jns);
      END_STATE();
    case 1028:
      ACCEPT_TOKEN(anon_sym_jo);
      END_STATE();
    case 1029:
      ACCEPT_TOKEN(anon_sym_jp);
      END_STATE();
    case 1030:
      ACCEPT_TOKEN(anon_sym_jrcxz);
      END_STATE();
    case 1031:
      ACCEPT_TOKEN(anon_sym_js);
      END_STATE();
    case 1032:
      ACCEPT_TOKEN(anon_sym_notrack);
      END_STATE();
    case 1033:
      ACCEPT_TOKEN(aux_sym_address_token1);
      END_STATE();
    case 1034:
      ACCEPT_TOKEN(aux_sym_operand_token1);
      END_STATE();
    case 1035:
      ACCEPT_TOKEN(aux_sym_fn_token1);
      END_STATE();
    case 1036:
      ACCEPT_TOKEN(sym_two_bytes);
      END_STATE();
    case 1037:
      ACCEPT_TOKEN(sym_two_bytes);
      if (lookahead == 'c') ADVANCE(624);
      if (lookahead == 'd') ADVANCE(626);
      if (lookahead == 'o') ADVANCE(600);
      END_STATE();
    case 1038:
      ACCEPT_TOKEN(sym_two_bytes);
      if (lookahead == 'c') ADVANCE(694);
      END_STATE();
    case 1039:
      ACCEPT_TOKEN(sym_two_bytes);
      if (lookahead == 'l') ADVANCE(336);
      END_STATE();
    case 1040:
      ACCEPT_TOKEN(sym_two_bytes);
      if (lookahead == 'm') ADVANCE(355);
      END_STATE();
    case 1041:
      ACCEPT_TOKEN(sym_two_bytes);
      if (lookahead == 's') ADVANCE(212);
      END_STATE();
    case 1042:
      ACCEPT_TOKEN(sym_two_bytes);
      if (lookahead == 't') ADVANCE(585);
      END_STATE();
    case 1043:
      ACCEPT_TOKEN(sym_two_bytes);
      if (lookahead == 't') ADVANCE(81);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 617},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 4},
  [6] = {.lex_state = 2},
  [7] = {.lex_state = 4},
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 617},
  [11] = {.lex_state = 617},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 5},
  [21] = {.lex_state = 5},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 615},
  [24] = {.lex_state = 617},
  [25] = {.lex_state = 617},
  [26] = {.lex_state = 617},
  [27] = {.lex_state = 617},
  [28] = {.lex_state = 617},
  [29] = {.lex_state = 5},
  [30] = {.lex_state = 617},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 617},
  [36] = {.lex_state = 1},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym_comment_token1] = ACTIONS(1),
    [aux_sym_comment_token2] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [aux_sym_address_token1] = ACTIONS(1),
    [aux_sym_operand_token1] = ACTIONS(1),
    [aux_sym_fn_token1] = ACTIONS(1),
  },
  [1] = {
    [sym_prog] = STATE(31),
    [sym__line] = STATE(10),
    [sym_address] = STATE(35),
    [aux_sym_prog_repeat1] = STATE(10),
    [aux_sym_address_repeat1] = STATE(25),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym_address_token1] = ACTIONS(5),
  },
  [2] = {
    [sym_comment] = STATE(33),
    [sym_opcode] = STATE(9),
    [sym_instruction] = STATE(18),
    [sym_callq] = STATE(18),
    [aux_sym__line_repeat1] = STATE(4),
    [sym__line_break] = ACTIONS(7),
    [aux_sym_comment_token1] = ACTIONS(9),
    [aux_sym_comment_token2] = ACTIONS(9),
    [anon_sym_adc] = ACTIONS(11),
    [anon_sym_adcx] = ACTIONS(11),
    [anon_sym_add] = ACTIONS(11),
    [anon_sym_addb] = ACTIONS(11),
    [anon_sym_addl] = ACTIONS(11),
    [anon_sym_addq] = ACTIONS(11),
    [anon_sym_addr32] = ACTIONS(11),
    [anon_sym_addsd] = ACTIONS(11),
    [anon_sym_addss] = ACTIONS(11),
    [anon_sym_addw] = ACTIONS(11),
    [anon_sym_adox] = ACTIONS(11),
    [anon_sym_aesdec] = ACTIONS(11),
    [anon_sym_aesdeclast] = ACTIONS(11),
    [anon_sym_aesenc] = ACTIONS(11),
    [anon_sym_aesenclast] = ACTIONS(11),
    [anon_sym_aeskeygenassist] = ACTIONS(11),
    [anon_sym_and] = ACTIONS(11),
    [anon_sym_andb] = ACTIONS(11),
    [anon_sym_andl] = ACTIONS(11),
    [anon_sym_andn] = ACTIONS(11),
    [anon_sym_andpd] = ACTIONS(11),
    [anon_sym_andps] = ACTIONS(11),
    [anon_sym_andq] = ACTIONS(11),
    [anon_sym_andw] = ACTIONS(11),
    [anon_sym_blendvps] = ACTIONS(11),
    [anon_sym_bsf] = ACTIONS(11),
    [anon_sym_bsr] = ACTIONS(11),
    [anon_sym_bswap] = ACTIONS(11),
    [anon_sym_bt] = ACTIONS(11),
    [anon_sym_btl] = ACTIONS(11),
    [anon_sym_btr] = ACTIONS(11),
    [anon_sym_bts] = ACTIONS(11),
    [anon_sym_cbtw] = ACTIONS(11),
    [anon_sym_cltd] = ACTIONS(11),
    [anon_sym_cltq] = ACTIONS(11),
    [anon_sym_cmova] = ACTIONS(11),
    [anon_sym_cmovae] = ACTIONS(11),
    [anon_sym_cmovb] = ACTIONS(11),
    [anon_sym_cmovbe] = ACTIONS(11),
    [anon_sym_cmove] = ACTIONS(11),
    [anon_sym_cmovg] = ACTIONS(11),
    [anon_sym_cmovge] = ACTIONS(11),
    [anon_sym_cmovl] = ACTIONS(11),
    [anon_sym_cmovle] = ACTIONS(11),
    [anon_sym_cmovne] = ACTIONS(11),
    [anon_sym_cmovns] = ACTIONS(11),
    [anon_sym_cmovo] = ACTIONS(11),
    [anon_sym_cmovp] = ACTIONS(11),
    [anon_sym_cmovs] = ACTIONS(11),
    [anon_sym_cmp] = ACTIONS(11),
    [anon_sym_cmpb] = ACTIONS(11),
    [anon_sym_cmpl] = ACTIONS(11),
    [anon_sym_cmpq] = ACTIONS(11),
    [anon_sym_cmpw] = ACTIONS(11),
    [anon_sym_comisd] = ACTIONS(11),
    [anon_sym_comiss] = ACTIONS(11),
    [anon_sym_cpuid] = ACTIONS(11),
    [anon_sym_cqto] = ACTIONS(11),
    [anon_sym_cvtsd2ss] = ACTIONS(11),
    [anon_sym_cvtsi2sd] = ACTIONS(11),
    [anon_sym_cvtsi2sdl] = ACTIONS(11),
    [anon_sym_cvtsi2sdq] = ACTIONS(11),
    [anon_sym_cvtsi2ss] = ACTIONS(11),
    [anon_sym_cvtsi2ssl] = ACTIONS(11),
    [anon_sym_cvtss2sd] = ACTIONS(11),
    [anon_sym_cvttsd2si] = ACTIONS(11),
    [anon_sym_cvttss2si] = ACTIONS(11),
    [anon_sym_cwtd] = ACTIONS(11),
    [anon_sym_cwtl] = ACTIONS(11),
    [anon_sym_data16] = ACTIONS(11),
    [anon_sym_dec] = ACTIONS(11),
    [anon_sym_div] = ACTIONS(11),
    [anon_sym_divl] = ACTIONS(11),
    [anon_sym_divq] = ACTIONS(11),
    [anon_sym_divsd] = ACTIONS(11),
    [anon_sym_divss] = ACTIONS(11),
    [anon_sym_endbr64] = ACTIONS(11),
    [anon_sym_femms] = ACTIONS(11),
    [anon_sym_fildl] = ACTIONS(11),
    [anon_sym_fldt] = ACTIONS(11),
    [anon_sym_fmulp] = ACTIONS(11),
    [anon_sym_fs] = ACTIONS(11),
    [anon_sym_fstpl] = ACTIONS(11),
    [anon_sym_gs] = ACTIONS(11),
    [anon_sym_idiv] = ACTIONS(11),
    [anon_sym_idivl] = ACTIONS(11),
    [anon_sym_imul] = ACTIONS(11),
    [anon_sym_inc] = ACTIONS(11),
    [anon_sym_incl] = ACTIONS(11),
    [anon_sym_insb] = ACTIONS(11),
    [anon_sym_insl] = ACTIONS(11),
    [anon_sym_kmovw] = ACTIONS(11),
    [anon_sym_knotw] = ACTIONS(11),
    [anon_sym_lea] = ACTIONS(11),
    [anon_sym_leaveq] = ACTIONS(11),
    [anon_sym_lock] = ACTIONS(11),
    [anon_sym_maxsd] = ACTIONS(11),
    [anon_sym_maxss] = ACTIONS(11),
    [anon_sym_mfence] = ACTIONS(11),
    [anon_sym_minsd] = ACTIONS(11),
    [anon_sym_minss] = ACTIONS(11),
    [anon_sym_mov] = ACTIONS(11),
    [anon_sym_movabs] = ACTIONS(11),
    [anon_sym_movapd] = ACTIONS(11),
    [anon_sym_movaps] = ACTIONS(11),
    [anon_sym_movb] = ACTIONS(11),
    [anon_sym_movbe] = ACTIONS(11),
    [anon_sym_movd] = ACTIONS(11),
    [anon_sym_movdqa] = ACTIONS(11),
    [anon_sym_movdqu] = ACTIONS(11),
    [anon_sym_movhlps] = ACTIONS(11),
    [anon_sym_movhps] = ACTIONS(11),
    [anon_sym_movl] = ACTIONS(11),
    [anon_sym_movq] = ACTIONS(11),
    [anon_sym_movsb] = ACTIONS(11),
    [anon_sym_movsbl] = ACTIONS(11),
    [anon_sym_movsbq] = ACTIONS(11),
    [anon_sym_movsbw] = ACTIONS(11),
    [anon_sym_movsd] = ACTIONS(11),
    [anon_sym_movslq] = ACTIONS(11),
    [anon_sym_movss] = ACTIONS(11),
    [anon_sym_movswl] = ACTIONS(11),
    [anon_sym_movswq] = ACTIONS(11),
    [anon_sym_movups] = ACTIONS(11),
    [anon_sym_movw] = ACTIONS(11),
    [anon_sym_movzbl] = ACTIONS(11),
    [anon_sym_movzbq] = ACTIONS(11),
    [anon_sym_movzbw] = ACTIONS(11),
    [anon_sym_movzwl] = ACTIONS(11),
    [anon_sym_mul] = ACTIONS(11),
    [anon_sym_mulb] = ACTIONS(11),
    [anon_sym_mull] = ACTIONS(11),
    [anon_sym_mulq] = ACTIONS(11),
    [anon_sym_mulsd] = ACTIONS(11),
    [anon_sym_mulss] = ACTIONS(11),
    [anon_sym_mulw] = ACTIONS(11),
    [anon_sym_mulx] = ACTIONS(11),
    [anon_sym_neg] = ACTIONS(11),
    [anon_sym_negl] = ACTIONS(11),
    [anon_sym_negq] = ACTIONS(11),
    [anon_sym_nop] = ACTIONS(11),
    [anon_sym_nopl] = ACTIONS(11),
    [anon_sym_nopw] = ACTIONS(11),
    [anon_sym_not] = ACTIONS(11),
    [anon_sym_notl] = ACTIONS(11),
    [anon_sym_notw] = ACTIONS(11),
    [anon_sym_or] = ACTIONS(11),
    [anon_sym_orb] = ACTIONS(11),
    [anon_sym_orl] = ACTIONS(11),
    [anon_sym_orq] = ACTIONS(11),
    [anon_sym_orw] = ACTIONS(11),
    [anon_sym_outsb] = ACTIONS(11),
    [anon_sym_outsl] = ACTIONS(11),
    [anon_sym_packuswb] = ACTIONS(11),
    [anon_sym_paddd] = ACTIONS(11),
    [anon_sym_paddq] = ACTIONS(11),
    [anon_sym_paddw] = ACTIONS(11),
    [anon_sym_palignr] = ACTIONS(11),
    [anon_sym_pand] = ACTIONS(11),
    [anon_sym_pandn] = ACTIONS(11),
    [anon_sym_pblendw] = ACTIONS(11),
    [anon_sym_pclmulhqhqdq] = ACTIONS(11),
    [anon_sym_pclmullqhqdq] = ACTIONS(11),
    [anon_sym_pclmullqlqdq] = ACTIONS(11),
    [anon_sym_pcmpeqb] = ACTIONS(11),
    [anon_sym_pcmpeqd] = ACTIONS(11),
    [anon_sym_pcmpgtd] = ACTIONS(11),
    [anon_sym_pextrb] = ACTIONS(11),
    [anon_sym_pextrq] = ACTIONS(11),
    [anon_sym_pextrw] = ACTIONS(11),
    [anon_sym_pinsrb] = ACTIONS(11),
    [anon_sym_pinsrd] = ACTIONS(11),
    [anon_sym_pinsrw] = ACTIONS(11),
    [anon_sym_pmaddubsw] = ACTIONS(11),
    [anon_sym_pmaddwd] = ACTIONS(11),
    [anon_sym_pmovmskb] = ACTIONS(11),
    [anon_sym_pmuludq] = ACTIONS(11),
    [anon_sym_pop] = ACTIONS(11),
    [anon_sym_popcnt] = ACTIONS(11),
    [anon_sym_por] = ACTIONS(11),
    [anon_sym_prefetcht0] = ACTIONS(11),
    [anon_sym_prefetcht1] = ACTIONS(11),
    [anon_sym_pshufb] = ACTIONS(11),
    [anon_sym_pshufd] = ACTIONS(11),
    [anon_sym_pshufhw] = ACTIONS(11),
    [anon_sym_pshuflw] = ACTIONS(11),
    [anon_sym_pslld] = ACTIONS(11),
    [anon_sym_pslldq] = ACTIONS(11),
    [anon_sym_psllq] = ACTIONS(11),
    [anon_sym_psrad] = ACTIONS(11),
    [anon_sym_psrld] = ACTIONS(11),
    [anon_sym_psrldq] = ACTIONS(11),
    [anon_sym_psrlq] = ACTIONS(11),
    [anon_sym_psrlw] = ACTIONS(11),
    [anon_sym_psubb] = ACTIONS(11),
    [anon_sym_psubd] = ACTIONS(11),
    [anon_sym_psubq] = ACTIONS(11),
    [anon_sym_psubusb] = ACTIONS(11),
    [anon_sym_psubusw] = ACTIONS(11),
    [anon_sym_punpckhbw] = ACTIONS(11),
    [anon_sym_punpckhdq] = ACTIONS(11),
    [anon_sym_punpckhqdq] = ACTIONS(11),
    [anon_sym_punpckhwd] = ACTIONS(11),
    [anon_sym_punpcklbw] = ACTIONS(11),
    [anon_sym_punpckldq] = ACTIONS(11),
    [anon_sym_punpcklqdq] = ACTIONS(11),
    [anon_sym_punpcklwd] = ACTIONS(11),
    [anon_sym_push] = ACTIONS(11),
    [anon_sym_pushq] = ACTIONS(11),
    [anon_sym_pxor] = ACTIONS(11),
    [anon_sym_re] = ACTIONS(11),
    [anon_sym_rep] = ACTIONS(11),
    [anon_sym_repnz] = ACTIONS(11),
    [anon_sym_repz] = ACTIONS(11),
    [anon_sym_retq] = ACTIONS(11),
    [anon_sym_rex] = ACTIONS(11),
    [anon_sym_rex_DOTB] = ACTIONS(11),
    [anon_sym_rex_DOTRB] = ACTIONS(11),
    [anon_sym_rex_DOTRXB] = ACTIONS(11),
    [anon_sym_rex_DOTW] = ACTIONS(11),
    [anon_sym_rex_DOTWB] = ACTIONS(11),
    [anon_sym_rex_DOTWRB] = ACTIONS(11),
    [anon_sym_rex_DOTWRXB] = ACTIONS(11),
    [anon_sym_rex_DOTXB] = ACTIONS(11),
    [anon_sym_rol] = ACTIONS(11),
    [anon_sym_roll] = ACTIONS(11),
    [anon_sym_ror] = ACTIONS(11),
    [anon_sym_rorl] = ACTIONS(11),
    [anon_sym_rorx] = ACTIONS(11),
    [anon_sym_sar] = ACTIONS(11),
    [anon_sym_sarl] = ACTIONS(11),
    [anon_sym_sarx] = ACTIONS(11),
    [anon_sym_sbb] = ACTIONS(11),
    [anon_sym_seta] = ACTIONS(11),
    [anon_sym_setae] = ACTIONS(11),
    [anon_sym_setb] = ACTIONS(11),
    [anon_sym_setbe] = ACTIONS(11),
    [anon_sym_sete] = ACTIONS(11),
    [anon_sym_setg] = ACTIONS(11),
    [anon_sym_setge] = ACTIONS(11),
    [anon_sym_setl] = ACTIONS(11),
    [anon_sym_setle] = ACTIONS(11),
    [anon_sym_setne] = ACTIONS(11),
    [anon_sym_setnp] = ACTIONS(11),
    [anon_sym_setns] = ACTIONS(11),
    [anon_sym_seto] = ACTIONS(11),
    [anon_sym_setp] = ACTIONS(11),
    [anon_sym_sha1msg1] = ACTIONS(11),
    [anon_sym_sha1msg2] = ACTIONS(11),
    [anon_sym_sha1nexte] = ACTIONS(11),
    [anon_sym_sha1rnds4] = ACTIONS(11),
    [anon_sym_shl] = ACTIONS(11),
    [anon_sym_shld] = ACTIONS(11),
    [anon_sym_shll] = ACTIONS(11),
    [anon_sym_shlq] = ACTIONS(11),
    [anon_sym_shlx] = ACTIONS(11),
    [anon_sym_shr] = ACTIONS(11),
    [anon_sym_shrd] = ACTIONS(11),
    [anon_sym_shrl] = ACTIONS(11),
    [anon_sym_shrq] = ACTIONS(11),
    [anon_sym_shrx] = ACTIONS(11),
    [anon_sym_shufpd] = ACTIONS(11),
    [anon_sym_shufps] = ACTIONS(11),
    [anon_sym_ss] = ACTIONS(11),
    [anon_sym_sub] = ACTIONS(11),
    [anon_sym_subb] = ACTIONS(11),
    [anon_sym_subl] = ACTIONS(11),
    [anon_sym_subpd] = ACTIONS(11),
    [anon_sym_subq] = ACTIONS(11),
    [anon_sym_subsd] = ACTIONS(11),
    [anon_sym_subss] = ACTIONS(11),
    [anon_sym_subw] = ACTIONS(11),
    [anon_sym_test] = ACTIONS(11),
    [anon_sym_testb] = ACTIONS(11),
    [anon_sym_testl] = ACTIONS(11),
    [anon_sym_tzcnt] = ACTIONS(11),
    [anon_sym_ucomisd] = ACTIONS(11),
    [anon_sym_ucomiss] = ACTIONS(11),
    [anon_sym_ud2] = ACTIONS(11),
    [anon_sym_unpckhpd] = ACTIONS(11),
    [anon_sym_vaesenc] = ACTIONS(11),
    [anon_sym_vaesenclast] = ACTIONS(11),
    [anon_sym_vblendps] = ACTIONS(11),
    [anon_sym_vblendvps] = ACTIONS(11),
    [anon_sym_vbroadcasti128] = ACTIONS(11),
    [anon_sym_vbroadcasti32x4] = ACTIONS(11),
    [anon_sym_vbroadcastss] = ACTIONS(11),
    [anon_sym_vcvtusi2sd] = ACTIONS(11),
    [anon_sym_vdivsd] = ACTIONS(11),
    [anon_sym_vextracti128] = ACTIONS(11),
    [anon_sym_vextracti32x4] = ACTIONS(11),
    [anon_sym_vinsertf128] = ACTIONS(11),
    [anon_sym_vinserti128] = ACTIONS(11),
    [anon_sym_vinserti32x4] = ACTIONS(11),
    [anon_sym_vinserti64x4] = ACTIONS(11),
    [anon_sym_vmovapd] = ACTIONS(11),
    [anon_sym_vmovaps] = ACTIONS(11),
    [anon_sym_vmovd] = ACTIONS(11),
    [anon_sym_vmovdqa] = ACTIONS(11),
    [anon_sym_vmovdqa32] = ACTIONS(11),
    [anon_sym_vmovdqa64] = ACTIONS(11),
    [anon_sym_vmovdqu] = ACTIONS(11),
    [anon_sym_vmovdqu32] = ACTIONS(11),
    [anon_sym_vmovdqu64] = ACTIONS(11),
    [anon_sym_vmovq] = ACTIONS(11),
    [anon_sym_vmovsd] = ACTIONS(11),
    [anon_sym_vmovss] = ACTIONS(11),
    [anon_sym_vmovups] = ACTIONS(11),
    [anon_sym_vmulsd] = ACTIONS(11),
    [anon_sym_vpackusdw] = ACTIONS(11),
    [anon_sym_vpaddb] = ACTIONS(11),
    [anon_sym_vpaddd] = ACTIONS(11),
    [anon_sym_vpaddq] = ACTIONS(11),
    [anon_sym_vpaddw] = ACTIONS(11),
    [anon_sym_vpalignr] = ACTIONS(11),
    [anon_sym_vpand] = ACTIONS(11),
    [anon_sym_vpblendd] = ACTIONS(11),
    [anon_sym_vpblendmd] = ACTIONS(11),
    [anon_sym_vpbroadcastd] = ACTIONS(11),
    [anon_sym_vpbroadcastq] = ACTIONS(11),
    [anon_sym_vpclmulhqhqdq] = ACTIONS(11),
    [anon_sym_vpclmulhqlqdq] = ACTIONS(11),
    [anon_sym_vpclmullqhqdq] = ACTIONS(11),
    [anon_sym_vpclmullqlqdq] = ACTIONS(11),
    [anon_sym_vpcmpgtd] = ACTIONS(11),
    [anon_sym_vpcmpltud] = ACTIONS(11),
    [anon_sym_vperm2f128] = ACTIONS(11),
    [anon_sym_vperm2i128] = ACTIONS(11),
    [anon_sym_vpermd] = ACTIONS(11),
    [anon_sym_vpermi2d] = ACTIONS(11),
    [anon_sym_vpermq] = ACTIONS(11),
    [anon_sym_vpermt2d] = ACTIONS(11),
    [anon_sym_vpextrw] = ACTIONS(11),
    [anon_sym_vpinsrb] = ACTIONS(11),
    [anon_sym_vpinsrd] = ACTIONS(11),
    [anon_sym_vpinsrq] = ACTIONS(11),
    [anon_sym_vpinsrw] = ACTIONS(11),
    [anon_sym_vpmaddubsw] = ACTIONS(11),
    [anon_sym_vpmaddwd] = ACTIONS(11),
    [anon_sym_vpmullw] = ACTIONS(11),
    [anon_sym_vpmuludq] = ACTIONS(11),
    [anon_sym_vpor] = ACTIONS(11),
    [anon_sym_vprord] = ACTIONS(11),
    [anon_sym_vprorq] = ACTIONS(11),
    [anon_sym_vpshufb] = ACTIONS(11),
    [anon_sym_vpshufd] = ACTIONS(11),
    [anon_sym_vpslld] = ACTIONS(11),
    [anon_sym_vpslldq] = ACTIONS(11),
    [anon_sym_vpsllq] = ACTIONS(11),
    [anon_sym_vpsllw] = ACTIONS(11),
    [anon_sym_vpsrld] = ACTIONS(11),
    [anon_sym_vpsrldq] = ACTIONS(11),
    [anon_sym_vpsrlq] = ACTIONS(11),
    [anon_sym_vpsrlw] = ACTIONS(11),
    [anon_sym_vpsubd] = ACTIONS(11),
    [anon_sym_vpsubq] = ACTIONS(11),
    [anon_sym_vpsubusw] = ACTIONS(11),
    [anon_sym_vpsubw] = ACTIONS(11),
    [anon_sym_vpunpckhdq] = ACTIONS(11),
    [anon_sym_vpunpckhqdq] = ACTIONS(11),
    [anon_sym_vpunpckhwd] = ACTIONS(11),
    [anon_sym_vpunpckldq] = ACTIONS(11),
    [anon_sym_vpunpcklqdq] = ACTIONS(11),
    [anon_sym_vpunpcklwd] = ACTIONS(11),
    [anon_sym_vpxor] = ACTIONS(11),
    [anon_sym_vpxord] = ACTIONS(11),
    [anon_sym_vshufi32x4] = ACTIONS(11),
    [anon_sym_vshufi64x2] = ACTIONS(11),
    [anon_sym_vshufps] = ACTIONS(11),
    [anon_sym_vsubsd] = ACTIONS(11),
    [anon_sym_vucomisd] = ACTIONS(11),
    [anon_sym_vucomiss] = ACTIONS(11),
    [anon_sym_vunpckhpd] = ACTIONS(11),
    [anon_sym_vunpckhps] = ACTIONS(11),
    [anon_sym_vunpcklpd] = ACTIONS(11),
    [anon_sym_vunpcklps] = ACTIONS(11),
    [anon_sym_vxorps] = ACTIONS(11),
    [anon_sym_vzeroall] = ACTIONS(11),
    [anon_sym_vzeroupper] = ACTIONS(11),
    [anon_sym_xchg] = ACTIONS(11),
    [anon_sym_xgetbv] = ACTIONS(11),
    [anon_sym_xor] = ACTIONS(11),
    [anon_sym_xorl] = ACTIONS(11),
    [anon_sym_xorpd] = ACTIONS(11),
    [anon_sym_xorps] = ACTIONS(11),
    [anon_sym_xorw] = ACTIONS(11),
    [anon_sym_callq] = ACTIONS(13),
    [anon_sym_ja] = ACTIONS(13),
    [anon_sym_jae] = ACTIONS(13),
    [anon_sym_jb] = ACTIONS(13),
    [anon_sym_jbe] = ACTIONS(13),
    [anon_sym_je] = ACTIONS(13),
    [anon_sym_jg] = ACTIONS(13),
    [anon_sym_jge] = ACTIONS(13),
    [anon_sym_jl] = ACTIONS(13),
    [anon_sym_jle] = ACTIONS(13),
    [anon_sym_jmp] = ACTIONS(13),
    [anon_sym_jmpq] = ACTIONS(13),
    [anon_sym_jne] = ACTIONS(13),
    [anon_sym_jno] = ACTIONS(13),
    [anon_sym_jns] = ACTIONS(13),
    [anon_sym_jo] = ACTIONS(13),
    [anon_sym_jp] = ACTIONS(13),
    [anon_sym_jrcxz] = ACTIONS(13),
    [anon_sym_js] = ACTIONS(13),
    [anon_sym_notrack] = ACTIONS(13),
    [sym_two_bytes] = ACTIONS(15),
  },
  [3] = {
    [sym_comment] = STATE(32),
    [sym_opcode] = STATE(9),
    [sym_instruction] = STATE(17),
    [sym_callq] = STATE(17),
    [aux_sym__line_repeat1] = STATE(2),
    [sym__line_break] = ACTIONS(17),
    [aux_sym_comment_token1] = ACTIONS(9),
    [aux_sym_comment_token2] = ACTIONS(9),
    [anon_sym_adc] = ACTIONS(11),
    [anon_sym_adcx] = ACTIONS(11),
    [anon_sym_add] = ACTIONS(11),
    [anon_sym_addb] = ACTIONS(11),
    [anon_sym_addl] = ACTIONS(11),
    [anon_sym_addq] = ACTIONS(11),
    [anon_sym_addr32] = ACTIONS(11),
    [anon_sym_addsd] = ACTIONS(11),
    [anon_sym_addss] = ACTIONS(11),
    [anon_sym_addw] = ACTIONS(11),
    [anon_sym_adox] = ACTIONS(11),
    [anon_sym_aesdec] = ACTIONS(11),
    [anon_sym_aesdeclast] = ACTIONS(11),
    [anon_sym_aesenc] = ACTIONS(11),
    [anon_sym_aesenclast] = ACTIONS(11),
    [anon_sym_aeskeygenassist] = ACTIONS(11),
    [anon_sym_and] = ACTIONS(11),
    [anon_sym_andb] = ACTIONS(11),
    [anon_sym_andl] = ACTIONS(11),
    [anon_sym_andn] = ACTIONS(11),
    [anon_sym_andpd] = ACTIONS(11),
    [anon_sym_andps] = ACTIONS(11),
    [anon_sym_andq] = ACTIONS(11),
    [anon_sym_andw] = ACTIONS(11),
    [anon_sym_blendvps] = ACTIONS(11),
    [anon_sym_bsf] = ACTIONS(11),
    [anon_sym_bsr] = ACTIONS(11),
    [anon_sym_bswap] = ACTIONS(11),
    [anon_sym_bt] = ACTIONS(11),
    [anon_sym_btl] = ACTIONS(11),
    [anon_sym_btr] = ACTIONS(11),
    [anon_sym_bts] = ACTIONS(11),
    [anon_sym_cbtw] = ACTIONS(11),
    [anon_sym_cltd] = ACTIONS(11),
    [anon_sym_cltq] = ACTIONS(11),
    [anon_sym_cmova] = ACTIONS(11),
    [anon_sym_cmovae] = ACTIONS(11),
    [anon_sym_cmovb] = ACTIONS(11),
    [anon_sym_cmovbe] = ACTIONS(11),
    [anon_sym_cmove] = ACTIONS(11),
    [anon_sym_cmovg] = ACTIONS(11),
    [anon_sym_cmovge] = ACTIONS(11),
    [anon_sym_cmovl] = ACTIONS(11),
    [anon_sym_cmovle] = ACTIONS(11),
    [anon_sym_cmovne] = ACTIONS(11),
    [anon_sym_cmovns] = ACTIONS(11),
    [anon_sym_cmovo] = ACTIONS(11),
    [anon_sym_cmovp] = ACTIONS(11),
    [anon_sym_cmovs] = ACTIONS(11),
    [anon_sym_cmp] = ACTIONS(11),
    [anon_sym_cmpb] = ACTIONS(11),
    [anon_sym_cmpl] = ACTIONS(11),
    [anon_sym_cmpq] = ACTIONS(11),
    [anon_sym_cmpw] = ACTIONS(11),
    [anon_sym_comisd] = ACTIONS(11),
    [anon_sym_comiss] = ACTIONS(11),
    [anon_sym_cpuid] = ACTIONS(11),
    [anon_sym_cqto] = ACTIONS(11),
    [anon_sym_cvtsd2ss] = ACTIONS(11),
    [anon_sym_cvtsi2sd] = ACTIONS(11),
    [anon_sym_cvtsi2sdl] = ACTIONS(11),
    [anon_sym_cvtsi2sdq] = ACTIONS(11),
    [anon_sym_cvtsi2ss] = ACTIONS(11),
    [anon_sym_cvtsi2ssl] = ACTIONS(11),
    [anon_sym_cvtss2sd] = ACTIONS(11),
    [anon_sym_cvttsd2si] = ACTIONS(11),
    [anon_sym_cvttss2si] = ACTIONS(11),
    [anon_sym_cwtd] = ACTIONS(11),
    [anon_sym_cwtl] = ACTIONS(11),
    [anon_sym_data16] = ACTIONS(11),
    [anon_sym_dec] = ACTIONS(11),
    [anon_sym_div] = ACTIONS(11),
    [anon_sym_divl] = ACTIONS(11),
    [anon_sym_divq] = ACTIONS(11),
    [anon_sym_divsd] = ACTIONS(11),
    [anon_sym_divss] = ACTIONS(11),
    [anon_sym_endbr64] = ACTIONS(11),
    [anon_sym_femms] = ACTIONS(11),
    [anon_sym_fildl] = ACTIONS(11),
    [anon_sym_fldt] = ACTIONS(11),
    [anon_sym_fmulp] = ACTIONS(11),
    [anon_sym_fs] = ACTIONS(11),
    [anon_sym_fstpl] = ACTIONS(11),
    [anon_sym_gs] = ACTIONS(11),
    [anon_sym_idiv] = ACTIONS(11),
    [anon_sym_idivl] = ACTIONS(11),
    [anon_sym_imul] = ACTIONS(11),
    [anon_sym_inc] = ACTIONS(11),
    [anon_sym_incl] = ACTIONS(11),
    [anon_sym_insb] = ACTIONS(11),
    [anon_sym_insl] = ACTIONS(11),
    [anon_sym_kmovw] = ACTIONS(11),
    [anon_sym_knotw] = ACTIONS(11),
    [anon_sym_lea] = ACTIONS(11),
    [anon_sym_leaveq] = ACTIONS(11),
    [anon_sym_lock] = ACTIONS(11),
    [anon_sym_maxsd] = ACTIONS(11),
    [anon_sym_maxss] = ACTIONS(11),
    [anon_sym_mfence] = ACTIONS(11),
    [anon_sym_minsd] = ACTIONS(11),
    [anon_sym_minss] = ACTIONS(11),
    [anon_sym_mov] = ACTIONS(11),
    [anon_sym_movabs] = ACTIONS(11),
    [anon_sym_movapd] = ACTIONS(11),
    [anon_sym_movaps] = ACTIONS(11),
    [anon_sym_movb] = ACTIONS(11),
    [anon_sym_movbe] = ACTIONS(11),
    [anon_sym_movd] = ACTIONS(11),
    [anon_sym_movdqa] = ACTIONS(11),
    [anon_sym_movdqu] = ACTIONS(11),
    [anon_sym_movhlps] = ACTIONS(11),
    [anon_sym_movhps] = ACTIONS(11),
    [anon_sym_movl] = ACTIONS(11),
    [anon_sym_movq] = ACTIONS(11),
    [anon_sym_movsb] = ACTIONS(11),
    [anon_sym_movsbl] = ACTIONS(11),
    [anon_sym_movsbq] = ACTIONS(11),
    [anon_sym_movsbw] = ACTIONS(11),
    [anon_sym_movsd] = ACTIONS(11),
    [anon_sym_movslq] = ACTIONS(11),
    [anon_sym_movss] = ACTIONS(11),
    [anon_sym_movswl] = ACTIONS(11),
    [anon_sym_movswq] = ACTIONS(11),
    [anon_sym_movups] = ACTIONS(11),
    [anon_sym_movw] = ACTIONS(11),
    [anon_sym_movzbl] = ACTIONS(11),
    [anon_sym_movzbq] = ACTIONS(11),
    [anon_sym_movzbw] = ACTIONS(11),
    [anon_sym_movzwl] = ACTIONS(11),
    [anon_sym_mul] = ACTIONS(11),
    [anon_sym_mulb] = ACTIONS(11),
    [anon_sym_mull] = ACTIONS(11),
    [anon_sym_mulq] = ACTIONS(11),
    [anon_sym_mulsd] = ACTIONS(11),
    [anon_sym_mulss] = ACTIONS(11),
    [anon_sym_mulw] = ACTIONS(11),
    [anon_sym_mulx] = ACTIONS(11),
    [anon_sym_neg] = ACTIONS(11),
    [anon_sym_negl] = ACTIONS(11),
    [anon_sym_negq] = ACTIONS(11),
    [anon_sym_nop] = ACTIONS(11),
    [anon_sym_nopl] = ACTIONS(11),
    [anon_sym_nopw] = ACTIONS(11),
    [anon_sym_not] = ACTIONS(11),
    [anon_sym_notl] = ACTIONS(11),
    [anon_sym_notw] = ACTIONS(11),
    [anon_sym_or] = ACTIONS(11),
    [anon_sym_orb] = ACTIONS(11),
    [anon_sym_orl] = ACTIONS(11),
    [anon_sym_orq] = ACTIONS(11),
    [anon_sym_orw] = ACTIONS(11),
    [anon_sym_outsb] = ACTIONS(11),
    [anon_sym_outsl] = ACTIONS(11),
    [anon_sym_packuswb] = ACTIONS(11),
    [anon_sym_paddd] = ACTIONS(11),
    [anon_sym_paddq] = ACTIONS(11),
    [anon_sym_paddw] = ACTIONS(11),
    [anon_sym_palignr] = ACTIONS(11),
    [anon_sym_pand] = ACTIONS(11),
    [anon_sym_pandn] = ACTIONS(11),
    [anon_sym_pblendw] = ACTIONS(11),
    [anon_sym_pclmulhqhqdq] = ACTIONS(11),
    [anon_sym_pclmullqhqdq] = ACTIONS(11),
    [anon_sym_pclmullqlqdq] = ACTIONS(11),
    [anon_sym_pcmpeqb] = ACTIONS(11),
    [anon_sym_pcmpeqd] = ACTIONS(11),
    [anon_sym_pcmpgtd] = ACTIONS(11),
    [anon_sym_pextrb] = ACTIONS(11),
    [anon_sym_pextrq] = ACTIONS(11),
    [anon_sym_pextrw] = ACTIONS(11),
    [anon_sym_pinsrb] = ACTIONS(11),
    [anon_sym_pinsrd] = ACTIONS(11),
    [anon_sym_pinsrw] = ACTIONS(11),
    [anon_sym_pmaddubsw] = ACTIONS(11),
    [anon_sym_pmaddwd] = ACTIONS(11),
    [anon_sym_pmovmskb] = ACTIONS(11),
    [anon_sym_pmuludq] = ACTIONS(11),
    [anon_sym_pop] = ACTIONS(11),
    [anon_sym_popcnt] = ACTIONS(11),
    [anon_sym_por] = ACTIONS(11),
    [anon_sym_prefetcht0] = ACTIONS(11),
    [anon_sym_prefetcht1] = ACTIONS(11),
    [anon_sym_pshufb] = ACTIONS(11),
    [anon_sym_pshufd] = ACTIONS(11),
    [anon_sym_pshufhw] = ACTIONS(11),
    [anon_sym_pshuflw] = ACTIONS(11),
    [anon_sym_pslld] = ACTIONS(11),
    [anon_sym_pslldq] = ACTIONS(11),
    [anon_sym_psllq] = ACTIONS(11),
    [anon_sym_psrad] = ACTIONS(11),
    [anon_sym_psrld] = ACTIONS(11),
    [anon_sym_psrldq] = ACTIONS(11),
    [anon_sym_psrlq] = ACTIONS(11),
    [anon_sym_psrlw] = ACTIONS(11),
    [anon_sym_psubb] = ACTIONS(11),
    [anon_sym_psubd] = ACTIONS(11),
    [anon_sym_psubq] = ACTIONS(11),
    [anon_sym_psubusb] = ACTIONS(11),
    [anon_sym_psubusw] = ACTIONS(11),
    [anon_sym_punpckhbw] = ACTIONS(11),
    [anon_sym_punpckhdq] = ACTIONS(11),
    [anon_sym_punpckhqdq] = ACTIONS(11),
    [anon_sym_punpckhwd] = ACTIONS(11),
    [anon_sym_punpcklbw] = ACTIONS(11),
    [anon_sym_punpckldq] = ACTIONS(11),
    [anon_sym_punpcklqdq] = ACTIONS(11),
    [anon_sym_punpcklwd] = ACTIONS(11),
    [anon_sym_push] = ACTIONS(11),
    [anon_sym_pushq] = ACTIONS(11),
    [anon_sym_pxor] = ACTIONS(11),
    [anon_sym_re] = ACTIONS(11),
    [anon_sym_rep] = ACTIONS(11),
    [anon_sym_repnz] = ACTIONS(11),
    [anon_sym_repz] = ACTIONS(11),
    [anon_sym_retq] = ACTIONS(11),
    [anon_sym_rex] = ACTIONS(11),
    [anon_sym_rex_DOTB] = ACTIONS(11),
    [anon_sym_rex_DOTRB] = ACTIONS(11),
    [anon_sym_rex_DOTRXB] = ACTIONS(11),
    [anon_sym_rex_DOTW] = ACTIONS(11),
    [anon_sym_rex_DOTWB] = ACTIONS(11),
    [anon_sym_rex_DOTWRB] = ACTIONS(11),
    [anon_sym_rex_DOTWRXB] = ACTIONS(11),
    [anon_sym_rex_DOTXB] = ACTIONS(11),
    [anon_sym_rol] = ACTIONS(11),
    [anon_sym_roll] = ACTIONS(11),
    [anon_sym_ror] = ACTIONS(11),
    [anon_sym_rorl] = ACTIONS(11),
    [anon_sym_rorx] = ACTIONS(11),
    [anon_sym_sar] = ACTIONS(11),
    [anon_sym_sarl] = ACTIONS(11),
    [anon_sym_sarx] = ACTIONS(11),
    [anon_sym_sbb] = ACTIONS(11),
    [anon_sym_seta] = ACTIONS(11),
    [anon_sym_setae] = ACTIONS(11),
    [anon_sym_setb] = ACTIONS(11),
    [anon_sym_setbe] = ACTIONS(11),
    [anon_sym_sete] = ACTIONS(11),
    [anon_sym_setg] = ACTIONS(11),
    [anon_sym_setge] = ACTIONS(11),
    [anon_sym_setl] = ACTIONS(11),
    [anon_sym_setle] = ACTIONS(11),
    [anon_sym_setne] = ACTIONS(11),
    [anon_sym_setnp] = ACTIONS(11),
    [anon_sym_setns] = ACTIONS(11),
    [anon_sym_seto] = ACTIONS(11),
    [anon_sym_setp] = ACTIONS(11),
    [anon_sym_sha1msg1] = ACTIONS(11),
    [anon_sym_sha1msg2] = ACTIONS(11),
    [anon_sym_sha1nexte] = ACTIONS(11),
    [anon_sym_sha1rnds4] = ACTIONS(11),
    [anon_sym_shl] = ACTIONS(11),
    [anon_sym_shld] = ACTIONS(11),
    [anon_sym_shll] = ACTIONS(11),
    [anon_sym_shlq] = ACTIONS(11),
    [anon_sym_shlx] = ACTIONS(11),
    [anon_sym_shr] = ACTIONS(11),
    [anon_sym_shrd] = ACTIONS(11),
    [anon_sym_shrl] = ACTIONS(11),
    [anon_sym_shrq] = ACTIONS(11),
    [anon_sym_shrx] = ACTIONS(11),
    [anon_sym_shufpd] = ACTIONS(11),
    [anon_sym_shufps] = ACTIONS(11),
    [anon_sym_ss] = ACTIONS(11),
    [anon_sym_sub] = ACTIONS(11),
    [anon_sym_subb] = ACTIONS(11),
    [anon_sym_subl] = ACTIONS(11),
    [anon_sym_subpd] = ACTIONS(11),
    [anon_sym_subq] = ACTIONS(11),
    [anon_sym_subsd] = ACTIONS(11),
    [anon_sym_subss] = ACTIONS(11),
    [anon_sym_subw] = ACTIONS(11),
    [anon_sym_test] = ACTIONS(11),
    [anon_sym_testb] = ACTIONS(11),
    [anon_sym_testl] = ACTIONS(11),
    [anon_sym_tzcnt] = ACTIONS(11),
    [anon_sym_ucomisd] = ACTIONS(11),
    [anon_sym_ucomiss] = ACTIONS(11),
    [anon_sym_ud2] = ACTIONS(11),
    [anon_sym_unpckhpd] = ACTIONS(11),
    [anon_sym_vaesenc] = ACTIONS(11),
    [anon_sym_vaesenclast] = ACTIONS(11),
    [anon_sym_vblendps] = ACTIONS(11),
    [anon_sym_vblendvps] = ACTIONS(11),
    [anon_sym_vbroadcasti128] = ACTIONS(11),
    [anon_sym_vbroadcasti32x4] = ACTIONS(11),
    [anon_sym_vbroadcastss] = ACTIONS(11),
    [anon_sym_vcvtusi2sd] = ACTIONS(11),
    [anon_sym_vdivsd] = ACTIONS(11),
    [anon_sym_vextracti128] = ACTIONS(11),
    [anon_sym_vextracti32x4] = ACTIONS(11),
    [anon_sym_vinsertf128] = ACTIONS(11),
    [anon_sym_vinserti128] = ACTIONS(11),
    [anon_sym_vinserti32x4] = ACTIONS(11),
    [anon_sym_vinserti64x4] = ACTIONS(11),
    [anon_sym_vmovapd] = ACTIONS(11),
    [anon_sym_vmovaps] = ACTIONS(11),
    [anon_sym_vmovd] = ACTIONS(11),
    [anon_sym_vmovdqa] = ACTIONS(11),
    [anon_sym_vmovdqa32] = ACTIONS(11),
    [anon_sym_vmovdqa64] = ACTIONS(11),
    [anon_sym_vmovdqu] = ACTIONS(11),
    [anon_sym_vmovdqu32] = ACTIONS(11),
    [anon_sym_vmovdqu64] = ACTIONS(11),
    [anon_sym_vmovq] = ACTIONS(11),
    [anon_sym_vmovsd] = ACTIONS(11),
    [anon_sym_vmovss] = ACTIONS(11),
    [anon_sym_vmovups] = ACTIONS(11),
    [anon_sym_vmulsd] = ACTIONS(11),
    [anon_sym_vpackusdw] = ACTIONS(11),
    [anon_sym_vpaddb] = ACTIONS(11),
    [anon_sym_vpaddd] = ACTIONS(11),
    [anon_sym_vpaddq] = ACTIONS(11),
    [anon_sym_vpaddw] = ACTIONS(11),
    [anon_sym_vpalignr] = ACTIONS(11),
    [anon_sym_vpand] = ACTIONS(11),
    [anon_sym_vpblendd] = ACTIONS(11),
    [anon_sym_vpblendmd] = ACTIONS(11),
    [anon_sym_vpbroadcastd] = ACTIONS(11),
    [anon_sym_vpbroadcastq] = ACTIONS(11),
    [anon_sym_vpclmulhqhqdq] = ACTIONS(11),
    [anon_sym_vpclmulhqlqdq] = ACTIONS(11),
    [anon_sym_vpclmullqhqdq] = ACTIONS(11),
    [anon_sym_vpclmullqlqdq] = ACTIONS(11),
    [anon_sym_vpcmpgtd] = ACTIONS(11),
    [anon_sym_vpcmpltud] = ACTIONS(11),
    [anon_sym_vperm2f128] = ACTIONS(11),
    [anon_sym_vperm2i128] = ACTIONS(11),
    [anon_sym_vpermd] = ACTIONS(11),
    [anon_sym_vpermi2d] = ACTIONS(11),
    [anon_sym_vpermq] = ACTIONS(11),
    [anon_sym_vpermt2d] = ACTIONS(11),
    [anon_sym_vpextrw] = ACTIONS(11),
    [anon_sym_vpinsrb] = ACTIONS(11),
    [anon_sym_vpinsrd] = ACTIONS(11),
    [anon_sym_vpinsrq] = ACTIONS(11),
    [anon_sym_vpinsrw] = ACTIONS(11),
    [anon_sym_vpmaddubsw] = ACTIONS(11),
    [anon_sym_vpmaddwd] = ACTIONS(11),
    [anon_sym_vpmullw] = ACTIONS(11),
    [anon_sym_vpmuludq] = ACTIONS(11),
    [anon_sym_vpor] = ACTIONS(11),
    [anon_sym_vprord] = ACTIONS(11),
    [anon_sym_vprorq] = ACTIONS(11),
    [anon_sym_vpshufb] = ACTIONS(11),
    [anon_sym_vpshufd] = ACTIONS(11),
    [anon_sym_vpslld] = ACTIONS(11),
    [anon_sym_vpslldq] = ACTIONS(11),
    [anon_sym_vpsllq] = ACTIONS(11),
    [anon_sym_vpsllw] = ACTIONS(11),
    [anon_sym_vpsrld] = ACTIONS(11),
    [anon_sym_vpsrldq] = ACTIONS(11),
    [anon_sym_vpsrlq] = ACTIONS(11),
    [anon_sym_vpsrlw] = ACTIONS(11),
    [anon_sym_vpsubd] = ACTIONS(11),
    [anon_sym_vpsubq] = ACTIONS(11),
    [anon_sym_vpsubusw] = ACTIONS(11),
    [anon_sym_vpsubw] = ACTIONS(11),
    [anon_sym_vpunpckhdq] = ACTIONS(11),
    [anon_sym_vpunpckhqdq] = ACTIONS(11),
    [anon_sym_vpunpckhwd] = ACTIONS(11),
    [anon_sym_vpunpckldq] = ACTIONS(11),
    [anon_sym_vpunpcklqdq] = ACTIONS(11),
    [anon_sym_vpunpcklwd] = ACTIONS(11),
    [anon_sym_vpxor] = ACTIONS(11),
    [anon_sym_vpxord] = ACTIONS(11),
    [anon_sym_vshufi32x4] = ACTIONS(11),
    [anon_sym_vshufi64x2] = ACTIONS(11),
    [anon_sym_vshufps] = ACTIONS(11),
    [anon_sym_vsubsd] = ACTIONS(11),
    [anon_sym_vucomisd] = ACTIONS(11),
    [anon_sym_vucomiss] = ACTIONS(11),
    [anon_sym_vunpckhpd] = ACTIONS(11),
    [anon_sym_vunpckhps] = ACTIONS(11),
    [anon_sym_vunpcklpd] = ACTIONS(11),
    [anon_sym_vunpcklps] = ACTIONS(11),
    [anon_sym_vxorps] = ACTIONS(11),
    [anon_sym_vzeroall] = ACTIONS(11),
    [anon_sym_vzeroupper] = ACTIONS(11),
    [anon_sym_xchg] = ACTIONS(11),
    [anon_sym_xgetbv] = ACTIONS(11),
    [anon_sym_xor] = ACTIONS(11),
    [anon_sym_xorl] = ACTIONS(11),
    [anon_sym_xorpd] = ACTIONS(11),
    [anon_sym_xorps] = ACTIONS(11),
    [anon_sym_xorw] = ACTIONS(11),
    [anon_sym_callq] = ACTIONS(13),
    [anon_sym_ja] = ACTIONS(13),
    [anon_sym_jae] = ACTIONS(13),
    [anon_sym_jb] = ACTIONS(13),
    [anon_sym_jbe] = ACTIONS(13),
    [anon_sym_je] = ACTIONS(13),
    [anon_sym_jg] = ACTIONS(13),
    [anon_sym_jge] = ACTIONS(13),
    [anon_sym_jl] = ACTIONS(13),
    [anon_sym_jle] = ACTIONS(13),
    [anon_sym_jmp] = ACTIONS(13),
    [anon_sym_jmpq] = ACTIONS(13),
    [anon_sym_jne] = ACTIONS(13),
    [anon_sym_jno] = ACTIONS(13),
    [anon_sym_jns] = ACTIONS(13),
    [anon_sym_jo] = ACTIONS(13),
    [anon_sym_jp] = ACTIONS(13),
    [anon_sym_jrcxz] = ACTIONS(13),
    [anon_sym_js] = ACTIONS(13),
    [anon_sym_notrack] = ACTIONS(13),
    [sym_two_bytes] = ACTIONS(19),
  },
  [4] = {
    [aux_sym__line_repeat1] = STATE(4),
    [sym__line_break] = ACTIONS(21),
    [aux_sym_comment_token1] = ACTIONS(23),
    [aux_sym_comment_token2] = ACTIONS(23),
    [anon_sym_adc] = ACTIONS(23),
    [anon_sym_adcx] = ACTIONS(23),
    [anon_sym_add] = ACTIONS(23),
    [anon_sym_addb] = ACTIONS(23),
    [anon_sym_addl] = ACTIONS(23),
    [anon_sym_addq] = ACTIONS(23),
    [anon_sym_addr32] = ACTIONS(23),
    [anon_sym_addsd] = ACTIONS(23),
    [anon_sym_addss] = ACTIONS(23),
    [anon_sym_addw] = ACTIONS(23),
    [anon_sym_adox] = ACTIONS(23),
    [anon_sym_aesdec] = ACTIONS(23),
    [anon_sym_aesdeclast] = ACTIONS(23),
    [anon_sym_aesenc] = ACTIONS(23),
    [anon_sym_aesenclast] = ACTIONS(23),
    [anon_sym_aeskeygenassist] = ACTIONS(23),
    [anon_sym_and] = ACTIONS(23),
    [anon_sym_andb] = ACTIONS(23),
    [anon_sym_andl] = ACTIONS(23),
    [anon_sym_andn] = ACTIONS(23),
    [anon_sym_andpd] = ACTIONS(23),
    [anon_sym_andps] = ACTIONS(23),
    [anon_sym_andq] = ACTIONS(23),
    [anon_sym_andw] = ACTIONS(23),
    [anon_sym_blendvps] = ACTIONS(23),
    [anon_sym_bsf] = ACTIONS(23),
    [anon_sym_bsr] = ACTIONS(23),
    [anon_sym_bswap] = ACTIONS(23),
    [anon_sym_bt] = ACTIONS(23),
    [anon_sym_btl] = ACTIONS(23),
    [anon_sym_btr] = ACTIONS(23),
    [anon_sym_bts] = ACTIONS(23),
    [anon_sym_cbtw] = ACTIONS(23),
    [anon_sym_cltd] = ACTIONS(23),
    [anon_sym_cltq] = ACTIONS(23),
    [anon_sym_cmova] = ACTIONS(23),
    [anon_sym_cmovae] = ACTIONS(23),
    [anon_sym_cmovb] = ACTIONS(23),
    [anon_sym_cmovbe] = ACTIONS(23),
    [anon_sym_cmove] = ACTIONS(23),
    [anon_sym_cmovg] = ACTIONS(23),
    [anon_sym_cmovge] = ACTIONS(23),
    [anon_sym_cmovl] = ACTIONS(23),
    [anon_sym_cmovle] = ACTIONS(23),
    [anon_sym_cmovne] = ACTIONS(23),
    [anon_sym_cmovns] = ACTIONS(23),
    [anon_sym_cmovo] = ACTIONS(23),
    [anon_sym_cmovp] = ACTIONS(23),
    [anon_sym_cmovs] = ACTIONS(23),
    [anon_sym_cmp] = ACTIONS(23),
    [anon_sym_cmpb] = ACTIONS(23),
    [anon_sym_cmpl] = ACTIONS(23),
    [anon_sym_cmpq] = ACTIONS(23),
    [anon_sym_cmpw] = ACTIONS(23),
    [anon_sym_comisd] = ACTIONS(23),
    [anon_sym_comiss] = ACTIONS(23),
    [anon_sym_cpuid] = ACTIONS(23),
    [anon_sym_cqto] = ACTIONS(23),
    [anon_sym_cvtsd2ss] = ACTIONS(23),
    [anon_sym_cvtsi2sd] = ACTIONS(23),
    [anon_sym_cvtsi2sdl] = ACTIONS(23),
    [anon_sym_cvtsi2sdq] = ACTIONS(23),
    [anon_sym_cvtsi2ss] = ACTIONS(23),
    [anon_sym_cvtsi2ssl] = ACTIONS(23),
    [anon_sym_cvtss2sd] = ACTIONS(23),
    [anon_sym_cvttsd2si] = ACTIONS(23),
    [anon_sym_cvttss2si] = ACTIONS(23),
    [anon_sym_cwtd] = ACTIONS(23),
    [anon_sym_cwtl] = ACTIONS(23),
    [anon_sym_data16] = ACTIONS(23),
    [anon_sym_dec] = ACTIONS(23),
    [anon_sym_div] = ACTIONS(23),
    [anon_sym_divl] = ACTIONS(23),
    [anon_sym_divq] = ACTIONS(23),
    [anon_sym_divsd] = ACTIONS(23),
    [anon_sym_divss] = ACTIONS(23),
    [anon_sym_endbr64] = ACTIONS(23),
    [anon_sym_femms] = ACTIONS(23),
    [anon_sym_fildl] = ACTIONS(23),
    [anon_sym_fldt] = ACTIONS(23),
    [anon_sym_fmulp] = ACTIONS(23),
    [anon_sym_fs] = ACTIONS(23),
    [anon_sym_fstpl] = ACTIONS(23),
    [anon_sym_gs] = ACTIONS(23),
    [anon_sym_idiv] = ACTIONS(23),
    [anon_sym_idivl] = ACTIONS(23),
    [anon_sym_imul] = ACTIONS(23),
    [anon_sym_inc] = ACTIONS(23),
    [anon_sym_incl] = ACTIONS(23),
    [anon_sym_insb] = ACTIONS(23),
    [anon_sym_insl] = ACTIONS(23),
    [anon_sym_kmovw] = ACTIONS(23),
    [anon_sym_knotw] = ACTIONS(23),
    [anon_sym_lea] = ACTIONS(23),
    [anon_sym_leaveq] = ACTIONS(23),
    [anon_sym_lock] = ACTIONS(23),
    [anon_sym_maxsd] = ACTIONS(23),
    [anon_sym_maxss] = ACTIONS(23),
    [anon_sym_mfence] = ACTIONS(23),
    [anon_sym_minsd] = ACTIONS(23),
    [anon_sym_minss] = ACTIONS(23),
    [anon_sym_mov] = ACTIONS(23),
    [anon_sym_movabs] = ACTIONS(23),
    [anon_sym_movapd] = ACTIONS(23),
    [anon_sym_movaps] = ACTIONS(23),
    [anon_sym_movb] = ACTIONS(23),
    [anon_sym_movbe] = ACTIONS(23),
    [anon_sym_movd] = ACTIONS(23),
    [anon_sym_movdqa] = ACTIONS(23),
    [anon_sym_movdqu] = ACTIONS(23),
    [anon_sym_movhlps] = ACTIONS(23),
    [anon_sym_movhps] = ACTIONS(23),
    [anon_sym_movl] = ACTIONS(23),
    [anon_sym_movq] = ACTIONS(23),
    [anon_sym_movsb] = ACTIONS(23),
    [anon_sym_movsbl] = ACTIONS(23),
    [anon_sym_movsbq] = ACTIONS(23),
    [anon_sym_movsbw] = ACTIONS(23),
    [anon_sym_movsd] = ACTIONS(23),
    [anon_sym_movslq] = ACTIONS(23),
    [anon_sym_movss] = ACTIONS(23),
    [anon_sym_movswl] = ACTIONS(23),
    [anon_sym_movswq] = ACTIONS(23),
    [anon_sym_movups] = ACTIONS(23),
    [anon_sym_movw] = ACTIONS(23),
    [anon_sym_movzbl] = ACTIONS(23),
    [anon_sym_movzbq] = ACTIONS(23),
    [anon_sym_movzbw] = ACTIONS(23),
    [anon_sym_movzwl] = ACTIONS(23),
    [anon_sym_mul] = ACTIONS(23),
    [anon_sym_mulb] = ACTIONS(23),
    [anon_sym_mull] = ACTIONS(23),
    [anon_sym_mulq] = ACTIONS(23),
    [anon_sym_mulsd] = ACTIONS(23),
    [anon_sym_mulss] = ACTIONS(23),
    [anon_sym_mulw] = ACTIONS(23),
    [anon_sym_mulx] = ACTIONS(23),
    [anon_sym_neg] = ACTIONS(23),
    [anon_sym_negl] = ACTIONS(23),
    [anon_sym_negq] = ACTIONS(23),
    [anon_sym_nop] = ACTIONS(23),
    [anon_sym_nopl] = ACTIONS(23),
    [anon_sym_nopw] = ACTIONS(23),
    [anon_sym_not] = ACTIONS(23),
    [anon_sym_notl] = ACTIONS(23),
    [anon_sym_notw] = ACTIONS(23),
    [anon_sym_or] = ACTIONS(23),
    [anon_sym_orb] = ACTIONS(23),
    [anon_sym_orl] = ACTIONS(23),
    [anon_sym_orq] = ACTIONS(23),
    [anon_sym_orw] = ACTIONS(23),
    [anon_sym_outsb] = ACTIONS(23),
    [anon_sym_outsl] = ACTIONS(23),
    [anon_sym_packuswb] = ACTIONS(23),
    [anon_sym_paddd] = ACTIONS(23),
    [anon_sym_paddq] = ACTIONS(23),
    [anon_sym_paddw] = ACTIONS(23),
    [anon_sym_palignr] = ACTIONS(23),
    [anon_sym_pand] = ACTIONS(23),
    [anon_sym_pandn] = ACTIONS(23),
    [anon_sym_pblendw] = ACTIONS(23),
    [anon_sym_pclmulhqhqdq] = ACTIONS(23),
    [anon_sym_pclmullqhqdq] = ACTIONS(23),
    [anon_sym_pclmullqlqdq] = ACTIONS(23),
    [anon_sym_pcmpeqb] = ACTIONS(23),
    [anon_sym_pcmpeqd] = ACTIONS(23),
    [anon_sym_pcmpgtd] = ACTIONS(23),
    [anon_sym_pextrb] = ACTIONS(23),
    [anon_sym_pextrq] = ACTIONS(23),
    [anon_sym_pextrw] = ACTIONS(23),
    [anon_sym_pinsrb] = ACTIONS(23),
    [anon_sym_pinsrd] = ACTIONS(23),
    [anon_sym_pinsrw] = ACTIONS(23),
    [anon_sym_pmaddubsw] = ACTIONS(23),
    [anon_sym_pmaddwd] = ACTIONS(23),
    [anon_sym_pmovmskb] = ACTIONS(23),
    [anon_sym_pmuludq] = ACTIONS(23),
    [anon_sym_pop] = ACTIONS(23),
    [anon_sym_popcnt] = ACTIONS(23),
    [anon_sym_por] = ACTIONS(23),
    [anon_sym_prefetcht0] = ACTIONS(23),
    [anon_sym_prefetcht1] = ACTIONS(23),
    [anon_sym_pshufb] = ACTIONS(23),
    [anon_sym_pshufd] = ACTIONS(23),
    [anon_sym_pshufhw] = ACTIONS(23),
    [anon_sym_pshuflw] = ACTIONS(23),
    [anon_sym_pslld] = ACTIONS(23),
    [anon_sym_pslldq] = ACTIONS(23),
    [anon_sym_psllq] = ACTIONS(23),
    [anon_sym_psrad] = ACTIONS(23),
    [anon_sym_psrld] = ACTIONS(23),
    [anon_sym_psrldq] = ACTIONS(23),
    [anon_sym_psrlq] = ACTIONS(23),
    [anon_sym_psrlw] = ACTIONS(23),
    [anon_sym_psubb] = ACTIONS(23),
    [anon_sym_psubd] = ACTIONS(23),
    [anon_sym_psubq] = ACTIONS(23),
    [anon_sym_psubusb] = ACTIONS(23),
    [anon_sym_psubusw] = ACTIONS(23),
    [anon_sym_punpckhbw] = ACTIONS(23),
    [anon_sym_punpckhdq] = ACTIONS(23),
    [anon_sym_punpckhqdq] = ACTIONS(23),
    [anon_sym_punpckhwd] = ACTIONS(23),
    [anon_sym_punpcklbw] = ACTIONS(23),
    [anon_sym_punpckldq] = ACTIONS(23),
    [anon_sym_punpcklqdq] = ACTIONS(23),
    [anon_sym_punpcklwd] = ACTIONS(23),
    [anon_sym_push] = ACTIONS(23),
    [anon_sym_pushq] = ACTIONS(23),
    [anon_sym_pxor] = ACTIONS(23),
    [anon_sym_re] = ACTIONS(23),
    [anon_sym_rep] = ACTIONS(23),
    [anon_sym_repnz] = ACTIONS(23),
    [anon_sym_repz] = ACTIONS(23),
    [anon_sym_retq] = ACTIONS(23),
    [anon_sym_rex] = ACTIONS(23),
    [anon_sym_rex_DOTB] = ACTIONS(23),
    [anon_sym_rex_DOTRB] = ACTIONS(23),
    [anon_sym_rex_DOTRXB] = ACTIONS(23),
    [anon_sym_rex_DOTW] = ACTIONS(23),
    [anon_sym_rex_DOTWB] = ACTIONS(23),
    [anon_sym_rex_DOTWRB] = ACTIONS(23),
    [anon_sym_rex_DOTWRXB] = ACTIONS(23),
    [anon_sym_rex_DOTXB] = ACTIONS(23),
    [anon_sym_rol] = ACTIONS(23),
    [anon_sym_roll] = ACTIONS(23),
    [anon_sym_ror] = ACTIONS(23),
    [anon_sym_rorl] = ACTIONS(23),
    [anon_sym_rorx] = ACTIONS(23),
    [anon_sym_sar] = ACTIONS(23),
    [anon_sym_sarl] = ACTIONS(23),
    [anon_sym_sarx] = ACTIONS(23),
    [anon_sym_sbb] = ACTIONS(23),
    [anon_sym_seta] = ACTIONS(23),
    [anon_sym_setae] = ACTIONS(23),
    [anon_sym_setb] = ACTIONS(23),
    [anon_sym_setbe] = ACTIONS(23),
    [anon_sym_sete] = ACTIONS(23),
    [anon_sym_setg] = ACTIONS(23),
    [anon_sym_setge] = ACTIONS(23),
    [anon_sym_setl] = ACTIONS(23),
    [anon_sym_setle] = ACTIONS(23),
    [anon_sym_setne] = ACTIONS(23),
    [anon_sym_setnp] = ACTIONS(23),
    [anon_sym_setns] = ACTIONS(23),
    [anon_sym_seto] = ACTIONS(23),
    [anon_sym_setp] = ACTIONS(23),
    [anon_sym_sha1msg1] = ACTIONS(23),
    [anon_sym_sha1msg2] = ACTIONS(23),
    [anon_sym_sha1nexte] = ACTIONS(23),
    [anon_sym_sha1rnds4] = ACTIONS(23),
    [anon_sym_shl] = ACTIONS(23),
    [anon_sym_shld] = ACTIONS(23),
    [anon_sym_shll] = ACTIONS(23),
    [anon_sym_shlq] = ACTIONS(23),
    [anon_sym_shlx] = ACTIONS(23),
    [anon_sym_shr] = ACTIONS(23),
    [anon_sym_shrd] = ACTIONS(23),
    [anon_sym_shrl] = ACTIONS(23),
    [anon_sym_shrq] = ACTIONS(23),
    [anon_sym_shrx] = ACTIONS(23),
    [anon_sym_shufpd] = ACTIONS(23),
    [anon_sym_shufps] = ACTIONS(23),
    [anon_sym_ss] = ACTIONS(23),
    [anon_sym_sub] = ACTIONS(23),
    [anon_sym_subb] = ACTIONS(23),
    [anon_sym_subl] = ACTIONS(23),
    [anon_sym_subpd] = ACTIONS(23),
    [anon_sym_subq] = ACTIONS(23),
    [anon_sym_subsd] = ACTIONS(23),
    [anon_sym_subss] = ACTIONS(23),
    [anon_sym_subw] = ACTIONS(23),
    [anon_sym_test] = ACTIONS(23),
    [anon_sym_testb] = ACTIONS(23),
    [anon_sym_testl] = ACTIONS(23),
    [anon_sym_tzcnt] = ACTIONS(23),
    [anon_sym_ucomisd] = ACTIONS(23),
    [anon_sym_ucomiss] = ACTIONS(23),
    [anon_sym_ud2] = ACTIONS(23),
    [anon_sym_unpckhpd] = ACTIONS(23),
    [anon_sym_vaesenc] = ACTIONS(23),
    [anon_sym_vaesenclast] = ACTIONS(23),
    [anon_sym_vblendps] = ACTIONS(23),
    [anon_sym_vblendvps] = ACTIONS(23),
    [anon_sym_vbroadcasti128] = ACTIONS(23),
    [anon_sym_vbroadcasti32x4] = ACTIONS(23),
    [anon_sym_vbroadcastss] = ACTIONS(23),
    [anon_sym_vcvtusi2sd] = ACTIONS(23),
    [anon_sym_vdivsd] = ACTIONS(23),
    [anon_sym_vextracti128] = ACTIONS(23),
    [anon_sym_vextracti32x4] = ACTIONS(23),
    [anon_sym_vinsertf128] = ACTIONS(23),
    [anon_sym_vinserti128] = ACTIONS(23),
    [anon_sym_vinserti32x4] = ACTIONS(23),
    [anon_sym_vinserti64x4] = ACTIONS(23),
    [anon_sym_vmovapd] = ACTIONS(23),
    [anon_sym_vmovaps] = ACTIONS(23),
    [anon_sym_vmovd] = ACTIONS(23),
    [anon_sym_vmovdqa] = ACTIONS(23),
    [anon_sym_vmovdqa32] = ACTIONS(23),
    [anon_sym_vmovdqa64] = ACTIONS(23),
    [anon_sym_vmovdqu] = ACTIONS(23),
    [anon_sym_vmovdqu32] = ACTIONS(23),
    [anon_sym_vmovdqu64] = ACTIONS(23),
    [anon_sym_vmovq] = ACTIONS(23),
    [anon_sym_vmovsd] = ACTIONS(23),
    [anon_sym_vmovss] = ACTIONS(23),
    [anon_sym_vmovups] = ACTIONS(23),
    [anon_sym_vmulsd] = ACTIONS(23),
    [anon_sym_vpackusdw] = ACTIONS(23),
    [anon_sym_vpaddb] = ACTIONS(23),
    [anon_sym_vpaddd] = ACTIONS(23),
    [anon_sym_vpaddq] = ACTIONS(23),
    [anon_sym_vpaddw] = ACTIONS(23),
    [anon_sym_vpalignr] = ACTIONS(23),
    [anon_sym_vpand] = ACTIONS(23),
    [anon_sym_vpblendd] = ACTIONS(23),
    [anon_sym_vpblendmd] = ACTIONS(23),
    [anon_sym_vpbroadcastd] = ACTIONS(23),
    [anon_sym_vpbroadcastq] = ACTIONS(23),
    [anon_sym_vpclmulhqhqdq] = ACTIONS(23),
    [anon_sym_vpclmulhqlqdq] = ACTIONS(23),
    [anon_sym_vpclmullqhqdq] = ACTIONS(23),
    [anon_sym_vpclmullqlqdq] = ACTIONS(23),
    [anon_sym_vpcmpgtd] = ACTIONS(23),
    [anon_sym_vpcmpltud] = ACTIONS(23),
    [anon_sym_vperm2f128] = ACTIONS(23),
    [anon_sym_vperm2i128] = ACTIONS(23),
    [anon_sym_vpermd] = ACTIONS(23),
    [anon_sym_vpermi2d] = ACTIONS(23),
    [anon_sym_vpermq] = ACTIONS(23),
    [anon_sym_vpermt2d] = ACTIONS(23),
    [anon_sym_vpextrw] = ACTIONS(23),
    [anon_sym_vpinsrb] = ACTIONS(23),
    [anon_sym_vpinsrd] = ACTIONS(23),
    [anon_sym_vpinsrq] = ACTIONS(23),
    [anon_sym_vpinsrw] = ACTIONS(23),
    [anon_sym_vpmaddubsw] = ACTIONS(23),
    [anon_sym_vpmaddwd] = ACTIONS(23),
    [anon_sym_vpmullw] = ACTIONS(23),
    [anon_sym_vpmuludq] = ACTIONS(23),
    [anon_sym_vpor] = ACTIONS(23),
    [anon_sym_vprord] = ACTIONS(23),
    [anon_sym_vprorq] = ACTIONS(23),
    [anon_sym_vpshufb] = ACTIONS(23),
    [anon_sym_vpshufd] = ACTIONS(23),
    [anon_sym_vpslld] = ACTIONS(23),
    [anon_sym_vpslldq] = ACTIONS(23),
    [anon_sym_vpsllq] = ACTIONS(23),
    [anon_sym_vpsllw] = ACTIONS(23),
    [anon_sym_vpsrld] = ACTIONS(23),
    [anon_sym_vpsrldq] = ACTIONS(23),
    [anon_sym_vpsrlq] = ACTIONS(23),
    [anon_sym_vpsrlw] = ACTIONS(23),
    [anon_sym_vpsubd] = ACTIONS(23),
    [anon_sym_vpsubq] = ACTIONS(23),
    [anon_sym_vpsubusw] = ACTIONS(23),
    [anon_sym_vpsubw] = ACTIONS(23),
    [anon_sym_vpunpckhdq] = ACTIONS(23),
    [anon_sym_vpunpckhqdq] = ACTIONS(23),
    [anon_sym_vpunpckhwd] = ACTIONS(23),
    [anon_sym_vpunpckldq] = ACTIONS(23),
    [anon_sym_vpunpcklqdq] = ACTIONS(23),
    [anon_sym_vpunpcklwd] = ACTIONS(23),
    [anon_sym_vpxor] = ACTIONS(23),
    [anon_sym_vpxord] = ACTIONS(23),
    [anon_sym_vshufi32x4] = ACTIONS(23),
    [anon_sym_vshufi64x2] = ACTIONS(23),
    [anon_sym_vshufps] = ACTIONS(23),
    [anon_sym_vsubsd] = ACTIONS(23),
    [anon_sym_vucomisd] = ACTIONS(23),
    [anon_sym_vucomiss] = ACTIONS(23),
    [anon_sym_vunpckhpd] = ACTIONS(23),
    [anon_sym_vunpckhps] = ACTIONS(23),
    [anon_sym_vunpcklpd] = ACTIONS(23),
    [anon_sym_vunpcklps] = ACTIONS(23),
    [anon_sym_vxorps] = ACTIONS(23),
    [anon_sym_vzeroall] = ACTIONS(23),
    [anon_sym_vzeroupper] = ACTIONS(23),
    [anon_sym_xchg] = ACTIONS(23),
    [anon_sym_xgetbv] = ACTIONS(23),
    [anon_sym_xor] = ACTIONS(23),
    [anon_sym_xorl] = ACTIONS(23),
    [anon_sym_xorpd] = ACTIONS(23),
    [anon_sym_xorps] = ACTIONS(23),
    [anon_sym_xorw] = ACTIONS(23),
    [anon_sym_callq] = ACTIONS(23),
    [anon_sym_ja] = ACTIONS(23),
    [anon_sym_jae] = ACTIONS(23),
    [anon_sym_jb] = ACTIONS(23),
    [anon_sym_jbe] = ACTIONS(23),
    [anon_sym_je] = ACTIONS(23),
    [anon_sym_jg] = ACTIONS(23),
    [anon_sym_jge] = ACTIONS(23),
    [anon_sym_jl] = ACTIONS(23),
    [anon_sym_jle] = ACTIONS(23),
    [anon_sym_jmp] = ACTIONS(23),
    [anon_sym_jmpq] = ACTIONS(23),
    [anon_sym_jne] = ACTIONS(23),
    [anon_sym_jno] = ACTIONS(23),
    [anon_sym_jns] = ACTIONS(23),
    [anon_sym_jo] = ACTIONS(23),
    [anon_sym_jp] = ACTIONS(23),
    [anon_sym_jrcxz] = ACTIONS(23),
    [anon_sym_js] = ACTIONS(23),
    [anon_sym_notrack] = ACTIONS(23),
    [sym_two_bytes] = ACTIONS(25),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 3,
    ACTIONS(30), 1,
      aux_sym_operand_token1,
    STATE(5), 1,
      aux_sym_operand_repeat1,
    ACTIONS(28), 5,
      sym__line_break,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      anon_sym_COMMA,
      anon_sym_,
  [14] = 6,
    ACTIONS(33), 1,
      sym__line_break,
    ACTIONS(37), 1,
      aux_sym_operand_token1,
    STATE(6), 1,
      aux_sym_instruction_repeat1,
    STATE(20), 1,
      aux_sym_operand_repeat1,
    STATE(29), 1,
      sym_operand,
    ACTIONS(35), 2,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [34] = 3,
    ACTIONS(42), 1,
      aux_sym_operand_token1,
    STATE(5), 1,
      aux_sym_operand_repeat1,
    ACTIONS(40), 5,
      sym__line_break,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      anon_sym_COMMA,
      anon_sym_,
  [48] = 6,
    ACTIONS(44), 1,
      sym__line_break,
    ACTIONS(48), 1,
      aux_sym_operand_token1,
    STATE(6), 1,
      aux_sym_instruction_repeat1,
    STATE(7), 1,
      aux_sym_operand_repeat1,
    STATE(12), 1,
      sym_operand,
    ACTIONS(46), 2,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [68] = 6,
    ACTIONS(48), 1,
      aux_sym_operand_token1,
    ACTIONS(50), 1,
      sym__line_break,
    STATE(7), 1,
      aux_sym_operand_repeat1,
    STATE(8), 1,
      aux_sym_instruction_repeat1,
    STATE(14), 1,
      sym_operand,
    ACTIONS(52), 2,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [88] = 5,
    ACTIONS(5), 1,
      aux_sym_address_token1,
    ACTIONS(54), 1,
      ts_builtin_sym_end,
    STATE(25), 1,
      aux_sym_address_repeat1,
    STATE(35), 1,
      sym_address,
    STATE(11), 2,
      sym__line,
      aux_sym_prog_repeat1,
  [105] = 5,
    ACTIONS(56), 1,
      ts_builtin_sym_end,
    ACTIONS(58), 1,
      aux_sym_address_token1,
    STATE(25), 1,
      aux_sym_address_repeat1,
    STATE(35), 1,
      sym_address,
    STATE(11), 2,
      sym__line,
      aux_sym_prog_repeat1,
  [122] = 2,
    ACTIONS(63), 2,
      anon_sym_COMMA,
      anon_sym_,
    ACTIONS(61), 3,
      sym__line_break,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [132] = 4,
    ACTIONS(65), 1,
      sym__line_break,
    ACTIONS(69), 1,
      aux_sym_fn_token1,
    STATE(13), 1,
      aux_sym_fn_repeat1,
    ACTIONS(67), 2,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [146] = 2,
    ACTIONS(63), 2,
      anon_sym_COMMA,
      anon_sym_,
    ACTIONS(46), 3,
      sym__line_break,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [156] = 4,
    ACTIONS(72), 1,
      sym__line_break,
    ACTIONS(76), 1,
      aux_sym_fn_token1,
    STATE(13), 1,
      aux_sym_fn_repeat1,
    ACTIONS(74), 2,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [170] = 2,
    ACTIONS(33), 1,
      sym__line_break,
    ACTIONS(35), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_operand_token1,
  [179] = 3,
    ACTIONS(7), 1,
      sym__line_break,
    STATE(33), 1,
      sym_comment,
    ACTIONS(9), 2,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [190] = 3,
    ACTIONS(78), 1,
      sym__line_break,
    STATE(36), 1,
      sym_comment,
    ACTIONS(9), 2,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [201] = 2,
    ACTIONS(80), 1,
      sym__line_break,
    ACTIONS(82), 3,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
      aux_sym_operand_token1,
  [210] = 4,
    ACTIONS(40), 1,
      anon_sym_COMMA,
    ACTIONS(84), 1,
      anon_sym_,
    ACTIONS(86), 1,
      aux_sym_operand_token1,
    STATE(21), 1,
      aux_sym_operand_repeat1,
  [223] = 4,
    ACTIONS(28), 1,
      anon_sym_COMMA,
    ACTIONS(88), 1,
      anon_sym_,
    ACTIONS(90), 1,
      aux_sym_operand_token1,
    STATE(21), 1,
      aux_sym_operand_repeat1,
  [236] = 2,
    ACTIONS(93), 1,
      sym__line_break,
    ACTIONS(95), 2,
      aux_sym_comment_token1,
      aux_sym_comment_token2,
  [244] = 3,
    ACTIONS(97), 1,
      aux_sym_fn_token1,
    STATE(15), 1,
      aux_sym_fn_repeat1,
    STATE(22), 1,
      sym_fn,
  [254] = 3,
    ACTIONS(99), 1,
      anon_sym_COLON,
    ACTIONS(101), 1,
      aux_sym_address_token1,
    STATE(24), 1,
      aux_sym_address_repeat1,
  [264] = 3,
    ACTIONS(104), 1,
      anon_sym_COLON,
    ACTIONS(106), 1,
      aux_sym_address_token1,
    STATE(24), 1,
      aux_sym_address_repeat1,
  [274] = 1,
    ACTIONS(108), 2,
      ts_builtin_sym_end,
      aux_sym_address_token1,
  [279] = 1,
    ACTIONS(110), 2,
      ts_builtin_sym_end,
      aux_sym_address_token1,
  [284] = 1,
    ACTIONS(112), 2,
      ts_builtin_sym_end,
      aux_sym_address_token1,
  [289] = 2,
    ACTIONS(63), 1,
      anon_sym_COMMA,
    ACTIONS(114), 1,
      anon_sym_,
  [296] = 1,
    ACTIONS(116), 2,
      ts_builtin_sym_end,
      aux_sym_address_token1,
  [301] = 1,
    ACTIONS(118), 1,
      ts_builtin_sym_end,
  [305] = 1,
    ACTIONS(7), 1,
      sym__line_break,
  [309] = 1,
    ACTIONS(78), 1,
      sym__line_break,
  [313] = 1,
    ACTIONS(120), 1,
      sym__line_break,
  [317] = 1,
    ACTIONS(122), 1,
      anon_sym_COLON,
  [321] = 1,
    ACTIONS(124), 1,
      sym__line_break,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 14,
  [SMALL_STATE(7)] = 34,
  [SMALL_STATE(8)] = 48,
  [SMALL_STATE(9)] = 68,
  [SMALL_STATE(10)] = 88,
  [SMALL_STATE(11)] = 105,
  [SMALL_STATE(12)] = 122,
  [SMALL_STATE(13)] = 132,
  [SMALL_STATE(14)] = 146,
  [SMALL_STATE(15)] = 156,
  [SMALL_STATE(16)] = 170,
  [SMALL_STATE(17)] = 179,
  [SMALL_STATE(18)] = 190,
  [SMALL_STATE(19)] = 201,
  [SMALL_STATE(20)] = 210,
  [SMALL_STATE(21)] = 223,
  [SMALL_STATE(22)] = 236,
  [SMALL_STATE(23)] = 244,
  [SMALL_STATE(24)] = 254,
  [SMALL_STATE(25)] = 264,
  [SMALL_STATE(26)] = 274,
  [SMALL_STATE(27)] = 279,
  [SMALL_STATE(28)] = 284,
  [SMALL_STATE(29)] = 289,
  [SMALL_STATE(30)] = 296,
  [SMALL_STATE(31)] = 301,
  [SMALL_STATE(32)] = 305,
  [SMALL_STATE(33)] = 309,
  [SMALL_STATE(34)] = 313,
  [SMALL_STATE(35)] = 317,
  [SMALL_STATE(36)] = 321,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prog, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__line_repeat1, 2),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__line_repeat1, 2),
  [25] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__line_repeat1, 2), SHIFT_REPEAT(4),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_operand_repeat1, 2),
  [30] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_operand_repeat1, 2), SHIFT_REPEAT(5),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_instruction_repeat1, 2),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_instruction_repeat1, 2),
  [37] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_instruction_repeat1, 2), SHIFT_REPEAT(20),
  [40] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operand, 1),
  [42] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 2),
  [46] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_instruction, 2),
  [48] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [50] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_instruction, 1),
  [52] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_instruction, 1),
  [54] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_prog, 1),
  [56] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_prog_repeat1, 2),
  [58] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_prog_repeat1, 2), SHIFT_REPEAT(25),
  [61] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_instruction, 3),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [65] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_fn_repeat1, 2),
  [67] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_fn_repeat1, 2),
  [69] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_fn_repeat1, 2), SHIFT_REPEAT(13),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fn, 1),
  [74] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_fn, 1),
  [76] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [80] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_opcode, 1),
  [82] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_opcode, 1),
  [84] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operand, 1),
  [86] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_operand_repeat1, 2),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_operand_repeat1, 2), SHIFT_REPEAT(21),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_callq, 2),
  [95] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_callq, 2),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [99] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_address_repeat1, 2),
  [101] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_address_repeat1, 2), SHIFT_REPEAT(24),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_address, 1),
  [106] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 4),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 3),
  [112] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 5),
  [114] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [116] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__line, 6),
  [118] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [120] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1),
  [122] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [124] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_asm(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
