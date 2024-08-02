#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "reccomendation.h"
# include "structures.h"

/*typedef struct menu{
    char id[5];
    char type[50];
    char name[100];
    float price;
    float rating;
    int calories;
    int veg;
    int n;
    int priority;
}item;*/

struct menu{
 char foodid[5];
 char foodtype[50];
 char foodname[100];
 float price;
 float rating;
 int calories;
 int veg;
 int nooftimes;
 int priority;
 };

int IsNotMember(struct menu arr[], int size, struct menu element) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].foodid,element.foodid)==0) {
            return 0;
        }
    }
    return 1;
}

void RatingSort(struct menu array[], int size) {
    struct menu temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].rating < array[j + 1].rating) {
                // swap elements if they are in the wrong order
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int PriorityNotIn(int arr1[25],int arr1_size,struct menu element){
    for (int i=0;i<arr1_size;i++){
        if (arr1[i]==element.priority){
            return 0;
        }
    }
    return 1;
}

item FindItem(struct menu items[25],int count,char id[10]){
    for (int i=0;i<count;i++){
        if (strcmp(items[i].foodid,id)==0){
            return items[i];
        }
    }
}

int NotInArray(int num, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 0;
        }
    }
    return 1;
}




void main(){
    char menu_id[50];
    struct menu items[25];

    printf("Enter menu id:");
    scanf("%s",menu_id);

    FILE *fptr;
    fptr=fopen(menu_id,"r");

    if (fptr==NULL){
        printf("File cannot be opened");
    }

    int count=0;
    fseek(fptr, 81, SEEK_SET);

    while(!feof(fptr)){

    fscanf(fptr,"%5[^,],%50[^,],%100[^,],%f,%f,%d,%d,%d,%d\n",
           items[count].foodid, items[count].foodtype,
           items[count].foodname, &items[count].price,
           &items[count].rating, &items[count].calories,
           &items[count].veg, &items[count].nooftimes,
           &items[count].priority);
    count++;
    }

    int i=0;
    int selected_priority[5];
    int selected_priority_index=0;
    int all_priority[5]={1,2,3,4};

    struct menu selected_items[10];
    int selected_items_index;
    char selected_id[10];

    printf("Enter number of selected items[max 10]: ");
    scanf("%d",&selected_items_index);
    printf("\n");

    while (i<selected_items_index){
        printf("Enter selected item %d: ",i+1);
        scanf("%s",selected_id);
        selected_items[i]=FindItem(items,count,selected_id);
         if (PriorityNotIn(selected_priority,selected_priority_index,selected_items[i])){
            selected_priority[selected_priority_index]=selected_items[i].priority;
            selected_priority_index++;
        }
        selected_priority_index++;
        i++;
    }

    int needed_priority[5];
    int needed_priority_index=0;

    for (int j=0;j<5;j++){
        if (NotInArray(all_priority[j],selected_priority,selected_priority_index)){
            needed_priority[needed_priority_index]=all_priority[j];
            needed_priority_index++;
        }
    }

    struct menu recommendations[7];
    int recommendations_index=0;

    RatingSort(items,count);

    for (i=0;i<needed_priority_index;i++){
        for (int j=0;j<count;j++){
            if (items[j].priority==needed_priority[i]){
                recommendations[recommendations_index]=items[j];
                recommendations_index++;
                break;
            }
        }
    }

    int current_recommendation=0;


    while (recommendations_index<7){
            if (current_recommendation>4){
                current_recommendation=1;
            }
            for (i=0;i<count;i++){
                if (items[i].priority==current_recommendation && IsNotMember(recommendations,recommendations_index,items[i]) && IsNotMember(selected_items,selected_items_index,items[i])){
                    recommendations[recommendations_index]=items[i];
                    recommendations_index++;
                    break;
                }
            }

            current_recommendation++;

    }

    printf("\nFinal recommendations are: \n");
    printf("\n%-7s %-25s %-10s %-10s\n\n","Item ID",
           "Item Name","Price","Calories");

    for(i=0;i<recommendations_index;i++){
        printf("%-7s %-25s %-10.2f %d\n",recommendations[i].foodid,
               recommendations[i].foodname,recommendations[i].price,
               recommendations[i].calories);
    }

}*/

