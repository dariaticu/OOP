#include <iostream>
using namespace std;

float operator"" _Kelvin(unsigned long long k) 
{
    return static_cast<float>(k - 273.15);
}

float operator"" _Kelvin(long double k) 
{
    return static_cast<float>(k - 273.15);
}

float operator"" _Fahrenheit(unsigned long long f) 
{
    return static_cast<float>((f - 32) * 5.0 / 9.0);
}

float operator"" _Fahrenheit(long double f) 
{
    return static_cast<float>((f - 32) * 5.0 / 9.0);
}


template <typename T>
class Tree 
{
public:
    struct Node 
    {
        T value;
        Node** children;       
        int children_count, capacity;          

        //constructor
        Node(T val) : value(val), children_count(0), capacity(2) 
        {
            children = new Node * [capacity];
        }

        ~Node() 
        {
            delete[] children;
        }

        void add_child_ptr(Node* child) 
        {
            if (children_count == capacity) 
            {
                capacity *= 2;
                Node** new_array = new Node * [capacity];
                for (int i = 0; i < children_count; i++) 
                    new_array[i] = children[i];
                
                delete[] children;
                children = new_array;
            }
            children[children_count++] = child;
        }

        void insert_child_ptr(Node* child, int index) 
        {
            if (index < 0 || index > children_count) return;

            if (children_count == capacity) 
            {
                capacity *= 2;
                Node** new_array = new Node * [capacity];
                for (int i = 0; i < children_count; i++) 
                    new_array[i] = children[i];
                
                delete[] children;
                children = new_array;
            }
            for (int i = children_count; i > index; i--) 
                children[i] = children[i - 1];
            
            children[index] = child;
            children_count++;
        }
    };

private:
    Node* root;
    int count_recursive(Node* node) {
        if (node == nullptr) return 0;
        int count = node->children_count; 
        for (int i = 0; i < node->children_count; i++) {
            count += count_recursive(node->children[i]); 
        }
        return count;
    }

    
    Node* find_recursive(Node* node, T param, bool (*cmp)(const T&, const T&)) 
    {
        if (node == nullptr) 
            return nullptr;

       
        if (cmp(node->value, param)) 
            return node;

        for (int i = 0; i < node->children_count; i++) 
        {
            Node* result = find_recursive(node->children[i], param, cmp);
            if(result != nullptr) 
                return result;
        }
        return nullptr;
    }

public:
    //constructor arbore
    Tree() : root(nullptr) {}

    // 1. add_node method
    Node* add_node(Node* parent, T value) 
    {
        Node* new_node = new Node(value);
        if (parent == nullptr) 
            root = new_node;
        else 
            parent->add_child_ptr(new_node);
        return new_node;
    }

    // 2. get_node method
    Node* get_node(Node* parent) {
        if (parent == nullptr) return root;
        return parent;
    }

    // 3. delete_node method (?terge nodul ?i to?i copiii lui recursiv)
    void delete_node(Node* node) {
        if (node == nullptr) return;
        for (int i = 0; i < node->children_count; i++) {
            delete_node(node->children[i]);
        }
        if (node == root) {
            root = nullptr;
        }
        delete node; 
    }

    // 4. find method 
    Node* find(T param, bool (*cmp)(const T&, const T&)) {
        return find_recursive(root, param, cmp);
    }

    // 5. insert method 
    Node* insert(Node* parent, T value, int index) {
        if (parent == nullptr) return nullptr;
        Node* new_node = new Node(value);
        parent->insert_child_ptr(new_node, index);
        return new_node;
    }

    // 6. sort method 
    void sort(Node* node, bool (*cmp)(const T&, const T&) = nullptr) {
        if (node == nullptr) return;

        for (int i = 0; i < node->children_count - 1; i++) {
            for (int j = i + 1; j < node->children_count; j++) {
                bool should_swap = false;
                if (cmp != nullptr) 
                    should_swap = cmp(node->children[j]->value, node->children[i]->value);
                else 
                    should_swap = node->children[j]->value < node->children[i]->value;
                

                if (should_swap) {
                    Node* temp = node->children[i];
                    node->children[i] = node->children[j];
                    node->children[j] = temp;
                }
            }
        }
    }

    // 7. count method 
    int count(Node* node) {
        if (node == nullptr) {
            return count_recursive(root);
        }
        return count_recursive(node);
    }
};

bool compareEqual(const int& a, const int& b) {
    return a == b;
}

bool compareDesc(const int& a, const int& b) {
    return a > b;
}

int main() 
{

    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    float c = 300.5_Kelvin;

    std::cout << "--- Conversii ---" << std::endl;
    std::cout << "300 Kelvin in Celsius: " << a << std::endl;
    std::cout << "120 Fahrenheit in Celsius: " << b << std::endl;
    std::cout << "\n--- Arbore n-ar ---" << std::endl;
    Tree<int> myTree;

    auto root = myTree.add_node(nullptr, 10); 

    myTree.add_node(root, 50);
    auto node30 = myTree.add_node(root, 30);
    myTree.add_node(root, 40);


    myTree.add_node(node30, 99);
    myTree.add_node(node30, 25);

    std::cout << "get_node(nullptr) returneaza nodul cu valoarea: "
        << myTree.get_node(nullptr)->value << "\n";

    std::cout << "Total descendenti ai radacinii: " << myTree.count(nullptr) << "\n";
    std::cout << "Total descendenti ai lui 30: " << myTree.count(node30) << "\n";

    myTree.insert(root, 45, 1);

    std::cout << "\nSortam copiii radacinii crescator (default):\n";
    myTree.sort(root, nullptr);
    for (int i = 0; i < root->children_count; i++) {
        std::cout << root->children[i]->value << " ";
    }
    std::cout << "\n";

    std::cout << "Sortam copiii radacinii descrescator (callback):\n";
    myTree.sort(root, compareDesc);
    for (int i = 0; i < root->children_count; i++) {
        std::cout << root->children[i]->value << " ";
    }
    std::cout << "\n";
  
    auto found = myTree.find(99, compareEqual);
    if (found != nullptr) {
        std::cout << "\nNodul cu valoarea 99 a fost gasit!\n";
    }

    myTree.delete_node(root);
    return 0;
}