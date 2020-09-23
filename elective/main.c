#include<stdio.h>
#include<string.h>
typedef struct{
    char name[10];
    int e;
}students;
typedef struct{
    char name[10];
}elective;
void inputStudentDetails(students s[],int n);
int inputTotalNumber();
int displayMenu();
void displayParticularElectiveNames(students s[],int n);
void displayNames(students s[],int n);
void printElective(int a,elective e[],int c);
void countElective(students s[],int n,int a);
void selectOtherElective(int e,students s[],int n);
int main(){
    int n,d;
    n=inputTotalNumber();
    students s[n];
    inputStudentDetails(s,n);
    do{
        d=displayMenu();
        switch (d)
        {
        case 1:
            displayParticularElectiveNames(s,n);
            break;
        case 2:
            countElective(s,n,0);
            break;
        case 3:
            displayNames(s,n);
            break;
        case 4:
            break;
        default:
            printf("Please enter a valid choice\n");
        }
    }while (d!=4);
    return 0;
}

int inputTotalNumber(){
    int n;
    printf("Enter the total number of students\n");
    scanf("%d",&n);
    return n;
}
void inputStudentDetails(students s[],int n){
    int i;
    for(i=0;i<n;i++){
        fflush(stdin);
        printf("Enter Student No.%d name\n",i+1);
        gets(s[i].name);
        fflush(stdin);
        printf("Enter your elective choice\n");
        printf("1.Internet Of Things\n");
        printf("2.Advanced Java\n");
        printf("3.J2EE\n");
        scanf("%d",&s[i].e);
    }
}
int displayMenu(){
    int c;
    printf("1.Display names of students for a particular elective\n");
    printf("2.Display count of each elective\n");
    printf("3.Display name of students in all electives\n");
    printf("4.Exit\n");
    scanf("%d",&c);
    return c;
}
void displayParticularElectiveNames(students s[],int n){
    int e,i;
    printf("Enter your elective choice\n");
    printf("1.Internet Of Things\n");
    printf("2.Advanced Java\n");
    printf("3.J2EE\n");
    scanf("%d",&e);
    switch (e){
        case 1:
            printf("Students in the elective Internet Of Things are\n");
            break;
        case 2:
            printf("Students in the elective Advanced Java are\n");
            break;
        case 3:
            printf("Students in the elective J2EE are\n");
            break;
    }
    for(i=0;i<n;i++)
        if(s[i].e==e)
            puts(s[i].name);
}
void displayNames(students s[],int n){
    elective e1[5],e2[5],e3[5];
    int c1=0,c2=0,c3=0,i;
    for(i=0;i<n;i++){
        if(s[i].e==1){
            strcpy(e1[c1].name,s[i].name);
            c1++;
        }else if(s[i].e==2){
            strcpy(e2[c2].name,s[i].name);
            c2++;
        }else if(s[i].e==3){
            strcpy(e3[c3].name,s[i].name);
            c3++;
        }
    }
    printElective(1,e1,c1);
    printElective(2,e2,c2);
    printElective(3,e3,c3);
}
void printElective(int a,elective e[],int c){
    int i;
    switch (a){
        case 1:
            printf("Students in the elective Internet Of Things are\n");
            break;
        case 2:
            printf("Students in the elective Advanced Java are\n");
            break;
        case 3:
            printf("Students in the elective J2EE are\n");
            break;
    }
    for(i=0;i<c;i++)
        puts(e[i].name);
}
void countElective(students s[],int n,int a){
    int c1=0,c2=0,c3=0,i=0;
    for(i=0;i<n;i++){
        switch (s[i].e)
        {
            case 1:
                c1++;
                break;
            case 2:
                c2++;
                break;
            case 3:
                c3++;
                break;
        }
    }
    printf("The count in each elective is \n");
    printf("1.Internet Of Things: %d\n",c1);
    printf("2.Advanced Java: %d\n",c2);
    printf("3.J2EE: %d\n",c3);
    if(a==0){
        if(c1<3){
            printf("Note that this elective \"Internet Of Things\" doesn't have the required strength\n");
            printf("Request all students who chose this elective to reselect their elective\n");
            selectOtherElective(1,s,n);
        }else if(c2<3){
            printf("Note that this elective \"Advanced Java\" doesn't have the required strength\n");
            printf("Request all students who chose this elective to reselect their elective\n");
            selectOtherElective(2,s,n);
        }else if(c3<3){
            printf("Note that this elective \"J2EE\" doesn't have the required strength\n");
            printf("Request all students who chose this elective to reselect their elective\n");
            selectOtherElective(3,s,n);
        }
    }
}
void selectOtherElective(int e,students s[],int n){
    int i;
    for(i=0;i<n;i++){
        if(s[i].e==e){
            puts(s[i].name);
            printf("Please reselect your elective choice\n");
            printf("1.Internet Of Things\n");
            printf("2.Advanced Java\n");
            printf("3.J2EE\n");
            scanf("%d",&s[i].e);
        }
    }
    countElective(s,n,1);
}