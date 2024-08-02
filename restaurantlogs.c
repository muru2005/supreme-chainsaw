# include <stdio.h>
# include <string.h>
# include "restaurantlogs.h"
# include "structures.h"
/*struct restaurant {
    char restaurantid[10];
    char restaurantname[100];
    int x;
    int y;
    char cuisine[50];
    char menu[100];
    char username[100];
    char password[100];
    float ratings;
    int nooftimesordered;
    int offer;
    int min_amount;
};*/

int logs(struct restaurant arr[],int i,char menuid[]){
     char username[100];
     char password[100];
     printf("enter the username:");
     scanf("%s",username);
     getchar();
     printf("enter the password:");
     scanf("%s",password);
     getchar();
     int choice=1;
     for(int j=0;j<i;j++){
        if(strcmp(arr[j].username,username)==0 && strcmp(arr[j].password,password)==0){
            strcpy(menuid,arr[j].menu);
            choice=0;
            return 1;


        }

     }
     if(choice==1){
        return 0;
     }
}
int forgotpassw(struct restaurant arr[],int i){

    char name1[50];
    printf("enter the name of the restaurant:");
    fgets(name1,sizeof(name1),stdin);
    name1[strcspn(name1,"\n")]='\0';
    int choice =1;
    for(int j=0;j<i;j++){
        if(strcmp(arr[j].restaurantname,name1)==0){
            printf("the password is :%s\n",arr[j].password);
            choice=0;
        }

    }
    if(choice){
        printf("no such restaurant exists\n");
    }




}

/*int main(){
 printf("Welcome To Restaurant Login Portal!\n");
 struct restaurant arr[100];
 int i=0;
 FILE *fptr;
 fptr=fopen("restaurants.csv","r");
 char c[325];
 fgets(c,sizeof(c),fptr);
 while(!feof(fptr)){
    fscanf(fptr, "%9[^,],%99[^,],%d,%d,%49[^,],%99[^,],%99[^,],%99[^,],%f,%d,%d,%d\n",
                  arr[i].restaurantid, arr[i].restaurantname, &arr[i].x, &arr[i].y,
                  arr[i].cuisine, arr[i].menu, arr[i].username, arr[i].password,
                  &arr[i].ratings, &arr[i].nooftimesordered,&arr[i].offer,&arr[i].min_amount);

    i+=1;

 }
  int b=login(arr,i);
 if(b==1){
    printf("Congratulations you have logged in successfully!");
 }
 else{
    printf("invalid login credentials");
 }






}*/
