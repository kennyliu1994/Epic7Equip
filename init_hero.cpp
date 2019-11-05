#include "main.h"

//暗槍,賽茲,水奶,暗拉茲,露娜,木刺,偶像,蒂姬,木反,伊賽麗亞,暗刺,木狼,木扇,狗子,光槍,水扇,小水奶,暗狗,席德
void init_hero(hero_status &hero)
{
    if (hero_name == "暗槍")
    {
        hero.atk = 1144;
        hero.atk_pctg = 0;
        hero.hp = 4895;
        hero.hp_pctg = 0;
        hero.def = 543;
        hero.def_pctg = 0;
        hero.crit = 23;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 101;
    }
    else if (hero_name == "賽茲")
    {
        hero.atk = 1228;
        hero.atk_pctg = 0;
        hero.hp = 6266;
        hero.hp_pctg = 0;
        hero.def = 473;
        hero.def_pctg = 0;
        hero.crit = 23;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 113;
    }

    else if (hero_name == "水奶")
    {
        hero.atk = 576;
        hero.atk_pctg = 0;
        hero.hp = 5700;
        hero.hp_pctg = 0;
        hero.def = 743;
        hero.def_pctg = 0;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 88;
    }

    else if (hero_name == "暗拉茲")
    {
        hero.atk = 1021;
        hero.atk_pctg = 0;
        hero.hp = 4855;
        hero.hp_pctg = 0;
        hero.def = 610;
        hero.def_pctg = 0;
        hero.crit = 35;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 112;
    }

    else if (hero_name == "露娜")
    {
        hero.atk = 1119;
        hero.atk_pctg = 0;
        hero.hp = 6266;
        hero.hp_pctg = 0;
        hero.def = 627;
        hero.def_pctg = 0;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 109;
    }

    else if (hero_name == "木刺")
    {
        hero.atk = 1283;
        hero.atk_pctg = 0;
        hero.hp = 5138;
        hero.hp_pctg = 0;
        hero.def = 522;
        hero.def_pctg = 0;
        hero.crit = 23;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 116;
    }

    else if (hero_name == "偶像")
    {
        hero.atk = 932;
        hero.atk_pctg = 0;
        hero.hp = 4370;
        hero.hp_pctg = 0;
        hero.def = 652;
        hero.def_pctg = 0;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 108;
    }

    else if (hero_name == "蒂姬")
    {
        hero.atk = 1039;
        hero.atk_pctg = 0;
        hero.hp = 5299;
        hero.hp_pctg = 0;
        hero.def = 673;
        hero.def_pctg = 0;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 18;
        hero.resist = 18;
        hero.spd = 115;
    }

    else if (hero_name == "木反")
    {
        hero.atk = 1228;
        hero.atk_pctg = 0;
        hero.hp = 6266;
        hero.hp_pctg = 0;
        hero.def = 473;
        hero.def_pctg = 0;
        hero.crit = 23;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 113;
    }

    else if (hero_name == "伊賽麗亞")
    {
        hero.atk = 1158;
        hero.atk_pctg = 0;
        hero.hp = 6002;
        hero.hp_pctg = 0;
        hero.def = 553;
        hero.def_pctg = 0;
        hero.crit = 23;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 112;
    }

    else if (hero_name == "暗刺")
    {
        hero.atk = 1283;
        hero.atk_pctg = 0;
        hero.hp = 5138;
        hero.hp_pctg = 0;
        hero.def = 522;
        hero.def_pctg = 0;
        hero.crit = 23;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 116;
    }

    else if (hero_name == "木狼")
    {
        hero.atk = 812;
        hero.atk_pctg = 0;
        hero.hp = 4370;
        hero.hp_pctg = 0;
        hero.def = 462;
        hero.def_pctg = 0;
        hero.crit = 27;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 12;
        hero.resist = 0;
        hero.spd = 106;
    }

    else if (hero_name == "木扇")
    {
        hero.atk = 1003;
        hero.atk_pctg = 0;
        hero.hp = 5704;
        hero.hp_pctg = 0;
        hero.def = 585;
        hero.def_pctg = 0;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 30;
        hero.resist = 0;
        hero.spd = 115;
    }

    else if (hero_name == "狗子")
    {
        hero.atk = 796;
        hero.atk_pctg = 0;
        hero.hp = 3925;
        hero.hp_pctg = 0;
        hero.def = 599;
        hero.def_pctg = 0;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.spd = 104;
    }

    else if (hero_name == "光槍")
    {
        hero.atk = 970;
        hero.hp = 5935;
        hero.spd = 106;
        hero.def = 557;
        hero.crit = 27;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.atk_pctg = 0;
        hero.hp_pctg = 0;
        hero.def_pctg = 0;
    }

    else if (hero_name == "水扇")
    {
        hero.atk = 1182;
        hero.hp = 5299;
        hero.spd = 114;
        hero.def = 571;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 18;
        hero.resist = 0;
        hero.atk_pctg = 0;
        hero.hp_pctg = 0;
        hero.def_pctg = 0;
    }

    else if (hero_name == "小水奶")
    {
        hero.atk = 540;
        hero.hp = 4900;
        hero.spd = 94;
        hero.def = 729;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.atk_pctg = 0;
        hero.hp_pctg = 0;
        hero.def_pctg = 0;
    }

    else if (hero_name == "暗狗")
    {
        hero.atk = 1119;
        hero.hp = 6091;
        hero.spd = 100;
        hero.def = 594;
        hero.crit = 15;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.atk_pctg = 0;
        hero.hp_pctg = 0;
        hero.def_pctg = 0;
    }

    else if (hero_name == "席德")
    {
        hero.atk = 1029;
        hero.hp = 5097;
        hero.spd = 126;
        hero.def = 473;
        hero.crit = 23;
        hero.crit_dmg = 150;
        hero.dual_atk = 5;
        hero.effective = 0;
        hero.resist = 0;
        hero.atk_pctg = 0;
        hero.hp_pctg = 0;
        hero.def_pctg = 0;
    }
}