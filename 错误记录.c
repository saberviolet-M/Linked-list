/* 双链表 */
遍历链表:
/* error1： */
没有循增量
void traverse_node(struct node *pH)
{
    //传入
    struct node *p = pH->next;
    //类似节点遍历
    while (NULL != p->next)
    {
        printf("pH->data = %d.\n", p->data);
        p->next;
    }
}
p->next;  >>>>  p = p->next;
PS：循环结构最重要有3——初始条件，终止条件，循环增量

/* error2： */
缺失尾结点
void traverse_node(struct node *pH)
{
    //传入
    struct node *p = pH->next;
    //类似节点遍历
    while (NULL != p->next)
    {
        printf("pH->data = %d.\n", p->data);
        p = p->next;
    }
}
1、struct node *p = pH->next;  >>>>      struct node *p = pH;
2、进入后先跳过头节点，然后打印输出信息
printf("pH->data = %d.\n", p->data);  >>>>  p = p->next
p = p->next;                          >>>>  printf("pH->data = %d.\n", p->data);

/* error3： */
void traverse_node(struct node *pH)
{
    //传入头节点指针
    struct node *p = pH;
    //给个计数
    int cnt = 0;//←←←←←←←←←←←←
    //类似节点遍历
    while (NULL != p->next)
    {
        p = p->next;
        cnt++;
        printf("No.%d node:pH->data = %d.\n", cnt, p->data);
    }
}
/* 错误提示：
            [Error] stray '\243' in program
            [Error] stray '\273' in program
            [Error] expected ',' or ';' before 'while'
IDE:DevC++5.11中↑信息表示使用了中文的“，”or“；”逗号或分号 */

