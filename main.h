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
};

extern string input_path;
extern string output_path;
extern string hero_name;
extern string need_type;
extern int need_spd;
extern int need_crit;

void run();
void input_new_equipment();
void load_database();
void calculate();
void init_hero(hero_status &);
void init_part(part &, part &, part &, part &, part &, part &);

// void Lorina(individual &temp);
// void Sez(individual &temp);
// void Angelica(individual &temp);
// void Auxiliary_Lots(individual &temp);
// void Luna(individual &temp);
// void Vildred(individual &temp);
// void Tamarinne(individual &temp);
// void Dizzy(individual &temp);
// void Violet(individual &temp);
// void Iseria(individual &temp);
// void Arbiter_Vildred(individual &temp);
// void Righteous_Thief_Roozid(individual &temp);
// void Bellona(individual &temp);
// void Jecht(individual &temp);
// void Watcher_Schuri(individual &temp);
// void Seaside_Bellona(individual &temp);
// void Angelic_Montmorancy(individual &temp);
// void Assassin_Cartuja(individual &temp);
// void Cidd(individual &temp);

#endif