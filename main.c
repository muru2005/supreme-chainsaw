#include <stdio.h>
#include <stdlib.h>
# include <string.h>

# include "customerlogin.h"
# include "customerlogin.c"
# include "restaurantlogs.c"
# include "restaurantlogs.h"
# include "menualter.c"
# include "menualter.h"
# include "Dispmap.c"
# include "Dispmap.h"
# include "RF1.c"
# include "RF1.h"
# include "cartitem.c"
# include "cartitem.h"
# include "payment.c"
# include "payment.h"
# include "feedback.h"
# include "feedback.c"
# include "delivery.c"
# include "delivery.h"
# include "deliverylogin.c"
# include "deliverylogin.h"

int restx=0,resty=0;
char custid[100];
char username[100];
char menu[200];
char cusine[100];
int u=0;
int w=0;
int main()
{

    printf("welcome to Zip-Foods!\n\n");
    int n=0;
    scanf("%d",&n);
    int choice=0;
    printf("Are you:\n0-An admin\n1-An user\n2-driver\nChoice:");
    scanf("%d",&choice);
    printf("\n");

    if(choice==1){

      //FILE *fptr;
    //fptr=fopen("customerlogs.csv","w");
    //fprintf(fptr,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n","CustID","Custname","Username","pwd","phoneno","dob","membership status","loyalty points","ewallet balance");
    //fclose(fptr);
    printf("Welcome to Customer Login Portal!\n\n");
    int i=1;

    while(i){
     int choice=0;
     printf("Do you wish to:\n1-Create new account\n2-login to existing account\n3-Forgot password\nChoice: ");
     scanf("%d",&choice);
     if(choice==1){
      printf("Welcome to registration!\n\n");
      reg();
     }

     else if(choice==2){

        char password[100];
        printf("Enter user-name: ");
        scanf("%s",username);
        printf("Enter password:");
        scanf("%s",password);
        char c_name[100];
        u=login(username,password,custid,c_name);
        if(u){
            printf("\nSuccessful Login!\n\nWelcome %s\n\n",c_name);
        }
        else{
            printf("\nInvalid Login Credentials. Please Try Again!\n");


        }


       }
      else if(choice==3){
        char name[100];
        printf("\nEnter phone-number: ");
        scanf("%s",name);


        char password[100];


       int number=forgot(name,password);
       if(number!=0){
        printf("\nYour password is: %s\n",password);}


      }
     int cont=0;
     printf("Do you wish to continue:\nNo-0\nYes-1\n\nChoice: ");
     scanf("%d",&cont);
     if(cont==0){
        break;
     }}
    if(u){

     printf("               Map:\n");
     int GRID_SIZE=35;
    char grid[36][36];
    int valid=0;
    int x,y;
    int a,b;
    DispMap(grid, GRID_SIZE);
    while (!(valid)){

        printf("Enter delivery address x and y: ");
        scanf("%d%d",&x,&y);
        getchar();
        if (NotOnRoad(x,y) && NotOnRestaurant(x,y)){
            valid=1;
        }
        else{
            printf("\nInvalid Address\n");
        }
    }

    main_rf1(x,y);
    getchar();
    char id[100];
    char restid[10];
    printf("\nEnter restaurant name: ");
    fgets(id,sizeof(id),stdin);
    id[strcspn(id,"\n")]='\0';
    FILE *fptr;
    char menuid[200];
    fptr=fopen("restaurants.csv","r");
    if(fptr==NULL){
    printf("file cannot be opened\n");}
    fptr = fopen("restaurants.csv", "r");
    if (fptr == NULL) {
        printf("\nFile could not be opened\n");
        return 1;
    }

    char c[325];
    fgets(c,sizeof(c),fptr);
    struct restaurant arr[100];


     i = 0;
    while (fscanf(fptr, "%9[^,],%99[^,],%d,%d,%49[^,],%99[^,],%99[^,],%99[^,],%f,%d,%d,%d\n",
                  arr[i].restaurantid, arr[i].restaurantname, &arr[i].x, &arr[i].y,
                  arr[i].cuisine, arr[i].menu, arr[i].username, arr[i].password,
                  &arr[i].ratings, &arr[i].nooftimesordered,&arr[i].offer,&arr[i].min_amount) == 12) {
                 i++;

                  }

    for(int j=0;j<i;j++){

        if(strcmp(arr[j].restaurantname,id)==0){
             restx=arr[j].x;
             resty=arr[j].y;
            strcpy(menuid,arr[j].menu);
            strcpy(restid,arr[j].restaurantid);
            strcpy(cusine,arr[j].cuisine);
        }
    }
    fclose(fptr);
   struct cart cart1[100];
   int z=0;



   float* arr4 = main_c(menuid,cart1,custid,restid,cusine);
   float totalprice=arr4[0];
   z=(int)arr4[1];




  int numer= main_p(totalprice,restid,username);
 char drivername[100];
 char driverphno[100];
 int driverx=0,drivery=0;
 main_delivery(restx ,resty,x,y, drivername,driverphno,&driverx,&drivery);

 if(numer){
   main_f(restid,menuid,cart1,z);
   route path;
   route path1;
   path1=CalcRoute(driverx,drivery,restx,resty);
    path=CalcRoute(x,y,restx,resty);
    DispRoute(driverx,drivery,restx,resty,path1,grid);
     grid[driverx][drivery]='D';
    DispRoute(x,y,restx,resty,path,grid);



    printf("Your driver is assigned!\n");
    printf("Driver name: %s\n",drivername);
    printf("Driver phone-number: %s\n",driverphno);
    }

 else{
    printf("\n\nThank you! Hope you have a good day!");
 }
    }
else{
    printf("\n\nThank you! Hope you have a good day!");

}

    }














    else if(choice==0){
        printf("Welcome To Restaurant Login Portal!\n");
         struct restaurant arr[100];
         int i=0;
         FILE *fptr;
         fptr=fopen("restaurants.csv","r");
         char c[325];
         fgets(c,sizeof(c),fptr);
         getchar();
         while(!feof(fptr)){
          fscanf(fptr, "%9[^,],%99[^,],%d,%d,%49[^,],%99[^,],%99[^,],%99[^,],%f,%d,%d,%d\n",
                  arr[i].restaurantid, arr[i].restaurantname, &arr[i].x, &arr[i].y,
                  arr[i].cuisine, arr[i].menu, arr[i].username, arr[i].password,
                  &arr[i].ratings, &arr[i].nooftimesordered,&arr[i].offer,&arr[i].min_amount);

          i+=1;

 }

 while(1){
 int choice1=0;
 printf("enter 1 to login\n2 for forgot password");
 scanf("%d",&choice1);
 getchar();

 if(choice1==1){
  w=logs(arr,i,menu);
  if(w==1){
    printf("Congratulations you have logged in successfully!\n");
  }
  else{
    printf("invalid login credentials\n");
 }}
 else if(choice1==2){
    forgotpassw(arr,i);


 }
 int z=0;
 printf("want to continue y -1 n-0");
 scanf("%d",&z);
 getchar();
 if(z==0){
    break;
 }

 }
if(w==1){
 printf("Welcome to menu altering page");

 FILE *file;


 file = fopen(menu,"r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    item records[100];
    int count = 0;
    char header[325];
    fgets(header,sizeof(header),file);


    // Read records from the file
    while (!feof(file)) {
        fscanf(file, "%5[^,],%50[^,],%100[^,],%f,%f,%d,%d,%d,%d\n",
                                         records[count].id,
                                         records[count].type,
                                         records[count].name,
                                         &records[count].price,
                                         &records[count].rating,
                                         &records[count].calories,
                                         &records[count].veg,
                                         &records[count].n,
                                         &records[count].priority);
        count++;
    }

    fclose(file);

    int choice;
    do {
        DisplayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                DisplayRecords(records, count);
                break;
            case 2:
                UpdatePrice(records, count);
                break;
            case 3:
                AddRecord(records, &count);
                break;
            case 4:
                DeleteRecord(records, &count);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    // Write updated records back to the file
    file = fopen(menu, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
      fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
            "foodid", "foodtype", "foodname","price", "rating", "calories", "veg",
            "no_of_times_ordered","priority");

    for (int i = 0; i < count; i++) {

        fprintf(file, "%s,%s,%s,%.2f,%.2f,%d,%d,%d,%d\n",
                records[i].id,
                records[i].type,
                records[i].name,
                records[i].price,
                records[i].rating,
                records[i].calories,
                records[i].veg,
                records[i].n,
                0);
    }

    fclose(file);

    return 0;






}
else{
    printf("Program exits.");
}





    }
else if(choice==2){

    main_dl();


}
else{
    printf("invalid number program exits\n");
}
}















