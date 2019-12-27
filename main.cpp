#include "main.h"
#include "Kenny.h"

#include <fstream>

string input_path = "./input/epic7_output.txt";
string output_path;
string operation;
string hero_name;
string need_type;
string sort_by;
int need_crit = 0;
int need_spd = 0;

int main(int argc, char **argv)
{
    Kenny_convert ct;

    operation = argv[1];
    if (operation == "calculate")
    {
        output_path = "./output/" + ct.char2str(argv[2]) + "_" + ct.char2str(argv[3]) + ".txt";
        hero_name = argv[2];
        need_type = argv[3];
        sort_by = argv[4];
        need_crit = ct.char2int(argv[5]);
        need_spd = ct.char2int(argv[6]);
    }

    clock_t start = clock();
    run();
    clock_t end = clock();
    cout << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;
}

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
    fs_database.open(input_path.c_str(), ios::app);
    fs_database << endl
                << e.part << " " << e.type << " " << e.atk << " "
                << e.atk_pctg << " " << e.hp << " " << e.hp_pctg << " "
                << e.def << " " << e.def_pctg << " " << e.crit << " "
                << e.crit_dmg << " " << e.effective << " "
                << e.resist << " " << e.spd;
    fs_database.close();
}

void load_database()
{
    fstream fs_database, fs_w, fs_h, fs_a, fs_n, fs_r, fs_b;
    fs_database.open(input_path.c_str(), ios::in);
    if (!fs_database)
    {
        cout << "cant find epic7_output.txt" << endl;
        exit(1);
    }
    fs_w.open("./parts/weapon.txt", ios::out);
    fs_h.open("./parts/helmet.txt", ios::out);
    fs_a.open("./parts/armor.txt", ios::out);
    fs_n.open("./parts/necklace.txt", ios::out);
    fs_r.open("./parts/ring.txt", ios::out);
    fs_b.open("./parts/boots.txt", ios::out);

    string line;         //一行
    vector<string> word; //一個字
    vector<int> index;
    index.assign(6, 0);
    while (getline(fs_database, line))
    {
        split(line, word, ' ');
        if (word[0] == "w")
        {
            fs_w << index[0]
                 << " " << word[0]
                 << " " << word[1];
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_w << " " << word[i];
            }
            fs_w << " *"; //used or not used
            fs_w << endl;
            index[0]++;
        }
        else if (word[0] == "h")
        {
            fs_h << index[1]
                 << " " << word[0]
                 << " " << word[1];
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_h << " " << word[i];
            }
            fs_h << " *"; //used or not used
            fs_h << endl;
            index[1]++;
        }
        else if (word[0] == "a")
        {
            fs_a << index[2]
                 << " " << word[0]
                 << " " << word[1];
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_a << " " << word[i];
            }
            fs_a << " *"; //used or not used
            fs_a << endl;
            index[2]++;
        }
        else if (word[0] == "n")
        {
            fs_n << index[3]
                 << " " << word[0]
                 << " " << word[1];
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_n << " " << word[i];
            }
            fs_n << " *"; //used or not used
            fs_n << endl;
            index[3]++;
        }
        else if (word[0] == "r")
        {
            fs_r << index[4]
                 << " " << word[0]
                 << " " << word[1];
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_r << " " << word[i];
            }
            fs_r << " *"; //used or not used
            fs_r << endl;
            index[4]++;
        }
        else if (word[0] == "b")
        {
            fs_b << index[5]
                 << " " << word[0]
                 << " " << word[1];
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_b << " " << word[i];
            }
            fs_b << " *"; //used or not used
            fs_b << endl;
            index[5]++;
        }
    }

    fs_database.close();
    fs_w.close();
    fs_h.close();
    fs_a.close();
    fs_n.close();
    fs_r.close();
    fs_b.close();
}

void run()
{
    if (operation == "input")
    {
        input_new_equipment();
    }
    if (operation == "database")
    {
        load_database(); //datebase update
    }
    if (operation == "calculate")
    {
        calculate();
    }
}