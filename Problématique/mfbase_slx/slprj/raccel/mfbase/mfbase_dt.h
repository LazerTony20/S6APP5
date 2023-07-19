#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "struct_Coz7I33h7U40qMF2BpcKK" , 14 ,
400 } , { "struct_advsopL1F9Ect2zUPC8Nz" , 15 , 272 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( void * ) , sizeof ( action_T ) , 2
* sizeof ( uint32_T ) , sizeof ( struct_Coz7I33h7U40qMF2BpcKK ) , sizeof (
struct_advsopL1F9Ect2zUPC8Nz ) } ; static const char_T * rtDataTypeNames [ ]
= { "real_T" , "real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" ,
"int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" ,
"action_T" , "timer_uint32_pair_T" , "struct_Coz7I33h7U40qMF2BpcKK" ,
"struct_advsopL1F9Ect2zUPC8Nz" } ; static DataTypeTransition rtBTransitions [
] = { { ( char_T * ) ( & rtB . iylv2nym5g . re ) , 0 , 1 , 2 } , { ( char_T *
) ( & rtB . kvqrrj0pzi ) , 0 , 0 , 14 } , { ( char_T * ) ( & rtB . iuggdtr2ec
) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW . pcpbmwodyl [ 0 ] . re ) , 0 , 1 ,
100 } , { ( char_T * ) ( & rtDW . dm5weww2p4 ) , 0 , 0 , 6047 } , { ( char_T
* ) ( & rtDW . fsno0ua31k . TimePtr ) , 11 , 0 , 5 } , { ( char_T * ) ( &
rtDW . k3xlnbd1ms ) , 6 , 0 , 10 } , { ( char_T * ) ( & rtDW . hylkho2gi3 ) ,
7 , 0 , 7 } , { ( char_T * ) ( & rtDW . exlre3bg5r . PrevIndex ) , 10 , 0 , 2
} , { ( char_T * ) ( & rtDW . gdnwvot3yi ) , 8 , 0 , 1 } } ; static
DataTypeTransitionTable rtBTransTable = { 10U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . Gain_Trans
) , 0 , 0 , 12 } , { ( char_T * ) ( & rtP . NSampleEnable_ActiveLevel ) , 7 ,
0 , 2 } , { ( char_T * ) ( & rtP . Gain3_Gain ) , 0 , 0 , 542003 } , { (
char_T * ) ( & rtP . ManualSwitch7_CurrentSetting ) , 3 , 0 , 2 } } ; static
DataTypeTransitionTable rtPTransTable = { 4U , rtPTransitions } ;
