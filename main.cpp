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

    /* play state */
    bool play = true;

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

    while(play)
    {
        std::cout << "> ";
        
        int highest_roll;
        int curr_roll;

        std::cin >> input;

        switch(input)
        {
            case 'r':
                curr_roll = roll(bonus, d20);
                std::cout << "ROLLED: " << curr_roll;

                /* TODO: Retain last 10 rolls. (see: STL.Vector) */
                /* I don't know how useful this will be... maybe for stat
                 * creation?*/
                if(curr_roll > highest_roll)
                {
                    highest_roll = curr_roll;
                }
                std::cout << " (highest: " << highest_roll << ")" << std::endl;
                break;
            case 'm':
                menu();
                break;
            case 'c':
                std::cout << "\033[2J\033[1;1H";
                menu();
                break;
            case 'q':
                play = false;
                break;
            default:
                std::cout << "Not proper input. (input 'm' for help!)" << std::endl;
                break;
        }
    }

    return 0;
}
