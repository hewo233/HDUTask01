#include <string.h>
#include <time.h>

const char classify[5][10] = {"coffee", "tea", "juice", "milk", "other"};

typedef struct {
    int ID;
    char name[50];
    int price;
    char description[100];
    int type;
    int quantity;
    int available;
} tGoods;

typedef struct {
    int ID;
    char customerName[50];
    time_t ordertime;
    int status;
    int goodsNum[100]; // goodsNum[goodsID] is num
} tOrder;

void printGoods(tGoods *goods,int goodsNum);
void addGoods(tGoods *goods,int *goodsNum);

int searchGoods(tGoods *goods,int goodsNum,int printFlag);
void deleteGoods(tGoods *goods,int *goodsNum);
void modifyGoods(tGoods *goods,int goodsNum);

int searchOrder(tOrder *order,int orderNum,int printFlag);
void sortOrder(tOrder *order,int orderNum);

void printOrder(tOrder *order,int orderNum);
void addOrder(tOrder *orderm,int *orderNum,tGoods *goods,int goodsNum);
void deleteOrder(tOrder *order,int *orderNum);
void finishOrder(tOrder *order,int orderNum,tGoods *goods,int goodsNum);

void printMenu();

void save();

int getSales(tOrder *order,int orderNum,tGoods *goods,int goodsNum,time_t start,time_t end);



