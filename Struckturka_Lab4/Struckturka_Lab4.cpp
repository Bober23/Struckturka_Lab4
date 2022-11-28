//лаба3
//задача 1: хранение строки в виде односвязного списка
//задача 2: хранение в двухсвязном списке
//посчитать слова, пробелы убрать, добавить символ g на 6 позицию

//лаба4
//создать программу по выполнению всех операций над односвязным списком
//программа должна работать в диалоговом режиме с меню
//после выполнения любого действия на экране должно появляться адекватное сообщение
//после каждого действия должен распечатываться список с указанием местанахождения текущего указателя
//в конце работы список очищается
//каждая операция должна быть реализована в виде отдельной функции
//операции над односвязным списком: начало работы, очистить список, проверить пустоту списка,
//установить указатель в начало, проверка, находится ли указатель в конце, передвинуть указатель вперед
//показать следующее значение элемента списка, удалить элемент списка за указателем, взять элемент за указателем, изменить значение за ук.,
//добавить элемент за указателем, распечататьь список, закончить работу

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct listElement
{
    char value;
    listElement* nextElement = NULL;
};
struct listCollection {
    listElement* head;
    listElement* current;
};


void PrintList(listCollection collection) {
    listElement* node = collection.head;
    while (1) {
        printf("%c", node->value);
        if (node == collection.current)
            printf("*");
        node = node->nextElement;
        if (node == NULL) {
            printf("\n");
            break;
        }
    }
}
void DeleteNext(listCollection* list) {
    if (list->current->nextElement->nextElement != 0) {
        listElement* badNode = list->current->nextElement;
        list->current->nextElement = list->current->nextElement->nextElement;
        free(badNode);
    }
    else list->current->nextElement = NULL;
}
void DeleteAll(listCollection* list) {
    listElement* node = list->head;
    listElement* badElement = node;
    while (node->nextElement != NULL)
    {
        badElement = node;
        node = node->nextElement;
        free(badElement);
    }
    list->head = NULL;
    list->current = NULL;
}
listCollection StartWork() {
    listCollection list;
    list.current = NULL;
    list.head = NULL;
    return list;

}
int CheckEmpty(listCollection* list) {
    if (list->head == NULL) {
        printf("List is empty\n");
        return 1;
    }
    else {
        printf("List is not empty\n");
        return 0;
    }
}
void CheckPointerOnEnd(listCollection* list){
    if (list->current->nextElement == NULL) {
        printf("YES\n");
    }
    else printf("NO\n");
}
void MovePointerToStart(listCollection* list) {
    list->current = list->head;
}
void AddElement(listCollection* collection, char data) {
    struct listElement* current;
    current = (struct listElement*)malloc(sizeof(struct listElement));
    if (current == NULL) { printf("Error, NULL\n"); exit(1); }
    current->value = data;
    current->nextElement = NULL;
    if (collection->head == NULL) {
        collection->head = current;
        collection->current = current;
    }
    else if (collection->current->nextElement == NULL) {
        collection->current->nextElement = current;
    }
    else {
        current->nextElement = collection->current->nextElement;
        collection->current->nextElement = current;
    }
}
void MovePointerForvard(listCollection* list) {
    list->current = list->current->nextElement;
}
void CheckNext(listCollection* list) {
    printf("Next element is %c\n", list->current->nextElement->value);
}
void ChangeNext(listCollection* list,char data){
    list->current->nextElement->value = data;
}
void menu(listCollection list) {
    int menuPointer = 0;
    int buffer;
    int isExist = 0;
    system("cls");
    while (menuPointer!=12) {
        menuPointer = 0;
        system("cls");
        printf("Menu\n");
        printf("Select menu item\n");
        printf("1. Clear list\n");
        printf("2. Check empty\n");
        printf("3. Set pointer to head\n");
        printf("4. Check pointer on the end\n");
        printf("5. Move pointer forvard\n");
        printf("6. Check next element\n");
        printf("7. Delete next element\n");
        printf("8. Extract next element\n");
        printf("9. Change next element\n");
        printf("10. Add new element\n");
        printf("11. Print list\n");
        printf("12. Exit\n");
        printf("\nList: \n");
        if (list.head != NULL)
            PrintList(list);
        else printf("List is Empty\n");
        scanf_s("%d", &menuPointer);
        buffer=getchar();//мусор
        switch (menuPointer)
        {
        case 1:
            system("cls");
            if (list.head != NULL) {
                DeleteAll(&list);
            }
            printf("Work done, press enter to return\n");
            buffer = getchar();
            break;
        case 2:
            system("cls");
            CheckEmpty(&list);
            printf("Work done, press enter to return\n");
            buffer = getchar();
            break;
        case 3:
            system("cls");
            MovePointerToStart(&list);
            printf("Work done, press enter to return\n");
            buffer = getchar();
            break;
        case 4:
            system("cls");
            if (list.head != NULL) {
                CheckPointerOnEnd(&list);
                printf("Work done, press enter to return\n");
            }
            else printf("Error, empty list\n");
            buffer = getchar();
            break;
        case 5:
            system("cls");
            if (list.head != NULL) {
                if (list.current->nextElement != NULL) {
                    MovePointerForvard(&list);
                    printf("Work done, press enter to return\n");
                }
                else printf("Error, end of list");
            }
            else printf("Error, list empty");
            buffer = getchar();
            break;
        case 6:
            system("cls");
            if (list.head != NULL) {
                if (list.current->nextElement != NULL) {
                    CheckNext(&list);
                    printf("Work done, press enter to return\n");
                }
                else printf("Error, end of list");
            }
            else printf("Error, empty list\n");
            buffer = getchar();
            break;
        case 7:
            system("cls");
            if (list.head != NULL) {
                if (list.current->nextElement != NULL) {
                    DeleteNext(&list);
                    printf("Work done, press enter to return\n");
                }
                else printf("Error, end of list");
            }
            else printf("Error, empty list\n");
            buffer = getchar();
            break;
        case 8:
            system("cls");
            if (list.head != NULL) {
                if (list.current->nextElement != NULL) {
                    CheckNext(&list);
                    DeleteNext(&list);
                    printf("Work done, press enter to return\n");
                }
                else printf("Error, end of list");
            }
            else printf("Error, empty list\n");
            buffer = getchar();
            break;
        case 9:
            system("cls");
            if (list.head != NULL) {
                if (list.current->nextElement != NULL) {
                    char inputChangeElement;
                    printf("Input new element\n");
                    buffer = scanf_s("%c", &inputChangeElement);
                    ChangeNext(&list, inputChangeElement);
                    printf("Work done, press enter to return\n");
                    buffer = getchar();
                }
                else
                   printf("Error, end of list\n");
            }
            else printf("Error, empty list\n");
            buffer = getchar();
            break;
        case 10:
            system("cls");
            char inputElement;
            printf("Input your element\n");
            buffer=scanf_s("%c", &inputElement);
            AddElement(&list, inputElement);
            printf("Work done, press enter to return\n");
            buffer=getchar();
            buffer=getchar();
            break;
        case 11:
            system("cls");
            if (list.head != NULL) {
                PrintList(list);
                printf("Work done, press enter button to return\n");
            }
            else printf("Error, list is empty\n");
            buffer=getchar();
            break;
        default:
            system("cls");
            break;
        }
    }
    if (list.head!=NULL)
        DeleteAll(&list); //если выход
}
void main() {
    int menuPointer = 0;
    while (menuPointer != 12) {
        menuPointer = 0;
        printf("Menu\n");
        printf("Select menu item\n");
        printf("1. Create list and start work\n");
        printf("2. Exit\n");
        scanf_s("%d", &menuPointer);
        if (menuPointer == 1) {
            listCollection list = StartWork();
            menu(list);
            exit(0);
        }
        else if (menuPointer == 2)
            exit(0);
        else printf("Incorrect input\n");
        getchar();
        getchar();
        system("cls");
    }
}


