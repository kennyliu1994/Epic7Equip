#include "global.h"

#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

void split(const string &s, vector<string> &sv, const char delim = ' ')
{
    sv.clear();
    stringstream ss(s);
    string temp;
    while (getline(ss, temp, delim))
    {
        sv.emplace_back(move(temp));
    }
}

void copy(individual &i, vector<string> words)
{
    i.set = words[1];
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
    fstream fs;
    string line;
    fs.open("list.in", ios::in);
    vector<string> word;
    int w = 0, h = 0, a = 0, n = 0, r = 0, b = 0;
    while (getline(fs, line))
    {
        split(line, word, ' ');
        if (line[0] == 'w')
        {
            copy(weapon[w], word);
            w++;
            continue;
        }
        if (line[0] == 'h')
        {
            copy(helmet[h], word);
            h++;
            continue;
        }
        if (line[0] == 'a')
        {
            copy(armor[a], word);
            a++;
            continue;
        }
        if (line[0] == 'n')
        {
            copy(necklace[n], word);
            n++;
            continue;
        }
        if (line[0] == 'r')
        {
            copy(ring[r], word);
            r++;
            continue;
        }
        if (line[0] == 'b')
        {
            copy(boots[b], word);
            b++;
            continue;
        }
    }
    fs.close();
}