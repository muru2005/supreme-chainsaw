# include <stdio.h>
# include <string.h>
# include "structures.h"
# include "deliverylogin.h"

int logind(char uname[],char pword[]){
 FILE *file= fopen("delivery.csv","r");
 char line[2500];
 int index=0;
 int choice=1;
 while(fgets(line,sizeof(line),file)){
        char *name;
        char *phone_num;
        char *username;
        char *password;
        name=strtok(line,",");
        phone_num=strtok(NULL,",");
        username=strtok(NULL,",");
        password=strtok(NULL,",");

        if(strcmp(uname,username)==0 && strcmp(pword,password)==0){
            choice=0;
            return 1;

        }






}
if(choice==1){
    return 0;
}
}
int changexy(char username[],int x,int y){
  FILE *file= fopen("delivery.csv","r");
 char line[2500];
 int index=0;
 int choice=1;
 delinfo drivers[15];
 int drivers_index=0;

 while(fgets(line,sizeof(line),file)){

        char *name;
        char *phone_num;
        char *uname;
        char *pword;
        char *sbalance;
        char *strx;
        char *stry;
        int nx,ny;
        char *eptr;
        float balance=0.0;

        name=strtok(line,",");
        phone_num=strtok(NULL,",");
        uname=strtok(NULL,",");
        pword=strtok(NULL,",");
        sbalance=strtok(NULL,",");
        strx=strtok(NULL,",");
        stry=strtok(NULL,",");

        nx=atoi(strx);
        ny=atoi(stry);


        strcpy(drivers[drivers_index].name,name);
        strcpy(drivers[drivers_index].phoneNumber,phone_num);
        strcpy(drivers[drivers_index].uname,uname);
        strcpy(drivers[drivers_index].pword,pword);

        balance=strtof(sbalance,&eptr);
        drivers[drivers_index].balance=balance;




        if(strcmp(uname,username)==0){
            nx=x;
            ny=y;

        }

        drivers[drivers_index].x=nx;
        drivers[drivers_index].y=ny;
        drivers_index++;





}
 FILE *fptr;
 fptr=fopen("delivery.csv","w");
    for(int i=0;i<drivers_index;i++){
        fprintf(fptr,"%s,%s,%s,%s,%f,%d,%d,\n",drivers[i].name,drivers[i].phoneNumber,drivers[i].uname,drivers[i].pword,drivers[i].balance,drivers[i].x,drivers[i].y);
     }

    fclose(fptr);}
int view_balance(char username[]){
 delinfo drivers[15];
 int drivers_index=0;
 int choice =1;
 char line[2500];
 FILE *file= fopen("delivery.csv","r");

 while(fgets(line,sizeof(line),file)){

        char *name;
        char *phone_num;
        char *uname;
        char *pword;
        char *sbalance;
        char *strx;
        char *stry;
        char *eptr;
        float balance=0.0;
         name=strtok(line,",");
        phone_num=strtok(NULL,",");
        uname=strtok(NULL,",");
        pword=strtok(NULL,",");
        sbalance=strtok(NULL,",");
        strx=strtok(NULL,",");
        stry=strtok(NULL,",");

        int nx=atoi(strx);
        int ny=atoi(stry);
        balance=strtof(sbalance,&eptr);

        if(strcmp(uname,username)==0){
          choice=0;
          printf("\nThe balance amount is: %f\n",balance);
          fclose(file);
          break;
        }




}

}

int main_dl(){
 printf("       Delivery Agent Login Portal\n\n");
 char uname[100];
 char pword[100];
 int d=0;
 int choice =0;

while(1){
printf("Do you wish to:\n1-Login\n2-Change base co-ordinates\n3-View amount\nChoice: ");
scanf("%d",&choice);
if(choice==1){
 printf("Enter user-name: ");
 scanf("%s",uname);
 printf("Enter password: ");
 scanf("%s",pword);
  d=logind(uname,pword);
 if(d){
    printf("\nLogin Successful!\n");



 }
 else{
    printf("\nInvalid Credentials! Try again!\n");


 }



}
if(choice==2){
    if(d){
       int x=0;
    int y=0;
     printf("\nEnter x and y coordinates:");
    scanf("%d %d",&x,&y);
    printf("\n");


    changexy(uname,x,y);

    }
    else{
        printf("\n\nThank You! Hope to see you soon!");
        break;
    }
}
if(choice==3){
    if(d){
     view_balance(uname);
    }
    else{
        printf("\n\nThank You! Hope to see you soon!");
        break;
    }
}
int a=0;
printf("Do you wish to continue?\nYes-1\nN-0\nChoice:");
scanf("%d",&a);
if(a==0){
    break;
}


}
}



