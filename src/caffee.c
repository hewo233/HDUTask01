#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "caffee.h"

void printMenu()
{
    printf("1. Add goods\n");
    printf("2. Search goods\n");
    printf("3. Delete goods\n");
    printf("4. Modify goods\n");
    printf("5. Add order\n");
    printf("6. Search order\n");
    printf("7. Delete order\n");
    printf("8. Finish order\n");
    printf("9. Print goods\n");
    printf("10. Print order\n");
    printf("11. Sort order\n");
    printf("12. Get sales\n");
    printf("13. Save\n");
    printf("14. Exit\n");
}

void printGoods(tGoods *goods,int goodsNum)
{
    printf("ID\tName\tPrice\tDescription\tType\tQuantity\n");
    for(int i=0;i<goodsNum;i++)
    {
        printf("%d\t%s\t%d\t%s\t%s\t%d\n",goods[i].ID,goods[i].name,goods[i].price,goods[i].description,classify[goods[i].type],goods[i].quantity);
    }
}

int main()
{
    
}