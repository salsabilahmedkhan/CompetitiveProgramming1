#include <stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    int i,sum=0,n=0;
    while(scanf("%s",a))
    {
        if(strcmp(a,"*")==0)
        return 0;
        else
        {
            for(i=0;a[i];i++)
                sum=sum+a[i];

                if(sum==('H'+'a'+'j'+'j'))
                    printf("Case %d: Hajj-e-Akbar\n",++n);
                if(sum==('U'+'m'+'r'+'a'+'h'))
                    printf("Case %d: Hajj-e-Asghar\n",++n);

        }
    }
    return 0;
}
