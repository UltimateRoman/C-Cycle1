#include<stdio.h>
int main()
{
 int c,a;
 char ch='y';
 printf("1.Area of rectangle");
 printf("\n2.Area of triangle");
 while(ch=='y')
 {
  printf("\n\nEnter choice:");
  scanf("%d",&c);
  if(c==1)
  {
   int l,b;
   printf("\nEnter length of rectangle:");
   scanf("%d",&l);
   printf("Enter breadth of rectangle:");
   scanf("%d",&b);
   a=l*b;
   printf("\nArea of rectangle:%d",a);
  }
  else if(c==2)
  {
   int b,h;
   printf("\nEnter base length:");
   scanf("%d",&b);
   printf("Enter height of triangle:");
   scanf("%d",&h);
   a=0.5*b*h;
   printf("\nArea of triangle:%d",a);
  }
  else
  {
   printf("\nEnter a valid choice!!");
  }
  printf("\nDo u want to continue?");
  scanf("%s",&ch);
 }
 return 0;
}
