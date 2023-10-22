#include <stdio.h>
#include<string.h>

double bodymassindex(double weight,double height){

    double bmi = weight/(height * height);

    return bmi;
}
int main(int argc, char const *argv[])
{
    printf("## BMI Calculator ##\n");

    char username[50];

    double weight,height,bmi;

    printf("Enter user name > ");

    scanf(" %[^\n]",&username);

    printf("\n");

    printf("Enter your height > ");

    scanf(" %lf",&height);

    printf("\n");

    printf("Enter your weight > ");

    scanf(" %lf",&weight);

    printf("\n");

    bmi = bodymassindex(weight,height);

    if(bmi< 18.5){
        printf("# %s ,Your weight status is Underweight.\n",username);
    }
    else if((bmi >= 18.5)&&(bmi<25))
    {
        printf("# %s, Your weight status is Normal Weight\n",username);
    }
    else if((bmi>=25)&& (bmi <30)){
        printf("# %s, Your weight status is Overweiht.\n",username);
    }
    else{
        printf("# %s,Your weight status is Obese.\n",username);
    }

    FILE *filePtr;
    filePtr = fopen("BMI_Record.txt","w");
    fprintf(filePtr,"%s\n",username);
    fprintf(filePtr,"height = %.2lf \n",height);
    fprintf(filePtr,"weight = %.2lf \n",weight);
    fprintf(filePtr,"BMI = %.2lf\n",bmi);
    if(bmi< 18.5){
        fprintf(filePtr," # Weight status = %s\n","Underweight");
    }
    else if((bmi >= 18.5)&&(bmi<25))
    {
        fprintf(filePtr," # Weight status = %s\n","Normal Weight");
    }
    else if((bmi>=25)&& (bmi <30)){
        fprintf(filePtr," # Weight status = %s","Overweight");
    }
    else{
        fprintf(filePtr," # Weight status =%s\n","Obese");
    }
    fclose(filePtr);

    char checkName[50];
    int check;

    printf("\n");

    printf("Do you want to see your status record ?\n");

    printf("\n");

    printf("Enter your name >");

    scanf(" %[^\n]",&checkName);

    printf("\n");

    check = strcmp(username,checkName);

    if(check == 0){

        FILE *filePtr;
        filePtr = fopen("BMI_Record.txt","r");
         if(filePtr == NULL){
        printf("File can not be read");
        return 1;
         }

        char buffer[100];

   while((fgets(buffer,sizeof(buffer),filePtr))!= NULL){

        printf(buffer);

   }

   fclose(filePtr);

    }
    else{
        printf(" Username is incorrect !\n");
    }
    

    return 0;
}
