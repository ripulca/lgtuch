#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;
/*степ. дерева 4*/
struct Tree {
    int used, ch, lvl, num;
    char Data;
    Tree *leftch, *rightneib1, *rightneib2, *rightneib3;
};

void TreeGen(Tree*walk, Tree**root, int* c, int max, int min, int all, int*tmp1, int tmp2) {
    if (walk != NULL) {
        if ((*tmp1) < all) {
            walk->Data = char('a' + rand() % ('z' - 'a'));
            cout << "Уровень: " << walk->lvl << " Ключ: " << walk->Data << endl;
            if (walk->lvl == (*c)) {
                (*c) = walk->lvl + 1;
            }
            (*tmp1)++;
            if ((((*c) == 1)&&(min==0))||(((*tmp1)<all-1)&&(min==0))) {
                walk->ch = 1 + rand() % max;
            }
            else {
                walk->ch = min + rand() % max;
            }
            if (walk->lvl<tmp2) {
                switch (walk->ch) {
                case 1:
                    walk->used = 1;
                    walk->leftch = new Tree;
                    walk->leftch->lvl = walk->lvl + 1;
                    walk->leftch->used = NULL;
                    walk->leftch->Data = NULL;
                    walk->rightneib1 = NULL;
                    walk->rightneib2 = NULL;
                    walk->rightneib3 = NULL;
                    break;
                case 2:
                    walk->used = 2;
                    walk->leftch = new Tree;
                    walk->leftch->lvl = walk->lvl + 1;
                    walk->leftch->used = NULL;
                    walk->leftch->Data = NULL;
                    walk->rightneib1 = new Tree;
                    walk->rightneib1->lvl = walk->lvl + 1;
                    walk->rightneib1->used = NULL;
                    walk->rightneib1->Data = NULL;
                    walk->rightneib2 = NULL;
                    walk->rightneib3 = NULL;
                    break;
                case 3:
                    walk->used = 3;
                    walk->leftch = new Tree;
                    walk->leftch->lvl = walk->lvl + 1;
                    walk->leftch->used = NULL;
                    walk->leftch->Data = NULL;
                    walk->rightneib1 = new Tree;
                    walk->rightneib1->lvl = walk->lvl + 1;
                    walk->rightneib1->used = NULL;
                    walk->rightneib1->Data = NULL;
                    walk->rightneib2 = new Tree;
                    walk->rightneib2->lvl = walk->lvl + 1;
                    walk->rightneib2->used = NULL;
                    walk->rightneib2->Data = NULL;
                    walk->rightneib3 = NULL;
                    break;
                case 4:
                    walk->used = 4;
                    walk->leftch = new Tree;
                    walk->leftch->lvl = walk->lvl + 1;
                    walk->leftch->used = NULL;
                    walk->leftch->Data = NULL;
                    walk->rightneib1 = new Tree;
                    walk->rightneib1->lvl = walk->lvl + 1;
                    walk->rightneib1->used = NULL;
                    walk->rightneib1->Data = NULL;
                    walk->rightneib2 = new Tree;
                    walk->rightneib2->lvl = walk->lvl + 1;
                    walk->rightneib2->used = NULL;
                    walk->rightneib2->Data = NULL;
                    walk->rightneib3 = new Tree;
                    walk->rightneib3->lvl = walk->lvl + 1;
                    walk->rightneib3->used = NULL;
                    walk->rightneib3->Data = NULL;
                    break;
                case 0:
                    walk->used = 0;
                    walk->leftch = NULL;
                    walk->rightneib1 = NULL;
                    walk->rightneib2 = NULL;
                    walk->rightneib3 = NULL;
                    break;
                }
            }
            else if((walk->lvl == tmp2)||((*tmp1)==all)){
                walk->used = 0;
                walk->leftch = NULL;
                walk->rightneib1 = NULL;
                walk->rightneib2 = NULL;
                walk->rightneib3 = NULL;
            }
            (*root) = walk; 

            TreeGen(walk->leftch, root, c, max, min, all, tmp1, tmp2);
            TreeGen(walk->rightneib1, root, c, max, min, all, tmp1, tmp2);
            TreeGen(walk->rightneib2, root, c, max, min, all, tmp1, tmp2);
            TreeGen(walk->rightneib3, root, c, max, min, all, tmp1, tmp2);
        }
    }
}

void Root(Tree* root) {
    cout << "Корень: " << root->Data<<endl;
}

void GetLabel(Tree* walk, char x) {
    if (walk != NULL) {
        GetLabel(walk->leftch, x);
        GetLabel(walk->rightneib1, x);
        GetLabel(walk->rightneib2, x);
        GetLabel(walk->rightneib3, x);
        if (walk->Data == x) {
            cout << "Уровень узла: " << walk->lvl << " Ключ: " << walk->Data << endl;
        }
    }
}

void SetLabel(Tree* walk, Tree**root, char x) {
    if (walk != NULL) {
        SetLabel(walk->leftch, root, x);
        SetLabel(walk->rightneib1, root, x);
        SetLabel(walk->rightneib2, root, x);
        SetLabel(walk->rightneib3, root, x);
        if (walk->Data == x) {
            cin >> walk->Data;
            (*root) = walk;
            cout << "Номер узла: " << walk->lvl << " Ключ: " << walk->Data << endl;
        }
    }
}

void Search(Tree* walk, char x) {
    if (walk != NULL) {
        Search(walk->leftch, x);
        Search(walk->rightneib1, x);
        Search(walk->rightneib2, x);
        Search(walk->rightneib3, x);
        if (walk->Data == x) {
            cout << "Номер узла: " << walk->num << " Уровень узла: " << walk->lvl << " Ключ: " << walk->Data << endl;
        }
    }
}

void Parent(Tree* walk, char x, Tree**temp, int n) {
    if (walk != NULL) {
        if (walk->leftch !=NULL) {
            Parent(walk->leftch, x, temp, n);
            Parent(walk->rightneib1, x, temp, n);
            Parent(walk->rightneib2, x, temp, n);
            Parent(walk->rightneib3, x, temp, n);
            if (walk->leftch != NULL) {
                if ((walk->leftch->Data == x)&&(walk->leftch->lvl == n)) {
                    cout << "Родитель:  Уровень узла: " << walk->lvl << " Ключ: " << walk->Data << endl;
                    (*temp) = walk;
                }
            }
            if (walk->rightneib1 != NULL) {
                if ((walk->rightneib1->Data == x) && (walk->rightneib1->lvl == n)) {
                    cout << "Родитель:  Уровень узла: " << walk->lvl << " Ключ: " << walk->Data << endl;
                    (*temp) = walk;
                }
            }
            if (walk->rightneib2 != NULL) {
                if ((walk->rightneib2->Data == x) && (walk->rightneib2->lvl == n)) {
                    cout << "Родитель:  Уровень узла: " << walk->lvl << " Ключ: " << walk->Data << endl;
                    (*temp) = walk;
                }
            }
            if (walk->rightneib3 != NULL) {
                if ((walk->rightneib3->Data == x) && (walk->rightneib3->lvl == n)) {
                    cout << "Родитель:  Уровень узла: " << walk->lvl << " Ключ: " << walk->Data << endl;
                    (*temp) = walk;
                }
            }
        }
    }
}

void Add(Tree**root, Tree*walk, int *c, int max, int min, char n, int f) {
    if (walk != NULL) {
        Add(root, walk->leftch, c, max, min, n, f);
        Add(root, walk->rightneib1, c, max, min, n, f);
        Add(root, walk->rightneib2, c, max, min, n, f);
        Add(root, walk->rightneib3, c, max, min, n, f);
        if ((walk->Data == n)&&(walk->lvl == f)) {
            (*root) = walk;
            if ((*root)->ch < max) {
                (*root)->ch++;
            }
            if (((*root)->used == 0) && ((*root)->used < (*root)->ch)) {
                (*root)->leftch = new Tree;
                (*root)->leftch->Data = char('a' + rand() % ('z' - 'a'));
                (*root)->leftch->ch = min + rand() % max;
                (*root)->leftch->lvl = (*root)->lvl + 1;
                (*root)->leftch->used = 0;
                (*root)->leftch->leftch = NULL;
                (*root)->leftch->rightneib1 = NULL;
                (*root)->leftch->rightneib2 = NULL;
                (*root)->leftch->rightneib3 = NULL;
                (*root)->used++;
                if ((*root)->leftch->lvl == *c) {
                    (*c) = (*root)->leftch->lvl + 1;
                }
            }
            else if (((*root)->used == 1) && ((*root)->used < (*root)->ch)) {
                (*root)->rightneib1 = new Tree;
                (*root)->rightneib1->Data = char('a' + rand() % ('z' - 'a'));
                (*root)->rightneib1->ch = min + rand() % max;
                (*root)->rightneib1->lvl = (*root)->lvl + 1;
                (*root)->rightneib1->used = 0;
                (*root)->rightneib1->leftch = NULL;
                (*root)->rightneib1->rightneib1 = NULL;
                (*root)->rightneib1->rightneib2 = NULL;
                (*root)->rightneib1->rightneib3 = NULL;
                (*root)->used++;
            }
            else if (((*root)->used == 2) && ((*root)->used < (*root)->ch)) {
                (*root)->rightneib2 = new Tree;
                (*root)->rightneib2->Data = char('a' + rand() % ('z' - 'a'));
                (*root)->rightneib2->ch = min + rand() % max;
                (*root)->rightneib2->lvl = (*root)->lvl + 1;
                (*root)->rightneib2->used = 0;
                (*root)->rightneib2->leftch = NULL;
                (*root)->rightneib2->rightneib1 = NULL;
                (*root)->rightneib2->rightneib2 = NULL;
                (*root)->rightneib2->rightneib3 = NULL;
                (*root)->used++;
            }
            else if (((*root)->used == 3) && ((*root)->used < (*root)->ch)) {
                (*root)->rightneib3 = new Tree;
                (*root)->rightneib3->Data = char('a' + rand() % ('z' - 'a'));
                (*root)->rightneib3->ch = min + rand() % max;
                (*root)->rightneib3->lvl = (*root)->lvl + 1;
                (*root)->rightneib3->used = 0;
                (*root)->rightneib3->leftch = NULL;
                (*root)->rightneib3->rightneib1 = NULL;
                (*root)->rightneib3->rightneib2 = NULL;
                (*root)->rightneib3->rightneib3 = NULL;
                (*root)->used++;
            }
            else if ((*root)->used == (*root)->ch) {
                cout << "Данный узел занят." << endl;
            }
        }
    }
}

void Delete(Tree* walk, Tree** root, Tree*temp, char x, int f) {
    if (walk != NULL) {
        if (walk->leftch != NULL) {
            if ((walk->leftch->Data == x) && (walk->lvl == f - 1)) {
                (*root) = walk;
            }
        }
        if (walk->rightneib1 != NULL) {
            if ((walk->rightneib1->Data == x) && (walk->lvl == f - 1)) {
                (*root) = walk;
            }
        }
        if (walk->rightneib2 != NULL) {
            if ((walk->rightneib2->Data == x) && (walk->lvl == f - 1)) {
                (*root) = walk;
            }
        }
        if (walk->rightneib3 != NULL) {
            if ((walk->rightneib3->Data == x) && (walk->lvl == f - 1)) {
                (*root) = walk;
            }
        }
        Delete(walk->leftch, root, temp, x, f);
        Delete(walk->rightneib1, root, temp, x, f);
        Delete(walk->rightneib2, root, temp, x, f);
        Delete(walk->rightneib3, root, temp, x, f);
        if ((walk->Data == x) && (walk->lvl == f)) {
            temp = walk;
            cout << "Номер узла: " << walk->num << " Уровень узла: " << walk->lvl << " Ключ: " << walk->Data << endl;
            if (walk->leftch != NULL) {
                temp = temp->leftch;
                if (temp->rightneib1!=NULL) {
                    while (temp->rightneib1 != NULL) {
                        if (temp->rightneib3 != NULL) {
                            temp = temp->rightneib3;
                        }
                        else if (temp->rightneib2 != NULL) {
                            temp = temp->rightneib2;
                        }
                        else {
                            temp = temp->rightneib1;
                        }
                    }
                    temp->leftch = walk->rightneib1;
                    (*root) = temp;
                    temp->rightneib1 = walk->rightneib2;
                    (*root) = temp;
                    temp->rightneib2 = walk->rightneib3;
                    (*root) = temp;
                }
                walk->Data = walk->leftch->Data;
                (*root) = walk;
                walk->used = walk->leftch->used;
                (*root) = walk;
                walk->rightneib1 = walk->leftch->rightneib1;
                (*root) = walk;
                walk->rightneib2 = walk->leftch->rightneib2;
                (*root) = walk;
                walk->rightneib3 = walk->leftch->rightneib3;
                (*root) = walk;
                walk->leftch = walk->leftch->leftch;
                (*root) = walk;
            }
            else {
                walk = (*root);
                if (walk->leftch != NULL) {
                    if (walk->leftch->Data == x) {
                        walk->leftch = walk->rightneib1;
                        (*root) = walk;
                        walk->rightneib1 = walk->rightneib2;
                        (*root) = walk;
                        walk->rightneib2 = walk->rightneib3;
                        (*root) = walk;
                        walk->rightneib3 = NULL;
                        (*root) = walk;
                    }
                }
                if (walk->rightneib1 != NULL) {
                    if (walk->rightneib1->Data == x) {
                        walk->rightneib1 = walk->rightneib2;
                        (*root) = walk;
                        walk->rightneib2 = walk->rightneib3;
                        (*root) = walk;
                        walk->rightneib3 = NULL;
                        (*root) = walk;
                    }
                }
                if (walk->rightneib2 != NULL) {
                    if (walk->rightneib2->Data == x) {
                        walk->rightneib2 = walk->rightneib3;
                        (*root) = walk;
                        walk->rightneib3 = NULL;
                        (*root) = walk;
                    }
                }
                if (walk->rightneib3 != NULL) {
                    if (walk->rightneib3->Data == x) {
                        walk->rightneib3 = NULL;
                        (*root) = walk;
                    }
                }
            }
        }
    }
}

void lvlcorr( Tree*walk, Tree**root, Tree*temp, int*c) {
    if (walk != NULL) {
        if (walk->leftch != NULL) {
            if (walk->leftch->lvl != (walk->lvl + 1)) {
                walk->leftch->lvl = walk->lvl + 1;
                (*root) = walk;
            }
            if (walk->rightneib1 != NULL) {
                walk->rightneib1->lvl = walk->lvl + 1;
                (*root) = walk;
            }
            if (walk->rightneib2 != NULL) {
                walk->rightneib2->lvl = walk->lvl + 1;
                (*root) = walk;
            }
            if (walk->rightneib3 != NULL) {
                walk->rightneib3->lvl = walk->lvl + 1;
                (*root) = walk;
            }
            if (walk->lvl + 1 > (*c)) {
                (*c) = walk->lvl + 1;
            }
        }
        lvlcorr(walk->leftch, root, temp, c);
        lvlcorr(walk->rightneib1, root, temp, c);
        lvlcorr(walk->rightneib2, root, temp, c);
        lvlcorr(walk->rightneib3, root, temp, c);
    }
}

void LeftMostChild(Tree* walk, char x, int n) {
    if (walk != NULL) {
        LeftMostChild(walk->leftch, x, n);
        LeftMostChild(walk->rightneib1, x, n);
        LeftMostChild(walk->rightneib2, x, n);
        LeftMostChild(walk->rightneib3, x, n);
        if ((walk->Data == x) && (walk->lvl == n) && (walk->leftch==NULL)) {
            cout << "Нет потомков." << endl;
        }
        else if ((walk->Data == x)&&(walk->lvl==n)) {
            cout << "Номер узла: " << walk->num << " Ключ: " << walk->Data << " Самый левый потомок:   Номер узла: " << walk->leftch->num << " Уровень: " << walk->leftch->lvl << " Ключ: " << walk->leftch->Data << endl;
        }
    }
}

bool RightNeighbour(Tree* walk, char x, int n) {
    if (walk != NULL) {
        RightNeighbour(walk->leftch, x, n);
        RightNeighbour(walk->rightneib1, x, n);
        RightNeighbour(walk->rightneib2, x, n);
        RightNeighbour(walk->rightneib3, x, n);
        if ((walk->leftch != NULL)&&(walk->rightneib1 != NULL)) {
            if ((walk->leftch->Data == x) && (walk->leftch->lvl == n)) {
                cout << "Правый сосед:  Номер узла: " << walk->rightneib1->num << " Ключ: " << walk->rightneib1->Data << endl;
                return true;
            }
        }
        if ((walk->rightneib1 != NULL)&&(walk->rightneib2 != NULL)) {
            if ((walk->rightneib1->Data == x) && (walk->rightneib1->lvl == n)) {
                cout << "Правый сосед:  Номер узла: " << walk->rightneib2->num << " Ключ: " << walk->rightneib2->Data << endl;
                return true;
            }
        }
        if ((walk->rightneib2 != NULL)&&(walk->rightneib3 != NULL)) {
            if ((walk->rightneib2->Data == x) && (walk->rightneib2->lvl == n)) {
                cout << "Правый сосед:  Номер узла: " << walk->rightneib3->num << " Ключ: " << walk->rightneib3->Data << endl;
                return true;
            }
        }
    }
}

void MakeTreeNULL(Tree*walk, Tree** root) {
    if (walk != NULL) {
        MakeTreeNULL(walk->leftch, root);
        MakeTreeNULL(walk->rightneib1, root);
        MakeTreeNULL(walk->rightneib2, root);
        MakeTreeNULL(walk->rightneib3, root);
        walk = NULL;
        (*root) = walk;
    }
}

void SeeWalkTree(Tree* walk, Tree**root, int*n) {
    if (walk != NULL) {
        if (walk->leftch != NULL) {
            if (walk->leftch->Data == NULL) {
                walk->leftch = NULL;
            }
        }
        if (walk->rightneib1 != NULL) {
            if (walk->rightneib1->Data == NULL) {
                walk->rightneib1 = NULL;
            }
        }
        if (walk->rightneib2 != NULL) {
            if (walk->rightneib2->Data == NULL) {
                walk->rightneib2 = NULL;
            }
        }
        if (walk->rightneib3 != NULL) {
            if (walk->rightneib3->Data == NULL) {
                walk->rightneib3 = NULL;
            }
        }
        SeeWalkTree(walk->leftch, root, n);
        SeeWalkTree(walk->rightneib1, root, n);
        SeeWalkTree(walk->rightneib2, root, n);
        SeeWalkTree(walk->rightneib3, root, n);
        walk->num = *n;
        cout << "Уровень: " << walk->lvl <<" Номер узла: "<< walk->num<< " Ключ: " << walk->Data << endl;
        (*root) = walk;
        (*n)++;
    }
}

void SeeTree(Tree*root, int c, int*temp) {
    if (root != NULL) {
        temp++;
        SeeTree(root->leftch, c, temp);
        for (int i = 0; i < 3*root->lvl; i++) {
            cout << "   ";
        }
        cout <<root->lvl<<" / " << root->Data << endl<<endl;
        SeeTree(root->rightneib1, c, temp);
        SeeTree(root->rightneib2, c, temp);
        SeeTree(root->rightneib3, c, temp);
        
    }
}


int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int v = 1, c=0, n=0, N=0, min, max, sredn, disp, all, tmp1=0, tmp2;
    char x;
    cout << "Введите среднее кол-во потомков. От 0 до 4." << endl;
    cin >> sredn;
    while ((sredn > 4) || (sredn < 1)) {
        cout << "Некорректный ввод. Повторите." << endl;
        cin >> sredn;
    }
    cout << "Введите дисперсию:" << endl;
    cin >> disp;
    while ((sredn - disp < 0) || (sredn + disp > 4)||(disp==0)) {
        cout << "Некорректный ввод. Повторите." << endl;
        cin >> disp;
    }
    min = sredn - disp;
    max = sredn + disp;
    max -= min;
    cout << "Введите кол-во узлов:" << endl;
    cin >> all;
    tmp2 = int(all / 4);
    if ((all - (4*tmp2)) != 0) {
        tmp2+= all - (4 * tmp2);
    }

    Tree* root = new Tree;
    root->lvl = 0;
    Tree* walk = root;
    Tree* tmp = new Tree;
    tmp = root;
    Tree* temp = new Tree;
    temp = root;

    TreeGen(walk, &root, &c, max, min, all, &tmp1, tmp2);
    root = tmp;
    walk = root;
    SeeWalkTree(walk, &root, &n);
    n = 0;
    cout << endl;
    SeeTree(root, c, &n);
    root = tmp;
    cout << endl;
    cout << "1-добавить эл. 2-удалить. 3-вывести в консоль. 4-обнулить дерево. 5-поиск. 6-получить ключ. 7-изменить ключ. 8-корень. 9-самый левый р. 10-правый сосед. 11-родитель. 0-выход." << endl;
    while (v != 0) {
        cin >> v;
        switch (v) {
        case 1:
            cout << "Введите ключ родительского узла:" << endl;
            cin >> x;
            cout << "Введите lvl родительского узла:"<<endl;
            cin >> n;
            while (n > c) {
                cout << "Некорректный ввод. Повторите:" << endl;
                cin >> n;
            }
            Add(&root, walk, &c, max, min, x, n);
            root = tmp;
            walk = root;
            cout << endl;
            SeeTree(root, c, &n);
            break;
        case 2:
            cout << "Введите ключ узла:" << endl;
            cin >> x;
            cout << "Введите lvl узла:" << endl;
            cin >> n;
            while (n > c) {
                cout << "Некорректный ввод. Повторите:" << endl;
                cin >> n;
            }
            Delete(walk, &root, temp, x, n);
            root = tmp;
            walk = root;
            lvlcorr(walk, &root, temp, &c);
            root = tmp;
            walk = root;
            cout << endl;
            SeeTree(root, c, &n);
            break;
        case 3:
            if (root==NULL) {
                cout << "Дерево пусто." << endl;
            }
            else {
                n = 0;
                SeeWalkTree(walk, &root, &n);
                root = tmp;
                walk = root;
                cout << endl;
                SeeTree(root, c, &n);
                root = tmp;
                walk = root;
                cout << endl;
            }
            break;
        case 4:
            MakeTreeNULL(walk, &root);
            c = 0;
            break;
        case 5:
            cout << "Введите ключ узла:" << endl;
            cin >> x;
            Search(walk, x);
            root = tmp;
            walk = root;
            break;
        case 6:
            cout << "Введите ключ узла:" << endl;
            cin >> x;
            GetLabel(walk, x);
            root = tmp;
            walk = root;
            break;
        case 7:
            cout << "Введите ключ узла:" << endl;
            cin >> x;
            SetLabel(walk, &root, x);
            root = tmp;
            walk = root;
            break;
        case 8:
            if (root == NULL) {
                cout << "Дерево пусто." << endl;
            }
            else {
                Root(root);
            }
            break;
        case 9:
            cout << "Введите ключ узла:" << endl;
            cin >> x;
            cout << "Введите lvl узла:" << endl;
            cin >> n;
            while (n > c) {
                cout << "Некорректный ввод. Повторите:" << endl;
                cin >> n;
            }
            LeftMostChild(walk, x, n);
            break;
        case 10:
            cout << "Введите ключ узла:" << endl;
            cin >> x;
            cout << "Введите lvl узла:" << endl;
            cin >> n;
            while (n > c) {
                cout << "Некорректный ввод. Повторите:" << endl;
                cin >> n;
            }
            RightNeighbour(walk, x, n);
            break;
        case 11:
            cout << "Введите ключ узла:" << endl;
            cin >> x;
            cout << "Введите lvl узла:" << endl;
            cin >> n;
            while (n > c) {
                cout << "Некорректный ввод. Повторите:" << endl;
                cin >> n;
            }
            if (n==0) {
                cout << "Корень";
            }
            else {
                Parent(walk, x, &temp, n);
            }
            break;
        }
    }
}