//
// Created by anis on 7/31/19.
// 

#ifndef INF155_20193_TP3_MOD_DESSIN_H
#define INF155_20193_TP3_MOD_DESSIN_H

#include <stdint.h>
#include "mod_geo.h"
#include "mod_vehicule.h"
#include "winBGIm.h"
#define _USE_MATH_DEFINES
#include <math.h>

//Screen dimension constants
#define LARGEUR_ECRAN_PX 800
#define HAUTEUR_ECRAN_PX 800
#define LARGEUR_VISIBLE_VOIE_PX 20
#define EPAISSEUR_BORDURE_PX 5


extern const t_point CENTRE ;
typedef struct t_vehicule t_vehicule;

/*
DESSINER_ECRAN
Dessine la route à l'écran ayant le nombre de voies spécifié. 
ENTREE: 
nb_voies (entier): Le nombre de voies à afficher. 
SORTIE: Aucune
*/
void dessiner_ecran(int nb_voies);


/*
DESSINER_VEHICULE
Desssine un véhicule à l'écran sur la voie spécifiée. 
ENTREES:
vehicule: Référence vers le véhicule à afficher.
voie: La voie sur laquelle le véhicule sera affiché
centre: Coordonées du centre de la route.
*/
void dessiner_vehicule(t_vehicule *vehicule, int voie, t_point centre);

#endif //INF155_20193_TP3_MOD_DESSIN_H
