# include <stdio.h>
# include <string.h>
# include "cartitem.h"
# include "structures.h"
# include "reccomendation2.h"
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

/*struct cart{
  char foodid[5];
  char foodname[100];
  char foodtype[50];
  float price;
  int qty;
  float totprice;
  int totcalories;



};*/
float sum;
int a=0;

int additem(struct menu arr1[100],struct cart cart1[],int m){

 char fid[5];
 int qty=0;
 printf("enter the foodid:");
 scanf("%s",fid);
 for(int i=0;i<m;i++){
            if (strcmp(arr1[i].foodid,fid)==0){
                printf("enter the qty:");
                scanf("%d",&qty);
                strcpy(cart1[a].foodid,arr1[i].foodid);
                strcpy(cart1[a].foodname,arr1[i].foodname);
                strcpy(cart1[a].foodtype,arr1[i].foodtype);
                cart1[a].price=arr1[i].price;
                cart1[a].qty=qty;
                cart1[a].totprice=qty*cart1[a].price;
                cart1[a].totcalories=qty*arr1[i].calories;
                a++;
                break;
            }}
 }

int removeitem(char fid[5],struct cart cart1[]){
      int choice =0;
      printf("1-want to remove whole item\n0-change the quantity");
      scanf("%d",&choice);
      if(choice){
        int index=0;

        for(int i=0;i<a;i++){
            if(strcmp(cart1[i].foodid,fid)==0){
                index=i;
            }
        }


        for(int i=index;i<a;i++){
            cart1[i]=cart1[i+1];
            }
        a--;

}
else if(choice==0){
    int qty=0;
    printf("enter the new qty\n");
    scanf("%d",&qty);
    for(int i=0;i<a;i++){
            if(strcmp(cart1[i].foodid,fid)==0){
                int calories=cart1[i].totcalories/(cart1[i].qty);
                cart1[i].qty=qty;
                cart1[i].totprice=qty*cart1[i].price;
                cart1[i].totcalories=qty*calories;

            }
        }



}
}


int viewcart(struct cart cart1[]){
            printf("%-5s %-15s %-25s %-5s %-5s %-5s %-5s\n\n","foodid","foodtype","foodname","price","qty","totprice","totcalories");
            int sum=0;
            for(int i=0;i<a;i++){
                printf("%-5s   %-15s   %-25s   %-5.2f   %-5d   %-5.2f   %-5d\n",cart1[i].foodid,cart1[i].foodtype,cart1[i].foodname,cart1[i].price,cart1[i].qty,cart1[i].totprice,cart1[i].totcalories);
                sum+=cart1[i].totcalories;}
            printf("the total calories is %d",sum);
        }

















float* main_c(char menuid[],struct cart cart1[],char custid[],char restid[],char cusine[]){

 struct menu arr1[100];


 FILE*fptr;
 fptr=fopen(menuid,"r");
 if(fptr==NULL){
    printf("file cannot be opened\n");
 }
 int m=0;
 char d[325];
 fgets(d,sizeof(d),fptr);
 while(m<100 &&!feof(fptr)){

    fscanf(fptr,"%5[^,],%50[^,],%100[^,],%f,%f,%d,%d,%d,%d\n", arr1[m].foodid, arr1[m].foodtype, arr1[m].foodname, &arr1[m].price, &arr1[m].rating, &arr1[m].calories, &arr1[m].veg, &arr1[m].nooftimes,&arr1[m].priority);
    m++;

 }


 printf("%-7s %-15s %-45s %-7s %-7s %-7s %-5s %-5s\n","foodid","foodtype","foodname","price","rating","calories","veg","n");


 int n=0;

 while(n<m){
    printf("%-7s %-15s %-45s %-7.2f %-7.2f %-7d %-5d %-5d\n",arr1[n].foodid,arr1[n].foodtype,arr1[n].foodname,arr1[n].price,arr1[n].rating,arr1[n].calories,arr1[n].veg,arr1[n].nooftimes);
    n++;
 }
 int num=1;

 while(num){
    int choice=0;
    printf("welcome to item selection page!\n");
    printf("enter the choice you want to do 1-add items to cart\n2-to remove items from the cart\n3-to view the cart\n4-view reccomendation");
    scanf("%d",&choice);
    if(choice==1){
      additem(arr1,cart1,m);



      }
    else if(choice==2){
        char fid[5];

        printf("enter the foodid:");
        scanf("%s",fid);

        removeitem(fid,cart1);
        }




    else if(choice==3){


        viewcart(cart1);
    }

    else if(choice==4){



        char cartid[100][11];
        for(int i=0;i<a;i++){
            strcpy(cartid[i],cart1[i].foodid);
        }
        main_r2(menuid,cartid,a,custid,restid);

    }
    int b=0;

    printf("want to contiune yes-1 or no-0:");

    scanf("%d",&b);
    if(b==0){
      for(int i=0;i<a;i++){
                sum+=cart1[i].totprice;
            }

        printf("the total price of all items is %.2f\n",sum);
         static float arr3[3];
        arr3[0]=sum;
        arr3[1]=(float)a;

    fclose(fptr);

    fptr=fopen("Book1.csv","a");
    if(fptr==NULL){
        printf("unable to open the file");
    }
  fprintf(fptr,"\n%s,%s,%s,",restid,cusine,custid);
  if(a!=1){
    for(int i=0;i<a-1;i++){
        fprintf(fptr,"%s,",cart1[i].foodid);
    }
    fprintf(fptr,"%s",cart1[a-1].foodid);
    fclose(fptr);}
  else{
    fprintf(fptr,"%s",cart1[0].foodid);
  }
    return arr3;




        }}

      }


















