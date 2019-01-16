
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>

struct Node
{
struct Node *next;
char * task;
int status;
};

void push(struct Node** head_ref, char* task)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    char *temp=malloc(sizeof(*task));
    strcpy(temp,task);
    new_node->task=temp;
    new_node->status=1;
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}


void remove_at(int index,struct Node** head_ref)
{
    struct Node* prev_node ,* target_node;
    prev_node = *head_ref;
    if(index==1){
        *head_ref=prev_node->next;
        free(prev_node);
        return;
    }
    for(int i =1 ;i<(index-1);i++){
    prev_node=prev_node->next;
    }
    target_node=prev_node->next;
    prev_node->next=target_node->next;
    free(target_node);
}

void printList(struct Node *node)
{
    int i =1;
    while (node != NULL){
	printf("\n %d -> %s | status: %d", i , node->task,  node->status);
	node = node->next;
	i++;
    }
}

int main()
{
        int pos,choice;
        struct Node* head = NULL;
        char task[100] ="eat";
        while(1){
            printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\nChoose || 1: to add task. || 2: to remove task || 11 to exit \n");
            printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            scanf("%d",&choice);
            if(stdin)
            fflush(stdin);
            switch(choice){
                case 1:
                    printf("Enter a task \n");
                    scanf("%[^\n]s",task);
                    push(&head,task);
                    break;
                case 2:
                    printf("please enter task number to be removed \n");
                    scanf("%d",&pos);
                    remove_at(pos,&head);
                    break;
                case 11:
                    exit(0);
                    break;
                default: printf("\n please follow instruction \n");

            }
            system("cls");
            printList(head);
        }
        return 0;
}
