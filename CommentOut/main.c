#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char c;
    char mem;
    file = fopen("Com.txt","r");

    c = getc(file);
    mem=c;
    while(c!=EOF)
    {
        if(c!='/')//no comment start detected
        {
            printf("%c",c);
            c=getc(file);
            mem=c;
        }
        else if(c=='/')//possible comment
        {
            c=getc(file);

            if(c=='*')
            {//actual "/**/"coment
                c=getc(file);
                while(c!='*')
                {
                    c=getc(file);
                }
                c=getc(file);
            }

            else if(c!='/')//check if "//"
            {//false alarm
                printf("%c",c);
                c=getc(file);
                mem=c;
            }

            else//actual "//" comment
            {

                while(c!='\n')//Iterate until new line
                {
                    c=getc(file);
                }
            }
        }

    }
    fclose(file);
    return 0;
}
