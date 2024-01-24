#include <iostream>
#include <string>
#include <limits>

using namespace std;

//function for finding the placement of the user input (letter or word)
int placement_num(const string& str, string& user_input)
{
    size_t place = str.find(user_input);

    //finds the place where the input occurs
    if (place != string::npos)
    {
        return static_cast<int> (place);
    }

    else
    {
        return -1;
    }
}

//asks for input and prints out the position
int main()
{
    string sentence = "The quick brown fox",
           user_input;
    int char_place,
        substring_place;

    cout << "Enter a letter or word to find: \n";
    getline(cin, user_input);

    if (user_input.size()==1)
    {
        char_place = placement_num(sentence, user_input);

        if (char_place != -1)
        {
            cout << char_place << endl;
        }

        else
        {
            cout << "-1" << endl;
        }
    }

    else
    {
        substring_place = placement_num(sentence, user_input);

        if (substring_place != -1)
        {
            cout << substring_place << endl;
        }

        else
        {
            cout << "-1" << endl;
        }
    }
}
