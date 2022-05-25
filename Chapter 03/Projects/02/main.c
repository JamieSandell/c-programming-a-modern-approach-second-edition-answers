/*
Write a program that formats product information entered by the user. A session with the
program should look like this:

Enter item number: 583
Enter unit price: 13.5
Enter purchase date (mm/dd/yyyy): 10/24/2010

Item            Unit            Purchase
                Price           Date
583             $   13.50       10/24/2010


The item number and date should be left justified: the unit price should be right justified.
Allow dollar amounts up to $9999.99. Hint: Use tabs to line up the columns.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int item_number;
    float unit_price;
    int purchase_date_day;
    int purchase_date_month;
    int purchase_date_year;

    printf("Enter item number: ");
    scanf("%d", &item_number);
    printf("Enter unit price: ");
    scanf("%7f", &unit_price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &purchase_date_month, &purchase_date_day, &purchase_date_year);
    printf("\nItem\t\t\tUnit\t\t\tPurchase\n");
    printf("\t\t\t\tPrice\t\t\tDate\n");
    printf("%-3d\t\t\t$%4.2f\t\t\t%-3d/%-3d/%-3d\n", item_number, unit_price, purchase_date_month, purchase_date_day, purchase_date_year);

    return EXIT_SUCCESS;
}