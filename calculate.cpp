#include "main.h"

#include <algorithm> // sort
#include <fstream>

vector<int> type;
part weapon, helmet, armor, necklace, ring, boots;

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
    //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=破滅
    //7=吸血 8=反擊 9=抵抗 10=夾攻 11=憤怒 12=免疫
    if (need_type == "攻擊" && type[2] >= 4)
        return true; //1
    else
        return false; //0
}

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

bool cmp_atk(hero_status const &a, hero_status const &b)
{
    return a.atk > b.atk;
};

void calculate()
{
    hero_status hero;
    init_part(weapon, helmet, armor, necklace, ring, boots);
    vector<hero_status> comp;
    for (unsigned int w = 0; w < weapon.type.size(); w++)
    {
        for (unsigned int h = 0; h < helmet.type.size(); h++)
        {
            for (unsigned int a = 0; a < armor.type.size(); a++)
            {
                for (unsigned int n = 0; n < necklace.type.size(); n++)
                {
                    for (unsigned int r = 0; r < ring.type.size(); r++)
                    {
                        for (unsigned int b = 0; b < boots.type.size(); b++)
                        {
                            if (filter(w, h, a, n, r, b))
                            {
                                init_hero(hero);
                                suit_effect(hero);
                                if (hero_with_suit(hero, w, h, a, n, r, b))
                                {
                                    comp.push_back(hero);
                                    while (comp.size() > 20)
                                    {
                                        sort(comp.begin(), comp.end(), cmp_atk);
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
        for (int j = 0; j < 5; j++)
        {
            if (comp[i].part_index[j] > 9)
                fs << comp[i].part_index[j] << ",";
            else
                fs << "0" << comp[i].part_index[j] << ",";
        }
        if (comp[i].part_index[5] > 9)
            fs << comp[i].part_index[5];
        else
            fs << "0" << comp[i].part_index[5];
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