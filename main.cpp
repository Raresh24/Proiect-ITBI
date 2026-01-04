#include <iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream f("file.in");
ofstream c("file.out");
void printspace( int niv ){
for (int i=0; i<niv *4;i++)
    c << " ";
}
int main()
{
char s[1000];
int niv =0;
while ( f.getline(s,1000)) {
    if (s[0] == '<' && s[1]== '/'){
        niv--;
        printspace(niv);
        c << s << endl;
    }

    else if (s[0] == '<' && s[strlen(s)-1] == '>')
        if (s[strlen(s)-2] == '/'){
        printspace(niv);
            c << s << endl;}
        else if ( s[1]== '!') {niv --;
                                cout << s << endl;
                                niv ++;}
        else {
            printspace(niv);
            c << s << endl;
            niv ++ ;
        }
    else { if (s[strlen(s)-1]== ';' || s[strlen(s)-1]== '}')

        c << s <<endl;
        else {printspace (niv);
                c << s << endl;

    }
    } }
    f.close();
    c.close();
    return 0;}
