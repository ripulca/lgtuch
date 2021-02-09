#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

struct adj {
    int* smej;
    int size;
};

struct graph {
    int size = 9;
    int* num = new int[size];
    int num_i[9] = { 0, 2, 3, 6, 4, 1, 7, 8, 5 };
    adj Adj[9];
    stack<int> S;
    int lowlink[9] = { 0,0,0,0,0,0,0,0,0 };
    vector<int> stronglink;

    void STRONG(int v, int i, int x);
};

void graph::STRONG(int v, int i, int x) {
    i++;
    num[v] = i;
    lowlink[v] = i;
    S.push(v);
    for (int w = Adj[v].smej[0], j=0; j < Adj[v].size; j++) {
        if (num[w] == 0) {
            STRONG(w, i, x);
            if (lowlink[v] > lowlink[w]) {
                lowlink[v] = lowlink[w];
            }
        }
        else if(num[w]<num[v]){
            if (num[w]==(S.top()+1)) {
                if (lowlink[v] > num[w]) {
                    lowlink[v] = num[w];
                }
            }
        }
    }
    if (lowlink[v]==num[v]) {
        while (x==S.top()&& x >= v) {
            stronglink.push_back(v);
            S.pop();
        }
    }
}

int main(){
    graph A;
    int i = 0;
    for (int x = 0; x < A.size; x++) {
        A.num[x] = 0;
        cout <<"enter the amount of the tops for "<< x <<endl;
        cin >> A.Adj[x].size;
        A.Adj[x].smej = new int[A.Adj[x].size];
        for (int j = 0; j < A.Adj[x].size; j++) {
            cout << "enter top " << j << endl;
            cin>>A.Adj[x].smej[j];
        }
    }
    for (int x = 0; x < A.size;x++) {
        if (A.num[A.num_i[x]] == 0) {
            const int c = A.num_i[x];
            A.STRONG(A.num_i[x], x, c);
        }
        if (!A.stronglink.empty()) {
            for (int i = 0; i < A.stronglink.size(); i++) {
                cout << A.stronglink[i] << " ";
            }
            cout << endl;
        }
    }
}