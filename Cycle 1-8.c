#include<stdio.h>
int main()
{
 int n,a[100],i;
 char ch;
 do
 {
  int s,l;
  l=0;
  printf("\n\nEnter No:of numbers:");
  scanf("%d",&n);
  printf("Enter the numbers:");
  for(i=0;i<n;++i)
   scanf("%d",&a[i]);
  s=a[0];
  for(i=0;i<n;++i)
  {
   if(a[i]<s)
    s=a[i];
   if(a[i]>l)
    l=a[i];
  }
  printf("\nSmallest number:%d",s);
  printf("\nLargest number:%d",l);
  printf("\n\nDo u want to continue?");
  scanf("%s",&ch);
 }while(ch=='y');
 return 0;
}


