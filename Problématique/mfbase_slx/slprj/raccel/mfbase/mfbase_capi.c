#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "mfbase_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "mfbase.h"
#include "mfbase_capi.h"
#include "mfbase_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"mfbase/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "mfbase/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 2 , 0 , TARGET_STRING ( "mfbase/Switch1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 3 , 0 , TARGET_STRING ( "mfbase/Switch3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"mfbase/Manual Switch1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 5
, 0 , TARGET_STRING ( "mfbase/Manual Switch7" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 2 } , { 6 , 0 , TARGET_STRING ( "mfbase/Downsample" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 7 , 0 , TARGET_STRING (
"mfbase/Conditionnement/Upsample" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 8 , 0 , TARGET_STRING ( "mfbase/Digital Filter Design/Digital Filter"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"mfbase/Digital Filter Design1/Digital Filter" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"mfbase/Passe-Bande R/Digital Filter" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 11 , 0 , TARGET_STRING ( "mfbase/VCO/Fcn" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
 "mfbase/FM Demodulator Passband/Output zeros until signal  is available (Ho)/N-Sample Enable"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"mfbase/FM Demodulator Passband/Subsystem/Complex Exponential" ) ,
TARGET_STRING ( "" ) , 0 , 2 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"mfbase/FM Demodulator Passband/Subsystem1/Unwrap" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"mfbase/FM Demodulator Passband/Time and  Sample time/Time" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0
, 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 16
, TARGET_STRING ( "mfbase/FM Demodulator Passband" ) , TARGET_STRING ( "Fc" )
, 0 , 0 , 0 } , { 17 , TARGET_STRING ( "mfbase/FM Demodulator Passband" ) ,
TARGET_STRING ( "Kc" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING (
"mfbase/FM Demodulator Passband" ) , TARGET_STRING ( "Ho" ) , 3 , 0 , 0 } , {
19 , TARGET_STRING ( "mfbase/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 20 , TARGET_STRING ( "mfbase/Constant1" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 21 , TARGET_STRING ( "mfbase/Delta f" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 22 , TARGET_STRING ( "mfbase/From Workspace1" ) ,
TARGET_STRING ( "Time0" ) , 0 , 1 , 0 } , { 23 , TARGET_STRING (
"mfbase/From Workspace1" ) , TARGET_STRING ( "Data0" ) , 0 , 1 , 0 } , { 24 ,
TARGET_STRING ( "mfbase/From Workspace2" ) , TARGET_STRING ( "Time0" ) , 0 ,
2 , 0 } , { 25 , TARGET_STRING ( "mfbase/From Workspace2" ) , TARGET_STRING (
"Data0" ) , 0 , 2 , 0 } , { 26 , TARGET_STRING ( "mfbase/Gain3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING (
"mfbase/Bruit Gaussien Additif" ) , TARGET_STRING ( "MeanVal" ) , 0 , 0 , 0 }
, { 28 , TARGET_STRING ( "mfbase/Bruit Gaussien Additif" ) , TARGET_STRING (
"VarianceRTP" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"mfbase/Bruit Gaussien avec Acc//desacc" ) , TARGET_STRING ( "MeanVal" ) , 0
, 0 , 0 } , { 30 , TARGET_STRING ( "mfbase/Bruit Gaussien avec Acc//desacc" )
, TARGET_STRING ( "VarianceRTP" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING (
"mfbase/Sine Wave" ) , TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 32 ,
TARGET_STRING ( "mfbase/Sine Wave" ) , TARGET_STRING ( "Frequency" ) , 0 , 0
, 0 } , { 33 , TARGET_STRING ( "mfbase/Sine Wave" ) , TARGET_STRING ( "Phase"
) , 0 , 0 , 0 } , { 34 , TARGET_STRING ( "mfbase/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING ( "mfbase/Switch1" ) ,
TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"mfbase/Switch2" ) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } , { 37 ,
TARGET_STRING ( "mfbase/Switch3" ) , TARGET_STRING ( "Threshold" ) , 0 , 0 ,
0 } , { 38 , TARGET_STRING ( "mfbase/Manual Switch1" ) , TARGET_STRING (
"CurrentSetting" ) , 4 , 0 , 0 } , { 39 , TARGET_STRING (
"mfbase/Manual Switch7" ) , TARGET_STRING ( "CurrentSetting" ) , 4 , 0 , 0 }
, { 40 , TARGET_STRING ( "mfbase/Conditionnement/Gain3" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"mfbase/Digital Filter Design1/Digital Filter" ) , TARGET_STRING (
"InitialStates" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"mfbase/Digital Filter Design1/Digital Filter" ) , TARGET_STRING (
"Coefficients" ) , 0 , 3 , 0 } , { 43 , TARGET_STRING (
"mfbase/Filtre accentuation/Discrete Filter" ) , TARGET_STRING ( "Numerator"
) , 0 , 4 , 0 } , { 44 , TARGET_STRING (
"mfbase/Filtre accentuation/Discrete Filter" ) , TARGET_STRING (
"Denominator" ) , 0 , 4 , 0 } , { 45 , TARGET_STRING (
"mfbase/Filtre accentuation/Discrete Filter" ) , TARGET_STRING (
"InitialStates" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"mfbase/Filtre désaccentuation/Discrete Filter" ) , TARGET_STRING (
"Numerator" ) , 0 , 4 , 0 } , { 47 , TARGET_STRING (
"mfbase/Filtre désaccentuation/Discrete Filter" ) , TARGET_STRING (
"Denominator" ) , 0 , 4 , 0 } , { 48 , TARGET_STRING (
"mfbase/Filtre désaccentuation/Discrete Filter" ) , TARGET_STRING (
"InitialStates" ) , 0 , 0 , 0 } , { 49 , TARGET_STRING (
"mfbase/Passe-Bande R/Digital Filter" ) , TARGET_STRING ( "InitialStates" ) ,
0 , 0 , 0 } , { 50 , TARGET_STRING ( "mfbase/Passe-Bande R/Digital Filter" )
, TARGET_STRING ( "Coefficients" ) , 0 , 3 , 0 } , { 51 , TARGET_STRING (
"mfbase/Passe-Bande T/Digital Filter" ) , TARGET_STRING ( "InitialStates" ) ,
0 , 0 , 0 } , { 52 , TARGET_STRING ( "mfbase/Passe-Bande T/Digital Filter" )
, TARGET_STRING ( "Coefficients" ) , 0 , 3 , 0 } , { 53 , TARGET_STRING (
"mfbase/VCO/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 54 ,
TARGET_STRING ( "mfbase/VCO/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 55 , TARGET_STRING ( "mfbase/VCO/Gain" ) , TARGET_STRING ( "Gain" )
, 0 , 0 , 0 } , { 56 , TARGET_STRING ( "mfbase/VCO/Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 57 , TARGET_STRING (
"mfbase/Conditionnement/Digital Filter Design/Digital Filter" ) ,
TARGET_STRING ( "InitialStates" ) , 0 , 0 , 0 } , { 58 , TARGET_STRING (
"mfbase/Conditionnement/Digital Filter Design/Digital Filter" ) ,
TARGET_STRING ( "Coefficients" ) , 0 , 5 , 0 } , { 59 , TARGET_STRING (
"mfbase/FM Demodulator Passband/Analytic Signal/Digital Filter" ) ,
TARGET_STRING ( "InitialStates" ) , 0 , 0 , 0 } , { 60 , TARGET_STRING (
"mfbase/FM Demodulator Passband/Analytic Signal/Digital Filter" ) ,
TARGET_STRING ( "Coefficients" ) , 0 , 6 , 0 } , { 61 , TARGET_STRING (
 "mfbase/FM Demodulator Passband/Output zeros until signal  is available (Ho)/N-Sample Enable"
) , TARGET_STRING ( "ActiveLevel" ) , 3 , 0 , 0 } , { 62 , TARGET_STRING (
"mfbase/FM Demodulator Passband/Subsystem1/Difference" ) , TARGET_STRING (
"ICPrevInput" ) , 0 , 0 , 0 } , { 63 , TARGET_STRING (
"mfbase/FM Demodulator Passband/Time and  Sample time/Difference" ) ,
TARGET_STRING ( "ICPrevInput" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 64 , TARGET_STRING (
"Gain_Trans" ) , 0 , 0 , 0 } , { 65 , TARGET_STRING ( "Use_acc" ) , 0 , 0 , 0
} , { 66 , TARGET_STRING ( "Use_noise" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 ,
0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . etpk0jtvcd , & rtB . m2wtc0ckk2 ,
& rtB . bferk0v2qg , & rtB . cmi2ww44rt , & rtB . af1inyls4b , & rtB .
kvqrrj0pzi , & rtB . dykl1swx0i , & rtB . ax4bvnk00p , & rtB . jb1ivufg2k , &
rtB . b3yqfcq0dq , & rtB . arphqhrt5o , & rtB . pz5or3grsa , & rtB .
iuggdtr2ec , & rtB . iylv2nym5g . re , & rtB . c3x101if1y , & rtB .
drxlfcnfp1 , & rtP . FMDemodulatorPassband_Fc , & rtP .
FMDemodulatorPassband_Kc , & rtP . FMDemodulatorPassband_Ho , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . Deltaf_Value , & rtP .
FromWorkspace1_Time0 [ 0 ] , & rtP . FromWorkspace1_Data0 [ 0 ] , & rtP .
FromWorkspace2_Time0 [ 0 ] , & rtP . FromWorkspace2_Data0 [ 0 ] , & rtP .
Gain3_Gain_exqztjtlsw , & rtP . BruitGaussienAdditif_MeanVal , & rtP .
BruitGaussienAdditif_VarianceRTP , & rtP . BruitGaussienavecAccdesacc_MeanVal
, & rtP . BruitGaussienavecAccdesacc_VarianceRTP , & rtP . SineWave_Amplitude
, & rtP . SineWave_Frequency , & rtP . SineWave_Phase , & rtP .
Switch_Threshold , & rtP . Switch1_Threshold , & rtP . Switch2_Threshold , &
rtP . Switch3_Threshold , & rtP . ManualSwitch1_CurrentSetting , & rtP .
ManualSwitch7_CurrentSetting , & rtP . Gain3_Gain , & rtP .
DigitalFilter_InitialStates_hneh2bcd32 , & rtP .
DigitalFilter_Coefficients_lkgbigm1d0 [ 0 ] , & rtP . DiscreteFilter_NumCoef
[ 0 ] , & rtP . DiscreteFilter_DenCoef [ 0 ] , & rtP .
DiscreteFilter_InitialStates , & rtP . DiscreteFilter_NumCoef_is5dyfvkwv [ 0
] , & rtP . DiscreteFilter_DenCoef_c5me0iwyqv [ 0 ] , & rtP .
DiscreteFilter_InitialStates_l4qwclyke5 , & rtP .
DigitalFilter_InitialStates_lrzr4u3uql , & rtP .
DigitalFilter_Coefficients_ktr5wnr0zq [ 0 ] , & rtP .
DigitalFilter_InitialStates_bkk5sluujk , & rtP .
DigitalFilter_Coefficients_i4kbkanqgr [ 0 ] , & rtP .
Constant_Value_kslaxjeuqc , & rtP . Constant1_Value_dsqxhplhg3 , & rtP .
Gain_Gain , & rtP . Delay_InitialCondition , & rtP .
DigitalFilter_InitialStates , & rtP . DigitalFilter_Coefficients [ 0 ] , &
rtP . DigitalFilter_InitialStates_frg2cb2ftf , & rtP .
DigitalFilter_Coefficients_ip34inopza [ 0 ] , & rtP .
NSampleEnable_ActiveLevel , & rtP . Difference_ICPrevInput_dxjkj5p3um , & rtP
. Difference_ICPrevInput , & rtP . Gain_Trans , & rtP . Use_acc , & rtP .
Use_noise , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } , { "struct" , "creal_T" , 0 , 0 , sizeof ( creal_T ) , SS_DOUBLE ,
1 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof ( uint32_T ) ,
SS_UINT32 , 0 , 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof (
uint8_T ) , SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 1 , 1 , 140001 , 1 , 128000 , 1 , 1 , 1775 , 1 , 2 , 1 , 545 , 1 , 101 } ;
static const real_T rtcapiStoredFloats [ ] = { 6.25E-7 , 0.0 , 6.25E-6 ,
6.25E-5 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 0 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 1 , 0 } , { ( const void * ) & rtcapiStoredFloats
[ 3 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 2 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 16 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 48 ,
rtModelParameters , 3 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 1390277494U , 1537201641U , 3250638661U , 178444161U } , ( NULL ) , 0 , 0
, rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo *
mfbase_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void mfbase_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void mfbase_host_InitializeDataMapInfo ( mfbase_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
