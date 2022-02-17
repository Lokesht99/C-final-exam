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
    struct stdDetailes std;
    FILE *fptr;
    if((fptr=fopen("C:\student99.txt","w"))==NULL){
        printf("Error! opening file");
        exit(1);
    }
    printf("Enter a student detailes:\n");
    printf("\nStudentName:");
    scanf("%s",&std.name);
    printf("\nStudentId:");
    scanf("%d",&std.Id);
    printf("\nStudentCourse:");
    scanf("%s",&std.course);
    printf("\nStudentAge:");
    scanf("%d",&std.Age);
    fprintf(fptr,"%s %d %s %s\n",&std.name,&std.Id,&std.course,&std.Age);
    //fwrite(&std, sizeof(struct stdDetailes),1,fptr);
    fclose(fptr);
}
void read()
{
    printf("\nDetailes are:\n");
    {
        struct stdDetailes std;
        FILE *fptr;
        if((fptr=fopen("C:\student99.txt","r"))==NULL){
        printf("Error! opening file");
        exit(1);
    }
        //fread(&std,sizeof(struct stdDetailes),1,fptr);
        while(fscanf(fptr,"name: %s\nId: %d\nAge: %d\ncourse:%s\n",std.name,std.Id,std.Age,std.course));
        {
            printf("name: %s\n",std.name);
            printf("id: %d\n",std.Id);
            printf("course: %s\n",std.course);
            printf("age: %d\n",std.Age);
        }
        fclose(fptr);
    }
}
int main(){
    struct stdDetailes std;
    write();
    read();
}


