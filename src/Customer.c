#include "Customer.h"
#include "defines.h"
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


struct customer {
    unsigned int nr_orders;
    unsigned int menuID;
    struct customer *next;
};

Customer* newCustomer(void) {
    Customer *tmpCustomer = (Customer*) malloc (sizeof(struct customer));
    srand(time(0));
    tmpCustomer->nr_orders = (rand() % MAX_ORDERS) + 1;
    tmpCustomer->menuID = (rand() % MAX_ORDER_ID) + 1;
    tmpCustomer->next = NULL;
    usleep(1000000);
    return tmpCustomer;

}

unsigned int getQuantityCust(custQ *queueCust)
{
    return queueCust->first->nr_orders;
}

unsigned int getMenuIdCust(custQ *queueCust)
{
    return queueCust->first->menuID;
}

void enqueueClients(custQ *custNode, Customer* currentCustomer)
{
   
    if (custNode->last != NULL)
    {
        custNode->last->next = currentCustomer;
    }

    custNode->last = currentCustomer;

    if (custNode->first == NULL)
    {
        custNode->first = currentCustomer;
    }
}

void dequeueCustomers(custQ *queueCust)
{
    Customer *tempNode = NULL;

    if (queueCust->first == NULL)
    {

        return;
    }

    tempNode = queueCust->first;
    queueCust->first = tempNode->next;
    if (queueCust->first == NULL)
    {
        queueCust->last = NULL;
    }
    
    free(tempNode);
}

custQ *initQueue(void)
{
    custQ *newQueu = malloc(sizeof(custQ));
    newQueu->first = NULL;
    newQueu->last = NULL;

    return newQueu;
}
