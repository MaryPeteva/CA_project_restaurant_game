#ifndef GROUP_TASK1_TABLES_H
#define GROUP_TASK1_TABLES_H


#define MAX_TABLES 8
#define MAX_ORDERS_TABLE 2

#include "defines.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct table Table;

typedef struct tableQ
{
    Table *first;
    Table *last;
}tableQ;

Table* createTable(unsigned int menuId, unsigned int quantity, unsigned int tableNum);
tableQ *initTableQueue(void);
unsigned int getMenuIdTable(tableQ* tableQueue);
unsigned int getQuantityTable(tableQ* tableQueue);
unsigned int getTableIdTable(tableQ* tableQueue);
void enqueueTables( tableQ *tableQueue ,Table* currentTable);
void dequeueTables(tableQ *tableQueue);

#endif //GROUP_TASK1_TABLES_H
