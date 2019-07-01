#include "global.h"

#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int n_weapon;
int n_helmet;
int n_armor;
int n_necklace;
int n_ring;
int n_boots;
int n_final;
individual *weapon;
individual *helmet;
individual *armor;
individual *necklace;
individual *ring;
individual *boots;
individual *final;

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "input") == 0)
    {
        fstream fs;
        fs.open("list.in", ios::app);
        fs << argv[2] << " " << argv[3] << " " << argv[4] << " " << argv[5] << " " << argv[6]
           << " " << argv[7] << " " << argv[8] << " " << argv[9] << " " << argv[10] << " " << argv[11]
           << " " << argv[12] << " " << argv[13] << " " << argv[14] << " " << argv[15] << endl;
        fs.close();
    }

    if (strcmp(argv[1], "calculate") == 0)
    {
        initialize();
        weapon = new individual[n_weapon];
        helmet = new individual[n_helmet];
        armor = new individual[n_armor];
        necklace = new individual[n_necklace];
        ring = new individual[n_ring];
        boots = new individual[n_boots];
        final = new individual[n_final];
        load();
        calculate();
        fstream fs;
        fs.open("list.out", ios::out);
        int f = 0;
        while (f < n_final)
        {
            fs << final[f].atk << " " << final[f].atk_pctg << " " << final[f].hp << " " << final[f].hp_pctg
               << " " << final[f].def << " " << final[f].def_pctg << " " << final[f].crit_chance
               << " " << final[f].crit_dmg << " " << final[f].dual_atk_chance << " " << final[f].effectiveness
               << " " << final[f].effect_resist << " " << final[f].speed << endl;
            f++;
        }
        fs.close();
    }

    //if operation = find_highest_speed
    //find_highest_speed
    //show equip
}