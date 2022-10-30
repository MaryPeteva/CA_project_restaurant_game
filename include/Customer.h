#ifndef GROUP_TASK_RESTAURANT_CUSTOMER_H
#define GROUP_TASK_RESTAURANT_CUSTOMER_H

#include "defines.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct customer Customer;

Customer* newCustomer(void);

typedef struct
{
    Customer *first;
    Customer *last;
} custQ;

void enqueueClients(custQ *custQueue, Customer* currentCustomer);
unsigned int getTableNumCust(Customer *currentCustomer);
unsigned int getMenuIdCust(custQ *queueCust);
unsigned int getQuantityCust(custQ *queueCust);
void dequeueCustomers(custQ *queueCust);
custQ *initQueue(void);

#endif //GROUP_TASK_RESTAURANT_CUSTOMER_H
