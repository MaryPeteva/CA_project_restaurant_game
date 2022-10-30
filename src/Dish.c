#include "Dish.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*UNFINISHED. FINISH SO IT WORKS*/

/**
 * Used to define a dish within the restaurant OS. Contains menu ID, dish Price, number of ingredients needed,
 * list of ingredient names, the Name of the Dish and a list of ingredient names
 */

/**
 * Creates a new dish with a predefined amount of ingredients.
 * @return A pointer to a dish stored in the memory.
 */

struct dish {
    unsigned int menuID;
    unsigned int numIngredients;
    unsigned int cookingTime;
    float coctailPrice;
    string coctailName;
    string *ingerdientsList;
};

Dish* newDish(void){
    struct dish *tmpDish = (struct dish *) malloc (sizeof (struct dish));
    tmpDish->coctailName = NULL;
    tmpDish->coctailPrice = 0;
    tmpDish->numIngredients = 0;
    tmpDish->cookingTime = 0;
    tmpDish->menuID = 0;

    return tmpDish;
}

void setDish(Dish **coctail, unsigned int id, string name, float price, unsigned int cookingTime, unsigned int ingredientsNumber, string *ingerdientsList)
{
    
    setDishName(coctail, name);
    setDishPrice(coctail, price);
    addToMenu(coctail, id);
    setCookingTime(coctail, cookingTime);
    setNumIngredients(coctail, ingredientsNumber);
    setNeededIngredients(coctail, ingerdientsList);
}

/**
* Sets the name of a newly added Dish.
* @param Dish - the dish that needs to be updated
* @param Name  - the Name for the new dish
*/
void setDishName(Dish **coctail, string Name){
    (*coctail)->coctailName = strdup(Name);
}

/**
 * Sets the Price of the new Dish.
 * @param Dish - the dish that needs to be updated
 * @param Price - the PRice of the new dish
 */
void setDishPrice(Dish **coctail, float Price){
    (*coctail)->coctailPrice = Price;
}

/**
 * Sets the total Number of ingredients needed for the new Dish
 * @param Dish - the dish that needs to be updated
 * @param Ingredients - the total amount of ingredients
 */
void setNumIngredients(Dish **coctail, unsigned int Ingredients){
    (*coctail)->numIngredients = Ingredients;
}

/**
 * Adds a list of ingredients to the dish.
 * @param Dish - the dish that needs to be updated
 * @param Ingredients - the list of ingredients needed
 */
void setNeededIngredients(Dish **coctail, string Ingredients[]){
    int tmpIngredientsCount = (*coctail)->numIngredients;
    (*coctail)->ingerdientsList = (string*) malloc(tmpIngredientsCount * sizeof(string));
    for(int i = 0; i<tmpIngredientsCount; i++){
        (*coctail)->ingerdientsList[i] = strdup(Ingredients[i]);
    }
}

/**
 * Prints the ingredients of a given dish
 * @param Dish - Pointer to the Dish
 */
void printIngredients(Dish* coctail){
    for(unsigned int i = 0; i < coctail->numIngredients; i++){
        fputs("\t", stdout);
        fputs(coctail->ingerdientsList[i], stdout);
        fputs("\n", stdout);
    }
}

/**
 * Sets the cooking time of the Dish
 * @param Dish - the dish that needs to be updated
 * @param Time - the Time needed to cook the dish
 */
void setCookingTime(Dish **coctail, unsigned int Time){
    (*coctail)->cookingTime = Time;
}

/**
 * Links the new Dish to the restaurant menu
 * @param Dish - the dish that needs to be updated
 * @param menuID - the number in the menu for the dish
 */
void addToMenu(Dish **coctail, unsigned int menuID){
    (*coctail)->menuID = menuID;
}

/**
 * Tells how long the Dish needs to be cooked
 * @param Dish - A pointer to a Dish
 * @return Returns the cooking timer
 */
unsigned int getDishTimer(Dish *coctail){
    return coctail->cookingTime;
}

/**
 * Returns the dish name
 * @param Dish - A pointer to a Dish
 * @return Returns the Dish Name
 */
string getDishName(Dish *coctail){
    return coctail->coctailName;
}

/**
 * Returns the Number of ingredients needed for the Dish
 * @param Dish - A pointer to a DIsh
 * @return Returns the total number of ingredients needed
 */
unsigned int getNumberIngredients(Dish *coctail){
    return coctail->numIngredients;
}

/**
 * Returns the Dish Price
 * @param Dish - A pointer tp a Dish
 * @return Returns the Dish Price
 */
float getPrice(Dish *coctail){
    return coctail->coctailPrice;
}

/**
 * Returns the ID from the menu
 * @param Dish - A pointer to a Dish
 * @return Returns the menu number of the Dish as an integer
 */
unsigned int getMenuID(Dish *coctail){
    return coctail->menuID;
}

/**
 * Returns a list of the Dish ingredients
 * @param Dish - A pointer to a Dish
 * @return Returns the ingredients of the Dish
 */
string* getIngredientsList(Dish *coctail){
    return coctail->ingerdientsList;
}

string getCoctailName(Dish *coctail)
{
    return coctail->coctailName;
}

void printMenu(Dish* coctail)
{
    printf("%d. %s %.2flv\n", coctail->menuID, coctail->coctailName, coctail->coctailPrice);
}


void deinitDish(Dish *coctail)
{
    int ingCount = getNumberIngredients(coctail);;

    free(coctail->coctailName);
    
    for (int i = 0; i < ingCount; i++)
    {
        free(coctail->ingerdientsList[i]);
    }

    free(coctail->ingerdientsList);
    free(coctail);
}