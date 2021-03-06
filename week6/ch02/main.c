#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int KEY;
enum NODECOLOR
{
    BLACK = 0,
    RED = 1
};

typedef struct RBTree
{
    struct RBTree* parent;
    struct RBTree* left, * right;
    KEY key;
    NODECOLOR color;
}RBTree, * PRBTree;

PRBTree RB_InsertNode(PRBTree root, KEY key);
PRBTree RB_InsertNode_Fixup(PRBTree root, PRBTree z);
PRBTree RB_DeleteNode(PRBTree root, KEY key);
PRBTree RB_DeleteNode_Fixup(PRBTree root, PRBTree z);
PRBTree Find_Node(PRBTree root, KEY key);
void Left_Rotate(PRBTree A, PRBTree& root);
void Right_Rotate(PRBTree A, PRBTree& root);
void Mid_Visit(PRBTree T);
void Mid_DeleteTree(PRBTree T);
void Print_Node(PRBTree node);

void Left_Rotate(PRBTree A, PRBTree& root)
{
    PRBTree B;
    B = A->right;
    if (NULL == B)
        return;
    A->right = B->left;
    if (NULL != B->left)
        B->left->parent = A;
    B->parent = A->parent;
    // 这样三个判断连在一起避免了A->parent = NULL的情况
    if (A == root)
    {
        root = B;
    }
    else if (A == A->parent->left)
    {
        A->parent->left = B;
    }
    else
    {
        A->parent->right = B;
    }
    B->left = A;
    A->parent = B;
}

void Right_Rotate(PRBTree A, PRBTree& root)
{
    PRBTree B;
    B = A->left;
    if (NULL == B)
        return;
    A->left = B->right;
    if (NULL != B->right)
        B->right->parent = A;
    B->parent = A->parent;
    // 这样三个判断连在一起避免了A->parent = NULL的情况
    if (A == root)
    {
        root = B;
    }
    else if (A == A->parent->left)
    {
        A->parent->left = B;
    }
    else
    {
        A->parent->right = B;
    }
    A->parent = B;
    B->right = A;
}

PRBTree Find_Node(PRBTree root, KEY key)
{
    PRBTree x;
    // 找到key所在的node
    x = root;
    do
    {
        if (key == x->key)
            break;
        if (key < x->key)
        {
            if (NULL != x->left)
                x = x->left;
            else
                break;
        }
        else
        {
            if (NULL != x->right)
                x = x->right;
            else
                break;
        }
    } while (NULL != x);

    return x;
}

PRBTree RB_InsertNode(PRBTree root, KEY key)
{
    PRBTree x, y;
    PRBTree z;
    if (NULL == (z = (PRBTree)malloc(sizeof(RBTree))))
    {
        printf("Memory alloc error\n");
        return NULL;
    }
    z->key = key;
    // 得到z的父节点
    x = root, y = NULL;
    while (NULL != x)
    {
        y = x;
        if (z->key < x->key)
        {
            if (NULL != x->left)
            {
                x = x->left;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (NULL != x->right)
            {
                x = x->right;
            }
            else
            {
                break;
            }
        }
    }
    // 把z放到合适的位置
    z->parent = y;
    if (NULL == y)
    {
        root = z;
    }
    else
    {
        if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
    }
    // 设置z的左右子树为空并且颜色是red，注意新插入的节点颜色都是red
    z->left = z->right = NULL;
    z->color = RED; 
    return RB_InsertNode_Fixup(root, z);
}

PRBTree RB_InsertNode_Fixup(PRBTree root, PRBTree z)
{
    PRBTree y;
    while (root != z && RED == z->parent->color) 
    {
        if (z->parent == z->parent->parent->left) 
        {
            y = z->parent->parent->right; 
            if (NULL != y && RED == y->color) 
            {
                z->parent->color = BLACK;
                y->color = BLACK; 
                z->parent->parent->color = RED; 
                z = z->parent->parent; 
            }
            else
            {
                if (z == z->parent->right) 
                {
                    z = z->parent;
                    Left_Rotate(z, root);
                }
                z->parent->color = BLACK; 
                z->parent->parent->color = RED; 
                Right_Rotate(z->parent->parent, root);
            }
        }
        else // 父节点为祖父节点的右子树
        {
            y = z->parent->parent->left; 
            if (NULL != y && RED == y->color) 
            {
                z->parent->color = BLACK; 
                y->color = BLACK;
                z->parent->parent->color = RED; 
                z = z->parent->parent; 
            }
            else // y不存在或者颜色是B
            {
                if (z == z->parent->left) 

                {
                    z = z->parent;
                    Right_Rotate(z, root);
                }
                z->parent->color = BLACK; 
                z->parent->parent->color = RED;
                Left_Rotate(z->parent->parent, root);
            }
        }
    } 
 // 根节点的颜色始终都是B
    root->color = BLACK;
    return root;
}
PRBTree RB_DeleteNode(PRBTree root, KEY key)
{
    PRBTree x, y, z, x_parent;
    z = Find_Node(root, key);
    if (NULL == z)
        return root;
    // 当z有一个空子树的时候,y == z
    // 否则,y是大于z最小的结点
    if (NULL == z->left || NULL == z->right)
        y = z;
    else
    {
        y = z->right;
        while (NULL != y->left)
            y = y->left;
    }
    //x是y的子树,可能为NULL
    if (NULL != y->left)
        x = y->left;
    else
        x = y->right;//设定x的位置取代y
    if (NULL != x)
        x->parent = y->parent;
    if (NULL == y->parent)
        root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    // 把y的key拷贝到z中,这样y就是待删除的结点了
    if (y != z)
    {
        z->key = y->key;
    }
    // 如果y的颜色值是B,那么要对树进行修正
    if (BLACK == y->color && NULL != x)
        RB_DeleteNode_Fixup(root, x);
    free(y);
    return root;
}
PRBTree RB_DeleteNode_Fixup(PRBTree root, PRBTree x)
{
    PRBTree w;
    while (x != root && BLACK == x->color)
    {
        if (x == x->parent->left) // 如果x是左子树
        {
            w = x->parent->right; // w是x的兄弟结点
            if (NULL == w)
                continue;
            if (RED == w->color) // 如果w的颜色是红色 
            {
                w->color = BLACK;
                x->parent->color = RED;
                Left_Rotate(x->parent, root);
                w = x->parent->right;
            }
            if (NULL != w->left && BLACK == w->left->color &&
                NULL != w->right && BLACK == w->right->color)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (NULL != w->right && BLACK == w->right->color)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    Right_Rotate(w, root);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                Left_Rotate(x->parent, root);
                x = root;
            }
        }
        else
        {
            w = x->parent->left;
            if (NULL == w)
                continue;
            if (RED == w->color)
            {
                w->color = BLACK;
                x->parent->color = RED;
                Left_Rotate(x->parent, root);
                w = x->parent->left;
            }
            if (NULL != w->left && BLACK == w->left->color &&
                NULL != w->right && BLACK == w->right->color)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (NULL != w->left && BLACK == w->left->color)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    Left_Rotate(w, root);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                Right_Rotate(x->parent, root);
                x = root;
            }
        }
    }
    x->color = BLACK;
    return root;
}
void Print_Node(PRBTree node)
{
    char* color[] = { "BLACK", "RED" };
    printf("Key = %d,\tcolor = %s", node->key, color[node->color]);
    if (NULL != node->parent)
        printf(",\tparent = %d", node->parent->key);
    if (NULL != node->left)
        printf(",\tleft = %d", node->left->key);
    if (NULL != node->right)
        printf(",\tright = %d", node->right->key);
    printf("\n");
}// 中序遍历树
void Mid_Visit(PRBTree T)
{
    if (NULL != T)
    {
        if (NULL != T->left)
            Mid_Visit(T->left);
        Print_Node(T);
        if (NULL != T->right)
            Mid_Visit(T->right);
    }
}// 中序删除树的各个节点
void Mid_DeleteTree(PRBTree T)
{
    if (NULL != T)
    {
        if (NULL != T->left)
            Mid_DeleteTree(T->left);
        PRBTree temp = T->right;
        free(T);
        T = NULL;
        if (NULL != temp)
            Mid_DeleteTree(temp);
    }
}
void Create_New_Array(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % 1000;
    }
}
int main(int argc, char* argv[])
{
    //int array[10] = {80, 116, 81, 205, 82, 68, 151, 20, 109, 100};
    int array[10];
    srand(time(NULL));
    Create_New_Array(array, 10);
    PRBTree root = NULL;
    int i;
    for (i = 0; i < 10; i++)
    {
        root = RB_InsertNode(root, array[i]);
    }
    Mid_Visit(root);
    // 随机删除一个结点
    int index = rand() % 10;
    printf("delete node %d\n", array[index]);
    root = RB_DeleteNode(root, array[index]);
    Mid_Visit(root);
    // 删除整颗树
    Mid_DeleteTree(root);
    return 0;
}
