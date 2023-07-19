
%% Multiplexage Analogique

clc
close all

load xanalogique.mat
type = 1;

offseta = 33*10^3;
fI = 1.36*10^6+n*offseta;
fc = 1.36*10^6;
fba = 1.36*10^6-340*10^3-4*offseta;


fp1 = 1.36*10^6-150000;
fp2 = 1.36*10^6+150000;

fimage = fba-340000;
fc1 = fimage-150000;
fc2 = fimage+150000;


xx = audioplayer ( xanalogique, 30000) ;
yn = audioplayer ( out.znanalogique, 30000) ;
ym = audioplayer ( out.zmanalogique, 30000) ;

%% Multiplexage Numérique

clc
close all

load xnumerique.mat
type = 0;
n = 0;
m = 1;


offsetn = 90*10^3;
%fI = 1.36*10^6+n*offsetn;
%fc = 1.36*10^6;
fbn = (1.36*10^6)-(340*10^3)-offsetn;

xx = audioplayer ( xnumerique, 30000) ;
yn = audioplayer ( out.znnumerique, 30000) ;
ym = audioplayer ( out.zmnumerique, 30000) ;

%play(xx)



