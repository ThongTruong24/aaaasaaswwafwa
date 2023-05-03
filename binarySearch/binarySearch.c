/*
 * File: binarySearch.c
 * Author: Thong Truong
 * Date: 02/01/2003
 * Description: Search input data by binary search method
 */

#include <stdio.h>
#include <stdlib.h>

/* Create a database by Node */
typedef struct Node {
    int data;
    struct Node *next;
} Node;

/* Description: Creation vector for Node*/
typedef struct { 
    void (*push_back)(Node **, int);
} vector;

/* Create a database with center point using CenterPoint*/
typedef struct CenterPoint {
    int value;
    struct CenterPoint *left;
    struct CenterPoint *right;
} CenterPoint;

/* 
 * Function: *databaseCenterPoint()
 * Description: Add the corresponding address and value, linking them together from smallest
 * to largest by Node struct
 * Input:
 *     Node *firstNode
 *     int value
 */
void push_back(Node **firstNode, int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    
    /* Sort in ascending order */
    if (*firstNode == NULL || (*firstNode)->data >= value) {
        new_node->next = *firstNode;
        *firstNode = new_node;
        return;
    }

    Node *current = *firstNode;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}



/* 
 * Function: *databaseCenterPoint()
 * Description: Find the midpoints and link them together by CenterPoint struct using recursion
 * Input:
 *     Node *firstNode
 *     int start
 *     int end
 * Output:
 *     root: Addresses and corresponding data of CenterPoint struct associated with each other
 */
CenterPoint *databaseCenterPoint(Node *firstNode, int start, int end) {
      if (firstNode == NULL || start > end) {
        return NULL;
    }
    
    /* Determine the CenterPoint */
    int mid = (start + end) / 2;
    Node *node = firstNode;
    for (int i = start; i < mid; i++) {
        if (node->next == NULL) {
            break;
        }
        node = node->next;
    }

    CenterPoint *root = (CenterPoint *) malloc(sizeof(CenterPoint));

    /* set value for the CenterPoint */
    root->value = node->data;

    /* use recursion to find CenterPoint right and left */
    root->left = databaseCenterPoint(firstNode, start, mid - 1);
    root->right = databaseCenterPoint(node->next, mid + 1, end);

    return root;
}

/* 
 * Function: *centerPoint()
 * Description: Set the address and data at the respective midpoints 
 * Input:
 *     Node *firstNode
 * Output:
 *     databaseCenterPoint(): Addresses and corresponding data of CenterPoint struct associated with each other
 */
CenterPoint *centerPoint(Node *firstNode) {
    int length = 0;
    Node *node = firstNode;
    while (node != NULL) {
        node = node->next;
        length++;
    }

    return databaseCenterPoint(firstNode, 0, length - 1);
}

/* 
 * Function: *binarySearch()
 * Description: search CenterPoint with right value using recursion
 * Input:
 *     CenterPoint *root
 *     int value: Value required to search
 * Output:
 *     root: Address of the found value
 *     NULL: there is no address corresponding to the requested value
 */
CenterPoint *binarySearch(CenterPoint *root, int value) {
    static int loop = 0;
    loop++;
    printf("Number of repetitions: %d\n", loop);
    if (root == NULL) {
        return NULL;
    }

    if (root->value == value) {
        return root;
    }
    
    /* Use recursion to find the address corresponding to the value */
    if (value < root->value) {
        return binarySearch(root->left, value);
    } else {
        return binarySearch(root->right, value);
    }
}

/* 
 * Function: printList()
 * Description: print value from 1 to 10000 of the database 
 * Input:
 *     vector *database
 *     Node **node
 */
void printList(Node *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* 
 * Function: setDatabase()
 * Description: initialize a vector containing data from 1 to 10000 
 * Input:
 *     vector *database
 *     Node **node
 */
void setDatabase (vector *database, Node **node) {
    for (int i = 0; i < 10000; i++) {
        (*database).push_back(node, i + 1);
    }
}

/* 
 * Function: vectorInit()
 * Description: vector value initialization
 * Input:
 *     vector *database
 *     Node **node
 */
void vectorInit(vector *database, Node **node) {
    *node = NULL;
    database->push_back = &push_back;
}


int main() {

    Node *node;
    vector database;
    vectorInit(&database, &node);
 
    setDatabase(&database, &node);

    CenterPoint *ptr = centerPoint(node);
    printList(node);

    int value = 0;
    printf("Enter value: ");
    scanf("%d", &value);

    CenterPoint *result = binarySearch(ptr, value);
    if (result != NULL) {
        printf("Find success: %d\n", result->value);
    } else {
        printf("Not found %d\n", value);
    }
    return 0;
}