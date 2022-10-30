#ifndef GROUP_TASK1_DISH_H
#define GROUP_TASK1_DISH_H

#include "defines.h"

typedef struct dish Dish;

Dish* newDish(void);
void setDish(Dish **dish, unsigned int id, string name, float price, unsigned int cookingTime, unsigned int ingredientsNumber, string *ingerdientsList);
void setDishName(Dish **Dish, string Name);
void setDishPrice(Dish **Dish, float Price);
void setNumIngredients(Dish **Dish, unsigned int Ingredients);
void setNeededIngredients(Dish **Dish, string Ingredients[]);
void setCookingTime(Dish **Dish, unsigned int Time);
void addToMenu(Dish **Dish, unsigned int menuID);

void printIngredients(Dish* Dish);
void printMenu(Dish* coctail);

void deinitDish(Dish *coctail);

unsigned int getDishTimer(Dish *Dish);
string getDishName(Dish *Dish);
unsigned int getNumberIngredients(Dish *Dish);
float getPrice(Dish *Dish);
unsigned int getMenuID(Dish *Dish);
string* getIngredientsList(Dish *Dish);
string getCoctailName(Dish *coctail);

#endif //GROUP_TASK1_DISH_H
