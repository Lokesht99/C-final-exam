#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stdDetailes
{
int Id,Age;
char name[25],course[25];
} ;
void write()
{
int n;
struct stdDetailes std;
FILE *fptr;
if((fptr=fopen("student11.txt","w"))==NULL){
printf("Error! opening file");
exit(1);
}
printf("Enter a student detailes:\n");
printf("\nStudentName:");
gets(std.name);
//scanf("%s",&std.name);
printf("\nStudentId:");
scanf("%d",&std.Id);
fflush(stdin);
printf("\nStudentCourse:");
// gets(std.course);
scanf("%s",&std.course);
printf("\nStudentAge:");
scanf("%d",&std.Age);
fprintf(fptr,"%s %d %s %d\n",&std.name,std.Id,&std.course,std.Age);
//fwrite(&std, sizeof(struct stdDetailes),1,fptr);
fclose(fptr);
}
void read()
{
printf("\nDetailes are:\n");
{
struct stdDetailes std;
FILE *fptr;
if((fptr=fopen("student11.txt","r"))==NULL){
printf("Error! opening file");
exit(1);
}
//fread(&std,sizeof(struct stdDetailes),1,fptr);
fscanf(fptr,"%s %d %d %s\n",std.name,&std.Id,std.course,&std.Age);
printf("name : %s",std.name);
printf("\nid : %d",std.Id);
printf("\ncourse : %s",std.course);
printf("\nage : %d",std.Age);
fclose(fptr);
}
}
int main(){
struct stdDetailes std;
write();
read();
return 0;
}
