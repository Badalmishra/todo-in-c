#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<string.h>

struct Node{
struct Node *next;
char task[100];
int status;
};
void push(struct Node** head_ref, char task[100]){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(new_node->task,task);
    new_node->status=1;
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}
void update_status(int index,struct Node** head_ref){
    struct Node * target_node;
    target_node=*head_ref;
    int i;
    for( i=1;i<index;i++){
        target_node=target_node->next;
    }
    printf("\n status of %s was %d\n",target_node->task,target_node->status);
    target_node->status=(!target_node->status);
    printf(" Its now changed to %d \n",target_node->status);
    getch();
}
void show_active(struct Node** head_ref){
    struct Node * traverser=*head_ref;
    int i=1;
    printf("\n List of active tasks\n");
    while(traverser!=NULL){
        if(traverser->status==1){
            printf(" %d || %s \n",i,traverser->task);
        }
        i++;
        traverser=traverser->next;
    }
    getch();
}
void remove_at(int index,struct Node** head_ref){
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
void printList(struct Node *node){
    int i =1;
    while (node != NULL){
	printf("\n %d -> %s | status: %d", i , node->task,  node->status);
	node = node->next;
	i++;
    }
}
int main(){
        int pos,choice;
        struct Node* head = NULL;
        char task[100] ="eat";
        while(1){
            system("cls");
            printList(head);
            printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\nChoose \n 1: to add task. || 2: to remove task \n 3: for active tasks 4: to update task status|| 11 to exit \n");
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
                case 3:
                    show_active(&head);
                    break;
                case 4:
                    printf("please enter task number to be updated \n");
                    scanf("%d",&pos);
                    update_status(pos,&head);
                    break;
                case 11:
                    exit(0);
                    break;
                default: printf("\n please follow instruction \n");

            }
        }
        return 0;
}
