#include <iostream>

class Stack{
    private:
        int top;
        int capacity;
        int *StackArray;
        void DoubleCapacity();
    public:
        Stack():top(-1),capacity(1){
            StackArray = new int[capacity];
        }
        void Push(int x);
        void Pop();
        bool IsEmpty();
        int Top();
        int Size();
};
void Stack::DoubleCapacity(){

    capacity *= 2;                            
    int *newStackArray = new int[capacity];       

    for (int i = 0 ; i < capacity/2; i++) {   
        newStackArray[i] = StackArray[i];
    }

    delete [] StackArray;              
    StackArray = newStackArray;             
}

void Stack::Push(int x){

    if (top == capacity - 1) {
        DoubleCapacity();
    }
    StackArray[++top] = x;
}

void Stack::Pop(){

    if (IsEmpty()) {
        std::cout << "Stack is empty.\n";
        return;
    }
    top--;
}

bool Stack::IsEmpty(){
    return (top == -1);
}

int Stack::Top(){

    if (IsEmpty()) {
        std::cout << "Stack is empty.\n";
        return -1;
    }
    return StackArray[top];
}

int Stack::Size() {
    return top+1;
}

int main() {
    Stack stack;
    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Pop(); // 3
    std::cout << stack.Size(); // 2 
}
