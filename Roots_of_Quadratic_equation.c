#include<stdio.h>
#include<math.h>
int main()
{
 int a,b,c;
 float d,x1,x2;
 char ch;
 do
 {
  printf("For a quadratic equation ax^2 + bx + c = 0");
  printf("\nEnter value of a:");
  scanf("%d",&a);
  printf("Enter value of b:");
  scanf("%d",&b);
  printf("Enter value of c:");
  scanf("%d",&c);
  d=sqrt(b*b-4*a*c);
  if(d>=0)
  {
   x1=(-b+d)/2*a;
   x2=(-b-d)/2*a;
   printf("\nRoots of the equation are:");
   printf("%f , %f",x1,x2);
  }
  else printf("\nRoots are imaginary!");
  printf("\nDo u want to continue?");
  scanf("%s",&ch);
 }while(ch=='y');
return 0;
}
