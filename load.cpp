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
    fstream fs;
    fstream fs_w;
    fstream fs_h;
    fstream fs_a;
    fstream fs_n;
    fstream fs_r;
    fstream fs_b;
    string line;
    fs.open("list.in", ios::in);
    fs_w.open("./input/weapon.in", ios::out);
    fs_h.open("./input/helmet.in", ios::out);
    fs_a.open("./input/armor.in", ios::out);
    fs_n.open("./input/necklace.in", ios::out);
    fs_r.open("./input/ring.in", ios::out);
    fs_b.open("./input/boots.in", ios::out);
    vector<string> word;
    int w = 1, h = 1, a = 1, n = 1, r = 1, b = 1;
    while (getline(fs, line))
    {
        split(line, word, ' ');
        if (line[0] == 'w')
        {
            copy(weapon[w], word);
            fs_w << w << " " << line << endl;
            w++;
            continue;
        }
        if (line[0] == 'h')
        {
            copy(helmet[h], word);
            fs_h << h << " " << line << endl;
            h++;
            continue;
        }
        if (line[0] == 'a')
        {
            copy(armor[a], word);
            fs_a << a << " " << line << endl;
            a++;
            continue;
        }
        if (line[0] == 'n')
        {
            copy(necklace[n], word);
            fs_n << n << " " << line << endl;
            n++;
            continue;
        }
        if (line[0] == 'r')
        {
            copy(ring[r], word);
            fs_r << r << " " << line << endl;
            r++;
            continue;
        }
        if (line[0] == 'b')
        {
            copy(boots[b], word);
            fs_b << b << " " << line << endl;
            b++;
            continue;
        }
    }
    fs.close();
    fs_w.close();
    fs_h.close();
    fs_a.close();
    fs_n.close();
    fs_r.close();
    fs_b.close();
}