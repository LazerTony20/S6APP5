Ns = 10; % Nombre d'�chantillons par symbole

fa = [1 0 1 0 1 1 0 0 1 1 1 1 1]';  % s�quence de Barker invers�e

% Les deux lignes suivantes ins�rent le nombre appropri� de z�ros
% entre chaque paire d'impulsions.
% Dans exemple 4, il y a 10 �chantillons par symbole.

a = (fa.*2-1).*[1 zeros(1,Ns-1)]; 
rep = reshape(a', 13*Ns, 1)';
