#include "main.h"
#include "Kenny.h"

#include <algorithm> // sort
#include <fstream>

vector<int> type;
part weapon, helmet, armor, necklace, ring, boots;

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
    p.used.push_back(word[14]);
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

void cal_type(string s)
{
    //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=破滅
    //7=吸血 8=反擊 9=抵抗 10=夾攻 11=憤怒 12=免疫
    if (s == "生命")
        type[0]++;
    else if (s == "防禦")
        type[1]++;
    else if (s == "攻擊")
        type[2]++;
    else if (s == "速度")
        type[3]++;
    else if (s == "暴擊")
        type[4]++;
    else if (s == "命中")
        type[5]++;
    else if (s == "破滅")
        type[6]++;
    else if (s == "吸血")
        type[7]++;
    else if (s == "反擊")
        type[8]++;
    else if (s == "抵抗")
        type[9]++;
    else if (s == "夾攻")
        type[10]++;
    else if (s == "憤怒")
        type[11]++;
    else if (s == "免疫")
        type[12]++;
}

bool filter(unsigned int w, unsigned int h, unsigned int a, unsigned int n, unsigned int r, unsigned int b)
{
    type.assign(13, 0);
    cal_type(weapon.type[w]);
    cal_type(helmet.type[h]);
    cal_type(armor.type[a]);
    cal_type(necklace.type[n]);
    cal_type(ring.type[r]);
    cal_type(boots.type[b]);
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=破滅
    //7=吸血 8=反擊 9=抵抗 10=夾攻 11=憤怒 12=免疫
    if (need_type == "攻擊")
    {
        if (type[2] >= 4)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "速度")
    {
        if (type[3] >= 4)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "速度生命")
    {
        if (type[3] == 4 && type[0] == 2)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "速度命中")
    {
        if (type[3] == 4 && type[5] == 2)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "速度抵抗")
    {
        if (type[3] == 4 && type[9] == 2)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "速度免疫")
    {
        if (type[3] == 4 && type[12] == 2)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "破滅")
    {
        if (type[6] >= 4)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "吸血")
    {
        if (type[7] >= 4)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "反擊")
    {
        if (type[8] >= 4)
            return true; //1
        else
            return false; //0
    }
    else if (need_type == "憤怒")
    {
        if (type[11] >= 4)
            return true; //1
        else
            return false; //0
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void suit_effect(hero_status &hero)
{
    if (type[0] >= 2)
        hero.hp_pctg += (type[0] / 2 * 15);
    if (type[1] >= 2)
        hero.def_pctg += (type[1] / 2 * 15);
    if (type[2] >= 4)
        hero.atk_pctg += (type[2] / 4 * 35);
    if (type[3] >= 4)
        hero.spd *= 1.25;
    if (type[4] >= 2)
        hero.crit += (type[4] / 2 * 12);
    if (type[5] >= 2)
        hero.effective += (type[5] / 2 * 20);
    if (type[6] >= 4)
        hero.crit_dmg += (type[6] / 4 * 40);
    if (type[9] >= 2)
        hero.resist += (type[9] / 2 * 20);
    if (type[10] >= 2)
        hero.dual_atk += (type[10] / 2 * 4);
}

bool hero_with_suit(hero_status &hero, unsigned int w, unsigned int h, unsigned int a, unsigned int n, unsigned int r, unsigned int b)
{
    hero.part_index.assign(6, 0);
    hero.part_index[0] = w;
    hero.part_index[1] = h;
    hero.part_index[2] = a;
    hero.part_index[3] = n;
    hero.part_index[4] = r;
    hero.part_index[5] = b;

    hero.spd += weapon.spd[w] + helmet.spd[h] + armor.spd[a] + necklace.spd[n] + ring.spd[r] + boots.spd[b];
    hero.crit += weapon.crit[w] + helmet.crit[h] + armor.crit[a] + necklace.crit[n] + ring.crit[r] + boots.crit[b];
    if (hero.spd >= need_spd && hero.crit >= need_crit)
    {
        hero.atk_pctg += weapon.atk_pctg[w] + helmet.atk_pctg[h] + armor.atk_pctg[a] + necklace.atk_pctg[n] + ring.atk_pctg[r] + boots.atk_pctg[b];
        hero.atk *= 0.01 * hero.atk_pctg + 1;
        hero.atk += weapon.atk[w] + helmet.atk[h] + armor.atk[a] + necklace.atk[n] + ring.atk[r] + boots.atk[b];

        hero.hp_pctg += weapon.hp_pctg[w] + helmet.hp_pctg[h] + armor.hp_pctg[a] + necklace.hp_pctg[n] + ring.hp_pctg[r] + boots.hp_pctg[b];
        hero.hp *= 0.01 * hero.hp_pctg + 1;
        hero.hp += weapon.hp[w] + helmet.hp[h] + armor.hp[a] + necklace.hp[n] + ring.hp[r] + boots.hp[b];

        hero.def_pctg += weapon.def_pctg[w] + helmet.def_pctg[h] + armor.def_pctg[a] + necklace.def_pctg[n] + ring.def_pctg[r] + boots.def_pctg[b];
        hero.def *= 0.01 * hero.def_pctg + 1;
        hero.def += weapon.def[w] + helmet.def[h] + armor.def[a] + necklace.def[n] + ring.def[r] + boots.def[b];

        hero.crit_dmg += weapon.crit_dmg[w] + helmet.crit_dmg[h] + armor.crit_dmg[a] + necklace.crit_dmg[n] + ring.crit_dmg[r] + boots.crit_dmg[b];
        hero.effective += weapon.effective[w] + helmet.effective[h] + armor.effective[a] + necklace.effective[n] + ring.effective[r] + boots.effective[b];
        hero.resist += weapon.resist[w] + helmet.resist[h] + armor.resist[a] + necklace.resist[n] + ring.resist[r] + boots.resist[b];
        return true;
    }
    else
        return false;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool cmp_atk(hero_status const &a, hero_status const &b)
{
    return a.atk > b.atk;
};

bool cmp_spd(hero_status const &a, hero_status const &b)
{
    return a.spd > b.spd;
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void calculate()
{
    hero_status hero;
    init_part(weapon, helmet, armor, necklace, ring, boots);
    vector<hero_status> comp;
    for (unsigned int w = 0; w < weapon.type.size(); w++)
    {
        if (weapon.used[w] == "used")
            continue;
        for (unsigned int h = 0; h < helmet.type.size(); h++)
        {
            if (helmet.used[h] == "used")
                continue;
            for (unsigned int a = 0; a < armor.type.size(); a++)
            {
                if (armor.used[a] == "used")
                    continue;
                for (unsigned int n = 0; n < necklace.type.size(); n++)
                {
                    if (necklace.used[n] == "used")
                        continue;
                    for (unsigned int r = 0; r < ring.type.size(); r++)
                    {
                        if (ring.used[r] == "used")
                            continue;
                        for (unsigned int b = 0; b < boots.type.size(); b++)
                        {
                            if (boots.used[b] == "used")
                                continue;
                            if (filter(w, h, a, n, r, b))
                            {
                                init_hero(hero);
                                suit_effect(hero);
                                if (hero_with_suit(hero, w, h, a, n, r, b))
                                {
                                    comp.push_back(hero);
                                    while (comp.size() > 20)
                                    {
                                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=破滅
                                        //7=吸血 8=反擊 9=抵抗 10=夾攻 11=憤怒 12=免疫
                                        if (sort_by == "攻擊")
                                        {
                                            sort(comp.begin(), comp.end(), cmp_atk);
                                        }
                                        else if (sort_by == "速度")
                                        {
                                            sort(comp.begin(), comp.end(), cmp_spd);
                                        }
                                        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        comp.pop_back();
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (comp.size() < 20)
    {
        sort(comp.begin(), comp.end(), cmp_atk);
    }
    if (comp.size() == 0)
    {
        cout << "Not found" << endl;
        exit(0);
    }
    fstream fs;
    fs.open(output_path.c_str(), ios::out);
    for (unsigned int i = 0; i < comp.size(); i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (comp[i].part_index[j] > 9)
                fs << comp[i].part_index[j] << ",";
            else
                fs << "0" << comp[i].part_index[j] << ",";
        }
        fs << " 攻擊 = " << comp[i].atk
           << " 生命 = " << comp[i].hp
           << " 防禦 = " << comp[i].def
           << " 暴擊 = " << comp[i].crit
           << " 暴傷 = " << comp[i].crit_dmg
           << " 效果命中 = " << comp[i].effective
           << " 效果抵抗 = " << comp[i].resist
           << " 夾攻 = " << comp[i].dual_atk
           << " 速度 = " << comp[i].spd
           << endl;
    }
    fs.close();
}