# FOOD Delivery system

## Design features about the source code 
the above source code consists of multiple modules and their corresponding header files .The modules which are present in food delivery system are :

1) Customer Login module 
2) Restaurant Login module
3) Restaurant selection module
4) Item selection module 
5) Cart item module 
6) payment module 
7) food reccomendation module 
8) feedback module 
9) delivery management module 

All these modules have corresponding header files which contain the prototypes of the user defined functions 

### main .c
Here main .c is a module which runs the terminal of the food delivery system . Here all the modules and their corresponding header files have been included here . It asks whether the the person using is a user or an admin and executes the corresponding modules . 

### customerlogin.c
Here the above module has 3 operations .They are:
1) Registration
2) Login
3) forgot password 
customerlogin.h is the corresponding header file.
### Dispmap.c
Here the above module is used in order to display the map in the form of grid in the user where restaurants and roads are marked in the grid . Dispmap.h is the corresponding header file .It also asks the user to enter the delivery address and checks whether the 
delivery address does not coincide with any of the roads or restaurant locations .
### RF1.c
Here the above module is used in order to filter the restaurants so that the users can select the restaurant that they want . 
It consists of the following parts
1) selecting the cuisine 
2) ranks  the restaurants based on 
   
   i) distance 

   ii) ratings

   iii) offers

3) filtering the restaurants based on specific food item 
RF1.h is the corresponding header file for this module .
### cartitem.c
Here the above module is used to select food items from the selected restaurant.The menu is also displayed . 
  There are 4  methods here :
1) Adding items 
2) Removing items
3) View Cart
4) reccomendation
After this method is done the total cost of all the items ordered is displayed to the user.cartitem.h is the corresponding header file for the module.
### reccomendation2.c
Here the above module is used in order to make reccomendations to the user about food items which he has not ordered. It makes reccomendations  based on  previous order histories reccomendation2.h is the corresponding header file . 
### payment.c
Here in the  above module the total cost is reduced by general offers as well as membership offers. Membership offers are only for those who are the members of the app and they get a chance to use the points in order to reduce the total cost . Finally the amount gets deducted from the e-wallet balance of the user.
payment.h is the corresponding header file for the above module.
### feedback.c
Here in the above module the feedback can be given about the restaurant and the individual food items .The ratings out of 5 will have been given by the user . So the ratings will get updated in the restaurants and menu database ̣ feedback.h is the corresponding header file .
### restaurantlogs.c
Here in the above module it consists of 2 parts:
1) login
2) forgot password
if the credentials are correct then the user proceeds to the next module .
### menualter.c
Here in the above module it consists of the following parts
1) add records
2) delete records
3) update price 
4) display records
Add records : This part involves adding a record to the menu of the particular restaurant 

delete records : This involves deleting a record from the menu 

update price : This involves updating the price of a menu item 

Displays records : Displays all the items present in the menu .
menualter.h is the coressponding header file .
### deliverylogin.c
In this above  module enables the delivery guys to login 
so that they can check their e-wallet balance present in their 
account. The driver can then see his bank balance present once he logs in .deliverylogin.h is the coressponding module. The driver can also change the coordinates(his position).
### delivery.c
in this above module based on the shortest path algorithm drivers are selected and their names and phone numbers are displayed to the users.Also the position of the driver is displayed through a grid .Also based on the distance that the driver travels in delivering the food the amount gets updated in the csv file .delivery.h is the corresponding module .
### structures.h
this header file consists of all the structure defintions present in all the c modules . this header file is imported in all the c files so that we can make use of the structure defintions.
## Essential databases to be used 
1) customerlogs.c->customerlogs.csv
2) Dispmap.c->restaurants.csv,csv file of the particular restaurant
3) delivery.c->delivery.csv
4) feedback.c-> restaurants.csv,csv file of the particular restaurant 
5) menualter.c-> csv file of the particular restaurant 
6) payment.c->customerlogs.csv
7) reccomendation2.c->Book1.csv 
8) restaurantlogs.c-> restaurants.csv
9) RF1.c-> restaurants.csv
10)deliverylogin.c->delivery.csv

11) delivery.c->delivery.csv
## compilation Instructions 
Ensure the all the C files,header files and the csv files are in 
the same location. 
### code for compilation of the source code
gcc customerlogin.c Dispmap.c delivery.c feedback.c menualter.c payment.c reccomendation2.c restaurantlogs.c RF1.c main.c -o Food Delivery System 
### alternate method 
Codeblocks : Create a project file and add all the  source c files and the header files  and build the project and click run to execute the project.

