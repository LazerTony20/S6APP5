  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtP.Gain_Trans
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Use_acc
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Use_noise
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.SineWave_Amplitude
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.FMDemodulatorPassband_Fc
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.SineWave_Frequency
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.Difference_ICPrevInput
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.Difference_ICPrevInput_dxjkj5p3um
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.FMDemodulatorPassband_Kc
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.BruitGaussienavecAccdesacc_MeanVal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.BruitGaussienAdditif_MeanVal
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.SineWave_Phase
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtP.NSampleEnable_ActiveLevel
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.FMDemodulatorPassband_Ho
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% rtP.Gain3_Gain
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Switch_Threshold
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.FromWorkspace1_Time0
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.FromWorkspace1_Data0
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 140003;
	
	  ;% rtP.FromWorkspace2_Time0
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 280004;
	
	  ;% rtP.FromWorkspace2_Data0
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 408004;
	
	  ;% rtP.DigitalFilter_InitialStates
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 536004;
	
	  ;% rtP.DigitalFilter_Coefficients
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 536005;
	
	  ;% rtP.DiscreteFilter_NumCoef
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 536550;
	
	  ;% rtP.DiscreteFilter_DenCoef
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 536552;
	
	  ;% rtP.DiscreteFilter_InitialStates
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 536554;
	
	  ;% rtP.Switch1_Threshold
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 536555;
	
	  ;% rtP.Gain3_Gain_exqztjtlsw
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 536556;
	
	  ;% rtP.Delay_InitialCondition
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 536557;
	
	  ;% rtP.Gain_Gain
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 536558;
	
	  ;% rtP.DigitalFilter_InitialStates_bkk5sluujk
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 536559;
	
	  ;% rtP.DigitalFilter_Coefficients_i4kbkanqgr
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 536560;
	
	  ;% rtP.BruitGaussienavecAccdesacc_VarianceRTP
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 538335;
	
	  ;% rtP.BruitGaussienAdditif_VarianceRTP
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 538336;
	
	  ;% rtP.Switch2_Threshold
	  section.data(20).logicalSrcIdx = 33;
	  section.data(20).dtTransOffset = 538337;
	
	  ;% rtP.DigitalFilter_InitialStates_lrzr4u3uql
	  section.data(21).logicalSrcIdx = 34;
	  section.data(21).dtTransOffset = 538338;
	
	  ;% rtP.DigitalFilter_Coefficients_ktr5wnr0zq
	  section.data(22).logicalSrcIdx = 35;
	  section.data(22).dtTransOffset = 538339;
	
	  ;% rtP.DigitalFilter_InitialStates_frg2cb2ftf
	  section.data(23).logicalSrcIdx = 36;
	  section.data(23).dtTransOffset = 540114;
	
	  ;% rtP.DigitalFilter_Coefficients_ip34inopza
	  section.data(24).logicalSrcIdx = 37;
	  section.data(24).dtTransOffset = 540115;
	
	  ;% rtP.DiscreteFilter_NumCoef_is5dyfvkwv
	  section.data(25).logicalSrcIdx = 38;
	  section.data(25).dtTransOffset = 540216;
	
	  ;% rtP.DiscreteFilter_DenCoef_c5me0iwyqv
	  section.data(26).logicalSrcIdx = 39;
	  section.data(26).dtTransOffset = 540218;
	
	  ;% rtP.DiscreteFilter_InitialStates_l4qwclyke5
	  section.data(27).logicalSrcIdx = 40;
	  section.data(27).dtTransOffset = 540220;
	
	  ;% rtP.Switch3_Threshold
	  section.data(28).logicalSrcIdx = 41;
	  section.data(28).dtTransOffset = 540221;
	
	  ;% rtP.DigitalFilter_InitialStates_hneh2bcd32
	  section.data(29).logicalSrcIdx = 42;
	  section.data(29).dtTransOffset = 540222;
	
	  ;% rtP.DigitalFilter_Coefficients_lkgbigm1d0
	  section.data(30).logicalSrcIdx = 43;
	  section.data(30).dtTransOffset = 540223;
	
	  ;% rtP.Constant1_Value
	  section.data(31).logicalSrcIdx = 44;
	  section.data(31).dtTransOffset = 541998;
	
	  ;% rtP.Constant_Value
	  section.data(32).logicalSrcIdx = 45;
	  section.data(32).dtTransOffset = 541999;
	
	  ;% rtP.Deltaf_Value
	  section.data(33).logicalSrcIdx = 46;
	  section.data(33).dtTransOffset = 542000;
	
	  ;% rtP.Constant_Value_kslaxjeuqc
	  section.data(34).logicalSrcIdx = 47;
	  section.data(34).dtTransOffset = 542001;
	
	  ;% rtP.Constant1_Value_dsqxhplhg3
	  section.data(35).logicalSrcIdx = 48;
	  section.data(35).dtTransOffset = 542002;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtP.ManualSwitch7_CurrentSetting
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.ManualSwitch1_CurrentSetting
	  section.data(2).logicalSrcIdx = 50;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.iylv2nym5g
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 14;
      section.data(14)  = dumData; %prealloc
      
	  ;% rtB.kvqrrj0pzi
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ax4bvnk00p
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.af1inyls4b
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtB.bferk0v2qg
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtB.jb1ivufg2k
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtB.pz5or3grsa
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtB.etpk0jtvcd
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtB.m2wtc0ckk2
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtB.arphqhrt5o
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtB.drxlfcnfp1
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtB.c3x101if1y
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtB.cmi2ww44rt
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtB.b3yqfcq0dq
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtB.dykl1swx0i
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 13;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.iuggdtr2ec
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.pcpbmwodyl
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtDW.dm5weww2p4
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.dksjzo35tz
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ns1e41noub
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 545;
	
	  ;% rtDW.aocltagyhy
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 546;
	
	  ;% rtDW.equyrom4ri
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 547;
	
	  ;% rtDW.dch3ldlezc
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 559;
	
	  ;% rtDW.ls4rap0rxz
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 560;
	
	  ;% rtDW.jrje5czue4
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 561;
	
	  ;% rtDW.of1zesxmyr
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 2335;
	
	  ;% rtDW.kvwf4z4tdc
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 4109;
	
	  ;% rtDW.mm2cbalfqe
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 4110;
	
	  ;% rtDW.covkckaqzy
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 4160;
	
	  ;% rtDW.lmpd4xicsv
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 4260;
	
	  ;% rtDW.azd1nscsvg
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 4261;
	
	  ;% rtDW.fbqsbjctwt
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 4262;
	
	  ;% rtDW.iuikqqfh00
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 6036;
	
	  ;% rtDW.biw5aqxbfw
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 6037;
	
	  ;% rtDW.lq4msaiq1a
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 6043;
	
	  ;% rtDW.nibf5v1aip
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 6044;
	
	  ;% rtDW.j1qmyowelr
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 6045;
	
	  ;% rtDW.p020cbzauu
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 6046;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.fsno0ua31k.TimePtr
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jbo3zfaqcm.TimePtr
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jy4tcp0o45.LoggedData
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.gqufr243mp.LoggedData
	  section.data(4).logicalSrcIdx = 25;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.ndvre5ae41.AQHandles
	  section.data(5).logicalSrcIdx = 26;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% rtDW.k3xlnbd1ms
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.fqkbge1awt
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jvkjpo0c5r
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.ak2jmb5qhb
	  section.data(4).logicalSrcIdx = 30;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.mhhphxgwzy
	  section.data(5).logicalSrcIdx = 31;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDW.ofz1xq2j1b
	  section.data(6).logicalSrcIdx = 32;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDW.h14we4z1mf
	  section.data(7).logicalSrcIdx = 33;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDW.b2lamlqnub
	  section.data(8).logicalSrcIdx = 34;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDW.ludu3yc2dq
	  section.data(9).logicalSrcIdx = 35;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDW.fiifseybg4
	  section.data(10).logicalSrcIdx = 36;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.hylkho2gi3
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.a5szsiglx3
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.d4lombes4u
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtDW.flmb0z2zov
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtDW.ep5lb2uepv
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.exlre3bg5r.PrevIndex
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lmahjmhysf.PrevIndex
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.gdnwvot3yi
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1390277494;
  targMap.checksum1 = 1537201641;
  targMap.checksum2 = 3250638661;
  targMap.checksum3 = 178444161;

