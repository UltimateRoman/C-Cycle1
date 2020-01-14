#include<stdio.h>
int main()
{
 int n,i,j,f;
 char ch;
 do
 {
  printf("\nEnter range:");
  scanf("%d",&n);
  printf("Prime nos within the range are: ");
  for(i=2;i<=n;++i)
  {
   f=0;
   for(j=2;j<=i;++j)
    if(i%j==0)
     f++;
   if(f<2)
    printf(" %d",i);
  }
  printf("\n\nDo u want to continue?");
  scanf("%s",&ch);
 }while(ch=='y');
 return 0;
}
