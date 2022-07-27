#ifndef SIDE_FUNCTIONS
#define SIDE_FUNCTIONS

#include <bits/stdc++.h>

using namespace std;

/*
* Function returns a boolean value, true if the file is exist in the current directory, and false in other cases.
@param: file - a string contains the file's name.
@logic: read more at here: cplusplus.com/reference/ios/ios/rdstate/
*/
bool fileExist(string file) {
    ifstream targetFile;

    targetFile.open(file.c_str());
    if ((targetFile.rdstate() & ifstream::failbit) != 0) {
        return false;
    }

    return true;
}

/*
* Function retrun the number of digits of the given integer.
@param: x - a 64-bits integer.
*/
int countDigit(long long x) {
    int counter = 0;
    while (x > 0) {
        counter++;
        x /= 10;
    }
    return counter;
}

/*
* Function return a string with the content exactly same with the given long long integer.
@param: number - a 64-bits integer, which will be "converted" into a string.
*/
string integerToString(long long number) {
    string result = "";
    while (number > 0) {
        result = char((number % 10) + '0') + result;
        number /= 10;
    }
    return result;
}

/*
* Function calculates the result of the expression: a^b or a to the power of b using binary algorithm.
@param: a - a 64-bits integer.
@param: b - a 64-bits integer.
*/
long long binaryPower(long long a, long long b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    long long res = binaryPower(a, b / 2);
    if (b % 2)
        return res * res * a;
    return res * res;
}

/*
* Function returns a formated string containing numbers with added '0' in front if needed.
@param: targetNumber - an integer which will be contained in the string.
@param: maximumValue - an integer hold the maximum value which will be display.
!ALERT: the targetNumber should be smaller or equal to the maximumValue.
*/
string getFormatedNumber(int targetNumber, int maximumValue) {
    string result = "";
    int maximum_number_of_digit = countDigit(maximumValue);

    while (targetNumber > 0) {
        result = (char)(targetNumber % 10 + '0') + result;
        targetNumber /= 10;
    }

    while (result.length() < maximum_number_of_digit) {
        result = '0' + result;
    }
    return result;
}

#endif