#include "interact.h"
#include "affichage.h"

int choose_carre(Plateau* p, int clicx, int clicy){
	pt_Carre tomove[4];
	int len;
	Carre carre;

	len = carre_abletomove(p, tomove);

	if (coord_dans_plateau(clicx,clicy))
		carre = coord_to_carre(clicx, clicy);
	else 
		return 0;  
	if (carre_dans_abletomove(carre, tomove, len)){
		deplace_carre_dans_vide(p, carre);
		return 1;
	}
	
	return 0;
}

int wait_and_treat_event(int* clicx, int* clicy){
	MLV_Event ev;
	MLV_Keyboard_button key;


	ev = MLV_wait_keyboard_or_mouse(&key, NULL, NULL, clicx, clicy);

	if(ev == MLV_MOUSE_BUTTON)
		return 1;
	
	else if (ev == MLV_KEY && key == MLV_KEYBOARD_ESCAPE)
		return 2;

	return 0;
}

Carre coord_to_carre(int x,int y){
	return create_carre((DEBUTY -y)/CASE * -1, (DEBUTX - x)/CASE * -1);
}

int coord_dans_plateau(int x, int y){
	return x >= DEBUTX && x < DEBUTX + W && y >= DEBUTY && y < DEBUTY + H;
}

int clic_dans_box(int clicx, int clicy, int boxx, int boxy){
	return clicx >= boxx && clicx < boxx + TEXTBOXW && clicy >= boxy && clicy < boxy + TEXTBOXH;
}

