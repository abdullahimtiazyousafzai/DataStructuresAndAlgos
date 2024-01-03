#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Graph
{
private:
    list<int> *adjlist;
    int size;

public:
    Graph(int V)
    {
        size = V;
        adjlist = new list<int>[size];
    }

    void insert_edge(int a, int b, bool bi)
    {
        if (a >= 0 && a < size && b >= 0 && b < size)
        {
            adjlist[a].push_back(b);
            if (bi)
                adjlist[b].push_back(a);
        }
        else
        {
            cout << "Invalid vertex index in "<<a<<" or "<<b<<endl;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " : ";
            for (auto &temp : adjlist[i])
            {
                cout << temp << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph T(20);
    T.insert_edge(1, 2, true);
    T.insert_edge(2, 3, false);
    T.insert_edge(3, 5, true);
    T.insert_edge(12, 5, false);
    T.insert_edge(24, 2, true);
    T.insert_edge(8, 6, false);
    T.display();
    return 0;
}