#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mod_geo.h"
#include "mod_dessin.h"
#include "mod_vehicule.h"
#include "winBGIm.h"
#include "mod_route.h"
#include <time.h>

#define NB_VOIES 5 //entre 1 et 10
#define NB_VEHICULES 50
#define VITESSE_MIN 50
#define VITESSE_MAX 150
#define LONGUEUR 40
#define DIST_MIN 0.01
#define FACILITER_DEPASSEMENTS 1

#define DELAI_ITERATIONS_MS 0

int main(void)
{	
	initwindow(800, 800);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	t_route* route;
	char nom_fichier[100] = "nom_fichier";


	route = route_init(NB_VOIES, VITESSE_MIN, VITESSE_MAX, LONGUEUR, NB_VEHICULES);

	route_ajout_vehicules_aleatoirement(route, NB_VEHICULES);

	do {
		cleardevice();
		dessiner_ecran(NB_VOIES);

		for (size_t i_voie = 0; i_voie < route->nb_voies; i_voie++)
		{
			for (size_t i_vehicule = 0; i_vehicule < route->voies[i_voie]->nb_vehicules; i_vehicule++)
			{
				t_vehicule* v = route->voies[i_voie]->vehicules[i_vehicule];
				dessiner_vehicule(v, i_voie, CENTRE);
				v->position = v->position + vehicule_calculer_deplacement(v, 2);
			}
		}
		route_sauvegarder_route(nom_fichier, route);

		delay_graph(100);
	} while (!kbhit_graph());
}
