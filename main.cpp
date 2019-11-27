#include <iostream>
using namespace std;
class node_d
{
   private: node_d*prev;
            node_d*next;
            int data;
            friend class doubly_linked_list;
};
class doubly_linked_list
{
    private: node_d*head;
             node_d*last;
    public:  doubly_linked_list()
             {
                 head=0;
                 last=0;
             }
             ~doubly_linked_list()
              {

              }
            void create(int x)
            { node_d*n=new node_d;
              n->data=x;
                if(head==0)
                {
                    head=n;
                    head->next=0;
                    head->prev=0;


                }
                else
                {
                    node_d*p=head;
                    while(p->next)
                       {p=p->next;}
                    p->next=n;
                    n->next=0;
                    n->prev=p;
                }
                last=n;
            }
            void display()
            {
                node_d*p=head;
                while(p)
                {
                    cout<<p->data;
                    if(p->next!=0)
                        cout<<"->";
                    p=p->next;
                }
            }
            void rev_display()
            {
                node_d*p=last;
                while(p!=0)
                {
                    cout<<p->data;
                    if(p->prev!=0)
                        cout<<"->";
                    p=p->prev;
                }
            }

            int length()
            {
                node_d*p=head;
                int c=0;
                while(p)
                { c++;
                  p=p->next;
                }
                return c;

            }
            void Insert(int index,int val)
            {
                if(index<0||index>length())
                    return;
                    node_d*p=head;
                    node_d*n=new node_d;
                    n->data=val;
                if(index==0)
                {
                    if(p==0)
                    {
                        head=n;
                        head->next=head->prev=0;
                        last=head;
                    }
                    else
                    {  n->prev=p->prev;
                        p->prev=n;
                        n->next=p;
                        head=n;

                    }
                }
                else
                    {for(int i=0;i<index-1;i++)
                 p=p->next;
                 n->next=p->next;
                 p->next=n;
                 n->prev=p;
                 if(n->next!=0)
                 n->next->prev=n;
                 else
                    last=n;





            }}
            int del(int index)
            {
                if(index<=0||index>length())
                    return -1;
                    node_d*p=head;
                    int d=0;
                if(index==1)
                {
                    if(p->next==0)
                    {
                       d=p->data;
                       head=last=0;
                       delete p;
                       return d;

                    }
                    else
                    {
                        d=p->data;
                        head=p->next;
                        head->prev=0;
                        delete p;
                        return d;
                    }
                }
                else
                {
                    for(int i=0;i<index-1;i++)
                    p=p->next;
                   p->prev->next=p->next;
                   if(p->next)
                   p->next->prev=p->prev;
                   else
                    last=p->prev;
                   d=p->data;
                   delete p;
                   return d;


                }
            }
            void Reverse()
            {
                node_d*p=head;
                while(p)
                {node_d*q=p->prev;
                   if(q==0)
                    last=p;
                   p->prev=p->next;
                    if(p->prev==0)
                        head=p;
                   p->next=q;
                   p=p->prev;

                   }


            }
            void create_circular()
            {

                last->next=head;
                head->prev=last;

            }
            int check_circular()
            {
                node_d*p=head;
                if(p->prev)
                    return 1;
                return 0;
            }
            void display_circular()
            {
                node_d *p=head;
                do{
                    cout<<p->data;
                    if(p->next!=head)cout<<"->";
                    p=p->next;
                }while(p!=head);
            }




};

class node
{
   private: int data;
          node *next;
          friend class linked_list;
};
class linked_list
{
private: node*head;
         node*last;
public: linked_list()
         {
            head=0;
            last=0;
         }

         void add(int x)
         {


             node*n=new node;
             n->data=x;
             node*p=head;

             if(p==0)
             {
                 head=n;
                 }

             else
             {
               last->next=n;

             }
             n->next=0;
             last=n;
         }
         void display()
         { cout<<endl;
             node*p=head;
             while(p!=0)
             {
                 cout<<p->data;
                 if(p->next!=0)
                    cout<<"->";
                 p=p->next;
             }
         }
         void rec_display(node*p)
         {
             if(p!=0)
                {
                cout<<p->data;
                if(p->next!=0)
                cout<<"->";
                rec_display(p->next);
                }

         }
             void rec_reverse(node*p)
         {
             if(p!=0)
                {
                rec_reverse(p->next);
                cout<<p->data;
                if(p!=head)
                cout<<"->";

                }

         }
         node* get_head()
         {
             return head;
         }
         int count_elements()
         {
             int cnt=0;

                node*p=head;
                while(p!=0)
                {
                    cnt++;
                    p=p->next;
                }
                return cnt;

         }
         int count_rec(node*p)
         {
             if(p==0)
                return 0;

            else{
                 return count_rec(p->next)+1;
               }


         }
         int sum()
         {
             int sum=0;
             node*p=head;
             while(p!=0)
             {
               sum+=p->data;
               p=p->next;
             }
             return sum;
         }
         int sum_rec(node*p)
         {
             if(p)
             {
                 return p->data+sum_rec(p->next);
             }
             else
                return 0;
         }
         int Max()
         {
             node*p=head;
             int m=INT_MIN;
             while(p!=0)
             {
                 if(p->data>m)
                    m=p->data;
                 p=p->next;
             }
             return m;
         }
         int Max_rec(node*p)
         { int M=INT_MIN;
             if(!p)
             {
                 return M;
             }
             M=Max_rec(p->next);

            return M>p->data?M:p->data;

         }
      int Min_rec(node*p)
      {
       int M=INT_MAX;
       if(!p)return M;
       M=Min_rec(p->next);
       return M<p->data?M:p->data;
      }
      void linear_search()
      {
          int val;
          cout<<endl<<"enter value to be searched ";
          cin>>val;
          node*p=head;
          int c=0;
          int f=0;
          node*q=0;
          while(p)
          { c++;
              if(p->data==val)
                 {cout<<endl<<"found at: "<<c;
                  f=1;
                  if(q)
                  {


                  q->next=p->next;
                  p->next=head;
                  head=p;
                  }

                  break;
                  }
                  q=p;
            p=p->next;
          }

          if(!c||!f)
            cout<<endl<<"not found";


      }
      node* linear_search_rec(node*p,int val)
      {
          if(!p)
          {
              return 0;
          }
          if(val==p->data)
            return p;

            return linear_search_rec(p->next,val);
      }
      void add_atfront(int val)

      {
          node*n=new node;
          n->data=val;
          n->next=head;
          head=n;
      }

      void Insert()
      {
          cout<<endl<<"enter index and value ";
          int index,val;
          cin>>index>>val;
          if(index<0||index>count_elements())
            return;

         if(index==0)
         { add_atfront(val);}

         else if(index>0)
         {

             node*p=head;
             for(int i=0;i<index-1&&p;i++)
             {

                p=p->next;
             }

         if(p)
         {

             node*n=new node;
             n->data=val;
             n->next=p->next;
             p->next=n;
         }}}

    void insert_inSorted()
    {
        int x;
        cout<<"enter element ";
        cin>>x;
        cout<<endl;
           if(head==0)
            add(x);

        else if(x<head->data)
        add_atfront(x);

        else if(x>last->data)
        add(x);
        else
        { node*p=head;
         while(p)
         {
            if(x>p->data&&x<p->next->data)
               {
                node*n=new node;
                n->data=x;
                n->next=p->next;
                p->next=n;
               }
               p=p->next;
         }
        }

    }
    int del_by_val(int val)
    { int d=-1;
        if(val==head->data)
        { node*temp=head;

            head=head->next;
            d=temp->data;
            delete temp;
            temp=0;
            return d;

        }
        else
        { node*p=head;
          node*q=p;
            while(p)
            {
                if(p->data==val)
                {
                 q->next=p->next;
                 d=p->data;
                 delete p;
                 p=0;
                 return d;
                }

                q=p;
                p=p->next;
            }
        }
        return d;
    }
     int del_by_index(int index)
    { int d=-1;
      if(index<1||index>count_elements())
        return d;
        if(index==1)
        { node*temp=head;

            head=head->next;
            d=temp->data;
            delete temp;
            temp=0;
            return d;

        }
        else
        { node*p=head;
          node*q=0;

            for(int i=1;p&&i<index;i++)
            {
                q=p;
                p=p->next;
            }

                 q->next=p->next;
                 d=p->data;
                 delete p;
                 p=0;
                 return d;

        }
    }
    int isSorted()
    {
        node*p=head->next;
        node*q=head;
        while(p)
        {
            if(q->data>p->data)
                return 0;
            q=p;
            p=p->next;

        }
        return 1;

    }
    void remove_contiguous_duplicates()
    {
        node*p=head;
        node*q=head->next;
        while(q)
        {
            if(q->data!=p->data)
            {
                p=q;
                q=q->next;
            }
            else
            {
                p->next=q->next;
                delete q;
                q=p->next;
            }

        }
        last=p;
    }
    void Reverse()
    {
        node*p=0;
        node*prev=0;
        node*t=head;
        while(t)
        {
             prev=p;
             p=t;
             t=t->next;
             p->next=prev;
             if(p==head)last=p;
             if(t==0)head=p;
        }
    }
    void Reverse_rec(node*p,node*q)
    {
        if(p)Reverse_rec(p->next,p);
        else {head=q;return;}
        p->next=q;

    }
    void concatenate(linked_list &l1)
    {
        node*p=head;
        while(p->next)
        {
            p=p->next;
        }
        p->next=l1.head;

    }
    void merge_lists(linked_list &l1)
    {
        node*p=head;
        node*q=0;
        node*p1=l1.head;
        node*q1=0;
        while(p&&p1)
        {
            if(p->data<p1->data)
            {
                q=p;
                p=p->next;
            }
            else if(p->data>p1->data)
            {
                if(p==head)
                {
                    q1=p1->next;
                    p1->next=p;
                    head=p1;
                    q=p1;
                    p1=q1;
                }
                else
                {
                    q1=p1->next;
                    p1->next=p;
                    q->next=p1;
                    q=p1;
                    p1=q1;
                }
            }
            else
            {   q=p;
                p=p->next;
                p1=p1->next;
            }

        }
        if(q&&!p)
        {
            q->next=p1;
        }

    }
    void Merge(linked_list *l1)
    {
        node*p=head;
        node*q=l1->head;
        node*lastm=0;
        while(p&&q)
        {
            if(p->data<q->data)
            {   if(lastm==0)
                {lastm=p;

                    head=lastm;
                }
                else {lastm->next=p;
                       lastm=p;
                        }

                 p=p->next;

            }
            else if(p->data>q->data)
            {
                if(lastm==0)
                {lastm=q;
                head=lastm;
                }
                else
                {
                    lastm->next=q;
                    lastm=q;
                }
                q=q->next;

            }
            else
            {
                lastm->next=p;
                lastm=p;
                p=p->next;
                node*t=q;
                q=q->next;
                delete t;
                t=0;

            }
            lastm->next=0;
        }
        if(p)
        {lastm->next=p;
          lastm=last;
        }
        else
        {
            lastm->next=q;
            lastm=l1->last;
        }
        lastm->next=0;

    }
    int find_loop()
    {
        node*p=head;
        node*f=head;

        do
        {
            p=p->next;
            f=f->next;

            f=f==0?0:f->next;
        }while(f&&f!=p);
        return p==f?1:0;



    }
    void create_loop()
    {
       node *p=head;
       int x;
       cout<<endl<<"enter the value already in the list to create a loop ";
       cin>>x;
       while(p->data!=x)
       {
           p=p->next;
       }
       last->next=p->next;
    }
    void add_circular(int d)
    {

        if(head==0)
        {   node*n=new node;
            n->data=d;
            n->next=0;
            head=n;
            head->next=head;
            last=head;
        }
        else
        {
            node*n=new node;
            n->data=d;
            n->next=head;
            last->next=n;
            last=n;

        }



    }
    int check_circular()
    {
        node*p=head;
        while(p->next!=head&&p->next!=0)
        {
            p=p->next;
        }
        if(p->next==head)
            return 1;
        return 0;
    }

void display_circular()
{ cout<<endl;
    node*p=head;
    do{
        cout<<p->data;
        if(p->next!=head)
            cout<<"->";
        p=p->next;
      }while(p!=head);
      cout<<endl;
}
void display_circular_rec1(node*p)
{

    if(p->next==head)
    {cout<<p->data;
     return;}
     cout<<p->data<<"->";
     display_circular_rec(p->next);

}
void display_circular_rec(node*p)
{
    static int flag=0;
    if(p!=head||flag==0)
    {cout<<p->data;
     if(p->next!=head)
        cout<<"->";

     flag=1;
     display_circular_rec(p->next);}
     flag=0;

}
int count_circular()
{
    node*p=head;
    int c=0;
    do{c++;p=p->next;}while(p!=head);
    return c;
}

void insert_circular(int index,int val)
{

    if(index<0||index>count_circular())
        return;
    node*n=new node;
    n->data=val;
    node*p=head;
    if(head==0)
        add_circular(val);
    if(index==0)
    {
        n->next=head;
        head=n;
        last->next=head;
    }
    else
    {   int i=0;
         node*q=0;
        do{ q=p;
            p=p->next;
            i++;
        }while(i<index);
        n->next=p;
        q->next=n;
        if(q==last)
            last=n;
    }
}
int delete_circular(int index)
{  int d=-1;
    if(index<1||index>count_circular())
        return d;
        node*p=head;

    if(index==1)
    {
        if(p->next==head)
           {  d=p->data;
               delete p; return d;}
        else
          { d=p->data;
            head=p->next;
            last->next=head;
            delete p;
             return d;}


    }
    else
    { int i=1;
      node*q=0;
        do{q=p;p=p->next; i++;}while(i<index);
        q->next=p->next;
        d=p->data;
        delete p;
        return d;


    }

}
  void middle()
  {
      node*p=head;
      int c=count_elements();
      if(c%2==0)
      {
          c=c/2;
      }
      else
        c=c/2+1;
      for(int i=0;i<c-1;i++)
      p=p->next;
      int d=p->data;
      cout<<endl;
      cout<<"middle node is at: "<<p<<" data is: "<<d;


  }
  void middle_singleScan()
  {
      node*p=head;
      node*f=head;
      while(f)
      {

          f=f->next;
          if(f)f=f->next;
          if(f)p=p->next;

      }
      int d=p->data;
      cout<<endl;
      cout<<"middle node is at: "<<p<<" data is: "<<d;

  }
};


int main()
{int ch;
 linked_list l;
  linked_list lc;
  doubly_linked_list d;
  linked_list l1;
     do{
  cout<<"       linked list    ";
  cout<<endl;
  cout<<endl;
  cout<<"1. singly linked list"<<endl;
  cout<<"2. circular linked list"<<endl;
  cout<<"3. doubly linked list"<<endl;
  cout<<"4. Exit"<<endl;

  cout<<endl<<endl;
  cout<<"Enter choice ";
  cin>>ch;
  cout<<endl;
  switch(ch)
  {
      case 1:int ch1;
             do{ cout<<endl<<endl;
              cout<<"1.  Add "<<endl;
              cout<<"2.  Display"<<endl;
              cout<<"3.  Sum"<<endl;
              cout<<"4.  Max"<<endl;
              cout<<"5.  Min"<<endl;
              cout<<"6.  Insert"<<endl;
              cout<<"7.  Search"<<endl;
              cout<<"8.  Check Sorted"<<endl;
              cout<<"9.  Insert in sorted"<<endl;
              cout<<"10. Delete"<<endl;
              cout<<"11. Remove contiguous duplicate"<<endl;
              cout<<"12. Reverse"<<endl;
              cout<<"13. Two list operation"<<endl;
              cout<<"14. Create loop"<<endl;
              cout<<"15. Check for loop"<<endl;
              cout<<"16. Middle element"<<endl;
              cout<<"17. Count"<<endl;
              cout<<"18. Go back"<<endl;


              cout<<"Enter choice ";
              cin>>ch1;
              cout<<endl;

                        int x,index;

              switch(ch1)
              {
                  case 1: cout<<"enter element "<<endl;

                           cin>>x;
                           l.add(x);
                           cout<<"success"<<endl;
                           break;
                  case 2: l.display();
                          break;
                  case 3:
                          cout<<"sum: "<<l.sum()<<endl;
                          break;
                  case 4:
                          cout<<"max: "<<l.Max()<<endl;;
                          break;
                 case 5:  cout<<"min: "<<l.Min_rec(l.get_head());
                           break;

                  case 6: l.Insert();
                          break;
                  case 7: l.linear_search();
                          break;
                  case 8: cout<<l.isSorted();
                          break;
                  case 9: l.insert_inSorted();
                          break;

                  case 10: cin>>index;
                           cout<<l.del_by_index(index)<<endl;
                           break;
                  case 11: l.remove_contiguous_duplicates();
                           cout<<"success"<<endl;
                           break;
                  case 12: l.Reverse();
                           cout<<"success"<<endl;
                           break;
                  case 13:
                           int ch2;

                           do{cout<<endl;
                           cout<<"1. Add in second"<<endl;
                           cout<<"2. Display second"<<endl;
                           cout<<"3. Insert in second"<<endl;
                           cout<<"4. Delete from second"<<endl;
                           cout<<"5. Concatenate in second"<<endl;
                           cout<<"6. Merge in second"<<endl;
                           cout<<"7. Go back"<<endl;


                              cout<<"Enter choice ";
                              cin>>ch2;
                              cout<<endl;

                            switch(ch2)
                            {
                                case 1: cout<<"enter element "<<endl;

                                       cin>>x;
                                       l1.add(x);
                                       cout<<"success"<<endl;
                                       break;
                                case 2:l1.display();
                                       break;
                                case 3:l1.Insert();
                                       break;
                                case 4:cin>>index;
                                       cout<<l1.del_by_index(index)<<endl;
                                       break;
                                case 5:l1.concatenate(l);
                                       cout<<"success"<<endl;
                                       break;
                                case 6: l1.Merge(&l);
                                        cout<<"success"<<endl;
                                        break;


                            }
                           }while(ch2>0&&ch2<7);
                            break;

                case 14: l.create_loop();
                         cout<<"success"<<endl;
                         break;
                case 15: if(l.find_loop())
                         cout<<"loop found"<<endl;
                         else
                            cout<<"not found"<<endl;
                         break;


                case 16: l.middle_singleScan();
                         break;
                case 17: cout<<l.count_elements();
                         break;
              }
              }while(ch1<18&&ch1>0);
              break;
   case 2: int ch3;
            do{cout<<endl;
                           cout<<"1. Add in circular"<<endl;
                           cout<<"2. Display circular"<<endl;
                           cout<<"3. Insert in circular"<<endl;
                           cout<<"4. Delete from circular"<<endl;

                           cout<<"5. Count circular"<<endl;


                           cout<<"6. Go back"<<endl;


                              cout<<"Enter choice ";
                              cin>>ch3;
                              cout<<endl;

                              int x1,index1;
                            switch(ch3)
                            {case 1: cout<<"enter element "<<endl;

                                       cin>>x1;
                                       lc.add_circular(x1);
                                       cout<<"success"<<endl;
                                       break;
                                case 2:lc.display_circular();
                                       break;
                                case 3:cout<<"enter index and value ";
                                       cin>>index1>>x1;
                                       cout<<endl;
                                       lc.insert_circular(index1,x1);
                                       break;
                                case 4:cout<<"enter index ";
                                       cin>>index1;
                                       cout<<endl;
                                       cout<<lc.delete_circular(index1)<<endl;
                                       break;
                                case 5: cout<<lc.count_circular();
                                         break;

                            }
                                  }while(ch3>0&&ch3<6);
                                  break;
    case 3: int ch4;
            do{ cout<<endl;
                           cout<<"1. Add "<<endl;
                           cout<<"2. Display"<<endl;
                           cout<<"3. Insert "<<endl;
                           cout<<"4. Delete"<<endl;
                           cout<<"5. Count"<<endl;
                           cout<<"6. Reverse "<<endl;
                           cout<<"7. Reverse display"<<endl;
                           cout<<"8. Go back"<<endl;


                              cout<<"Enter choice ";
                              cin>>ch4;
                              cout<<endl;
                              int xd,indexd;

                            switch(ch4)
                            {
                                case 1: cout<<"enter element "<<endl;

                                       cin>>xd;
                                       d.create(xd);
                                       cout<<"success"<<endl;
                                       break;
                                case 2:d.display();
                                       break;
                                case 3:cout<<"enter index and value ";
                                       cin>>indexd>>xd;
                                       cout<<endl;
                                       d.Insert(indexd,xd);
                                       break;
                                case 4:cout<<"enter index ";
                                       cin>>indexd;
                                       cout<<endl;
                                       cout<<d.del(indexd)<<endl;
                                       break;
                                case 5: cout<<d.length();
                                         break;
                                case 6: d.Reverse();
                                        cout<<"success";
                                        break;
                                case 7: d.rev_display();
                                        break;


                            }

                          }while(ch4>0&&ch4<8);
                          break;
}
}while(ch<4&&ch>0);
}
