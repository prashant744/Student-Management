#include<stdio.h>
#include<conio.h>
#include<string.h>
struct mydate{
   int d,m,y;
};
struct student{
    char name[80];
    char scno[80];
    int mark;
    int age;
    struct mydate dob;
};

struct student readStudent(){
    struct student x;
    fflush(stdin);
    printf("Enter Name:");gets(x.name);
    printf("Enter scno:");gets(x.scno);
    printf("Enter mark:");scanf("%d",&x.mark);
    printf("Enter age:");scanf("%d",&x.age);
    printf("Enter DoB:");scanf("%d%d%d",&x.dob.d,&x.dob.m,&x.dob.y);
    return x;
}
struct student updateStudent(struct student x){
    fflush(stdin);
    int c;
    //update name
    printf("\nCurrent Name = %s",x.name);
    printf("\nDo you want to change name(y/n)");c=getchar();
    fflush(stdin);
    if(c=='y'||c=='Y'){ printf("Enter New Name:");gets(x.name);}
    //update MArks
    printf("\nCurrent Marks = %d",x.mark);
    printf("\nDo you want to change Marks(y/n)");c=getchar();
    if(c=='y'||c=='Y'){ printf("Enter New Marks:");scanf("%d",&x.mark);}
    //update age
    fflush(stdin);
    printf("\nCurrent Age = %d",x.age);
    printf("\nDo you want to change Age/n)");c=getchar();
    fflush(stdin);
    if(c=='y'||c=='Y'){ printf("Enter New Age:");scanf("%d",&x.age);}
    //update dob
	fflush(stdin);
    printf("\nCurrent DOB = %02d/%02d%04d",x.dob.d,x.dob.m,x.dob.y);
    printf("\nDo you want to change DOB(y/n)");c=getchar();
    fflush(stdin);
    if(c=='y'||c=='Y'){ printf("Enter New DOB:");scanf("%d%d%d",&x.dob.d,&x.dob.m,&x.dob.y);}
    return x;
}

void printStudent(struct student x){
    printf("\nName:%s",x.name);
    printf("\tSc Number:%s",x.scno);
    printf("\tMark:%d",x.mark);
    printf("\tAge:%d",x.age);
    printf("\tDOB:%02d\\%02d\\%04d",x.dob.d,x.dob.m,x.dob.y);
    printf("\n");
}
