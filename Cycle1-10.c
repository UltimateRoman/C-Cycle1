#include<stdio.h>
int main()
{
 int n,i,j,k,d;
 d=1;
 char ch;
 do
 {
  printf("\nEnter no:of rows of the triangle:");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  {
   for(k=0;k<=n-i;++k)
    printf(" ");
   for(j=0;j<=i;++j)
   {
    if(i==0||j==0)
     d=1;
    else
     d=d*(i-j+1)/j;
    printf("%d ",d);
   }
   printf("\n");
  }
  printf("\n\nDo u want to continue?");
  scanf("%s",&ch);
 }while(ch=='y');
 return 0;
}
