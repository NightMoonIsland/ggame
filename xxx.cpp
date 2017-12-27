// Compiled shader for iPhone, iPod Touch and iPad

//////////////////////////////////////////////////////////////////////////
// 
// NOTE: This is *not* a valid shader file, the contents are provided just
// for information and for debugging purposes only.
// 
//////////////////////////////////////////////////////////////////////////
// Skipping shader variants that would not be included into build of current scene.

Shader "Legacy Shaders/Transparent/Cutout/VertexLit" {
Properties {
 _Color ("Main Color", Color) = (1.000000,1.000000,1.000000,1.000000)
 _SpecColor ("Spec Color", Color) = (1.000000,1.000000,1.000000,0.000000)
 _Emission ("Emissive Color", Color) = (0.000000,0.000000,0.000000,0.000000)
 _Shininess ("Shininess", Range(0.100000,1.000000)) = 0.700000
 _MainTex ("Base (RGB) Trans (A)", 2D) = "white" { }
 _Cutoff ("Alpha cutoff", Range(0.000000,1.000000)) = 0.500000
}
SubShader { 
 LOD 100
 Tags { "QUEUE"="AlphaTest" "IGNOREPROJECTOR"="true" "RenderType"="TransparentCutout" }


 // Stats for Vertex shader:
 //         gles: 5 math, 2 texture, 1 branch
 Pass {
  Tags { "LIGHTMODE"="Vertex" "QUEUE"="AlphaTest" "IGNOREPROJECTOR"="true" "RenderType"="TransparentCutout" }
  AlphaToMask On
  ColorMask RGB
  //////////////////////////////////
  //                              //
  //      Compiled programs       //
  //                              //
  //////////////////////////////////
//////////////////////////////////////////////////////
No keywords set in this variant.
-- Hardware tier variant: Tier 1
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  mediump vec4 color_8;
  color_8 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_9;
  tmpvar_9.w = 1.0;
  tmpvar_9.xyz = tmpvar_1;
  highp mat4 m_10;
  m_10 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_11;
  highp vec4 tmpvar_12;
  highp vec4 tmpvar_13;
  tmpvar_11.x = m_10[0].x;
  tmpvar_11.y = m_10[1].x;
  tmpvar_11.z = m_10[2].x;
  tmpvar_11.w = m_10[3].x;
  tmpvar_12.x = m_10[0].y;
  tmpvar_12.y = m_10[1].y;
  tmpvar_12.z = m_10[2].y;
  tmpvar_12.w = m_10[3].y;
  tmpvar_13.x = m_10[0].z;
  tmpvar_13.y = m_10[1].z;
  tmpvar_13.z = m_10[2].z;
  tmpvar_13.w = m_10[3].z;
  highp mat3 tmpvar_14;
  tmpvar_14[0] = tmpvar_11.xyz;
  tmpvar_14[1] = tmpvar_12.xyz;
  tmpvar_14[2] = tmpvar_13.xyz;
  highp vec3 tmpvar_15;
  tmpvar_15 = normalize((tmpvar_14 * _glesNormal));
  eyeNormal_7 = tmpvar_15;
  highp vec3 tmpvar_16;
  tmpvar_16 = normalize(((unity_MatrixV * unity_ObjectToWorld) * tmpvar_9).xyz);
  viewDir_6 = -(tmpvar_16);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    highp vec3 tmpvar_17;
    tmpvar_17 = unity_LightPosition[il_2].xyz;
    mediump vec3 dirToLight_18;
    dirToLight_18 = tmpvar_17;
    mediump vec3 specColor_19;
    specColor_19 = specColor_4;
    mediump float tmpvar_20;
    tmpvar_20 = max (dot (eyeNormal_7, dirToLight_18), 0.0);
    mediump vec3 tmpvar_21;
    tmpvar_21 = ((tmpvar_20 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_20 > 0.0)) {
      specColor_19 = (specColor_4 + ((0.5 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_18 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_19;
    lcolor_5 = (lcolor_5 + min ((tmpvar_21 * 0.5), vec3(1.0, 1.0, 1.0)));
  };
  color_8.xyz = lcolor_5;
  color_8.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_22;
  mediump vec4 tmpvar_23;
  tmpvar_23 = clamp (color_8, 0.0, 1.0);
  tmpvar_22 = tmpvar_23;
  lowp vec3 tmpvar_24;
  mediump vec3 tmpvar_25;
  tmpvar_25 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_24 = tmpvar_25;
  highp vec4 tmpvar_26;
  tmpvar_26.w = 1.0;
  tmpvar_26.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_22;
  xlv_COLOR1 = tmpvar_24;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_26));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 1
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 2
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  mediump vec4 color_8;
  color_8 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_9;
  tmpvar_9.w = 1.0;
  tmpvar_9.xyz = tmpvar_1;
  highp mat4 m_10;
  m_10 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_11;
  highp vec4 tmpvar_12;
  highp vec4 tmpvar_13;
  tmpvar_11.x = m_10[0].x;
  tmpvar_11.y = m_10[1].x;
  tmpvar_11.z = m_10[2].x;
  tmpvar_11.w = m_10[3].x;
  tmpvar_12.x = m_10[0].y;
  tmpvar_12.y = m_10[1].y;
  tmpvar_12.z = m_10[2].y;
  tmpvar_12.w = m_10[3].y;
  tmpvar_13.x = m_10[0].z;
  tmpvar_13.y = m_10[1].z;
  tmpvar_13.z = m_10[2].z;
  tmpvar_13.w = m_10[3].z;
  highp mat3 tmpvar_14;
  tmpvar_14[0] = tmpvar_11.xyz;
  tmpvar_14[1] = tmpvar_12.xyz;
  tmpvar_14[2] = tmpvar_13.xyz;
  highp vec3 tmpvar_15;
  tmpvar_15 = normalize((tmpvar_14 * _glesNormal));
  eyeNormal_7 = tmpvar_15;
  highp vec3 tmpvar_16;
  tmpvar_16 = normalize(((unity_MatrixV * unity_ObjectToWorld) * tmpvar_9).xyz);
  viewDir_6 = -(tmpvar_16);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    highp vec3 tmpvar_17;
    tmpvar_17 = unity_LightPosition[il_2].xyz;
    mediump vec3 dirToLight_18;
    dirToLight_18 = tmpvar_17;
    mediump vec3 specColor_19;
    specColor_19 = specColor_4;
    mediump float tmpvar_20;
    tmpvar_20 = max (dot (eyeNormal_7, dirToLight_18), 0.0);
    mediump vec3 tmpvar_21;
    tmpvar_21 = ((tmpvar_20 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_20 > 0.0)) {
      specColor_19 = (specColor_4 + ((0.5 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_18 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_19;
    lcolor_5 = (lcolor_5 + min ((tmpvar_21 * 0.5), vec3(1.0, 1.0, 1.0)));
  };
  color_8.xyz = lcolor_5;
  color_8.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_22;
  mediump vec4 tmpvar_23;
  tmpvar_23 = clamp (color_8, 0.0, 1.0);
  tmpvar_22 = tmpvar_23;
  lowp vec3 tmpvar_24;
  mediump vec3 tmpvar_25;
  tmpvar_25 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_24 = tmpvar_25;
  highp vec4 tmpvar_26;
  tmpvar_26.w = 1.0;
  tmpvar_26.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_22;
  xlv_COLOR1 = tmpvar_24;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_26));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 2
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 3
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  mediump vec4 color_8;
  color_8 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_9;
  tmpvar_9.w = 1.0;
  tmpvar_9.xyz = tmpvar_1;
  highp mat4 m_10;
  m_10 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_11;
  highp vec4 tmpvar_12;
  highp vec4 tmpvar_13;
  tmpvar_11.x = m_10[0].x;
  tmpvar_11.y = m_10[1].x;
  tmpvar_11.z = m_10[2].x;
  tmpvar_11.w = m_10[3].x;
  tmpvar_12.x = m_10[0].y;
  tmpvar_12.y = m_10[1].y;
  tmpvar_12.z = m_10[2].y;
  tmpvar_12.w = m_10[3].y;
  tmpvar_13.x = m_10[0].z;
  tmpvar_13.y = m_10[1].z;
  tmpvar_13.z = m_10[2].z;
  tmpvar_13.w = m_10[3].z;
  highp mat3 tmpvar_14;
  tmpvar_14[0] = tmpvar_11.xyz;
  tmpvar_14[1] = tmpvar_12.xyz;
  tmpvar_14[2] = tmpvar_13.xyz;
  highp vec3 tmpvar_15;
  tmpvar_15 = normalize((tmpvar_14 * _glesNormal));
  eyeNormal_7 = tmpvar_15;
  highp vec3 tmpvar_16;
  tmpvar_16 = normalize(((unity_MatrixV * unity_ObjectToWorld) * tmpvar_9).xyz);
  viewDir_6 = -(tmpvar_16);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    highp vec3 tmpvar_17;
    tmpvar_17 = unity_LightPosition[il_2].xyz;
    mediump vec3 dirToLight_18;
    dirToLight_18 = tmpvar_17;
    mediump vec3 specColor_19;
    specColor_19 = specColor_4;
    mediump float tmpvar_20;
    tmpvar_20 = max (dot (eyeNormal_7, dirToLight_18), 0.0);
    mediump vec3 tmpvar_21;
    tmpvar_21 = ((tmpvar_20 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_20 > 0.0)) {
      specColor_19 = (specColor_4 + ((0.5 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_18 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_19;
    lcolor_5 = (lcolor_5 + min ((tmpvar_21 * 0.5), vec3(1.0, 1.0, 1.0)));
  };
  color_8.xyz = lcolor_5;
  color_8.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_22;
  mediump vec4 tmpvar_23;
  tmpvar_23 = clamp (color_8, 0.0, 1.0);
  tmpvar_22 = tmpvar_23;
  lowp vec3 tmpvar_24;
  mediump vec3 tmpvar_25;
  tmpvar_25 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_24 = tmpvar_25;
  highp vec4 tmpvar_26;
  tmpvar_26.w = 1.0;
  tmpvar_26.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_22;
  xlv_COLOR1 = tmpvar_24;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_26));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 3
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 1
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (592 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 192
  Matrix4x4 unity_WorldToObject at 256
  Matrix4x4 unity_MatrixV at 336
  Matrix4x4 unity_MatrixInvV at 400
  Matrix4x4 unity_MatrixVP at 464
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 glstate_lightmodel_ambient at 320
  VectorHalf4 _Color at 528
  VectorHalf4 _SpecColor at 536
  VectorHalf4 _Emission at 544
  ScalarHalf _Shininess at 552
  VectorInt4 unity_VertexLightParams at 560
  Vector4 _MainTex_ST at 576
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    float u_xlat27;
    int u_xlati28;
    half u_xlat16_31;
    half u_xlat16_32;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat16_32 = dot(u_xlat1.xyz, Globals.unity_LightPosition[u_xlati28].xyz);
        u_xlat16_32 = max(u_xlat16_32, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_32) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb2 = half(0.0)<u_xlat16_32;
        if(u_xlatb2){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + Globals.unity_LightPosition[u_xlati28].xyz);
            u_xlat16_32 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_32 = rsqrt(u_xlat16_32);
            u_xlat16_8.xyz = half3(u_xlat16_32) * u_xlat16_8.xyz;
            u_xlat16_32 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_32 = max(u_xlat16_32, half(0.0));
            u_xlat16_32 = log2(u_xlat16_32);
            u_xlat16_32 = u_xlat16_31 * u_xlat16_32;
            u_xlat16_32 = exp2(u_xlat16_32);
            u_xlat16_32 = min(u_xlat16_32, half(1.0));
            u_xlat16_32 = u_xlat16_32 * half(0.5);
            u_xlat16_6.xyz = half3(u_xlat16_32) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = u_xlat16_7.xyz * half3(0.5, 0.5, 0.5);
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 1
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


-- Hardware tier variant: Tier 2
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (592 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 192
  Matrix4x4 unity_WorldToObject at 256
  Matrix4x4 unity_MatrixV at 336
  Matrix4x4 unity_MatrixInvV at 400
  Matrix4x4 unity_MatrixVP at 464
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 glstate_lightmodel_ambient at 320
  VectorHalf4 _Color at 528
  VectorHalf4 _SpecColor at 536
  VectorHalf4 _Emission at 544
  ScalarHalf _Shininess at 552
  VectorInt4 unity_VertexLightParams at 560
  Vector4 _MainTex_ST at 576
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    float u_xlat27;
    int u_xlati28;
    half u_xlat16_31;
    half u_xlat16_32;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat16_32 = dot(u_xlat1.xyz, Globals.unity_LightPosition[u_xlati28].xyz);
        u_xlat16_32 = max(u_xlat16_32, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_32) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb2 = half(0.0)<u_xlat16_32;
        if(u_xlatb2){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + Globals.unity_LightPosition[u_xlati28].xyz);
            u_xlat16_32 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_32 = rsqrt(u_xlat16_32);
            u_xlat16_8.xyz = half3(u_xlat16_32) * u_xlat16_8.xyz;
            u_xlat16_32 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_32 = max(u_xlat16_32, half(0.0));
            u_xlat16_32 = log2(u_xlat16_32);
            u_xlat16_32 = u_xlat16_31 * u_xlat16_32;
            u_xlat16_32 = exp2(u_xlat16_32);
            u_xlat16_32 = min(u_xlat16_32, half(1.0));
            u_xlat16_32 = u_xlat16_32 * half(0.5);
            u_xlat16_6.xyz = half3(u_xlat16_32) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = u_xlat16_7.xyz * half3(0.5, 0.5, 0.5);
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 2
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


-- Hardware tier variant: Tier 3
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (592 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 192
  Matrix4x4 unity_WorldToObject at 256
  Matrix4x4 unity_MatrixV at 336
  Matrix4x4 unity_MatrixInvV at 400
  Matrix4x4 unity_MatrixVP at 464
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 glstate_lightmodel_ambient at 320
  VectorHalf4 _Color at 528
  VectorHalf4 _SpecColor at 536
  VectorHalf4 _Emission at 544
  ScalarHalf _Shininess at 552
  VectorInt4 unity_VertexLightParams at 560
  Vector4 _MainTex_ST at 576
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    float u_xlat27;
    int u_xlati28;
    half u_xlat16_31;
    half u_xlat16_32;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat16_32 = dot(u_xlat1.xyz, Globals.unity_LightPosition[u_xlati28].xyz);
        u_xlat16_32 = max(u_xlat16_32, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_32) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb2 = half(0.0)<u_xlat16_32;
        if(u_xlatb2){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + Globals.unity_LightPosition[u_xlati28].xyz);
            u_xlat16_32 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_32 = rsqrt(u_xlat16_32);
            u_xlat16_8.xyz = half3(u_xlat16_32) * u_xlat16_8.xyz;
            u_xlat16_32 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_32 = max(u_xlat16_32, half(0.0));
            u_xlat16_32 = log2(u_xlat16_32);
            u_xlat16_32 = u_xlat16_31 * u_xlat16_32;
            u_xlat16_32 = exp2(u_xlat16_32);
            u_xlat16_32 = min(u_xlat16_32, half(1.0));
            u_xlat16_32 = u_xlat16_32 * half(0.5);
            u_xlat16_6.xyz = half3(u_xlat16_32) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = u_xlat16_7.xyz * half3(0.5, 0.5, 0.5);
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 3
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


//////////////////////////////////////////////////////
Keywords set in this variant: POINT 
-- Hardware tier variant: Tier 1
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform mediump vec4 unity_LightAtten[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  highp vec3 eyePos_8;
  mediump vec4 color_9;
  color_9 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_10;
  tmpvar_10.w = 1.0;
  tmpvar_10.xyz = tmpvar_1;
  highp vec3 tmpvar_11;
  tmpvar_11 = ((unity_MatrixV * unity_ObjectToWorld) * tmpvar_10).xyz;
  eyePos_8 = tmpvar_11;
  highp mat4 m_12;
  m_12 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_13;
  highp vec4 tmpvar_14;
  highp vec4 tmpvar_15;
  tmpvar_13.x = m_12[0].x;
  tmpvar_13.y = m_12[1].x;
  tmpvar_13.z = m_12[2].x;
  tmpvar_13.w = m_12[3].x;
  tmpvar_14.x = m_12[0].y;
  tmpvar_14.y = m_12[1].y;
  tmpvar_14.z = m_12[2].y;
  tmpvar_14.w = m_12[3].y;
  tmpvar_15.x = m_12[0].z;
  tmpvar_15.y = m_12[1].z;
  tmpvar_15.z = m_12[2].z;
  tmpvar_15.w = m_12[3].z;
  highp mat3 tmpvar_16;
  tmpvar_16[0] = tmpvar_13.xyz;
  tmpvar_16[1] = tmpvar_14.xyz;
  tmpvar_16[2] = tmpvar_15.xyz;
  highp vec3 tmpvar_17;
  tmpvar_17 = normalize((tmpvar_16 * _glesNormal));
  eyeNormal_7 = tmpvar_17;
  highp vec3 tmpvar_18;
  tmpvar_18 = normalize(tmpvar_11);
  viewDir_6 = -(tmpvar_18);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    mediump float att_19;
    highp vec3 dirToLight_20;
    dirToLight_20 = (unity_LightPosition[il_2].xyz - (eyePos_8 * unity_LightPosition[il_2].w));
    highp float tmpvar_21;
    tmpvar_21 = dot (dirToLight_20, dirToLight_20);
    att_19 = (1.0/((1.0 + (unity_LightAtten[il_2].z * tmpvar_21))));
    if (((unity_LightPosition[il_2].w != 0.0) && (tmpvar_21 > unity_LightAtten[il_2].w))) {
      att_19 = 0.0;
    };
    dirToLight_20 = (dirToLight_20 * inversesqrt(max (tmpvar_21, 1e-06)));
    att_19 = (att_19 * 0.5);
    mediump vec3 dirToLight_22;
    dirToLight_22 = dirToLight_20;
    mediump vec3 specColor_23;
    specColor_23 = specColor_4;
    mediump float tmpvar_24;
    tmpvar_24 = max (dot (eyeNormal_7, dirToLight_22), 0.0);
    mediump vec3 tmpvar_25;
    tmpvar_25 = ((tmpvar_24 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_24 > 0.0)) {
      specColor_23 = (specColor_4 + ((att_19 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_22 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_23;
    lcolor_5 = (lcolor_5 + min ((tmpvar_25 * att_19), vec3(1.0, 1.0, 1.0)));
  };
  color_9.xyz = lcolor_5;
  color_9.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_26;
  mediump vec4 tmpvar_27;
  tmpvar_27 = clamp (color_9, 0.0, 1.0);
  tmpvar_26 = tmpvar_27;
  lowp vec3 tmpvar_28;
  mediump vec3 tmpvar_29;
  tmpvar_29 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_28 = tmpvar_29;
  highp vec4 tmpvar_30;
  tmpvar_30.w = 1.0;
  tmpvar_30.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_26;
  xlv_COLOR1 = tmpvar_28;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_30));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 1
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 2
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform mediump vec4 unity_LightAtten[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  highp vec3 eyePos_8;
  mediump vec4 color_9;
  color_9 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_10;
  tmpvar_10.w = 1.0;
  tmpvar_10.xyz = tmpvar_1;
  highp vec3 tmpvar_11;
  tmpvar_11 = ((unity_MatrixV * unity_ObjectToWorld) * tmpvar_10).xyz;
  eyePos_8 = tmpvar_11;
  highp mat4 m_12;
  m_12 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_13;
  highp vec4 tmpvar_14;
  highp vec4 tmpvar_15;
  tmpvar_13.x = m_12[0].x;
  tmpvar_13.y = m_12[1].x;
  tmpvar_13.z = m_12[2].x;
  tmpvar_13.w = m_12[3].x;
  tmpvar_14.x = m_12[0].y;
  tmpvar_14.y = m_12[1].y;
  tmpvar_14.z = m_12[2].y;
  tmpvar_14.w = m_12[3].y;
  tmpvar_15.x = m_12[0].z;
  tmpvar_15.y = m_12[1].z;
  tmpvar_15.z = m_12[2].z;
  tmpvar_15.w = m_12[3].z;
  highp mat3 tmpvar_16;
  tmpvar_16[0] = tmpvar_13.xyz;
  tmpvar_16[1] = tmpvar_14.xyz;
  tmpvar_16[2] = tmpvar_15.xyz;
  highp vec3 tmpvar_17;
  tmpvar_17 = normalize((tmpvar_16 * _glesNormal));
  eyeNormal_7 = tmpvar_17;
  highp vec3 tmpvar_18;
  tmpvar_18 = normalize(tmpvar_11);
  viewDir_6 = -(tmpvar_18);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    mediump float att_19;
    highp vec3 dirToLight_20;
    dirToLight_20 = (unity_LightPosition[il_2].xyz - (eyePos_8 * unity_LightPosition[il_2].w));
    highp float tmpvar_21;
    tmpvar_21 = dot (dirToLight_20, dirToLight_20);
    att_19 = (1.0/((1.0 + (unity_LightAtten[il_2].z * tmpvar_21))));
    if (((unity_LightPosition[il_2].w != 0.0) && (tmpvar_21 > unity_LightAtten[il_2].w))) {
      att_19 = 0.0;
    };
    dirToLight_20 = (dirToLight_20 * inversesqrt(max (tmpvar_21, 1e-06)));
    att_19 = (att_19 * 0.5);
    mediump vec3 dirToLight_22;
    dirToLight_22 = dirToLight_20;
    mediump vec3 specColor_23;
    specColor_23 = specColor_4;
    mediump float tmpvar_24;
    tmpvar_24 = max (dot (eyeNormal_7, dirToLight_22), 0.0);
    mediump vec3 tmpvar_25;
    tmpvar_25 = ((tmpvar_24 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_24 > 0.0)) {
      specColor_23 = (specColor_4 + ((att_19 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_22 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_23;
    lcolor_5 = (lcolor_5 + min ((tmpvar_25 * att_19), vec3(1.0, 1.0, 1.0)));
  };
  color_9.xyz = lcolor_5;
  color_9.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_26;
  mediump vec4 tmpvar_27;
  tmpvar_27 = clamp (color_9, 0.0, 1.0);
  tmpvar_26 = tmpvar_27;
  lowp vec3 tmpvar_28;
  mediump vec3 tmpvar_29;
  tmpvar_29 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_28 = tmpvar_29;
  highp vec4 tmpvar_30;
  tmpvar_30.w = 1.0;
  tmpvar_30.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_26;
  xlv_COLOR1 = tmpvar_28;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_30));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 2
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 3
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform mediump vec4 unity_LightAtten[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  highp vec3 eyePos_8;
  mediump vec4 color_9;
  color_9 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_10;
  tmpvar_10.w = 1.0;
  tmpvar_10.xyz = tmpvar_1;
  highp vec3 tmpvar_11;
  tmpvar_11 = ((unity_MatrixV * unity_ObjectToWorld) * tmpvar_10).xyz;
  eyePos_8 = tmpvar_11;
  highp mat4 m_12;
  m_12 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_13;
  highp vec4 tmpvar_14;
  highp vec4 tmpvar_15;
  tmpvar_13.x = m_12[0].x;
  tmpvar_13.y = m_12[1].x;
  tmpvar_13.z = m_12[2].x;
  tmpvar_13.w = m_12[3].x;
  tmpvar_14.x = m_12[0].y;
  tmpvar_14.y = m_12[1].y;
  tmpvar_14.z = m_12[2].y;
  tmpvar_14.w = m_12[3].y;
  tmpvar_15.x = m_12[0].z;
  tmpvar_15.y = m_12[1].z;
  tmpvar_15.z = m_12[2].z;
  tmpvar_15.w = m_12[3].z;
  highp mat3 tmpvar_16;
  tmpvar_16[0] = tmpvar_13.xyz;
  tmpvar_16[1] = tmpvar_14.xyz;
  tmpvar_16[2] = tmpvar_15.xyz;
  highp vec3 tmpvar_17;
  tmpvar_17 = normalize((tmpvar_16 * _glesNormal));
  eyeNormal_7 = tmpvar_17;
  highp vec3 tmpvar_18;
  tmpvar_18 = normalize(tmpvar_11);
  viewDir_6 = -(tmpvar_18);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    mediump float att_19;
    highp vec3 dirToLight_20;
    dirToLight_20 = (unity_LightPosition[il_2].xyz - (eyePos_8 * unity_LightPosition[il_2].w));
    highp float tmpvar_21;
    tmpvar_21 = dot (dirToLight_20, dirToLight_20);
    att_19 = (1.0/((1.0 + (unity_LightAtten[il_2].z * tmpvar_21))));
    if (((unity_LightPosition[il_2].w != 0.0) && (tmpvar_21 > unity_LightAtten[il_2].w))) {
      att_19 = 0.0;
    };
    dirToLight_20 = (dirToLight_20 * inversesqrt(max (tmpvar_21, 1e-06)));
    att_19 = (att_19 * 0.5);
    mediump vec3 dirToLight_22;
    dirToLight_22 = dirToLight_20;
    mediump vec3 specColor_23;
    specColor_23 = specColor_4;
    mediump float tmpvar_24;
    tmpvar_24 = max (dot (eyeNormal_7, dirToLight_22), 0.0);
    mediump vec3 tmpvar_25;
    tmpvar_25 = ((tmpvar_24 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_24 > 0.0)) {
      specColor_23 = (specColor_4 + ((att_19 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_22 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_23;
    lcolor_5 = (lcolor_5 + min ((tmpvar_25 * att_19), vec3(1.0, 1.0, 1.0)));
  };
  color_9.xyz = lcolor_5;
  color_9.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_26;
  mediump vec4 tmpvar_27;
  tmpvar_27 = clamp (color_9, 0.0, 1.0);
  tmpvar_26 = tmpvar_27;
  lowp vec3 tmpvar_28;
  mediump vec3 tmpvar_29;
  tmpvar_29 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_28 = tmpvar_29;
  highp vec4 tmpvar_30;
  tmpvar_30.w = 1.0;
  tmpvar_30.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_26;
  xlv_COLOR1 = tmpvar_28;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_30));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 3
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 1
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (656 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 256
  Matrix4x4 unity_WorldToObject at 320
  Matrix4x4 unity_MatrixV at 400
  Matrix4x4 unity_MatrixInvV at 464
  Matrix4x4 unity_MatrixVP at 528
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 unity_LightAtten[8] at 192
  VectorHalf4 glstate_lightmodel_ambient at 384
  VectorHalf4 _Color at 592
  VectorHalf4 _SpecColor at 600
  VectorHalf4 _Emission at 608
  ScalarHalf _Shininess at 616
  VectorInt4 unity_VertexLightParams at 624
  Vector4 _MainTex_ST at 640
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    half4 unity_LightAtten[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    bool u_xlatb12;
    bool u_xlatb21;
    float u_xlat27;
    int u_xlati28;
    float u_xlat29;
    bool u_xlatb29;
    half u_xlat16_31;
    half u_xlat16_32;
    half u_xlat16_33;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat2.xyz = (-u_xlat0.xyz) * Globals.unity_LightPosition[u_xlati28].www + Globals.unity_LightPosition[u_xlati28].xyz;
        u_xlat29 = dot(u_xlat2.xyz, u_xlat2.xyz);
        u_xlat3.x = float(Globals.unity_LightAtten[u_xlati28].z) * u_xlat29 + 1.0;
        u_xlat3.x = float(1.0) / u_xlat3.x;
        u_xlatb12 = 0.0!=Globals.unity_LightPosition[u_xlati28].w;
        u_xlatb21 = float(Globals.unity_LightAtten[u_xlati28].w)<u_xlat29;
        u_xlatb12 = u_xlatb21 && u_xlatb12;
        u_xlat29 = max(u_xlat29, 9.99999997e-07);
        u_xlat29 = rsqrt(u_xlat29);
        u_xlat2.xyz = float3(u_xlat29) * u_xlat2.xyz;
        u_xlat29 = u_xlat3.x * 0.5;
        u_xlat16_32 = (u_xlatb12) ? half(0.0) : half(u_xlat29);
        u_xlat16_33 = dot(u_xlat1.xyz, u_xlat2.xyz);
        u_xlat16_33 = max(u_xlat16_33, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_33) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb29 = half(0.0)<u_xlat16_33;
        if(u_xlatb29){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + u_xlat2.xyz);
            u_xlat16_33 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_33 = rsqrt(u_xlat16_33);
            u_xlat16_8.xyz = half3(u_xlat16_33) * u_xlat16_8.xyz;
            u_xlat16_33 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_33 = max(u_xlat16_33, half(0.0));
            u_xlat16_33 = log2(u_xlat16_33);
            u_xlat16_33 = u_xlat16_31 * u_xlat16_33;
            u_xlat16_33 = exp2(u_xlat16_33);
            u_xlat16_33 = min(u_xlat16_33, half(1.0));
            u_xlat16_33 = u_xlat16_32 * u_xlat16_33;
            u_xlat16_6.xyz = half3(u_xlat16_33) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = half3(u_xlat16_32) * u_xlat16_7.xyz;
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 1
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


-- Hardware tier variant: Tier 2
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (656 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 256
  Matrix4x4 unity_WorldToObject at 320
  Matrix4x4 unity_MatrixV at 400
  Matrix4x4 unity_MatrixInvV at 464
  Matrix4x4 unity_MatrixVP at 528
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 unity_LightAtten[8] at 192
  VectorHalf4 glstate_lightmodel_ambient at 384
  VectorHalf4 _Color at 592
  VectorHalf4 _SpecColor at 600
  VectorHalf4 _Emission at 608
  ScalarHalf _Shininess at 616
  VectorInt4 unity_VertexLightParams at 624
  Vector4 _MainTex_ST at 640
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    half4 unity_LightAtten[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    bool u_xlatb12;
    bool u_xlatb21;
    float u_xlat27;
    int u_xlati28;
    float u_xlat29;
    bool u_xlatb29;
    half u_xlat16_31;
    half u_xlat16_32;
    half u_xlat16_33;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat2.xyz = (-u_xlat0.xyz) * Globals.unity_LightPosition[u_xlati28].www + Globals.unity_LightPosition[u_xlati28].xyz;
        u_xlat29 = dot(u_xlat2.xyz, u_xlat2.xyz);
        u_xlat3.x = float(Globals.unity_LightAtten[u_xlati28].z) * u_xlat29 + 1.0;
        u_xlat3.x = float(1.0) / u_xlat3.x;
        u_xlatb12 = 0.0!=Globals.unity_LightPosition[u_xlati28].w;
        u_xlatb21 = float(Globals.unity_LightAtten[u_xlati28].w)<u_xlat29;
        u_xlatb12 = u_xlatb21 && u_xlatb12;
        u_xlat29 = max(u_xlat29, 9.99999997e-07);
        u_xlat29 = rsqrt(u_xlat29);
        u_xlat2.xyz = float3(u_xlat29) * u_xlat2.xyz;
        u_xlat29 = u_xlat3.x * 0.5;
        u_xlat16_32 = (u_xlatb12) ? half(0.0) : half(u_xlat29);
        u_xlat16_33 = dot(u_xlat1.xyz, u_xlat2.xyz);
        u_xlat16_33 = max(u_xlat16_33, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_33) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb29 = half(0.0)<u_xlat16_33;
        if(u_xlatb29){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + u_xlat2.xyz);
            u_xlat16_33 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_33 = rsqrt(u_xlat16_33);
            u_xlat16_8.xyz = half3(u_xlat16_33) * u_xlat16_8.xyz;
            u_xlat16_33 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_33 = max(u_xlat16_33, half(0.0));
            u_xlat16_33 = log2(u_xlat16_33);
            u_xlat16_33 = u_xlat16_31 * u_xlat16_33;
            u_xlat16_33 = exp2(u_xlat16_33);
            u_xlat16_33 = min(u_xlat16_33, half(1.0));
            u_xlat16_33 = u_xlat16_32 * u_xlat16_33;
            u_xlat16_6.xyz = half3(u_xlat16_33) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = half3(u_xlat16_32) * u_xlat16_7.xyz;
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 2
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


-- Hardware tier variant: Tier 3
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (656 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 256
  Matrix4x4 unity_WorldToObject at 320
  Matrix4x4 unity_MatrixV at 400
  Matrix4x4 unity_MatrixInvV at 464
  Matrix4x4 unity_MatrixVP at 528
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 unity_LightAtten[8] at 192
  VectorHalf4 glstate_lightmodel_ambient at 384
  VectorHalf4 _Color at 592
  VectorHalf4 _SpecColor at 600
  VectorHalf4 _Emission at 608
  ScalarHalf _Shininess at 616
  VectorInt4 unity_VertexLightParams at 624
  Vector4 _MainTex_ST at 640
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    half4 unity_LightAtten[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    bool u_xlatb12;
    bool u_xlatb21;
    float u_xlat27;
    int u_xlati28;
    float u_xlat29;
    bool u_xlatb29;
    half u_xlat16_31;
    half u_xlat16_32;
    half u_xlat16_33;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat2.xyz = (-u_xlat0.xyz) * Globals.unity_LightPosition[u_xlati28].www + Globals.unity_LightPosition[u_xlati28].xyz;
        u_xlat29 = dot(u_xlat2.xyz, u_xlat2.xyz);
        u_xlat3.x = float(Globals.unity_LightAtten[u_xlati28].z) * u_xlat29 + 1.0;
        u_xlat3.x = float(1.0) / u_xlat3.x;
        u_xlatb12 = 0.0!=Globals.unity_LightPosition[u_xlati28].w;
        u_xlatb21 = float(Globals.unity_LightAtten[u_xlati28].w)<u_xlat29;
        u_xlatb12 = u_xlatb21 && u_xlatb12;
        u_xlat29 = max(u_xlat29, 9.99999997e-07);
        u_xlat29 = rsqrt(u_xlat29);
        u_xlat2.xyz = float3(u_xlat29) * u_xlat2.xyz;
        u_xlat29 = u_xlat3.x * 0.5;
        u_xlat16_32 = (u_xlatb12) ? half(0.0) : half(u_xlat29);
        u_xlat16_33 = dot(u_xlat1.xyz, u_xlat2.xyz);
        u_xlat16_33 = max(u_xlat16_33, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_33) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb29 = half(0.0)<u_xlat16_33;
        if(u_xlatb29){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + u_xlat2.xyz);
            u_xlat16_33 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_33 = rsqrt(u_xlat16_33);
            u_xlat16_8.xyz = half3(u_xlat16_33) * u_xlat16_8.xyz;
            u_xlat16_33 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_33 = max(u_xlat16_33, half(0.0));
            u_xlat16_33 = log2(u_xlat16_33);
            u_xlat16_33 = u_xlat16_31 * u_xlat16_33;
            u_xlat16_33 = exp2(u_xlat16_33);
            u_xlat16_33 = min(u_xlat16_33, half(1.0));
            u_xlat16_33 = u_xlat16_32 * u_xlat16_33;
            u_xlat16_6.xyz = half3(u_xlat16_33) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = half3(u_xlat16_32) * u_xlat16_7.xyz;
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 3
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


-- Hardware tier variant: Tier 1
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform mediump vec4 unity_LightAtten[8];
uniform highp vec4 unity_SpotDirection[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  highp vec3 eyePos_8;
  mediump vec4 color_9;
  color_9 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_10;
  tmpvar_10.w = 1.0;
  tmpvar_10.xyz = tmpvar_1;
  highp vec3 tmpvar_11;
  tmpvar_11 = ((unity_MatrixV * unity_ObjectToWorld) * tmpvar_10).xyz;
  eyePos_8 = tmpvar_11;
  highp mat4 m_12;
  m_12 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_13;
  highp vec4 tmpvar_14;
  highp vec4 tmpvar_15;
  tmpvar_13.x = m_12[0].x;
  tmpvar_13.y = m_12[1].x;
  tmpvar_13.z = m_12[2].x;
  tmpvar_13.w = m_12[3].x;
  tmpvar_14.x = m_12[0].y;
  tmpvar_14.y = m_12[1].y;
  tmpvar_14.z = m_12[2].y;
  tmpvar_14.w = m_12[3].y;
  tmpvar_15.x = m_12[0].z;
  tmpvar_15.y = m_12[1].z;
  tmpvar_15.z = m_12[2].z;
  tmpvar_15.w = m_12[3].z;
  highp mat3 tmpvar_16;
  tmpvar_16[0] = tmpvar_13.xyz;
  tmpvar_16[1] = tmpvar_14.xyz;
  tmpvar_16[2] = tmpvar_15.xyz;
  highp vec3 tmpvar_17;
  tmpvar_17 = normalize((tmpvar_16 * _glesNormal));
  eyeNormal_7 = tmpvar_17;
  highp vec3 tmpvar_18;
  tmpvar_18 = normalize(tmpvar_11);
  viewDir_6 = -(tmpvar_18);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    mediump float rho_19;
    mediump float att_20;
    highp vec3 dirToLight_21;
    dirToLight_21 = (unity_LightPosition[il_2].xyz - (eyePos_8 * unity_LightPosition[il_2].w));
    highp float tmpvar_22;
    tmpvar_22 = dot (dirToLight_21, dirToLight_21);
    att_20 = (1.0/((1.0 + (unity_LightAtten[il_2].z * tmpvar_22))));
    if (((unity_LightPosition[il_2].w != 0.0) && (tmpvar_22 > unity_LightAtten[il_2].w))) {
      att_20 = 0.0;
    };
    dirToLight_21 = (dirToLight_21 * inversesqrt(max (tmpvar_22, 1e-06)));
    highp float tmpvar_23;
    tmpvar_23 = max (dot (dirToLight_21, unity_SpotDirection[il_2].xyz), 0.0);
    rho_19 = tmpvar_23;
    att_20 = (att_20 * clamp ((
      (rho_19 - unity_LightAtten[il_2].x)
     * unity_LightAtten[il_2].y), 0.0, 1.0));
    att_20 = (att_20 * 0.5);
    mediump vec3 dirToLight_24;
    dirToLight_24 = dirToLight_21;
    mediump vec3 specColor_25;
    specColor_25 = specColor_4;
    mediump float tmpvar_26;
    tmpvar_26 = max (dot (eyeNormal_7, dirToLight_24), 0.0);
    mediump vec3 tmpvar_27;
    tmpvar_27 = ((tmpvar_26 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_26 > 0.0)) {
      specColor_25 = (specColor_4 + ((att_20 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_24 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_25;
    lcolor_5 = (lcolor_5 + min ((tmpvar_27 * att_20), vec3(1.0, 1.0, 1.0)));
  };
  color_9.xyz = lcolor_5;
  color_9.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_28;
  mediump vec4 tmpvar_29;
  tmpvar_29 = clamp (color_9, 0.0, 1.0);
  tmpvar_28 = tmpvar_29;
  lowp vec3 tmpvar_30;
  mediump vec3 tmpvar_31;
  tmpvar_31 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_30 = tmpvar_31;
  highp vec4 tmpvar_32;
  tmpvar_32.w = 1.0;
  tmpvar_32.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_28;
  xlv_COLOR1 = tmpvar_30;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_32));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 1
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 2
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform mediump vec4 unity_LightAtten[8];
uniform highp vec4 unity_SpotDirection[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  highp vec3 eyePos_8;
  mediump vec4 color_9;
  color_9 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_10;
  tmpvar_10.w = 1.0;
  tmpvar_10.xyz = tmpvar_1;
  highp vec3 tmpvar_11;
  tmpvar_11 = ((unity_MatrixV * unity_ObjectToWorld) * tmpvar_10).xyz;
  eyePos_8 = tmpvar_11;
  highp mat4 m_12;
  m_12 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_13;
  highp vec4 tmpvar_14;
  highp vec4 tmpvar_15;
  tmpvar_13.x = m_12[0].x;
  tmpvar_13.y = m_12[1].x;
  tmpvar_13.z = m_12[2].x;
  tmpvar_13.w = m_12[3].x;
  tmpvar_14.x = m_12[0].y;
  tmpvar_14.y = m_12[1].y;
  tmpvar_14.z = m_12[2].y;
  tmpvar_14.w = m_12[3].y;
  tmpvar_15.x = m_12[0].z;
  tmpvar_15.y = m_12[1].z;
  tmpvar_15.z = m_12[2].z;
  tmpvar_15.w = m_12[3].z;
  highp mat3 tmpvar_16;
  tmpvar_16[0] = tmpvar_13.xyz;
  tmpvar_16[1] = tmpvar_14.xyz;
  tmpvar_16[2] = tmpvar_15.xyz;
  highp vec3 tmpvar_17;
  tmpvar_17 = normalize((tmpvar_16 * _glesNormal));
  eyeNormal_7 = tmpvar_17;
  highp vec3 tmpvar_18;
  tmpvar_18 = normalize(tmpvar_11);
  viewDir_6 = -(tmpvar_18);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    mediump float rho_19;
    mediump float att_20;
    highp vec3 dirToLight_21;
    dirToLight_21 = (unity_LightPosition[il_2].xyz - (eyePos_8 * unity_LightPosition[il_2].w));
    highp float tmpvar_22;
    tmpvar_22 = dot (dirToLight_21, dirToLight_21);
    att_20 = (1.0/((1.0 + (unity_LightAtten[il_2].z * tmpvar_22))));
    if (((unity_LightPosition[il_2].w != 0.0) && (tmpvar_22 > unity_LightAtten[il_2].w))) {
      att_20 = 0.0;
    };
    dirToLight_21 = (dirToLight_21 * inversesqrt(max (tmpvar_22, 1e-06)));
    highp float tmpvar_23;
    tmpvar_23 = max (dot (dirToLight_21, unity_SpotDirection[il_2].xyz), 0.0);
    rho_19 = tmpvar_23;
    att_20 = (att_20 * clamp ((
      (rho_19 - unity_LightAtten[il_2].x)
     * unity_LightAtten[il_2].y), 0.0, 1.0));
    att_20 = (att_20 * 0.5);
    mediump vec3 dirToLight_24;
    dirToLight_24 = dirToLight_21;
    mediump vec3 specColor_25;
    specColor_25 = specColor_4;
    mediump float tmpvar_26;
    tmpvar_26 = max (dot (eyeNormal_7, dirToLight_24), 0.0);
    mediump vec3 tmpvar_27;
    tmpvar_27 = ((tmpvar_26 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_26 > 0.0)) {
      specColor_25 = (specColor_4 + ((att_20 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_24 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_25;
    lcolor_5 = (lcolor_5 + min ((tmpvar_27 * att_20), vec3(1.0, 1.0, 1.0)));
  };
  color_9.xyz = lcolor_5;
  color_9.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_28;
  mediump vec4 tmpvar_29;
  tmpvar_29 = clamp (color_9, 0.0, 1.0);
  tmpvar_28 = tmpvar_29;
  lowp vec3 tmpvar_30;
  mediump vec3 tmpvar_31;
  tmpvar_31 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_30 = tmpvar_31;
  highp vec4 tmpvar_32;
  tmpvar_32.w = 1.0;
  tmpvar_32.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_28;
  xlv_COLOR1 = tmpvar_30;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_32));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 2
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 3
-- Vertex shader for "gles":
// Stats: 5 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform mediump vec4 unity_LightColor[8];
uniform highp vec4 unity_LightPosition[8];
uniform mediump vec4 unity_LightAtten[8];
uniform highp vec4 unity_SpotDirection[8];
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform lowp vec4 glstate_lightmodel_ambient;
uniform highp mat4 unity_MatrixV;
uniform highp mat4 unity_MatrixInvV;
uniform highp mat4 unity_MatrixVP;
uniform mediump vec4 _Color;
uniform mediump vec4 _SpecColor;
uniform mediump vec4 _Emission;
uniform mediump float _Shininess;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  highp vec3 tmpvar_1;
  tmpvar_1 = _glesVertex.xyz;
  mediump float shininess_3;
  mediump vec3 specColor_4;
  mediump vec3 lcolor_5;
  mediump vec3 viewDir_6;
  mediump vec3 eyeNormal_7;
  highp vec3 eyePos_8;
  mediump vec4 color_9;
  color_9 = vec4(0.0, 0.0, 0.0, 1.1);
  highp vec4 tmpvar_10;
  tmpvar_10.w = 1.0;
  tmpvar_10.xyz = tmpvar_1;
  highp vec3 tmpvar_11;
  tmpvar_11 = ((unity_MatrixV * unity_ObjectToWorld) * tmpvar_10).xyz;
  eyePos_8 = tmpvar_11;
  highp mat4 m_12;
  m_12 = (unity_WorldToObject * unity_MatrixInvV);
  highp vec4 tmpvar_13;
  highp vec4 tmpvar_14;
  highp vec4 tmpvar_15;
  tmpvar_13.x = m_12[0].x;
  tmpvar_13.y = m_12[1].x;
  tmpvar_13.z = m_12[2].x;
  tmpvar_13.w = m_12[3].x;
  tmpvar_14.x = m_12[0].y;
  tmpvar_14.y = m_12[1].y;
  tmpvar_14.z = m_12[2].y;
  tmpvar_14.w = m_12[3].y;
  tmpvar_15.x = m_12[0].z;
  tmpvar_15.y = m_12[1].z;
  tmpvar_15.z = m_12[2].z;
  tmpvar_15.w = m_12[3].z;
  highp mat3 tmpvar_16;
  tmpvar_16[0] = tmpvar_13.xyz;
  tmpvar_16[1] = tmpvar_14.xyz;
  tmpvar_16[2] = tmpvar_15.xyz;
  highp vec3 tmpvar_17;
  tmpvar_17 = normalize((tmpvar_16 * _glesNormal));
  eyeNormal_7 = tmpvar_17;
  highp vec3 tmpvar_18;
  tmpvar_18 = normalize(tmpvar_11);
  viewDir_6 = -(tmpvar_18);
  lcolor_5 = (_Emission.xyz + (_Color.xyz * glstate_lightmodel_ambient.xyz));
  specColor_4 = vec3(0.0, 0.0, 0.0);
  shininess_3 = (_Shininess * 128.0);
  for (highp int il_2 = 0; il_2 < 8; il_2++) {
    mediump float rho_19;
    mediump float att_20;
    highp vec3 dirToLight_21;
    dirToLight_21 = (unity_LightPosition[il_2].xyz - (eyePos_8 * unity_LightPosition[il_2].w));
    highp float tmpvar_22;
    tmpvar_22 = dot (dirToLight_21, dirToLight_21);
    att_20 = (1.0/((1.0 + (unity_LightAtten[il_2].z * tmpvar_22))));
    if (((unity_LightPosition[il_2].w != 0.0) && (tmpvar_22 > unity_LightAtten[il_2].w))) {
      att_20 = 0.0;
    };
    dirToLight_21 = (dirToLight_21 * inversesqrt(max (tmpvar_22, 1e-06)));
    highp float tmpvar_23;
    tmpvar_23 = max (dot (dirToLight_21, unity_SpotDirection[il_2].xyz), 0.0);
    rho_19 = tmpvar_23;
    att_20 = (att_20 * clamp ((
      (rho_19 - unity_LightAtten[il_2].x)
     * unity_LightAtten[il_2].y), 0.0, 1.0));
    att_20 = (att_20 * 0.5);
    mediump vec3 dirToLight_24;
    dirToLight_24 = dirToLight_21;
    mediump vec3 specColor_25;
    specColor_25 = specColor_4;
    mediump float tmpvar_26;
    tmpvar_26 = max (dot (eyeNormal_7, dirToLight_24), 0.0);
    mediump vec3 tmpvar_27;
    tmpvar_27 = ((tmpvar_26 * _Color.xyz) * unity_LightColor[il_2].xyz);
    if ((tmpvar_26 > 0.0)) {
      specColor_25 = (specColor_4 + ((att_20 * 
        clamp (pow (max (dot (eyeNormal_7, 
          normalize((dirToLight_24 + viewDir_6))
        ), 0.0), shininess_3), 0.0, 1.0)
      ) * unity_LightColor[il_2].xyz));
    };
    specColor_4 = specColor_25;
    lcolor_5 = (lcolor_5 + min ((tmpvar_27 * att_20), vec3(1.0, 1.0, 1.0)));
  };
  color_9.xyz = lcolor_5;
  color_9.w = _Color.w;
  specColor_4 = (specColor_4 * _SpecColor.xyz);
  lowp vec4 tmpvar_28;
  mediump vec4 tmpvar_29;
  tmpvar_29 = clamp (color_9, 0.0, 1.0);
  tmpvar_28 = tmpvar_29;
  lowp vec3 tmpvar_30;
  mediump vec3 tmpvar_31;
  tmpvar_31 = clamp (specColor_4, 0.0, 1.0);
  tmpvar_30 = tmpvar_31;
  highp vec4 tmpvar_32;
  tmpvar_32.w = 1.0;
  tmpvar_32.xyz = tmpvar_1;
  xlv_COLOR0 = tmpvar_28;
  xlv_COLOR1 = tmpvar_30;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_32));
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying lowp vec3 xlv_COLOR1;
varying highp vec2 xlv_TEXCOORD0;
void main ()
{
  lowp vec4 col_1;
  lowp vec4 tmpvar_2;
  tmpvar_2 = texture2D (_MainTex, xlv_TEXCOORD0);
  col_1.xyz = (tmpvar_2 * xlv_COLOR0).xyz;
  col_1.xyz = (col_1 * 2.0).xyz;
  col_1.w = (tmpvar_2.w * xlv_COLOR0.w);
  if ((col_1.w <= _Cutoff)) {
    discard;
  };
  col_1.xyz = (col_1.xyz + xlv_COLOR1);
  gl_FragData[0] = col_1;
}


#endif


-- Hardware tier variant: Tier 3
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 1
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (784 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 384
  Matrix4x4 unity_WorldToObject at 448
  Matrix4x4 unity_MatrixV at 528
  Matrix4x4 unity_MatrixInvV at 592
  Matrix4x4 unity_MatrixVP at 656
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 unity_LightAtten[8] at 192
  Vector4 unity_SpotDirection[8] at 256
  VectorHalf4 glstate_lightmodel_ambient at 512
  VectorHalf4 _Color at 720
  VectorHalf4 _SpecColor at 728
  VectorHalf4 _Emission at 736
  ScalarHalf _Shininess at 744
  VectorInt4 unity_VertexLightParams at 752
  Vector4 _MainTex_ST at 768
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    half4 unity_LightAtten[8];
    float4 unity_SpotDirection[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    bool u_xlatb12;
    bool u_xlatb21;
    float u_xlat27;
    int u_xlati28;
    float u_xlat29;
    bool u_xlatb29;
    half u_xlat16_31;
    half u_xlat16_32;
    half u_xlat16_33;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat2.xyz = (-u_xlat0.xyz) * Globals.unity_LightPosition[u_xlati28].www + Globals.unity_LightPosition[u_xlati28].xyz;
        u_xlat29 = dot(u_xlat2.xyz, u_xlat2.xyz);
        u_xlat3.x = float(Globals.unity_LightAtten[u_xlati28].z) * u_xlat29 + 1.0;
        u_xlat3.x = float(1.0) / u_xlat3.x;
        u_xlatb12 = 0.0!=Globals.unity_LightPosition[u_xlati28].w;
        u_xlatb21 = float(Globals.unity_LightAtten[u_xlati28].w)<u_xlat29;
        u_xlatb12 = u_xlatb21 && u_xlatb12;
        u_xlat16_32 = (u_xlatb12) ? half(0.0) : half(u_xlat3.x);
        u_xlat29 = max(u_xlat29, 9.99999997e-07);
        u_xlat29 = rsqrt(u_xlat29);
        u_xlat2.xyz = float3(u_xlat29) * u_xlat2.xyz;
        u_xlat29 = dot(u_xlat2.xyz, Globals.unity_SpotDirection[u_xlati28].xyz);
        u_xlat29 = max(u_xlat29, 0.0);
        u_xlat16_33 = half(u_xlat29 + (-float(Globals.unity_LightAtten[u_xlati28].x)));
        u_xlat16_33 = u_xlat16_33 * Globals.unity_LightAtten[u_xlati28].y;
        u_xlat16_33 = clamp(u_xlat16_33, 0.0h, 1.0h);
        u_xlat16_32 = u_xlat16_32 * u_xlat16_33;
        u_xlat16_32 = u_xlat16_32 * half(0.5);
        u_xlat16_33 = dot(u_xlat1.xyz, u_xlat2.xyz);
        u_xlat16_33 = max(u_xlat16_33, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_33) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb29 = half(0.0)<u_xlat16_33;
        if(u_xlatb29){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + u_xlat2.xyz);
            u_xlat16_33 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_33 = rsqrt(u_xlat16_33);
            u_xlat16_8.xyz = half3(u_xlat16_33) * u_xlat16_8.xyz;
            u_xlat16_33 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_33 = max(u_xlat16_33, half(0.0));
            u_xlat16_33 = log2(u_xlat16_33);
            u_xlat16_33 = u_xlat16_31 * u_xlat16_33;
            u_xlat16_33 = exp2(u_xlat16_33);
            u_xlat16_33 = min(u_xlat16_33, half(1.0));
            u_xlat16_33 = u_xlat16_32 * u_xlat16_33;
            u_xlat16_6.xyz = half3(u_xlat16_33) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = half3(u_xlat16_32) * u_xlat16_7.xyz;
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 1
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


-- Hardware tier variant: Tier 2
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (784 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 384
  Matrix4x4 unity_WorldToObject at 448
  Matrix4x4 unity_MatrixV at 528
  Matrix4x4 unity_MatrixInvV at 592
  Matrix4x4 unity_MatrixVP at 656
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 unity_LightAtten[8] at 192
  Vector4 unity_SpotDirection[8] at 256
  VectorHalf4 glstate_lightmodel_ambient at 512
  VectorHalf4 _Color at 720
  VectorHalf4 _SpecColor at 728
  VectorHalf4 _Emission at 736
  ScalarHalf _Shininess at 744
  VectorInt4 unity_VertexLightParams at 752
  Vector4 _MainTex_ST at 768
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    half4 unity_LightAtten[8];
    float4 unity_SpotDirection[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    bool u_xlatb12;
    bool u_xlatb21;
    float u_xlat27;
    int u_xlati28;
    float u_xlat29;
    bool u_xlatb29;
    half u_xlat16_31;
    half u_xlat16_32;
    half u_xlat16_33;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat2.xyz = (-u_xlat0.xyz) * Globals.unity_LightPosition[u_xlati28].www + Globals.unity_LightPosition[u_xlati28].xyz;
        u_xlat29 = dot(u_xlat2.xyz, u_xlat2.xyz);
        u_xlat3.x = float(Globals.unity_LightAtten[u_xlati28].z) * u_xlat29 + 1.0;
        u_xlat3.x = float(1.0) / u_xlat3.x;
        u_xlatb12 = 0.0!=Globals.unity_LightPosition[u_xlati28].w;
        u_xlatb21 = float(Globals.unity_LightAtten[u_xlati28].w)<u_xlat29;
        u_xlatb12 = u_xlatb21 && u_xlatb12;
        u_xlat16_32 = (u_xlatb12) ? half(0.0) : half(u_xlat3.x);
        u_xlat29 = max(u_xlat29, 9.99999997e-07);
        u_xlat29 = rsqrt(u_xlat29);
        u_xlat2.xyz = float3(u_xlat29) * u_xlat2.xyz;
        u_xlat29 = dot(u_xlat2.xyz, Globals.unity_SpotDirection[u_xlati28].xyz);
        u_xlat29 = max(u_xlat29, 0.0);
        u_xlat16_33 = half(u_xlat29 + (-float(Globals.unity_LightAtten[u_xlati28].x)));
        u_xlat16_33 = u_xlat16_33 * Globals.unity_LightAtten[u_xlati28].y;
        u_xlat16_33 = clamp(u_xlat16_33, 0.0h, 1.0h);
        u_xlat16_32 = u_xlat16_32 * u_xlat16_33;
        u_xlat16_32 = u_xlat16_32 * half(0.5);
        u_xlat16_33 = dot(u_xlat1.xyz, u_xlat2.xyz);
        u_xlat16_33 = max(u_xlat16_33, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_33) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb29 = half(0.0)<u_xlat16_33;
        if(u_xlatb29){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + u_xlat2.xyz);
            u_xlat16_33 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_33 = rsqrt(u_xlat16_33);
            u_xlat16_8.xyz = half3(u_xlat16_33) * u_xlat16_8.xyz;
            u_xlat16_33 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_33 = max(u_xlat16_33, half(0.0));
            u_xlat16_33 = log2(u_xlat16_33);
            u_xlat16_33 = u_xlat16_31 * u_xlat16_33;
            u_xlat16_33 = exp2(u_xlat16_33);
            u_xlat16_33 = min(u_xlat16_33, half(1.0));
            u_xlat16_33 = u_xlat16_32 * u_xlat16_33;
            u_xlat16_6.xyz = half3(u_xlat16_33) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = half3(u_xlat16_32) * u_xlat16_7.xyz;
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 2
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


-- Hardware tier variant: Tier 3
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (784 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 384
  Matrix4x4 unity_WorldToObject at 448
  Matrix4x4 unity_MatrixV at 528
  Matrix4x4 unity_MatrixInvV at 592
  Matrix4x4 unity_MatrixVP at 656
  VectorHalf4 unity_LightColor[8] at 0
  Vector4 unity_LightPosition[8] at 64
  VectorHalf4 unity_LightAtten[8] at 192
  Vector4 unity_SpotDirection[8] at 256
  VectorHalf4 glstate_lightmodel_ambient at 512
  VectorHalf4 _Color at 720
  VectorHalf4 _SpecColor at 728
  VectorHalf4 _Emission at 736
  ScalarHalf _Shininess at 744
  VectorInt4 unity_VertexLightParams at 752
  Vector4 _MainTex_ST at 768
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 unity_LightColor[8];
    float4 unity_LightPosition[8];
    half4 unity_LightAtten[8];
    float4 unity_SpotDirection[8];
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    half4 glstate_lightmodel_ambient;
    float4 hlslcc_mtx4x4unity_MatrixV[4];
    float4 hlslcc_mtx4x4unity_MatrixInvV[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    half4 _Color;
    half4 _SpecColor;
    half4 _Emission;
    half _Shininess;
    int4 unity_VertexLightParams;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float3 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    half3 COLOR1 [[ user(COLOR1) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float3 u_xlat2;
    bool u_xlatb2;
    float3 u_xlat3;
    half3 u_xlat16_4;
    half3 u_xlat16_5;
    half3 u_xlat16_6;
    half3 u_xlat16_7;
    half3 u_xlat16_8;
    bool u_xlatb12;
    bool u_xlatb21;
    float u_xlat27;
    int u_xlati28;
    float u_xlat29;
    bool u_xlatb29;
    half u_xlat16_31;
    half u_xlat16_32;
    half u_xlat16_33;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].www + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].yyy * Globals.hlslcc_mtx4x4unity_MatrixV[1].xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[0].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[2].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_MatrixV[3].xyz * Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].www + u_xlat3.xyz;
    u_xlat1.xyz = u_xlat1.xyz * input.POSITION0.yyy;
    u_xlat0.xyz = u_xlat0.xyz * input.POSITION0.xxx + u_xlat1.xyz;
    u_xlat0.xyz = u_xlat2.xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = u_xlat3.xyz + u_xlat0.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].yyy;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].xxx + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].zzz + u_xlat1.xyz;
    u_xlat1.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[0].www + u_xlat1.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].yyy;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].xxx + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].zzz + u_xlat2.xyz;
    u_xlat2.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[1].www + u_xlat2.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].yyy;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].xxx + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].zzz + u_xlat3.xyz;
    u_xlat3.xyz = Globals.hlslcc_mtx4x4unity_WorldToObject[3].xyz * Globals.hlslcc_mtx4x4unity_MatrixInvV[2].www + u_xlat3.xyz;
    u_xlat1.x = dot(u_xlat1.xyz, input.NORMAL0.xyz);
    u_xlat1.y = dot(u_xlat2.xyz, input.NORMAL0.xyz);
    u_xlat1.z = dot(u_xlat3.xyz, input.NORMAL0.xyz);
    u_xlat27 = dot(u_xlat1.xyz, u_xlat1.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat1.xyz = float3(u_xlat27) * u_xlat1.xyz;
    u_xlat27 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat27 = rsqrt(u_xlat27);
    u_xlat16_4.xyz = Globals._Color.xyz * Globals.glstate_lightmodel_ambient.xyz + Globals._Emission.xyz;
    u_xlat16_31 = Globals._Shininess * half(128.0);
    u_xlat16_5.xyz = u_xlat16_4.xyz;
    u_xlat16_6.x = half(0.0);
    u_xlat16_6.y = half(0.0);
    u_xlat16_6.z = half(0.0);
    u_xlati28 = 0x0;
    while(true){
        u_xlatb2 = u_xlati28>=Globals.unity_VertexLightParams.x;
        if(u_xlatb2){break;}
        u_xlat2.xyz = (-u_xlat0.xyz) * Globals.unity_LightPosition[u_xlati28].www + Globals.unity_LightPosition[u_xlati28].xyz;
        u_xlat29 = dot(u_xlat2.xyz, u_xlat2.xyz);
        u_xlat3.x = float(Globals.unity_LightAtten[u_xlati28].z) * u_xlat29 + 1.0;
        u_xlat3.x = float(1.0) / u_xlat3.x;
        u_xlatb12 = 0.0!=Globals.unity_LightPosition[u_xlati28].w;
        u_xlatb21 = float(Globals.unity_LightAtten[u_xlati28].w)<u_xlat29;
        u_xlatb12 = u_xlatb21 && u_xlatb12;
        u_xlat16_32 = (u_xlatb12) ? half(0.0) : half(u_xlat3.x);
        u_xlat29 = max(u_xlat29, 9.99999997e-07);
        u_xlat29 = rsqrt(u_xlat29);
        u_xlat2.xyz = float3(u_xlat29) * u_xlat2.xyz;
        u_xlat29 = dot(u_xlat2.xyz, Globals.unity_SpotDirection[u_xlati28].xyz);
        u_xlat29 = max(u_xlat29, 0.0);
        u_xlat16_33 = half(u_xlat29 + (-float(Globals.unity_LightAtten[u_xlati28].x)));
        u_xlat16_33 = u_xlat16_33 * Globals.unity_LightAtten[u_xlati28].y;
        u_xlat16_33 = clamp(u_xlat16_33, 0.0h, 1.0h);
        u_xlat16_32 = u_xlat16_32 * u_xlat16_33;
        u_xlat16_32 = u_xlat16_32 * half(0.5);
        u_xlat16_33 = dot(u_xlat1.xyz, u_xlat2.xyz);
        u_xlat16_33 = max(u_xlat16_33, half(0.0));
        u_xlat16_7.xyz = half3(u_xlat16_33) * Globals._Color.xyz;
        u_xlat16_7.xyz = u_xlat16_7.xyz * Globals.unity_LightColor[u_xlati28].xyz;
        u_xlatb29 = half(0.0)<u_xlat16_33;
        if(u_xlatb29){
            u_xlat16_8.xyz = half3((-u_xlat0.xyz) * float3(u_xlat27) + u_xlat2.xyz);
            u_xlat16_33 = dot(u_xlat16_8.xyz, u_xlat16_8.xyz);
            u_xlat16_33 = rsqrt(u_xlat16_33);
            u_xlat16_8.xyz = half3(u_xlat16_33) * u_xlat16_8.xyz;
            u_xlat16_33 = dot(u_xlat1.xyz, float3(u_xlat16_8.xyz));
            u_xlat16_33 = max(u_xlat16_33, half(0.0));
            u_xlat16_33 = log2(u_xlat16_33);
            u_xlat16_33 = u_xlat16_31 * u_xlat16_33;
            u_xlat16_33 = exp2(u_xlat16_33);
            u_xlat16_33 = min(u_xlat16_33, half(1.0));
            u_xlat16_33 = u_xlat16_32 * u_xlat16_33;
            u_xlat16_6.xyz = half3(u_xlat16_33) * Globals.unity_LightColor[u_xlati28].xyz + u_xlat16_6.xyz;
        }
        u_xlat16_7.xyz = half3(u_xlat16_32) * u_xlat16_7.xyz;
        u_xlat16_7.xyz = min(u_xlat16_7.xyz, half3(1.0, 1.0, 1.0));
        u_xlat16_5.xyz = u_xlat16_5.xyz + u_xlat16_7.xyz;
        u_xlati28 = u_xlati28 + 0x1;
    }
    output.COLOR1.xyz = u_xlat16_6.xyz * Globals._SpecColor.xyz;
    output.COLOR1.xyz = clamp(output.COLOR1.xyz, 0.0h, 1.0h);
    output.COLOR0.xyz = u_xlat16_5.xyz;
    output.COLOR0.xyz = clamp(output.COLOR0.xyz, 0.0h, 1.0h);
    output.COLOR0.w = Globals._Color.w;
    output.COLOR0.w = clamp(output.COLOR0.w, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 3
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (2 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    half3 COLOR1 [[ user(COLOR1) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    bool u_xlatb1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD0.xy);
    u_xlat16_0 = u_xlat16_0 * input.COLOR0;
    u_xlatb1 = Globals._Cutoff>=u_xlat16_0.w;
    if((int(u_xlatb1) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0.xyz = u_xlat16_0.xyz * half3(2.0, 2.0, 2.0) + input.COLOR1.xyz;
    output.SV_Target0.w = u_xlat16_0.w;
    return output;
}


 }


 // Stats for Vertex shader:
 //         gles: 5 math, 3 texture, 1 branch
 Pass {
  Tags { "LIGHTMODE"="VertexLM" "QUEUE"="AlphaTest" "IGNOREPROJECTOR"="true" "RenderType"="TransparentCutout" }
  AlphaToMask On
  ColorMask RGB
  //////////////////////////////////
  //                              //
  //      Compiled programs       //
  //                              //
  //////////////////////////////////
//////////////////////////////////////////////////////
No keywords set in this variant.
-- Hardware tier variant: Tier 1
-- Vertex shader for "gles":
// Stats: 5 math, 3 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesColor;
attribute vec4 _glesMultiTexCoord0;
attribute vec4 _glesMultiTexCoord1;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 unity_LightmapST;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp vec4 tmpvar_1;
  mediump vec4 tmpvar_2;
  tmpvar_2 = clamp (_glesColor, 0.0, 1.0);
  tmpvar_1 = tmpvar_2;
  highp vec4 tmpvar_3;
  tmpvar_3.w = 1.0;
  tmpvar_3.xyz = _glesVertex.xyz;
  xlv_COLOR0 = tmpvar_1;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord1.xy * unity_LightmapST.xy) + unity_LightmapST.zw);
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_3));
}


#endif
#ifdef FRAGMENT
uniform mediump sampler2D unity_Lightmap;
uniform sampler2D _MainTex;
uniform lowp vec4 _Color;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp vec4 tex_1;
  lowp vec4 col_2;
  mediump vec4 tmpvar_3;
  tmpvar_3 = texture2D (unity_Lightmap, xlv_TEXCOORD0);
  tex_1 = tmpvar_3;
  col_2 = (tex_1 * _Color);
  lowp vec4 tmpvar_4;
  tmpvar_4 = texture2D (_MainTex, xlv_TEXCOORD1);
  tex_1 = tmpvar_4;
  col_2.xyz = (tmpvar_4 * col_2).xyz;
  col_2.xyz = (col_2 * 2.0).xyz;
  col_2.w = (tmpvar_4.w * xlv_COLOR0.w);
  if ((col_2.w <= _Cutoff)) {
    discard;
  };
  gl_FragData[0] = col_2;
}


#endif


-- Hardware tier variant: Tier 1
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 2
-- Vertex shader for "gles":
// Stats: 5 math, 3 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesColor;
attribute vec4 _glesMultiTexCoord0;
attribute vec4 _glesMultiTexCoord1;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 unity_LightmapST;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp vec4 tmpvar_1;
  mediump vec4 tmpvar_2;
  tmpvar_2 = clamp (_glesColor, 0.0, 1.0);
  tmpvar_1 = tmpvar_2;
  highp vec4 tmpvar_3;
  tmpvar_3.w = 1.0;
  tmpvar_3.xyz = _glesVertex.xyz;
  xlv_COLOR0 = tmpvar_1;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord1.xy * unity_LightmapST.xy) + unity_LightmapST.zw);
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_3));
}


#endif
#ifdef FRAGMENT
uniform mediump sampler2D unity_Lightmap;
uniform sampler2D _MainTex;
uniform lowp vec4 _Color;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp vec4 tex_1;
  lowp vec4 col_2;
  mediump vec4 tmpvar_3;
  tmpvar_3 = texture2D (unity_Lightmap, xlv_TEXCOORD0);
  tex_1 = tmpvar_3;
  col_2 = (tex_1 * _Color);
  lowp vec4 tmpvar_4;
  tmpvar_4 = texture2D (_MainTex, xlv_TEXCOORD1);
  tex_1 = tmpvar_4;
  col_2.xyz = (tmpvar_4 * col_2).xyz;
  col_2.xyz = (col_2 * 2.0).xyz;
  col_2.w = (tmpvar_4.w * xlv_COLOR0.w);
  if ((col_2.w <= _Cutoff)) {
    discard;
  };
  gl_FragData[0] = col_2;
}


#endif


-- Hardware tier variant: Tier 2
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 3
-- Vertex shader for "gles":
// Stats: 5 math, 3 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesColor;
attribute vec4 _glesMultiTexCoord0;
attribute vec4 _glesMultiTexCoord1;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 unity_LightmapST;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp vec4 tmpvar_1;
  mediump vec4 tmpvar_2;
  tmpvar_2 = clamp (_glesColor, 0.0, 1.0);
  tmpvar_1 = tmpvar_2;
  highp vec4 tmpvar_3;
  tmpvar_3.w = 1.0;
  tmpvar_3.xyz = _glesVertex.xyz;
  xlv_COLOR0 = tmpvar_1;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord1.xy * unity_LightmapST.xy) + unity_LightmapST.zw);
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_3));
}


#endif
#ifdef FRAGMENT
uniform mediump sampler2D unity_Lightmap;
uniform sampler2D _MainTex;
uniform lowp vec4 _Color;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp vec4 tex_1;
  lowp vec4 col_2;
  mediump vec4 tmpvar_3;
  tmpvar_3 = texture2D (unity_Lightmap, xlv_TEXCOORD0);
  tex_1 = tmpvar_3;
  col_2 = (tex_1 * _Color);
  lowp vec4 tmpvar_4;
  tmpvar_4 = texture2D (_MainTex, xlv_TEXCOORD1);
  tex_1 = tmpvar_4;
  col_2.xyz = (tmpvar_4 * col_2).xyz;
  col_2.xyz = (col_2 * 2.0).xyz;
  col_2.w = (tmpvar_4.w * xlv_COLOR0.w);
  if ((col_2.w <= _Cutoff)) {
    discard;
  };
  gl_FragData[0] = col_2;
}


#endif


-- Hardware tier variant: Tier 3
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 1
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Normal"
Uses vertex data channel "TexCoord0"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (160 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 0
  Matrix4x4 unity_MatrixVP at 64
  Vector4 unity_LightmapST at 128
  Vector4 _MainTex_ST at 144
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 unity_LightmapST;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    half4 COLOR0 [[ attribute(1) ]] ;
    float3 TEXCOORD1 [[ attribute(2) ]] ;
    float3 TEXCOORD0 [[ attribute(3) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    output.COLOR0 = input.COLOR0;
    output.COLOR0 = clamp(output.COLOR0, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD1.xy * Globals.unity_LightmapST.xy + Globals.unity_LightmapST.zw;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 1
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0
Set 2D Texture "unity_Lightmap" to slot 1

Constant Buffer "Globals" (10 bytes) on slot 0 {
  VectorHalf4 _Color at 0
  ScalarHalf _Cutoff at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 _Color;
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    texture2d<half, access::sample > unity_Lightmap [[ texture (1) ]] ,
    sampler samplerunity_Lightmap [[ sampler (1) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    half3 u_xlat16_1;
    half3 u_xlat16_2;
    bool u_xlatb9;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy);
    u_xlat16_1.x = u_xlat16_0.w * input.COLOR0.w;
    u_xlatb9 = Globals._Cutoff>=u_xlat16_1.x;
    output.SV_Target0.w = u_xlat16_1.x;
    if((int(u_xlatb9) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat16_2.xyz = unity_Lightmap.sample(samplerunity_Lightmap, input.TEXCOORD0.xy).xyz;
    u_xlat16_1.xyz = u_xlat16_2.xyz * Globals._Color.xyz;
    u_xlat16_1.xyz = u_xlat16_0.xyz * u_xlat16_1.xyz;
    output.SV_Target0.xyz = u_xlat16_1.xyz + u_xlat16_1.xyz;
    return output;
}


-- Hardware tier variant: Tier 2
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Normal"
Uses vertex data channel "TexCoord0"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (160 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 0
  Matrix4x4 unity_MatrixVP at 64
  Vector4 unity_LightmapST at 128
  Vector4 _MainTex_ST at 144
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 unity_LightmapST;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    half4 COLOR0 [[ attribute(1) ]] ;
    float3 TEXCOORD1 [[ attribute(2) ]] ;
    float3 TEXCOORD0 [[ attribute(3) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    output.COLOR0 = input.COLOR0;
    output.COLOR0 = clamp(output.COLOR0, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD1.xy * Globals.unity_LightmapST.xy + Globals.unity_LightmapST.zw;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 2
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0
Set 2D Texture "unity_Lightmap" to slot 1

Constant Buffer "Globals" (10 bytes) on slot 0 {
  VectorHalf4 _Color at 0
  ScalarHalf _Cutoff at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 _Color;
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    texture2d<half, access::sample > unity_Lightmap [[ texture (1) ]] ,
    sampler samplerunity_Lightmap [[ sampler (1) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    half3 u_xlat16_1;
    half3 u_xlat16_2;
    bool u_xlatb9;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy);
    u_xlat16_1.x = u_xlat16_0.w * input.COLOR0.w;
    u_xlatb9 = Globals._Cutoff>=u_xlat16_1.x;
    output.SV_Target0.w = u_xlat16_1.x;
    if((int(u_xlatb9) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat16_2.xyz = unity_Lightmap.sample(samplerunity_Lightmap, input.TEXCOORD0.xy).xyz;
    u_xlat16_1.xyz = u_xlat16_2.xyz * Globals._Color.xyz;
    u_xlat16_1.xyz = u_xlat16_0.xyz * u_xlat16_1.xyz;
    output.SV_Target0.xyz = u_xlat16_1.xyz + u_xlat16_1.xyz;
    return output;
}


-- Hardware tier variant: Tier 3
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Normal"
Uses vertex data channel "TexCoord0"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (160 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 0
  Matrix4x4 unity_MatrixVP at 64
  Vector4 unity_LightmapST at 128
  Vector4 _MainTex_ST at 144
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 unity_LightmapST;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    half4 COLOR0 [[ attribute(1) ]] ;
    float3 TEXCOORD1 [[ attribute(2) ]] ;
    float3 TEXCOORD0 [[ attribute(3) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    output.COLOR0 = input.COLOR0;
    output.COLOR0 = clamp(output.COLOR0, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD1.xy * Globals.unity_LightmapST.xy + Globals.unity_LightmapST.zw;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 3
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0
Set 2D Texture "unity_Lightmap" to slot 1

Constant Buffer "Globals" (10 bytes) on slot 0 {
  VectorHalf4 _Color at 0
  ScalarHalf _Cutoff at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 _Color;
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    texture2d<half, access::sample > unity_Lightmap [[ texture (1) ]] ,
    sampler samplerunity_Lightmap [[ sampler (1) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    half3 u_xlat16_1;
    half3 u_xlat16_2;
    bool u_xlatb9;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy);
    u_xlat16_1.x = u_xlat16_0.w * input.COLOR0.w;
    u_xlatb9 = Globals._Cutoff>=u_xlat16_1.x;
    output.SV_Target0.w = u_xlat16_1.x;
    if((int(u_xlatb9) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat16_2.xyz = unity_Lightmap.sample(samplerunity_Lightmap, input.TEXCOORD0.xy).xyz;
    u_xlat16_1.xyz = u_xlat16_2.xyz * Globals._Color.xyz;
    u_xlat16_1.xyz = u_xlat16_0.xyz * u_xlat16_1.xyz;
    output.SV_Target0.xyz = u_xlat16_1.xyz + u_xlat16_1.xyz;
    return output;
}


 }


 // Stats for Vertex shader:
 //         gles: 7 math, 3 texture, 1 branch
 Pass {
  Tags { "LIGHTMODE"="VertexLMRGBM" "QUEUE"="AlphaTest" "IGNOREPROJECTOR"="true" "RenderType"="TransparentCutout" }
  AlphaToMask On
  ColorMask RGB
  //////////////////////////////////
  //                              //
  //      Compiled programs       //
  //                              //
  //////////////////////////////////
//////////////////////////////////////////////////////
No keywords set in this variant.
-- Hardware tier variant: Tier 1
-- Vertex shader for "gles":
// Stats: 7 math, 3 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesColor;
attribute vec4 _glesMultiTexCoord0;
attribute vec4 _glesMultiTexCoord1;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 unity_LightmapST;
uniform highp vec4 unity_Lightmap_ST;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
varying highp vec2 xlv_TEXCOORD2;
void main ()
{
  lowp vec4 tmpvar_1;
  mediump vec4 tmpvar_2;
  tmpvar_2 = clamp (_glesColor, 0.0, 1.0);
  tmpvar_1 = tmpvar_2;
  highp vec4 tmpvar_3;
  tmpvar_3.w = 1.0;
  tmpvar_3.xyz = _glesVertex.xyz;
  xlv_COLOR0 = tmpvar_1;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord1.xy * unity_LightmapST.xy) + unity_LightmapST.zw);
  xlv_TEXCOORD1 = ((_glesMultiTexCoord1.xy * unity_Lightmap_ST.xy) + unity_Lightmap_ST.zw);
  xlv_TEXCOORD2 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_3));
}


#endif
#ifdef FRAGMENT
uniform mediump sampler2D unity_Lightmap;
uniform sampler2D _MainTex;
uniform lowp vec4 _Color;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD2;
void main ()
{
  lowp vec4 tex_1;
  lowp vec4 col_2;
  mediump vec4 tmpvar_3;
  tmpvar_3 = texture2D (unity_Lightmap, xlv_TEXCOORD0);
  tex_1 = tmpvar_3;
  col_2 = (tex_1 * tex_1.w);
  col_2 = (col_2 * 2.0);
  col_2 = (col_2 * _Color);
  lowp vec4 tmpvar_4;
  tmpvar_4 = texture2D (_MainTex, xlv_TEXCOORD2);
  tex_1 = tmpvar_4;
  col_2.xyz = (tmpvar_4 * col_2).xyz;
  col_2.xyz = (col_2 * 4.0).xyz;
  col_2.w = (tmpvar_4.w * xlv_COLOR0.w);
  if ((col_2.w <= _Cutoff)) {
    discard;
  };
  gl_FragData[0] = col_2;
}


#endif


-- Hardware tier variant: Tier 1
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 2
-- Vertex shader for "gles":
// Stats: 7 math, 3 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesColor;
attribute vec4 _glesMultiTexCoord0;
attribute vec4 _glesMultiTexCoord1;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 unity_LightmapST;
uniform highp vec4 unity_Lightmap_ST;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
varying highp vec2 xlv_TEXCOORD2;
void main ()
{
  lowp vec4 tmpvar_1;
  mediump vec4 tmpvar_2;
  tmpvar_2 = clamp (_glesColor, 0.0, 1.0);
  tmpvar_1 = tmpvar_2;
  highp vec4 tmpvar_3;
  tmpvar_3.w = 1.0;
  tmpvar_3.xyz = _glesVertex.xyz;
  xlv_COLOR0 = tmpvar_1;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord1.xy * unity_LightmapST.xy) + unity_LightmapST.zw);
  xlv_TEXCOORD1 = ((_glesMultiTexCoord1.xy * unity_Lightmap_ST.xy) + unity_Lightmap_ST.zw);
  xlv_TEXCOORD2 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_3));
}


#endif
#ifdef FRAGMENT
uniform mediump sampler2D unity_Lightmap;
uniform sampler2D _MainTex;
uniform lowp vec4 _Color;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD2;
void main ()
{
  lowp vec4 tex_1;
  lowp vec4 col_2;
  mediump vec4 tmpvar_3;
  tmpvar_3 = texture2D (unity_Lightmap, xlv_TEXCOORD0);
  tex_1 = tmpvar_3;
  col_2 = (tex_1 * tex_1.w);
  col_2 = (col_2 * 2.0);
  col_2 = (col_2 * _Color);
  lowp vec4 tmpvar_4;
  tmpvar_4 = texture2D (_MainTex, xlv_TEXCOORD2);
  tex_1 = tmpvar_4;
  col_2.xyz = (tmpvar_4 * col_2).xyz;
  col_2.xyz = (col_2 * 4.0).xyz;
  col_2.w = (tmpvar_4.w * xlv_COLOR0.w);
  if ((col_2.w <= _Cutoff)) {
    discard;
  };
  gl_FragData[0] = col_2;
}


#endif


-- Hardware tier variant: Tier 2
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 3
-- Vertex shader for "gles":
// Stats: 7 math, 3 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesColor;
attribute vec4 _glesMultiTexCoord0;
attribute vec4 _glesMultiTexCoord1;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 unity_LightmapST;
uniform highp vec4 unity_Lightmap_ST;
uniform highp vec4 _MainTex_ST;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
varying highp vec2 xlv_TEXCOORD2;
void main ()
{
  lowp vec4 tmpvar_1;
  mediump vec4 tmpvar_2;
  tmpvar_2 = clamp (_glesColor, 0.0, 1.0);
  tmpvar_1 = tmpvar_2;
  highp vec4 tmpvar_3;
  tmpvar_3.w = 1.0;
  tmpvar_3.xyz = _glesVertex.xyz;
  xlv_COLOR0 = tmpvar_1;
  xlv_TEXCOORD0 = ((_glesMultiTexCoord1.xy * unity_LightmapST.xy) + unity_LightmapST.zw);
  xlv_TEXCOORD1 = ((_glesMultiTexCoord1.xy * unity_Lightmap_ST.xy) + unity_Lightmap_ST.zw);
  xlv_TEXCOORD2 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_3));
}


#endif
#ifdef FRAGMENT
uniform mediump sampler2D unity_Lightmap;
uniform sampler2D _MainTex;
uniform lowp vec4 _Color;
uniform lowp float _Cutoff;
varying lowp vec4 xlv_COLOR0;
varying highp vec2 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD2;
void main ()
{
  lowp vec4 tex_1;
  lowp vec4 col_2;
  mediump vec4 tmpvar_3;
  tmpvar_3 = texture2D (unity_Lightmap, xlv_TEXCOORD0);
  tex_1 = tmpvar_3;
  col_2 = (tex_1 * tex_1.w);
  col_2 = (col_2 * 2.0);
  col_2 = (col_2 * _Color);
  lowp vec4 tmpvar_4;
  tmpvar_4 = texture2D (_MainTex, xlv_TEXCOORD2);
  tex_1 = tmpvar_4;
  col_2.xyz = (tmpvar_4 * col_2).xyz;
  col_2.xyz = (col_2 * 4.0).xyz;
  col_2.w = (tmpvar_4.w * xlv_COLOR0.w);
  if ((col_2.w <= _Cutoff)) {
    discard;
  };
  gl_FragData[0] = col_2;
}


#endif


-- Hardware tier variant: Tier 3
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 1
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Normal"
Uses vertex data channel "TexCoord0"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (176 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 0
  Matrix4x4 unity_MatrixVP at 64
  Vector4 unity_LightmapST at 128
  Vector4 unity_Lightmap_ST at 144
  Vector4 _MainTex_ST at 160
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 unity_LightmapST;
    float4 unity_Lightmap_ST;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    half4 COLOR0 [[ attribute(1) ]] ;
    float3 TEXCOORD1 [[ attribute(2) ]] ;
    float3 TEXCOORD0 [[ attribute(3) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
    float2 TEXCOORD2 [[ user(TEXCOORD2) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    output.COLOR0 = input.COLOR0;
    output.COLOR0 = clamp(output.COLOR0, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD1.xy * Globals.unity_LightmapST.xy + Globals.unity_LightmapST.zw;
    output.TEXCOORD1.xy = input.TEXCOORD1.xy * Globals.unity_Lightmap_ST.xy + Globals.unity_Lightmap_ST.zw;
    output.TEXCOORD2.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 1
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0
Set 2D Texture "unity_Lightmap" to slot 1

Constant Buffer "Globals" (10 bytes) on slot 0 {
  VectorHalf4 _Color at 0
  ScalarHalf _Cutoff at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 _Color;
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD2 [[ user(TEXCOORD2) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    texture2d<half, access::sample > unity_Lightmap [[ texture (1) ]] ,
    sampler samplerunity_Lightmap [[ sampler (1) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    half4 u_xlat16_1;
    half3 u_xlat16_2;
    bool u_xlatb9;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD2.xy);
    u_xlat16_1.x = u_xlat16_0.w * input.COLOR0.w;
    u_xlatb9 = Globals._Cutoff>=u_xlat16_1.x;
    output.SV_Target0.w = u_xlat16_1.x;
    if((int(u_xlatb9) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat16_1 = unity_Lightmap.sample(samplerunity_Lightmap, input.TEXCOORD0.xy);
    u_xlat16_2.xyz = u_xlat16_1.www * u_xlat16_1.xyz;
    u_xlat16_2.xyz = u_xlat16_2.xyz * Globals._Color.xyz;
    u_xlat16_2.xyz = u_xlat16_2.xyz + u_xlat16_2.xyz;
    u_xlat16_2.xyz = u_xlat16_0.xyz * u_xlat16_2.xyz;
    output.SV_Target0.xyz = u_xlat16_2.xyz * half3(4.0, 4.0, 4.0);
    return output;
}


-- Hardware tier variant: Tier 2
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Normal"
Uses vertex data channel "TexCoord0"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (176 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 0
  Matrix4x4 unity_MatrixVP at 64
  Vector4 unity_LightmapST at 128
  Vector4 unity_Lightmap_ST at 144
  Vector4 _MainTex_ST at 160
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 unity_LightmapST;
    float4 unity_Lightmap_ST;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    half4 COLOR0 [[ attribute(1) ]] ;
    float3 TEXCOORD1 [[ attribute(2) ]] ;
    float3 TEXCOORD0 [[ attribute(3) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
    float2 TEXCOORD2 [[ user(TEXCOORD2) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    output.COLOR0 = input.COLOR0;
    output.COLOR0 = clamp(output.COLOR0, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD1.xy * Globals.unity_LightmapST.xy + Globals.unity_LightmapST.zw;
    output.TEXCOORD1.xy = input.TEXCOORD1.xy * Globals.unity_Lightmap_ST.xy + Globals.unity_Lightmap_ST.zw;
    output.TEXCOORD2.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 2
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0
Set 2D Texture "unity_Lightmap" to slot 1

Constant Buffer "Globals" (10 bytes) on slot 0 {
  VectorHalf4 _Color at 0
  ScalarHalf _Cutoff at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 _Color;
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD2 [[ user(TEXCOORD2) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    texture2d<half, access::sample > unity_Lightmap [[ texture (1) ]] ,
    sampler samplerunity_Lightmap [[ sampler (1) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    half4 u_xlat16_1;
    half3 u_xlat16_2;
    bool u_xlatb9;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD2.xy);
    u_xlat16_1.x = u_xlat16_0.w * input.COLOR0.w;
    u_xlatb9 = Globals._Cutoff>=u_xlat16_1.x;
    output.SV_Target0.w = u_xlat16_1.x;
    if((int(u_xlatb9) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat16_1 = unity_Lightmap.sample(samplerunity_Lightmap, input.TEXCOORD0.xy);
    u_xlat16_2.xyz = u_xlat16_1.www * u_xlat16_1.xyz;
    u_xlat16_2.xyz = u_xlat16_2.xyz * Globals._Color.xyz;
    u_xlat16_2.xyz = u_xlat16_2.xyz + u_xlat16_2.xyz;
    u_xlat16_2.xyz = u_xlat16_0.xyz * u_xlat16_2.xyz;
    output.SV_Target0.xyz = u_xlat16_2.xyz * half3(4.0, 4.0, 4.0);
    return output;
}


-- Hardware tier variant: Tier 3
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Normal"
Uses vertex data channel "TexCoord0"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (176 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 0
  Matrix4x4 unity_MatrixVP at 64
  Vector4 unity_LightmapST at 128
  Vector4 unity_Lightmap_ST at 144
  Vector4 _MainTex_ST at 160
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 unity_LightmapST;
    float4 unity_Lightmap_ST;
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float3 POSITION0 [[ attribute(0) ]] ;
    half4 COLOR0 [[ attribute(1) ]] ;
    float3 TEXCOORD1 [[ attribute(2) ]] ;
    float3 TEXCOORD0 [[ attribute(3) ]] ;
};

struct Mtl_VertexOut
{
    half4 COLOR0 [[ user(COLOR0) ]];
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
    float2 TEXCOORD2 [[ user(TEXCOORD2) ]];
    float4 mtl_Position [[ position ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    output.COLOR0 = input.COLOR0;
    output.COLOR0 = clamp(output.COLOR0, 0.0h, 1.0h);
    output.TEXCOORD0.xy = input.TEXCOORD1.xy * Globals.unity_LightmapST.xy + Globals.unity_LightmapST.zw;
    output.TEXCOORD1.xy = input.TEXCOORD1.xy * Globals.unity_Lightmap_ST.xy + Globals.unity_Lightmap_ST.zw;
    output.TEXCOORD2.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    return output;
}


-- Hardware tier variant: Tier 3
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0
Set 2D Texture "unity_Lightmap" to slot 1

Constant Buffer "Globals" (10 bytes) on slot 0 {
  VectorHalf4 _Color at 0
  ScalarHalf _Cutoff at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half4 _Color;
    half _Cutoff;
};

struct Mtl_FragmentIn
{
    half4 COLOR0 [[ user(COLOR0) ]] ;
    float2 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD2 [[ user(TEXCOORD2) ]] ;
};

struct Mtl_FragmentOut
{
    half4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    texture2d<half, access::sample > unity_Lightmap [[ texture (1) ]] ,
    sampler samplerunity_Lightmap [[ sampler (1) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half4 u_xlat16_0;
    half4 u_xlat16_1;
    half3 u_xlat16_2;
    bool u_xlatb9;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD2.xy);
    u_xlat16_1.x = u_xlat16_0.w * input.COLOR0.w;
    u_xlatb9 = Globals._Cutoff>=u_xlat16_1.x;
    output.SV_Target0.w = u_xlat16_1.x;
    if((int(u_xlatb9) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat16_1 = unity_Lightmap.sample(samplerunity_Lightmap, input.TEXCOORD0.xy);
    u_xlat16_2.xyz = u_xlat16_1.www * u_xlat16_1.xyz;
    u_xlat16_2.xyz = u_xlat16_2.xyz * Globals._Color.xyz;
    u_xlat16_2.xyz = u_xlat16_2.xyz + u_xlat16_2.xyz;
    u_xlat16_2.xyz = u_xlat16_0.xyz * u_xlat16_2.xyz;
    output.SV_Target0.xyz = u_xlat16_2.xyz * half3(4.0, 4.0, 4.0);
    return output;
}


 }


 // Stats for Vertex shader:
 //         gles: 8 avg math (4..12), 2 texture, 1 branch
 Pass {
  Name "CASTER"
  Tags { "LIGHTMODE"="SHADOWCASTER" "QUEUE"="AlphaTest" "IGNOREPROJECTOR"="true" "SHADOWSUPPORT"="true" "RenderType"="TransparentCutout" }
  //////////////////////////////////
  //                              //
  //      Compiled programs       //
  //                              //
  //////////////////////////////////
//////////////////////////////////////////////////////
Keywords set in this variant: SHADOWS_DEPTH 
-- Hardware tier variant: Tier 1
-- Vertex shader for "gles":
// Stats: 4 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform highp vec4 _WorldSpaceLightPos0;
uniform highp vec4 unity_LightShadowBias;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 _MainTex_ST;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  highp vec4 tmpvar_1;
  highp vec4 wPos_2;
  highp vec4 tmpvar_3;
  tmpvar_3 = (unity_ObjectToWorld * _glesVertex);
  wPos_2 = tmpvar_3;
  if ((unity_LightShadowBias.z != 0.0)) {
    highp mat3 tmpvar_4;
    tmpvar_4[0] = unity_WorldToObject[0].xyz;
    tmpvar_4[1] = unity_WorldToObject[1].xyz;
    tmpvar_4[2] = unity_WorldToObject[2].xyz;
    highp vec3 tmpvar_5;
    tmpvar_5 = normalize((_glesNormal * tmpvar_4));
    highp float tmpvar_6;
    tmpvar_6 = dot (tmpvar_5, normalize((_WorldSpaceLightPos0.xyz - 
      (tmpvar_3.xyz * _WorldSpaceLightPos0.w)
    )));
    wPos_2.xyz = (tmpvar_3.xyz - (tmpvar_5 * (unity_LightShadowBias.z * 
      sqrt((1.0 - (tmpvar_6 * tmpvar_6)))
    )));
  };
  tmpvar_1 = (unity_MatrixVP * wPos_2);
  highp vec4 clipPos_7;
  clipPos_7.xyw = tmpvar_1.xyw;
  clipPos_7.z = (tmpvar_1.z + clamp ((unity_LightShadowBias.x / tmpvar_1.w), 0.0, 1.0));
  clipPos_7.z = mix (clipPos_7.z, max (clipPos_7.z, -(tmpvar_1.w)), unity_LightShadowBias.y);
  gl_Position = clipPos_7;
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
uniform lowp vec4 _Color;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp float x_1;
  x_1 = ((texture2D (_MainTex, xlv_TEXCOORD1).w * _Color.w) - _Cutoff);
  if ((x_1 < 0.0)) {
    discard;
  };
  gl_FragData[0] = vec4(0.0, 0.0, 0.0, 0.0);
}


#endif


-- Hardware tier variant: Tier 1
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 2
-- Vertex shader for "gles":
// Stats: 4 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform highp vec4 _WorldSpaceLightPos0;
uniform highp vec4 unity_LightShadowBias;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 _MainTex_ST;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  highp vec4 tmpvar_1;
  highp vec4 wPos_2;
  highp vec4 tmpvar_3;
  tmpvar_3 = (unity_ObjectToWorld * _glesVertex);
  wPos_2 = tmpvar_3;
  if ((unity_LightShadowBias.z != 0.0)) {
    highp mat3 tmpvar_4;
    tmpvar_4[0] = unity_WorldToObject[0].xyz;
    tmpvar_4[1] = unity_WorldToObject[1].xyz;
    tmpvar_4[2] = unity_WorldToObject[2].xyz;
    highp vec3 tmpvar_5;
    tmpvar_5 = normalize((_glesNormal * tmpvar_4));
    highp float tmpvar_6;
    tmpvar_6 = dot (tmpvar_5, normalize((_WorldSpaceLightPos0.xyz - 
      (tmpvar_3.xyz * _WorldSpaceLightPos0.w)
    )));
    wPos_2.xyz = (tmpvar_3.xyz - (tmpvar_5 * (unity_LightShadowBias.z * 
      sqrt((1.0 - (tmpvar_6 * tmpvar_6)))
    )));
  };
  tmpvar_1 = (unity_MatrixVP * wPos_2);
  highp vec4 clipPos_7;
  clipPos_7.xyw = tmpvar_1.xyw;
  clipPos_7.z = (tmpvar_1.z + clamp ((unity_LightShadowBias.x / tmpvar_1.w), 0.0, 1.0));
  clipPos_7.z = mix (clipPos_7.z, max (clipPos_7.z, -(tmpvar_1.w)), unity_LightShadowBias.y);
  gl_Position = clipPos_7;
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
uniform lowp vec4 _Color;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp float x_1;
  x_1 = ((texture2D (_MainTex, xlv_TEXCOORD1).w * _Color.w) - _Cutoff);
  if ((x_1 < 0.0)) {
    discard;
  };
  gl_FragData[0] = vec4(0.0, 0.0, 0.0, 0.0);
}


#endif


-- Hardware tier variant: Tier 2
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 3
-- Vertex shader for "gles":
// Stats: 4 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec3 _glesNormal;
attribute vec4 _glesMultiTexCoord0;
uniform highp vec4 _WorldSpaceLightPos0;
uniform highp vec4 unity_LightShadowBias;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_WorldToObject;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 _MainTex_ST;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  highp vec4 tmpvar_1;
  highp vec4 wPos_2;
  highp vec4 tmpvar_3;
  tmpvar_3 = (unity_ObjectToWorld * _glesVertex);
  wPos_2 = tmpvar_3;
  if ((unity_LightShadowBias.z != 0.0)) {
    highp mat3 tmpvar_4;
    tmpvar_4[0] = unity_WorldToObject[0].xyz;
    tmpvar_4[1] = unity_WorldToObject[1].xyz;
    tmpvar_4[2] = unity_WorldToObject[2].xyz;
    highp vec3 tmpvar_5;
    tmpvar_5 = normalize((_glesNormal * tmpvar_4));
    highp float tmpvar_6;
    tmpvar_6 = dot (tmpvar_5, normalize((_WorldSpaceLightPos0.xyz - 
      (tmpvar_3.xyz * _WorldSpaceLightPos0.w)
    )));
    wPos_2.xyz = (tmpvar_3.xyz - (tmpvar_5 * (unity_LightShadowBias.z * 
      sqrt((1.0 - (tmpvar_6 * tmpvar_6)))
    )));
  };
  tmpvar_1 = (unity_MatrixVP * wPos_2);
  highp vec4 clipPos_7;
  clipPos_7.xyw = tmpvar_1.xyw;
  clipPos_7.z = (tmpvar_1.z + clamp ((unity_LightShadowBias.x / tmpvar_1.w), 0.0, 1.0));
  clipPos_7.z = mix (clipPos_7.z, max (clipPos_7.z, -(tmpvar_1.w)), unity_LightShadowBias.y);
  gl_Position = clipPos_7;
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
}


#endif
#ifdef FRAGMENT
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
uniform lowp vec4 _Color;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp float x_1;
  x_1 = ((texture2D (_MainTex, xlv_TEXCOORD1).w * _Color.w) - _Cutoff);
  if ((x_1 < 0.0)) {
    discard;
  };
  gl_FragData[0] = vec4(0.0, 0.0, 0.0, 0.0);
}


#endif


-- Hardware tier variant: Tier 3
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 1
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (240 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 32
  Matrix4x4 unity_WorldToObject at 96
  Matrix4x4 unity_MatrixVP at 160
  Vector4 _WorldSpaceLightPos0 at 0
  Vector4 unity_LightShadowBias at 16
  Vector4 _MainTex_ST at 224
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _WorldSpaceLightPos0;
    float4 unity_LightShadowBias;
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float4 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float4 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    float4 mtl_Position [[ position ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float4 u_xlat2;
    float u_xlat6;
    float u_xlat9;
    bool u_xlatb9;
    u_xlat0.x = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz);
    u_xlat0.y = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz);
    u_xlat0.z = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz);
    u_xlat9 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat9 = rsqrt(u_xlat9);
    u_xlat0.xyz = float3(u_xlat9) * u_xlat0.xyz;
    u_xlat1 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3] * input.POSITION0.wwww + u_xlat1;
    u_xlat2.xyz = (-u_xlat1.xyz) * Globals._WorldSpaceLightPos0.www + Globals._WorldSpaceLightPos0.xyz;
    u_xlat9 = dot(u_xlat2.xyz, u_xlat2.xyz);
    u_xlat9 = rsqrt(u_xlat9);
    u_xlat2.xyz = float3(u_xlat9) * u_xlat2.xyz;
    u_xlat9 = dot(u_xlat0.xyz, u_xlat2.xyz);
    u_xlat9 = (-u_xlat9) * u_xlat9 + 1.0;
    u_xlat9 = sqrt(u_xlat9);
    u_xlat9 = u_xlat9 * Globals.unity_LightShadowBias.z;
    u_xlat0.xyz = (-u_xlat0.xyz) * float3(u_xlat9) + u_xlat1.xyz;
    u_xlatb9 = Globals.unity_LightShadowBias.z!=0.0;
    u_xlat0.xyz = (bool(u_xlatb9)) ? u_xlat0.xyz : u_xlat1.xyz;
    u_xlat2 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat2 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat2;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat2;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat1.wwww + u_xlat0;
    u_xlat1.x = Globals.unity_LightShadowBias.x / u_xlat0.w;
    u_xlat1.x = min(u_xlat1.x, 0.0);
    u_xlat1.x = max(u_xlat1.x, -1.0);
    u_xlat6 = u_xlat0.z + u_xlat1.x;
    u_xlat1.x = min(u_xlat0.w, u_xlat6);
    output.mtl_Position.xyw = u_xlat0.xyw;
    u_xlat0.x = (-u_xlat6) + u_xlat1.x;
    output.mtl_Position.z = Globals.unity_LightShadowBias.y * u_xlat0.x + u_xlat6;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    return output;
}


-- Hardware tier variant: Tier 1
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (16 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
  VectorHalf4 _Color at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
    half4 _Color;
};

struct Mtl_FragmentIn
{
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    float4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half u_xlat16_0;
    bool u_xlatb0;
    half u_xlat16_1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy).w;
    u_xlat16_1 = u_xlat16_0 * Globals._Color.w + (-Globals._Cutoff);
    u_xlatb0 = u_xlat16_1<half(0.0);
    if((int(u_xlatb0) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0 = float4(0.0, 0.0, 0.0, 0.0);
    return output;
}


-- Hardware tier variant: Tier 2
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (240 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 32
  Matrix4x4 unity_WorldToObject at 96
  Matrix4x4 unity_MatrixVP at 160
  Vector4 _WorldSpaceLightPos0 at 0
  Vector4 unity_LightShadowBias at 16
  Vector4 _MainTex_ST at 224
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _WorldSpaceLightPos0;
    float4 unity_LightShadowBias;
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float4 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float4 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    float4 mtl_Position [[ position ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float4 u_xlat2;
    float u_xlat6;
    float u_xlat9;
    bool u_xlatb9;
    u_xlat0.x = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz);
    u_xlat0.y = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz);
    u_xlat0.z = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz);
    u_xlat9 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat9 = rsqrt(u_xlat9);
    u_xlat0.xyz = float3(u_xlat9) * u_xlat0.xyz;
    u_xlat1 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3] * input.POSITION0.wwww + u_xlat1;
    u_xlat2.xyz = (-u_xlat1.xyz) * Globals._WorldSpaceLightPos0.www + Globals._WorldSpaceLightPos0.xyz;
    u_xlat9 = dot(u_xlat2.xyz, u_xlat2.xyz);
    u_xlat9 = rsqrt(u_xlat9);
    u_xlat2.xyz = float3(u_xlat9) * u_xlat2.xyz;
    u_xlat9 = dot(u_xlat0.xyz, u_xlat2.xyz);
    u_xlat9 = (-u_xlat9) * u_xlat9 + 1.0;
    u_xlat9 = sqrt(u_xlat9);
    u_xlat9 = u_xlat9 * Globals.unity_LightShadowBias.z;
    u_xlat0.xyz = (-u_xlat0.xyz) * float3(u_xlat9) + u_xlat1.xyz;
    u_xlatb9 = Globals.unity_LightShadowBias.z!=0.0;
    u_xlat0.xyz = (bool(u_xlatb9)) ? u_xlat0.xyz : u_xlat1.xyz;
    u_xlat2 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat2 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat2;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat2;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat1.wwww + u_xlat0;
    u_xlat1.x = Globals.unity_LightShadowBias.x / u_xlat0.w;
    u_xlat1.x = min(u_xlat1.x, 0.0);
    u_xlat1.x = max(u_xlat1.x, -1.0);
    u_xlat6 = u_xlat0.z + u_xlat1.x;
    u_xlat1.x = min(u_xlat0.w, u_xlat6);
    output.mtl_Position.xyw = u_xlat0.xyw;
    u_xlat0.x = (-u_xlat6) + u_xlat1.x;
    output.mtl_Position.z = Globals.unity_LightShadowBias.y * u_xlat0.x + u_xlat6;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    return output;
}


-- Hardware tier variant: Tier 2
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (16 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
  VectorHalf4 _Color at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
    half4 _Color;
};

struct Mtl_FragmentIn
{
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    float4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half u_xlat16_0;
    bool u_xlatb0;
    half u_xlat16_1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy).w;
    u_xlat16_1 = u_xlat16_0 * Globals._Color.w + (-Globals._Cutoff);
    u_xlatb0 = u_xlat16_1<half(0.0);
    if((int(u_xlatb0) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0 = float4(0.0, 0.0, 0.0, 0.0);
    return output;
}


-- Hardware tier variant: Tier 3
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "Color"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (240 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 32
  Matrix4x4 unity_WorldToObject at 96
  Matrix4x4 unity_MatrixVP at 160
  Vector4 _WorldSpaceLightPos0 at 0
  Vector4 unity_LightShadowBias at 16
  Vector4 _MainTex_ST at 224
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _WorldSpaceLightPos0;
    float4 unity_LightShadowBias;
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_WorldToObject[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float4 POSITION0 [[ attribute(0) ]] ;
    float3 NORMAL0 [[ attribute(1) ]] ;
    float4 TEXCOORD0 [[ attribute(2) ]] ;
};

struct Mtl_VertexOut
{
    float4 mtl_Position [[ position ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    float4 u_xlat2;
    float u_xlat6;
    float u_xlat9;
    bool u_xlatb9;
    u_xlat0.x = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[0].xyz);
    u_xlat0.y = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[1].xyz);
    u_xlat0.z = dot(input.NORMAL0.xyz, Globals.hlslcc_mtx4x4unity_WorldToObject[2].xyz);
    u_xlat9 = dot(u_xlat0.xyz, u_xlat0.xyz);
    u_xlat9 = rsqrt(u_xlat9);
    u_xlat0.xyz = float3(u_xlat9) * u_xlat0.xyz;
    u_xlat1 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3] * input.POSITION0.wwww + u_xlat1;
    u_xlat2.xyz = (-u_xlat1.xyz) * Globals._WorldSpaceLightPos0.www + Globals._WorldSpaceLightPos0.xyz;
    u_xlat9 = dot(u_xlat2.xyz, u_xlat2.xyz);
    u_xlat9 = rsqrt(u_xlat9);
    u_xlat2.xyz = float3(u_xlat9) * u_xlat2.xyz;
    u_xlat9 = dot(u_xlat0.xyz, u_xlat2.xyz);
    u_xlat9 = (-u_xlat9) * u_xlat9 + 1.0;
    u_xlat9 = sqrt(u_xlat9);
    u_xlat9 = u_xlat9 * Globals.unity_LightShadowBias.z;
    u_xlat0.xyz = (-u_xlat0.xyz) * float3(u_xlat9) + u_xlat1.xyz;
    u_xlatb9 = Globals.unity_LightShadowBias.z!=0.0;
    u_xlat0.xyz = (bool(u_xlatb9)) ? u_xlat0.xyz : u_xlat1.xyz;
    u_xlat2 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat2 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat2;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat2;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat1.wwww + u_xlat0;
    u_xlat1.x = Globals.unity_LightShadowBias.x / u_xlat0.w;
    u_xlat1.x = min(u_xlat1.x, 0.0);
    u_xlat1.x = max(u_xlat1.x, -1.0);
    u_xlat6 = u_xlat0.z + u_xlat1.x;
    u_xlat1.x = min(u_xlat0.w, u_xlat6);
    output.mtl_Position.xyw = u_xlat0.xyw;
    u_xlat0.x = (-u_xlat6) + u_xlat1.x;
    output.mtl_Position.z = Globals.unity_LightShadowBias.y * u_xlat0.x + u_xlat6;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    return output;
}


-- Hardware tier variant: Tier 3
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (16 bytes) on slot 0 {
  ScalarHalf _Cutoff at 0
  VectorHalf4 _Color at 8
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    half _Cutoff;
    half4 _Color;
};

struct Mtl_FragmentIn
{
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    float4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    half u_xlat16_0;
    bool u_xlatb0;
    half u_xlat16_1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy).w;
    u_xlat16_1 = u_xlat16_0 * Globals._Color.w + (-Globals._Cutoff);
    u_xlatb0 = u_xlat16_1<half(0.0);
    if((int(u_xlatb0) * int(0xffffffffu))!=0){discard_fragment();}
    output.SV_Target0 = float4(0.0, 0.0, 0.0, 0.0);
    return output;
}


//////////////////////////////////////////////////////
Keywords set in this variant: SHADOWS_CUBE 
-- Hardware tier variant: Tier 1
-- Vertex shader for "gles":
// Stats: 12 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesMultiTexCoord0;
uniform highp vec4 _LightPositionRange;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 _MainTex_ST;
varying highp vec3 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  highp vec4 tmpvar_1;
  tmpvar_1.w = 1.0;
  tmpvar_1.xyz = _glesVertex.xyz;
  xlv_TEXCOORD0 = ((unity_ObjectToWorld * _glesVertex).xyz - _LightPositionRange.xyz);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_1));
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
}


#endif
#ifdef FRAGMENT
uniform highp vec4 _LightPositionRange;
uniform highp vec4 unity_LightShadowBias;
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
uniform lowp vec4 _Color;
varying highp vec3 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp float x_1;
  x_1 = ((texture2D (_MainTex, xlv_TEXCOORD1).w * _Color.w) - _Cutoff);
  if ((x_1 < 0.0)) {
    discard;
  };
  highp vec4 tmpvar_2;
  tmpvar_2 = fract((vec4(1.0, 255.0, 65025.0, 1.658138e+07) * min (
    ((sqrt(dot (xlv_TEXCOORD0, xlv_TEXCOORD0)) + unity_LightShadowBias.x) * _LightPositionRange.w)
  , 0.999)));
  highp vec4 tmpvar_3;
  tmpvar_3 = (tmpvar_2 - (tmpvar_2.yzww * 0.003921569));
  gl_FragData[0] = tmpvar_3;
}


#endif


-- Hardware tier variant: Tier 1
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 2
-- Vertex shader for "gles":
// Stats: 12 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesMultiTexCoord0;
uniform highp vec4 _LightPositionRange;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 _MainTex_ST;
varying highp vec3 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  highp vec4 tmpvar_1;
  tmpvar_1.w = 1.0;
  tmpvar_1.xyz = _glesVertex.xyz;
  xlv_TEXCOORD0 = ((unity_ObjectToWorld * _glesVertex).xyz - _LightPositionRange.xyz);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_1));
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
}


#endif
#ifdef FRAGMENT
uniform highp vec4 _LightPositionRange;
uniform highp vec4 unity_LightShadowBias;
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
uniform lowp vec4 _Color;
varying highp vec3 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp float x_1;
  x_1 = ((texture2D (_MainTex, xlv_TEXCOORD1).w * _Color.w) - _Cutoff);
  if ((x_1 < 0.0)) {
    discard;
  };
  highp vec4 tmpvar_2;
  tmpvar_2 = fract((vec4(1.0, 255.0, 65025.0, 1.658138e+07) * min (
    ((sqrt(dot (xlv_TEXCOORD0, xlv_TEXCOORD0)) + unity_LightShadowBias.x) * _LightPositionRange.w)
  , 0.999)));
  highp vec4 tmpvar_3;
  tmpvar_3 = (tmpvar_2 - (tmpvar_2.yzww * 0.003921569));
  gl_FragData[0] = tmpvar_3;
}


#endif


-- Hardware tier variant: Tier 2
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 3
-- Vertex shader for "gles":
// Stats: 12 math, 2 textures, 1 branches
Shader Disassembly:
#version 100

#ifdef VERTEX
attribute vec4 _glesVertex;
attribute vec4 _glesMultiTexCoord0;
uniform highp vec4 _LightPositionRange;
uniform highp mat4 unity_ObjectToWorld;
uniform highp mat4 unity_MatrixVP;
uniform highp vec4 _MainTex_ST;
varying highp vec3 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  highp vec4 tmpvar_1;
  tmpvar_1.w = 1.0;
  tmpvar_1.xyz = _glesVertex.xyz;
  xlv_TEXCOORD0 = ((unity_ObjectToWorld * _glesVertex).xyz - _LightPositionRange.xyz);
  gl_Position = (unity_MatrixVP * (unity_ObjectToWorld * tmpvar_1));
  xlv_TEXCOORD1 = ((_glesMultiTexCoord0.xy * _MainTex_ST.xy) + _MainTex_ST.zw);
}


#endif
#ifdef FRAGMENT
uniform highp vec4 _LightPositionRange;
uniform highp vec4 unity_LightShadowBias;
uniform sampler2D _MainTex;
uniform lowp float _Cutoff;
uniform lowp vec4 _Color;
varying highp vec3 xlv_TEXCOORD0;
varying highp vec2 xlv_TEXCOORD1;
void main ()
{
  lowp float x_1;
  x_1 = ((texture2D (_MainTex, xlv_TEXCOORD1).w * _Color.w) - _Cutoff);
  if ((x_1 < 0.0)) {
    discard;
  };
  highp vec4 tmpvar_2;
  tmpvar_2 = fract((vec4(1.0, 255.0, 65025.0, 1.658138e+07) * min (
    ((sqrt(dot (xlv_TEXCOORD0, xlv_TEXCOORD0)) + unity_LightShadowBias.x) * _LightPositionRange.w)
  , 0.999)));
  highp vec4 tmpvar_3;
  tmpvar_3 = (tmpvar_2 - (tmpvar_2.yzww * 0.003921569));
  gl_FragData[0] = tmpvar_3;
}


#endif


-- Hardware tier variant: Tier 3
-- Fragment shader for "gles":
Shader Disassembly:
// All GLSL source is contained within the vertex program

-- Hardware tier variant: Tier 1
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (160 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 16
  Matrix4x4 unity_MatrixVP at 80
  Vector4 _LightPositionRange at 0
  Vector4 _MainTex_ST at 144
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _LightPositionRange;
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float4 POSITION0 [[ attribute(0) ]] ;
    float4 TEXCOORD0 [[ attribute(1) ]] ;
};

struct Mtl_VertexOut
{
    float3 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    u_xlat0.xyz = input.POSITION0.yyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xyz * input.POSITION0.xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xyz * input.POSITION0.www + u_xlat0.xyz;
    output.TEXCOORD0.xyz = u_xlat0.xyz + (-Globals._LightPositionRange.xyz);
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    return output;
}


-- Hardware tier variant: Tier 1
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (48 bytes) on slot 0 {
  Vector4 _LightPositionRange at 0
  Vector4 unity_LightShadowBias at 16
  ScalarHalf _Cutoff at 32
  VectorHalf4 _Color at 40
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _LightPositionRange;
    float4 unity_LightShadowBias;
    half _Cutoff;
    half4 _Color;
};

struct Mtl_FragmentIn
{
    float3 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    float4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    float u_xlat0;
    half u_xlat16_0;
    bool u_xlatb0;
    half u_xlat16_1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy).w;
    u_xlat16_1 = u_xlat16_0 * Globals._Color.w + (-Globals._Cutoff);
    u_xlatb0 = u_xlat16_1<half(0.0);
    if((int(u_xlatb0) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat0 = dot(input.TEXCOORD0.xyz, input.TEXCOORD0.xyz);
    u_xlat0 = sqrt(u_xlat0);
    u_xlat0 = u_xlat0 + Globals.unity_LightShadowBias.x;
    output.SV_Target0 = float4(u_xlat0) * Globals._LightPositionRange.wwww;
    return output;
}


-- Hardware tier variant: Tier 2
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (160 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 16
  Matrix4x4 unity_MatrixVP at 80
  Vector4 _LightPositionRange at 0
  Vector4 _MainTex_ST at 144
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _LightPositionRange;
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float4 POSITION0 [[ attribute(0) ]] ;
    float4 TEXCOORD0 [[ attribute(1) ]] ;
};

struct Mtl_VertexOut
{
    float3 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    u_xlat0.xyz = input.POSITION0.yyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xyz * input.POSITION0.xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xyz * input.POSITION0.www + u_xlat0.xyz;
    output.TEXCOORD0.xyz = u_xlat0.xyz + (-Globals._LightPositionRange.xyz);
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    return output;
}


-- Hardware tier variant: Tier 2
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (48 bytes) on slot 0 {
  Vector4 _LightPositionRange at 0
  Vector4 unity_LightShadowBias at 16
  ScalarHalf _Cutoff at 32
  VectorHalf4 _Color at 40
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _LightPositionRange;
    float4 unity_LightShadowBias;
    half _Cutoff;
    half4 _Color;
};

struct Mtl_FragmentIn
{
    float3 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    float4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    float u_xlat0;
    half u_xlat16_0;
    bool u_xlatb0;
    half u_xlat16_1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy).w;
    u_xlat16_1 = u_xlat16_0 * Globals._Color.w + (-Globals._Cutoff);
    u_xlatb0 = u_xlat16_1<half(0.0);
    if((int(u_xlatb0) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat0 = dot(input.TEXCOORD0.xyz, input.TEXCOORD0.xyz);
    u_xlat0 = sqrt(u_xlat0);
    u_xlat0 = u_xlat0 + Globals.unity_LightShadowBias.x;
    output.SV_Target0 = float4(u_xlat0) * Globals._LightPositionRange.wwww;
    return output;
}


-- Hardware tier variant: Tier 3
-- Vertex shader for "metal":
Uses vertex data channel "Vertex"
Uses vertex data channel "TexCoord"

Constant Buffer "Globals" (160 bytes) on slot 0 {
  Matrix4x4 unity_ObjectToWorld at 16
  Matrix4x4 unity_MatrixVP at 80
  Vector4 _LightPositionRange at 0
  Vector4 _MainTex_ST at 144
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _LightPositionRange;
    float4 hlslcc_mtx4x4unity_ObjectToWorld[4];
    float4 hlslcc_mtx4x4unity_MatrixVP[4];
    float4 _MainTex_ST;
};

struct Mtl_VertexIn
{
    float4 POSITION0 [[ attribute(0) ]] ;
    float4 TEXCOORD0 [[ attribute(1) ]] ;
};

struct Mtl_VertexOut
{
    float3 TEXCOORD0 [[ user(TEXCOORD0) ]];
    float4 mtl_Position [[ position ]];
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]];
};

vertex Mtl_VertexOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    Mtl_VertexIn input [[ stage_in ]])
{
    Mtl_VertexOut output;
    float4 u_xlat0;
    float4 u_xlat1;
    u_xlat0.xyz = input.POSITION0.yyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1].xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0].xyz * input.POSITION0.xxx + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2].xyz * input.POSITION0.zzz + u_xlat0.xyz;
    u_xlat0.xyz = Globals.hlslcc_mtx4x4unity_ObjectToWorld[3].xyz * input.POSITION0.www + u_xlat0.xyz;
    output.TEXCOORD0.xyz = u_xlat0.xyz + (-Globals._LightPositionRange.xyz);
    u_xlat0 = input.POSITION0.yyyy * Globals.hlslcc_mtx4x4unity_ObjectToWorld[1];
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[0] * input.POSITION0.xxxx + u_xlat0;
    u_xlat0 = Globals.hlslcc_mtx4x4unity_ObjectToWorld[2] * input.POSITION0.zzzz + u_xlat0;
    u_xlat0 = u_xlat0 + Globals.hlslcc_mtx4x4unity_ObjectToWorld[3];
    u_xlat1 = u_xlat0.yyyy * Globals.hlslcc_mtx4x4unity_MatrixVP[1];
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[0] * u_xlat0.xxxx + u_xlat1;
    u_xlat1 = Globals.hlslcc_mtx4x4unity_MatrixVP[2] * u_xlat0.zzzz + u_xlat1;
    output.mtl_Position = Globals.hlslcc_mtx4x4unity_MatrixVP[3] * u_xlat0.wwww + u_xlat1;
    output.TEXCOORD1.xy = input.TEXCOORD0.xy * Globals._MainTex_ST.xy + Globals._MainTex_ST.zw;
    return output;
}


-- Hardware tier variant: Tier 3
-- Fragment shader for "metal":
Set 2D Texture "_MainTex" to slot 0

Constant Buffer "Globals" (48 bytes) on slot 0 {
  Vector4 _LightPositionRange at 0
  Vector4 unity_LightShadowBias at 16
  ScalarHalf _Cutoff at 32
  VectorHalf4 _Color at 40
}

Shader Disassembly:
#include <metal_stdlib>
#include <metal_texture>
using namespace metal;
struct Globals_Type
{
    float4 _LightPositionRange;
    float4 unity_LightShadowBias;
    half _Cutoff;
    half4 _Color;
};

struct Mtl_FragmentIn
{
    float3 TEXCOORD0 [[ user(TEXCOORD0) ]] ;
    float2 TEXCOORD1 [[ user(TEXCOORD1) ]] ;
};

struct Mtl_FragmentOut
{
    float4 SV_Target0 [[ color(0) ]];
};

fragment Mtl_FragmentOut xlatMtlMain(
    constant Globals_Type& Globals [[ buffer(0) ]],
    texture2d<half, access::sample > _MainTex [[ texture (0) ]] ,
    sampler sampler_MainTex [[ sampler (0) ]] ,
    Mtl_FragmentIn input [[ stage_in ]])
{
    Mtl_FragmentOut output;
    float u_xlat0;
    half u_xlat16_0;
    bool u_xlatb0;
    half u_xlat16_1;
    u_xlat16_0 = _MainTex.sample(sampler_MainTex, input.TEXCOORD1.xy).w;
    u_xlat16_1 = u_xlat16_0 * Globals._Color.w + (-Globals._Cutoff);
    u_xlatb0 = u_xlat16_1<half(0.0);
    if((int(u_xlatb0) * int(0xffffffffu))!=0){discard_fragment();}
    u_xlat0 = dot(input.TEXCOORD0.xyz, input.TEXCOORD0.xyz);
    u_xlat0 = sqrt(u_xlat0);
    u_xlat0 = u_xlat0 + Globals.unity_LightShadowBias.x;
    output.SV_Target0 = float4(u_xlat0) * Globals._LightPositionRange.wwww;
    return output;
}


 }
}
}