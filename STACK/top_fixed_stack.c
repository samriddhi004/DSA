//top is 0th index which remains fixed.
//other elements move to the right 
//every new element gets added to arr_stack[0]

#include<stdio.h>
#include<stdlib.h>
#define size 5
int back = -1;
int stack_arr[size];
void push(int data){

    int i;
    back++;
    for(i=back;i>0;i--){
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;

}
void print(){
    int i;
    if(back == -1 ){
        printf("Stack underflow \n");
    }
    for(i = 0; i<=back;i++){
        printf("%d ",stack_arr[i]);
    }
}
void pop(){
    printf("\nThe popped element is %d \n",stack_arr[0]);
    for(int i= 0;i<back;i++){
        stack_arr[i]=stack_arr[i+1];
    }
    back--;
}
int isEmpty(){
    if(back == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(back == size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void peek(){
    if(isEmpty()){
        printf("Stack underflow\n");
    }
    else{
        printf("The topmost element is %d ",stack_arr[0]);
    }
}

int main(){
    int choice, data;
    while(1){
        printf("\n");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print the top element");
        printf("\n4. Print all the stack elements");
        printf("\n5. Quit");
        printf("\nEnter your choice ");
        scanf(" %d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf(" %d",&data);
            push(data);
            break;
        case 2:
            pop();
            break;
        
        case 3:
            peek();
            break;
        
        case 4:
            print();
            break;
        
        case 5:
            exit(1);

        default:
        printf("\nWrong choice :// \n");
    }
    }
    return 0;
}