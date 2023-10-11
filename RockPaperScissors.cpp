#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
 * Determines if choice1 beats choice2.
 *
 * Valid values for both parameters are:
 * 1: Rock
 * 2: Paper
 * 3: Scissors
 *
 * Rock beats Scissors, Paper beats Rock, Scissors beat Paper.
 *
 * Returns true if choice1 beats choice2
 */
bool beats(int choice1, int choice2)
{
   switch (choice1)
   {
       case 1:                      //choice1 is Rock
            if (choice2 == 2)
               return false;        //Paper beats Rock
            else
                return true;        //Rock beats Scissors
        case 2:                     //choice1 is Paper
            if (choice2 == 1)
                return true;        //Paper beats Rock
            else
                return false;       //Scissors beats Paper
        case 3:                     //choice1 is Scissors
            if (choice2 == 1)
                return false;       //Paper beats Scissors
            else
                return true;        //Scissors beats Rock
        default:
            exit(1);
   }
}

//-----------function for random numbors in range of 1-3--------->
int randomNum()
{
    srand((unsigned)time(0));
    return (rand() % 3) + 1;        //Random value % 3 + 1 = 0 +1 ,1 +1 ,2 +1
}

//----------function to print out the choice------------------>
string printchoice(int a)
{
    switch(a)
    {
        case 1:
            return "choice is Rock";
        case 2:
            return "choice is Paper";
        case 3:
            return "choice is Scissors";
        default:
            return "No Option";
    }
}

/*
 * Performs a game of Rock-Paper-Scissors.
 *
 * Prompts the player for a choice of Rock, Paper or Scissors (1, 2 or 3)
 * and chooses a second choice to play against.
 *
 * Displays the choice of the player and computer.
 *
 * Returns true if the player wins, false if the player loses.
 * Repeats the game in case of a draw.
 */
bool play()
{
    int player;
    std::cout << "Select 1, 2 or 3 for Rock,Paper or Scissors : ";
    std::cin >> player;
    int comp = randomNum();
    std::cout << "Your " << printchoice(player) << std::endl;
    std::cout << "Computer's " << printchoice(comp) << std::endl;
    if (player == comp)
    {
        std::cout<<"Same choice. Tie. \n";
        play();
    }
    return beats(player, comp);
}

/*
 * Performs three games of Rock-Paper-Scissors and returns true if the player
 * wins at least two of them.
 */
bool bestOf3()
{
    int player = 0;
    int comp = 0;
    while (player != 2 && comp != 2)
        (play() ? player++ : comp++);
    if (player == 2)
        return true;
    else
        return false;
}

/*
 * Performs five games of Rock-Paper-Scissors and returns true if the player
 * wins at least three of them.
 */
bool bestOf5()
{
    int player = 0;
    int comp = 0;
    while (player != 3 && comp != 3)
        (play() ? player++ : comp++);
    if (player == 3)
        return true;
    else
        return false;
}

/******************************************************************************/
// Template code starts here. Please do not edit beyond this point.
/******************************************************************************/

/*
 * Converts a game mode choice into the game mode's name for display purposes.
 *
 * Note: we can only return a raw pointer here because string literals have
 * static storage duration i.e. they survive for the whole run time of the
 * program. Returning a pointer to something that is not a string literal
 * would be dangerous!
 */
const char *gameModeToString(int mode)
{
    switch (mode)
    {
    case 1:
        return "Single";
    case 2:
        return "Best of Three";
    case 3:
        return "Best of Five";
    default:
        return "invalid";
    }
}

int main()
{
    // Initialize random seed
    srand(time(nullptr));

    int mode = 0;
    while (true)
    {
        cout << "Choose a game mode: \n"
             << "1: " << gameModeToString(1) << "\n"
             << "2: " << gameModeToString(2) << "\n"
             << "3: " << gameModeToString(3) << "\n"
             << "0: exit\n";
        cout << "Your choice: ";
        cin >> mode;
        if (mode == 0)
            return 0;
        if (mode < 1 || mode > 3)
        {
            cout << "Invalid choice\n";
            continue;
        }
        break;
    }

    bool won = false;
    switch (mode)
    {
    case 1:
        won = play();
        break;
    case 2:
        won = bestOf3();
        break;
    case 3:
        won = bestOf5();
        break;
    default:
        // unreachable code
        return -1;
    }

    if (won)
    {
        cout << "Congratulations! You win the game!\n";
    }
    else
    {
        cout << "Unfortunate! You lose the game.\n";
    }
    //std::getchar();
    return 0;
}