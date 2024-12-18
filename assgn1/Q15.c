#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{ 
    int info ;
    struct node * next ;
};


struct node * start = NULL ;


struct node * create_node()
{
    struct node * temp ;
    temp =( struct node *) malloc ( sizeof ( struct node ));
    printf ( " Enter Node information " );
    scanf ( " % d " , &temp -> info );
    temp -> next = NULL ;
}

insert_node ()
{
    if( start == NULL )
        start = create_node ();
    else
    {
        struct node * ptr = start ;
        while ( ptr -> next != NULL )
            ptr = ptr -> next ;
        ptr -> next = create_node ();
        
    }
}

display ()
{
    struct node * ptr = start ;
    while ( ptr != NULL )
    {
        printf ( " \n % d " , ptr -> info );
        ptr = ptr -> next ; 
    }

}


int main ()
{

    insert_node ();
    insert_node ();
    insert_node ();
    display ();
    getch();
    return 0;

}