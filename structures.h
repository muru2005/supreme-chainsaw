#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
struct reg {
    char custid[50];
    char custname[100];
    char username[100];
    char pwd[100];
    char dob[50];
    char phoneno[50];
    int status;
    int points;
    int balance;
}s1;
struct restaurant {
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
};
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
typedef struct node{
    int x;
    int y;
    int dist;
}node;
typedef struct restaurants{
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
}restaurant;
typedef struct menus{
    char id[5];
    char type[50];
    char name[100];
    float price;
    float rating;
    int calories;
    int veg;
    int n;
    int priority;
}items;
/*typedef struct node{
    int x;
    int y;
    int dist;
}node;*/
typedef struct route{
    int source_node_x;
    int source_node_y;
    int dest_node_x;
    int dest_node_y;
}route;
typedef struct item{
    char id[5];
    char type[50];
    char name[100];
    float price;
    float rating;
    int calories;
    int veg;
    int n;
    int priority;
} item;
struct cart{
  char foodid[5];
  char foodname[100];
  char foodtype[50];
  float price;
  int qty;
  float totprice;
  int totcalories;



};
typedef struct menu3{
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
    float rating;
    char name[100];
    char ftype[100];
    float price;
    int calories;
}item_asoc;

;
typedef struct delivery{
    char name[100];
    char phoneNumber[20];
    int x;
    int y;
    int dist;
    char uname[100];
    char pword[100];
    float balance;
}delinfo;

typedef struct nodes{
    int x;
    int y;
    int dist;
}node2;


#endif // STRUCTURES_H_INCLUDED
