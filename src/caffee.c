#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "caffee.h"

tGoods *goods;
tOrder *order;
int goodsNum, orderNum;

void init()
{
    goods = (tGoods *)malloc(sizeof(tGoods)*100);
    order = (tOrder *)malloc(sizeof(tOrder)*100);
    goodsNum = orderNum = 0;
}

void printMenu() 
{
    time_t start, end;

    while (1) 
    {
        int choice;
        printf("\n1. 打印商品\n2. 添加商品\n3. 搜索商品\n4. 删除商品\n5. 修改商品\n6. 搜索订单\n7. 排序订单\n8. 打印订单\n9. 添加订单\n10. 删除订单\n11. 完成订单\n12. 保存\n13. 获取销售\n14. 退出\n");
        printf("请输入你的选择：");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printGoods(goods, goodsNum);
                break;
            case 2:
                addGoods(goods, &goodsNum);
                break;
            case 3:
                serachGoods(goods, goodsNum, 1);
                break;
            case 4:
                deleteGoods(goods, &goodsNum);
                break;
            case 5:
                modifyGoods(goods, goodsNum);
                break;
            case 6:
                searchOrder(order, orderNum, 1);
                break;
            case 7:
                sortOrder(order, orderNum);
                break;
            case 8:
                printOrder(order, orderNum);
                break;
            case 9:
                addOrder(order, &orderNum, goods, goodsNum);
                break;
            case 10:
                deleteOrder(order, &orderNum);
                break;
            case 11:
                finishOrder(order, orderNum, goods, goodsNum);
                break;
            case 12:
                save();
                break;
            case 13:
                printf("请输入开始和结束时间：");
                scanf("%ld %ld", &start, &end);
                getSales(order, orderNum, goods, goodsNum, start, end);
                break;
            case 14:
                return;
            default:
                printf("无效的选择，请重新输入。\n");
        }
    }
}

void printGoods(tGoods *goods,int goodsNum)
{
    printf("编号\t名字\t价格\t描述\t类型\t库存\n");
    for(int i=0;i<goodsNum;i++)
    {
        if(goods[i].available == 0) continue;
        printf("%d\t%s\t%d\t%s\t%s\t%d\n",goods[i].ID,goods[i].name,goods[i].price,goods[i].description,classify[goods[i].type],goods[i].quantity);
    }
}

void addGoods(tGoods *goods,int *goodsNum)
{
    printf("请输入商品名字：");
    scanf("%s",goods[*goodsNum].name);
    printf("请输入商品价格：");
    scanf("%d",&goods[*goodsNum].price);
    printf("请输入商品描述：");
    scanf("%s",goods[*goodsNum].description);
    printf("请输入商品类型：");
    scanf("%d",&goods[*goodsNum].type);
    printf("请输入商品库存：");
    scanf("%d",&goods[*goodsNum].quantity);
    goods[*goodsNum].available = 1;
    goods[*goodsNum].ID = *goodsNum;
    (*goodsNum)++;
}

int searchGoods(tGoods *goods, int goodsNum, int printFlag)
{
    printf("请选择搜索方式：1.编号 2.名字\n");
    int choice;
    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("请输入商品编号：");
        int id;
        scanf("%d", &id);
        for(int i=0;i<goodsNum;i++)
        {
            if(goods[i].ID == id && goods[i].available == 1)
            {
                if(printFlag)
                {
                    printf("编号\t名字\t价格\t描述\t类型\t库存\n");
                    printf("%d\t%s\t%d\t%s\t%s\t%d\n",goods[i].ID,goods[i].name,goods[i].price,goods[i].description,classify[goods[i].type],goods[i].quantity);
                }
                return i;
            }
        }
    }
    else if(choice == 2)
    {
        printf("请输入商品名字：");
        char name[50];
        scanf("%s", name);
        for(int i=0;i<goodsNum;i++)
        {
            if(strcmp(goods[i].name, name) == 0 && goods[i].available == 1)
            {
                if(printFlag)
                {
                    printf("编号\t名字\t价格\t描述\t类型\t库存\n");
                    printf("%d\t%s\t%d\t%s\t%s\t%d\n",goods[i].ID,goods[i].name,goods[i].price,goods[i].description,classify[goods[i].type],goods[i].quantity);
                }
                return i;
            }
        }
    }
    if(printFlag)
        printf("商品不存在\n");
    return -1;
}

void deleteGoods(tGoods *goods, int *goodsNum)
{
    int id = serachGoods(goods, *goodsNum, 0);
    if(id == -1)
    {
        printf("商品不存在\n");
        return;
    }
    goods[id].available = 0;
}

void modifyGoods(tGoods *goods, int goodsNum)
{
    int id = serachGoods(goods, goodsNum, 0);
    if(id == -1)
    {
        printf("商品不存在\n");
        return;
    }
    printf("请输入商品名字：");
    scanf("%s",goods[id].name);
    printf("请输入商品价格：");
    scanf("%d",&goods[id].price);
    printf("请输入商品描述：");
    scanf("%s",goods[id].description);
    printf("请输入商品类型：");
    scanf("%d",&goods[id].type);
    printf("请输入商品库存：");
    scanf("%d",&goods[id].quantity);
}

int searchOrder(tOrder *order, int orderNum, int printFlag)
{
    return -1;
}

void sortOrder(tOrder *order, int orderNum)
{
    return;
}

void printOrder(tOrder *order, int orderNum)
{
    return;
}

void addOrder(tOrder *order, int *orderNum, tGoods *goods, int goodsNum)
{
    return;
}

void deleteOrder(tOrder *order, int *orderNum)
{
    return;
}

void finishOrder(tOrder *order, int orderNum, tGoods *goods, int goodsNum)
{
    return;
}

void save()
{
    return;
}

int getSales(tOrder *order, int orderNum, tGoods *goods, int goodsNum, time_t start, time_t end)
{
    return 0;
}

int main()
{
    init();
    printMenu();
}