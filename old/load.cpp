#include "global.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

void cal_size()
{
    fstream fs;
    fs.open("list.in", ios::in);
    n_weapon = 0;
    n_helmet = 0;
    n_armor = 0;
    n_necklace = 0;
    n_ring = 0;
    n_boots = 0;
    string line;
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
    fs.close();
}



void copy(individual &i, vector<string> words, const int index)
{
    i.index = index;
    i.set_type.assign(1, 0);
    i.set_type[0] = stoi(words[1]);
    i.atk = stoi(words[2]);
    i.atk_pctg = stoi(words[3]);
    i.hp = stoi(words[4]);
    i.hp_pctg = stoi(words[5]);
    i.def = stoi(words[6]);
    i.def_pctg = stoi(words[7]);
    i.crit_chance = stoi(words[8]);
    i.crit_dmg = stoi(words[9]);
    i.dual_atk_chance = stoi(words[10]);
    i.effectiveness = stoi(words[11]);
    i.effect_resist = stoi(words[12]);
    i.speed = stoi(words[13]);
}

void load()
{
    cal_size();
    weapon = new individual[n_weapon];
    helmet = new individual[n_helmet];
    armor = new individual[n_armor];
    necklace = new individual[n_necklace];
    ring = new individual[n_ring];
    boots = new individual[n_boots];
    string line;
    vector<string> word;
    int w = 0, h = 0, a = 0, n = 0, r = 0, b = 0; //第幾件裝備
    while (getline(fs, line))
    {
        split(line, word, ' '); //split string to vector by " "
        if (line[0] == 'w')
        {
            copy(weapon[w], word, w);
            fs_w << weapon[w].index << " ";
            fs_w << type_in_Chinese(weapon[w].set_type[0]) << " ";
            fs_w << weapon[w].atk << " " << weapon[w].atk_pctg << " " << weapon[w].hp << " " << weapon[w].hp_pctg << " " << weapon[w].def << " " << weapon[w].def_pctg << " " << weapon[w].crit_chance << " " << weapon[w].crit_dmg << " " << weapon[w].dual_atk_chance << " " << weapon[w].effectiveness << " " << weapon[w].effect_resist << " " << weapon[w].speed;
            fs_w << endl;
            w++;
            continue;
        }
        if (line[0] == 'h')
        {
            copy(helmet[h], word, h);
            fs_h << helmet[h].index << " ";
            fs_h << type_in_Chinese(helmet[h].set_type[0]) << " ";
            fs_h << helmet[h].atk << " " << helmet[h].atk_pctg << " " << helmet[h].hp << " " << helmet[h].hp_pctg << " " << helmet[h].def << " " << helmet[h].def_pctg << " " << helmet[h].crit_chance << " " << helmet[h].crit_dmg << " " << helmet[h].dual_atk_chance << " " << helmet[h].effectiveness << " " << helmet[h].effect_resist << " " << helmet[h].speed;
            fs_h << endl;
            h++;
            continue;
        }
        if (line[0] == 'a')
        {
            copy(armor[a], word, a);
            fs_a << armor[a].index << " ";
            fs_a << type_in_Chinese(armor[a].set_type[0]) << " ";
            fs_a << armor[a].atk << " " << armor[a].atk_pctg << " " << armor[a].hp << " " << armor[a].hp_pctg << " " << armor[a].def << " " << armor[a].def_pctg << " " << armor[a].crit_chance << " " << armor[a].crit_dmg << " " << armor[a].dual_atk_chance << " " << armor[a].effectiveness << " " << armor[a].effect_resist << " " << armor[a].speed;
            fs_a << endl;
            a++;
            continue;
        }
        if (line[0] == 'n')
        {
            copy(necklace[n], word, n);
            fs_n << necklace[n].index << " ";
            fs_n << type_in_Chinese(necklace[n].set_type[0]) << " ";
            fs_n << necklace[n].atk << " " << necklace[n].atk_pctg << " " << necklace[n].hp << " " << necklace[n].hp_pctg << " " << necklace[n].def << " " << necklace[n].def_pctg << " " << necklace[n].crit_chance << " " << necklace[n].crit_dmg << " " << necklace[n].dual_atk_chance << " " << necklace[n].effectiveness << " " << necklace[n].effect_resist << " " << necklace[n].speed;
            fs_n << endl;
            n++;
            continue;
        }
        if (line[0] == 'r')
        {
            copy(ring[r], word, r);
            fs_r << ring[r].index << " ";
            fs_r << type_in_Chinese(ring[r].set_type[0]) << " ";
            fs_r << ring[r].atk << " " << ring[r].atk_pctg << " " << ring[r].hp << " " << ring[r].hp_pctg << " " << ring[r].def << " " << ring[r].def_pctg << " " << ring[r].crit_chance << " " << ring[r].crit_dmg << " " << ring[r].dual_atk_chance << " " << ring[r].effectiveness << " " << ring[r].effect_resist << " " << ring[r].speed;
            fs_r << endl;
            r++;
            continue;
        }
        if (line[0] == 'b')
        {
            copy(boots[b], word, b);
            fs_b << boots[b].index << " ";
            fs_b << type_in_Chinese(boots[b].set_type[0]) << " ";
            fs_b << boots[b].atk << " " << boots[b].atk_pctg << " " << boots[b].hp << " " << boots[b].hp_pctg << " " << boots[b].def << " " << boots[b].def_pctg << " " << boots[b].crit_chance << " " << boots[b].crit_dmg << " " << boots[b].dual_atk_chance << " " << boots[b].effectiveness << " " << boots[b].effect_resist << " " << boots[b].speed;
            fs_b << endl;
            b++;
            continue;
        }
    }
    
}