#include<stdio.h>
int main()
{
 int a[5],s,m,i;
 double p;
 char ch;
 ch='y';
 printf("Enter maximum marks of the exam:");
 scanf("%d",&m);
 do
 {
  s=0;
  p=0;
  printf("\nEnter marks of the student in 5 subjects:");
  for(i=0;i<5;++i)
  {
   scanf("%d",&a[i]);
   s=s+a[i];
  }
  printf("\nSum of marks:%d",s);
  p=((double)s/(double)m)*20;
  printf("\nPercentage of marks:%f",p);
  printf("\nClass obtained:");
  if(p>=75)
   printf("First Class with distinction");
  else if((p>=60)&&(p<75))
   printf("First Class");
  else if((p>=50)&&(p<60))
   printf("Second Class");
  else
   printf("Failed!");
  printf("\n\nDo u want to continue?");
   scanf("%s",&ch);
 }while(ch=='y');
 return 0;
}
