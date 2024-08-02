#include <stdio.h>
#include <string.h>
# include "feedback.h"
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
/*struct menu{
 char foodid[5];
 char foodtype[50];
 char foodname[100];
 float price;
 float rating;
 int calories;
 int veg;
 int nooftimes;
 int priority;
 };*/

int raterest(struct restaurant arr[],int i,char id[]){


    int found = 0;


    for (int j = 0; j < i; j++) {
        if (strcmp(arr[j].restaurantid,id) == 0) {
            float rating;

            printf("Enter the overall rating you want to give: ");
            scanf("%f", &rating);
            arr[j].ratings = (arr[j].ratings * arr[j].nooftimesordered + rating) / (arr[j].nooftimesordered + 1);
            arr[j].nooftimesordered++;



            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No restaurant with such id exists\n");

    }
    FILE *fptr;
    fptr = fopen("restaurants.csv", "w");
    if (fptr == NULL) {
        printf("File could not be opened\n");

    }

    fprintf(fptr, "%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
            "RestaurantId", "RestaurantName", "X", "Y", "Cuisine", "Menu",
            "Username", "Password", "Ratings", "No of times ordered","offer","min_amount");

    for (int j = 0; j < i; j++) {
        fprintf(fptr, "%s,%s,%d,%d,%s,%s,%s,%s,%.2f,%d,%d,%d\n",
                arr[j].restaurantid, arr[j].restaurantname, arr[j].x, arr[j].y,
                arr[j].cuisine, arr[j].menu, arr[j].username, arr[j].password,
                arr[j].ratings, arr[j].nooftimesordered,arr[j].offer,arr[j].min_amount);
    }


    fclose(fptr);






}

int ratemenu(struct menu arr1[],char array1[][100],int m,char file[30],int size){
  for(int n=0;n<size;n++){
    for(int i=0;i<m;i++){
        if(strcmp(arr1[i].foodid,array1[n])==0){
            float rating=0.0;
            printf("enter the ratings for the food item %s:",arr1[i].foodid);
            scanf("%f",&rating);
            arr1[i].rating = (arr1[i].rating * arr1[i].nooftimes + rating) / (arr1[i].nooftimes + 1);
            arr1[i].nooftimes++;
            break;


        }

    }}

    FILE *fp;
    fp=fopen(file,"w");
    if(fp==NULL){
        printf("file could not be opened");
        return 1;
    }
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
            "foodid", "foodtype", "foodname","price", "rating", "calories", "veg",
            "no_of_times_ordered","priority");

    for (int j = 0; j < m; j++) {
        fprintf(fp, "%s,%s,%s,%.2f,%.2f,%d,%d,%d,%d\n",
                arr1[j].foodid, arr1[j].foodtype, arr1[j].foodname, arr1[j].price,
                arr1[j].rating, arr1[j].calories, arr1[j].veg, arr1[j].nooftimes,arr1[j].priority);}


    fclose(fp);





}







int main_f(char id[10],char file[100],struct cart cart1[],int size) {

    printf("Welcome to feedback portal\n");
    struct restaurant arr[100];

    FILE *fptr;

    struct menu arr1[100];

    fptr = fopen("restaurants.csv", "r");
    if (fptr == NULL) {
        printf("File could not be opened\n");
        return 1;
    }

    char c[325];
    fgets(c,sizeof(c),fptr);


    int i = 0;
    while (fscanf(fptr, "%9[^,],%99[^,],%d,%d,%49[^,],%99[^,],%99[^,],%99[^,],%f,%d,%d,%d\n",
                  arr[i].restaurantid, arr[i].restaurantname, &arr[i].x, &arr[i].y,
                  arr[i].cuisine, arr[i].menu, arr[i].username, arr[i].password,
                  &arr[i].ratings, &arr[i].nooftimesordered,&arr[i].offer,&arr[i].min_amount) == 12) {
        i++;
    }

    fclose(fptr);
    raterest(arr,i,id);




    FILE*fp;
    fp = fopen(file, "r");
    if (fp == NULL) {
    printf("file cannot be opened\n");
    return 1;
     }
   char d[325];
   fgets(d,sizeof(d),fp);
   int m=0;
   while (m<20 &&!feof(fp)) {
    fscanf(fp, "%5[^,],%50[^,],%100[^,],%f,%f,%d,%d,%d,%d\n", arr1[m].foodid, arr1[m].foodtype, arr1[m].foodname, &arr1[m].price, &arr1[m].rating, &arr1[m].calories, &arr1[m].veg, &arr1[m].nooftimes,&arr1[m].priority);
    m++;
    }

    char array1[100][100];


    for(int i=0;i<size;i++){

        strcpy(array1[i],cart1[i].foodid);
    }

    fclose(fp);
    ratemenu(arr1,array1,m,file,size);




}


