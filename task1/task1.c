#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct diff {
    long offset;                /* offset of the difference in file starting from zero*/
    unsigned char orig_value;   /* value of the byte in ORIG */
    unsigned char new_value;    /* value of the byte in NEW */
} diff;

typedef struct node node;

struct node {
    diff *diff_data; /* pointer to a struct containing the offset and the value of the bytes in each of the files*/
    node *next;
};

/* Print the nodes in diff_list in the following format:
 * byte POSITION ORIG_VALUE NEW_VALUE
 * Each item followed by a newline character. */
void list_print(node *diff_list, FILE* output){
    if(diff_list->diff_data != NULL){
        fprintf(output, "byte %ld %02X %02X\n",
                diff_list->diff_data->offset,
                diff_list->diff_data->orig_value,
                diff_list->diff_data->new_value);
        if(diff_list->next != NULL)
            list_print(diff_list->next, output);
    }
};

/* Add a new node with the given data to the list,
   and return a pointer to the list (i.e., the first node in the list).
   If the list is null - create a new entry and return a pointer to the entry.*/
node* list_append(node* diff_list, diff* data){
    node *new = (node*)malloc(sizeof(node));
    if(data!=NULL) {
        diff* new_diff = (diff*)malloc(sizeof(diff));
        new_diff->offset = data->offset;
        new_diff->new_value = data->new_value;
        new_diff->orig_value = data->orig_value;

        new->diff_data = new_diff;
        new->next = diff_list;
        return new;
    }
    return new;
}

/* Free the memory allocated by and for the list. */
void list_free(node *diff_list) {
    node* current = diff_list;
    node* temp;
    while(current!=NULL)
    {
        temp = current;
        current = current->next;
        free(temp->diff_data);
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    diff *dif1 = (diff *) malloc(sizeof(diff));
    dif1->offset = 10;
    dif1->new_value = 'A';
    dif1->orig_value = 'B';

    diff *dif2 = (diff *) malloc(sizeof(diff));
    dif2->offset = 20;
    dif2->new_value = 'C';
    dif2->orig_value = 'D';

    node *list = (node *) malloc(sizeof(node));

    list = list_append(list, dif1);
    list = list_append(list, dif2);

    list_print(list, stdout);
    list_free(list);

    return 0;
}