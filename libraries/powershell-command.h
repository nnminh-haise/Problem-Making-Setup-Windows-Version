#include <bits/stdc++.h>

using namespace std;

void showDirectory(string directory, bool isRecurse = false) {
    string command = "powershell Get-ChildItem -Force " + directory;
    if (isRecurse)
        command += " -Recurse";
    system(command.c_str());
    return;
}

void createDirectory(string directory) {
    string command = "powershell New-Item -Path \"" + directory + "\" -ItemType Directory";
    system(command.c_str());
    return;
}

void createFile(string file) {
    string command = "powershell New-Item -Path \"" + file + "\" -ItemType File";
    system(command.c_str());
    return;
}

void copyFile(string file, string destination) {
    string command = "powershell Copy-Item -Path \"" + file + "\" -Destination \"" + destination + "\"";
    system(command.c_str());
    return;
}

void removeFile(string file) {
    string command = "powershell Remove-Item " + file;
    system(command.c_str());
    return;
}

void removeFiles(vector <string> files) {
    for (string file: files) {
        removeFile(file);
    }
    return;
}

void executeFile(string filename) {
    string str = "powershell -ExecutionPolicy Bypass -F " + filename;
    system(str.c_str());
    return;
}