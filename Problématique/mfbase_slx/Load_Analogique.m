% APP5 S6 GE - E2023
% Anthony Royer - ROYA2019
% Problématique - Système Analogique
% 14 juillet 2023

% Péparatifs
close all
clear
clc
opengl software

% Contrôles
RunSim = 1;
Use_acc = 0;
Use_noise = 0;
Auto_Find_Transmit_Gain = 0;    % Trouver automatiquement le gain de transmission a utiliser
Calcul_RSB = 1;                 % Mode calcul RSB ou simulation simple

% Variables
Gain_Trans = sqrt(10/0.126459854740914);

%% Mise en place de l'environnement de la simulation
load sons.mat
if RunSim == 1
    if Auto_Find_Transmit_Gain == 1
        Use_acc = 0;
        Use_noise = 0;
        Gain_Trans = 1;
        out = sim('mfbase');
        PsGu = sum(out.Pr.^2)/length(out.Pr);
        disp(['La valeur a mettre dans le gain de transmission ou A = sqrt(10/x) avec x = ', num2str(PsGu), 'W'])
        Gain_Trans = sqrt(10/PsGu);
    end
    if Calcul_RSB == 1
        %=============================
        % Sans Acc/desacc (sans bruit)
        %=============================
        Use_acc = 0;
        Use_noise = 0;
        out = sim('mfbase');
        Ps = sum(out.Pr.^2)/length(out.Pr);
        
        PS1 = sum(out.Sortie2(4000:end).^2)/length(out.Sortie2(4000:end));
        Pso = sum(out.Sortie(4000:end).^2)/length(out.Sortie(4000:end));
        disp('Simulation (PS) Fished...')
        disp(['Ps = ', num2str(Ps), ' W'])
        disp(['Ps = ', num2str(10*log10(Ps)), ' dBW'])
        disp(['Pso = ', num2str(10*log10(Pso)), ' dBW'])
        %=============================
        % Sans Acc/desacc (avec bruit)
        %=============================
        Use_acc = 0;
        Use_noise = 1;
        out = sim('mfbase');
        Psb = sum(out.Pr.^2)/length(out.Pr);
        
        PS2 = sum(out.Sortie2(4000:end).^2)/length(out.Sortie2(4000:end));
        Psbo = sum(out.Sortie(4000:end).^2)/length(out.Sortie(4000:end));
        disp('Simulation (PSb) Fished...')
        disp(['Psb = ', num2str(10*log10(Psb)), ' dBW'])
        disp(['Psbo = ', num2str(10*log10(Psbo)), ' dBW'])
        %=============================
        % Avec Acc/desacc (sans bruit)
        %=============================
        Use_acc = 1;
        Use_noise = 0;
        out = sim('mfbase');
        Ps_acc = sum(out.Pr.^2)/length(out.Pr);
        
        PS3 = sum(out.Sortie2(4000:end).^2)/length(out.Sortie2(4000:end));
        Pso_acc = sum(out.Sortie(4000:end).^2)/length(out.Sortie(4000:end));
        disp('Simulation (PS avec Acc/desacc) Fished...')
        disp(['Ps_acc = ', num2str(10*log10(Ps_acc)), ' dBW'])
        disp(['Pso_acc = ', num2str(10*log10(Pso_acc)), ' dBW'])
        %=============================
        % Avec Acc/desacc (avec bruit)
        %=============================
        Use_acc = 1;
        Use_noise = 1;
        out = sim('mfbase');
        Psb_acc = sum(out.Pr.^2)/length(out.Pr);
        
        PS4 = sum(out.Sortie2(4000:end).^2)/length(out.Sortie2(4000:end));
        Psbo_acc = sum(out.Sortie(4000:end).^2)/length(out.Sortie(4000:end));
        disp('Simulation (PSb (bruit) avec Acc/desacc) Fished...')
        disp(['Psb_acc = ', num2str(10*log10(Psb_acc)), ' dBW'])
        disp(['Psbo_acc = ', num2str(10*log10(Psbo_acc)), ' dBW'])
        %Calculs des RSBi et RSBo
        RSBi_SA = Ps/(Psb-Ps);
        RSBi_AA = Ps/(Psb_acc-Ps);
%         RSBo_SA = Pso/(Psbo-Pso);
%         RSBo_AA = Pso_acc/(Psbo_acc-Pso_acc);
        Beta = 57/18;
        Pm = 10.5397e-3;
        RSBo_SA = RSBi_SA*6*(Beta.^2)*(Beta+1)*Pm;
        RSBo_AA = RSBi_AA*6*(Beta.^2)*(Beta+1)*Pm;
        % Affichage des RSBo
        disp(['RSBi (sans accentuation/désaccentuation) = ', num2str(10*log10(RSBi_SA)),' dB'])
        disp(['RSBi (avec accentuation/désaccentuation) = ', num2str(10*log10(RSBi_AA)),' dB'])
        disp(['RSBo (sans accentuation/désaccentuation) = ', num2str(10*log10(RSBo_SA)),' dB'])
        disp(['RSBo (avec accentuation/désaccentuation) = ', num2str(10*log10(RSBo_AA)),' dB'])
    else
        out = sim('mfbase');
        clc
        disp('Simulation Fished...')
        figure('Name','Signaux Entrants et Sortants')
        hold on
        plot(Sonm16(4000:end,2))
        plot(out.Sortie(4000:end))
        legend('Entrée','Sortie')
        hold off
        disp(' ')
    end
end

