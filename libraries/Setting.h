#ifndef SETTING
#define SETTING

#include <bits/stdc++.h>
#include "SideFunctions.h"

using namespace std;

/*
A class created for handling reading settings from a JSON file.
*/
class Setting {
    private:
        string mSettingFile = "";
        vector < pair < string, string > > mDataSet;
        int mNumberOfTestcase = 0;
        bool mRemoveTemporaryFile = false;

        void readSettings() {
            ifstream setting(mSettingFile.c_str());

            string input = "";
            while (!setting.eof()) {
                getline(setting, input);
                if (input == "{" or input == "}") {
                    continue;
                }

                string key = "", value = "";
                input = removeSpecialCharacters(input);
                int index = 0;
                int last_index = input.length() - 1;

                while (index <= last_index and input[index] != ':') {
                    key += input[index++];
                }
                ++index;
                while (index <= last_index) {
                    value += input[index++];
                }

                mDataSet.push_back({key, value});
            }

            setting.close();
            return;
        }

        string removeSpecialCharacters(string str) {
            string result = "";
            for (char chr: str) {
                if (chr != ' ' and chr != ',' and chr != '\"') {
                    result += chr;
                }
            }
            return result;
        }

        int stringToInteger(string value) {
            int result = 0;
            for (char digit: value) {
                result *= 10;
                result += (digit - '0');
            }
            return result;
        }

    public:
        Setting(string settingFile = "") {
            if (fileExist(settingFile) == false) {
                cerr << "\nError! File \"" << settingFile << "\" is not exist!\n\n";
            }
            else {
                mSettingFile = settingFile;
                readSettings();
            }
        }

        int getNumberOfTestcase() {
            string value = "";
            for (pair < string, string > data: mDataSet) {
                if (data.first == "number_of_testcases") {
                    value = data.second;
                }
            }

            return stringToInteger(value);
        }

        int getRemoveFileIndicator() {
            string value = "";
            for (pair < string, string > data: mDataSet) {
                if (data.first == "remove_temporary_files") {
                    value = data.second;
                }
            }

            return ((value == "true") ? true : false);
        }
};

#endif