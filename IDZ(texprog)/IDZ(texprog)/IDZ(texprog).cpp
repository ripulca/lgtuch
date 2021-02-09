#include <cassert>
#include <array>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;

struct List {
    float key;
    float inf1;
    char inf2;
    List* next;
    List* prev;
};

bool readf(List**head, List**list, int*j, char*Name) {
	ifstream fin; int x;
	fin.open(Name, ios::in);
	if (!fin.is_open()) {
		cout << "Не удалось открыть файл." << endl;
		return false;
	}
	else {
		cout << "Файл успешно открыт." << endl;
		fin >> x;
		if ((*head) == NULL) {
			(*head) = new List;
			fin>>(*head)->key;
			cout << (*head)->key << endl;
			fin>>(*head)->inf1;
			cout << (*head)->inf1 << endl;
			fin>>(*head)->inf2;
			cout << (*head)->inf2 << endl;
			(*head)->next = NULL;
			(*list) = (*head);
			(*j)++;
			x--;
		}
		while (x!=0) {
			if ((*j) != 1) {
				while ((*list)->next != NULL) {
					(*list) = (*list)->next;
				}
			}
			(*list)->next = new List;
			(*list) = (*list)->next;
			fin>>(*list)->key;
			cout << (*list)->key << endl;
			fin>>(*list)->inf1;
			cout << (*list)->inf1 << endl;
			fin>>(*list)->inf2;
			cout << (*list)->inf2 << endl;
			(*list)->next = NULL;
			(*j)++;
			x--;
		}
		cout << "количество эл.:" << *j << endl;
		fin.close();
		return true;
	}
}

void add(List** head, List**walk, int* size) {
	if (*head == NULL) {
		(*head) = new List;
		cout << "введите значение эл." << endl;
		cin >> (*head)->key;
		cout << "введите доп. поле1" << endl;
		cin >> (*head)->inf1;
		cout << "введите доп. поле2" << endl;
		cin >> (*head)->inf2;
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*walk) = (*head);
		(*size)++;
	}
	else {
		int l;
		List* tmp = new List;
		cout << "1-начало/середина, 2-конец" << endl;
		cin >> l;
		switch (l){
		case 1:
			int x;
			*walk = *head;
			cout << "введите индекс, куда добавить" << endl;
			cin >> x;
			x--;
			for (int i = 1; i < x; i++) {
				*walk = (*walk)->next;
			}
			tmp = (*walk)->next;
			(*walk)->next = new List;
			(*walk)->next->prev = (*walk);
			(*walk) = (*walk)->next;
			cout << "введите значение эл." << endl;
			cin >> (*walk)->key;
			cout << "введите доп. поле1" << endl;
			cin >> (*walk)->inf1;
			cout << "введите доп. поле2" << endl;
			cin >> (*walk)->inf2;
			(*walk)->next = tmp;
			x++;
			if (x == 0) {
				swap((*walk)->prev->key, (*walk)->key);
				swap((*walk)->inf1, (*walk)->prev->inf1);
				swap((*walk)->inf2, (*walk)->prev->inf2);
			}
			(*size)++;
			break;
		case 2:
			while ((*walk)->next != NULL) {
				(*walk) = (*walk)->next;
			}
			(*walk)->next = new List;
			(*walk)->next->prev = (*walk);
			(*walk) = (*walk)->next;
			cout << "введите значение эл." << endl;
			cin >> (*walk)->key;
			cout << "введите доп. поле1" << endl;
			cin >> (*walk)->inf1;
			cout << "введите доп. поле2" << endl;
			cin>>(*walk)->inf2;
			(*walk)->next = NULL;
			(*size)++;
			break;
		}
	}
}

void del(List** head, List** walk, int* size, float DL) {
	*walk = *head;
	List* tmp = (*walk);
	if (tmp->key==DL) {
		tmp = tmp->next;
	}
	else if (tmp->next->key == DL) {
		tmp->next = tmp->next->next;
	}
	else {
		while (tmp->next->key != DL) {
			tmp = tmp->next;
		}
		tmp->next = tmp->next->next;
	}
	(*walk) = tmp;
	(*size)--;
}

void change(List** head, List** walk, float x) {
	*walk = *head;
	while ((*walk)->key != x) {
	(*walk) = (*walk)->next;
	}
	cout << "введите значение эл." << endl;
	cin >> (*walk)->key;
	cout << "введите доп. поле1" << endl;
	cin >> (*walk)->inf1;
	cout << "введите доп. поле2" << endl;
	cin >> (*walk)->inf2;
}

void list_swap(List**a,List**b) {
	swap((*a)->key, (*b)->key);
	swap((*a)->inf1, (*b)->inf1);
	swap((*a)->inf2, (*b)->inf2);
}

void quicksort(List** left, List** right) {
	if ((*left) == (*right))
		return;
	else if ((*left)->next == (*right)) {
		if ((*left)->key > (*right)->key)
			list_swap(left, right);
	}
	else {
		List* last = (*left);
		List* current = (*left);
		do {
			current = current->next;

			if (current->key < (*left)->key) {
				last = last->next;
				list_swap(&last, &current);
			}

		} while (current != (*right));

		list_swap(left, &last);

		quicksort(left, &last);
		if (last != (*right))
			quicksort(&last->next, right);
	}
}

void note_cons(List* head, int j) {
	cout << "кол-во эл." << j << endl;
	while(head!=NULL) {
		cout << head->key << " "<<head->inf1<<" "<<head->inf2<<endl;
		head = head->next;
	}
	cout << endl;
}

int main(){
	setlocale(LC_ALL, "rus");
	int size=0, v=1; float DL, x;
	char Name[20];
    List* head = NULL;
    List* tmp = NULL;
	List* tmp1 = new List;
	while (v != 0) {
		cout << "Выберите опцию: 1-добавить эл., 2-удалить эл., 3-изменить ключи, 4-сортировать по ключу, 5-считать файл;" << endl;
		cin >> v;
		switch (v){
		case 1:
			add(&head, &tmp, &size);
			tmp = head;
			note_cons(head, size);
			break;
		case 2:
			cout << "введите ключ для удаления" << endl;
			cin >> DL;
			del(&head, &tmp, &size, DL);
			tmp = head;
			note_cons(head, size);
			break;
		case 3:
			cout << "введите ключ для поиска" << endl;
			cin >> x;
			change(&head, &tmp, x);
			tmp = head;
			note_cons(head, size);
			break;
		case 4:
			tmp = head;
			while(tmp->next!=NULL) {
				tmp = tmp->next;
			}
			quicksort(&head, &tmp);
			note_cons(head, size);
			break;
		case 5:
			cout << "введите имя файла" << endl;
			std::cin >> Name;
			readf(&head, &tmp, &size, Name);
			tmp = head;
			note_cons(head, size);
			break;
		}
	}
}