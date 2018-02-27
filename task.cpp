
#include <iostream>
#include <vector>

using namespace std;

void print_it(vector<int> &);
void insert(vector<int> &);
void join(const vector<int> &, vector<int> &);

int main(void) {
    int size_to, size_from;
    
    cout << "Введите размер вектора to" << endl;
    cin >> size_to;
    cout << "Введите вектор to" << endl;
    vector<int> to(size_to);
    insert(to);
    cout << endl;
    
    cout << "Введите размер вектора from" << endl;
    cin >> size_from;
    cout << "Введите вектор from" << endl;
    vector<int> from(size_from);
    insert(from);
    cout << endl;
    
    join(from, to);
    cout << "Отсортированный вектор" << endl;
    print_it(to);
    
    return 0;
}


void join(const vector<int> &from, vector<int> &to) {
    // подготовка, устанавливаем итераторы на начало векторов
    vector<int>::const_iterator it_from;
    vector<int>::iterator it_to;
    it_from = from.begin();
    it_to = to.begin();
    
    int length = from.size() + to.size(); // число итераций не должно превышать
                                          // количество элементов в 2-х векторах
    for(int i = 0; i < length; i++) {
    
        if (*it_from < *it_to) {  // если эл. из from меньше чем эл. из to
            to.insert(it_to, *it_from); // то пишем его в to
            it_to = to.begin() + (i+1); // вектор расширился, переназначим итер.
            if (it_from + 1  != from.end()) it_from++; // если мы "обработали"
            else break ; // все эл. из from, то на этом заканчиваем сортировку
            
        }
        
       if (*it_from > *it_to) { // если эл. из from больше чем эл. из to
            if ((it_to + 1) == to.end()) { // сравниваем с последним эл. из to?
                to.insert(it_to + 1, *it_from); // если да, то пишем его в to
                it_to = to.begin() + (i + 1); // вектор расширился, переназначим итер.
                if (it_from + 1  != from.end()) it_from++; // если мы "обработали"
                else break; // все эл. из from, то на этом заканчиваем сортировку
            }
            else it_to++; // сравниваем след. эл. из to
       }
       
       if (*it_from == *it_to) { // если эл-ты в обоих векторах равны
            to.insert(it_to + 1, *it_from); // то пишем их рядом в to
            it_to = to.begin() + (i); // вектор расширился, переназначим итер.
            if (it_from + 1  != from.end()) it_from++; // если мы "обработали"
            else break; // все эл. из from, то на этом заканчиваем сортировку
       } 
    }
}


void print_it(vector<int> &b){
    for (int i = 0; i < b.size(); i++) { 
        cout << b[i] << " ";
        }
        cout << endl;
}


void insert(vector<int> &a) {
    int b;
    for (int i = 0; i < a.size(); i++) {
        cin >> b;
        a[i] = b;
    }
}


