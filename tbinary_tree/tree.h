#include <stdio.h>
#include <stdlib.h>

struct tnode{
    struct tnode* lchild;
    int data;
    struct tnode* rchild;
};
