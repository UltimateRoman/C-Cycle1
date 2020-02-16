#include<stdio.h>
int main()
{
 int i,j;
 char ch = 'A';
 for(i=0;i<5;++i)
 {
  for(j=0;j<=i;++j)
   printf("%c ",ch);
  ch=ch+1;
  printf("\n");
 }
 return 0;
}
