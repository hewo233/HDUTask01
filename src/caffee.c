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
                searchGoods(goods, goodsNum, 1);
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
    int id = searchGoods(goods, *goodsNum, 0);
    if(id == -1)
    {
        printf("商品不存在\n");
        return;
    }
    goods[id].available = 0;
}

void modifyGoods(tGoods *goods, int goodsNum)
{
    int id = searchGoods(goods, goodsNum, 0);
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
    void sortOrder(tOrder *order, int orderNum);

    printf("请选择搜索方式：1.订单号 2.顾客名字\n");
    int choice;
    scanf("%d", &choice);
    if(choice == 1)
    {
        printf("请输入订单号：");
        int id;
        scanf("%d", &id);
        for(int i=0;i<orderNum;i++)
        {
            if(order[i].ID == id)
            {
                if(printFlag)
                {
                    struct tm *date = localtime(&order[i].ordertime);
                    char buffer[80];
                    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", date);
                    printf("订单号：%d\n顾客名字：%s\n订单状态：%d\n订单时间：%s\n购买商品为：\n",order[i].ID,order[i].customerName,order[i].status,buffer);
                    for(int j=0;j<goodsNum;j++)
                    {
                        if(order[i].goodsNum[j] > 0)
                        {
                            printf("ID : %d Num :%d\n",i,order[i].goodsNum[j]);
                        }
                    }
                }
                return i;
            }
        }
    }
    else if(choice == 2)
    {
        printf("请输入顾客名字：");
        char name[50];
        scanf("%s", name);
        for(int i=0;i<orderNum;i++)
        {
            if(strcmp(order[i].customerName, name) == 0 )
            {
                if(printFlag)
                {
                    struct tm *date = localtime(&order[i].ordertime);
                    char buffer[80];
                    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", date);
                    printf("订单号：%d\n顾客名字：%s\n订单状态：%d\n订单时间：%s\n购买商品为：\n",order[i].ID,order[i].customerName,order[i].status,buffer);
                    for(int j=0;j<goodsNum;j++)
                    {
                        if(order[i].goodsNum[j] > 0)
                        {
                            printf("ID : %d Num :%d\n",i,order[i].goodsNum[j]);
                        }
                    }
                }
                return i;
            }
        }
    }
    if(printFlag)
        printf("订单不存在\n");

    return -1;
}

void sortOrder(tOrder *order, int orderNum)
{
    int i, j;
    tOrder temp;

    for (i = 0; i < orderNum - 1; i++) 
    {
        for (j = 0; j < orderNum - i - 1; j++) 
        {
            if (order[j].ID > order[j + 1].ID) 
            {
                // 交换顺序
                temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }    
    return;
}

void printOrder(tOrder *order, int orderNum)
{
    void sortOrder(tOrder *order, int orderNum);

    for(int i=0;i<orderNum;i++)
    {
        struct tm *date = localtime(&order[i].ordertime);
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", date);
        printf("订单号：%d\n顾客名字：%s\n订单状态：%d\n订单时间：%s\n购买商品为：\n",order[i].ID,order[i].customerName,order[i].status,buffer);
        for(int j=0;j<goodsNum;j++)
        {
            if(order[i].goodsNum[j] > 0)
            {
                printf("ID : %d Num :%d\n",i,order[i].goodsNum[j]);
            }
        }        
    }
    
    return;
}

void addOrder(tOrder *order, int *orderNum, tGoods *goods, int goodsNum)
{
    void sortOrder(tOrder *order, int orderNum);

    printf("该订单订单号为：%d\n",orderNum);
    printf("请输入顾客名字：\n");
    scanf("%s",order[*orderNum].customerName);

    printf("请输入购买商品种类的个数\n");
    int num=0;
    scanf("%d",&num);

    for(int i=0;i<num;i++)
    {
        int goodsID=0,goodsNum=0;
        printf("请输入商品编号\n");
        scanf("%d",&goodsID);
        printf("请输入购买该商品的数量\n");
        scanf("%d",&goodsNum);
        order[*orderNum].goodsNum[goodsID]=goodsNum;

    }

    order[*orderNum].ordertime=time(NULL);
    order[*orderNum].status = 1;
    order[*orderNum].ID = *orderNum;
    (*orderNum)++;
    return;
}

void deleteOrder(tOrder *order, int *orderNum)
{
    void sortOrder(tOrder *order, int orderNum);

    printf("请输入订单号\n");
    int num=0;
    scanf("%d",&num);

    if (order[num].status==1||order[num].status==2)
    {
        order[num].status=3;
        printf("操作成功\n");
    }
    else if (order[num].status==3)
    {
        printf("订单原已删除\n");
    }
    else printf("订单不存在\n");

    return;
}

void finishOrder(tOrder *order, int orderNum, tGoods *goods, int goodsNum)
{
    void sortOrder(tOrder *order, int orderNum);

    printf("请输入订单号\n");
    int num=0;
    scanf("%d",&num);

    if (order[num].status==1||order[num].status==3)
    {
        order[num].status=2;

        for(int j=0;j<goodsNum;j++)
        {
            if(order[num].goodsNum[j] > 0)
            {
                goods[j].quantity=goods[j].quantity-order[num].goodsNum[j];
            }
        }        
        printf("操作成功\n");
    }
    else if (order[num].status==2)
    {
        printf("订单原已完成\n");
    }
    else printf("订单不存在\n");

    return;
}

void save()
{
    void sortOrder(tOrder *order, int orderNum);

    return;
}

int getSales(tOrder *order, int orderNum, tGoods *goods, int goodsNum, time_t start, time_t end)
{
    void sortOrder(tOrder *order, int orderNum);

    int year1=0, year2=0;
    int month1=0, month2=0;
    int day1=0, day2=0;
    printf("请输入起始时间（年 月 日）：\n");
    scanf("%d %d %d\n",&year1,&month1,&day1);
    printf("请输入结束时间（年 月 日）：\n");
    scanf("%d %d %d\n",&year2,&month2,&day2);

    struct tm date1 = {0};
    date1.tm_year = year1 - 1900; // tm_year表示的是从1900年开始的年数
    date1.tm_mon = month1 - 1;    // tm_mon表示的是0-11的月份
    date1.tm_mday = day1;
    time_t time1 = mktime(&date1);
    struct tm date2 = {0};
    date2.tm_year = year2 - 1900; // tm_year表示的是从1900年开始的年数
    date2.tm_mon = month2 - 1;    // tm_mon表示的是0-11的月份
    date2.tm_mday = day2;
    time_t time2 = mktime(&date2);
    printf("Converted time_t: %ld\n", time1);
    printf("Converted time_t: %ld\n", time2);

    int sales=0;
    int salesList[100]={"0"};

    for(int i=0;i<orderNum;i++)
    {
        if(order[i].ordertime>time1&&order[i].ordertime<time2&&order[i].status==2)
        {
            for(int j=0;j<goodsNum;j++)
            {
                if(order[i].goodsNum[j] > 0)
                {
                    sales=sales+goods[j].price*order[i].goodsNum[j];
                    salesList[j]=salesList[j]+order[i].goodsNum[j];

                }
            }
                return i;
        }
    }

    printf("总销额为：%d元\n销售清单如下\n",sales);
    for(int i=0;i<goodsNum;i++)
    {
        if(salesList[i]>0)
        {
            printf("商品编号：%d\t商品名字：%s\t商品单价：%d\t销售数量：&d\t总销售额：%d\n",goods[i].ID,goods[i].name,goods[i].price,salesList[i],goods[i].price*salesList[i]);
        }
    }

    return 0;
}

int main()
{
    init();
    printMenu();
}