
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
int data;
struct node *left,*right,*next;
} node;


node* create(int k)
{
   node *new_node = (node*)(malloc)(sizeof(node));
    new_node->left = new_node->next = new_node->right = NULL ;
    new_node->data = k;
    return (new_node);
}

void deletenode(node* head,int count,int target);
int getleavesnodes(node* vt);
void main()
{
    int ct =1;
    int dt=0;
    int flag =0;
    int inp=0;
    int cn=0;
    int leaves=0;
    node *head_2 = NULL;
    node *ptr,*tmp,*cur;
    printf("\nRange : ");
    scanf("%d",&inp);

    int k,i,j,p;
    printf("\n inputs  : ");


        scanf("%d",&k);
        head_2 = ptr =  create(k);

    cur =tmp =  head_2;

                                                                // insertion takes place here !!
    while(1)
    {
     while(cur!=NULL && ct>0)
    {
            if(cur->next)
        {
            ptr = cur;
        }
        else
            ptr = head_2;

        if(cn++ == (inp-1))
          {
              flag=1;
              break;
         }
         scanf("%d",&i);

          tmp->next = ptr->left = create(i);
          tmp = tmp->next;

        if(cn++ == (inp-1))
           {
               flag =1;
           break;
        }
        scanf("%d",&j);
           tmp->next = ptr->right = create(j);
            tmp = tmp->next;

              --ct;
        cur = cur->next;
            }
            ct = 2;
            if(flag ==1)
                break;
          }


          cur =head_2;
          printf("\noutput : ");                                    // Displaying the tree
          while(cur != NULL)
          {
              printf("\t%d",cur->data);
              cur= cur->next;
          }


         printf("\n\nEnter the position of the data you want to delete from the tree : ");
         scanf("%d",&dt);
        deletenode(head_2,0,dt);


        leaves = getleavesnodes(head_2);
        printf("\nNo of leaves remaining in the tree = %d\n",leaves-1);
}
void deletenode(node* head,int count,int target)                                //  deletion at specific position
{
    while(head!=NULL)
    {

            if(count == (target))
            {
            free(head);
                break;
            }
            head = head->next;
            ++count;
        }
}
int getleavesnodes(node* vt)                                                    //  count the no of leaflets
{
    if (vt == NULL)
        return 0;

    if ((vt->left == NULL ) && (vt->right == NULL))
        return 1;
    else
        return(getleavesnodes(vt->left) + getleavesnodes(vt->right));
}
