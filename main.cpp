#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "mod_geo.h"
#include "mod_dessin.h"
#include "mod_vehicule.h"
#include "winBGIm.h"
#include "mod_route.h"
#include <time.h>

#define NB_VOIES 5
#define NB_VEHICULES 200
#define FACILITER_DEPASSEMENTS 1

#define DELAI_ITERATIONS_MS 0

int main(void)
{	
	initwindow(800, 800);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	t_route route;

	t_vehicule v;
	geo_init_polygone(&(v.geometrie), 4);
	vehicule_reset_geometrie(&v);
	v.position = 0;
	v.vitesse = 100;
	v.vitesse_cible = 120;
	v.voie = 0;

	do {
		cleardevice();
		dessiner_ecran(NB_VOIES);

		dessiner_vehicule(&v, 0, CENTRE);

		v.position = v.position + vehicule_calculer_deplacement(&v, 2);

		delay_graph(100);
	} while (!kbhit_graph());
}
