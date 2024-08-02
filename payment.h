#ifndef PAYMENT_H_INCLUDED
#define PAYMENT_H_INCLUDED
float genofferdeduct(struct restaurant arr[],char restid[10],int i,float totalcost);
float memberoffdeduct(struct reg custlog[],char username[],int a,float totalcost);
int main_p(float totalcost,char restid[],char username[]);


#endif // PAYMENT_H_INCLUDED
