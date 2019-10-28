#include "main.h"
#include "Kenny.h"

#include <fstream>
#include <vector>

void load(part &p, vector<string> word)
{
    Kenny_convert ct;
    p.type.push_back(word[2]);
    p.atk.push_back(ct.str2int(word[3]));
    p.atk_pctg.push_back(ct.str2int(word[4]));
    p.hp.push_back(ct.str2int(word[5]));
    p.hp_pctg.push_back(ct.str2int(word[6]));
    p.def.push_back(ct.str2int(word[7]));
    p.def_pctg.push_back(ct.str2int(word[8]));
    p.crit.push_back(ct.str2int(word[9]));
    p.crit_dmg.push_back(ct.str2int(word[10]));
    p.effective.push_back(ct.str2int(word[11]));
    p.resist.push_back(ct.str2int(word[12]));
    p.spd.push_back(ct.str2int(word[13]));
}

void init_part(part &weapon, part &helmet, part &armor, part &necklace, part &ring, part &boots)
{
    fstream fs_w, fs_h, fs_a, fs_n, fs_r, fs_b;
    fs_w.open("./parts/weapon.txt", ios::in);
    fs_h.open("./parts/helmet.txt", ios::in);
    fs_a.open("./parts/armor.txt", ios::in);
    fs_n.open("./parts/necklace.txt", ios::in);
    fs_r.open("./parts/ring.txt", ios::in);
    fs_b.open("./parts/boots.txt", ios::in);
    string line;         //一行
    vector<string> word; //一個字
    while (getline(fs_w, line))
    {
        split(line, word, ' ');
        load(weapon, word);
    }
    while (getline(fs_h, line))
    {
        split(line, word, ' ');
        load(helmet, word);
    }
    while (getline(fs_a, line))
    {
        split(line, word, ' ');
        load(armor, word);
    }
    while (getline(fs_n, line))
    {
        split(line, word, ' ');
        load(necklace, word);
    }
    while (getline(fs_r, line))
    {
        split(line, word, ' ');
        load(ring, word);
    }
    while (getline(fs_b, line))
    {
        split(line, word, ' ');
        load(boots, word);
    }
    fs_w.close();
    fs_h.close();
    fs_a.close();
    fs_n.close();
    fs_r.close();
    fs_b.close();
}