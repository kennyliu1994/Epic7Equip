#include "global.h"

#include <iostream>
#include <fstream>
#include <algorithm> // min sort
#include <iomanip>

void copy(individual &temp, individual weapon, individual helmet, individual armor, individual necklace, individual ring, individual boots,
          int w, int h, int a, int n, int r, int b)
{
    temp.belong.assign(6, 0);
    temp.belong[0] = w;
    temp.belong[1] = h;
    temp.belong[2] = a;
    temp.belong[3] = n;
    temp.belong[4] = r;
    temp.belong[5] = b;
    //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=暴傷
    //7=吸血 8=反擊 9=抵抗 10=夾擊 11=憤怒 12=免疫
    temp.atk_pctg += weapon.atk_pctg + helmet.atk_pctg + armor.atk_pctg + necklace.atk_pctg + ring.atk_pctg + boots.atk_pctg;
    temp.atk *= 0.01 * temp.atk_pctg + 1;
    temp.atk += weapon.atk + helmet.atk + armor.atk + necklace.atk + ring.atk + boots.atk;

    temp.hp_pctg += weapon.hp_pctg + helmet.hp_pctg + armor.hp_pctg + necklace.hp_pctg + ring.hp_pctg + boots.hp_pctg;
    temp.hp *= 0.01 * temp.hp_pctg + 1;
    temp.hp += weapon.hp + helmet.hp + armor.hp + necklace.hp + ring.hp + boots.hp;

    temp.def_pctg += weapon.def_pctg + helmet.def_pctg + armor.def_pctg + necklace.def_pctg + ring.def_pctg + boots.def_pctg;
    temp.def *= 0.01 * temp.def_pctg + 1;
    temp.def += weapon.def + helmet.def + armor.def + necklace.def + ring.def + boots.def;

    //temp.crit_chance += weapon.crit_chance + helmet.crit_chance + armor.crit_chance + necklace.crit_chance + ring.crit_chance + boots.crit_chance;
    temp.crit_dmg += weapon.crit_dmg + helmet.crit_dmg + armor.crit_dmg + necklace.crit_dmg + ring.crit_dmg + boots.crit_dmg;
    temp.dual_atk_chance += weapon.dual_atk_chance + helmet.dual_atk_chance + armor.dual_atk_chance + necklace.dual_atk_chance + ring.dual_atk_chance + boots.dual_atk_chance;
    temp.effectiveness += weapon.effectiveness + helmet.effectiveness + armor.effectiveness + necklace.effectiveness + ring.effectiveness + boots.effectiveness;
    temp.effect_resist += weapon.effect_resist + helmet.effect_resist + armor.effect_resist + necklace.effect_resist + ring.effect_resist + boots.effect_resist;
    //temp.speed += weapon.speed + helmet.speed + armor.speed + necklace.speed + ring.speed + boots.speed;
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

bool cmp_hp_eff(individual const &a, individual const &b)
{
    return a.effectiveness * a.hp > b.effectiveness * b.hp;
};

bool cmp_hp_res(individual const &a, individual const &b)
{
    return a.effect_resist * a.hp > b.effect_resist * b.hp;
};

bool cmp_atk_dmg(individual const &a, individual const &b)
{
    return a.atk * a.crit_dmg > b.atk * b.crit_dmg;
};

bool cmp_atk_dmg_hp(individual const &a, individual const &b)
{
    return a.atk * a.crit_dmg * a.hp > b.atk * b.crit_dmg * b.hp;
};

bool cmp_dmg(individual const &a, individual const &b)
{
    return a.crit_dmg > b.crit_dmg;
};

void calculate()
{
    vector<individual> comp;
    comp.clear();
    load();
    int f = 0;
    n_need = 10;
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

                            //Auxiliary_Lots(hero); //5/92(n_need/sec)
                            //Watcher_Schuri(hero); //30/12(n_need/sec)
                            //Luna(hero); //30/8
                            //Seaside_Bellona(hero); //30/43
                            //Dizzy(hero); //30/3
                            //Iseria(hero); //30/15
                            //Tamarinne(hero); //30/35
                            //Angelica(hero); //30/28
                            //Angelic_Montmorancy(hero); //30/28
                            //Lorina(hero); //30/1
                            //Violet(hero); //30/0
                            //Vildred(hero); //30/1.37
                            //Jecht(hero); //30/0.67
                            Arbiter_Vildred(hero); //30/3
                            //Sez(hero); //30/7.71
                            //Bellona(hero); //30/3
                            //Righteous_Thief_Roozid(hero); //30/1.76

                            if (temp.set_type[0] >= 2)
                                hero.hp_pctg += (temp.set_type[0] / 2 * 15);
                            if (temp.set_type[1] >= 2)
                                hero.def_pctg += (temp.set_type[1] / 2 * 15);
                            if (temp.set_type[2] >= 4)
                                hero.atk_pctg += (temp.set_type[2] / 4 * 35);
                            if (temp.set_type[3] >= 4)
                                hero.speed *= 1.25;
                            if (temp.set_type[4] >= 2)
                                hero.crit_chance += (temp.set_type[4] / 2 * 12);
                            if (temp.set_type[5] >= 2)
                                hero.effectiveness += (temp.set_type[5] / 2 * 20);
                            if (temp.set_type[6] >= 4)
                                hero.crit_dmg += (temp.set_type[6] / 4 * 40);
                            if (temp.set_type[9] >= 2)
                                hero.effect_resist += (temp.set_type[9] / 2 * 20);
                            if (temp.set_type[10] >= 2)
                                hero.dual_atk_chance += (temp.set_type[10] / 2 * 4);

                            //hero.speed += weapon[w].speed + helmet[h].speed + armor[a].speed + necklace[n].speed + ring[r].speed + boots[b].speed;
                            hero.crit_chance += weapon[w].crit_chance + helmet[h].crit_chance + armor[a].crit_chance + necklace[n].crit_chance + ring[r].crit_chance + boots[b].crit_chance;

                            //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=暴傷
                            //7=吸血 8=反擊 9=抵抗 10=夾擊 11=憤怒 12=免疫

                            //if (temp.set_type[3] >= 4 && hero.speed >= 200) //1速
                            //if (temp.set_type[2] >= 4 && temp.crit_chance >= 90 - 27) //攻擊光槍
                            //if (temp.set_type[7] >= 4 && temp.crit_chance >= 85 - 30 - 15) //吸血水龍
                            //if (temp.set_type[3] >= 4 && temp.crit_chance >= 90 - 15) //速度水扇
                            //if (temp.set_type[8] >= 4 && temp.speed >= (200 - 115)) //反擊蒂姬
                            //if (temp.set_type[3] >= 4 && temp.speed >= (202 - 112 * 1.25)) //速度伊賽
                            //if (temp.set_type[3] >= 4 && temp.speed >= (182 - 106 * 1.25)) //速度歌姬
                            //if (temp.set_type[3] >= 4 && temp.speed >= (146 - 88 * 1.25)) //速度水奶
                            //if (temp.set_type[3] >= 4 && temp.speed >= (180 - 94 * 1.25)) //速度小水奶
                            //if (temp.set_type[2] >= 4 && temp.crit_chance >= 85 - 23) //攻擊lorina
                            //if (temp.set_type[7] >= 4 && temp.crit_chance >= 80 - 23) //吸血反賊
                            //if (temp.set_type[3] >= 4 && temp.crit_chance >= 85 - 23) //速度木刺
                            //if (temp.set_type[3] >= 4) //2速
                            //if (temp.set_type[3] >= 4) //3速

                            //if (temp.set_type[2] >= 4 && temp.crit_chance >= 85 - 23) //攻擊水刺
                            if (temp.set_type[3] >= 4 && hero.crit_chance >= 85) //攻擊暗刺
                            //if (temp.set_type[3] >= 4 && temp.crit_chance >= 85 - 23) //速度暴傷木扇
                            {
                                copy(hero, weapon[w], helmet[h], armor[a], necklace[n], ring[r], boots[b], w, h, a, n, r, b);
                                comp.push_back(hero);
                                f++;
                                if (f > n_need)
                                {
                                    //sort(comp.begin(), comp.end(), cmp_speed); //速度
                                    //sort(comp.begin(), comp.end(), cmp_atk); //攻擊
                                    //sort(comp.begin(), comp.end(), cmp_hp); //生命
                                    //sort(comp.begin(), comp.end(), cmp_eff); //命中
                                    //sort(comp.begin(), comp.end(), cmp_hp_eff); //生命*命中
                                    //sort(comp.begin(), comp.end(), cmp_hp_res); //生命*抵抗
                                    sort(comp.begin(), comp.end(), cmp_atk_dmg); //攻擊*暴傷
                                    //sort(comp.begin(), comp.end(), cmp_atk_dmg_hp); //攻擊*暴傷*生命
                                    //sort(comp.begin(), comp.end(), cmp_dmg); //暴傷
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
    if (f == 0)
    {
        cout << "Not found" << endl;
        exit(0);
    }
    fstream fs;
    fs.open("list.out", ios::out);
    for (int n = 0; n < f; n++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (comp[n].belong[i] > 9)
                fs << comp[n].belong[i] << ",";
            else
                fs << "0" << comp[n].belong[i] << ",";
        }
        if (comp[n].belong[5] > 9)
            fs << comp[n].belong[5];
        else
            fs << "0" << comp[n].belong[5];
        fs << " atk = " << comp[n].atk << " hp = " << comp[n].hp << " def = " << comp[n].def << " crit = " << comp[n].crit_chance
           << " crit_dmg = " << comp[n].crit_dmg << " dual = " << comp[n].dual_atk_chance << " effect = " << comp[n].effectiveness
           << " resist = " << comp[n].effect_resist << " speed = " << comp[n].speed << endl;
    }
    fs.close();
    delete[] weapon;
    delete[] helmet;
    delete[] armor;
    delete[] necklace;
    delete[] ring;
    delete[] boots;
}