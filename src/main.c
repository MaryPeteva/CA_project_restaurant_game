#include "defines.h"
#include "restaurant.h"
#include "menu.h"
#include "Dish.h"
#include "Kitchen.h"


int main() {
    
    Menu* MENU = createMenu();
    
    printf("\t MENU:\n");
    
    for (int i = 0; i < MAX_ORDER_ID; i++)
    {
        printMenu(MENU->dishes[i]);
        printIngredients(MENU->dishes[i]);
    }
    
    short business = TRUE;

    while (business){
       business = openForBusiness(MENU);
    }

    for (int i = 0; i < MAX_ORDER_ID; i++)
    {   
        deinitDish(MENU->dishes[i]);
    }

    free(MENU);
    dienitKitchen();

    return EXIT_OK;
}
