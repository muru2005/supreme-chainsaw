#ifndef DELIVERY_H_INCLUDED
#define DELIVERY_H_INCLUDED
void DeliveryDistSort(delinfo arr[],int size);
int CalcDist2(int source_x, int source_y, int dest_x, int dest_y) ;
void main_delivery(int restx ,int resty,int custx,int custy,char driver_name[],char phoneno[],int *driverx,int *drivery);
#endif // DELIVERY_H_INCLUDED
