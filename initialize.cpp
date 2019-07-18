#include "global.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void initialize()
{
    n_weapon = 0;
    n_helmet = 0;
    n_armor = 0;
    n_necklace = 0;
    n_ring = 0;
    n_boots = 0;
    string line;
    fstream fs;
    fs.open("list.in", ios::in);
    while (getline(fs, line))
    {
        if (line[0] == 'w')
            n_weapon++;
        if (line[0] == 'h')
            n_helmet++;
        if (line[0] == 'a')
            n_armor++;
        if (line[0] == 'n')
            n_necklace++;
        if (line[0] == 'r')
            n_ring++;
        if (line[0] == 'b')
            n_boots++;
    }
    //total_progress = n_weapon * n_helmet * n_armor * n_necklace * n_ring * n_boots;
    fs.close();
}