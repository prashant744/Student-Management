#include <studstru.h>
#include <fileop.h>
#include <process.h>
#include <dos.h>
void displayTime(){
 struct time curtime;
 gettime(&curtime);
 printf("\t\t%02d:%02d:%02d",curtime.ti_hour,curtime.ti_min,curtime.ti_sec);
}
void displayDate(){
  struct date today;
  getdate(&today);
  printf("\n%02d/%02d/%04d",today.da_day,today.da_mon,today.da_year);
}
int printMenu(){
  int c;
  clrscr();
  printf("\nStudent Management system");
  displayDate();
  displayTime();
  printf("\n1 List of all students");
  printf("\n2 Insert new student");
  printf("\n3 Search student");
  printf("\n4 Update student");
  printf("\n5 Delete student");
  printf("\n6 Count student");
  printf("\n7 Exit");
  printf("\nEnter Your Choice (1-7)");scanf("%d",&c);
  return c;
}

int main(){
  int c;
  struct student x;
  char *scno;
  while(1){
  c=printMenu();
  switch(c){
     case 1:
	 listStudent();
	 printf("\nPress any key to continue...");
	 getch();
	 break;
     case 2:
	x=readStudent();
	insertStudent(x);
	printf("\nPress any key to continue...");
	getch();
	break;
     case 3:
	printf("\nEnter Scno to search");scanf("%s",scno);
	x=searchStudent(scno);
	if(strcmpi(x.scno,scno)==0)
		printStudent(x);
	else
		printf("\n%s - not Found");
	printf("\nPress any key to continue...");
	getch();
	break;
     case 4:
	printf("\nEnter Scno to search");scanf("%s",scno);
	updateFileStudent(scno);
	printf("\nPress any key to continue...");
	getch();
	break;
     case 5:
	printf("\nEnter Scno to search");scanf("%s",scno);
	deleteFileStudent(scno);
	printf("\nPress any key to continue...");
	getch();
	break;
     case 6:
	printf("\nCurrent Strenth=%03d",countStudent());
	printf("\nPress any key to continue...");
	getch();
	break;
     case 7:
	exit(0);
  }
  }
  return 0;
}

