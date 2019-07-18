#include "global.h"

#include <iostream>
#include <fstream>

void input()
{
    individual input;
    input.set_type.assign(1, 0); //store input set type
    fstream fs;
    fs.open("list.in", ios::app);
    int count = 0;

    cout << "部位 = " << endl;
    cin >> input.equip_type;
    cout << "0=生命 1=防禦 2=攻擊 3=速度 4=暴擊 5=命中 6=暴傷 7=吸血 8=反擊 9=抵抗 10=夾擊 11=憤怒 12=免疫" << endl;
    cout << "set_type = " << endl;
    cin >> input.set_type[0];
    cout << "攻擊 = " << endl;
    cin >> input.atk;
    if (input.atk != 0)
        count++;
    cout << "攻擊% = " << endl;
    cin >> input.atk_pctg;
    if (input.atk_pctg != 0)
        count++;
    cout << "生命 = " << endl;
    cin >> input.hp;
    if (input.hp != 0)
        count++;
    cout << "生命% = " << endl;
    cin >> input.hp_pctg;
    if (input.hp_pctg != 0)
        count++;
    cout << "防禦 = " << endl;
    cin >> input.def;
    if (input.def != 0)
        count++;
    cout << "防禦% = " << endl;
    cin >> input.def_pctg;
    if (input.def_pctg != 0)
        count++;
    cout << "暴擊 = " << endl;
    cin >> input.crit_chance;
    if (input.crit_chance != 0)
        count++;
    cout << "暴傷 = " << endl;
    cin >> input.crit_dmg;
    if (input.crit_dmg != 0)
        count++;
    cout << "夾擊 = " << endl;
    cin >> input.dual_atk_chance;
    if (input.dual_atk_chance != 0)
        count++;
    cout << "命中 = " << endl;
    cin >> input.effectiveness;
    if (input.effectiveness != 0)
        count++;
    cout << "抵抗 = " << endl;
    cin >> input.effect_resist;
    if (input.effect_resist != 0)
        count++;
    cout << "速度 = " << endl;
    cin >> input.speed;
    if (input.speed != 0)
        count++;
    if (count != 5)
    {
        cout << "input wrong!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        exit(1);
    }
    fs << input.equip_type << " " << input.set_type[0]
       << " " << input.atk << " " << input.atk_pctg << " " << input.hp << " " << input.hp_pctg
       << " " << input.def << " " << input.def_pctg << " " << input.crit_chance
       << " " << input.crit_dmg << " " << input.dual_atk_chance << " " << input.effectiveness
       << " " << input.effect_resist << " " << input.speed << endl;
    fs.close();
}