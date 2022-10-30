#include "tables.h"

struct table {
    unsigned int tableNumber;
    unsigned int numOrders;
    unsigned int menuIDs;
    bool isTaken;
    bool isOrderReady;
    struct table *next;
    
};

Table* createTable(unsigned int menuId, unsigned int quantity, unsigned int tableNum)
{
    Table *tmpTable = (Table*)malloc(sizeof(struct table));
    tmpTable->tableNumber = tableNum;
    tmpTable->isTaken = true;
    tmpTable->menuIDs = menuId;
    tmpTable->numOrders = quantity;
    tmpTable->next = NULL;
    tableNum++;
    return tmpTable;
}

unsigned int getMenuIdTable(tableQ* tableQueue)
{
    return tableQueue->first->menuIDs;
}

unsigned int getTableIdTable(tableQ* tableQueue)
{
    return tableQueue->first->tableNumber;
}

unsigned int getQuantityTable(tableQ* tableQueue)
{
    return tableQueue->first->numOrders;
}

void dequeueTables(tableQ *tableQueue)
{
    Table *tempNode = NULL;

    if (tableQueue->first == NULL)
    {
        return;
    }

    tempNode = tableQueue->first;
    tableQueue->first = tempNode->next;

    if (tableQueue->first == NULL)
    {
        tableQueue->last = NULL;
    }

    free(tempNode);
}


void enqueueTables( tableQ *tableQueue ,Table* currentTable)
{
    if(tableQueue->last != NULL)
    {
        tableQueue->last->next = currentTable;
    }

    tableQueue->last = currentTable;

    if(tableQueue->first == NULL)
    {
        tableQueue->first = currentTable;
    }
}

tableQ *initTableQueue(void)
{
    tableQ *newQueu = malloc(sizeof(tableQ));
    newQueu->first = NULL;
    newQueu->last = NULL;

    return newQueu;
}
