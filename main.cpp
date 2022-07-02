#include <iostream>
#include <string>
#include <cstdlib> /* Enables rand() */
#include <ctime> /* Enables time() */

bool DEBUG = false; /* Not really needed. Maybe. */

int roll(int bonus, int dice)
{
    /* I'm not sure if this is how I want to do it. */
    return ((rand() % dice) + bonus);
}

void menu()
{
    std::cout << "MENU:" << std::endl;
    std::cout << "\tr: roll" << std::endl;
    std::cout << "\tm: menu" << std::endl;
    std::cout << "\tc: clear screen, then displays menu" << std::endl;
    std::cout << "\tq: quit" << std::endl;
}


int main()
{
    /* Create seed */
    srand(time(0));

    /* Dice types*/
    short int d20 = 21;

    /* multipliers */
    short int bonus = 2;

    /* Player input */
    char input;

    /* Testing dice.*/
    if(DEBUG)
    {
        std::cout << "Roll 0: " << roll(bonus, d20) << std::endl;
        std::cout << "Roll 1: " << roll(bonus, d20) << std::endl;
        std::cout << "Roll 2: " << roll(bonus, d20) << std::endl;
        std::cout << "Roll 3: " << roll(bonus, d20) << std::endl;
        std::cout << "Roll 4: " << roll(bonus, d20) << std::endl;
    }

    menu();

    while(true)
    {
        /* TODO: This is a little annoying. Maybe an indicator instead of "Input"? */
        std::cout << "Input: " << std::endl;

        std::cin >> input;

        /* TODO: Figure out how to do a switch! */
        if(input == 'r')
        {
            std::cout << "ROLLED: " << roll(bonus, d20) << std::endl;
        }
        else if(input == 'm')
        {
            menu();
        }
        else if(input == 'c')
        {
            std::cout << "\033[2J\033[1;1H";
            menu();
        }
        else if(input == 'q')
        {
            break;
        }else
        {
            std::cout << "Not proper input. (input 'm' for help!)" << std::endl;
        }
    }

    return 0;
}
