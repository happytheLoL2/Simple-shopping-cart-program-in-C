#include <stdio.h>
#include <string.h>

/*Author: Megyesi Antonia
  Date: 2025.08.24
  Project: Simple shopping cart
*/

int main(){
    char items[10][50];
    float prices[10];
    int numberOfItems[10];
    int welcomeItem;
    float total = 0;

    printf("Welcome to our shopping centre. How many items would you like to buy today?\n");
    scanf("%d", &welcomeItem);

    if (welcomeItem > 10) {
        welcomeItem = 10;
        printf("Sorry, max 10 items allowed!\n");
    }
    
    int i;
    for(i = 0; i < welcomeItem; i++){
        getchar(); 

        printf("\nWhat item would you like?\n");
        fgets(items[i], sizeof(items[i]), stdin);
        items[i][strcspn(items[i], "\n")] = 0; 

        printf("What's the price of the item?\n");
        scanf("%f", &prices[i]);

        printf("How many would you like to buy?\n");
        scanf("%d", &numberOfItems[i]);

        total += prices[i] * numberOfItems[i];
    }

    printf("\n--- Your Cart ---\n");
    printf("Item           Price   Qty   Subtotal\n");
    for( i = 0; i < welcomeItem; i++){
        printf("%-13s %.2f   %d     %.2f\n",
               items[i], prices[i], numberOfItems[i],
               prices[i] * numberOfItems[i]);
    }
    printf("-------------------------------\n");
    printf("TOTAL: %.2f €\n", total);

    return 0;
}

