#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
// ˫����
// ����Ľڵ�
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

// ��ӽڵ�
struct node *creat_node(int data)
{
    //����ѿռ��Žڵ�
    struct node *p = (struct node *)malloc(sizeof(struct node));

    //�ѿռ����Ƿ���������
    if(NULL == p)
    {
        printf("malloc error!");
    }

    //����ѿռ�
    memset(p, 0, sizeof(struct node));

    //�������
    p->data = data;
    p->next = NULL;
    p->prev = NULL;
}

// ͷ����
void insert_head(struct node *pH, struct node *new)
{
    //1���½ڵ�nextָ��ָ��ԭ��һ����Ч�ڵ�
    new->next = pH->next;

    //2���½ڵ��prevָ��ָ��ͷ�ڵ�
    new->prev = pH;

    //ע��ֻ����ͷ�ڵ�֮�������Ч�ڵ��ʱ�����²���ų���
    //3��ԭ����һ����Ч�ڵ��prevָ��ָ���½ڵ�
    if(NULL != pH->next)
    pH->next->prev = new;

    //4��ͷ�ڵ��nextָ��ָ���½ڵ�
    pH->next = new;

    //��ͷ�ڵ�data��Žڵ�����
    pH->data += 1;
}

// β����
void insert_tail(struct node *pH, struct node *new)
{
    //1������ͷ�ڵ�ָ��
    struct node *p = pH;
    //2���ҵ�β���
    while (NULL != p->next)
    {
        //�ڵ��nextָ�벻�ǿվ�������һ���ڵ�
        p = p->next;
    }
    //����ѭ��ʱ���ҵ�β���p
    //3���������
    p->next = new;
    new->prev = p;
    pH->data += 1;
}

// �����ڵ�
void traverse_node(struct node *pH)
{
    //����ͷ�ڵ�ָ��
    struct node *p = pH;
    //��������
    int cnt = 0;
    //���ƽڵ����
    while (NULL != p->next)
    {
        p = p->next;
        cnt++;
        printf("No.%d node:pH->data = %d.\n", cnt, p->data);
    }
}

// ɾ������������ֵ��Ӧ�Ľڵ�,����ȱ��������ж������ͬʱ����ֻ��ɾ����һ���ҵ�������
int delete_node(struct node *pH, int data)
{
    //����ͷ�ڵ�ָ��
    struct node *p = pH;
    //���ƽڵ����
    while (NULL != p->next)
    {
        //����ͷ�ڵ�
        p = p->next;
        //�ж���Ч�ڵ��Ƿ�ʹ������data���
        if(p->data == data)
        {
            //����Դ�β������ͨ�ڵ�
            if(NULL == p->next)
            {
                //β���
                p->prev->next = NULL;
            }
            else
            {
                //��ͨ�ڵ�
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
            //�ͷŶѿռ�
            free(p);
            //��ͷָ���еļ���ֵ��һ
            pH->data -= 1;
            return 0;
        }
    }
    //ѭ������û���ҵ����ӡ�����Ϣ
    printf("û���ҵ���Ӧ�ڵ�\n");
    return -1;
}


int main(void)
{
    struct node* pH = creat_node(0);
    insert_tail(pH, creat_node(14));
    insert_tail(pH, creat_node(15));
    insert_tail(pH, creat_node(16));
    printf("����%d���ڵ�.\n", pH->data);
    printf("----------------ɾ��ǰ----------------\n");
    traverse_node(pH);

    delete_node(pH, 16);

    printf("����%d���ڵ�.\n", pH->data);
    printf("----------------ɾ����----------------\n");
    traverse_node(pH);

/*     //�ֶ������ڵ�
    printf("pH->data = %d.\n", pH->next->data);
    printf("pH->data = %d.\n", pH->next->next->data);
    printf("pH->data = %d.\n", pH->next->next->next->data); */


    return 0;
}
