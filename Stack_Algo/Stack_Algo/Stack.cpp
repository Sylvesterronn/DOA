#include <iostream>
#include <cassert>

#define DEFAULT_CAPACITY (100)

class Stack {
private:
    int size;
    int capacity;
    int* objects;

public:
    Stack() {
        size = 0;
        capacity = DEFAULT_CAPACITY;
        objects = new int[capacity];
    }

    ~Stack() {
        delete[] objects;
    }

    void push(const int& x) {
        if (size >= capacity) {
            resize(2 * capacity);
            std::cout << "Resized the array!" << std::endl;
        }

        objects[size] = x;
        size++;
    }

    void pop() {
        assert(size > 0);
        size--;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << objects[i] << ",";
        }
        std::cout << std::endl;
    }

private:
    void resize(int new_capacity) {
        int* new_objects = new int[new_capacity];
        for (int i = 0; i < size; i++) {
            new_objects[i] = objects[i];
        }
        delete[] objects;
        objects = new_objects;
        capacity = new_capacity;
    }
};

int main() {
    Stack stack;

    for (int i = 0; i < 110; i++) {
        stack.push(5);
    }

    stack.print();

    return 0;
}
