#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
# include "structures.h"
# include "delivery.h"
/*typedef struct delivery{
    char name[100];
    char phoneNumber[20];
    int x;
    int y;
    int dist;
}delinfo;

//Node structure
typedef struct node{
    int x;
    int y;
    int dist;
}node;*/

void DeliveryDistSort(delinfo arr[],int size){
    for (int i=0;i<size-1;i++){
        for (int j=0;j<size-i-1;j++){
            if (arr[j].dist>arr[j+1].dist){
                delinfo temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

//Returns distance b/w two coordinates
int CalcDist2(int source_x, int source_y, int dest_x, int dest_y) {

    // Making Source Nodes
    node2 source_node1;

    source_node1.x=source_x-(source_x%5);
    source_node1.y=source_y-(source_y%5);
    source_node1.dist=(source_x%5)+(source_y%5);

    node2 source_node2;

    source_node2.x=source_x-(source_x%5);
    source_node2.y=source_y+(5-(source_y%5));
    source_node2.dist=(source_x%5)+(5-(source_y%5));

    node2 source_node3;

    source_node3.x=source_x+(5-(source_x%5));
    source_node3.y=source_y-(source_y%5);
    source_node3.dist=(5-(source_x%5))+(source_y%5);

    node2 source_node4;

    source_node4.x=source_x+(5-(source_x%5));
    source_node4.y=source_y+(5-(source_y%5));
    source_node4.dist=(5-(source_x%5))+(5-(source_y%5));


    //Destination nodes

    node2 dest_node1;

    dest_node1.x=dest_x-(dest_x%5);
    dest_node1.y=dest_y-(dest_y%5);
    dest_node1.dist=(dest_x%5)+(dest_y%5);

    node2 dest_node2;

    dest_node2.x=dest_x-(dest_x%5);
    dest_node2.y=dest_y+(5-(dest_y%5));
    dest_node2.dist=(dest_x%5)+(5-(dest_y%5));

    node2 dest_node3;

    dest_node3.x=dest_x+(5-(dest_x%5));
    dest_node3.y=dest_y-(dest_y%5);
    dest_node3.dist=(5-(dest_x%5))+(dest_y%5);

    node2 dest_node4;

    dest_node4.x=dest_x+(5-(dest_x%5));
    dest_node4.y=dest_y+(5-(dest_y%5));
    dest_node4.dist=(5-(dest_x%5))+(5-(dest_y%5));

    int min=999;
    node2 sources[4]={source_node1,source_node2,source_node3,source_node4};
    node2 dests[4]={dest_node1,dest_node2,dest_node3,dest_node4};

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


void main_delivery(int restx ,int resty,int custx,int custy,char driver_name[],char phoneno[],int *driverx,int *drivery){

    FILE *file= fopen("delivery.csv","r");

    srand(time(0));
    char line[2500];

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



        drivers[drivers_index].x=nx;
        drivers[drivers_index].y=ny;


        drivers[drivers_index].dist=CalcDist2(drivers[drivers_index].x,drivers[drivers_index].y,restx,resty);

        drivers[drivers_index].balance=balance;



        drivers_index++;
    }
    fclose(file);


    int homedist=CalcDist2(restx,resty,custx,custy);



    DeliveryDistSort(drivers,drivers_index);
    strcpy(driver_name,drivers[0].name);
    strcpy(phoneno,drivers[0].phoneNumber);
    *driverx=drivers[0].x;
    *drivery=drivers[0].y;
    drivers[0].dist+=homedist;
    drivers[0].balance+=(drivers[0].dist*2);
    FILE *fptr;
    fptr=fopen("delivery.csv","w");
    for(int i=0;i<drivers_index;i++){
        fprintf(fptr,"%s,%s,%s,%s,%f,%d,%d,\n",drivers[i].name,drivers[i].phoneNumber,drivers[i].uname,drivers[i].pword,drivers[i].balance,drivers[i].x,drivers[i].y);
    }
    fclose(fptr);





}
