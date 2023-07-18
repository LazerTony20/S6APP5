% APP5 S6 GE - E2023
% Anthony Royer - ROYA2019
% Problématique - Système Numerique
% 14 juillet 2023

% Péparatifs
close all
clear
clc
opengl software

% Contrôles
RunSim = 1;
Bruit = 1;          % Utiliser le bruit ou non (1 = oui)
Constellation = 0;  % Faire la constellation
%% Variables de simulation
% Les variables user et mod doivent être initialisées avant
% de simuler via Matlab. 
% La variable user est l'identifiant utilisateur (sur 4 bits, donc valeur de 0 à 15).
% La variable mod est le type de modulation (sur 3 bits, donc valeur de 0 à 7 mais 
% seulement 0 à 3 implémentés pour le moment). Pour mod, 0=BPSK, 1=QPSK, 2=8-PSK et 3=16-QAM.
% Ces variables sont automatiquement incluses dans le préambule du paquet.
user = 1;   % Valeur de 0 à 15
mod = 1;    % Type de modulation

%% Calculs de mes valeurs pour QPSK (Simulation)
disp('================================================================')
disp('==== Calcul de mes valeurs pour le QPSK pour simulation (G) ====')
disp('================================================================')
X_pre = 2.3;
Ps = 10;
Rs = 85000;
Bt = 95000;
Fpc = 1.36e6;
Larg_bloc = 300e3;

% Calculs
RSBi_pre = (X_pre.^2)*(Rs/Bt);
DSP_pre = (Ps/RSBi_pre)*(1/(Bt*2));
% Ep_pre = (X_pre.^2)*DSP_pre
% Pt = Ep_pre/Rs
freq_ech_sec_bruit = 2*(Fpc+(Larg_bloc./2));
disp(['Freq Ech (section avec bruit) = ', num2str(freq_ech_sec_bruit), ' Hz'])
disp(['RSBi = ',num2str(10*log10(RSBi_pre)), ' dB'])
disp(['No/2 = ', num2str(DSP_pre*1000000), ' µW/Hz'])
disp(['Puissance du bruit (variance) theorique = ', num2str(DSP_pre*freq_ech_sec_bruit), ' W'])
disp(['Upsample = ', num2str(freq_ech_sec_bruit/85000), ' --> Arrondi à la hausse à 40'])
freq_ech_sec_bruit = 3.4e6; % Valeur utilisée
variance_bruit = DSP_pre*freq_ech_sec_bruit;
disp(['Puissance du bruit (variance) = ', num2str(variance_bruit), ' W'])
%% Mise en place de l'environnement de la simulation
CalculREP
load sons.mat

%% Exécution de la simulation
if RunSim == 1
    set_param('genpaquet2/Identifiant utilisateur', 'Value', num2str(user))
    set_param('genpaquet2/Identifiant_mod', 'Value', num2str(mod))
    set_param('genpaquet2/Use_Bruit', 'Value', num2str(Bruit))
    out = sim('genpaquet2');
    clc
    disp('Simulation Fished...')
    disp(' ')
    if Constellation == 1
        figure('Name','Constellation')
        hold on
        plot(X(40:end), Y(40:end), 'o')
        title('Constellation')
        hold off
    end
end

