#include <stdio.h>
#include <stdlib.h>
#include<errno.h>
#include<windows.h>
typedef struct Items
{
	char name[100],unit[15];
	float price, amount,item_total;
}ite;
void main()
{
	int i,j;
	FILE *fp,*fp1;
	fp1=fopen("D:\\printable_bill.txt","w");
	fp=fopen("D:\\bills.txt","a+");
	if(fp==NULL || fp1==NULL )
	{
		perror("OOPS ERROR");
		printf("\nError no : %d",errno);
		exit(1);
	}
	float total=0;
	ite *item;
	char cust_name[50];
	printf("\nEnter the customer's name : ");
	gets(cust_name);
	printf("How many items have the customer purchased : ");
	scanf("%d",&i);
	fflush(stdin);
	item=(ite *)malloc(i*sizeof(ite));
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
	}

	for(j=0;j<i;j++)
	{
		item[j].item_total=item[j].price*item[j].amount;
	}
	for(j=0;j<i;j++)
	{
		total+=item[j].item_total;
	}
	printf("\nProcessing....");
	Sleep(5000);
	printf("\nDate : %s\nTime : %s",__DATE__,__TIME__);
	printf ("\n****************************************BILL**************************************\n_________________________________________________________________________________\nItem\t\t\tQuantity   \t\tPrice\t\t\tAmount");
	for(j=0;j<i;j++)
	{
		printf("\n%.5s...    	        %.2f%s.      	        Rs.%.2f		Rs.%.2f",item[j].name,item[j].amount,item[j].unit,item[j].price,item[j].item_total);	
	}
	printf ("\n*********************************************************************************\nTotal                                                           Rs.%.2f",total);
	fprintf(fp,"Customer Name : %s",cust_name);
	fprintf(fp,"\nDate : %s\nTime : %s",__DATE__,__TIME__);
	fprintf (fp,"\n***************************************BILL**************************************\n_________________________________________________________________________________\nItem\t\t\tQuantity   \t\tPrice\t\t\tAmount");
	for(j=0;j<i;j++)
	{
		fprintf(fp,"\n%.5s...    	        %.2f%s.     	        Rs.%.2f		Rs.%.2f",item[j].name,item[j].amount,item[j].unit,item[j].price,item[j].item_total);	
	}
	fprintf (fp,"\n*********************************************************************************\nTotal                                                           Rs.%.2f\n",total);
	fprintf(fp1,"Customer Name : %s",cust_name);
	fprintf(fp1,"\nDate : %s\nTime : %s",__DATE__,__TIME__);
	fprintf (fp1,"\n***************************************BILL**************************************\n_________________________________________________________________________________\nItem\t\t\tQuantity   \t\tPrice\t\t\tAmount");
	for(j=0;j<i;j++)
	{
		fprintf(fp1,"\n%.5s...    	        %.2f%s.     	        Rs.%.2f		Rs.%.2f",item[j].name,item[j].amount,item[j].unit,item[j].price,item[j].item_total);	
	}
	fprintf (fp1,"\n*********************************************************************************\nTotal                                                           	Rs.%.2f",total);
}

