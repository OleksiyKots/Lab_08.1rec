#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int CountStarsRecursively(char* str, int i) {
    if (strlen(str) < 3 || str[i + 2] == 0)
        return 0;
    if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
        return 1 + CountStarsRecursively(str, i + 1);
    else
        return CountStarsRecursively(str, i + 1);
}

char* ReplaceStarsRecursively(char* result, const char* str, char* temp, int i) {
    if (str[i + 2] == 0) {
        *temp++ = str[i++];
        *temp++ = str[i++];
        *temp = '\0';
        return result;
    }

    if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*') {
        strcat(temp, "!!");
        return ReplaceStarsRecursively(result, str, temp + 2, i + 3);
    }
    else {
        *temp++ = str[i++];
        *temp = '\0';
        return ReplaceStarsRecursively(result, str, temp, i);
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contains " << CountStarsRecursively(str, 0) << " groups of '***'" << endl;
    char* result = new char[151];
    result[0] = '\0';
    ReplaceStarsRecursively(result, str, result, 0);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << result << endl;
    delete[] result;
    return 0;
}
