
#include "menu.h"

Menu* createMenu()
{
    Menu *menu = (Menu *)malloc(sizeof(Menu));

    Dish *first = newDish();
    string ingr1[MAX_INGREDIENTS];
    ingr1[0] = "vodka";
    ingr1[1] = "tomato juice";
    ingr1[2] = "lemon juice";
    setDish(&first, 1, "Bloody Mary", 7.50, 4, 3, ingr1);
    menu->dishes[0] = first;

    Dish *second = newDish();
    string ingr2[MAX_INGREDIENTS];
    ingr2[0] = "gin";
    ingr2[1] = "dry matrini";
    setDish(&second, 2, "Martini dry", 7.70, 3, 2, ingr2);
    menu->dishes[1] = second;

    Dish *third = newDish();
    string ingr3[MAX_INGREDIENTS];
    ingr3[0] = "rum";
    ingr3[1] = "lime";
    ingr3[2] = "brown sugar";
    ingr3[3] = "soda";
    setDish(&third, 3, "Mojito", 7.90, 6, 4, ingr3);
    menu->dishes[2] = third;

    Dish *fourth = newDish();
    string ingr4[MAX_INGREDIENTS];
    ingr4[0] = "vodka";
    ingr4[1] = "cointreau";
    ingr4[2] = "lime";
    ingr4[3] = "bluberry juice";
    setDish(&fourth, 4, "Cosmopolitan", 7.80, 6, 4, ingr4);
    menu->dishes[3] = fourth;

    Dish *fifth = newDish();
    string ingr5[MAX_INGREDIENTS];
    ingr5[0] = "canadian whiskey";
    ingr5[1] = "martini rosso";
    ingr5[2] = "angustura";
    setDish(&fifth, 5, "Manhattan", 7.80, 4, 3, ingr5);
    menu->dishes[4] = fifth;

    Dish *sixth = newDish();
    string ingr6[MAX_INGREDIENTS];
    ingr6[0] = "vodka";
    ingr6[1] = "melon liqueur";
    ingr6[2] = "peach liqueur";
    setDish(&sixth, 6, "Sex on the beach", 7.60, 4, 3, ingr6);
    menu->dishes[5] = sixth;

    Dish *seventh = newDish();
    string ingr7[MAX_INGREDIENTS];
    ingr7[0] = "rum";
    ingr7[1] = "lime";
    ingr7[2] = "sugar syrup";
    setDish(&seventh, 7, "Daiquiri", 7.30, 3, 3, ingr7);
    menu->dishes[6] = seventh;

    Dish *eight = newDish();
    string ingr8[MAX_INGREDIENTS];
    ingr8[0] = "vodka";
    ingr8[1] = "lemon juice";
    ingr8[2] = "coconut liquor";
    ingr8[3] = "melon liquor";
    ingr8[4] = "pineapple liquor";
    setDish(&eight, 8, "Cuba Libre", 7.40, 5, 5, ingr8);
    menu->dishes[7] = eight;

    Dish *nineth = newDish();
    string ingr9[MAX_INGREDIENTS];
    ingr9[0] = "vodka";
    ingr9[1] = "khaula";
    ingr9[2] = "cream";
    setDish(&nineth, 9, "White Russian", 8.50, 4, 3, ingr9);
    menu->dishes[8] = nineth;

    Dish *tenth = newDish();
    string ingr10[MAX_INGREDIENTS];
    ingr10[0] = "tequilla";
    ingr10[1] = "cointreau";
    ingr10[2] = "lime";
    setDish(&tenth, 10, "Margarita", 8.20, 4, 3, ingr10);
    menu->dishes[9] = tenth;

    Dish *eleventh = newDish();
    string ingr11[MAX_INGREDIENTS];
    ingr11[0] = "dark rum";
    ingr11[1] = "pineapple juice";
    ingr11[2] = "orange";
    ingr11[3] = "lime";
    ingr11[4] = "marakuja";
    setDish(&eleventh, 11, "Hurricane", 8.90, 5, 5, ingr11);
    menu->dishes[10] = eleventh;

    Dish *twelfth = newDish();
    string ingr12[MAX_INGREDIENTS];
    ingr12[0] = "vodka";
    ingr12[1] = "gin";
    ingr12[2] = "tequila";
    ingr12[3] = "rum";
    ingr12[4] = "triple sec";
    ingr12[5] = "lemon juice";
    setDish(&twelfth, 12, "Long Island Ice Tea", 9.50, 7, 6, ingr12);
    menu->dishes[11] = twelfth;
    return menu;
}
