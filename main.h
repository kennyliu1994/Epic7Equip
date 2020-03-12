#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include <vector>

using namespace std;

class equipment
{
public:
    string part; //部位
    string suit; //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=破滅 7=吸血 8=反擊 9=抵抗 10=夾攻 11=憤怒 12=免疫
    int atk;
    int atk_pctg;
    int hp;
    int hp_pctg;
    int def;
    int def_pctg;
    int crit;
    int crit_dmg;
    int hit;
    int resist;
    int spd;
};

class hero_status
{
public:
    vector<int> part_index; //穿的裝備是分別第幾件
    int atk;
    int atk_pctg;
    int hp;
    int hp_pctg;
    int def;
    int def_pctg;
    int crit;
    int crit_dmg;
    int dual_atk;
    int hit;
    int resist;
    int spd;
};

class part //部位
{
public:
    vector<string> type; //類型
    vector<int> atk;
    vector<int> atk_pctg;
    vector<int> hp;
    vector<int> hp_pctg;
    vector<int> def;
    vector<int> def_pctg;
    vector<int> crit;
    vector<int> crit_dmg;
    vector<int> hit;
    vector<int> resist;
    vector<int> spd;
    vector<string> used;
};

extern int need_crit;
extern int need_spd;
extern int need_hp;
// extern string input_path;
extern string output_path;
extern string hero_name;
extern string need_suit;
extern string sort_by;

void calculate();
void init_hero(hero_status &);

#endif