#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# include "menualter.h"
# include "structures.h"

// Structure to hold food item information
/*typedef struct item{
    char id[5];
    char type[50];
    char name[100];
    float price;
    float rating;
    int calories;
    int veg;
    int n;
    int priority;
} item;*/

void DisplayMenu() {
    printf("\n=== MENU ===\n");
    printf("1. Display Records\n");
    printf("2. Update Price\n");
    printf("3. Add Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
}

void DisplayRecords(item records[], int count) {
    printf("\n=== RECORDS ===\n");
    for (int i = 0; i < count; i++) {
        printf("Food ID: %s\n", records[i].id);
        printf("Food Type: %s\n", records[i].type);
        printf("Food Name: %s\n", records[i].name);
        printf("Price: %.2f\n", records[i].price);
        printf("Rating: %.2f\n", records[i].rating);
        printf("Calories: %d\n", records[i].calories);
        printf("Veg: %d\n", records[i].veg);
        printf("No. of Times Ordered: %d\n", records[i].n);
        printf("\n");
    }
}

void UpdatePrice(item records[], int count) {
    char id[10];
    float newPrice;
    printf("Enter the Food ID: ");
    scanf("%s", id);

    for (int i = 0; i < count; i++) {
        if (strcmp(records[i].id, id) == 0) {
            printf("The accessed item is %s\n",records[i].name);
            printf("Enter the new price: ");
            scanf("%f", &newPrice);
            records[i].price = newPrice;
            printf("Price updated successfully.\n");
            return;
        }
    }

    printf("Food ID not found.\n");
}

int GetPriority(item arr1[100],int count,char food_type[50]){
    int k;
    for (k=0;k<count;k++){
        if (strcmp(arr1[k].type,food_type)==0){
            return arr1[k].priority;
        }
    }
}

void AddRecord(item records[], int *count) {
    if (*count >= 100) {
        printf("Maximum records reached. Cannot add more.\n");
        return;
    }

    item newItem;
    printf("Enter Food ID: ");
    scanf("%s", newItem.id);
    printf("Enter Food Type: ");
    scanf("\n%[^\n]", newItem.type);
    printf("Enter Food Name: ");
    scanf("\n%[^\n]", newItem.name);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    printf("Enter Rating: ");
    scanf("%f", &newItem.rating);
    printf("Enter Calories: ");
    scanf("%d", &newItem.calories);
    printf("Enter Veg (1 for yes, 0 for no): ");
    scanf("%d", &newItem.veg);
    newItem.n=0;


    records[*count] = newItem;
    (*count)++;

    printf("Record added successfully.\n");
}

void DeleteRecord(item records[], int *count) {
    char id[10];
    printf("Enter the Food ID to delete: ");
    scanf("%s", id);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(records[i].id, id) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                records[j] = records[j + 1];
            }
            (*count)--;
            printf("Record deleted successfully.\n");
            i--; // Recheck current index after deletion
        }
    }

    if (!found) {
        printf("Food ID not found.\n");
    }
}

/*int main() {
    FILE *file;

    char menu_id[100];
    printf("Enter menu id: ");
    gets(menu_id);

    file = fopen(menu_id,"r");

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
    file = fopen(menu_id, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
      fprintf(file, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n",
            "foodid", "foodtype", "foodname","price", "rating", "calories", "veg",
            "no_of_times_ordered,priority");

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
                records[i].priority);
    }

    fclose(file);

    return 0;
}*/




