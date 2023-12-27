#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

struct Student {
    int id;
    int S1, S2, S3, S4;
    Student(int id, int s1, int s2, int s3, int s4) : id(id), S1(s1), S2(s2), S3(s3), S4(s4) {}
};

class Graph {
private:
    std::unordered_map<int, std::list<int>> adjList; // Key: Student ID, Value: List of connected student IDs

public:
    void add_edge(const Student& u, const Student& v, bool bi) {
        adjList[u.id].push_back(v.id);
        if (bi) {
            adjList[v.id].push_back(u.id);
        }
    }

    void rem_edge(const Student& u, const Student& v) {
        adjList[u.id].remove(v.id);
        adjList[v.id].remove(u.id);
    }

    void display() {
        for (auto& pair : adjList) {
            std::cout << "Student ID " << pair.first << " : ";
            for (int studentId : pair.second) {
                std::cout << studentId << ", ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create some students
    Student alice(1, 90, 80, 70, 60);
    Student bob(2, 85, 75, 65, 55);
    Student charlie(3, 95, 85, 75, 65);

    // Create a graph and add some edges
    Graph G;
    G.add_edge(alice, bob, true);
    G.add_edge(bob, charlie, true);

    // Display the graph
    G.display();

    return 0;
}
