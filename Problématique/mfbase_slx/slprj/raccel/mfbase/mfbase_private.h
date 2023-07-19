#ifndef RTW_HEADER_mfbase_private_h_
#define RTW_HEADER_mfbase_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#include "dsp_rt.h"
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)   (((v1)==(v2))?((double)(v1)):  (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?   muDoubleScalarFloor((v) + 0.5) :   muDoubleScalarCeil((v) - 0.5) )
#endif
extern void RandSrcInitState_U_64 ( const uint32_T seed [ ] , real_T state [
] , int32_T nChans ) ; extern void RandSrc_U_D ( real_T y [ ] , const real_T
minVec [ ] , int32_T minLen , const real_T maxVec [ ] , int32_T maxLen ,
real_T state [ ] , int32_T nChans , int32_T nSamps ) ; extern void
RandSrcCreateSeeds_64 ( uint32_T initSeed , uint32_T seedArray [ ] , int32_T
numSeeds ) ; extern void RandSrcInitState_GZ ( const uint32_T seed [ ] ,
uint32_T state [ ] , int32_T nChans ) ; extern void RandSrc_GZ_D ( real_T y [
] , const real_T mean [ ] , int32_T meanLen , const real_T xstd [ ] , int32_T
xstdLen , uint32_T state [ ] , int32_T nChans , int32_T nSamps ) ;
#if defined(MULTITASKING)
#error Model (mfbase) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
