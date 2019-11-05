#include "main.h"
#include "Kenny.h"

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
