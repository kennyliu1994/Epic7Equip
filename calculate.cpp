#include "global.h"

#include <iostream>
#include <fstream>
#include <algorithm> // min sort

void copy(individual &temp, individual weapon, individual helmet, individual armor, individual necklace, individual ring, individual boots,
          int w, int h, int a, int n, int r, int b)
{
    /*temp.set_type.assign(13, 0);
    temp.set_type[weapon.set_type[0]]++;
    temp.set_type[helmet.set_type[0]]++;
    temp.set_type[armor.set_type[0]]++;
    temp.set_type[necklace.set_type[0]]++;
    temp.set_type[ring.set_type[0]]++;
    temp.set_type[boots.set_type[0]]++;*/
    temp.belong.assign(6, 0);
    temp.belong[0] = w;
    temp.belong[1] = h;
    temp.belong[2] = a;
    temp.belong[3] = n;
    temp.belong[4] = r;
    temp.belong[5] = b;
    //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=暴傷
    //7=吸血 8=反擊 9=抵抗 10=夾擊 11=憤怒 12=免疫
    if (temp.set_type[0] >= 2)
        temp.hp_pctg += (temp.set_type[0] / 2 * 15);
    if (temp.set_type[1] >= 2)
        temp.def_pctg += (temp.set_type[1] / 2 * 15);
    if (temp.set_type[2] >= 4)
        temp.atk_pctg += (temp.set_type[2] / 4 * 35);
    if (temp.set_type[3] >= 4)
        temp.speed *= 1.25;
    if (temp.set_type[4] >= 2)
        temp.crit_chance += (temp.set_type[4] / 2 * 12);
    if (temp.set_type[5] >= 2)
        temp.effectiveness += (temp.set_type[5] / 2 * 20);
    if (temp.set_type[6] >= 4)
        temp.crit_dmg += (temp.set_type[6] / 4 * 40);
    if (temp.set_type[9] >= 2)
        temp.effect_resist += (temp.set_type[9] / 2 * 20);
    if (temp.set_type[10] >= 2)
        temp.dual_atk_chance += (temp.set_type[10] / 2 * 4);
    temp.atk_pctg += weapon.atk_pctg + helmet.atk_pctg + armor.atk_pctg + necklace.atk_pctg + ring.atk_pctg + boots.atk_pctg;
    temp.atk *= 0.01 * temp.atk_pctg + 1;
    temp.atk += weapon.atk + helmet.atk + armor.atk + necklace.atk + ring.atk + boots.atk;

    temp.hp_pctg += weapon.hp_pctg + helmet.hp_pctg + armor.hp_pctg + necklace.hp_pctg + ring.hp_pctg + boots.hp_pctg;
    temp.hp *= 0.01 * temp.hp_pctg + 1;
    temp.hp += weapon.hp + helmet.hp + armor.hp + necklace.hp + ring.hp + boots.hp;

    temp.def_pctg += weapon.def_pctg + helmet.def_pctg + armor.def_pctg + necklace.def_pctg + ring.def_pctg + boots.def_pctg;
    temp.def *= 0.01 * temp.def_pctg + 1;
    temp.def += weapon.def + helmet.def + armor.def + necklace.def + ring.def + boots.def;

    temp.crit_chance += weapon.crit_chance + helmet.crit_chance + armor.crit_chance + necklace.crit_chance + ring.crit_chance + boots.crit_chance;
    temp.crit_dmg += weapon.crit_dmg + helmet.crit_dmg + armor.crit_dmg + necklace.crit_dmg + ring.crit_dmg + boots.crit_dmg;
    temp.dual_atk_chance += weapon.dual_atk_chance + helmet.dual_atk_chance + armor.dual_atk_chance + necklace.dual_atk_chance + ring.dual_atk_chance + boots.dual_atk_chance;
    temp.effectiveness += weapon.effectiveness + helmet.effectiveness + armor.effectiveness + necklace.effectiveness + ring.effectiveness + boots.effectiveness;
    temp.effect_resist += weapon.effect_resist + helmet.effect_resist + armor.effect_resist + necklace.effect_resist + ring.effect_resist + boots.effect_resist;
    temp.speed += weapon.speed + helmet.speed + armor.speed + necklace.speed + ring.speed + boots.speed;
}

bool cmp_speed(individual const &a, individual const &b)
{
    return a.speed > b.speed;
};

bool cmp_atk(individual const &a, individual const &b)
{
    return a.atk > b.atk;
};

bool cmp_hp(individual const &a, individual const &b)
{
    return a.hp > b.hp;
};

bool cmp_eff(individual const &a, individual const &b)
{
    return a.effectiveness > b.effectiveness;
};

void calculate()
{
    initialize();
    weapon = new individual[n_weapon];
    helmet = new individual[n_helmet];
    armor = new individual[n_armor];
    necklace = new individual[n_necklace];
    ring = new individual[n_ring];
    boots = new individual[n_boots];
    vector<individual> comp;
    comp.clear();
    load();
    int f = 0;
    for (int w = 0; w < n_weapon; w++)
    {
        for (int h = 0; h < n_helmet; h++)
        {
            for (int a = 0; a < n_armor; a++)
            {
                for (int n = 0; n < n_necklace; n++)
                {
                    for (int r = 0; r < n_ring; r++)
                    {
                        for (int b = 0; b < n_boots; b++)
                        {
                            temp.set_type.assign(13, 0);
                            temp.set_type[weapon[w].set_type[0]]++;
                            temp.set_type[helmet[h].set_type[0]]++;
                            temp.set_type[armor[a].set_type[0]]++;
                            temp.set_type[necklace[n].set_type[0]]++;
                            temp.set_type[ring[r].set_type[0]]++;
                            temp.set_type[boots[b].set_type[0]]++;
                            temp.crit_chance = weapon[w].crit_chance + helmet[h].crit_chance + armor[a].crit_chance + necklace[n].crit_chance + ring[r].crit_chance + boots[b].crit_chance;
                            temp.speed = weapon[w].speed + helmet[h].speed + armor[a].speed + necklace[n].speed + ring[r].speed + boots[b].speed;

                            //if (temp.set_type[3] >= 4) //最快速度
                            //if (temp.set_type[2] >= 4 && temp.crit_chance >= 85 - 23) //攻擊水刺
                            //if (temp.set_type[7] >= 4 && temp.crit_chance >= 85-30-15)//吸血水龍
                            //if (temp.set_type[3] >= 4 && temp.crit_chance >= 85 - 23) //速度木刺
                            //if (temp.set_type[3] >= 4 && temp.speed >= (150 - 88 * 1.25)) //速度150水奶
                            //if (temp.set_type[3] >= 4 && temp.speed >= (180 - 106 * 1.25)) //速度180歌姬
                            //if (temp.set_type[3] >= 4 && temp.speed >= (200 - 115 * 1.25)) //速度200蒂姬
                            //if (temp.set_type[7] >= 4 && temp.crit_chance >= 80 - 23) //吸血反擊
                            //if (temp.set_type[3] >= 4 && temp.speed >= (200 - 112 * 1.25)) //速度伊賽
                            //if (temp.set_type[3] >= 4) //2速
                            //if (temp.set_type[2] >= 4 && temp.crit_chance >= 85 - 23) //攻擊暗刺
                            if (temp.set_type[2] >= 4 && temp.crit_chance >= 85) //攻擊lorina
                            {
                                lorina(temp);
                                copy(temp, weapon[w], helmet[h], armor[a], necklace[n], ring[r], boots[b], w, h, a, n, r, b);
                                comp.push_back(temp);
                                f++;
                                if (f > n_need)
                                {
                                    //sort(comp.begin(), comp.end(), cmp_speed); //速度
                                    sort(comp.begin(), comp.end(), cmp_atk); //攻擊%
                                    //sort(comp.begin(), comp.end(), cmp_hp); //生命%
                                    //sort(comp.begin(), comp.end(), cmp_eff); //命中
                                    comp.pop_back();
                                    f--;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fstream fs;
    fs.open("list.out", ios::out);
    for (int n = 0; n < n_need; n++)
    {
        for (int i = 0; i < 13; i++)
        {
            fs << comp[n].set_type[i];
        }
        fs << " ";
        for (int i = 0; i < 5; i++)
        {
            if (comp[n].belong[i] + 1 > 9)
            {
                fs << comp[n].belong[i] + 1 << ",";
            }
            else
            {
                fs << "0" << comp[n].belong[i] + 1 << ",";
            }
        }
        if (comp[n].belong[5] + 1 > 9)
        {
            fs << comp[n].belong[5] + 1;
        }
        else
        {
            fs << "0" << comp[n].belong[5] + 1;
        }
        fs << " atk = " << comp[n].atk << " hp = " << comp[n].hp << " def = " << comp[n].def << " crit = " << comp[n].crit_chance
           << " crit_dmg = " << comp[n].crit_dmg << " dual = " << comp[n].dual_atk_chance << " effect = " << comp[n].effectiveness
           << " resist = " << comp[n].effect_resist << " speed = " << comp[n].speed << endl;
    }
    fs.close();
}