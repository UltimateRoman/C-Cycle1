#include<stdio.h>
int main()
{
 float a,b,ans;
 char s,ch;
 do
 {
  printf("\t\tSIMPLE CALCULATOR");
  printf("\n\nEnter 1st number:");
  scanf("%f",&a);
  printf("Enter 2nd number:");
  scanf("%f",&b);
  printf("Enter operator:");
  scanf("%s",&s);
  switch(s)
  {
   case '+': ans=a+b;
            break;
   case '-': ans=a-b;
            break;
   case '*': ans=a*b;
            break;
   case '/': ans=a/b;
            break;
   default: printf("\nEnter a valid operator!!");
  }
  printf("\nAnswer:%f",ans);
  printf("\n\nDo u want to continue?");
  scanf("%s",&ch);
 }while(ch=='y');
 return 0;
}
