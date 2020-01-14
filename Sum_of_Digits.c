#include<stdio.h>
int main()
{
 int n,s;
 char ch;
 do
 {
  s=0;
  printf("\nEnter number:");
  scanf("%d",&n);
  while(n!=0)
  {
   s=s+(n%10);
   n=n/10;
  }
  printf("\nSum of digits of the number:%d",s);
  printf("\n\nDo u want to continue?");
  scanf("%s",&ch);
 }while(ch=='y');
 return 0;
}
