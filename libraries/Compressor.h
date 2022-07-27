#ifndef COMPRESSOR
#define COMPRESSOR

#include <bits/stdc++.h>

using namespace std;

class Compressor {
    private:
        string mPath = "";
        string mDestinationPath = "";

        string addQuotationmarks(string str) {
            if (str[0] == '\"' and str[0] == '\"') {
                return str;
            }
            return "\"" + str + "\"";
        }

    public:
        Compressor(string path = "", string destinationPath = "") {
            mPath = addQuotationmarks(path);
            mDestinationPath = addQuotationmarks(destinationPath);
        }

        void createCompressor() {
            if (mPath.length() == 0) {
                cerr << "\nMissing Path!\n";
                return;
            }

            if (mDestinationPath.length() == 0) {
                cerr << "\nMissing DestinationPath!\n";
                return;
            }

            // * create compressor file: "compressor.ps1"
            ofstream compressor_file;
            compressor_file.open("compressor.ps1");

            compressor_file << "$compress = @{\n";
            compressor_file << "\tPath = " << mPath << endl;
            compressor_file << "\tDestinationPath = " << mDestinationPath << endl;
            compressor_file << "}\n";
            compressor_file << "Compress-Archive @compress" << endl;

            // * close compressor file: "compressor.ps1".
            compressor_file.close();

            return;
        }

        void excecuteCompressor() {
            string command = "powershell -ExecutionPolicy Bypass -F compressor.ps1";
            system(command.c_str());
            return;
        }
};

#endif