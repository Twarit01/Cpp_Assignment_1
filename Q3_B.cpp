//Checks whether the string is palindrome
#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    int left = 0, right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            cout << "\"" << str << "\" is not a palindrome.\n";
            return 1; 
        }
        left++;
        right--;
    }
    cout << "\"" << str << "\" is a palindrome.\n";
    return 0;
}