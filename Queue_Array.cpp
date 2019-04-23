#include<stdio.h>
#include<stdlib.h>
int queue[100];
int rear=-1;
int front=-1;
void insert(int);
int delete();
void display();

int main()
{
    int num1=0,num2=0;
    int choice;
    while(1){
        printf("\nSelect a choice from the following :\n");
        printf("[1] Add an element into the queue\n[2] Remove an element from the queue\n[3] Display the queue elements\n[4] exit\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            {
                printf("Enter the element to be added to the queue:");
                scanf("%d",&num1);
                insert(num1);
                printf("Insert Successful!");
                break;

            }
            case 2:
                {
                    num2=delete();
                    printf("%d element is deleted from the queue\n",num2);
                    break;
                }
            case 3:
                {
                    display();
                    break;
                }
            case 4:
                {
                    exit(0);
                }
            default:
                {
                    printf("Wrong choice!\nTry Again\n");
                    break;
                }
        }
    }
    return 0;
}

void insert(int element){
    if(front==-1){
        front=0;
        rear=0;
        queue[front]=element;
    }
    else if(front>-1){
        if(rear==99){
            printf("Queue is full\n");
            exit(1);
        }
        rear=rear+1;
        queue[rear]=element;
    }
}

int delete()
{
    int temp;
    if(front==-1 && rear==-1){
        printf("Queue list is empty\n");
        exit(1);
    }
    else{
        if(front!=-1 && front==rear){
            temp=queue[front];
            front=-1;
            rear=-1;
            return(temp);
        }
        else{
            temp=queue[front];
            front++;
            return(temp);
        }
    }
}

void display()
{
    int i;
    if(front==-1 && rear==-1){
        printf("Queue List is empty");
    }
    else{
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
    }
}
