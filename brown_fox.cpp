#include <iostream>
#include <string>
#include <limits>

using namespace std;

//function for finding the placement of the user input (letter or word)
int placement_num(const string& str, const string& user_input, 
                  bool case_sensitive = true, size_t user_start = 0)
{
    size_t place;
    string str_low, input_low;

    if (case_sensitive)
    {
        place = str.find(user_input, user_start); 
    }

    else
    {
        str_low = str.substr(user_start);
        input_low = user_input;

        for (char& c : str_low)
        {
            c = tolower(c);
        }

        for (char& c : input_low)
        {
            c = tolower(c);
        }

        place = str_low.find(input_low);

        if (place != string::npos)
        {
            place += user_start;
        }
    }


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
    char yn;
    size_t user_start;

    cout<< "Sentence: " <<  sentence;
    cout << "\n\nEnter a letter or word to find: \n";
    getline(cin, user_input);

    cout << "Case-sensitive? Enter y or n: ";
    cin >> yn;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    bool case_sensitive = (yn == 'y' || yn == 'Y');

    cout << "Starting position (default = 0): ";
    cin >> user_start;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    
    if (user_input.size()==1)
    {
        char_place = placement_num(sentence, user_input, case_sensitive, 
                                   user_start);

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
        substring_place = placement_num(sentence, user_input, 
                                        case_sensitive, user_start);

        if (substring_place != -1)
        {
            cout << substring_place << endl;
        }

        else
        {
            cout << "-1" << endl;
        }
    }

    return 0;
}
