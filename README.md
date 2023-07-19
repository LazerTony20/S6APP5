# Système efficace de communication multi-usagers
Votre firme de génie-conseil, Ultracom, doit concevoir un système de communication sans fil
multi-usager pour desservir une région éloignée. Le système s’apparentera à un système de
téléphonie cellulaire de première ou deuxième génération (bien qu’il n’y aura qu’une seule
tour et donc une seule cellule) en ce sens qu’il ne servira qu’à la transmission de la voix.
Pour communiquer par voie hertzienne de manière efficace, il sera nécessaire de transmettre
un signal en bande passante obtenu par modulation d’une porteuse dont la fréquence est
suffisamment élevée. Deux options devront être explorées, soit une approche de communication analogique 
et une approche de communication numérique. Pour l’option analogique,
la modulation de fréquence (MF) sera privilégiée. Cette option sera rendue plus attrayante
que dans votre contrat précédent par l’usage d’une largeur de bande plus grande (30 kHz au
lieu de 13 kHz) et de techniques de modulation et de démodulation différentes. Pour l’option
numérique, divers types de modulation numérique seront exploités avec différentes tailles de
constellation M. Le système permettra de choisir une valeur de M élevée lorsque le rapport
signal à bruit est suffisamment grand et vice-versa. Le nombre de conversations pouvant être
transmis à l’intérieur d’une largeur de bande donnée sera donc variable en fonction de la
valeur de M choisie.

Les signaux de voix à transmettre avec le système seront de qualité “ligne téléphonique.”
De plus, pour cette étude préliminaire, on développera uniquement la voie montante, soit
la chaîne de communication allant d’un téléphone sans fils individuel (transmetteur) à la
station de base centrale (récepteur) et non le sens inverse. Un bloc de fréquences de 300 kHz
de largeur centré autour de 902 MHz sera réservé pour cette voie montante de manière à
pouvoir supporter plusieurs transmissions ou conversations simultanées.
Pour la solution analogique, le bloc de 300 kHz sera divisé en 9 canaux de 30 kHz en incluant
des bandes de garde de 3 kHz selon la technique de multiplexage en fréquence. Vous devrez
déterminer quel rapport signal sur bruit est nécessaire à l’entrée du récepteur pour que
le rapport signal sur bruit du signal vocal en sortie soit de 30 dB. Au transmetteur, vous
emploierez un modulateur basé sur un oscillateur commandé en tension (OCT). Au récepteur,
une structure de démodulation de type superhétérodyne sera privilégiée avec une fréquence
intermédiaire fI de 340 kHz afin de pouvoir aisément choisir le canal qu’on souhaite recevoir
parmi les 9 possibiltés. Vous serez également amenés à explorer l’application de la technique
d’accentuation de de désaccentuation pour améliorer la qualité d’une communication en MF.

Vous aurez à quantifier cette amélioration en termes de la diminution de puissance qu’elle
rend possible tout en maintenant le RSB cible de 30 dB en sortie.
Pour la solution numérique, le bloc de 300 kHz sera divisé en 3 canaux de 95 kHz avec
des bandes de garde de 5 kHz. En plus de ce multiplexage en fréquence, chaque canal sera
subdivisé en tranches de temps pour effectuer du multiplexage en temps. Ainsi, à l’intérieur
d’une trame de longueur déterminée, on trouvera une suite de plusieurs paquets de données,
chacun correspondant à une conversation. Chaque paquet débutera par un préambule de
20 bits contenant une séquence de synchronisation prédéterminée de 13 bits, un identifiant
d’utilisateur de 4 bits et un identifiant de type de modulation de 3 bits. Le préambule sera
toujours modulé en BPSK à un taux de 85 kbits / sec. Le corps du paquet sera constitué de
128 symboles à un taux de 85 ksymboles / sec qui pourront être modulés selon des types et
des ordres de modulation divers (BPSK, QPSK, QAM-16, 8-PSK), en fonction du rapport
signal sur bruit disponible au récepteur. Un temps de garde minimum équivalent à 2 périodes
de symbole sera réservé entre deux paquets successifs.

Le modulateur au transmetteur devra avoir la flexibilité nécessaire pour supporter tous les
types de modulation prévus et sera basé sur une structure en quadrature. Le récepteur devra
évidemment posséder la même flexibilité et épousera également une structure en quadrature.
Toutefois, cette dernière constituera le deuxième étage d’une architecture superhétérodyne
permettant la sélection du bon canal de 95 kHz (parmi les 3 possibles). En fait, étant donné
les similarités, un récepteur unique pourrait être conçu capable de traiter à la fois le schème
analogique et le schème numérique.

Il vous faudra faire un exercice rigoureux de conception sur papier où chacun des choix
sera fondé sur une analyse mathématique. De manière purement analytique, vous devrez
prédire le RSB en entrée du récepteur nécessaire pour obtenir un RSB de 30 dB en sortie
avec la modulation de fréquence avec et sans accentuation / désaccentuation. Pour l’option
numérique, vous devrez déterminer pour chaque type de modulation proposé quel niveau de
RSB au récepteur est nécessaire pour obtenir un taux d’erreur sur les bits de 10−4
et ce,dans le cas d’une démodulation cohérente et non-cohérente (si applicable). Comme pour les
communications en bande de base, vous devrez choisir un type de filtre au transmetteur et au
récepteur de manière à minimiser la probabilité d’erreur et occuper la plus petite largeur de
bande possible. Vous devrez également déterminer pour chaque type de modulation proposé
combien de conversations simultanées sont possibles sur un canal de 95 kHz en sachant que
chaque transmission vocale de qualité téléphonique nécessite 64 kbits / sec.

Seuls certains aspects de vos designs sur papier devront être validés par simulation. On pourra
utiliser une fréquence porteuse centrale (centre du bloc de 300 kHz décrit) de 1,36 MHz au
lieu de 902 MHz afin de limiter la lourdeur des simulations. Pour la solution analogique, il
vous faudra valider une chaîne complète qui part du signal sonore en entrée et restitue le
signal sonore bruité en sortie. Au transmetteur, vous simulerez la modulation directe via un
oscillateur contrôlé en tension. Au récepteur, vous simulerez un récepteur superhétérodyne
avec un deuxième étage à structure en quadrature et vous validerez la capacité à sélectionner
un canal en fréquence parmi les 9 possibles dans le bloc de 300 kHz. Vous ajusterez la
puissance de transmission et injecterez un bruit blanc dans le canal de manière à obtenir
le RSB en entrée du récepteur prévu selon vos calculs pour atteindre la cible de 30 dB en
sortie. Il vous faudra alors mesurer le RSB en sortie à partir de la simulation. Vous répéterez
l’exercice en ajoutant les opérations d’accentuation et de désaccentuation.
Pour l’option numérique, vous n’aurez à valider qu’un seul des types de modulation retenus
(en plus du BPSK pour le préambule) parmi QPSK, 16-QAM, 8PSK ou autre. Il n’est
pas obligatoire de valider en simulation la réception non-cohérente (qui ne s’applique pas
à tous les types de modulation). Vous aurez à valider en simulation au moins un calcul
de probabilité d’erreur. Toutefois, pour limiter le temps de simulation, vous pouvez pour
ce faire cibler un taux d’erreur plus élevé, par exemple 10−2. Il vous faudra démontrer la
fonctionnalité superhétérodyne permettant de sélectionner un canal de 95 kHz parmi les 3 possibles. 
Il vous faudra également démontrer la capacité à détecter la présence 
d’un paquet à partir de son préambule connu de même que la synchronisation de l’horloge des symboles.

Le client vous informe qu’il est possible de représenter et même de simuler un système de
communication à haute fréquence en faisant abstraction de la porteuse, c’est-à-dire en le
représentant par un système équivalent en bande de base. Un tel modèle fait intervenir des
signaux complexes. Sans utiliser ce modèle équivalent pour vos simulations, il vous demande
toutefois de déterminer quelles caractéristiques statistiques devraient posséder des processus
aléatoires en bande de base x(t) et y(t) pour que le processus aléatoire réel n(t), à moyenne
nulle et à bande étroite centrée sur fc, puisse s’exprimer
n(t) = x(t) cos(2πfct) − y(t) sin(2πfct),
tout en possédant la propriété de stationnarité au sens large 1.
