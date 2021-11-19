#ifndef MOD_GEO_H
#define MOD_GEO_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define GEO_POLYGONE_MAX_PTS 4

//Definit un point dans le plan
typedef struct {
	int x; //abscisse
	int y; //ordonnee//
} t_point;

//Definit un polygone qui est un ensemble de points
typedef struct t_polygone {
	t_point points[GEO_POLYGONE_MAX_PTS]; //Tableau statique de points
	int nb_points; //Nombre de points dans le tableau
} t_polygone;


int geo_ajouter_tab_polygone(t_polygone* poly, t_point pts[], int nb_pts);
/*
Ajoute les nb_pts points se trouvant dans le tableau pts au polygone poly.
Les points sont ajoutes dans le polygone a partir de la position 0.
La fonction renvoie une valeur vraie si tous les points du tableau ont pu
etre ajoutes au polygone, ou valeur fausse sinon.
*/


void geo_rotation_point(t_point* point, double angle);
/*
Recoit une reference vers un point point et un angle angle. La fonction
effectue la rotation du point par rapport a lorigine. En supposant que le
point se trouve aux coordonnees (x,y) et que ses coordonnees apres la
rotation sont (x', y'), la formule permettant de calculer les nouvelles
coordonnees est la suivante :
x' = x.cos(angle) - y.sin(angle)
y' = x.sin(angle) + y.cos(angle)
*/


void geo_init_polygone(t_polygone* poly, int taille); //David
/*Initialise le polygone reçu par référence en lui assignant le nombre de
points définit par la taille reçue.
Si le nombre de points demande excede GEO_POLYGONE_MAX_PTS, vous devez
initialiser le nombre de points du polygone a 0.*/


int geo_ajouter_point_polygone(t_polygone* poly, t_point pt, int position); //David
/*Ajoute le point pt reçu en paramètre au tableau de points du polygone à la
position position. Les positions doivent etre entre 0 et le nombre de points
du polygone - 1. Si une position invalide a ete transmise, il ne faut pas
ajouter le point.
La fonction retourne une valeur vraie si le point a bien ete ajoute, ou une
valeur fausse sinon(position non - valide).*/


void geo_rotation_polygone(t_polygone* poly, double angle);
//Reçoit une référence vers un polygone poly et un angle angle.La fonction
//effectue la rotation du polygone par rapport à l’origine.

#endif
