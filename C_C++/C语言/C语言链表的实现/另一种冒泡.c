struct student *BubbleSort(struct student *head)
{
    struct student *endpt;
    struct student *p;
    struct student *p1;
    struct student *p2;
    p1=(struct student *)malloc(LEN);
    p1->next=head;
    head=p1;
    for (endpt=NULL; endpt!=head; endpt=p)
    {
        for (p=p1=head; p1->next->next!=endpt; p1=p1->next)
        {
            if (p1->next->num > p1->next->next->num)
            {
                p2 = p1->next->next;
                p1->next->next = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p = p1->next->next;
            }
        }
    }
    p1 = head;
    head = head->next;
    free(p1);
    p1= NULL;
    return head;
}
