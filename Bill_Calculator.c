#include<stdio.h>
int main()
{
 int cn,u,a;
 char ch;
 do
 {
  printf("\nEnter consumer no:");
  scanf("%d",&cn);
  printf("Enter units consumed:");
  scanf("%d",&u);
  if(u<=200)
   a=0.5*u;
  else if(u>200&&u<=400)
   a=100+0.65*(u-200);
  else if(u>400&&u<=600)
   a=230+0.8*(u-400);
  else
   a=390+(u-600);
  printf("\n\nConsumer No:%d",cn);
  printf("\nAmount to be paid:%d",a);
  printf("\n\nDo u want to continue?");
  scanf("%s",&ch);
 }while(ch=='y');
 return 0;
}
