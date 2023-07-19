#include "rt_logging_mmi.h"
#include "mfbase_capi.h"
#include <math.h>
#include "mfbase.h"
#include "mfbase_private.h"
#include "mfbase_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 2 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.5 (R2021a) 14-Nov-2020" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void RandSrcInitState_U_64 ( const uint32_T seed [ ] , real_T state
[ ] , int32_T nChans ) { real_T d ; int32_T i ; int32_T k ; int32_T n ;
uint32_T j ; for ( i = 0 ; i < nChans ; i ++ ) { j = seed [ i ] != 0U ? seed
[ i ] : 2147483648U ; state [ 35 * i + 34 ] = j ; for ( k = 0 ; k < 32 ; k ++
) { d = 0.0 ; for ( n = 0 ; n < 53 ; n ++ ) { j ^= j << 13 ; j ^= j >> 17 ; j
^= j << 5 ; d = ( real_T ) ( ( int32_T ) ( j >> 19 ) & 1 ) + ( d + d ) ; }
state [ 35 * i + k ] = ldexp ( d , - 53 ) ; } state [ 35 * i + 32 ] = 0.0 ;
state [ 35 * i + 33 ] = 0.0 ; } } void RandSrc_U_D ( real_T y [ ] , const
real_T minVec [ ] , int32_T minLen , const real_T maxVec [ ] , int32_T maxLen
, real_T state [ ] , int32_T nChans , int32_T nSamps ) { real_T d ; real_T
min ; real_T scale ; int32_T ii [ 2 ] ; int32_T chan ; int32_T i ; int32_T
one ; int32_T samps ; uint32_T j ; int8_T * onePtr ; one = 1 ; onePtr = (
int8_T * ) & one ; one = ( onePtr [ 0U ] == 0 ) ; for ( chan = 0 ; chan <
nChans ; chan ++ ) { min = minVec [ minLen > 1 ? chan : 0 ] ; scale = maxVec
[ maxLen > 1 ? chan : 0 ] - min ; i = ( int32_T ) ( ( uint32_T ) state [ chan
* 35 + 33 ] & 31U ) ; j = ( uint32_T ) state [ chan * 35 + 34 ] ; for ( samps
= 0 ; samps < nSamps ; samps ++ ) { d = ( state [ ( ( i + 20 ) & 31 ) + chan
* 35 ] - state [ ( ( i + 5 ) & 31 ) + chan * 35 ] ) - state [ chan * 35 + 32
] ; if ( d >= 0.0 ) { state [ chan * 35 + 32 ] = 0.0 ; } else { d ++ ; state
[ chan * 35 + 32 ] = 1.1102230246251565E-16 ; } state [ chan * 35 + i ] = d ;
i = ( i + 1 ) & 31 ; memcpy ( & ii [ 0U ] , & d , sizeof ( real_T ) ) ; ii [
one ] ^= j ; j ^= j << 13 ; j ^= j >> 17 ; j ^= j << 5 ; ii [ one ^ 1 ] ^= j
& 1048575U ; memcpy ( & d , & ii [ 0U ] , sizeof ( real_T ) ) ; y [ chan *
nSamps + samps ] = scale * d + min ; } state [ chan * 35 + 33 ] = i ; state [
chan * 35 + 34 ] = j ; } } void RandSrcCreateSeeds_64 ( uint32_T initSeed ,
uint32_T seedArray [ ] , int32_T numSeeds ) { real_T state [ 35 ] ; real_T
max ; real_T min ; real_T tmp ; int32_T i ; min = 0.0 ; max = 1.0 ;
RandSrcInitState_U_64 ( & initSeed , & state [ 0 ] , 1 ) ; for ( i = 0 ; i <
numSeeds ; i ++ ) { RandSrc_U_D ( & tmp , & min , 1 , & max , 1 , state , 1 ,
1 ) ; seedArray [ i ] = ( uint32_T ) ( tmp * 2.147483648E+9 ) ; } } void
RandSrcInitState_GZ ( const uint32_T seed [ ] , uint32_T state [ ] , int32_T
nChans ) { int32_T i ; for ( i = 0 ; i < nChans ; i ++ ) { state [ i << 1 ] =
362436069U ; state [ ( i << 1 ) + 1 ] = seed [ i ] == 0U ? 521288629U : seed
[ i ] ; } } void RandSrc_GZ_D ( real_T y [ ] , const real_T mean [ ] ,
int32_T meanLen , const real_T xstd [ ] , int32_T xstdLen , uint32_T state [
] , int32_T nChans , int32_T nSamps ) { real_T r ; real_T s ; real_T std ;
real_T x ; real_T y_p ; int32_T chan ; int32_T i ; int32_T j ; int32_T samp ;
uint32_T icng ; uint32_T jsr ; static const real_T vt [ 65 ] = { 0.340945 ,
0.4573146 , 0.5397793 , 0.6062427 , 0.6631691 , 0.7136975 , 0.7596125 ,
0.8020356 , 0.8417227 , 0.8792102 , 0.9148948 , 0.9490791 , 0.9820005 ,
1.0138492 , 1.044781 , 1.0749254 , 1.1043917 , 1.1332738 , 1.161653 ,
1.189601 , 1.2171815 , 1.2444516 , 1.2714635 , 1.298265 , 1.3249008 ,
1.3514125 , 1.3778399 , 1.4042211 , 1.4305929 , 1.4569915 , 1.4834527 ,
1.5100122 , 1.5367061 , 1.5635712 , 1.5906454 , 1.617968 , 1.6455802 ,
1.6735255 , 1.7018503 , 1.7306045 , 1.7598422 , 1.7896223 , 1.8200099 ,
1.851077 , 1.8829044 , 1.9155831 , 1.9492166 , 1.9839239 , 2.0198431 ,
2.0571356 , 2.095993 , 2.136645 , 2.1793713 , 2.2245175 , 2.2725186 ,
2.3239338 , 2.3795008 , 2.4402218 , 2.5075117 , 2.5834658 , 2.6713916 ,
2.7769942 , 2.7769942 , 2.7769942 , 2.7769942 } ; for ( chan = 0 ; chan <
nChans ; chan ++ ) { std = xstd [ xstdLen > 1 ? chan : 0 ] ; icng = state [
chan << 1 ] ; jsr = state [ ( chan << 1 ) + 1 ] ; for ( samp = 0 ; samp <
nSamps ; samp ++ ) { icng = 69069U * icng + 1234567U ; jsr ^= jsr << 13 ; jsr
^= jsr >> 17 ; jsr ^= jsr << 5 ; i = ( int32_T ) ( icng + jsr ) ; j = ( i &
63 ) + 1 ; r = ( real_T ) i * 4.6566128730773926E-10 * vt [ j ] ; if ( ! (
muDoubleScalarAbs ( r ) <= vt [ j - 1 ] ) ) { x = ( muDoubleScalarAbs ( r ) -
vt [ j - 1 ] ) / ( vt [ j ] - vt [ j - 1 ] ) ; icng = 69069U * icng +
1234567U ; jsr ^= jsr << 13 ; jsr ^= jsr >> 17 ; jsr ^= jsr << 5 ; y_p = (
real_T ) ( int32_T ) ( icng + jsr ) * 2.328306436538696E-10 + 0.5 ; s = x +
y_p ; if ( s > 1.301198 ) { r = r < 0.0 ? 0.4878992 * x - 0.4878992 :
0.4878992 - 0.4878992 * x ; } else if ( ! ( s <= 0.9689279 ) ) { x =
0.4878992 - 0.4878992 * x ; if ( y_p > 12.67706 - muDoubleScalarExp ( - 0.5 *
x * x ) * 12.37586 ) { r = r < 0.0 ? - x : x ; } else if ( ! (
muDoubleScalarExp ( - 0.5 * vt [ j ] * vt [ j ] ) + y_p * 0.01958303 / vt [ j
] <= muDoubleScalarExp ( - 0.5 * r * r ) ) ) { do { icng = 69069U * icng +
1234567U ; jsr ^= jsr << 13 ; jsr ^= jsr >> 17 ; jsr ^= jsr << 5 ; x =
muDoubleScalarLog ( ( real_T ) ( int32_T ) ( icng + jsr ) *
2.328306436538696E-10 + 0.5 ) / 2.776994 ; icng = 69069U * icng + 1234567U ;
jsr ^= jsr << 13 ; jsr ^= jsr >> 17 ; jsr ^= jsr << 5 ; } while (
muDoubleScalarLog ( ( real_T ) ( int32_T ) ( icng + jsr ) *
2.328306436538696E-10 + 0.5 ) * - 2.0 <= x * x ) ; r = r < 0.0 ? x - 2.776994
: 2.776994 - x ; } } } y [ chan * nSamps + samp ] = mean [ meanLen > 1 ? chan
: 0 ] + std * r ; } state [ chan << 1 ] = icng ; state [ ( chan << 1 ) + 1 ]
= jsr ; } } void MdlInitialize ( void ) { real_T arg ; int32_T i ; rtDW .
dm5weww2p4 = 0.0 ; rtDW . k3xlnbd1ms = 0 ; for ( i = 0 ; i < 544 ; i ++ ) {
rtDW . dksjzo35tz [ i ] = rtP . DigitalFilter_InitialStates ; } rtDW .
ns1e41noub = 0.0 ; rtDW . aocltagyhy = rtP . DiscreteFilter_InitialStates ;
memset ( & rtDW . equyrom4ri [ 0 ] , 0 , 12U * sizeof ( real_T ) ) ; rtDW .
dch3ldlezc = rtP . Delay_InitialCondition ; arg = muDoubleScalarRem ( rtP .
SineWave_Phase , 6.2831853071795862 ) ; if ( arg < 0.0 ) { arg +=
6.2831853071795862 ; } rtDW . ls4rap0rxz = arg ; rtDW . fqkbge1awt = 0 ; rtDW
. jvkjpo0c5r = 0 ; for ( i = 0 ; i < 1774 ; i ++ ) { rtDW . jrje5czue4 [ i ]
= rtP . DigitalFilter_InitialStates_bkk5sluujk ; rtDW . of1zesxmyr [ i ] =
rtP . DigitalFilter_InitialStates_lrzr4u3uql ; } rtDW . ep5lb2uepv = (
uint32_T ) 0 ; rtDW . kvwf4z4tdc = rtP . Difference_ICPrevInput ; rtDW .
ak2jmb5qhb = 0 ; rtDW . mhhphxgwzy = 0 ; memset ( & rtDW . pcpbmwodyl [ 0 ] ,
0 , 50U * sizeof ( creal_T ) ) ; memset ( & rtDW . mm2cbalfqe [ 0 ] , 0 , 50U
* sizeof ( real_T ) ) ; for ( i = 0 ; i < 100 ; i ++ ) { rtDW . covkckaqzy [
i ] = rtP . DigitalFilter_InitialStates_frg2cb2ftf ; } rtDW . gdnwvot3yi =
true ; rtDW . j1qmyowelr = 0.0 ; rtDW . lmpd4xicsv = rtP .
Difference_ICPrevInput_dxjkj5p3um ; rtDW . azd1nscsvg = rtP .
DiscreteFilter_InitialStates_l4qwclyke5 ; rtDW . ofz1xq2j1b = 0 ; for ( i = 0
; i < 1774 ; i ++ ) { rtDW . fbqsbjctwt [ i ] = rtP .
DigitalFilter_InitialStates_hneh2bcd32 ; } } void MdlStart ( void ) { real_T
arg ; uint32_T initSeed ; { bool externalInputIsInDatasetFormat = false ;
void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { { sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU origSigName = sdiGetLabelFromChars (
"" ) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath
= sdiGetLabelFromChars ( "mfbase/Constant1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE ; int_T sigDimsArray [
1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . ndvre5ae41 . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "28de9e1b-04d9-47f6-afc6-e652c4ada76b" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. ndvre5ae41 . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . ndvre5ae41
. AQHandles , "Parameter" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime
( rtDW . ndvre5ae41 . AQHandles , ssGetTaskTime ( rtS , 3 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . ndvre5ae41 . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . ndvre5ae41 . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } } } { int_T dimensions [ 2 ] = { 1 , 1 } ;
rtDW . jy4tcp0o45 . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "Pr" , SS_DOUBLE , 0 , 0 , 1 , 1 , 2 , dimensions , NO_LOGVALDIMS , (
NULL ) , ( NULL ) , 0 , 1 , 6.25E-7 , 1 ) ; if ( rtDW . jy4tcp0o45 .
LoggedData == ( NULL ) ) return ; } { int_T dimensions [ 2 ] = { 1 , 1 } ;
rtDW . gqufr243mp . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "Sortie" , SS_DOUBLE , 0 , 0 , 1 , 1 , 2 , dimensions , NO_LOGVALDIMS ,
( NULL ) , ( NULL ) , 0 , 1 , 6.25E-5 , 1 ) ; if ( rtDW . gqufr243mp .
LoggedData == ( NULL ) ) return ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "Sonm16" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace1_Data0 ; fromwksInfo -> nDataPoints
= 140001 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace1_Time0 ;
rtDW . fsno0ua31k . TimePtr = fromwksInfo -> time ; rtDW . fsno0ua31k .
DataPtr = fromwksInfo -> data ; rtDW . fsno0ua31k . RSimInfoPtr = fromwksInfo
; } rtDW . exlre3bg5r . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "Sonf16" ; fromwksInfo ->
origDataTypeId = 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo ->
origWidth = 1 ; fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo
-> data = ( void * ) rtP . FromWorkspace2_Data0 ; fromwksInfo -> nDataPoints
= 128000 ; fromwksInfo -> time = ( double * ) rtP . FromWorkspace2_Time0 ;
rtDW . jbo3zfaqcm . TimePtr = fromwksInfo -> time ; rtDW . jbo3zfaqcm .
DataPtr = fromwksInfo -> data ; rtDW . jbo3zfaqcm . RSimInfoPtr = fromwksInfo
; } rtDW . lmahjmhysf . PrevIndex = 0 ; } rtDW . b2lamlqnub = 0 ; rtDW .
h14we4z1mf = 0 ; rtDW . fiifseybg4 = 0 ; rtDW . ludu3yc2dq = 0 ; arg =
muDoubleScalarRem ( rtP . SineWave_Phase , 6.2831853071795862 ) ; if ( arg <
0.0 ) { arg += 6.2831853071795862 ; } rtDW . ls4rap0rxz = arg ; initSeed = (
uint32_T ) ( 100000 * rand ( ) ) ; RandSrcCreateSeeds_64 ( initSeed , & rtDW
. hylkho2gi3 , 1 ) ; RandSrcInitState_GZ ( & rtDW . hylkho2gi3 , & rtDW .
a5szsiglx3 [ 0 ] , 1 ) ; initSeed = ( uint32_T ) ( 100000 * rand ( ) ) ;
RandSrcCreateSeeds_64 ( initSeed , & rtDW . d4lombes4u , 1 ) ;
RandSrcInitState_GZ ( & rtDW . d4lombes4u , & rtDW . flmb0z2zov [ 0 ] , 1 ) ;
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { real_T ii1zz21sh4 ;
real_T eheq2ztwuw ; __m128d tmp ; real_T b3yxc1rh5x ; real_T gp0gzup4ft ;
real_T mggakv40ks ; real_T n3gvwnxz3z ; int32_T cnt ; int32_T inCnt ; if (
ssIsSampleHit ( rtS , 2 , 0 ) ) { { real_T t = ssGetTaskTime ( rtS , 2 ) ;
real_T * pTimeValues = ( real_T * ) rtDW . fsno0ua31k . TimePtr ; real_T *
pDataValues = ( real_T * ) rtDW . fsno0ua31k . DataPtr ; int numPoints ,
lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . fsno0ua31k .
RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints
- 1 ; if ( t < pTimeValues [ 0 ] ) { ii1zz21sh4 = 0.0 ; } else if ( t ==
pTimeValues [ lastPoint ] ) { ii1zz21sh4 = pDataValues [ lastPoint ] ; } else
if ( t > pTimeValues [ lastPoint ] ) { ii1zz21sh4 = 0.0 ; } else { int_T
currTimeIndex = rtDW . exlre3bg5r . PrevIndex ; if ( t < pTimeValues [
currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } ii1zz21sh4 = pDataValues [ currTimeIndex ] ; rtDW
. exlre3bg5r . PrevIndex = currTimeIndex ; } } { real_T t = ssGetTaskTime (
rtS , 2 ) ; real_T * pTimeValues = ( real_T * ) rtDW . jbo3zfaqcm . TimePtr ;
real_T * pDataValues = ( real_T * ) rtDW . jbo3zfaqcm . DataPtr ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
jbo3zfaqcm . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t < pTimeValues [ 0 ] ) { eheq2ztwuw = 0.0 ; } else if
( t == pTimeValues [ lastPoint ] ) { eheq2ztwuw = pDataValues [ lastPoint ] ;
} else if ( t > pTimeValues [ lastPoint ] ) { eheq2ztwuw = 0.0 ; } else {
int_T currTimeIndex = rtDW . lmahjmhysf . PrevIndex ; if ( t < pTimeValues [
currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } eheq2ztwuw = pDataValues [ currTimeIndex ] ; rtDW
. lmahjmhysf . PrevIndex = currTimeIndex ; } } if ( rtP .
ManualSwitch7_CurrentSetting == 1 ) { rtB . kvqrrj0pzi = ii1zz21sh4 ; } else
{ rtB . kvqrrj0pzi = eheq2ztwuw ; } rtDW . dm5weww2p4 = rtB . kvqrrj0pzi ;
rtDW . h14we4z1mf = 0 ; rtDW . b2lamlqnub = 0 ; } if ( ssIsSampleHit ( rtS ,
1 , 0 ) ) { inCnt = rtDW . b2lamlqnub ; if ( rtDW . h14we4z1mf == 0 ) { rtB .
ax4bvnk00p = rtDW . dm5weww2p4 ; inCnt = rtDW . b2lamlqnub + 1 ; if ( rtDW .
b2lamlqnub + 1 >= 1 ) { inCnt = 0 ; } } else { rtB . ax4bvnk00p = 0.0 ; } cnt
= rtDW . h14we4z1mf + 1 ; if ( rtDW . h14we4z1mf + 1 == 10 ) { cnt = 0 ; }
rtDW . h14we4z1mf = cnt ; rtDW . b2lamlqnub = inCnt ; mggakv40ks = rtB .
ax4bvnk00p * rtP . DigitalFilter_Coefficients [ 0 ] ; inCnt = 1 ; for ( cnt =
rtDW . k3xlnbd1ms ; cnt < 544 ; cnt ++ ) { mggakv40ks += rtDW . dksjzo35tz [
cnt ] * rtP . DigitalFilter_Coefficients [ inCnt ] ; inCnt ++ ; } for ( cnt =
0 ; cnt < rtDW . k3xlnbd1ms ; cnt ++ ) { mggakv40ks += rtDW . dksjzo35tz [
cnt ] * rtP . DigitalFilter_Coefficients [ inCnt ] ; inCnt ++ ; } if ( rtP .
ManualSwitch1_CurrentSetting == 1 ) { rtB . af1inyls4b = rtP . Gain3_Gain *
mggakv40ks ; } else { rtB . af1inyls4b = rtP . Constant1_Value ; } rtDW .
ns1e41noub = rtB . af1inyls4b ; rtDW . ludu3yc2dq = 0 ; rtDW . fiifseybg4 = 0
; } inCnt = rtDW . fiifseybg4 ; if ( rtDW . ludu3yc2dq == 0 ) { mggakv40ks =
rtDW . ns1e41noub ; inCnt = rtDW . fiifseybg4 + 1 ; if ( rtDW . fiifseybg4 +
1 >= 1 ) { inCnt = 0 ; } } else { mggakv40ks = 0.0 ; } cnt = rtDW .
ludu3yc2dq + 1 ; if ( rtDW . ludu3yc2dq + 1 == 10 ) { cnt = 0 ; } rtDW .
ludu3yc2dq = cnt ; rtDW . fiifseybg4 = inCnt ; rtDW . iuikqqfh00 = (
mggakv40ks - rtP . DiscreteFilter_DenCoef [ 1 ] * rtDW . aocltagyhy ) / rtP .
DiscreteFilter_DenCoef [ 0 ] ; if ( rtP . Use_acc > rtP . Switch1_Threshold )
{ rtB . bferk0v2qg = rtP . DiscreteFilter_NumCoef [ 0 ] * rtDW . iuikqqfh00 +
rtP . DiscreteFilter_NumCoef [ 1 ] * rtDW . aocltagyhy ; } else { rtB .
bferk0v2qg = mggakv40ks ; } rtDW . biw5aqxbfw [ 0 ] = ( 0.39840190260962222 *
rtB . bferk0v2qg - - 1.9996340177995371 * rtDW . equyrom4ri [ 0 ] ) -
0.99981376352845863 * rtDW . equyrom4ri [ 1 ] ; rtDW . biw5aqxbfw [ 1 ] = ( (
( - 1.99980655692852 * rtDW . equyrom4ri [ 0 ] + rtDW . biw5aqxbfw [ 0 ] ) +
rtDW . equyrom4ri [ 1 ] ) * 0.86214689252879251 - - 1.9990891829489383 * rtDW
. equyrom4ri [ 2 ] ) - 0.9992634467110395 * rtDW . equyrom4ri [ 3 ] ; rtDW .
biw5aqxbfw [ 2 ] = ( ( ( - 1.9997978723073633 * rtDW . equyrom4ri [ 2 ] +
rtDW . biw5aqxbfw [ 1 ] ) + rtDW . equyrom4ri [ 3 ] ) * 0.68790128792232441 -
- 1.9978956617967574 * rtDW . equyrom4ri [ 4 ] ) - 0.998054433302771 * rtDW .
equyrom4ri [ 5 ] ; rtDW . biw5aqxbfw [ 3 ] = ( ( ( - 1.9997691943469207 *
rtDW . equyrom4ri [ 4 ] + rtDW . biw5aqxbfw [ 2 ] ) + rtDW . equyrom4ri [ 5 ]
) * 0.37490807826215083 - - 1.9953154786920504 * rtDW . equyrom4ri [ 6 ] ) -
0.99543945377642 * rtDW . equyrom4ri [ 7 ] ; rtDW . biw5aqxbfw [ 4 ] = ( ( (
- 1.9996693187168857 * rtDW . equyrom4ri [ 6 ] + rtDW . biw5aqxbfw [ 3 ] ) +
rtDW . equyrom4ri [ 7 ] ) * 0.0739646787446445 - - 1.9911603881776003 * rtDW
. equyrom4ri [ 8 ] ) - 0.99122798334236528 * rtDW . equyrom4ri [ 9 ] ; rtDW .
biw5aqxbfw [ 5 ] = ( ( ( - 1.999086115617454 * rtDW . equyrom4ri [ 8 ] + rtDW
. biw5aqxbfw [ 4 ] ) + rtDW . equyrom4ri [ 9 ] ) * 0.0066569287323102891 - -
0.994291527586279 * rtDW . equyrom4ri [ 10 ] ) - 0.0 * rtDW . equyrom4ri [ 11
] ; rtB . jb1ivufg2k = ( rtDW . biw5aqxbfw [ 5 ] + rtDW . equyrom4ri [ 10 ] )
+ 0.0 * rtDW . equyrom4ri [ 11 ] ; rtB . pz5or3grsa = muDoubleScalarRem ( (
rtP . Gain3_Gain_exqztjtlsw * rtB . jb1ivufg2k * rtP . Deltaf_Value * rtP .
Constant1_Value_dsqxhplhg3 + rtP . Constant_Value_kslaxjeuqc ) + rtDW .
dch3ldlezc , 800.0 ) ; mggakv40ks = rtP . SineWave_Amplitude *
muDoubleScalarSin ( rtDW . ls4rap0rxz ) ; rtDW . ls4rap0rxz += rtP .
SineWave_Frequency * 3.9269908169872419E-6 ; if ( rtDW . ls4rap0rxz >=
6.2831853071795862 ) { rtDW . ls4rap0rxz -= 6.2831853071795862 ; } else if (
rtDW . ls4rap0rxz < 0.0 ) { rtDW . ls4rap0rxz += 6.2831853071795862 ; } rtB .
etpk0jtvcd = muDoubleScalarSin ( rtP . Gain_Gain * rtB . pz5or3grsa ) *
mggakv40ks ; gp0gzup4ft = rtB . etpk0jtvcd * rtP .
DigitalFilter_Coefficients_i4kbkanqgr [ 0 ] ; inCnt = 1 ; for ( cnt = rtDW .
fqkbge1awt ; cnt < 1774 ; cnt ++ ) { gp0gzup4ft += rtDW . jrje5czue4 [ cnt ]
* rtP . DigitalFilter_Coefficients_i4kbkanqgr [ inCnt ] ; inCnt ++ ; } for (
cnt = 0 ; cnt < rtDW . fqkbge1awt ; cnt ++ ) { gp0gzup4ft += rtDW .
jrje5czue4 [ cnt ] * rtP . DigitalFilter_Coefficients_i4kbkanqgr [ inCnt ] ;
inCnt ++ ; } RandSrc_GZ_D ( & b3yxc1rh5x , & rtP .
BruitGaussienavecAccdesacc_MeanVal , 1 , & rtP .
BruitGaussienavecAccdesacc_VarianceRTP , 1 , rtDW . a5szsiglx3 , 1 , 1 ) ;
RandSrc_GZ_D ( & n3gvwnxz3z , & rtP . BruitGaussienAdditif_MeanVal , 1 , &
rtP . BruitGaussienAdditif_VarianceRTP , 1 , rtDW . flmb0z2zov , 1 , 1 ) ; if
( rtP . Use_noise > rtP . Switch2_Threshold ) { if ( rtP . Use_acc > rtP .
Switch_Threshold ) { n3gvwnxz3z = b3yxc1rh5x ; } } else { n3gvwnxz3z = rtP .
Constant_Value ; } rtB . m2wtc0ckk2 = rtP . Gain_Trans * gp0gzup4ft +
n3gvwnxz3z ; gp0gzup4ft = rtB . m2wtc0ckk2 * rtP .
DigitalFilter_Coefficients_ktr5wnr0zq [ 0 ] ; inCnt = 1 ; for ( cnt = rtDW .
jvkjpo0c5r ; cnt < 1774 ; cnt ++ ) { gp0gzup4ft += rtDW . of1zesxmyr [ cnt ]
* rtP . DigitalFilter_Coefficients_ktr5wnr0zq [ inCnt ] ; inCnt ++ ; } for (
cnt = 0 ; cnt < rtDW . jvkjpo0c5r ; cnt ++ ) { gp0gzup4ft += rtDW .
of1zesxmyr [ cnt ] * rtP . DigitalFilter_Coefficients_ktr5wnr0zq [ inCnt ] ;
inCnt ++ ; } rtB . arphqhrt5o = gp0gzup4ft ; if ( ssGetLogOutput ( rtS ) ) {
{ double locTime = ssGetTaskTime ( rtS , 0 ) ; ; if (
rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . jy4tcp0o45 . LoggedData ) , & rtB . arphqhrt5o , 0 ) ; }
} } { { if ( rtDW . ep5lb2uepv == rtP . FMDemodulatorPassband_Ho ) { rtB .
iuggdtr2ec = ( boolean_T ) ( 2 - rtP . NSampleEnable_ActiveLevel ) ; } else {
rtB . iuggdtr2ec = ( boolean_T ) ( rtP . NSampleEnable_ActiveLevel - 1 ) ; (
rtDW . ep5lb2uepv ) ++ ; } } } { real_T * y = ( real_T * ) & rtB . drxlfcnfp1
; real_T time = ssGetTaskTime ( rtS , 0 ) ; * y = time ; } mggakv40ks = rtDW
. pcpbmwodyl [ rtDW . ak2jmb5qhb ] . re ; gp0gzup4ft = rtDW . pcpbmwodyl [
rtDW . ak2jmb5qhb ] . im ; b3yxc1rh5x = rtDW . mm2cbalfqe [ rtDW . mhhphxgwzy
] ; n3gvwnxz3z = rtB . arphqhrt5o * rtP .
DigitalFilter_Coefficients_ip34inopza [ 0 ] + rtDW . covkckaqzy [ 0 ] ; for (
cnt = 0 ; cnt <= 96 ; cnt += 2 ) { tmp = _mm_loadu_pd ( & rtDW . covkckaqzy [
cnt + 1 ] ) ; _mm_storeu_pd ( & rtDW . covkckaqzy [ cnt ] , _mm_add_pd (
_mm_mul_pd ( _mm_loadu_pd ( & rtP . DigitalFilter_Coefficients_ip34inopza [
cnt + 1 ] ) , _mm_set1_pd ( rtB . arphqhrt5o ) ) , tmp ) ) ; } for ( cnt = 98
; cnt < 99 ; cnt ++ ) { rtDW . covkckaqzy [ cnt ] = rtP .
DigitalFilter_Coefficients_ip34inopza [ cnt + 1 ] * rtB . arphqhrt5o + rtDW .
covkckaqzy [ cnt + 1 ] ; } rtDW . covkckaqzy [ 99 ] = rtB . arphqhrt5o * rtP
. DigitalFilter_Coefficients_ip34inopza [ 100 ] ; b3yxc1rh5x =
muDoubleScalarAtan2 ( mggakv40ks * n3gvwnxz3z + gp0gzup4ft * b3yxc1rh5x ,
mggakv40ks * b3yxc1rh5x - gp0gzup4ft * n3gvwnxz3z ) ; if ( rtDW . gdnwvot3yi
) { rtDW . nibf5v1aip = b3yxc1rh5x ; rtDW . gdnwvot3yi = false ; } n3gvwnxz3z
= rtDW . j1qmyowelr ; gp0gzup4ft = b3yxc1rh5x - rtDW . nibf5v1aip ;
mggakv40ks = gp0gzup4ft - muDoubleScalarFloor ( ( gp0gzup4ft +
3.1415926535897931 ) / 6.2831853071795862 ) * 6.2831853071795862 ; if ( (
mggakv40ks == - 3.1415926535897931 ) && ( gp0gzup4ft > 0.0 ) ) { mggakv40ks =
3.1415926535897931 ; } gp0gzup4ft = mggakv40ks - gp0gzup4ft ; if (
muDoubleScalarAbs ( gp0gzup4ft ) > 3.1415926535897931 ) { n3gvwnxz3z = rtDW .
j1qmyowelr + gp0gzup4ft ; } rtB . c3x101if1y = b3yxc1rh5x + n3gvwnxz3z ; rtDW
. nibf5v1aip = b3yxc1rh5x ; rtDW . j1qmyowelr = n3gvwnxz3z ; if ( rtB .
iuggdtr2ec ) { b3yxc1rh5x = 0.0 ; } else { b3yxc1rh5x = 1.0 / ( rtB .
drxlfcnfp1 - rtDW . kvwf4z4tdc ) * ( rtB . c3x101if1y - rtDW . lmpd4xicsv ) *
( 1.0 / ( 6.2831853071795862 * rtP . FMDemodulatorPassband_Kc ) ) ; } rtDW .
p020cbzauu = ( b3yxc1rh5x - rtP . DiscreteFilter_DenCoef_c5me0iwyqv [ 1 ] *
rtDW . azd1nscsvg ) / rtP . DiscreteFilter_DenCoef_c5me0iwyqv [ 0 ] ; if (
rtP . Use_acc > rtP . Switch3_Threshold ) { rtB . cmi2ww44rt = rtP .
DiscreteFilter_NumCoef_is5dyfvkwv [ 0 ] * rtDW . p020cbzauu + rtP .
DiscreteFilter_NumCoef_is5dyfvkwv [ 1 ] * rtDW . azd1nscsvg ; } else { rtB .
cmi2ww44rt = b3yxc1rh5x ; } gp0gzup4ft = rtB . cmi2ww44rt * rtP .
DigitalFilter_Coefficients_lkgbigm1d0 [ 0 ] ; inCnt = 1 ; for ( cnt = rtDW .
ofz1xq2j1b ; cnt < 1774 ; cnt ++ ) { gp0gzup4ft += rtDW . fbqsbjctwt [ cnt ]
* rtP . DigitalFilter_Coefficients_lkgbigm1d0 [ inCnt ] ; inCnt ++ ; } for (
cnt = 0 ; cnt < rtDW . ofz1xq2j1b ; cnt ++ ) { gp0gzup4ft += rtDW .
fbqsbjctwt [ cnt ] * rtP . DigitalFilter_Coefficients_lkgbigm1d0 [ inCnt ] ;
inCnt ++ ; } rtB . b3yqfcq0dq = gp0gzup4ft ; if ( ssIsSpecialSampleHit ( rtS
, 2 , 0 , 0 ) ) { rtB . dykl1swx0i = rtB . b3yqfcq0dq ; } if ( ssIsSampleHit
( rtS , 2 , 0 ) ) { if ( ssGetLogOutput ( rtS ) ) { { double locTime =
ssGetTaskTime ( rtS , 2 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . gqufr243mp
. LoggedData ) , & rtB . dykl1swx0i , 0 ) ; } } } } mggakv40ks = -
6.2831853071795862 * rtP . FMDemodulatorPassband_Fc * rtB . drxlfcnfp1 ; rtB
. iylv2nym5g . re = muDoubleScalarCos ( mggakv40ks ) ; rtB . iylv2nym5g . im
= muDoubleScalarSin ( mggakv40ks ) ; UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID3 ( int_T tid ) { { if ( rtDW . ndvre5ae41 . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . ndvre5ae41 . AQHandles ,
ssGetTaskTime ( rtS , 3 ) , ( char * ) & rtP . Constant1_Value + 0 ) ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { int32_T j ;
int32_T memIdx ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . k3xlnbd1ms --
; if ( rtDW . k3xlnbd1ms < 0 ) { rtDW . k3xlnbd1ms = 543 ; } rtDW .
dksjzo35tz [ rtDW . k3xlnbd1ms ] = rtB . ax4bvnk00p ; } rtDW . aocltagyhy =
rtDW . iuikqqfh00 ; for ( j = 0 ; j < 6 ; j ++ ) { memIdx = j << 1 ; rtDW .
equyrom4ri [ memIdx + 1 ] = rtDW . equyrom4ri [ memIdx ] ; rtDW . equyrom4ri
[ memIdx ] = rtDW . biw5aqxbfw [ j ] ; } rtDW . dch3ldlezc = rtB . pz5or3grsa
; rtDW . fqkbge1awt -- ; if ( rtDW . fqkbge1awt < 0 ) { rtDW . fqkbge1awt =
1773 ; } rtDW . jrje5czue4 [ rtDW . fqkbge1awt ] = rtB . etpk0jtvcd ; rtDW .
jvkjpo0c5r -- ; if ( rtDW . jvkjpo0c5r < 0 ) { rtDW . jvkjpo0c5r = 1773 ; }
rtDW . of1zesxmyr [ rtDW . jvkjpo0c5r ] = rtB . m2wtc0ckk2 ; rtDW .
kvwf4z4tdc = rtB . drxlfcnfp1 ; j = rtDW . ak2jmb5qhb ; rtDW . ak2jmb5qhb = (
rtDW . ak2jmb5qhb + 1 ) % 50 ; rtDW . pcpbmwodyl [ j ] = rtB . iylv2nym5g ; j
= rtDW . mhhphxgwzy ; rtDW . mhhphxgwzy = ( rtDW . mhhphxgwzy + 1 ) % 50 ;
rtDW . mm2cbalfqe [ j ] = rtB . arphqhrt5o ; rtDW . lmpd4xicsv = rtB .
c3x101if1y ; rtDW . azd1nscsvg = rtDW . p020cbzauu ; rtDW . ofz1xq2j1b -- ;
if ( rtDW . ofz1xq2j1b < 0 ) { rtDW . ofz1xq2j1b = 1773 ; } rtDW . fbqsbjctwt
[ rtDW . ofz1xq2j1b ] = rtB . cmi2ww44rt ; UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlTerminate
( void ) { rt_FREE ( rtDW . fsno0ua31k . RSimInfoPtr ) ; rt_FREE ( rtDW .
jbo3zfaqcm . RSimInfoPtr ) ; { if ( rtDW . ndvre5ae41 . AQHandles ) {
sdiTerminateStreaming ( & rtDW . ndvre5ae41 . AQHandles ) ; } } } static void
mr_mfbase_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) ; static void
mr_mfbase_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j ,
const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_mfbase_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_mfbase_restoreDataFromMxArray ( void * destData , const mxArray * srcArray
, mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_mfbase_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_mfbase_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_mfbase_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_mfbase_extractBitFieldFromMxArray
( const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_mfbase_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i ,
int j , mwIndex offset , const void * srcData , size_t numBytes ) ; static
void mr_mfbase_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i
, int j , mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T
* varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j
) ) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const
uint8_T * ) srcData , numBytes ) ; } static void
mr_mfbase_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_mfbase_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_mfbase_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_mfbase_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , uint_T fieldVal ) { mxSetCell (
mxGetFieldByNumber ( destArray , i , j ) , offset , mxCreateDoubleScalar ( (
double ) fieldVal ) ) ; } static uint_T
mr_mfbase_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static uint_T
mr_mfbase_extractBitFieldFromCellArrayWithOffset ( const mxArray * srcArray ,
mwIndex i , int j , mwIndex offset , uint_T numBits ) { const uint_T fieldVal
= ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber ( srcArray , i , j
) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u ) ; } mxArray *
mr_mfbase_GetDWork ( ) { static const char * ssDWFieldNames [ 3 ] = { "rtB" ,
"rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 ,
3 , ssDWFieldNames ) ; mr_mfbase_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const
void * ) & ( rtB ) , sizeof ( rtB ) ) ; { static const char *
rtdwDataFieldNames [ 40 ] = { "rtDW.pcpbmwodyl" , "rtDW.dm5weww2p4" ,
"rtDW.dksjzo35tz" , "rtDW.ns1e41noub" , "rtDW.aocltagyhy" , "rtDW.equyrom4ri"
, "rtDW.dch3ldlezc" , "rtDW.ls4rap0rxz" , "rtDW.jrje5czue4" ,
"rtDW.of1zesxmyr" , "rtDW.kvwf4z4tdc" , "rtDW.mm2cbalfqe" , "rtDW.covkckaqzy"
, "rtDW.lmpd4xicsv" , "rtDW.azd1nscsvg" , "rtDW.fbqsbjctwt" ,
"rtDW.iuikqqfh00" , "rtDW.biw5aqxbfw" , "rtDW.lq4msaiq1a" , "rtDW.nibf5v1aip"
, "rtDW.j1qmyowelr" , "rtDW.p020cbzauu" , "rtDW.k3xlnbd1ms" ,
"rtDW.fqkbge1awt" , "rtDW.jvkjpo0c5r" , "rtDW.ak2jmb5qhb" , "rtDW.mhhphxgwzy"
, "rtDW.ofz1xq2j1b" , "rtDW.h14we4z1mf" , "rtDW.b2lamlqnub" ,
"rtDW.ludu3yc2dq" , "rtDW.fiifseybg4" , "rtDW.hylkho2gi3" , "rtDW.a5szsiglx3"
, "rtDW.d4lombes4u" , "rtDW.flmb0z2zov" , "rtDW.ep5lb2uepv" ,
"rtDW.exlre3bg5r" , "rtDW.lmahjmhysf" , "rtDW.gdnwvot3yi" , } ; mxArray *
rtdwData = mxCreateStructMatrix ( 1 , 1 , 40 , rtdwDataFieldNames ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW .
pcpbmwodyl ) , sizeof ( rtDW . pcpbmwodyl ) ) ; mr_mfbase_cacheDataAsMxArray
( rtdwData , 0 , 1 , ( const void * ) & ( rtDW . dm5weww2p4 ) , sizeof ( rtDW
. dm5weww2p4 ) ) ; mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const
void * ) & ( rtDW . dksjzo35tz ) , sizeof ( rtDW . dksjzo35tz ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & ( rtDW .
ns1e41noub ) , sizeof ( rtDW . ns1e41noub ) ) ; mr_mfbase_cacheDataAsMxArray
( rtdwData , 0 , 4 , ( const void * ) & ( rtDW . aocltagyhy ) , sizeof ( rtDW
. aocltagyhy ) ) ; mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const
void * ) & ( rtDW . equyrom4ri ) , sizeof ( rtDW . equyrom4ri ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & ( rtDW .
dch3ldlezc ) , sizeof ( rtDW . dch3ldlezc ) ) ; mr_mfbase_cacheDataAsMxArray
( rtdwData , 0 , 7 , ( const void * ) & ( rtDW . ls4rap0rxz ) , sizeof ( rtDW
. ls4rap0rxz ) ) ; mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const
void * ) & ( rtDW . jrje5czue4 ) , sizeof ( rtDW . jrje5czue4 ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & ( rtDW .
of1zesxmyr ) , sizeof ( rtDW . of1zesxmyr ) ) ; mr_mfbase_cacheDataAsMxArray
( rtdwData , 0 , 10 , ( const void * ) & ( rtDW . kvwf4z4tdc ) , sizeof (
rtDW . kvwf4z4tdc ) ) ; mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 11 , (
const void * ) & ( rtDW . mm2cbalfqe ) , sizeof ( rtDW . mm2cbalfqe ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) & ( rtDW
. covkckaqzy ) , sizeof ( rtDW . covkckaqzy ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) & ( rtDW
. lmpd4xicsv ) , sizeof ( rtDW . lmpd4xicsv ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) & ( rtDW
. azd1nscsvg ) , sizeof ( rtDW . azd1nscsvg ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) & ( rtDW
. fbqsbjctwt ) , sizeof ( rtDW . fbqsbjctwt ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) & ( rtDW
. iuikqqfh00 ) , sizeof ( rtDW . iuikqqfh00 ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) & ( rtDW
. biw5aqxbfw ) , sizeof ( rtDW . biw5aqxbfw ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) & ( rtDW
. lq4msaiq1a ) , sizeof ( rtDW . lq4msaiq1a ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) & ( rtDW
. nibf5v1aip ) , sizeof ( rtDW . nibf5v1aip ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) & ( rtDW
. j1qmyowelr ) , sizeof ( rtDW . j1qmyowelr ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) & ( rtDW
. p020cbzauu ) , sizeof ( rtDW . p020cbzauu ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) & ( rtDW
. k3xlnbd1ms ) , sizeof ( rtDW . k3xlnbd1ms ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) & ( rtDW
. fqkbge1awt ) , sizeof ( rtDW . fqkbge1awt ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) & ( rtDW
. jvkjpo0c5r ) , sizeof ( rtDW . jvkjpo0c5r ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) & ( rtDW
. ak2jmb5qhb ) , sizeof ( rtDW . ak2jmb5qhb ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) & ( rtDW
. mhhphxgwzy ) , sizeof ( rtDW . mhhphxgwzy ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) & ( rtDW
. ofz1xq2j1b ) , sizeof ( rtDW . ofz1xq2j1b ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) & ( rtDW
. h14we4z1mf ) , sizeof ( rtDW . h14we4z1mf ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) & ( rtDW
. b2lamlqnub ) , sizeof ( rtDW . b2lamlqnub ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) & ( rtDW
. ludu3yc2dq ) , sizeof ( rtDW . ludu3yc2dq ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) & ( rtDW
. fiifseybg4 ) , sizeof ( rtDW . fiifseybg4 ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) & ( rtDW
. hylkho2gi3 ) , sizeof ( rtDW . hylkho2gi3 ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) & ( rtDW
. a5szsiglx3 ) , sizeof ( rtDW . a5szsiglx3 ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) & ( rtDW
. d4lombes4u ) , sizeof ( rtDW . d4lombes4u ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * ) & ( rtDW
. flmb0z2zov ) , sizeof ( rtDW . flmb0z2zov ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void * ) & ( rtDW
. ep5lb2uepv ) , sizeof ( rtDW . ep5lb2uepv ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void * ) & ( rtDW
. exlre3bg5r ) , sizeof ( rtDW . exlre3bg5r ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void * ) & ( rtDW
. lmahjmhysf ) , sizeof ( rtDW . lmahjmhysf ) ) ;
mr_mfbase_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void * ) & ( rtDW
. gdnwvot3yi ) , sizeof ( rtDW . gdnwvot3yi ) ) ; mxSetFieldByNumber ( ssDW ,
0 , 1 , rtdwData ) ; } return ssDW ; } void mr_mfbase_SetDWork ( const
mxArray * ssDW ) { ( void ) ssDW ; mr_mfbase_restoreDataFromMxArray ( ( void
* ) & ( rtB ) , ssDW , 0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData
= mxGetFieldByNumber ( ssDW , 0 , 1 ) ; mr_mfbase_restoreDataFromMxArray ( (
void * ) & ( rtDW . pcpbmwodyl ) , rtdwData , 0 , 0 , sizeof ( rtDW .
pcpbmwodyl ) ) ; mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dm5weww2p4 ) , rtdwData , 0 , 1 , sizeof ( rtDW . dm5weww2p4 ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . dksjzo35tz ) ,
rtdwData , 0 , 2 , sizeof ( rtDW . dksjzo35tz ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . ns1e41noub ) ,
rtdwData , 0 , 3 , sizeof ( rtDW . ns1e41noub ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . aocltagyhy ) ,
rtdwData , 0 , 4 , sizeof ( rtDW . aocltagyhy ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . equyrom4ri ) ,
rtdwData , 0 , 5 , sizeof ( rtDW . equyrom4ri ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . dch3ldlezc ) ,
rtdwData , 0 , 6 , sizeof ( rtDW . dch3ldlezc ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . ls4rap0rxz ) ,
rtdwData , 0 , 7 , sizeof ( rtDW . ls4rap0rxz ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . jrje5czue4 ) ,
rtdwData , 0 , 8 , sizeof ( rtDW . jrje5czue4 ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . of1zesxmyr ) ,
rtdwData , 0 , 9 , sizeof ( rtDW . of1zesxmyr ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . kvwf4z4tdc ) ,
rtdwData , 0 , 10 , sizeof ( rtDW . kvwf4z4tdc ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . mm2cbalfqe ) ,
rtdwData , 0 , 11 , sizeof ( rtDW . mm2cbalfqe ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . covkckaqzy ) ,
rtdwData , 0 , 12 , sizeof ( rtDW . covkckaqzy ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . lmpd4xicsv ) ,
rtdwData , 0 , 13 , sizeof ( rtDW . lmpd4xicsv ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . azd1nscsvg ) ,
rtdwData , 0 , 14 , sizeof ( rtDW . azd1nscsvg ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . fbqsbjctwt ) ,
rtdwData , 0 , 15 , sizeof ( rtDW . fbqsbjctwt ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . iuikqqfh00 ) ,
rtdwData , 0 , 16 , sizeof ( rtDW . iuikqqfh00 ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . biw5aqxbfw ) ,
rtdwData , 0 , 17 , sizeof ( rtDW . biw5aqxbfw ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . lq4msaiq1a ) ,
rtdwData , 0 , 18 , sizeof ( rtDW . lq4msaiq1a ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . nibf5v1aip ) ,
rtdwData , 0 , 19 , sizeof ( rtDW . nibf5v1aip ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . j1qmyowelr ) ,
rtdwData , 0 , 20 , sizeof ( rtDW . j1qmyowelr ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . p020cbzauu ) ,
rtdwData , 0 , 21 , sizeof ( rtDW . p020cbzauu ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . k3xlnbd1ms ) ,
rtdwData , 0 , 22 , sizeof ( rtDW . k3xlnbd1ms ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . fqkbge1awt ) ,
rtdwData , 0 , 23 , sizeof ( rtDW . fqkbge1awt ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . jvkjpo0c5r ) ,
rtdwData , 0 , 24 , sizeof ( rtDW . jvkjpo0c5r ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . ak2jmb5qhb ) ,
rtdwData , 0 , 25 , sizeof ( rtDW . ak2jmb5qhb ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . mhhphxgwzy ) ,
rtdwData , 0 , 26 , sizeof ( rtDW . mhhphxgwzy ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . ofz1xq2j1b ) ,
rtdwData , 0 , 27 , sizeof ( rtDW . ofz1xq2j1b ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . h14we4z1mf ) ,
rtdwData , 0 , 28 , sizeof ( rtDW . h14we4z1mf ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . b2lamlqnub ) ,
rtdwData , 0 , 29 , sizeof ( rtDW . b2lamlqnub ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . ludu3yc2dq ) ,
rtdwData , 0 , 30 , sizeof ( rtDW . ludu3yc2dq ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . fiifseybg4 ) ,
rtdwData , 0 , 31 , sizeof ( rtDW . fiifseybg4 ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . hylkho2gi3 ) ,
rtdwData , 0 , 32 , sizeof ( rtDW . hylkho2gi3 ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . a5szsiglx3 ) ,
rtdwData , 0 , 33 , sizeof ( rtDW . a5szsiglx3 ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . d4lombes4u ) ,
rtdwData , 0 , 34 , sizeof ( rtDW . d4lombes4u ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . flmb0z2zov ) ,
rtdwData , 0 , 35 , sizeof ( rtDW . flmb0z2zov ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . ep5lb2uepv ) ,
rtdwData , 0 , 36 , sizeof ( rtDW . ep5lb2uepv ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . exlre3bg5r ) ,
rtdwData , 0 , 37 , sizeof ( rtDW . exlre3bg5r ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . lmahjmhysf ) ,
rtdwData , 0 , 38 , sizeof ( rtDW . lmahjmhysf ) ) ;
mr_mfbase_restoreDataFromMxArray ( ( void * ) & ( rtDW . gdnwvot3yi ) ,
rtdwData , 0 , 39 , sizeof ( rtDW . gdnwvot3yi ) ) ; } } mxArray *
mr_mfbase_GetSimStateDisallowedBlocks ( ) { return NULL ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 67 ) ;
ssSetNumBlockIO ( rtS , 18 ) ; ssSetNumBlockParams ( rtS , 542019 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 6.25E-7 ) ;
ssSetSampleTime ( rtS , 1 , 6.25E-6 ) ; ssSetSampleTime ( rtS , 2 , 6.25E-5 )
; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1390277494U ) ; ssSetChecksumVal ( rtS , 1 ,
1537201641U ) ; ssSetChecksumVal ( rtS , 2 , 3250638661U ) ; ssSetChecksumVal
( rtS , 3 , 178444161U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 16 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } mfbase_InitializeDataMapInfo ( )
; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"mfbase" ) ; ssSetPath ( rtS , "mfbase" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 8.0 ) ; ssSetStepSize ( rtS , 6.25E-7 ) ;
ssSetFixedStepSize ( rtS , 6.25E-7 ) ; { static RTWLogInfo rt_DataLoggingInfo
; rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 50 , 1
, 544 , 1 , 1 , 12 , 1 , 1 , 1774 , 1774 , 1 , 50 , 100 , 1 , 1 , 1774 , 1 ,
1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
1 } ; static int_T rt_LoggedStateDimensions [ ] = { 50 , 1 , 544 , 1 , 1 , 12
, 1 , 1 , 1774 , 1774 , 1 , 50 , 100 , 1 , 1 , 1774 , 1 , 1 , 1 , 1 , 1 , 1 }
; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_INT32 , SS_INT32 , SS_INT32 , SS_INT32 , SS_INT32
, SS_INT32 } ; static int_T rt_LoggedStateComplexSignals [ ] = { 1 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ;
static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) } ; static const char_T * rt_LoggedStateLabels [ ] = { "IC_BUFF" ,
"Buffer" , "states" , "Buffer" , "states" , "FILT_STATES" , "DSTATE" ,
"AccFreqNorm" , "states" , "states" , "DSTATE" , "IC_BUFF" , "states" ,
"DSTATE" , "states" , "states" , "circBuf" , "circBuf" , "circBuf" ,
"CIRC_BUF_IDX" , "CIRC_BUF_IDX" , "circBuf" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"mfbase/FM\nDemodulator\nPassband/Subsystem/Delay" ,
"mfbase/Conditionnement/Upsample" ,
"mfbase/Conditionnement/Digital\nFilter Design/Digital Filter" ,
"mfbase/Upsample" , "mfbase/Filtre accentuation/Discrete Filter" ,
"mfbase/Digital\nFilter Design/Digital Filter" , "mfbase/VCO/Delay" ,
"mfbase/Sine Wave" , "mfbase/Passe-Bande T/Digital Filter" ,
"mfbase/Passe-Bande R/Digital Filter" ,
"mfbase/FM\nDemodulator\nPassband/Time and \nSample time/Difference/UD" ,
"mfbase/FM\nDemodulator\nPassband/Analytic Signal/Delay" ,
"mfbase/FM\nDemodulator\nPassband/Analytic Signal/Digital Filter" ,
"mfbase/FM\nDemodulator\nPassband/Subsystem1/Difference/UD" ,
"mfbase/Filtre désaccentuation/Discrete Filter" ,
"mfbase/Digital\nFilter Design1/Digital Filter" ,
"mfbase/Conditionnement/Digital\nFilter Design/Digital Filter" ,
"mfbase/Passe-Bande T/Digital Filter" , "mfbase/Passe-Bande R/Digital Filter"
, "mfbase/FM\nDemodulator\nPassband/Subsystem/Delay" ,
"mfbase/FM\nDemodulator\nPassband/Analytic Signal/Delay" ,
"mfbase/Digital\nFilter Design1/Digital Filter" } ; static const char_T *
rt_LoggedStateNames [ ] = { "IC_BUFF" , "Buffer" , "states" , "Buffer" ,
"states" , "FILT_STATES" , "DSTATE" , "AccFreqNorm" , "states" , "states" ,
"DSTATE" , "IC_BUFF" , "states" , "DSTATE" , "states" , "states" , "circBuf"
, "circBuf" , "circBuf" , "CIRC_BUF_IDX" , "CIRC_BUF_IDX" , "circBuf" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 ,
0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 }
, { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 ,
SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 ,
0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 }
} ; static int_T rt_LoggedStateIdxList [ ] = { 30 , 1 , 2 , 3 , 4 , 5 , 6 , 7
, 8 , 9 , 10 , 31 , 12 , 13 , 14 , 15 , 27 , 28 , 29 , 0 , 11 , 32 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 22 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 22 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) rtDW . pcpbmwodyl ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . dm5weww2p4 ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) rtDW . dksjzo35tz ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtDW . ns1e41noub ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . aocltagyhy ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) rtDW . equyrom4ri ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtDW . dch3ldlezc ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtDW . ls4rap0rxz ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) rtDW . jrje5czue4 ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) rtDW . of1zesxmyr ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtDW . kvwf4z4tdc ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) rtDW . mm2cbalfqe ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) rtDW . covkckaqzy ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtDW . lmpd4xicsv ;
rt_LoggedStateSignalPtrs [ 14 ] = ( void * ) & rtDW . azd1nscsvg ;
rt_LoggedStateSignalPtrs [ 15 ] = ( void * ) rtDW . fbqsbjctwt ;
rt_LoggedStateSignalPtrs [ 16 ] = ( void * ) & rtDW . k3xlnbd1ms ;
rt_LoggedStateSignalPtrs [ 17 ] = ( void * ) & rtDW . fqkbge1awt ;
rt_LoggedStateSignalPtrs [ 18 ] = ( void * ) & rtDW . jvkjpo0c5r ;
rt_LoggedStateSignalPtrs [ 19 ] = ( void * ) & rtDW . ak2jmb5qhb ;
rt_LoggedStateSignalPtrs [ 20 ] = ( void * ) & rtDW . mhhphxgwzy ;
rt_LoggedStateSignalPtrs [ 21 ] = ( void * ) & rtDW . ofz1xq2j1b ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver ( rtS
, 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
1390277494U ) ; ssSetChecksumVal ( rtS , 1 , 1537201641U ) ; ssSetChecksumVal
( rtS , 2 , 3250638661U ) ; ssSetChecksumVal ( rtS , 3 , 178444161U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 4 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_mfbase_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS
, mr_mfbase_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_mfbase_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if (
ssGetErrorStatus ( rtS ) ) { return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
