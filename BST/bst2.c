#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
}
*root = NULL;

struct node *insert(struct node *p, int key);
struct node *delete_node(struct node *p, int key);
void inorder(struct node *p);
void postorder(struct node *p);
void preorder(struct node *p);
int minimum_element(struct node *p);
int maximum_element(struct node *p);
void search_elements(struct node *p, int a, int b);
int search_node(struct node *p);
int search_node2(struct node *p);


int main()
{

    int n = 0;
    int arr[]={23,12,34,65,43,52,10};
    int i=0;
    while (i<7)
    {
        root=insert(root,arr[i]);
        i++;
    }
    
    while (n < 10)
    {
        int temp = 1;
        int min = 0, max = 0;
        int c;
        int b;

        printf("enter 1 for insertion\n");
        printf("enter 2 for deletion\n");
        printf("enter 3 for traversal\n");
        printf("enter 4 for minimum and maximum element\n");
        printf("enter 5 for finding elements in the entered range\n");
        printf("enter 6 to exit\n");

        int a;
        printf("enter the choice:");
        scanf("%d", &a);
        switch (a)
        {

        case 1:
            printf("enter the element to be inserted: ");
            scanf("%d", &b);
            root = insert(root, b);
            break;

        case 2:
            printf("enter the element to be deleted: ");
            scanf("%d", &c);
            root = delete_node(root, c);
            break;

        case 3:
            printf("enter 1 for postorder\n");
            printf("enter 2 for inorder\n");
            printf("enter 3 for preorder\n");
            printf("enter the choice: ");
            int c;
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                printf("postorder traversal is: \n");
                postorder(root);
                printf("\n");
                break;

            case 2:
                printf("inorder traversal is: \n");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("preoder traversal is: \n");
                preorder(root);
                printf("\n");
                break;

            default:
                break;

            }
            break;

        case 4:
            printf("minimum element is: %d\n", minimum_element(root));
            printf("maximum element is: %d\n", maximum_element(root));
            break;

        case 5:
            printf("enter the minimum value:");
            scanf("%d", &min);
            printf("enter the maximum value:");
            scanf("%d", &max);
            printf("elements in the range are: ");
            search_elements(root, min, max);
            printf("\n");
            break;

        default:
            temp = 0;
            break;
        }
        if (temp == 0)
        {
            break;
        }

        printf("\n");

        n++;
    }
    return 0;
}
void search_elements(struct node *p, int a, int b)
{

    if (p != NULL)
    {
        search_elements(p->lchild, a, b);
        if ((p->data >= a) && (p->data <= b))
        {
            printf("%d ", p->data);
        }
        search_elements(p->rchild, a, b);
    }
}
int maximum_element(struct node *p)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->rchild;
    }

    return q->data;
}

int minimum_element(struct node *p)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->lchild;
    }

    return q->data;
}

struct node *insert(struct node *p, int d)
{

    if (p == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->data = d;
        temp->lchild = NULL;
        temp->rchild = NULL;
        return temp;
    }
    else
    {
        if (d < (p->data))
        {
            p->lchild = insert(p->lchild, d);
        }
        else if (d > (p->data))
        {
            p->rchild = insert(p->rchild, d);
        }
        else
        {
            printf("data is already in the tree");
        }

        return p;
    }
}
void preorder(struct node *p)
{

    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
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
void postorder(struct node *p)
{

    if (p != NULL)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}
struct node *delete_node(struct node *p, int key)
{
    if (root == NULL)
    {
        printf("CANNOT DELETE NODE:");
        return NULL;
    }
    if (p == NULL)
    {
        return NULL;
    }
    if (p->data > key)
    {
        p->lchild = delete_node(p->lchild, key);
    }
    else if (p->data < key)
    {
        p->rchild = delete_node(p->rchild, key);
    }
    else
    {
        if ((p->lchild == NULL) && (p->rchild == NULL))
        {
            free(p);
            return NULL;
        }
        else
        {
            if (p->rchild == NULL)
            {
                p->data = search_node(p->lchild);
                p->lchild = delete_node(p->lchild, search_node(p->lchild));
            }
            else if (p->lchild == NULL)
            {
                p->data = search_node2(p->rchild);
                p->rchild = delete_node(p->rchild, search_node2(p->rchild));
            }
            else
            {
                p->data = search_node(p->lchild);
                p->lchild = delete_node(p->lchild, search_node(p->lchild));
            }

            return p;
        }
    }
}
int search_node(struct node *p)
{
    struct node *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->rchild;
    }
    return q->data;
}
int search_node2(struct node *p)
{

    struct node *q = NULL;
    while (p != NULL)
    {
        q = p;
        p = p->lchild;
    }
    return q->data;
}
