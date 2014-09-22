#include "filemanager.h"

FileManager::FileManager()
{
    //ctor

    identifierFound=false;
}

FileManager::~FileManager()
{
    //dtor
}

void FileManager::LoadContent(const char *filename,vector< vector<string> > &attributes,vector<vector<string> > &contents)
{
    string line,newLine;
    ifstream openfile(filename);
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            stringstream str;
            getline(openfile,line);


            if(line.find("Load=") != string::npos)
            {
                type=Attributes;
                line=line.erase(0,line.find("=")+1);
                tempAttributes.clear();
            }
            else
            {
                type=Contents;
                tempContents.clear();
            }

            str<< line;


            while(getline(str,newLine,']'))
            {
                newLine.erase(remove(newLine.begin(),newLine.end(), '['),newLine.end());


                string erase= " \t\n\r";
                newLine.erase(newLine.find_last_not_of(erase)+1);

                if(type == Attributes)
                {
                    tempAttributes.push_back(newLine);

                }
                else
                {
                    tempContents.push_back(newLine);
                }



                cout<<newLine<<endl;


            }
            if(type == Contents && tempContents.size() >0 )
                {
                    attributes.push_back(tempAttributes);
                    contents.push_back(tempContents);
                }
        }
    }
    else
    {

    }
}
void FileManager::LoadContent(const char *filename,vector< vector<string> > &attributes,vector<vector<string> > &contents,string identifier)
{
    string line,newLine;
    ifstream openFile(filename);
    if(openFile.is_open())
    {
        while(!openFile.eof())
        {
            stringstream str;
            getline(openFile,line);
            if(line.find("EndLoad=") != string::npos &&
            line.find(identifier) != string::npos)
            {
                identifierFound = false;
                break;
            }
            else if(line.find("Load=") != string::npos &&
            line.find(identifier) != string::npos)
            {
                identifierFound= true;
                continue;
            }



            if(identifierFound)
            {
//            vector <string> lineVector;
                if(line.find("Load=") != string::npos)
                {
                    type = Attributes;
                    line = line.erase(0,line.find("=")+1);
                    tempAttributes.clear();
                }
                else
                {
                    type =Contents;
                    tempContents.clear();
                }

                str<< line;

                while(getline(str,newLine,']'))
                {

                    newLine.erase(remove(newLine.begin(),newLine.end(), '['),newLine.end());

                    string erase= " \t\n\r";
                    newLine.erase(newLine.find_last_not_of(erase)+1);

                    if(type == Attributes)
                    {
                        tempAttributes.push_back(newLine);

                    }
                    else
                    {
                        tempContents.push_back(newLine);
                    }

                    cout<<newLine<<endl;
                }
                if(type == Contents && tempContents.size() >0 )
                    {
                        attributes.push_back(tempAttributes);
                        contents.push_back(tempContents);
                    }
            }

        }
    }
    else
    {

    }
}
