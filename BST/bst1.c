#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
    int height;
}
    *root = NULL;

struct node *insert(struct node *p, int key);
int search_element(struct node *p, int key);
void postorder(struct node *p);
void inorder(struct node *p);
int minimum_elemnt(struct node *p);
int height_tree(struct node *p);
struct node *LL_rotation(struct node *p);
struct node *RR_rotation(struct node *p);
struct node *LR_rotation(struct node *p);
struct node *RL_rotation(struct node *p);
int node_height(struct node *p);
int balance_factor(struct node *p);
struct node *search(struct node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        else if (p->data > key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return NULL;
}
int main()
{
    int n1;
    printf("enter the number of elements you want to enter:");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        int data1;
        printf("Enter the element:");
        scanf("%d", &data1);
        root = insert(root, data1);
    }
    printf("inorder is\n");
    inorder(root);
    printf("\n");
    // int n2;
    // printf("enter another element you want to insert:");
    // scanf("%d", &n2);
    // root = insert(root, n2);
    // printf("inorder is\n");
    // inorder(root);
    // printf("\n");
    // printf("%d ", minimum_elemnt(root));
    // printf("\n");
    // int n;
    // printf("Enter the element to search:");
    // scanf("%d", &n);
    // if (search(root, n) == NULL)
    // {
    //     printf("element is NOT present in the tree");
    // }
    // else
    // {
    //     printf("%d is present in the tree", search(root, n)->data);
    // }
    // printf("\n");
    printf("height of the tree is: %d", height_tree(root));
    printf("\n");
    // printf("postorder is\n");
    postorder(root);
}
struct node *insert(struct node *p, int key)
{

    if (p == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = key;
        temp->lchild = NULL;
        temp->rchild = NULL;
        temp->height = 1;
        if (root == NULL)
        {
            root = temp;
        }
        return temp;
    }
    else
    {
        if (p->data < key)
        {
            p->rchild = insert(p->rchild, key);
        }
        else if (p->data > key)
        {

            p->lchild = insert(p->lchild, key);
        }

        p->height = node_height(p);

        if ((balance_factor(p) == 2) && (balance_factor(p->lchild) == 1))
        {
            return LL_rotation(p);
        }
        else if ((balance_factor(p) == -2) && (balance_factor(p->rchild) == -1))
        {
            return RR_rotation(p);
        }
        else if ((balance_factor(p) == 2) && (balance_factor(p->lchild) == -1))
        {
            return LR_rotation(p);
        }
        else if ((balance_factor(p) == -2) && (balance_factor(p->rchild) == 1))
        {
            return RL_rotation(p);
        }
        return p;
    }
}
void inorder(struct node *p)
{

    if (p != NULL)
    {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}
int minimum_elemnt(struct node *p)
{
    struct node *q;

    while (p != NULL)
    {
        q = p;
        p = p->lchild;
    }
    return q->data;
}
void postorder(struct node *p)
{

    if (p != NULL)
    {
        printf("%d ", p->data);
        postorder(p->lchild);
        postorder(p->rchild);
    }
}
int search_element(struct node *p, int key)
{

    while (p != NULL)
    {
        if (p->data > key)
        {
            p = p->lchild;
        }
        if (p->data < key)
        {
            p = p->rchild;
        }
        if ((p->data == key))
        {
            return 3;
        }
    }
    return 2;
}
int height_tree(struct node *p)
{

    if (p == NULL)
    {
        return 0;
    }
    else
    {
        int lh = height_tree(p->lchild);
        int rh = height_tree(p->rchild);
        if (lh > rh)
        {
            return lh + 1;
        }
        else
        {
            return rh + 1;
        }
    }
}
struct node *LL_rotation(struct node *p)
{

    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    p->lchild = plr;
    pl->rchild = p;
    p->height = node_height(p);
    pl->height = node_height(pl);
    if (root == p)
    {
        root = pl;
    }

    return pl;
}
struct node *RR_rotation(struct node *p)
{

    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    p->rchild = prl;
    pr->lchild = p;
    p->height = node_height(p);
    pr->height = node_height(pr);
    if (root == p)
    {
        root = pr;
    }
    return pr;
}
struct node *LR_rotation(struct node *p)
{

    struct node *pl = p->lchild;
    struct node *plr = pl->rchild;
    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->lchild = pl;
    plr->rchild = p;
    p->height = node_height(p);
    pl->height = node_height(pl);
    plr->height = node_height(plr);
    if (root == p)
    {
        root = plr;
    }
    return plr;
}
struct node *RL_rotation(struct node *p)
{

    struct node *pr = p->rchild;
    struct node *prl = pr->lchild;
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->rchild = pr;
    prl->lchild = p;
    p->height = node_height(p);
    pr->height = node_height(pr);
    prl->height = node_height(prl);
    if (root == p)
    {
        root = prl;
    }
    return prl;
}
int node_height(struct node *p)
{
    int lh = 0, rh = 0;
    if (p != NULL)
    {
        if (p->lchild != NULL)
        {
            lh = p->lchild->height;
        }
        if (p->rchild != NULL)
        {
            rh = p->rchild->height;
        }
    }
    if (lh > rh)
    {
        return lh + 1;
    }
    else
    {
        return rh + 1;
    }
}
int balance_factor(struct node *p)
{

    int lh = 0, rh = 0;
    if (p != NULL)
    {
        if (p->lchild != NULL)
        {
            lh = p->lchild->height;
        }
        if (p->rchild != NULL)
        {
            rh = p->rchild->height;
            ;
        }
    }
    return lh - rh;
}