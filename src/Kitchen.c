#include "Kitchen.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define MAX_DISH_COUNT 6
struct cook {
    unsigned int maxDishes;
    unsigned int dishCounter;
    bool isCooking;
    string ChefName;
    Dish** DishesCooked;
};

static struct cook *chef = NULL;

void hireChef(char *Name) {
    srand(time(0));
    if (chef == NULL){
        chef = (Chef*) malloc(sizeof(struct cook));
        chef->isCooking = FALSE;
        chef->maxDishes = rand() % MAX_DISH_COUNT + 1;
        chef->dishCounter = 0;
        chef->ChefName = strdup(Name);

        chef->DishesCooked = (Dish**)malloc(sizeof(Dish*) * chef->maxDishes);
        for( unsigned int i = 0; i < chef->maxDishes; i++){
            chef->DishesCooked[i] = (Dish*) malloc (sizeof(Dish*));
        }
    }
}


unsigned int maxDishes(void)
{
    return chef->maxDishes; 
}

Chef* callChef(void){
    return chef;
}

// int cookingTimer(void){
//     int tmpTime = 0;
//     Dish* tmpDish = NULL;

//     for(int i = 0; i<chef->dishCounter; i++){
//         if(getDishTimer(chef->DishesCooked[i])==0){
//             chef->DishesCooked[i] = NULL;
//             return TRUE;
//         }
//         else {
//             tmpDish = chef->DishesCooked[i];
//             tmpTime = getDishTimer(tmpDish);
//             tmpTime--;
//             setCookingTime(&tmpDish, tmpTime);
//         }
//     }

//     return FALSE;
// }

order* createOrder(unsigned int menuId, unsigned int quantity, unsigned int tableNum)
{
    order* tmpOrder = (order*)malloc(sizeof(order));
    tmpOrder->menuID = menuId;
    tmpOrder->tableID = tableNum;
    tmpOrder->quantity = quantity;
    tmpOrder->isOrderReadyKitchen = true;
    tmpOrder->next = NULL;
    printf("Order for table %d is taken\n\n", tmpOrder->tableID);
    return tmpOrder;
}

void enqueueOrders(ordersQueue *queueNode, order* tmpOrder)
{
    if (queueNode->last != NULL)
    {
        queueNode->last->next = tmpOrder;
    }

    queueNode->last = tmpOrder;

    if (queueNode->first == NULL)
    {
        queueNode->first = tmpOrder;
    }
}

void dequeueOrders(ordersQueue *queueNode)
{
    printf("Your order is ready.\n");
    printf("See you next time!\n\n");

    order *tempNode = NULL;

    if (queueNode->first == NULL)
    {
        return;
    }

    tempNode = queueNode->first;
    queueNode->first = tempNode->next;

    if (queueNode->first == NULL)
    {
        queueNode->last = NULL;
    }

    free(tempNode);
}

ordersQueue *initQueueOrdres(void)
{
    ordersQueue *newQueu = malloc(sizeof(ordersQueue));
    newQueu->first = NULL;
    newQueu->last = NULL;

    return newQueu;
}

void dienitKitchen(void)
{
    for (unsigned int i = 0; i < chef->maxDishes; i++)
    {
        free(chef->DishesCooked[i]);
    }

    free(chef->DishesCooked);
    free(chef->ChefName);
    free(chef);
    chef = NULL;
}
