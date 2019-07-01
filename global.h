#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include <string>
using namespace std;

class individual
{
public:
    string set;
    int atk;
    int atk_pctg;
    int hp;
    int hp_pctg;
    int def;
    int def_pctg;
    int crit_chance;
    int crit_dmg;
    int dual_atk_chance;
    int effectiveness;
    int effect_resist;
    int speed;
};

extern int n_weapon;
extern int n_helmet;
extern int n_armor;
extern int n_necklace;
extern int n_ring;
extern int n_boots;
extern int n_final;
extern individual *weapon;
extern individual *weapon;
extern individual *helmet;
extern individual *armor;
extern individual *necklace;
extern individual *ring;
extern individual *boots;
extern individual *final;

void initialize();
void input();
void load();
void calculate();

#endif