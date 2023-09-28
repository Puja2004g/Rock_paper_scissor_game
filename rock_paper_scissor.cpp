#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int u_score = 0;
int c_score = 0;

string computer_turn();
string your_turn();
void winning_condition(string user_choice, string comp_choice);
void the_winner();

int main()
{
    cout << "Welcome to rock paper scissor game!!!" << endl;
    cout << endl
         << "Please follow the rules" << endl;
    cout << "1. Rock beats scissors" << endl
         << "2. Scissors beats paper" << endl
         << "3. Paper beats rock" << endl
         << "4. If both players choose the same shape,it is a tie " << endl
         << "4. Enter your choices carefully, in case of wrong typing you have to restart the game" << endl
         << "5. You will be awarded with 1 point each time you win and no negetive marking" << endl
         << "6. In case of a tie no points will be given" << endl;

    cout << endl
         << "You have 5 choices and after the game completed the winner will be showed" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " round" << endl;
        string c = computer_turn();
        string u = your_turn();
        winning_condition(u, c);
    }
    the_winner();
    return 0;
}

string computer_turn()
{
    srand(time(0));
    int num = rand() % 3 + 1;
    if (num == 1)
    {
        return "rock";
    }
    else if (num == 2)
    {
        return "paper";
    }

    else if (num == 3)
    {
        return "scissor";
    }
}

string your_turn()
{
    string user;
    cout << "Enter your choice: ";
    cin >> user;

    return user;
}

void winning_condition(string user_choice, string comp_choice)
{

    // game tie conditions
    if (user_choice == "rock" && comp_choice == "rock")
    {
        cout << "Game tie" << endl;
    }
    else if (user_choice == "paper" && comp_choice == "paper")
    {
        cout << "Game tie" << endl;
    }
    else if (user_choice == "scissor" && comp_choice == "scissor")
    {
        cout << "Game tie" << endl;
    }

    // rock conditions
    else if (user_choice == "rock" && comp_choice == "paper")
    {
        c_score++;
    }
    else if (user_choice == "rock" && comp_choice == "scissor")
    {
        u_score++;
    }

    // paper conditions
    else if (user_choice == "paper" && comp_choice == "rock")
    {
        u_score++;
    }

    else if (user_choice == "paper" && comp_choice == "scissor")
    {
        c_score++;
    }

    // scissor conditions
    else if (user_choice == "scissor" && comp_choice == "rock")
    {
        c_score++;
    }
    else if (user_choice == "scissor" && comp_choice == "paper")
    {
        u_score++;
    }

    //in case of typing mistake
    else
    {
        cout<<"OOPS! you have to restart the game"<<endl;
        cout<<"Please re-run the game"<<endl;
    }
}

void the_winner()
{
    cout << endl
         << "Your final score is: " << u_score << endl;
    cout << "Computers final score is: " << c_score << endl;
    if (u_score > c_score)
    {
        cout << "Congratulations You wins the game." << endl;
    }
    else if (u_score < c_score)
    {
        cout << "Better luck next time!!!" << endl;
    }
}