#include<iostream>
#include<string>
#include<sstream>
#include<map>

using namespace std;

class RomanNumeralsConverter {

    protected:
        map<int, string> lookup = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

    public:
        string convert(int number) {
            map<int, string>::reverse_iterator iterator;
            string solution = "";

            for(iterator = lookup.rbegin(); iterator != lookup.rend(); iterator++) {
                while(number >= iterator->first) {
                    solution += iterator->second;
                    number -= iterator->first;
                }
            }

            return solution;
        }
};

int main() {
    int value;

    while(true) {
        string input;

        cout << "Enter a number: ";
        getline(cin, input);

        stringstream stream(input);
        if(stream >> value) break;

        cout << "Enter a valid number!" << endl;
    }

    cout << "Roman numeral of the number " << value << " is: "
         << (new RomanNumeralsConverter())->convert(value)
         << endl;
}