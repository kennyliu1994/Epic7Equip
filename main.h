#ifndef _MAIN_H_
#define _MAIN_H_

#include <iostream>

using namespace std;
// #include <string>
// #include <vector>

class equipment
{
public:
    string type;
    string part;
    // //0=health 1=defense 2=attack 3=speed 4=ctitical 5=hit rate 6=destruction
    // //7=lifesteal 8=counter 9=resist 10=unity 11=rage 12=immunity
    // vector<int> belong;
    // int used;
    // int index;
    int atk;
    int atk_pctg;
    int hp;
    int hp_pctg;
    int def;
    int def_pctg;
    int crit;
    int crit_dmg;
    // int dual_atk_chance;
    int effective;
    int resist;
    int spd;
};

// //extern double total_progress;
// extern int n_weapon;
// extern int n_helmet;
// extern int n_armor;
// extern int n_necklace;
// extern int n_ring;
// extern int n_boots;
// extern int n_need;
// extern individual *weapon;
// extern individual *helmet;
// extern individual *armor;
// extern individual *necklace;
// extern individual *ring;
// extern individual *boots;
// extern individual hero;
// extern individual temp;

void run();
void input_new_equipment();
void load_database();
// void calculate();
// //void split(const string &s, vector<string> &sv, const char delim);

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