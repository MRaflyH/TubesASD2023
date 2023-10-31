#include "stack.c"
// #include "queue.c"

int main() {
    Stack stack;
    ElType element;
    CreateStack(&stack);
    Push(&stack, 1);
    Push(&stack, 2);
    Push(&stack, 3);
    Push(&stack, 4);
    Push(&stack, 5);
    DisplayStack(stack);

    // Queue queue;
    // ElType element;
    // CreateQueue(&queue);
    // Enqueue(&queue, 1);
    // Enqueue(&queue, 2);
    // Enqueue(&queue, 3);
    // Enqueue(&queue, 4);
    // Enqueue(&queue, 5);
    // Dequeue(&queue, &element);
    // DisplayQueue(queue);
    
    return 0;
}