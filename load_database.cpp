#include "main.h"
#include "Kenny.h"

#include <fstream>
#include <vector>

string type_in_Chinese(const int i)
{
    switch (i)
    {
    case 0:
        return "生命";
        break;
    case 1:
        return "防禦";
        break;
    case 2:
        return "攻擊";
        break;
    case 3:
        return "速度";
        break;
    case 4:
        return "暴擊";
        break;
    case 5:
        return "命中";
        break;
    case 6:
        return "暴傷";
        break;
    case 7:
        return "吸血";
        break;
    case 8:
        return "反擊";
        break;
    case 9:
        return "抵抗";
        break;
    case 10:
        return "夾擊";
        break;
    case 11:
        return "憤怒";
        break;
    case 12:
        return "免疫";
        break;
    default:
        return "load type error";
        break;
    }
}

void load_database()
{
    fstream fs_database, fs_w, fs_h, fs_a, fs_n, fs_r, fs_b;
    fs_database.open("database.txt", ios::in);
    fs_w.open("./parts/weapon.txt", ios::out);
    fs_h.open("./parts/helmet.txt", ios::out);
    fs_a.open("./parts/armor.txt", ios::out);
    fs_n.open("./parts/necklace.txt", ios::out);
    fs_r.open("./parts/ring.txt", ios::out);
    fs_b.open("./parts/boots.txt", ios::out);

    string line;         //一行
    vector<string> word; //一個字
    Kenny_convert ct;
    while (getline(fs_database, line))
    {
        split(line, word, ' ');
        if (word[0] == "w")
        {
            int index = 0;
            fs_w << index
                 << " " << type_in_Chinese(ct.str2int(word[1]));
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_w << " " << word[i];
            }
            fs_w << endl;
        }
        else if (word[0] == "h")
        {
            int index = 0;
            fs_h << index
                 << " " << type_in_Chinese(ct.str2int(word[1]));
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_h << " " << word[i];
            }
            fs_h << endl;
        }
        else if (word[0] == "a")
        {
            int index = 0;
            fs_a << index
                 << " " << type_in_Chinese(ct.str2int(word[1]));
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_a << " " << word[i];
            }
            fs_a << endl;
        }
        else if (word[0] == "n")
        {
            int index = 0;
            fs_n << index
                 << " " << type_in_Chinese(ct.str2int(word[1]));
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_n << " " << word[i];
            }
            fs_n << endl;
        }
        else if (word[0] == "r")
        {
            int index = 0;
            fs_r << index
                 << " " << type_in_Chinese(ct.str2int(word[1]));
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_r << " " << word[i];
            }
            fs_r << endl;
        }
        else if (word[0] == "b")
        {
            int index = 0;
            fs_b << index
                 << " " << type_in_Chinese(ct.str2int(word[1]));
            for (unsigned int i = 2; i < word.size(); i++)
            {
                fs_b << " " << word[i];
            }
            fs_b << endl;
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
