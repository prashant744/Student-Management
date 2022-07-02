
int countStudent()
{
	FILE *fp;
	int n,last;
	fp=fopen("student.dat","rb");//open file in binary mode
    fseek(fp,0,SEEK_END);
    last=ftell(fp);
    n=last/sizeof(struct student);
	fclose(fp);
	return n;
}
void listStudent()
{
	FILE *fp;
	int n,i;
	struct student x;
    fp=fopen("student.dat","rb");//open file in binary mode
	n=countStudent();
    for(i=0;i<=n-1;i++)
    {
     fread(&x,sizeof(x),1,fp);
     printStudent(x);
    }
    fclose(fp);
}
struct student searchStudent(char *scno)
{
	FILE *fp;
	int n,i;
	struct student x,y={"","",0,0,{0,0,0}};
	fp=fopen("student.dat","rb");
	n=countStudent();
	for(i=0;i<=n-1;i++)
	{
		fread(&x,sizeof(x),1,fp);
		if(strcmpi(x.scno,scno)==0){fclose(fp);return x;}
	}
	fclose(fp);
	return y;
}
int insertStudent(struct student x)
{
	FILE *fp;
	fp=fopen("student.dat","ab");
	fseek(fp,0,SEEK_END);
	if(fwrite(&x,sizeof(x),1,fp))
	{
		fclose(fp);
		return 1;
		}
	else{
		fclose(fp);
		return 0;
	}	
}
void updateFileStudent(char *scno)
{
	FILE *fp,*ft;
    int i,n,last;
	struct student x;
    int flag=0;
    fp=fopen("student.dat","rb");//open file in binary mode
    ft=fopen("studtemp.dat","wb");//open a temp file
    n=countStudent();
    printf("\nTotal Students in file = %d\n",n);
    fseek(fp,0,SEEK_SET);
    for(i=0;i<=n-1;i++)
    {
     fread(&x,sizeof(x),1,fp);
     if(strcmpi(scno,x.scno)!=0)
       {
		//printStudent(x);
		fwrite(&x,sizeof(x),1,ft);
       }
     else{
       x=updateStudent(x);
       //printStudent(x);
       fwrite(&x,sizeof(x),1,ft);
       flag=1;//updated
		}
    }
    flag==0 && printf("\n scno %s not found",scno);
    fclose(fp);
    fclose(ft);
    remove("student.dat");
    rename("studtemp.dat","student.dat");
}
void deleteFileStudent(char *scno)
{
	FILE *fp,*ft;
    int i,n,last;
    struct student x;
    int flag=0;
    fp=fopen("student.dat","rb");//open file in binary mode
    ft=fopen("studtemp.dat","wb");//open a temp file
    n=countStudent();
    printf("\nTotal Students in file = %d\n",n);
    fseek(fp,0,SEEK_SET);
    for(i=0;i<=n-1;i++)
    {
     fread(&x,sizeof(x),1,fp);
     if(strcmpi(scno,x.scno)!=0)
       {
	//printStudent(x);
	fwrite(&x,sizeof(x),1,ft);
       }
     else{
       flag=1;//deleted
     }
    }
    flag==0 && printf("\n scno %s not found",scno);
    fclose(fp);
    fclose(ft);
	remove("student.dat");
    rename("studtemp.dat","student.dat");
}
