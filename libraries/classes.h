#include <bits/stdc++.h>

using namespace std;

class Compress {
    public:
        void createArchiveFile(const vector <string> &files, const string destinationPath) {
            string path = setPath(files);

            createFile("zip.ps1");
            ofstream zipFile;
            zipFile.open("zip.ps1");
            zipFile << "$compress = @{" << endl;
            zipFile << "\tPath = " << path << endl;
            zipFile << "\tDestinationPath = \"" << destinationPath << "\"" << endl;
            zipFile << "}" << endl;
            zipFile << "Compress-Archive @compress" << endl;
            zipFile.close();
            return;
        }

    private:
        string setPath(const vector <string> &files) {
            string newPath = "";
            for (int i = 0; i < (int)files.size(); ++i) {
                newPath = newPath + "\"" + files[i] + "\"";
                if (i < (int)files.size() - 1)
                    newPath += ", ";
            }
            return newPath;
        }
};
