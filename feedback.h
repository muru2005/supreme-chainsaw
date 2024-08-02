#ifndef FEEDBACK_H_INCLUDED
#define FEEDBACK_H_INCLUDED

int raterest(struct restaurant arr[],int i,char id[]);
int ratemenu(struct menu arr1[],char array1[][100],int m,char file[30],int);
int main_f(char id[10],char file[100],struct cart cart1[],int);

#endif // FEEDBACK_H_INCLUDED
