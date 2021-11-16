#define GEO_POLYGONE_MAX_PTS 10
//D�finit un point dans le plan
typedef struct {
	int x; //abscisse
	int y; //ordonn�e//
} t_point;
//Definit un polygone qui est un ensemble de points
typedef struct t_polygone {
	t_point points[GEO_POLYGONE_MAX_PTS]; //Tableau statique de points
	int nb_points; //Nombre de points dans le tableau
} t_polygone;

void geo_init_polygone(t_polygone* poly, int taille);
/*Initialise le polygone reçu par référence en lui assignant le nombre de
points définit par la taille reçue.
Si le nombre de points demandé excède GEO_POLYGONE_MAX_PTS, vous devez
initialiser le nombre de points du polygone à 0.*/

int geo_ajouter_point_polygone(t_polygone* poly, t_point pt, int position);
/*Ajoute le point pt reçu en paramètre au tableau de points du polygone à la
position position.Les positions doivent être entre 0 et le nombre de points
du polygone - 1. Si une position invalide a été transmise, il ne faut pas
ajouter le point.
La fonction retourne une valeur vraie si le point a bien été ajouté, ou une
valeur fausse sinon(position non - valide).*/
} t_polygone;
void geo_rotation_polygone(t_polygone* poly, double angle);
//Reçoit une référence vers un polygone poly et un angle angle.La fonction
//effectue la rotation du polygone par rapport à l’origine.