#if 0
//
// Generated by Microsoft (R) D3D Shader Disassembler
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Position              0   xyzw        0     NONE   float   xyzw
// NORMAL                   0   xyz         1     NONE   float   xyz 
// TEXCOORD                 0   xy          2     NONE   float   xy  
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
// COLOR                    1   xyzw        1     NONE   float   xyzw
// TEXCOORD                 0   xy          2     NONE   float   xy  
// TEXCOORD                 1   xyz         3     NONE   float   xyz 
// SV_Position              0   xyzw        4      POS   float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c1         cb0             1        10  ( FLT, FLT, FLT, FLT)
// c11        cb0            12         4  ( FLT, FLT, FLT, FLT)
// c15        cb0            17         7  ( FLT, FLT, FLT, FLT)
//
//
// Runtime generated constant mappings:
//
// Target Reg                               Constant Description
// ---------- --------------------------------------------------
// c0                              Vertex Shader position offset
//
//
// Level9 shader bytecode:
//
    vs_2_0
    def c22, 2, -1, 0, 1
    dcl_texcoord v0  // vin<0,1,2,3>
    dcl_texcoord1 v1  // vin<4,5,6>
    dcl_texcoord2 v2  // vin<7,8>

#line 11 "C:\Users\cai_genkan\Desktop\source2222\02_DTK\src\Shaders\Utilities.fxh"
    mad r0.xyz, v1, c22.x, c22.y  // ::BiasX2<0,1,2>

#line 66 "C:\Users\cai_genkan\Desktop\source2222\02_DTK\src\Shaders\EnvironmentMapEffect.fx"
    dp3 r1.x, r0, c15
    dp3 r1.y, r0, c16
    dp3 r1.z, r0, c17
    nrm r0.xyz, r1  // ::worldNormal<0,1,2>

#line 34 "C:\Users\cai_genkan\Desktop\source2222\02_DTK\src\Shaders\Lighting.fxh"
    dp3 r1.x, -c4, r0  // ::dotL<0>
    dp3 r1.y, -c5, r0  // ::dotL<1>
    dp3 r1.z, -c6, r0  // ::dotL<2>

#line 37
    sge r2.xyz, r1, c22.z  // ::zeroL<0,1,2>
    mul r1.xyz, r1, r2  // ::diffuse<0,1,2>

#line 44
    mul r2.xyz, r1.y, c8
    mad r1.xyw, r1.x, c7.xyzz, r2.xyzz
    mad r1.xyz, r1.z, c9, r1.xyww
    mov r2.xyz, c2  // Parameters::DiffuseColor<0,1,2>
    mad oT0.xyz, r1, r2, c3  // ::VSEnvMapFresnelBn<0,1,2>

#line 70 "C:\Users\cai_genkan\Desktop\source2222\02_DTK\src\Shaders\EnvironmentMapEffect.fx"
    dp4 oPos.z, v0, c20  // ::VSEnvMapFresnelBn<15>

#line 64
    dp4 r1.x, v0, c12  // ::pos_ws<0>
    dp4 r1.y, v0, c13  // ::pos_ws<1>
    dp4 r1.z, v0, c14  // ::pos_ws<2>
    add r1.xyz, -r1, c10
    nrm r2.xyz, r1  // ::eyeVector<0,1,2>

#line 54
    dp3 r0.w, r2, r0  // ::viewAngle<0>
    abs r0.w, r0.w
    add r0.w, -r0.w, c22.w
    max r0.w, r0.w, c22.z
    pow r1.x, r0.w, c1.y
    mul oT1.xyz, r1.x, c1.x  // ::VSEnvMapFresnelBn<4,5,6>

#line 12 "C:\Users\cai_genkan\Desktop\source2222\02_DTK\src\Shaders\Common.fxh"
    dp4 r0.w, v0, c11
    max r0.w, r0.w, c22.z
    min oT1.w, r0.w, c22.w  // ::VSEnvMapFresnelBn<7>

#line 80 "C:\Users\cai_genkan\Desktop\source2222\02_DTK\src\Shaders\EnvironmentMapEffect.fx"
    dp3 r0.w, -r2, r0
    add r0.w, r0.w, r0.w
    mad oT3.xyz, r0, -r0.w, -r2  // ::VSEnvMapFresnelBn<10,11,12>

#line 70
    dp4 r0.x, v0, c18  // ::vout<13>
    dp4 r0.y, v0, c19  // ::vout<14>
    dp4 r0.z, v0, c21  // ::vout<16>

#line 200
    mad oPos.xy, r0.z, c0, r0  // ::VSEnvMapFresnelBn<13,14>
    mov oPos.w, r0.z  // ::VSEnvMapFresnelBn<16>

#line 44 "C:\Users\cai_genkan\Desktop\source2222\02_DTK\src\Shaders\Lighting.fxh"
    mov oT0.w, c2.w  // ::VSEnvMapFresnelBn<3>

#line 204 "C:\Users\cai_genkan\Desktop\source2222\02_DTK\src\Shaders\EnvironmentMapEffect.fx"
    mov oT2.xy, v2  // ::VSEnvMapFresnelBn<8,9>

// approximately 46 instruction slots used
vs_4_0
dcl_constantbuffer CB0[24], immediateIndexed
dcl_input v0.xyzw
dcl_input v1.xyz
dcl_input v2.xy
dcl_output o0.xyzw
dcl_output o1.xyzw
dcl_output o2.xy
dcl_output o3.xyz
dcl_output_siv o4.xyzw, position
dcl_temps 3
mad r0.xyz, v1.xyzx, l(2.000000, 2.000000, 2.000000, 0.000000), l(-1.000000, -1.000000, -1.000000, 0.000000)
dp3 r1.x, r0.xyzx, cb0[17].xyzx
dp3 r1.y, r0.xyzx, cb0[18].xyzx
dp3 r1.z, r0.xyzx, cb0[19].xyzx
dp3 r0.x, r1.xyzx, r1.xyzx
rsq r0.x, r0.x
mul r0.xyz, r0.xxxx, r1.xyzx
dp3 r1.x, -cb0[4].xyzx, r0.xyzx
dp3 r1.y, -cb0[5].xyzx, r0.xyzx
dp3 r1.z, -cb0[6].xyzx, r0.xyzx
ge r2.xyz, r1.xyzx, l(0.000000, 0.000000, 0.000000, 0.000000)
and r2.xyz, r2.xyzx, l(0x3f800000, 0x3f800000, 0x3f800000, 0)
mul r1.xyz, r1.xyzx, r2.xyzx
mul r2.xyz, r1.yyyy, cb0[8].xyzx
mad r1.xyw, r1.xxxx, cb0[7].xyxz, r2.xyxz
mad r1.xyz, r1.zzzz, cb0[9].xyzx, r1.xywx
mad o0.xyz, r1.xyzx, cb0[2].xyzx, cb0[3].xyzx
mov o0.w, cb0[2].w
dp4 r1.x, v0.xyzw, cb0[13].xyzw
dp4 r1.y, v0.xyzw, cb0[14].xyzw
dp4 r1.z, v0.xyzw, cb0[15].xyzw
add r1.xyz, -r1.xyzx, cb0[10].xyzx
dp3 r0.w, r1.xyzx, r1.xyzx
rsq r0.w, r0.w
mul r1.xyz, r0.wwww, r1.xyzx
dp3 r0.w, r1.xyzx, r0.xyzx
add r0.w, -|r0.w|, l(1.000000)
max r0.w, r0.w, l(0.000000)
log r0.w, r0.w
mul r0.w, r0.w, cb0[1].y
exp r0.w, r0.w
mul o1.xyz, r0.wwww, cb0[1].xxxx
dp4_sat o1.w, v0.xyzw, cb0[12].xyzw
mov o2.xy, v2.xyxx
dp3 r0.w, -r1.xyzx, r0.xyzx
add r0.w, r0.w, r0.w
mad o3.xyz, r0.xyzx, -r0.wwww, -r1.xyzx
dp4 o4.x, v0.xyzw, cb0[20].xyzw
dp4 o4.y, v0.xyzw, cb0[21].xyzw
dp4 o4.z, v0.xyzw, cb0[22].xyzw
dp4 o4.w, v0.xyzw, cb0[23].xyzw
ret 
// Approximately 0 instruction slots used
#endif

const BYTE EnvironmentMapEffect_VSEnvMapFresnelBn[] =
{
     68,  88,  66,  67, 240, 142, 
    230,  90,  97, 159,  55,  87, 
    177, 174, 161,  50, 141,  27, 
    249,  71,   1,   0,   0,   0, 
    212,  16,   0,   0,   4,   0, 
      0,   0,  48,   0,   0,   0, 
     12,  10,   0,   0, 188,  15, 
      0,   0,  48,  16,   0,   0, 
     65, 111, 110,  57, 212,   9, 
      0,   0, 212,   9,   0,   0, 
      0,   2, 254, 255, 136,   9, 
      0,   0,  76,   0,   0,   0, 
      3,   0,  36,   0,   0,   0, 
     72,   0,   0,   0,  72,   0, 
      0,   0,  36,   0,   1,   0, 
     72,   0,   0,   0,   1,   0, 
     10,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  12,   0, 
      4,   0,  11,   0,   0,   0, 
      0,   0,   0,   0,  17,   0, 
      7,   0,  15,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   2, 254, 255, 254, 255, 
    177,   1,  68,  66,  85,  71, 
     40,   0,   0,   0, 152,   6, 
      0,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,  80,   1, 
      0,   0,  44,   0,   0,   0, 
     96,   1,   0,   0,  12,   0, 
      0,   0, 168,   5,   0,   0, 
     24,   3,   0,   0,  67,  58, 
     92,  85, 115, 101, 114, 115, 
     92,  99,  97, 105,  95, 103, 
    101, 110, 107,  97, 110,  92, 
     68, 101, 115, 107, 116, 111, 
    112,  92, 115, 111, 117, 114, 
     99, 101,  50,  50,  50,  50, 
     92,  48,  50,  95,  68,  84, 
     75,  92, 115, 114,  99,  92, 
     83, 104,  97, 100, 101, 114, 
    115,  92,  85, 116, 105, 108, 
    105, 116, 105, 101, 115,  46, 
    102, 120, 104,   0,  67,  58, 
     92,  85, 115, 101, 114, 115, 
     92,  99,  97, 105,  95, 103, 
    101, 110, 107,  97, 110,  92, 
     68, 101, 115, 107, 116, 111, 
    112,  92, 115, 111, 117, 114, 
     99, 101,  50,  50,  50,  50, 
     92,  48,  50,  95,  68,  84, 
     75,  92, 115, 114,  99,  92, 
     83, 104,  97, 100, 101, 114, 
    115,  92,  69, 110, 118, 105, 
    114, 111, 110, 109, 101, 110, 
    116,  77,  97, 112,  69, 102, 
    102, 101,  99, 116,  46, 102, 
    120,   0,  67,  58,  92,  85, 
    115, 101, 114, 115,  92,  99, 
     97, 105,  95, 103, 101, 110, 
    107,  97, 110,  92,  68, 101, 
    115, 107, 116, 111, 112,  92, 
    115, 111, 117, 114,  99, 101, 
     50,  50,  50,  50,  92,  48, 
     50,  95,  68,  84,  75,  92, 
    115, 114,  99,  92,  83, 104, 
     97, 100, 101, 114, 115,  92, 
     76, 105, 103, 104, 116, 105, 
    110, 103,  46, 102, 120, 104, 
      0,  67,  58,  92,  85, 115, 
    101, 114, 115,  92,  99,  97, 
    105,  95, 103, 101, 110, 107, 
     97, 110,  92,  68, 101, 115, 
    107, 116, 111, 112,  92, 115, 
    111, 117, 114,  99, 101,  50, 
     50,  50,  50,  92,  48,  50, 
     95,  68,  84,  75,  92, 115, 
    114,  99,  92,  83, 104,  97, 
    100, 101, 114, 115,  92,  67, 
    111, 109, 109, 111, 110,  46, 
    102, 120, 104,   0, 171, 171, 
     40,   0,   0,   0, 112,   0, 
      0,   0, 194,   0,   0,   0, 
      9,   1,   0,   0,   0,   0, 
    255, 255, 204,   6,   0,   0, 
      0,   0, 255, 255, 228,   6, 
      0,   0,   0,   0, 255, 255, 
    240,   6,   0,   0,   0,   0, 
    255, 255, 252,   6,   0,   0, 
     11,   0,   0,   0,   8,   7, 
      0,   0,  66,   0,   1,   0, 
     28,   7,   0,   0,  66,   0, 
      1,   0,  44,   7,   0,   0, 
     66,   0,   1,   0,  60,   7, 
      0,   0,  66,   0,   1,   0, 
     76,   7,   0,   0,  34,   0, 
      2,   0,  88,   7,   0,   0, 
     34,   0,   2,   0, 104,   7, 
      0,   0,  34,   0,   2,   0, 
    120,   7,   0,   0,  37,   0, 
      2,   0, 136,   7,   0,   0, 
     39,   0,   2,   0, 152,   7, 
      0,   0,  44,   0,   2,   0, 
    168,   7,   0,   0,  44,   0, 
      2,   0, 184,   7,   0,   0, 
     44,   0,   2,   0, 204,   7, 
      0,   0,  44,   0,   2,   0, 
    224,   7,   0,   0,  44,   0, 
      2,   0, 236,   7,   0,   0, 
     70,   0,   1,   0,   0,   8, 
      0,   0,  64,   0,   1,   0, 
     16,   8,   0,   0,  64,   0, 
      1,   0,  32,   8,   0,   0, 
     64,   0,   1,   0,  48,   8, 
      0,   0,  65,   0,   1,   0, 
     64,   8,   0,   0,  65,   0, 
      1,   0,  80,   8,   0,   0, 
     54,   0,   1,   0,  92,   8, 
      0,   0,  56,   0,   1,   0, 
    108,   8,   0,   0,  56,   0, 
      1,   0, 120,   8,   0,   0, 
     56,   0,   1,   0, 136,   8, 
      0,   0,  56,   0,   1,   0, 
    152,   8,   0,   0,  56,   0, 
      1,   0, 168,   8,   0,   0, 
     12,   0,   3,   0, 184,   8, 
      0,   0,  12,   0,   3,   0, 
    200,   8,   0,   0,  12,   0, 
      3,   0, 216,   8,   0,   0, 
     80,   0,   1,   0, 232,   8, 
      0,   0,  80,   0,   1,   0, 
    248,   8,   0,   0,  80,   0, 
      1,   0,   8,   9,   0,   0, 
     70,   0,   1,   0,  28,   9, 
      0,   0,  70,   0,   1,   0, 
     44,   9,   0,   0,  70,   0, 
      1,   0,  60,   9,   0,   0, 
    200,   0,   1,   0,  76,   9, 
      0,   0, 200,   0,   1,   0, 
     96,   9,   0,   0,  44,   0, 
      2,   0, 108,   9,   0,   0, 
    204,   0,   1,   0, 120,   9, 
      0,   0,  66, 105,  97, 115, 
     88,  50,   0, 171,   1,   0, 
      3,   0,   1,   0,   3,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  80,  97, 114,  97, 
    109, 101, 116, 101, 114, 115, 
      0,  68, 105, 102, 102, 117, 
    115, 101,  67, 111, 108, 111, 
    114,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     17,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
     86,  83,  69, 110, 118,  77, 
     97, 112,  70, 114, 101, 115, 
    110, 101, 108,  66, 110,   0, 
     68, 105, 102, 102, 117, 115, 
    101,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  83, 112, 101,  99, 
    117, 108,  97, 114,   0,  84, 
    101, 120,  67, 111, 111, 114, 
    100,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   2,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,  69, 110, 118,  67, 
    111, 111, 114, 100,   0, 171, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   3,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     80, 111, 115, 105, 116, 105, 
    111, 110,  80,  83,   0, 171, 
     42,   3,   0,   0,  52,   3, 
      0,   0,  68,   3,   0,   0, 
     52,   3,   0,   0,  77,   3, 
      0,   0,  88,   3,   0,   0, 
    104,   3,   0,   0, 116,   3, 
      0,   0, 132,   3,   0,   0, 
     52,   3,   0,   0,   5,   0, 
      0,   0,   1,   0,  17,   0, 
      1,   0,   5,   0, 144,   3, 
      0,   0,  18,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,  19,   0,   0,   0, 
    255, 255, 255, 255,  15,   0, 
    255, 255,  30,   0,   0,   0, 
      4,   0,   5,   0,   6,   0, 
    255, 255,  33,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      7,   0,  36,   0,   0,   0, 
     10,   0,  11,   0,  12,   0, 
    255, 255,  40,   0,   0,   0, 
     13,   0,  14,   0, 255, 255, 
    255, 255,  41,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
     16,   0,  42,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
      3,   0,  43,   0,   0,   0, 
      8,   0,   9,   0, 255, 255, 
    255, 255, 100, 105, 102, 102, 
    117, 115, 101,   0,  13,   0, 
      0,   0,   0,   0,   1,   0, 
      2,   0, 255, 255, 100, 111, 
    116,  76,   0, 171, 171, 171, 
      9,   0,   0,   0,   0,   0, 
    255, 255, 255, 255, 255, 255, 
     10,   0,   0,   0, 255, 255, 
      1,   0, 255, 255, 255, 255, 
     11,   0,   0,   0, 255, 255, 
    255, 255,   2,   0, 255, 255, 
    101, 121, 101,  86, 101,  99, 
    116, 111, 114,   0, 171, 171, 
     24,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
    112, 111, 115,  95, 119, 115, 
      0, 171,  20,   0,   0,   0, 
      0,   0, 255, 255, 255, 255, 
    255, 255,  21,   0,   0,   0, 
    255, 255,   1,   0, 255, 255, 
    255, 255,  22,   0,   0,   0, 
    255, 255, 255, 255,   2,   0, 
    255, 255, 118, 105, 101, 119, 
     65, 110, 103, 108, 101,   0, 
    171, 171,   0,   0,   3,   0, 
      1,   0,   1,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     25,   0,   0,   0, 255, 255, 
    255, 255, 255, 255,   0,   0, 
    118, 105, 110,   0,  80, 111, 
    115, 105, 116, 105, 111, 110, 
      0,  78, 111, 114, 109,  97, 
    108,   0, 228,   4,   0,   0, 
     52,   3,   0,   0, 237,   4, 
      0,   0, 116,   3,   0,   0, 
     77,   3,   0,   0,  88,   3, 
      0,   0,   5,   0,   0,   0, 
      1,   0,   9,   0,   1,   0, 
      3,   0, 244,   4,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      1,   0,   2,   0,   3,   0, 
      2,   0,   0,   0,   4,   0, 
      5,   0,   6,   0, 255, 255, 
      3,   0,   0,   0,   7,   0, 
      8,   0, 255, 255, 255, 255, 
    118, 111, 117, 116,   0, 171, 
    171, 171,   5,   0,   0,   0, 
      1,   0,  17,   0,   1,   0, 
      5,   0, 144,   3,   0,   0, 
     37,   0,   0,   0,  13,   0, 
    255, 255, 255, 255, 255, 255, 
     38,   0,   0,   0, 255, 255, 
     14,   0, 255, 255, 255, 255, 
     39,   0,   0,   0, 255, 255, 
    255, 255,  16,   0, 255, 255, 
    119, 111, 114, 108, 100,  78, 
    111, 114, 109,  97, 108,   0, 
      8,   0,   0,   0,   0,   0, 
      1,   0,   2,   0, 255, 255, 
    122, 101, 114, 111,  76,   0, 
    171, 171,  12,   0,   0,   0, 
      0,   0,   1,   0,   2,   0, 
    255, 255,   0,   0,   0,   0, 
    192,   2,   0,   0, 200,   2, 
      0,   0,   1,   0,   0,   0, 
    216,   2,   0,   0, 228,   2, 
      0,   0, 239,   2,   0,   0, 
    252,   2,   0,   0,   1,   0, 
      0,   0,  12,   3,   0,   0, 
      0,   0,   0,   0,  24,   3, 
      0,   0, 184,   3,   0,   0, 
      9,   0,   0,   0, 200,   3, 
      0,   0,   0,   0,   0,   0, 
     52,   4,   0,   0, 116,   3, 
      0,   0,   1,   0,   0,   0, 
     60,   4,   0,   0,   0,   0, 
      0,   0,  72,   4,   0,   0, 
    116,   3,   0,   0,   3,   0, 
      0,   0,  80,   4,   0,   0, 
      0,   0,   0,   0, 116,   4, 
      0,   0, 116,   3,   0,   0, 
      1,   0,   0,   0, 128,   4, 
      0,   0,   0,   0,   0,   0, 
    140,   4,   0,   0,  52,   3, 
      0,   0,   3,   0,   0,   0, 
    148,   4,   0,   0,   0,   0, 
      0,   0, 184,   4,   0,   0, 
    196,   4,   0,   0,   1,   0, 
      0,   0, 212,   4,   0,   0, 
     24,   3,   0,   0, 224,   4, 
      0,   0,  12,   5,   0,   0, 
      3,   0,   0,   0,  28,   5, 
      0,   0,   0,   0,   0,   0, 
     64,   5,   0,   0,  72,   5, 
      0,   0,   3,   0,   0,   0, 
     88,   5,   0,   0,   0,   0, 
      0,   0, 124,   5,   0,   0, 
    116,   3,   0,   0,   1,   0, 
      0,   0, 136,   5,   0,   0, 
      0,   0,   0,   0, 148,   5, 
      0,   0, 116,   3,   0,   0, 
      1,   0,   0,   0, 156,   5, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  49,  48,  46,  49,   0, 
     81,   0,   0,   5,  22,   0, 
     15, 160,   0,   0,   0,  64, 
      0,   0, 128, 191,   0,   0, 
      0,   0,   0,   0, 128,  63, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   0,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      1, 128,   1,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      2, 128,   2,   0,  15, 144, 
      4,   0,   0,   4,   0,   0, 
      7, 128,   1,   0, 228, 144, 
     22,   0,   0, 160,  22,   0, 
     85, 160,   8,   0,   0,   3, 
      1,   0,   1, 128,   0,   0, 
    228, 128,  15,   0, 228, 160, 
      8,   0,   0,   3,   1,   0, 
      2, 128,   0,   0, 228, 128, 
     16,   0, 228, 160,   8,   0, 
      0,   3,   1,   0,   4, 128, 
      0,   0, 228, 128,  17,   0, 
    228, 160,  36,   0,   0,   2, 
      0,   0,   7, 128,   1,   0, 
    228, 128,   8,   0,   0,   3, 
      1,   0,   1, 128,   4,   0, 
    228, 161,   0,   0, 228, 128, 
      8,   0,   0,   3,   1,   0, 
      2, 128,   5,   0, 228, 161, 
      0,   0, 228, 128,   8,   0, 
      0,   3,   1,   0,   4, 128, 
      6,   0, 228, 161,   0,   0, 
    228, 128,  13,   0,   0,   3, 
      2,   0,   7, 128,   1,   0, 
    228, 128,  22,   0, 170, 160, 
      5,   0,   0,   3,   1,   0, 
      7, 128,   1,   0, 228, 128, 
      2,   0, 228, 128,   5,   0, 
      0,   3,   2,   0,   7, 128, 
      1,   0,  85, 128,   8,   0, 
    228, 160,   4,   0,   0,   4, 
      1,   0,  11, 128,   1,   0, 
      0, 128,   7,   0, 164, 160, 
      2,   0, 164, 128,   4,   0, 
      0,   4,   1,   0,   7, 128, 
      1,   0, 170, 128,   9,   0, 
    228, 160,   1,   0, 244, 128, 
      1,   0,   0,   2,   2,   0, 
      7, 128,   2,   0, 228, 160, 
      4,   0,   0,   4,   0,   0, 
      7, 224,   1,   0, 228, 128, 
      2,   0, 228, 128,   3,   0, 
    228, 160,   9,   0,   0,   3, 
      0,   0,   4, 192,   0,   0, 
    228, 144,  20,   0, 228, 160, 
      9,   0,   0,   3,   1,   0, 
      1, 128,   0,   0, 228, 144, 
     12,   0, 228, 160,   9,   0, 
      0,   3,   1,   0,   2, 128, 
      0,   0, 228, 144,  13,   0, 
    228, 160,   9,   0,   0,   3, 
      1,   0,   4, 128,   0,   0, 
    228, 144,  14,   0, 228, 160, 
      2,   0,   0,   3,   1,   0, 
      7, 128,   1,   0, 228, 129, 
     10,   0, 228, 160,  36,   0, 
      0,   2,   2,   0,   7, 128, 
      1,   0, 228, 128,   8,   0, 
      0,   3,   0,   0,   8, 128, 
      2,   0, 228, 128,   0,   0, 
    228, 128,  35,   0,   0,   2, 
      0,   0,   8, 128,   0,   0, 
    255, 128,   2,   0,   0,   3, 
      0,   0,   8, 128,   0,   0, 
    255, 129,  22,   0, 255, 160, 
     11,   0,   0,   3,   0,   0, 
      8, 128,   0,   0, 255, 128, 
     22,   0, 170, 160,  32,   0, 
      0,   3,   1,   0,   1, 128, 
      0,   0, 255, 128,   1,   0, 
     85, 160,   5,   0,   0,   3, 
      1,   0,   7, 224,   1,   0, 
      0, 128,   1,   0,   0, 160, 
      9,   0,   0,   3,   0,   0, 
      8, 128,   0,   0, 228, 144, 
     11,   0, 228, 160,  11,   0, 
      0,   3,   0,   0,   8, 128, 
      0,   0, 255, 128,  22,   0, 
    170, 160,  10,   0,   0,   3, 
      1,   0,   8, 224,   0,   0, 
    255, 128,  22,   0, 255, 160, 
      8,   0,   0,   3,   0,   0, 
      8, 128,   2,   0, 228, 129, 
      0,   0, 228, 128,   2,   0, 
      0,   3,   0,   0,   8, 128, 
      0,   0, 255, 128,   0,   0, 
    255, 128,   4,   0,   0,   4, 
      3,   0,   7, 224,   0,   0, 
    228, 128,   0,   0, 255, 129, 
      2,   0, 228, 129,   9,   0, 
      0,   3,   0,   0,   1, 128, 
      0,   0, 228, 144,  18,   0, 
    228, 160,   9,   0,   0,   3, 
      0,   0,   2, 128,   0,   0, 
    228, 144,  19,   0, 228, 160, 
      9,   0,   0,   3,   0,   0, 
      4, 128,   0,   0, 228, 144, 
     21,   0, 228, 160,   4,   0, 
      0,   4,   0,   0,   3, 192, 
      0,   0, 170, 128,   0,   0, 
    228, 160,   0,   0, 228, 128, 
      1,   0,   0,   2,   0,   0, 
      8, 192,   0,   0, 170, 128, 
      1,   0,   0,   2,   0,   0, 
      8, 224,   2,   0, 255, 160, 
      1,   0,   0,   2,   2,   0, 
      3, 224,   2,   0, 228, 144, 
    255, 255,   0,   0,  83,  72, 
     68,  82, 168,   5,   0,   0, 
     64,   0,   1,   0, 106,   1, 
      0,   0,  89,   0,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  24,   0,   0,   0, 
     95,   0,   0,   3, 242,  16, 
     16,   0,   0,   0,   0,   0, 
     95,   0,   0,   3, 114,  16, 
     16,   0,   1,   0,   0,   0, 
     95,   0,   0,   3,  50,  16, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   0,   0,   0,   0, 
    101,   0,   0,   3, 242,  32, 
     16,   0,   1,   0,   0,   0, 
    101,   0,   0,   3,  50,  32, 
     16,   0,   2,   0,   0,   0, 
    101,   0,   0,   3, 114,  32, 
     16,   0,   3,   0,   0,   0, 
    103,   0,   0,   4, 242,  32, 
     16,   0,   4,   0,   0,   0, 
      1,   0,   0,   0, 104,   0, 
      0,   2,   3,   0,   0,   0, 
     50,   0,   0,  15, 114,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,  64,   0,   0, 
      0,  64,   0,   0,   0,  64, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128, 191, 
      0,   0, 128, 191,   0,   0, 
    128, 191,   0,   0,   0,   0, 
     16,   0,   0,   8,  18,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,  70, 130,  32,   0, 
      0,   0,   0,   0,  17,   0, 
      0,   0,  16,   0,   0,   8, 
     34,   0,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
     18,   0,   0,   0,  16,   0, 
      0,   8,  66,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,  19,   0,   0,   0, 
     16,   0,   0,   7,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  68,   0, 
      0,   5,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   0,   0,   0,   0, 
      6,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  16,   0, 
      0,   9,  18,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   9,  34,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  16,   0, 
      0,   9,  66,   0,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0,  70,   2,  16,   0, 
      0,   0,   0,   0,  29,   0, 
      0,  10, 114,   0,  16,   0, 
      2,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,  10, 
    114,   0,  16,   0,   2,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0,   0,   0, 
     56,   0,   0,   7, 114,   0, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  70,   2,  16,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   8, 114,   0,  16,   0, 
      2,   0,   0,   0,  86,   5, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     50,   0,   0,  10, 178,   0, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   1,   0, 
      0,   0,  70, 136,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,  70,   8,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  10, 114,   0,  16,   0, 
      1,   0,   0,   0, 166,  10, 
     16,   0,   1,   0,   0,   0, 
     70, 130,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     70,   3,  16,   0,   1,   0, 
      0,   0,  50,   0,   0,  11, 
    114,  32,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  54,   0, 
      0,   6, 130,  32,  16,   0, 
      0,   0,   0,   0,  58, 128, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  17,   0, 
      0,   8,  18,   0,  16,   0, 
      1,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  13,   0,   0,   0, 
     17,   0,   0,   8,  34,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  30,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,  14,   0, 
      0,   0,  17,   0,   0,   8, 
     66,   0,  16,   0,   1,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,   0,   0, 
      0,   9, 114,   0,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16, 128,  65,   0,   0,   0, 
      1,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
     10,   0,   0,   0,  16,   0, 
      0,   7, 130,   0,  16,   0, 
      0,   0,   0,   0,  70,   2, 
     16,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  68,   0,   0,   5, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 114,   0,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16,   0,   1,   0, 
      0,   0,  16,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  70,   2,  16,   0, 
      1,   0,   0,   0,  70,   2, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16, 128, 193,   0, 
      0,   0,   0,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  52,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   0,   0,   0,   0, 
     47,   0,   0,   5, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,  25,   0, 
      0,   5, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   8, 114,  32, 
     16,   0,   1,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,   6, 128,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  17,  32,   0,   8, 
    130,  32,  16,   0,   1,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     12,   0,   0,   0,  54,   0, 
      0,   5,  50,  32,  16,   0, 
      2,   0,   0,   0,  70,  16, 
     16,   0,   2,   0,   0,   0, 
     16,   0,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   2,  16, 128,  65,   0, 
      0,   0,   1,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  11, 114,  32, 
     16,   0,   3,   0,   0,   0, 
     70,   2,  16,   0,   0,   0, 
      0,   0, 246,  15,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  70,   2,  16, 128, 
     65,   0,   0,   0,   1,   0, 
      0,   0,  17,   0,   0,   8, 
     18,  32,  16,   0,   4,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     20,   0,   0,   0,  17,   0, 
      0,   8,  34,  32,  16,   0, 
      4,   0,   0,   0,  70,  30, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  21,   0,   0,   0, 
     17,   0,   0,   8,  66,  32, 
     16,   0,   4,   0,   0,   0, 
     70,  30,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,  22,   0, 
      0,   0,  17,   0,   0,   8, 
    130,  32,  16,   0,   4,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     23,   0,   0,   0,  62,   0, 
      0,   1,  73,  83,  71,  78, 
    108,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
     80,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,  15,  15,   0,   0, 
     92,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,   7,   7,   0,   0, 
     99,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   2,   0, 
      0,   0,   3,   3,   0,   0, 
     83,  86,  95,  80, 111, 115, 
    105, 116, 105, 111, 110,   0, 
     78,  79,  82,  77,  65,  76, 
      0,  84,  69,  88,  67,  79, 
     79,  82,  68,   0,  79,  83, 
     71,  78, 156,   0,   0,   0, 
      5,   0,   0,   0,   8,   0, 
      0,   0, 128,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0, 128,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,   0, 
      0,   0, 134,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,  12, 
      0,   0, 134,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   7,   8, 
      0,   0, 143,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,  15,   0, 
      0,   0,  67,  79,  76,  79, 
     82,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  83, 
     86,  95,  80, 111, 115, 105, 
    116, 105, 111, 110,   0, 171
};