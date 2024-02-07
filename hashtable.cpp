#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Node{
    int key;
    int value;
    Node(int k, int v): key(k), value(v) {};
};

class HashTable{
    private:
        vector <list<Node>> table;
        int size;

        size_t hash(int key){
            return key % table.size();
        }
    public:
        HashTable(int initial_size): size(initial_size){
            table.resize(size);
        }
};