#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>



using namespace std;

class FileManager
{
    public:
        FileManager();
        virtual ~FileManager();

        void LoadContent(const char *filename,vector< vector<string> > &attributes,vector<vector<string> > &contents);
        void LoadContent(const char *filename,vector< vector<string> > &attributes,vector<vector<string> > &contents,string identifier);

    protected:


    private:


    enum LoadType { Attributes,Contents };
    LoadType type;
    bool identifierFound;

    vector<string> tempAttributes,tempContents;
};

#endif // FILEMANAGER_H
