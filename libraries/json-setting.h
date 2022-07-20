#include <bits/stdc++.h>

using namespace std;

class JSON {
    public:
        vector < pair <string, string> > dataset;
        int numberOfTestcase;
        bool createLog;
        bool removeClusterFiles;

        int evalutateValueType(const string value) {
            bool isNum = true;
            for (char chr: value)
                if (chr > '9' or chr < '0') {
                    isNum = false;
                    break;
                }
            if (isNum)
                return 1;
            if (value == "true" or value == "false")
                return 2;
            return 0;
        }

        void showData() {
            cout << "Data in JSON:\n\n";
            for (pair <string, string> data: dataset) {
                cout << "Attribute: " << data.first << endl;
                cout << "Value: " << data.second << endl;
                cout << "\n";
            }
            return;
        }

        void readJson(const string file) {
            ifstream jsonFile;
            string dataInline;

            jsonFile.open(file);
            while (jsonFile.eof() == false) {
                getline(jsonFile, dataInline);
                pair <string, string> data = extractData(dataInline);
                if (data.first != "" and data.second != "")
                    dataset.push_back(data);
            }
            jsonFile.close();

            //  * set data
            for (pair <string, string> data: dataset) {
                if (data.first == "numberOfTestcase") {
                    numberOfTestcase = stringToInteger(data.second);
                }
                else if (data.first == "createLog") {
                    createLog = ((data.second == "true") ? true : false);
                }
                else if (data.first == "removeClusterFiles") {
                    removeClusterFiles = ((data.second == "true") ? true : false);
                }
            }

            return;
        }


    private:
        int stringToInteger(const string str) {
            int result = 0;
            for (char chr: str) {
                result *= 10;
                result += (int)(chr - '0');
            }
            return result;
        }

        int evaluteCharacter(const char chr) {
            switch (chr) {
                case '{':
                case '}':
                case ',':
                    return 0;
                default:
                    return 1;
            }
            return -1;
        }

        bool isValidData(const string data) {
            bool result = true;
            int cnt = 0;
            for (char chr: data)
                if (chr == '\"')
                    cnt++;
            if (cnt % 2 != 0)
                result = false;
            return result;
        }

        string removeSpaces(const string data) {
            string result = "";
            for (char chr: data)
                if (chr != ' ')
                    result += chr;
            return result;
        }

        string removeQuotationmarksAndComma(const string data) {
            string result = "";
            for (char chr: data)
                if (chr != '\"' and chr != ',')
                    result += chr;
            return result;
        }

        pair <string, string> extractData(string dataInline) {
            if (dataInline.length() == 1 or isValidData(dataInline) == false)
                return {"", ""};

            pair <string, string> result({"", ""});

            dataInline = removeSpaces(dataInline);
            int n = dataInline.length();
            string attribute = "", value = "";

            // * Get Attribute
            int isPaired = 0;
            int index = 0;
            
            while (index < n) {
                char chr = dataInline[index];
                if (chr == '\"')
                    if (isPaired == 0) {
                        isPaired = 1;
                        while (dataInline[index + 1] != '\"')
                            attribute += dataInline[++index];
                    }
                    else {
                        break;
                    }
                ++index;
            }

            // * Get Value
            while (dataInline[index] != ':')
                ++index;
            ++index;
            while (index < n)
                value += dataInline[index++];

            result.first = attribute;
            result.second = removeQuotationmarksAndComma(value) ;
            return result;
        }

};
