#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    ifstream fin("file.in");
    ofstream fout("file.out");
    char linie[256],*cuv;
    while(fin.getline(linie,256))
    {
        cuv=strtok(linie,">");
        while(cuv!=NULL)
        {
            fout<<cuv<<">"<<endl;
            cuv=strtok(NULL,">");
        }
    }
    fin.close();
    fout.close();
    return 0;
}
