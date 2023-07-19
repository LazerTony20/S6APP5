Ns = 40; % Nombre d'échantillons par symbole

fa = [1 0 1 0 1 1 0 0 1 1 1 1 1]';  % séquence de Barker inversée

% Les deux lignes suivantes insèrent le nombre approprié de zéros
% entre chaque paire d'impulsions.
% Dans exemple 4, il y a 10 échantillons par symbole.

a = (fa.*2-1).*[1 zeros(1,Ns-1)]; 
rep = reshape(a', 13*Ns, 1)';
