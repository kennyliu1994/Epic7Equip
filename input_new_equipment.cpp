#include "main.h"

#include <fstream>

void input_new_equipment()
{
    double count = 0;
    equipment e;

    cout << "部位 = " << endl;
    cin >> e.part;
    cout << "生命0 防禦1 攻擊2 速度3 暴擊4 命中5 暴傷6 "
         << "吸血7 反擊8 抵抗9 夾擊10 憤怒11 免疫12 " << endl;
    cout << "種類 = " << endl;
    cin >> e.type;
    cout << "攻擊 = " << endl;
    cin >> e.atk;
    if (e.atk != 0)
        count++;
    cout << "攻擊% = " << endl;
    cin >> e.atk_pctg;
    if (e.atk_pctg != 0)
        count++;
    cout << "生命 = " << endl;
    cin >> e.hp;
    if (e.hp != 0)
        count++;
    cout << "生命% = " << endl;
    cin >> e.hp_pctg;
    if (e.hp_pctg != 0)
        count++;
    cout << "防禦 = " << endl;
    cin >> e.def;
    if (e.def != 0)
        count++;
    cout << "防禦% = " << endl;
    cin >> e.def_pctg;
    if (e.def_pctg != 0)
        count++;
    cout << "暴擊 = " << endl;
    cin >> e.crit;
    if (e.crit != 0)
        count++;
    cout << "暴傷 = " << endl;
    cin >> e.crit_dmg;
    if (e.crit_dmg != 0)
        count++;
    cout << "命中 = " << endl;
    cin >> e.effective;
    if (e.effective != 0)
        count++;
    cout << "抵抗 = " << endl;
    cin >> e.resist;
    if (e.resist != 0)
        count++;
    cout << "速度 = " << endl;
    cin >> e.spd;
    if (e.spd != 0)
        count++;

    if (count != 5)
    {
        cout << "輸入數量不正確，結束" << endl;
        exit(1);
    }

    fstream fs_database;
    fs_database.open("database.txt", ios::app);
    fs_database << endl
                << e.part << " " << e.type << " " << e.atk << " "
                << e.atk_pctg << " " << e.hp << " " << e.hp_pctg << " "
                << e.def << " " << e.def_pctg << " " << e.crit << " "
                << e.crit_dmg << " " << e.effective << " "
                << e.resist << " " << e.spd;
    fs_database.close();
}