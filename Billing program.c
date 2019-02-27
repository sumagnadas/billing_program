#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
#include<windows.h>//include files for memory allocation,error no.,sleep() function,etc
typedef struct Items
{
	char name[100],unit[15];
	float price, amount,item_total;
}ite;//structure for each item
void main()
{
	int i,j;
	FILE *fp,*fp1;//pointers for file
	fp1=fopen("D:\\printable_bill.txt","w");//file for printing the bill
	fp=fopen("D:\\bills.txt","a+");//file for keeping records
	if(fp==NULL || fp1==NULL )
	{
		perror("OOPS ERROR");
		printf("\nError no : %d",errno);
		exit(1);
	}//checks for error in file opening
	float total=0;
	ite *item;
	char cust_name[50];
	printf("\nEnter the customer's name : ");
	gets(cust_name);//customer name for storage of bill
	printf("How many items have the customer purchased : ");
	scanf("%d",&i);//number of items
	fflush(stdin);
	item=(ite *)malloc(i*sizeof(ite));//dynamically allocate memory for the items in the bill
	for(j=0;j<i;j++)
	{
		printf("\nEnter the name of item %d : ",j+1);
		gets(item[j].name);
		printf("\nEnter the unit of item %d : ",j+1);
		scanf("%s",item[j].unit);
		printf("\nEnter the price of item %d : ",j+1);
		scanf("%f",&item[j].price);
		fflush(stdin);
		printf("\nEnter the amount of item %d : ",j+1);
		scanf("%f",&item[j].amount);
		fflush(stdin);
	}//data input for each and every item

	for(j=0;j<i;j++)
	{
		item[j].item_total=item[j].price*item[j].amount;
	}//total cost for each item
	for(j=0;j<i;j++)
	{
		total+=item[j].item_total;
	}//total cost for all the items
	printf("\nProcessing....");
	Sleep(5000);//timer for five seconds
	printf("\nDate : %s\nTime : %s",__DATE__,__TIME__);//__DATE__ is the macro name for the system date in string format,__TIME__ is the macro name for time in string format
	printf ("\n****************************************BILL**************************************\n_________________________________________________________________________________\nItem\t\t\tQuantity   \t\tPrice\t\t\tAmount");
	for(j=0;j<i;j++)
	{
		printf("\n%.5s...    	        %.2f%s.      	        Rs.%.2f		Rs.%.2f",item[j].name,item[j].amount,item[j].unit,item[j].price,item[j].item_total);	
	}//print the bill on the screen
	printf ("\n*********************************************************************************\nTotal                                                           Rs.%.2f",total);
	fprintf(fp,"Customer Name : %s",cust_name);
	fprintf(fp,"\nDate : %s\nTime : %s",__DATE__,__TIME__);
	fprintf (fp,"\n***************************************BILL**************************************\n_________________________________________________________________________________\nItem\t\t\tQuantity   \t\tPrice\t\t\tAmount");
	for(j=0;j<i;j++)
	{
		fprintf(fp,"\n%.5s...    	        %.2f%s.     	        Rs.%.2f		Rs.%.2f",item[j].name,item[j].amount,item[j].unit,item[j].price,item[j].item_total);	
	}//print the bill on the file for record keeping
	fprintf (fp,"\n*********************************************************************************\nTotal                                                           Rs.%.2f\n",total);
	fprintf(fp1,"Customer Name : %s",cust_name);
	fprintf(fp1,"\nDate : %s\nTime : %s",__DATE__,__TIME__);
	fprintf (fp1,"\n***************************************BILL**************************************\n_________________________________________________________________________________\nItem\t\t\tQuantity   \t\tPrice\t\t\tAmount");
	for(j=0;j<i;j++)
	{
		fprintf(fp1,"\n%.5s...    	        %.2f%s.     	        Rs.%.2f		Rs.%.2f",item[j].name,item[j].amount,item[j].unit,item[j].price,item[j].item_total);	
	}//print the bill in the file for printing on paper
	fprintf (fp1,"\n*********************************************************************************\nTotal                                                           	Rs.%.2f",total);
}
