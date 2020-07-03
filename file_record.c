#include<stdio.h>
int main()
{
    FILE *f;
    int n,rno,tmarks;
    char fname[30],name[30];
    printf("Enter file name:");
    gets(fname);
    f = fopen(fname,"w");
    if(f==NULL)
    {
        printf("File could not be opened!");
        return -1;
    }
    printf("Enter no:of records:");
    scanf("%d",&n);
    printf("Enter student details:\n");
    fflush(stdin);
    fprintf(f,"%s","Student details\n");
    for(int i=0;i<n;++i)
    {
        printf("\nRoll No:");
        scanf("%d",&rno);
        printf("Student name:");
        scanf("%s",name);
        printf("Total marks:");
        scanf("%d",&tmarks);
        fprintf(f,"\nRoll No: %d \nStudent name: %s \nTotal marks: %d \n",rno,name,tmarks);
    }
    fclose(f);
    return 0;
}
