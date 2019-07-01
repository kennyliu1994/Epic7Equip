#include "global.h"

#include <iostream>

void copy(individual &final, individual weapon, individual helmet, individual armor, individual necklace, individual ring, individual boots)
{
    final.atk = weapon.atk + helmet.atk + armor.atk + necklace.atk + ring.atk + boots.atk;
    final.atk_pctg = weapon.atk_pctg + helmet.atk_pctg + armor.atk_pctg + necklace.atk_pctg + ring.atk_pctg + boots.atk_pctg;
    final.hp = weapon.hp + helmet.hp + armor.hp + necklace.hp + ring.hp + boots.hp;
    final.hp_pctg = weapon.hp_pctg + helmet.hp_pctg + armor.hp_pctg + necklace.hp_pctg + ring.hp_pctg + boots.hp_pctg;
    final.def = weapon.def + helmet.def + armor.def + necklace.def + ring.def + boots.def;
    final.def_pctg = weapon.def_pctg + helmet.def_pctg + armor.def_pctg + necklace.def_pctg + ring.def_pctg + boots.def_pctg;
    final.crit_chance = weapon.crit_chance + helmet.crit_chance + armor.crit_chance + necklace.crit_chance + ring.crit_chance + boots.crit_chance;
    final.crit_dmg = weapon.crit_dmg + helmet.crit_dmg + armor.crit_dmg + necklace.crit_dmg + ring.crit_dmg + boots.crit_dmg;
    final.dual_atk_chance = weapon.dual_atk_chance + helmet.dual_atk_chance + armor.dual_atk_chance + necklace.dual_atk_chance + ring.dual_atk_chance + boots.dual_atk_chance;
    final.effectiveness = weapon.effectiveness + helmet.effectiveness + armor.effectiveness + necklace.effectiveness + ring.effectiveness + boots.effectiveness;
    final.effect_resist = weapon.effect_resist + helmet.effect_resist + armor.effect_resist + necklace.effect_resist + ring.effect_resist + boots.effect_resist;
    final.speed = weapon.speed + helmet.speed + armor.speed + necklace.speed + ring.speed + boots.speed;
}

void calculate()
{
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
                            copy(final[f], weapon[w], helmet[h], armor[a], necklace[n], ring[r], boots[b]);
                            f++;
                        }
                    }
                }
            }
        }
    }
}