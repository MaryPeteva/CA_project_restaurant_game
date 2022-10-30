#ifndef GROUP_TASK1_KITCHEN_H
#define GROUP_TASK1_KITCHEN_H

#include "defines.h"
#include "Dish.h"
#include <stdbool.h>

typedef struct cook Chef;

typedef struct order
{ 
    int tableID;
    int menuID;
    int quantity;
    bool isOrderReadyKitchen;
    struct order *next;
} order;

typedef struct ordersQueue
{
    order *first;
    order *last;
} ordersQueue;

void hireChef(char *Name);
Chef* callChef(void);
//int cookingTimer(void);
unsigned int maxDishes(void);
order* createOrder(unsigned int menuId, unsigned int quantity, unsigned int tableNum);
void enqueueOrders(ordersQueue *queueOrders, order* tmpOrder);
void dequeueOrders(ordersQueue *queueOrders);
ordersQueue *initQueueOrdres(void);

void dienitKitchen(void);

#endif //GROUP_TASK1_KITCHEN_H
