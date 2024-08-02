#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "structures.h"
# include "reccomendation2.h"


/*typedef struct menu3{
    char id[10];
    char type[50];
    char name[100];
    float price;
    float rating;
    int calories;
    int veg;
    int n;
    int priority;
}item1;

typedef struct item_associativity{
    char id[10];
    int asoc;
}item_asoc;*/


void AssocSort1(item_asoc all_items[],int size){
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size-i-1;j++){
            if (all_items[j].asoc<all_items[j+1].asoc){
                item_asoc temp=all_items[j];
                all_items[j]=all_items[j+1];
                all_items[j+1]=temp;
            }
            else if ((all_items[j].asoc==all_items[j+1].asoc)&&(all_items[j].rating<all_items[j+1].rating)){
                item_asoc temp=all_items[j];
                all_items[j]=all_items[j+1];
                all_items[j+1]=temp;
            }
        }
    }
}

int InArray(char foodid[10], char arr[100][11], int size) {
    for (int i = 0; i < size; i++) {

        if (strcmp(foodid,arr[i])==0) {

            return 1;
        }
    }
    return 0;
}

item1 FindItem(item1 items[25],int count,char id[10]){
    for (int i=0;i<count;i++){
        if (strcmp(items[i].id,id)==0){
            return items[i];
        }
    }
}




void main_r2(char menu_id[],char cartid[100][11],int size1,char custid[],char rid[]){

    item1 items[25];

    FILE *fptr;
    fptr=fopen(menu_id,"r");

    if (fptr==NULL){
        printf("File cannot be opened");
    }

    int count=0;
    char del[1000];
    fgets(del,sizeof(del),fptr);

    while(!feof(fptr)){

    fscanf(fptr,"%5[^,],%50[^,],%100[^,],%f,%f,%d,%d,%d,%d\n",
           items[count].id, items[count].type,
           items[count].name, &items[count].price,
           &items[count].rating, &items[count].calories,
           &items[count].veg, &items[count].n,
           &items[count].priority);
    count++;
    }

    fclose(fptr);

    int i=0;

    item recommendtions[10];
    item_asoc all_item_assoc[50];

    for (i=0;i<count;i++){
        strcpy(all_item_assoc[i].id,items[i].id);
        all_item_assoc[i].asoc=0;
        all_item_assoc[i].rating=items[i].rating;
        strcpy(all_item_assoc[i].name,items[i].name);
        strcpy(all_item_assoc[i].ftype,items[i].type);
        all_item_assoc[i].price=items[i].price;
        all_item_assoc[i].calories=items[i].calories;

    }


    char food_id[10];

    FILE *file= fopen("Book1.csv","r");
    char line[1000];


    while(fgets(line,sizeof(line),file)){

        char *rest_id;
        char *rest_cuisine;
        char *cust_id;
        char *ordered_item;
        char *food_id;
        char prev_foods[50][10];
        int prev_food_index=0;
        int asoc_points=10;

        rest_id=strtok(line,",");
        rest_cuisine=strtok(NULL,",");
        cust_id=strtok(NULL,",");

        if (strcmp(rid,rest_id)==0){
            asoc_points+=2;
        }


        if (strcmp(custid,cust_id)==0){
            asoc_points+=5;
        }


        while ((food_id=strtok(NULL,",\n"))!=NULL){
            strcpy(prev_foods[prev_food_index],food_id);
            prev_food_index++;
        }

        for (i=0;i<size1;i++){

            if (InArray(cartid[i],prev_foods,prev_food_index)){

                for (int j=0;j<prev_food_index;j++){
                    for (int k=0;k<count;k++){
                        if (strcmp(all_item_assoc[k].id,prev_foods[j])==0){
                            all_item_assoc[k].asoc+=asoc_points;
                        }
                    }
                }
            }

        }

    }
    printf("%-5s %-25s %-10s %-5s %-5s %-5s\n\n","foodid","foodname","foodtype","price","calories","associativity");
    AssocSort1(all_item_assoc,count);
    int rec=0;

    for (int k=0;k<20;k++){
            if (InArray(all_item_assoc[k].id,cartid,size1)){
                printf("%-5s %-25s %-10s %-5.2f %-5d %-5s\n",all_item_assoc[k].id,all_item_assoc[k].name,all_item_assoc[k].ftype,all_item_assoc[k].price,all_item_assoc[k].calories,"chosen");
            }
            else{
               printf("%-5s %-25s %-10s %-5.2f %-5d %-5d\n",all_item_assoc[k].id,all_item_assoc[k].name,all_item_assoc[k].ftype,all_item_assoc[k].price,all_item_assoc[k].calories,all_item_assoc[k].asoc);
                rec++;
            }

            if (rec==7){
                break;
            }

    }
    fclose(file);




}

