#include <iostream>
#include <locale.h>

using namespace std;

struct Elem {
    int key;
    Elem* pnext;
};

int first_elem(Elem** pbeg, Elem** pend, int d) {
    Elem* ph = new Elem;
    ph->key = d;
    ph->pnext = 0;
    *pbeg = ph;
    *pend = ph;

    return 0;
}
int add_elem(Elem** pend, int d) {
    Elem* ph = new Elem;
    ph->key = d;
    ph->pnext = 0;
    (*pend)->pnext = ph;
    *pend = ph;

    return 0;
}
int del_elem(Elem** pbeg, Elem** pend, int k) {
    Elem* pk = 0;
    Elem* ph = *pbeg;
    if (!*pbeg)
        cout << "Ошибка: список пуст" << endl;
    return 0;

    if ((*pbeg)->key == k) {
        if (*pbeg = *pend) {
            *pbeg = 0;
            *pend = 0;
            delete pk;
        }
        else {
            *pbeg = (*pbeg)->pnext;
            delete ph;
        }
    }
    else {
        while ((ph->pnext) && (ph->pnext->key != k))
            ph = ph->pnext;
        pk = ph->pnext;
        if (pk) {
            ph->pnext = pk->pnext;
            delete pk;
        }
        else
            return 0;
    }
    return 1;
}
void work(Elem** pbeg, int z) {}
void print_elem(Elem* pbeg) {
    Elem* ph = pbeg;
    while (ph) {
        cout << ph->key << ' ';
        ph = ph->pnext;
    }
    cout << endl;
}
void del_list(Elem* pbeg) {
    if (pbeg != NULL) {
        del_list(pbeg->pnext);
        delete pbeg;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    Elem* pbeg = 0;
    Elem* pend = 0;
    int d;
    int g = 0;
    int a;
    int k;
    int z;
    char s;
    char ch;
    do {
        cout << " Нажмите 1 - добавить элемент/создать, 2 - удалить, 3 - просмотр списка: " << endl;
        cin >> ch;
        switch (ch) {
        case '1':
            if (!pbeg) {
                cout << "Введите 1 элемент списка: " << endl;
                cin >> d;
                first_elem(&pbeg, &pend, d);
                break;
            }
            else {
                cout << "Введите новый элемент списка: " << endl;
                cin >> a;
                add_elem(&pend, a);
                cout << "Список всех элементов" << endl;
                print_elem(pbeg);
                g = 1;
                break;
            }
        case '2':
            cout << "Введите значение элемента для удаления: " << endl;
            cin >> k;
            if (del_elem(&pbeg, &pend, k) == 0) {
                cout << "Элемент для удаления не найден" << endl;
                cout << "Список всех элементов" << endl;
                print_elem(pbeg);
            }
            else {
                del_elem(&pbeg, &pend, k);
                cout << "Список всех элементов" << endl;
                print_elem(pbeg);
            }
            break;
        case '3':
            if (g == 1)
            {
                cout << "Список всех элементов" << endl;
                print_elem(pbeg);
                break;
            }
            else
                cout << "Список пуст" << endl;
        }
        _flushall;
        cout << "Повторить (1-да/2-нет)" << endl;
        cin >> s;
    } while (s == '1');
    system("Pause");
    if (pbeg != NULL) {
        del_list(pbeg->pnext);
        delete pbeg;
    }
    return 0;
}