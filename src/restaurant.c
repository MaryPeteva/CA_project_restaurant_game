#include "restaurant.h"
#include "defines.h"
#include "tables.h"
#include "Customer.h"
#include "Kitchen.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
 
short openForBusiness(Menu* MENU)
{ 
    static unsigned int i = 0;
    
    char name[] = "SpiriT_Don";
    hireChef(name);
    
    srand(time(NULL));   
 
    char *coctailName = NULL;
    unsigned int j = 0;
    unsigned int menuId = 0;
    static int tableNum = 1;
    unsigned int cookMaxDish = maxDishes();
    unsigned int quantity = 0;
    unsigned int numClients = rand()% (MAX_CUSTOMERS) + 1;
    unsigned int tmpTableNum = 0;
    unsigned int requiredTables = 0;
    unsigned int quantityCount = 0;
    Customer* tmpClient;
    custQ* queueCust = initQueue();
    unsigned int clientsCount = numClients;
    tableQ* queueTables = initTableQueue();
    ordersQueue* queueOrders = initQueueOrdres();
    Table* tmpTable = NULL;
    order* tmpOrder = NULL;
 
    for( ; i < MAX_ROUNDS;)
    {
        //Chef* currentChef = callChef();
        printf("\n\tDay %d -- Welcome to BRUM BAR! Enjoy your drinks!\n\n", i + 1);
        printf("\tMAY THE COCTAILS BE WITH YOU!\n");
        for ( j = 0; j < numClients; j++)
        {
            // get the clients in line
            tmpClient = newCustomer();            
            enqueueClients(queueCust, tmpClient);            
        }
        
        while (queueCust->first != NULL)
        {
            
            if(clientsCount > MAX_TABLES)
            {
                requiredTables = MAX_TABLES;
            }
            else
            {
                requiredTables = clientsCount;
            }
 
            for (unsigned int  i = 0; i < requiredTables; i++)
            {
                //get the clients seated
                menuId = getMenuIdCust(queueCust);
                quantity = getQuantityCust(queueCust);
                coctailName = getCoctailName(MENU->dishes[menuId - 1]);
 
                printf("Customer sat on table %d, ordered %s - %d times\n\n", tableNum, coctailName, quantity);
 
                tmpTable = createTable(menuId, quantity, tableNum);
                //take customer  to  a table and take him off of the line
                enqueueTables(queueTables,tmpTable);
                dequeueCustomers(queueCust);
                tableNum++;
                clientsCount--;
            }
 
            tableNum = 1;
 
            unsigned int tablesCount = requiredTables;
            
            while (queueTables->first != NULL)
            {
                unsigned int requiredOrders = 0;
                if(tablesCount > cookMaxDish)
                {
                    requiredOrders = cookMaxDish;
                }
                else
                {
                    requiredOrders = tablesCount;
                }
 
                for (unsigned int i = 0; i < requiredOrders; i++)
                {
                    menuId = getMenuIdTable(queueTables);
                    quantity = getQuantityTable(queueTables);
                    tmpTableNum = getTableIdTable(queueTables);

                    for (unsigned int i = 0; i < quantity; i++)
                    {
                        quantityCount++;
                        tmpOrder = createOrder(menuId, 1, tmpTableNum);
                        //send order to the kitchen and take it off of the tables
                        enqueueOrders(queueOrders, tmpOrder);
                    }
                 
                    dequeueTables(queueTables);
                    tablesCount--;
                }
 
                for (unsigned int i = 0; i < quantityCount; i++)
                {
                    dequeueOrders(queueOrders);
                    // has to be  inn a different loop than enqueue
                }

                quantityCount = 0;
            }            
        }
        
        usleep(100000);
        i++;
        printf("\tCheers, come again tomorrow!\n");
 
        if(tableNum >= 8)
        {
            tableNum = 1;
        }
        
        free(queueCust);
        free(queueTables);
        free(queueOrders);
 
        return TRUE;
    }
   
    free(queueCust);
    free(queueTables);
    free(queueOrders);
    return FALSE;
}