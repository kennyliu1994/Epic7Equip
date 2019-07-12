#include "global.h"

#include <string.h> //strcmp
#include <iostream>

int n_weapon;
int n_helmet;
int n_armor;
int n_necklace;
int n_ring;
int n_boots;
int n_need = 40;
individual *weapon;
individual *helmet;
individual *armor;
individual *necklace;
individual *ring;
individual *boots;
individual temp; //store for compare

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "input") == 0)
    {
        input();
    }
    if (strcmp(argv[1], "calculate") == 0)
    {
        calculate();
    }
}