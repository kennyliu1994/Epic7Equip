#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>
#include <vector>

using namespace std;

class equipment
{
public:
    string part;
    string type;
    //0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=破滅
    //7=吸血 8=反擊 9=抵抗 10=夾攻 11=憤怒 12=免疫
    int atk;
    int atk_pctg;
    int hp;
    int hp_pctg;
    int def;
    int def_pctg;
    int crit;
    int crit_dmg;
    int effective;
    int resist;
    int spd;
};

class hero_status
{
public:
    vector<int> part_index;
    int atk;
    int atk_pctg;
    int hp;
    int hp_pctg;
    int def;
    int def_pctg;
    int crit;
    int crit_dmg;
    int dual_atk;
    int effective;
    int resist;
    int spd;
};

class part
{
public:
    vector<string> type;
    vector<int> atk;
    vector<int> atk_pctg;
    vector<int> hp;
    vector<int> hp_pctg;
    vector<int> def;
    vector<int> def_pctg;
    vector<int> crit;
    vector<int> crit_dmg;
    vector<int> effective;
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
extern string need_type;
extern string sort_by;

void run();
// void input_new_equipment();
// void load_database();
void calculate();
void init_hero(hero_status &);
// void init_part(part &, part &, part &, part &, part &, part &);

#endif