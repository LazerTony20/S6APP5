#ifndef RTW_HEADER_mfbase_h_
#define RTW_HEADER_mfbase_h_
#include <stddef.h>
#include <emmintrin.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef mfbase_COMMON_INCLUDES_
#define mfbase_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#include "stdlib.h"
#endif
#include "mfbase_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME mfbase
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (18) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { creal_T iylv2nym5g ; real_T kvqrrj0pzi ; real_T ax4bvnk00p ;
real_T af1inyls4b ; real_T bferk0v2qg ; real_T jb1ivufg2k ; real_T pz5or3grsa
; real_T etpk0jtvcd ; real_T m2wtc0ckk2 ; real_T arphqhrt5o ; real_T
drxlfcnfp1 ; real_T c3x101if1y ; real_T cmi2ww44rt ; real_T b3yqfcq0dq ;
real_T dykl1swx0i ; boolean_T iuggdtr2ec ; } B ; typedef struct { creal_T
pcpbmwodyl [ 50 ] ; real_T dm5weww2p4 ; real_T dksjzo35tz [ 544 ] ; real_T
ns1e41noub ; real_T aocltagyhy ; real_T equyrom4ri [ 12 ] ; real_T dch3ldlezc
; real_T ls4rap0rxz ; real_T jrje5czue4 [ 1774 ] ; real_T of1zesxmyr [ 1774 ]
; real_T kvwf4z4tdc ; real_T mm2cbalfqe [ 50 ] ; real_T covkckaqzy [ 100 ] ;
real_T lmpd4xicsv ; real_T azd1nscsvg ; real_T fbqsbjctwt [ 1774 ] ; real_T
iuikqqfh00 ; real_T biw5aqxbfw [ 6 ] ; real_T lq4msaiq1a ; real_T nibf5v1aip
; real_T j1qmyowelr ; real_T p020cbzauu ; struct { void * TimePtr ; void *
DataPtr ; void * RSimInfoPtr ; } fsno0ua31k ; struct { void * TimePtr ; void
* DataPtr ; void * RSimInfoPtr ; } jbo3zfaqcm ; struct { void * LoggedData ;
} jy4tcp0o45 ; struct { void * LoggedData ; } gqufr243mp ; struct { void *
AQHandles ; } ndvre5ae41 ; int32_T k3xlnbd1ms ; int32_T fqkbge1awt ; int32_T
jvkjpo0c5r ; int32_T ak2jmb5qhb ; int32_T mhhphxgwzy ; int32_T ofz1xq2j1b ;
int32_T h14we4z1mf ; int32_T b2lamlqnub ; int32_T ludu3yc2dq ; int32_T
fiifseybg4 ; uint32_T hylkho2gi3 ; uint32_T a5szsiglx3 [ 2 ] ; uint32_T
d4lombes4u ; uint32_T flmb0z2zov [ 2 ] ; uint32_T ep5lb2uepv ; struct { int_T
PrevIndex ; } exlre3bg5r ; struct { int_T PrevIndex ; } lmahjmhysf ;
boolean_T gdnwvot3yi ; } DW ; typedef struct { rtwCAPI_ModelMappingInfo mmi ;
} DataMapInfo ; struct P_ { real_T Gain_Trans ; real_T Use_acc ; real_T
Use_noise ; real_T SineWave_Amplitude ; real_T FMDemodulatorPassband_Fc ;
real_T SineWave_Frequency ; real_T Difference_ICPrevInput ; real_T
Difference_ICPrevInput_dxjkj5p3um ; real_T FMDemodulatorPassband_Kc ; real_T
BruitGaussienavecAccdesacc_MeanVal ; real_T BruitGaussienAdditif_MeanVal ;
real_T SineWave_Phase ; uint32_T NSampleEnable_ActiveLevel ; uint32_T
FMDemodulatorPassband_Ho ; real_T Gain3_Gain ; real_T Switch_Threshold ;
real_T FromWorkspace1_Time0 [ 140001 ] ; real_T FromWorkspace1_Data0 [ 140001
] ; real_T FromWorkspace2_Time0 [ 128000 ] ; real_T FromWorkspace2_Data0 [
128000 ] ; real_T DigitalFilter_InitialStates ; real_T
DigitalFilter_Coefficients [ 545 ] ; real_T DiscreteFilter_NumCoef [ 2 ] ;
real_T DiscreteFilter_DenCoef [ 2 ] ; real_T DiscreteFilter_InitialStates ;
real_T Switch1_Threshold ; real_T Gain3_Gain_exqztjtlsw ; real_T
Delay_InitialCondition ; real_T Gain_Gain ; real_T
DigitalFilter_InitialStates_bkk5sluujk ; real_T
DigitalFilter_Coefficients_i4kbkanqgr [ 1775 ] ; real_T
BruitGaussienavecAccdesacc_VarianceRTP ; real_T
BruitGaussienAdditif_VarianceRTP ; real_T Switch2_Threshold ; real_T
DigitalFilter_InitialStates_lrzr4u3uql ; real_T
DigitalFilter_Coefficients_ktr5wnr0zq [ 1775 ] ; real_T
DigitalFilter_InitialStates_frg2cb2ftf ; real_T
DigitalFilter_Coefficients_ip34inopza [ 101 ] ; real_T
DiscreteFilter_NumCoef_is5dyfvkwv [ 2 ] ; real_T
DiscreteFilter_DenCoef_c5me0iwyqv [ 2 ] ; real_T
DiscreteFilter_InitialStates_l4qwclyke5 ; real_T Switch3_Threshold ; real_T
DigitalFilter_InitialStates_hneh2bcd32 ; real_T
DigitalFilter_Coefficients_lkgbigm1d0 [ 1775 ] ; real_T Constant1_Value ;
real_T Constant_Value ; real_T Deltaf_Value ; real_T
Constant_Value_kslaxjeuqc ; real_T Constant1_Value_dsqxhplhg3 ; uint8_T
ManualSwitch7_CurrentSetting ; uint8_T ManualSwitch1_CurrentSetting ; } ;
extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW
rtDW ; extern P rtP ; extern mxArray * mr_mfbase_GetDWork ( ) ; extern void
mr_mfbase_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_mfbase_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * mfbase_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern const int_T
gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern rtInportTUtable
* gblInportTUtables ; extern const char * gblInportFileName ; extern const
int_T gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern
const int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
