#include<stdio.h>
#include<math.h>
#define pi 3.14
int userInput(){
    int a;
    printf("Please choose one of the shapes \n");
    printf("1.Cylinder\n");
    printf("2.Cone\n");
    printf("3.Sphere\n");
    scanf("%d",&a);
    return a;
}
void areaCylinder(float r,float h){
    float a=(2*pi*h*r)+(2*pi*r*r);
    printf("The area of the cylinder is %f\n",a);
}
void volumeCylinder(float r,float h){
    float v=pi*r*r*h;
    printf("The volume of the cylinder is %f\n",v);
}
void cylinder(){
    float r,h;
    printf("Enter the radius and height of the cylinder\n");
    scanf("%f,%f",&r,&h);
    areaCylinder(r,h);
    volumeCylinder(r,h);
}
void areaCone(float r,float h){
    float a=pi*r*(r+sqrt(h*h+r*r));
    printf("The area of the cone is %f\n",a);
}
void volumeCone(float r,float h){
    float v=(pi*r*r*h)/3;
    printf("The volume of the cone is %f\n",v);
}
void cone(){
    float r,h;
    printf("Enter the radius and height of the cone\n");
    scanf("%f,%f",&r,&h);
    areaCone(r,h);
    volumeCone(r,h);
}
void volumeSphere(float r){
    float v=(4*r*r*r*pi)/3;
    printf("The volume of the sphere is %f\n",v);
}
void areaSphere(float r){
    float a=4*r*r*pi;
    printf("The area of the Sphere is %f\n",a);
}
void sphere(){
    float r;
    printf("Enter the radius od the sphere\n");
    scanf("%f",&r);
    areaSphere(r);
    volumeSphere(r);
}
int main(){
    int a;
    a=userInput();
    switch (a)
    {
    case 1:
        cylinder();
        break;
    case 2:
        cone();
        break;
    case 3:
        sphere();
        break;
    default:
        printf("Please enter a valid input\n");
    }
    return 0;
}