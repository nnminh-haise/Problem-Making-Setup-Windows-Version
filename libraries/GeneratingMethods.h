#ifndef GENERATING_METHODS
#define GENERATING_METHODS

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;



/*
Represent a closed continiuous set of integers.
*/
class ClosedSet {
    private:
        long long mMinValue = 0;
        long long mMaxValue = 0;

    public:
        ClosedSet(long long minValue = 0, long long maxValue = 0) {
            mMinValue = minValue;
            mMaxValue = maxValue;
            return;
        }

        long long getMinValue() {
            return mMinValue;
        }

        long long getMaxValue() {
            return mMaxValue;
        }

        long long getSize() {
            return (mMaxValue - mMinValue + 1);
        }
};


/*
* Function returns a random integer number in the given range.
@param: objectRange - a ClosedSet represents the set of values.
*/
int randInt(ClosedSet objectRange) {
    return (rand() % objectRange.getSize() + objectRange.getMinValue());
}


/*
* Function returns a random integer number in the given range except the numbers in the excepted value list.
@param: objectRange - a ClosedSet represents the set of values.
@param: exceptionValues - a vector contains the excepted values.
*/
int randIntExcept(ClosedSet objectRange, vector <int> exceptedValues) {
    set <int> exceptions;
    for (int value: exceptedValues)
        exceptions.insert(value);

    int value = 0;
    do {
        value = randInt(objectRange);
    } while (exceptions.count(value) != 0);

    return value;
}

/*
* Function returns a random long long integer number in the given range.
@param: objectRange - a ClosedSet represents the set of values.
*/
long long randLLInt(ClosedSet objectRange) {
    return (rand() % objectRange.getSize() + objectRange.getMinValue());
}

/*
* Function returns a shuffled vector of integers from the given vector.
@param: list - a vector of integers.
*/
vector <int> shuffleList(vector <int> list) {
    vector <int> result;

    for (int i = 0; i < (int)list.size(); ++i) {
        int j = 0;
        do {
            j = randInt(ClosedSet(0, (int)list.size() - 1));
        } while (j == i);
        swap(list[i], list[j]);
    }

    for (int item: list)
        result.push_back(item);

    return result;
}

/*
* Function returns a shuffled vector of long long integers from the given vector.
@param: list - a vector of integers.
*/
vector <long long> shuffleLLList(vector <long long> list) {
    vector <long long> result;

    for (int i = 0; i < (int)list.size(); ++i) {
        int j = 0;
        do {
            j = randInt(ClosedSet(0, (int)list.size() - 1));
        } while (j == i);
        swap(list[i], list[j]);
    }

    for (long long item: list)
        result.push_back(item);

    return result;
}

/*
* Function returns a random generated vector of integers in between a given range.
@param: numberOfElements - an integer contains number of element of the vector.
@param: objectRange - a ClosedSet represents the set of values.
@param: containsDuplicates - a boolean indicator if the vector is allowed to contains duplicate elements.
*/
vector <int> randList(int numberOfElements, ClosedSet objectRange, bool containsDuplicates = false) {
    vector <int> result;

    if (containsDuplicates == false) {
        set <int> distinct_numbers;
        while (distinct_numbers.size() <= numberOfElements) {
            distinct_numbers.insert(randInt(objectRange));
        }

        for (int number: distinct_numbers) {
            result.push_back(number);
        }
    }
    else {
        int number_of_distinct_number = randInt(ClosedSet(1, numberOfElements));
        int number_of_duplicate_number = numberOfElements - number_of_distinct_number;
        set <int> distinct_numbers;

        while (distinct_numbers.size() <= number_of_distinct_number) {
            distinct_numbers.insert(randInt(objectRange));
        }

        for (int number: distinct_numbers) {
            result.push_back(number);
        }

        for (int rep = 1; rep <= number_of_duplicate_number; ++rep) {
            result.push_back(result[randInt(ClosedSet(0, (int)result.size() - 1))]);
        }
    }

    return result = shuffleList(result);
}

/*
* Function returns a random generated vector of long long integers in between a given range.
@param: numberOfElements - an integer contains number of element of the vector.
@param: objectRange - a ClosedSet represents the set of values.
@param: containsDuplicates - a boolean indicator if the vector is allowed to contains duplicate elements.
*/
vector <long long> randLLList(int numberOfElements, ClosedSet objectRange, bool containsDuplicates = false) {
    vector <long long> result;

    if (containsDuplicates == false) {
        set <long long> distinct_numbers;
        while (distinct_numbers.size() <= numberOfElements) {
            distinct_numbers.insert(randInt(objectRange));
        }

        for (long long number: distinct_numbers) {
            result.push_back(number);
        }
    }
    else {
        int number_of_distinct_number = randInt(ClosedSet(1, numberOfElements));
        int number_of_duplicate_number = numberOfElements - number_of_distinct_number;
        set <long long> distinct_numbers;

        while (distinct_numbers.size() <= number_of_distinct_number) {
            distinct_numbers.insert(randInt(objectRange));
        }

        for (long long number: distinct_numbers) {
            result.push_back(number);
        }

        for (int rep = 1; rep <= number_of_duplicate_number; ++rep) {
            result.push_back(result[randInt(ClosedSet(0, (int)result.size() - 1))]);
        }
    }

    return result = shuffleLLList(result);
}

/*
* Function returns a random generated string with the length {numberOfCharacters} and all the characters are in the {templateString}. Also there is an option for a no duplicates for the generated string.
@param: numberOfCharacters - an integer contains the number of characters in the generated string or the string's length.
@param: templateString - a given collection of characters will be randomly picked to generate the result string.
@param: isDistinct - a boolean indicator if there will be duplicants in the result string.
*/
string randStr(int numberOfCharacters, const string templateString = "qwertyuiopasdfghjklzxcvbnm", const bool isDistinct = false) {
    string result = "";

    if (isDistinct) {
        if (numberOfCharacters > templateString.length())
            return "ERROR";
        
        set <char> chrs;

        while (chrs.size() < numberOfCharacters)
            chrs.insert(templateString[randInt(ClosedSet(0, (int)templateString.length()))]);

        for (char chr: chrs)
            result += chr;
    }
    else {
        for (int i = 0; i < numberOfCharacters; ++i)
            result += templateString[randInt(ClosedSet(i, (int)templateString.length()))];
    }

    return result;
}

/*
* Function returns a formated string use as a problem's ID for ITMC's competitive programming website.
@param: date - an integer indicate the current date.
*/
string generateID(int date) {
    string custom_template = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string result = randStr(1, "ITMC") + to_string(randInt(ClosedSet(10, 99))) + to_string(randInt(ClosedSet(10, 99))) + to_string(date) + randStr(2, custom_template) + to_string(randInt(ClosedSet(10, 99)));
    return result;
}

#endif