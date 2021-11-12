/*
 * main.c
 * Author: Mücahit KURTLAR
 * License: MIT
Copyright 2021 Mücahit KURTLAR

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>

enum nodeColor {
    RED,
    BLACK
};

struct node {
    int data;
    int color;
    struct node *left;
    struct node *right;
};
typedef struct node node;

node *createnode(int data);
void insert(node **n, int data);
char getcolorch(int color);
int getdepth(node *n);
void printsamelevel(node *n, int level, int parent, int order, int rst);
void printlayers();
void walk(node *n);

int main() {
    int num;
    scanf("%d", &num);
    node *tree = NULL;
    for (; num != -1; scanf("%d", &num))
    {
        insert(&tree, num);
    }
    walk(tree);
    puts("");
    printlayers(tree);
    
    return 0;
}

node *createnode(int data) {
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->color = RED;
    newnode->left = newnode->right = NULL;

    return newnode;
}
void insert(node **n, int data) {
    int dir[98], ht = 0, index;
    node *stack[98], *newnode, *ptr, *xptr, *yptr;
    ptr = *n;
    if (*n == NULL)
    {
        node *new_node = (node*) malloc(sizeof(node));
        new_node->data = data;
        new_node->color = RED;
        new_node->left = new_node->right = NULL;
        *n = new_node;
        return;
    }

    stack[ht] = *n;
    dir[ht++] = 0;
    while (ptr != NULL)
    {
        if (data == ptr->data)
        {
            return;
        }
        if ((data - ptr->data) > 0)
        {
            index = 1;
        } else
        {
            index = 0;
        }
        stack[ht] = ptr;
        if (index)
        {
            ptr = ptr->right;
        } else
        {
            ptr = ptr->left;
        }
        dir[ht++] = index;
    }
    if (index)
    {
        stack[ht - 1]->right = newnode = createnode(data);
    } else
    {
        stack[ht - 1]->left = newnode = createnode(data);
    }
    while ((ht >= 3) && (stack[ht - 1]->color == RED)) {
        if (dir[ht - 2] == 0)
        {
            yptr = stack[ht - 2]->right;
            if (yptr != NULL && yptr->color == RED)
            {
                stack[ht - 2]->color = RED;
                stack[ht - 1]->color = yptr->color = BLACK;
                ht = ht - 2;
            } else {
                if (0 == dir[ht - 1])
                {
                    yptr = stack[ht - 1];
                } else
                {
                    xptr = stack[ht - 1];
                    yptr = xptr->right;
                    xptr->right = yptr->left;
                    yptr->left = xptr;
                    stack[ht - 2]->left = yptr;
                }
                xptr = stack[ht - 2];
                yptr->color = BLACK;
                xptr->color = RED;
                xptr->left = yptr->right;
                yptr->right = xptr;
                if (*n == xptr)
                {
                    *n = yptr;
                } else
                {
                    if (dir[ht - 3])
                    {
                        stack[ht - 3]->right = yptr;
                    } else
                    {
                        stack[ht - 3]->left = yptr;
                    }
                }
                break;
            }
        } else
        {
            yptr = stack[ht - 2]->left;
            if ((yptr != NULL) && (yptr->color == RED))
            {
                stack[ht - 2]->color = RED;
                stack[ht - 1]->color = yptr->color = BLACK;
                ht = ht - 2;
            } else
            {
                if (1 == dir[ht - 1])
                {
                    yptr = stack[ht - 1];
                } else
                {
                    xptr = stack[ht - 1];
                    yptr = xptr->left;
                    xptr->left = yptr->right;
                    yptr->right = xptr;
                    stack[ht - 2]->right = yptr;
                }
                xptr = stack[ht - 2];
                yptr->color = BLACK;
                xptr->color = RED;
                xptr->right = yptr->left;
                yptr->left = xptr;
                if (xptr == *n)
                {
                    *n = yptr;
                } else
                {
                    if (dir[ht - 3])
                    {
                        stack[ht - 3]->right = yptr;
                    } else
                    {
                        stack[ht - 3]->left = yptr;
                    }
                }
                break;
            }
        }
    }
    (*n)->color = BLACK;
}
char getcolorch(int color) {
    if (color == BLACK)
    {
        return 'B';
    }
    return 'R';
}
int getdepth(node *n) {
    if (n==NULL)
    {
       return 0;
    }
    else 
    { 
        int lDepth = getdepth(n->left); 
        int rDepth = getdepth(n->right);
        if (lDepth > rDepth)
        {
            return(lDepth+1);
        } else
        {
            return(rDepth+1);
        }
    }    
}
void printsamelevel(node *n, int level, int parent, int order, int rst) {
    static int isnl = 1;
    if (rst)
    {
        isnl = 1;
    }
    if (n == NULL) {
        return;
    }
    if (isnl)
    {
        
        if (level == 1 && order == 3)
        {
            printf("%d %c (%d R)", n->data, getcolorch(n->color), parent);
            isnl = 0;
        }
        if (level == 1 && order == 2)
        {
            printf("%d %c", n->data, getcolorch(n->color));
            isnl = 1;
        }
        if (level == 1 && order == 1)
        {
            printf("%d %c (%d L)", n->data, getcolorch(n->color), parent);
            isnl = 0;
        }
    } else
    {
        if (level == 1 && order == 3)
        {
            printf(" %d %c (%d R)", n->data, getcolorch(n->color), parent);
        }
        if (level == 1 && order == 1)
        {
            printf(" %d %c (%d L)", n->data, getcolorch(n->color), parent);
        }
    }
    if (level > 1) 
    {
        printsamelevel(n->left, level-1, n->data, 1, 0);
        printsamelevel(n->right, level-1, n->data, 3, 0); 
    }
}
void printlayers(node *n) { 
    int height = getdepth(n);
    for (int i = 1; i <= height; i++) 
    { 
        printsamelevel(n, i, n->data, 2, 1); 
        puts("");
    }
}
void walk(node *n) {
  if (n) {
    walk(n->left);
    printf("%d\n", n->data);
    walk(n->right);
  }
  return;
}
