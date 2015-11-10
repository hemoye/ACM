
/**********ǰ�����������**********/
void PreOrder( BiTreePtr T )
{
    if ( T == NULL )
        return ;

    printf("%c", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);

    return ;
}
/**********�������������**********/
void InOrder( BiTreePtr T )
{
    if ( T == NULL )
        return ;

    PreOrder(T->lchild);
    printf("%c", T->data);
    PreOrder(T->rchild);

    return ;
}
/**********�������������**********/
void PostOrder( BiTreePtr T )
{
    if ( T == NULL )
        return ;

    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%c", T->data);

    return ;
}
