#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void printspace( int niv ,char yamal[])
{
    yamal[0]='\0';
    for (int i=0; i<niv *4;i++)
    {
        strcat(yamal," ");
    }
}
int main()
{
    char linie[256],*cuv,matrix[1000][256],mat[1000][256],unu[256],doi[256],aux[256],*p,barca[1000][256],yamal[256];
    int contor=0,cnt=0,poz,niv=0;
    while(cin.getline(linie,256))
    {
        cuv=strtok(linie,">");
        while(cuv!=NULL)
        {
            if(cuv[strlen(cuv)-1]=='}' || cuv[strlen(cuv)-1]==';')
            {
                strcpy(matrix[contor],cuv);
                contor++;
            }
            else
            {
                strcpy(matrix[contor],cuv);
                strcat(matrix[contor],">");
                contor++;
            }
            cuv=strtok(NULL,">");
        }
    }
    for(int i=0;i<contor;i++)
    {
        if(strlen(matrix[i])==0)
        {
            continue;
        }
        if(strlen(matrix[i])==1 && matrix[i][0]=='>')
        {
            continue;
        }
        if(strchr(matrix[i],'<')!=NULL && matrix[i][0]!='<')
        {
            strcpy(aux,matrix[i]);
            p=strchr(aux,'<');
            poz=p-aux;
            strncpy(unu,aux,poz);
            unu[poz]='\0';
            strcpy(doi,p);
            strcpy(mat[cnt],unu);
            cnt++;
            strcpy(mat[cnt],doi);
            cnt++;
        }
        else
        {
            strcpy(mat[cnt],matrix[i]);
            cnt++;
        }
    }
    for(int pedri=0;pedri<cnt;pedri++)
    {
        if (mat[pedri][0] == '<' && mat[pedri][1]== '/')
        {
            niv--;
            printspace(niv,yamal);
            strcat(barca[pedri],yamal);
            strcat(barca[pedri],mat[pedri]);
        }
        else
        {
            if (mat[pedri][0] == '<' && mat[pedri][strlen(mat[pedri])-1] == '>')
            {
                if (mat[pedri][strlen(mat[pedri])-2] == '/')
                {
                    printspace(niv,yamal);
                    strcat(barca[pedri],yamal);
                    strcat(barca[pedri],mat[pedri]);
                }
                else 
                {
                    if ( mat[pedri][1]== '!')
                    {
                        niv --;
                        printspace(niv,yamal);
                        strcat(barca[pedri],yamal);
                        strcat(barca[pedri],mat[pedri]);
                        niv ++;
                    }
                    else 
                    {
                        printspace(niv,yamal);
                        strcat(barca[pedri],yamal);
                        strcat(barca[pedri],mat[pedri]);
                        niv ++ ;
                    }
                }
            }
            else
            {
                if (mat[pedri][strlen(mat[pedri])-1]== ';' || mat[pedri][strlen(mat[pedri])-1]== '}')
                {
                    strcat(barca[pedri],mat[pedri]);
                }
                else
                {
                    printspace (niv,yamal);
                    strcat(barca[pedri],yamal);
                    strcat(barca[pedri],mat[pedri]);
                }
            }
        }
    }
    for(int ind=0;ind<cnt;ind++)
    {
        if(cnt-ind==1)
        {
            cout<<barca[ind];
        }
        else
        {
            cout<<barca[ind]<<endl;
        }
    }
    return 0;
} 
