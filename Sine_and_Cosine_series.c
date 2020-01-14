#include<stdio.h>
#include<math.h>
int fac(int p)
{
 if(p==0)
  return 1;
 else return p*fac(p-1);
}
int main()
{
 char ch;
 int n,i,t;
 float x;
 double s,c;
 do
 {
  t=1;
  s=0;
  c=0;
  printf("\nEnter value of x(in radian):");
  scanf("%f",&x);
  printf("Enter value of n:");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  {
   s=s+t*(pow(x,2*i+1)/fac(2*i+1));
   c=c+t*(pow(x,2*i)/fac(2*i));
   t=t*-1;
  }
  printf("\nSine of x:%f",s);
  printf("\nCosine of x:%f",c);
  printf("\n\nDo u want to continue?");
  scanf("%s",&ch);
 }while(ch=='y');
 return 0;
}
