#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct TreapNode* Tree;
typedef int ElementType;
struct TreapNode
{
    ElementType val; //结点值
    int priority;   //优先级
    Tree lchild;+
    Tree rchild;
    TreapNode(int val = 0, int priority = 0) //默认构造函数
    {
        lchild = rchild = NULL;
        this->val = val;
        this->priority = priority;
    }
};
Tree search(Tree&, ElementType);
void right_rotate(Tree&);
void left_rotate(Tree&);
bool insert_val(Tree&, Tree&);
bool insert(Tree&, ElementType, int);
bool remove(Tree&, ElementType);


//查找函数
Tree search(Tree& root, ElementType val)
{
    if (!root)
        return NULL;
    else if (root->val > val)
        return search(root->lchild, val);
    else if (root->val < val)
        return  search(root->rchild, val);
    return root;
}
//插入函数
bool insert(Tree& root, ElementType val = 0, int priority = 0)
{
    Tree node = new TreapNode(val, priority);
    return insert_val(root, node);
}
//内部插入函数
//参数:根结点，需插入的结点
bool insert_val(Tree& root, Tree& node)
{
    if (!root)
    {
        root = node; //插入
        return true;
    }
    else if (root->val > node->val)
    {
        bool flag = insert_val(root->lchild, node);
        if (root->priority > node->priority) //检查是否需要调整
            right_rotate(root);
        return flag;
    }
    else if (root->val < node->val)
    {
        bool flag = insert_val(root->rchild, node);
        if (root->priority > node->priority) //检查是否需要调整
            left_rotate(root);
        return flag;
    }
    //已经含有该元素，释放结点
    delete node;
    return false;

}
//右旋转
void right_rotate(Tree& node)
{
    Tree temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node = temp;
}
//左旋转
void left_rotate(Tree& node)
{
    Tree temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    node = temp;
}

//删除函数
bool remove(Tree& root, ElementType val)
{
    if (root == NULL)
        return false;
    else if (root->val > val)
        return remove(root->lchild, val);
    else if (root->val < val)
        return remove(root->rchild, val);
    else //找到执行删除处理
    {

        Tree* node = &root;
        while ((*node)->lchild && (*node)->rchild)  //从该结点开始往下调整
        {
            if ((*node)->lchild->priority < (*node)->rchild->priority) //比较其左右孩子优先级
            {
                right_rotate(*node); //右旋转
                node = &((*node)->rchild); //更新传入参数，进入下一层
            }
            else
            {
                left_rotate(*node); //左旋转
                node = &((*node)->lchild); //更新传入参数，进入下一层
            }
        }

        //最后调整到（或者本来是）叶子结点，或者只有一个孩子的情况，可以直接删除了
        if ((*node)->lchild == NULL)
            (*node) = (*node)->rchild;
        else if ((*node)->rchild == NULL)
            (*node) = (*node)->lchild;
        return true;
    }
}


//前序
void PreOrder(Tree root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    PreOrder(root->lchild);
    PreOrder(root->rchild);
}
//中序
void InOrder(Tree root)
{
    if (root == NULL)
        return;
    InOrder(root->lchild);
    printf("%d ", root->val);
    InOrder(root->rchild);
}
int main()
{
    Tree root = NULL;

    insert(root, 11, 6);
    insert(root, 7, 13);
    insert(root, 14, 14);
    insert(root, 3, 18);
    insert(root, 9, 22);
    insert(root, 18, 20);
    insert(root, 16, 26);
    insert(root, 15, 30);
    insert(root, 17, 12);
    printf("插入:\n");
    printf("前序:");
    PreOrder(root);
    printf("\n");
    printf("中序:");
    InOrder(root);
    printf("\n");
    printf("删除:\n");
    remove(root, 11);
    printf("前序:");
    PreOrder(root);
    printf("\n");
    printf("中序:");
    InOrder(root);
    printf("\n");
    return 0;
}
