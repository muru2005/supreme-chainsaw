# include <stdio.h>
# include <string.h>
# include "payment.h"
# include "structures.h"
/*struct restaurant {
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

};*/
/*struct reg {
    char custid[50];
    char custname[100];
    char username[100];
    char pwd[100];
    char dob[50];
    char phoneno[50];
    int status;
    int points;
    int balance;
};*/

float genofferdeduct(struct restaurant arr[],char restid[10],int i,float totalcost){

 for(int j=0;j<i;j++){
    if(strcmp(arr[j].restaurantid,restid)==0){
        float amt=(float)((arr[j].offer)*totalcost)/100;



        if(amt<=arr[j].min_amount){
            totalcost=((100-arr[j].offer)*totalcost)/100;
        }
        else{
            totalcost-=arr[j].min_amount;
        }

    }
 }
 return totalcost;

}
float memberoffdeduct(struct reg custlog[],char username[],int a,float totalcost){
   FILE *fp;
   for(int i=0;i<a;i++){
    if(strcmp(custlog[i].username,username)==0){
        if(custlog[i].status==1){
         int y=0;
            printf("do you wish to use points y -1 or n-0:");
            scanf("%d",&y);
            if(y==1){
                int no=0;
                printf("enter the no of points you wish to use:");
                scanf("%d",&no);


                if(no<=custlog[i].points){
                    custlog[i].points-=no;


                    totalcost=totalcost-(no*2);

                    custlog[i].points+= totalcost/50;
                    if(totalcost<=custlog[i].balance){
                        custlog[i].balance-=totalcost;
                    }
                    else{
                        printf("balance is not there\n");
                        return 0.0;
                    }
                }
                else{
                    printf("points is not there\n");
                    custlog[i].points+= totalcost/50;
                    if(totalcost<=custlog[i].balance){
                        custlog[i].balance-=totalcost;

                    }
                    else{
                        printf("balance not there\n");
                        return 0.0;
                    }


                }
                fp=fopen("customerlogs.csv","w");
                if(fp==NULL){
                    printf("the file cannot be opened");
                }

            fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n","CustID","Custname","Username","pwd","phoneno","dob","membership status","loyalty points","ewallet balance");
            for(int i=0;i<a;i++){
                 fprintf(fp,"%s,%s,%s,%s,%s,%s,%d,%d,%d\n",custlog[i].custid,custlog[i].custname,custlog[i].username,custlog[i].pwd,custlog[i].phoneno,custlog[i].dob,custlog[i].status,custlog[i].points,custlog[i].balance);

            }
            return totalcost;

            }
            else{

                custlog[i].points+= totalcost/50;
               if(totalcost<=custlog[i].balance){
                custlog[i].balance-=totalcost;}
               else{
                printf("balance is not there");
                return 0.0;
               }
                fp=fopen("customerlogs.csv","w");
                if(fp==NULL){
                    printf("the file cannot be opened");
                }


            fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n","CustID","Custname","Username","pwd","phoneno","dob","membership status","loyalty points","ewallet balance");
            for(int i=0;i<a;i++){
                 fprintf(fp,"%s,%s,%s,%s,%s,%s,%d,%d,%d\n",custlog[i].custid,custlog[i].custname,custlog[i].username,custlog[i].pwd,custlog[i].phoneno,custlog[i].dob,custlog[i].status,custlog[i].points,custlog[i].balance);}

            return totalcost;



            }
            }
       else{
            custlog[i].points+= totalcost/50;
            if(totalcost<=custlog[i].balance){
                custlog[i].balance-=totalcost;
            }
            else{
                printf("balance is not there");
                return 0.0;
            }
            fp=fopen("customerlogs.csv","w");
                if(fp==NULL){
                    printf("the file cannot be opened");
                }


            fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n","CustID","Custname","Username","pwd","phoneno","dob","membership status","loyalty points","ewallet balance");
            for(int i=0;i<a;i++){
                 fprintf(fp,"%s,%s,%s,%s,%s,%s,%d,%d,%d\n",custlog[i].custid,custlog[i].custname,custlog[i].username,custlog[i].pwd,custlog[i].phoneno,custlog[i].dob,custlog[i].status,custlog[i].points,custlog[i].balance);}
            return totalcost;
        }
        fclose(fp);}}}



int main_p(float totalcost,char restid[],char username[]){
 printf("welcome to payment gateway module!\n");


 char password[50];
 struct restaurant arr[100];
 int i=0;


 FILE *fptr;
 fptr=fopen("restaurants.csv","r");
 if(fptr==NULL){
    printf("the file cannot be opened\n");
 }
 char b[300];
 fgets(b,sizeof(b),fptr);
 while(!feof(fptr)){
    fscanf(fptr, "%9[^,],%99[^,],%d,%d,%49[^,],%99[^,],%99[^,],%99[^,],%f,%d,%d,%d\n",
                  arr[i].restaurantid, arr[i].restaurantname, &arr[i].x, &arr[i].y,
                  arr[i].cuisine, arr[i].menu, arr[i].username, arr[i].password,
                  &arr[i].ratings, &arr[i].nooftimesordered,&arr[i].offer,&arr[i].min_amount);

   i++;}
 fclose(fptr);



 totalcost=genofferdeduct(arr,restid,i,totalcost);
 printf("the total cost after applying general offers is %.2f\n",totalcost);


 FILE*fp;
 fp=fopen("customerlogs.csv","r");
 if(fp==NULL){
    printf("the file cannot be opened");
 }
char header[325]; // Assuming headers are less than 256 characters
fgets(header, sizeof(header), fp); // Read and discard the header line


 int a=0;
 struct reg custlog[100];
 while(!feof(fp)){
     fscanf(fp,"%50[^,],%100[^,],%100[^,],%100[^,],%100[^,],%100[^,],%d,%d,%d\n",custlog[a].custid,custlog[a].custname,custlog[a].username,custlog[a].pwd,custlog[a].phoneno,custlog[a].dob,&custlog[a].status,&custlog[a].points,&custlog[a].balance);
    a++;}

 fclose(fp);

 float d=memberoffdeduct(custlog,username,a,totalcost);
 if (d!=0.0){
 printf("the final cost is %.2f\n",d);
 return 1;
 }
 else{
    printf("order is cancelled!");
    return 0;
 }
}




























