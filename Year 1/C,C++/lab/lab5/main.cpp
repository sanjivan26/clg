#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main() {
    DLList list;
    int ID = 0, val, opt = 1;
    while (opt != 0) {
        printf("Enter your option\n\t1 - New Webpage\n\t2 - Go Back\n\t3 - Go Front\n\t4 - Exit\n\t5 - Display\n>>>");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            printf("Inserting New Web Page : ");
            printf(">>%d", list.NewWebPage());
            ID++;
            break;
        case 2:
            printf("Go Back");
            val = list.Go_Prev();
            if (val != -1) {
                printf("Moved back > Current page : %d", val);
            } else {
                printf("Cannot go back in history");
            }
            break;
        case 3:
            printf("Go Front");
            val = list.Go_Next();
            if (val != -1) {
                printf("Moved front > Current page : %d", val);
            } else {
                printf("Cannot go front in history");
            }
            break;
        case 4:
            return 0;
        case 5:
            printf("Displaying List = > ");
            list.Display();
            printf("\n");
            break;
        default:
            break;
        }
        printf("\n\n(Press ENTER key to continue)");
        getchar();
        getchar();
    }
    return 0;
}
