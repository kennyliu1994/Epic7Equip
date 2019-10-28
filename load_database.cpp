#include "main.h"
#include "Kenny.h"

#include <fstream>
#include <vector>

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
