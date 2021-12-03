#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mod_geo.h"
#include "mod_dessin.h"
#include "mod_vehicule.h"
#include "winBGIm.h"
#include "mod_route.h"
#include <time.h>
#include <string.h>

#define NB_VOIES 3 //entre 1 et 10
#define NB_VEHICULES 40
#define VITESSE_MIN 50
#define VITESSE_MAX 150
#define DIST_MIN 0.1
#define FACILITER_DEPASSEMENTS 0

#define DELAI_ITERATIONS_MS 1

int main(void)
{	
	initwindow(800, 800);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	t_route* route;
	char nom_fichier[100] = "Sauvegarde_de_la_simulation";


	route = route_init(NB_VOIES, VITESSE_MIN, VITESSE_MAX, LONGUEUR_VOIE_KM, NB_VEHICULES);

	route_ajout_vehicules_aleatoirement(route, NB_VEHICULES);

	do {
		cleardevice();
		dessiner_ecran(NB_VOIES);

		for (size_t i_voie = 0; i_voie < route->nb_voies; i_voie++)
		{
			for (size_t i_vehicule = 0; i_vehicule < route->voies[i_voie]->nb_vehicules; i_vehicule++)
			{
				t_vehicule* v = route->voies[i_voie]->vehicules[i_vehicule];
				vehicule_decision(v, route, DELAI_ITERATIONS_MS, FACILITER_DEPASSEMENTS);
				dessiner_vehicule(v, i_voie, CENTRE);
			}
		}
		
		char message[25] = "Satisfaction: ";
		char pourcentage_satisfaction[7];
		sprintf(pourcentage_satisfaction, "%.2f", ((1 - route_ratio_insatisfaits(route)) * 100.0 )); //calcul du pourcentage de satisfaction
		strcat(message, pourcentage_satisfaction);
		setcolor(WHITE);
		outtextxy(CENTRE.x, CENTRE.y, message);
		delay_graph(100);
	} while (!kbhit_graph());

	route_sauvegarder_route(nom_fichier, route);
}
