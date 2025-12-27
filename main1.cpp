#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    ifstream fin("file.in");
    ofstream fout("file.out");
    char linie[256],aux[256];
    while(fin.getline(linie,256))
    {
        if(strlen(linie)==0)
        {
            continue;
        }
        if(strlen(linie)==1 && linie[0]=='>')
        {
            continue;
        }
        if(strchr(linie,'<')!=NULL && linie[0]!='<')
        {
            for(int ind=0;ind<strlen(linie);ind++)
            {
                if(linie[ind]=='<')
                {
                    fout<<endl;
                }
                fout<<linie[ind];
            }
            fout<<endl;
        }
        else
        {
            fout<<linie<<endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}
