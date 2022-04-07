bool verify_postfixexpression(char postfix[]) {
    for (i = 0; postfix[i] != '\0'; i++) {
        if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '/' && postfix[i] != '*'){
            push(postfix[i], &mystack);//If it is not an operator, push it to the stack
        }

        else{
            if (StackSize(&myStack) >= 2)
                pop(&num2, &myStack);

            else {
                printf("Invalid postfix expression\n");
                ClearStack(&myStack);
                break;
            }
        }
    }
}