# include <stdio.h>
# include <string.h>
# include "customerlogin.h"
# include "structures.h"

/*struct reg {
    char custid[50];
    char custname[100];
    char username[100];
    char pwd[100];
    char dob[50];
    char phoneno[50];
    int status;
    int points;
    int balance;
}s1;*/
 int reg(){
      FILE *fptr;
      fptr=fopen("customerlogs.csv","a");
      if (fptr == NULL){
           printf("file could not be opened");}



        s1.balance=10000;
        printf("enter the customer name:");
        scanf("%s",s1.custname);

        printf("enter the dob");
        scanf("%s",s1.dob);
        printf("enter the username");
        scanf("%s",s1.username);
        printf("enter the password");
        scanf("%s",s1.pwd);
        printf("enter the phoneno");
        scanf("%s",s1.phoneno);
        int num=0;
        printf("do you want to get registered as a member of this app yes-1,no-0\n");
        scanf("%d",&num);
        if(num){
            s1.status=1;
            s1.points=50;
            s1.balance-=500;
        }
        else{
            s1.status=0;
            s1.points=0;
        }

        for(int i=0;i<10;i++){

            s1.custid[i]=s1.phoneno[i];
        }
        int j=10;
        for(int i=0;i<5;i++){
            s1.custid[j]=s1.custname[i];
            j++;}

        fprintf(fptr,"%s,%s,%s,%s,%s,%s,%d,%d,%d\n",s1.custid,s1.custname,s1.username,s1.pwd,s1.phoneno,s1.dob,s1.status,s1.points,s1.balance);
        printf("Thank you!You have successfully registered as the member of this app\n");

        fclose(fptr);}

int login(char username[],char pwd[],char custid[],char c_name[]){
      FILE *fptr;
      fptr=fopen("customerlogs.csv","r+");
      if (fptr == NULL){
           printf("file could not be opened");}

     struct reg custlog[100];
     char array[9][100];
     char c[325];
     fgets(c,sizeof(c),fptr);
     int i=0;
     while(!feof(fptr)){
          fscanf(fptr,"%100[^,],%100[^,],%100[^,],%100[^,],%100[^,],%100[^,],%d,%d,%d\n",custlog[i].custid,custlog[i].custname,custlog[i].username,custlog[i].pwd,custlog[i].phoneno,custlog[i].dob,&custlog[i].status,&custlog[i].points,&custlog[i].balance);
          i+=1;}


    int temp=1;
        for(int j=0;j<i;j++){
            if(strncmp(custlog[j].username,username,strlen(username))==0 &&strncmp(custlog[j].pwd,pwd,strlen(pwd))==0){
                strcpy(custid,custlog[j].custid);
                strcpy(c_name,custlog[j].custname);
                return 1;
                temp=0;
                break;
            }
        }
        if(temp){
            return 0;
        }
        fclose(fptr);

        }

int forgot(char name[],char password[]){
   FILE *fptr;
   fptr=fopen("customerlogs.csv","r+");
   if (fptr == NULL){
           printf("file could not be opened");}

   struct reg custlog[100];
   char c[325];
    fgets(c,sizeof(c),fptr);
     int i=0;
     while(!feof(fptr)){
          fscanf(fptr,"%100[^,],%100[^,],%100[^,],%100[^,],%100[^,],%100[^,],%d,%d,%d\n",custlog[i].custid,custlog[i].custname,custlog[i].username,custlog[i].pwd,custlog[i].phoneno,custlog[i].dob,&custlog[i].status,&custlog[i].points,&custlog[i].balance);
          i+=1;}
     int choice3=1;
     for(int j=0;j<i;j++){
        if(strcmp(name,custlog[j].phoneno)==0){
            strcpy(password,custlog[j].pwd);
            choice3=0;

        }
     }
     if(choice3){
        printf("no such name or phone number exists\n");
        return 0;
     }












}



















/*int main(){

    //FILE *fptr;
    //fptr=fopen("customerlogs.csv","w");
    //fprintf(fptr,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n","CustID","Custname","Username","pwd","phoneno","dob","membership status","loyalty points","ewallet balance");
    //fclose(fptr);
printf("Welcome to Customer Login Portal!\n");
int i=1;

while(i){
     int choice=0;
     printf("enter the choice 1-registration\n2-login\n3-forgot password\n");
     scanf("%d",&choice);
     if(choice==1){
      printf("welcome to the registration!\n");
      reg();
     }

     else if(choice==2){
        char username[100];
        char password[100];
        printf("enter the username:");
        scanf("%s",username);
        printf("enter the password:");
        scanf("%s",password);
        int j=login(username,password);
        if(j){
            printf("Congratulations You have succesfully logged in !\n");
        }
        else{
            printf("Invalid Login Credentials Please Try Again!");


        }

       }
      else if(choice==3){
        char name[100];
        printf("enter the name");
        scanf("%s",name);
        char password[100];
        strcpy(password,forgot(name));
        printf("your password is %s",password);


      }
     int cont=0;
     printf("wanna continue yes-1,no-0:");
     scanf("%d",&cont);
     if(cont==0){
        break;
     }}}*/









































