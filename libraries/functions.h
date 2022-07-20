#include <bits/stdc++.h>

using namespace std;

string integerToString(int number) {
    string result = "";
    while (number > 0) {
        result = char((number % 10) + '0') + result;
        number /= 10;
    }
    return result;
}

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    return res * res;
}

long rand_int(const long minValue, const long maxValue) {
    return (rand() % (maxValue - minValue + 1) + minValue);
}

long long rand_ll(const long long minValue, const long long maxValue) {
    return (rand() % (maxValue - minValue + 1) + minValue);
}

double rand_double(double minValue, double maxValue, int numberOfDigit = 3) {
    vector <double> values;
    for (long i = minValue; i <= maxValue; ++i) {
        long long m = binpow(10, numberOfDigit);
        for (long j = 0; j <= m - 1; ++j) {
            double decimals = (j * 1.0) / m;
            double result = 1.0 * i + decimals;
            values.push_back(1.0 * i + decimals);
        }
    }
    return values[rand_int(0, values.size() - 1)];
}

long double rand_ld(long double minValue, long double maxValue, int numberOfDigit = 6) {
    vector <long double> values;
    for (long long i = minValue; i <= maxValue; ++i) {
        long long m = binpow(10, numberOfDigit);
        for (long long j = 0; j <= m - 1; ++j) {
            long double decimals = (j * 1.0) / m;
            long double result = 1.0 * i + decimals;
            values.push_back(1.0 * i + decimals);
        }
    }
    return values[rand_int(0, values.size() - 1)];
}

string rand_str(int len, string template_string = "qwertyuiopasdfghjklzxcvbnm") {
    string result = "";
    for (int i = 0; i < len; ++i) {
        result += template_string[rand_int(0, template_string.length() - 1)];
    }
    return result;
}

vector <int> rand_list(int len, int minValue, int maxValue, bool isDistinct = false) {
    vector <int> result(len, 0), is_free(len, 0);

    if (isDistinct) {
        int a = minValue, b = maxValue;
        while (b - a + 1 != len) {
            a = rand_int(minValue, maxValue);
            b = rand_int(minValue, maxValue);
        }

        for (int value = a; value <= b; ++value) {
            int index = -1;
            do {
                index = rand_int(0, len - 1);
            } while (is_free[index] != 0);
            result[index] = value;
            is_free[index] = 1;
        }
    } else {
        for (int &item: result) {
            item = rand_int(minValue, maxValue);
        }
    }

    return result;
}

vector <long long> rand_list_ll(int len, long long minValue, long long maxValue, bool isDistinct = false) {
    vector <long long> result(len, 0), is_free(len, 0);

    if (isDistinct) {
        long long a = minValue, b = maxValue;
        while (b - a + 1 != len) {
            a = rand_int(minValue, maxValue);
            b = rand_int(minValue, maxValue);
        }

        for (long long value = a; value <= b; ++value) {
            int index = -1;
            do {
                index = rand_int(0, len - 1);
            } while (is_free[index] != 0);
            result[index] = value;
            is_free[index] = 1;
        }
    } else {
        for (long long &item: result) {
            item = rand_int(minValue, maxValue);
        }
    }

    return result;
}

vector <double> rand_list_double(int len, double minValue, double maxValue, bool isDistinct = false) {
    vector <double> result(len, 0), is_free(len, 0);

    if (isDistinct) {
        double a = minValue, b = maxValue;
        while (b - a + 1 != len) {
            a = rand_int(minValue, maxValue);
            b = rand_int(minValue, maxValue);
        }

        for (double value = a; value <= b; ++value) {
            int index = -1;
            do {
                index = rand_int(0, len - 1);
            } while (is_free[index] != 0);
            result[index] = value;
            is_free[index] = 1;
        }
    } else {
        for (double &item: result) {
            item = rand_int(minValue, maxValue);
        }
    }

    return result;
}

vector <long double> rand_list_ld(int len, long double minValue, long double maxValue, bool isDistinct = false) {
    vector <long double> result(len, 0), is_free(len, 0);

    if (isDistinct) {
        long double a = minValue, b = maxValue;
        while (b - a + 1 != len) {
            a = rand_int(minValue, maxValue);
            b = rand_int(minValue, maxValue);
        }

        for (long double value = a; value <= b; ++value) {
            int index = -1;
            do {
                index = rand_int(0, len - 1);
            } while (is_free[index] != 0);
            result[index] = value;
            is_free[index] = 1;
        }
    } else {
        for (long double &item: result) {
            item = rand_int(minValue, maxValue);
        }
    }

    return result;
}

int countDigit(long long x) {
    int counter = 0;
    while (x > 0) {
        counter++;
        x /= 10;
    }
    return counter;
}

string generateID(int date) {
    string custom_template = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string result = rand_str(1, "ITMC") + to_string(rand_int(10, 99)) + to_string(rand_int(10, 99)) + to_string(date) + rand_str(2, custom_template) + to_string(rand_int(10, 99));
    return result;
}
