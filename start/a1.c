// struct Node
// {
//     struct Node *left;
//     struct Node *right;
//     int data;
// };

// struct Pair
// {
//     struct Node *node; // p
//     int mark;   // i
// };

// struct Stack CreateStack();

// void traverse(struct Node *root)
// {
//     struct Stack *stack = CreateStack(); // create a stack
//     struct Node *p = root;

//     push(stack, struct Pair{p, 0});
//     while (!is_empty(stack))
//     {
//         struct Pair pair = pop(stack);
//         if (pair.mark == 0)
//         {
//             pair.mark = 1;
//             push(stack, pair);
//             push(stack, {pair.node->left, 0});
//         }

//         if (pair.mark == 1)
//         {
//             pair.mark = 2;
//             push(stack, pair);
//             push(stack, {pair.node->left, 0});
//         }

//         if (pair.mark == 2)
//         {
//             if (pair.node != null)
//                 printf("%d", pair.node->data);
//         }
//     }
// }