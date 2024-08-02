#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "RF1.h"
# include "structures.h"


//Node structure
/*typedef struct node{
    int x;
    int y;
    int dist;
}node;*/

//Restaurant structure
/*typedef struct restaurants{
    char id[10];
    char name[100];
    int x;
    int y;
    char cuisine[50];
    char menu[100];
    char username[100];
    char password[100];
    float ratings;
    int n;
    int dist;
    int offer_percent;
    int offer_amount;
}restaurant;*/

/*typedef struct menus{
    char id[5];
    char type[50];
    char name[100];
    float price;
    float rating;
    int calories;
    int veg;
    int n;
    int priority;
}items;*/

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



//Bubble Sort for distance
void DistanceSort(restaurant array[], int size) {
    restaurant temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].dist > array[j + 1].dist) {
                // swap elements if they are in the wrong order
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//Bubble sort for rating (Descending)
void RatingSort(restaurant array[], int size) {
    restaurant temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].ratings < array[j + 1].ratings) {
                // swap elements if they are in the wrong order
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//Bubble sort for Offer amount(Descending)
void OfferSort(restaurant array[], int size) {
    restaurant temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].offer_amount < array[j + 1].offer_amount) {
                // swap elements if they are in the wrong order
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

//Returns distance b/w two coordinates
int CalcDist(int source_x, int source_y, int dest_x, int dest_y) {

    // Making Source Nodes
    node source_node1;

    source_node1.x=source_x-(source_x%5);
    source_node1.y=source_y-(source_y%5);
    source_node1.dist=(source_x%5)+(source_y%5);

    node source_node2;

    source_node2.x=source_x-(source_x%5);
    source_node2.y=source_y+(5-(source_y%5));
    source_node2.dist=(source_x%5)+(5-(source_y%5));

    node source_node3;

    source_node3.x=source_x+(5-(source_x%5));
    source_node3.y=source_y-(source_y%5);
    source_node3.dist=(5-(source_x%5))+(source_y%5);

    node source_node4;

    source_node4.x=source_x+(5-(source_x%5));
    source_node4.y=source_y+(5-(source_y%5));
    source_node4.dist=(5-(source_x%5))+(5-(source_y%5));


    //Destination nodes

    node dest_node1;

    dest_node1.x=dest_x-(dest_x%5);
    dest_node1.y=dest_y-(dest_y%5);
    dest_node1.dist=(dest_x%5)+(dest_y%5);

    node dest_node2;

    dest_node2.x=dest_x-(dest_x%5);
    dest_node2.y=dest_y+(5-(dest_y%5));
    dest_node2.dist=(dest_x%5)+(5-(dest_y%5));

    node dest_node3;

    dest_node3.x=dest_x+(5-(dest_x%5));
    dest_node3.y=dest_y-(dest_y%5);
    dest_node3.dist=(5-(dest_x%5))+(dest_y%5);

    node dest_node4;

    dest_node4.x=dest_x+(5-(dest_x%5));
    dest_node4.y=dest_y+(5-(dest_y%5));
    dest_node4.dist=(5-(dest_x%5))+(5-(dest_y%5));

    int min=999;
    node sources[4]={source_node1,source_node2,source_node3,source_node4};
    node dests[4]={dest_node1,dest_node2,dest_node3,dest_node4};

    for (int i=0; i<4; ++i){

         for (int j=0; j<4; ++j){
               int dist;
                dist=abs(sources[i].x-dests[j].x)+abs(sources[i].y-dests[j].y)+sources[i].dist+dests[j].dist;
                if (dist<min) {
                    min=dist;
                }
            }
        }




    return min;
}


int main_rf1(int dest_x,int dest_y) {

    int dist;





    //Array to hold all restaurants
    restaurant all_rest[100];

    FILE *fptr;

    fptr = fopen("restaurants.csv", "r");
    if (fptr == NULL) {
        printf("File could not be opened\n");
        return 1;
    }

    char header1[325];
    fgets(header1,sizeof(header1),fptr);

    int i = 0;
    int count=0;
    while (fscanf(fptr,"%9[^,],%99[^,],%d,%d,%49[^,],%99[^,],%99[^,],%99[^,],%f,%d,%d,%d\n",
                  all_rest[i].id, all_rest[i].name,
                  &all_rest[i].x, &all_rest[i].y,
                  all_rest[i].cuisine, all_rest[i].menu,
                  all_rest[i].username, all_rest[i].password,
                  &all_rest[i].ratings, &all_rest[i].n,
                  &all_rest[i].offer_percent,&all_rest[i].offer_amount) == 12) {
        i++;
        count++;
    }
    fclose(fptr);

    //Array to hold nearby restaurants
    restaurant near_rest[50];
    int near_rest_index=0;


    //To shortlist nearby restaurant
    int j;
    for (j = 0; j < i; j++) {
        int dist =CalcDist(all_rest[j].x,all_rest[j].y,dest_x,dest_y);
        if (dist<30) {
            all_rest[j].dist=dist;
            near_rest[near_rest_index]=all_rest[j];
            near_rest_index++;
        }
    }
     restaurant select_rest[50];
    //Array to hold cuisine filtered restaurants

    int select_rest_index=0;

    char cuisine[50];

    printf("Enter required cuisine:");
    scanf("\n%[^\n]",cuisine);

    for (i=0; i<near_rest_index;i++) {
        if (strcmp(near_rest[i].cuisine,cuisine)==0){
            select_rest[select_rest_index]=near_rest[i];
            select_rest_index++;
        }
    }

    int ranking_choice;

    //To get choice of ranking
    printf("\n");
    printf("Choices for ranking the restaurants\n");
    printf("1-Distance\n");
    printf("2-Rating\n");
    printf("3-Offer\n");
    printf("\n");
    printf("Enter choice of ranking: ");
    scanf("%d",&ranking_choice);
    printf("\n");

    if (ranking_choice==1){
        DistanceSort(select_rest, select_rest_index);
        printf("%-20s %-20s %s\n\n","Restaurant Name","Cuisine","Distance");

        //Printing restaurant of same cuisine
        for (i=0; i<select_rest_index; i++) {
            printf("%-20s %-20s %d\n",select_rest[i].name,select_rest[i].cuisine,select_rest[i].dist);
        }
    }
    else if (ranking_choice==2){
        RatingSort(select_rest, select_rest_index);
        printf("%-20s %-20s %s\n\n","Restaurant Name","Cuisine","Rating");

        //Printing restaurant of same cuisine
        for (i=0; i<select_rest_index; i++) {
            printf("%-20s %-20s %.2f\n",select_rest[i].name,select_rest[i].cuisine,select_rest[i].ratings);
        }
    }
    else if (ranking_choice==3){
        OfferSort(select_rest, select_rest_index);
        printf("%-20s %-20s %s\n\n","Restaurant Name","Cuisine","Offer");

        //Printing restaurant of same cuisine
        for (i=0; i<select_rest_index; i++) {
            printf("%-20s %-20s %d%% upto Rs%d\n",
            select_rest[i].name,select_rest[i].cuisine,
            select_rest[i].offer_percent,select_rest[i].offer_amount);
        }
    }
    else {
        printf("Invalid choice. No ranking done.\n");
        printf("%-20s %-20s %s\n\n","Restaurant Name","Cuisine","Rating");
        for (i=0; i<select_rest_index; i++) {
            printf("%-20s %-20s %.2f\n",select_rest[i].name,select_rest[i].cuisine,select_rest[i].ratings);
        }
    }

    printf("\n");

    int search_by_food;

    printf("Do you wish to search for a specific food item?\n");
    printf("Enter 1 for yes and 0 for no: ");
    scanf("%d",&search_by_food);

    printf("\n");

    if (search_by_food){
        char food_name[50];
    printf("Enter food name: ");
    scanf("\n%[^\n]",food_name);

    restaurant specific_food_rest[50];
    int specific_food_rest_index=0;

    for (i=0;i<select_rest_index;i++){


        FILE *fp;
        fp=fopen(select_rest[i].menu,"r");
        if(fp==NULL){
            printf("file cannot be opened");
        }

        items items[100];
        int item_count=0;

        char header[325];

        fgets(header,sizeof(header),fp);

        while(!feof(fp)){
                fscanf(fp,"%5[^,],%50[^,],%100[^,],%f,%f,%d,%d,%d,%d\n",
                items[item_count].id, items[item_count].type,
                items[item_count].name, &items[item_count].price,
                &items[item_count].rating, &items[item_count].calories,
                &items[item_count].veg, &items[item_count].n,
                &items[item_count].priority);
                item_count++;
        }

        fclose(fp);


         for (int j=0;j<item_count;j++){
            if (strcmp(items[j].name,food_name)==0){
                specific_food_rest[specific_food_rest_index]=select_rest[i];
                specific_food_rest_index++;
                break;

            }

        }

    }




    printf("\nThe final restaurants are: \n\n");
    printf("%-20s %-20s %-10s %-10s %-10s\n\n","Restaurant Name","Cuisine","Distance","Rating","Offer");

    for (i=0;i<specific_food_rest_index;i++){
        printf("%-20s %-20s %-10d %-10.2f %d%% upto Rs%d\n",
        specific_food_rest[i].name,specific_food_rest[i].cuisine,
        specific_food_rest[i].dist,specific_food_rest[i].ratings,
        specific_food_rest[i].offer_percent,specific_food_rest[i].offer_amount);
    }
    return specific_food_rest_index;
    }

    else{
        printf("\nThe final restaurants are: \n\n");
        printf("%-20s %-20s %-10s %-10s %-10s\n\n","Restaurant Name","Cuisine","Distance","Rating","Offer");

    for (i=0;i<select_rest_index;i++){
        printf("%-20s %-20s %-10d %-10.2f %d%% upto Rs%d\n",
        select_rest[i].name,select_rest[i].cuisine,
        select_rest[i].dist,select_rest[i].ratings,
        select_rest[i].offer_percent,select_rest[i].offer_amount);
    }
    return select_rest_index;
    }





}



