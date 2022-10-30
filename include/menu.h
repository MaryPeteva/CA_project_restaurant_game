#ifndef GROUP_TASK1_MENU_H
#define GROUP_TASK1_MENU_H

#include "Dish.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu
{
    Dish *dishes[MAX_ORDER_ID];
};
typedef struct menu Menu;

Menu* createMenu();

#endif //GROUP_TASK1_MENU_H
