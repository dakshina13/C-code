#include<stdio.h>
struct marks{
    int CIEmarks,SEEmarks;
};
int main(){
    int i;
    struct marks m[5];
    for(i=0;i<5;i++){
        printf("Enter the CIE marks for subject %d\n",i+1);
        scanf("%d",&m[i].CIEmarks);
        printf("ENter the SEE marks for subject %d\n",i+1);
        scanf("%d",&m[i].SEEmarks);
    }
    for(i=0;i<5;i++){
        float t=(float)m[i].CIEmarks+(float)(m[i].SEEmarks/2);
        if(t>=0 && t<=100){
        printf("The students grade for subject %d is ",i+1);
        if(t>=90)
            printf("S\n");
        else if(t>=80)
            printf("A\n");
        else if(t>=70)
            printf("B\n");
        else if(t>=60)
            printf("C\n");
        else if(t>=50)
            printf("D\n");
        else if(t>=40)
            printf("E\n");
        else if(t>=0 && t<40)
            printf("F\n");
        }else{
            printf("Invalid Input of marks\n");
        }
    }
    return 0;
}