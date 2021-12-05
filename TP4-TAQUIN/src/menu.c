#include "menu.h"
#include <stdio.h>
#include <dirent.h>
#include "affichage.h"

int gameover(){
    int choice =0;

}


int back_to_menu(){
    int clicx, clicy;
    int choice;

    const int espacement = 100;
    const int boxy = RESOLUTION/2;
    const int box1x = DEBUTX;
    const int box2x = DEBUTX + TEXTBOXW + espacement;

    draw_textbox("Menu", box1x, boxy);
    draw_textbox("Quitter",box2x , boxy);


    while (!( choice = wait_and_treat_event(&clicx, &clicy)));

    MLV_clear_window(MLV_COLOR_BLACK);
    
    if (choice == 1){
        if (clic_dans_box(clicx, clicy, box1x, boxy))
            return 1;
        if (clic_dans_box(clicx, clicy, box2x, boxy))
            return 2;
        else
            return 0;

    }
    return 0;


}