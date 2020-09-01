#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
// 双链表
// 链表的节点
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// 添加节点
struct node *creat_node(int data)
{
    //申请堆空间存放节点
    struct node *p = (struct node *)malloc(sizeof(struct node));

    //堆空间检测是否申请正常
    if(NULL == p)
    {
        printf("malloc error!");
    }

    //清理堆空间
    memset(p, 0, sizeof(struct node));

    //填充链表
    p->data = data;
    p->next = NULL;
    p->prev = NULL;
}

// 头插入
void insert_head(struct node *pH, struct node *new)
{
    //1、新节点next指针指向原第一个有效节点
    new->next = pH->next;

    //2、新节点的prev指针指向头节点
    new->prev = pH;

    //注：只有在头节点之后存在有效节点的时候以下步骤才成立
    //3、原来第一个有效节点的prev指针指向新节点
    if(NULL != pH->next)
    pH->next->prev = new;

    //4、头节点的next指针指向新节点
    pH->next = new;

    //给头节点data存放节点数量
    pH->data += 1;
}

// 尾插入
void insert_tail(struct node *pH, struct node *new)
{
    //1、传入头节点指针
    struct node *p = pH;
    //2、找到尾结点
    while (NULL != p->next)
    {
        //节点的next指针不是空就跳到下一个节点
        p = p->next;
    }
    //跳出循环时即找到尾结点p
    //3、填充数据
    p->next = new;
    new->prev = p;
    pH->data += 1;
}

// 遍历节点
void traverse_node(struct node *pH)
{
    //传入头节点指针
    struct node *p = pH;
    //给个计数
    int cnt = 0;
    //类似节点遍历
    while (NULL != p->next)
    {
        p = p->next;
        cnt++;
        printf("No.%d node:pH->data = %d.\n", cnt, p->data);
    }
}

// 删除与所输入数值对应的节点,但是缺点是如果有多个数据同时出现只能删除第一个找到的数据
int delete_node(struct node *pH, int data)
{
    //传入头节点指针
    struct node *p = pH;
    //类似节点遍历
    while (NULL != p->next)
    {
        //跳过头节点
        p = p->next;
        //判断有效节点是否和传入参数data相等
        if(p->data == data)
        {
            //区别对待尾结点和普通节点
            if(NULL == p->next)
            {
                //尾结点
                p->prev->next = NULL;
            }
            else
            {
                //普通节点
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            //释放堆空间
            free(p);
            //给头指针中的计数值减一
            pH->data -= 1;
            return 0;
        }
    }
    //循环结束没有找到则打印输出信息
    printf("没有找到对应节点\n");
    return -1;
}


int main(void)
{
    struct node* pH = creat_node(0);
    insert_tail(pH, creat_node(14));
    insert_tail(pH, creat_node(15));
    insert_tail(pH, creat_node(16));
    printf("存在%d个节点.\n", pH->data);
    printf("----------------删除前----------------\n");
    traverse_node(pH);

    delete_node(pH, 16);

    printf("存在%d个节点.\n", pH->data);
    printf("----------------删除后----------------\n");
    traverse_node(pH);

/*     //手动遍历节点
    printf("pH->data = %d.\n", pH->next->data);
    printf("pH->data = %d.\n", pH->next->next->data);
    printf("pH->data = %d.\n", pH->next->next->next->data); */


    return 0;
}
