#ifndef CARTITEM_H_INCLUDED
#define CARTITEM_H_INCLUDED
int additem(struct menu arr1[100],struct cart cart1[],int m);
int removeitem(char fid[5],struct cart cart1[]);
int viewcart(struct cart cart1[]);
float* main_c(char menuid[],struct cart cart1[],char custid[],char restid[],char cusine[]);

#endif // CARTITEM_H_INCLUDED,s
