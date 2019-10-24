#include "main.h"

// #include <fstream>

string operation;

// #include <time.h>

// int n_weapon;
// int n_helmet;
// int n_armor;
// int n_necklace;
// int n_ring;
// int n_boots;
// int n_need;
//double total_progress;
// individual *weapon;
// individual *helmet;
// individual *armor;
// individual *necklace;
// individual *ring;
// individual *boots;
// individual hero; //角色初始數值
// individual temp; //store for compare

int main(int argc, char **argv)
{
    operation = argv[1];

    clock_t start = clock();
    run();
    clock_t end = clock();
    cout << double(end - start) / CLOCKS_PER_SEC << " sec" << endl;
}

void run()
{
    if (operation == "input")
    {
        input_new_equipment();
    }
    if (operation == "calculate")
    {
        load_database();
        // calculate();
    }
}
