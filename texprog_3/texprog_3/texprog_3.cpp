#include <iostream>
#include <cstdlib>
#include <cmath>
#include <limits.h>
#include <ctime>
#include <windows.h>
using namespace std;

struct Data {
    float A;
    char B;
    int C;
};

struct list {
    Data D[7];
    int am;
    list *prev;
    list* next;
};

void add(list**head, list**List, int* n, int *N, int m) {
    (*List) = (*head);
    if ((*head)== NULL) {
        (*head) = new list;
        (*head)->D->A= float(rand() % 100) / 100;
        (*head)->D->B= char('a' + rand() % ('z' - 'a'));
        (*head)->D->C= rand() % 100 - 50;
        (*head)->next = NULL;
        (*head)->prev = NULL;
        (*head)->am=1;
        (*List) = (*head);
        (*n)++;
        (*N)++;
    }
    else {
        int y, x;
        list* tmp = new list;
        cout << "1- в начало или середину. 2- в конец" << endl;
        cin >> y;
        switch (y)
        {
        case 2:                                     //KONEC
            while ((*List)->next!=0) {
                (*List) = (*List)->next;
            }
            if ((*List)->am == m) {
                (*List)->next = new list;
                (*List)->next->am = 0;
                (*List)->next->prev = (*List);
                (*List) = (*List)->next;
                (*N)++;
            }
            cout << "" << endl;
            (*List)->D[(*List)->am].A= float(rand() % 100) / 100;
            (*List)->D[(*List)->am].B= char('a' + rand() % ('z' - 'a'));
            (*List)->D[(*List)->am].C= rand() % 100 - 50;
            (*List)->next = NULL;
            (*List)->am++;
            (*n)++;
            break;
        case 1:                                     //NACHALO I CEREDINA
            cout << "введите номер позиции" << endl;
            cin >> x;
            while ((*List)->am<x) {
                x -= (*List)->am;
                (*List) = (*List)->next;
            }
            x--;
            if ((*List)->am == m) {
                if ((*List)->next == NULL) {                                    //содз. новый блок
                    tmp = (*List)->next;
                    (*List)->next = new list;
                    (*List)->next->prev = (*List);
                    (*List)->next->D[0] = (*List)->D[m - 1];
                    (*List)->next->am = 1;
                    (*N)++;
                    for (int i = m - 1; i > x; i--) {
                        (*List)->D[i] = (*List)->D[i - 1];
                    }
                    cout << "" << endl;
                    (*List)->D[x].A = float(rand() % 100) / 100;
                    (*List)->D[x].B = char('a' + rand() % ('z' - 'a'));
                    (*List)->D[x].C = rand() % 100 - 50;
                    (*List)->next->next = tmp;
                    (*n)++;
                }
                else if((*List)->next->am == m) {                                    //содз. новый блок
                    tmp = (*List)->next;
                    (*List)->next = new list;
                    (*List)->next->prev = (*List);
                    (*List)->next->D[0] = (*List)->D[m - 1];
                    (*List)->next->am = 1;
                    (*N)++;
                    for (int i = m - 1; i > x; i--) {
                        (*List)->D[i] = (*List)->D[i - 1];
                    }
                    cout << "" << endl;
                    (*List)->D[x].A = float(rand() % 100) / 100;
                    (*List)->D[x].B = char('a' + rand() % ('z' - 'a'));
                    (*List)->D[x].C = rand() % 100 - 50;
                    (*List)->next->next = tmp;
                    (*n)++;
                }
                else if ((*List)->next->am != m) {                    //если в след. не все яч. заполн
                    for (int i = (*List)->next->am; i > 0; i--) {
                        (*List)->next->D[i] = (*List)->next->D[i - 1];
                    }
                    (*List)->next->D[0] = (*List)->D[m - 1];
                    (*List)->next->am++;
                    for (int i = m - 1; i > x; i--) {
                        (*List)->D[i] = (*List)->D[i - 1];
                    }
                    cout << "" << endl;
                    (*List)->D[x].A = float(rand() % 100) / 100;
                    (*List)->D[x].B = char('a' + rand() % ('z' - 'a'));
                    (*List)->D[x].C = rand() % 100 - 50;
                    (*n)++;
                }
            }
            else {
                while (((*List)->am < x)&&(x>0)) {
                    x -= (*List)->am;
                    (*List) = (*List)->next;
                }
                for (int i = m - 1; i > x; i--) {
                    (*List)->D[i] = (*List)->D[i - 1];
                }
                (*List)->D[x].A= float(rand() % 100) / 100;
                (*List)->D[x].B= char('a' + rand() % ('z' - 'a'));
                (*List)->D[x].C= rand() % 100 - 50;
                (*List)->am++;
                (*n)++;
            }
            break;
        }
    }
    cout << "всего эл. " << (*n) << endl;
}

void del(list** head, list** List, int* n, int*N, int m) {
    int x;
    (*List) = (*head);
    list* tmp = new list;
    cout << "введите номер эл." << endl;
    cin >> x;
    while ((*List)->am < x) {
        x -= (*List)->am;
        (*List) = (*List)->next;
    }
    x--;
    for (int i = x; i < m - 1; i++) {
        (*List)->D[i] = (*List)->D[i + 1];
    }
    ((*List)->am)--;
    (*n)--;
    (*List)->D[m - 1].A = 0;
    (*List)->D[m - 1].B = 0;
    (*List)->D[m - 1].C = 0;
    if ((*List)->am == 0) {
        (*N)--;
        delete (*List);
    }
}

void change(list** head, list** List, int n, int m) {
    int x;
    (*List) = (*head);
    list* tmp = new list;
    cout << "введите номер эл." << endl;
    cin >> x;
    while ((*List)->am < x) {
        x -= (*List)->am;
        (*List) = (*List)->next;
    }
    x--;
    cout << "" << endl;
    cin >> (*List)->D[x].A;
    cin >> (*List)->D[x].B;
    cin >> (*List)->D[x].C;
}

void clean(list** head, list** List, int* n, int *N) {
    list* d = new list;
    while ((*head)->next != NULL) {
        d = (*head)->next;
        free(*head);
        (*head) = d;
    }
    free(*head);
    *List = *head;
    (*n) = 0;
    (*N) = 0;
}

void search(list* head, list* List, int n, int N) {
    List = head;
    float x;
    cout << "введите значение эл.(первый столбец)" << endl;
    cin >> x;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < List->am; j++) {
            if ((List->D[j].A) == x) {
                cout << List->D[j].A << " " << List->D[j].B << " " << List->D[j].C << endl;
            }
        }
        List = List->next;
    }
}

void cons(list* head, list* List, int n, int N, int m) {
    List = head;
    cout << "всего:" << n << endl << "блоков:" << N << endl;
    for (int i = 0; i < N; i++) {
        cout << endl;
        cout << "блок " << (i+1) << endl;
        for (int j = 0; j < List->am; j++) {
            cout <<List->D[j].A<<" "<<List->D[j].B<<" "<<List->D[j].C<<endl;
        }
        List = List->next;
    }
    cout << endl;
}

void adm_data(list* head, list* List, int n, int N) {
    List = head;
    for (int i = 0; i < N; i++) {
        cout << endl << "блок " << (i + 1) << endl;
        for (int j = 0; j < List->am; j++) {
            cout << List->D[j].A << " " << List->D[j].B << " " << List->D[j].C << " " << &List->D[j] <<endl;
        }
        List = List->next;
    }
}

int main(){
    setlocale(LC_ALL, "Rus");
    int n=0, N=0, m=7, k=1;
    cout << "" << endl;
    list* head = NULL;
    list* List = NULL;
    while (k != 0) {
        cout << "1- добавить. 2- удалить. 3- удалить все. 4- изменить данные эл. 5- поиск. 6- вывод служебной инф. 0- выход" << endl;
        cin >> k;
        switch (k)
        {
        case 1:
            add(&head, &List, &n, &N, m);
            cons(head, List, n, N, m);
            break;
        case 2:
            del(&head, &List, &n, &N, m);
            cons(head, List, n, N, m);
            break;
        case 3:
            clean(&head, &List, &n, &N);
            cons(head, List, n, N, m);
            break;
        case 4:
            change(&head, &List, n, m);
            cons(head, List, n, N, m);
            break;
        case 5:
            search(head, List, n, N);
            break;
        case 6:
            adm_data(head, List, n, N);
        }
    }
}