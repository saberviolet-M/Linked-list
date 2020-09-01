#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
// ������
// ����Ľڵ�
struct node
{
    int data;
    struct node *next;
};

// ��ӽڵ�
struct node *create_node(int data)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if(NULL == p)
    {
        printf("malloc error.\n");
    }
    memset(p, 0, sizeof(struct node));
    p->data = data;
    p->next = NULL;
}

// ͷ����
void insert_head(struct node *pH, struct node *new)
{
    new->next = pH->next;
    pH->next = new;
    pH->data += 1;
}

// β����
void insert_tail(struct node *pH, struct node *new)
{
    struct node *p = pH;
    while (NULL != p->next)
    {
        p = p->next;
    }
    p->next = new;
    pH->data += 1;
}

// �����ڵ�
void traverse_node(struct node *pH)
{
    struct node *p = pH;
    int cnt = 0;
    while (NULL != p->next)
    {
        p = p->next;
        cnt += 1;
        printf("�ڵ�%d,p->data = %d.\n", cnt, p->data);
    }  
}


// ɾ������������ֵ��Ӧ�Ľڵ�,����ȱ��������ж������ͬʱ����ֻ��ɾ����һ���ҵ�������
int delete_node( struct node *pH, int data)
{
    struct node *p = pH;
    struct node *prev = NULL;
    while (NULL != p->next)
    {
        prev = p;
        p = p->next;
        if(p->data == data)
        {
            if(NULL == p->next)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = p->next;
            }
            free(p);
            pH->data -= 1;
            return 0;
        }
    } 
    printf("û���ҵ���Ӧ�ڵ㡣\n");
    return -1;
}

int delete1_node( struct node *pH, int data)
{
    struct node *p = pH;
    struct node *prev = NULL;
    int state_flag = 0;
    while (NULL != p->next)
    {
        prev = p;
        p = p->next;
        if(p->data == data)
        {
            state_flag = 1;
            if(NULL == p->next)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = p->next;
            }
            free(p);
            p = prev;
            pH->data -= 1;
        }
    } 
    if(state_flag)
        return 0;
    printf("û���ҵ���Ӧ�ڵ㡣\n");
    return -1;
}

int main(void)
{
    struct node *pH = create_node(0);
    insert_tail(pH, create_node(34));
    insert_tail(pH, create_node(35));
    insert_tail(pH, create_node(36));
    printf("����%d���ڵ�.\n", pH->data);
    traverse_node(pH);
    delete_node(pH, 36);

    printf("����%d���ڵ�.\n", pH->data);
    traverse_node(pH);
    insert_tail(pH, create_node(34));
    insert_tail(pH, create_node(35));
    insert_tail(pH, create_node(36));

    printf("����%d���ڵ�.\n", pH->data);
    traverse_node(pH);
    delete1_node(pH, 35);
    delete1_node(pH, 34);
    
    printf("����%d���ڵ�.\n", pH->data);
    traverse_node(pH);


/*     printf("p->data = %d.\n", pH->next->data);
    printf("p->data = %d.\n", pH->next->next->data);
    printf("p->data = %d.\n", pH->next->next->next->data); */


    return 0;
}
