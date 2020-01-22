#include<stdio.h>
int main()
{
    long cno, cn;
    int cs = 0, c = 0;
    printf("Enter Card No:");
    scanf("%ld",&cno);
    cn = cno;
    while (cn)
    {
        ++c;
        cn = cn / 10;
    }
    if (c == 13 || c == 15 || c== 16)
    {
       cn = cno;
       while (cn)
       {
           int i = (cn % 100) / 10;
           i = i * 2;
           while (i)
           {
               int j = i % 10;
               cs += j;
               i = i / 10;
           }
           cn = cn / 100;
       }
       cn = cno;
       while (cn)
       {
           int i=cn%10;
           cs+=i;
           cn=cn/100;
       }
       cn=cno;
       if(cs%10==0)
       {
           if(c==13)
           {
             for(int k=0;k<12;++k)
                 cn=cn/10;
             if(cn==4)
                 printf("VISA\n");
             else printf("INVALID\n");
           }
           else if(c==15)
           {
               for(int k=0;k<13;++k)
                   cn=cn/10;
               if(cn==34||cn==37)
                   printf("AMEX\n");
               else printf("INVALID\n");
           }
           else if(c==16)
           {
               for(int k=0;k<14;++k)
                   cn=cn/10;
               if(cn==51||cn==52||cn==53||cn==54||cn==55)
                   printf("MASTERCARD\n");
               else
               {
                   cn=cn/10;
                   if(cn==4)
                       printf("VISA\n");
                   else printf("INVALID\n");
               }
           }

       }
       else printf("INVALID\n");
    }
    else printf("INVALID\n");
    return 0;
}
