//
// Created by anis on 7/31/19.
//

#include "mod_dessin.h"//

/******************** Déclaration des constantes et représentations cachées *****/
const t_point CENTRE = {LARGEUR_ECRAN_PX / 2, HAUTEUR_ECRAN_PX / 2};

/*
/******************* Déclaration des fonctions privées ***************************/
//void convertir_poly_tabs(t_polygone poly, int16_t **tab_x, int16_t **tab_y);
//
//
int rayon_ecran(){
    return LARGEUR_ECRAN_PX < HAUTEUR_ECRAN_PX ? (LARGEUR_ECRAN_PX / 2) - 10 : (HAUTEUR_ECRAN_PX / 2) - 10;
}

void dessiner_ecran(int nb_voies){
    const int rayon = rayon_ecran();

    int rayon_courant = rayon;
	setcolor(WHITE);
    for(int i=0; i < EPAISSEUR_BORDURE_PX; i++, rayon_courant--){
        circle(CENTRE.x, CENTRE.y, rayon_courant);
    }

    for(int i=0; i<nb_voies; i++){
        rayon_courant-= LARGEUR_VISIBLE_VOIE_PX;
        circle(CENTRE.x, CENTRE.y, rayon_courant);
    }

    for(int i=0; i < EPAISSEUR_BORDURE_PX; i++, rayon_courant--){
        circle(CENTRE.x, CENTRE.y, rayon_courant);
    }

}

double circonference_voie_px(int num_voie){
    //Le rayon de la voie 0, pris au centre de la voie.
    double rayon_voie_0 = rayon_ecran() - LARGEUR_VISIBLE_VOIE_PX / 2;
    //Le rayon de la voie num_voie
    double rayon_voie = rayon_voie_0;
    //La circonférence calculée à partir du rayon de la voie
    double circonference;

    rayon_voie -= num_voie * LARGEUR_VISIBLE_VOIE_PX;

    circonference = 2 * M_PI * rayon_voie;

    return circonference;
}

t_point changer_repere_point(t_point pt, t_point centre){
    t_point resultat;

    resultat.x = pt.x + centre.x;
    resultat.y = centre.y - pt.y;

    return resultat;
}

t_polygone changer_repere_polygone(t_polygone poly, t_point centre){
	t_polygone resultat;

	geo_init_polygone(&resultat, poly.nb_points);

    for(int i=0; i<poly.nb_points; i++){
        resultat.points[i] = changer_repere_point(poly.points[i], centre);
    }
	return resultat;
}

void convertir_poly_tabs(t_polygone poly, int **tab_points){
    *tab_points = (int*)malloc(poly.nb_points*2*sizeof(int));
    
    for(int i=0; i<poly.nb_points; i++){
        (*tab_points)[i*2] = poly.points[i].x;
        (*tab_points)[i*2+1] = poly.points[i].y;
    }
}

void dessiner_polygone(t_polygone poly, t_point centre){
    int *tab_points;

	t_polygone poly_nouv_repere;

	poly_nouv_repere.nb_points = 0;
	geo_init_polygone(&poly_nouv_repere, 4);
	
	poly_nouv_repere = changer_repere_polygone(poly, centre);

    convertir_poly_tabs(poly_nouv_repere, &tab_points);

    fillpoly(poly_nouv_repere.nb_points, tab_points);


    free(tab_points);
}

void placer_vehicule_voie(t_vehicule *vehicule, int voie){
    int decalage ;


    //On calcule le déclage sur la voie 0
    decalage = rayon_ecran() - EPAISSEUR_BORDURE_PX - (LARGEUR_VISIBLE_VOIE_PX / 2) - VEHICULE_LARGEUR / 2;

    decalage -= LARGEUR_VISIBLE_VOIE_PX * voie;

    for(int i=0; i<vehicule->geometrie.nb_points; i++){
        vehicule->geometrie.points[i].y += decalage;
    }
}

void dessiner_vehicule(t_vehicule *vehicule, int voie, t_point centre){
    //Réinitialiser les coordonnées du véhicule
    vehicule_reset_geometrie(vehicule);

    placer_vehicule_voie(vehicule, voie);

    //On calcule la distance affichée qui est un modulo: la distance est toujours entre 0
    // et LONGUEUR_VOIE_KM
    double rapport_distance_longueur = vehicule->position / LONGUEUR_VOIE_KM;
    double distance_affichee = LONGUEUR_VOIE_KM * (rapport_distance_longueur - ceil(rapport_distance_longueur));

    double angle = distance_affichee * (-2*M_PI) / LONGUEUR_VOIE_KM;

	double diff_vitesse = fabs(vehicule->vitesse_cible - vehicule->vitesse) / vehicule->vitesse_cible;

	if (diff_vitesse < 0.1)
	{
		setcolor(WHITE);
		setfillpattern("SOLID_FILL", WHITE);
	}
	else if (diff_vitesse < 0.2)
	{
		setcolor(YELLOW);
		setfillpattern("SOLID_FILL", YELLOW);
	}
	else
	{
		setcolor(RED);
		setfillpattern("SOLID_FILL", RED);
	}

    geo_rotation_polygone(&(vehicule->geometrie), angle);

    dessiner_polygone(vehicule->geometrie, centre);
}
