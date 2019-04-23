//Here I am work with only lowercase Character(a-z)


#include<bits/stdc++.h>
using namespace std;

struct node{
    bool endpoint;
    node* next[26+1];

    node()
    {
        endpoint=false;
        for(int i=0;i<26;i++)
        {
            next[i]=NULL;
        }
    }

};

node* root=NULL;

void insert(char *str,int len)
{
    node* cur=root;

    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';

        if(cur->next[id]==NULL)
        {
            cur->next[id]=new node();
        }
        cur=cur->next[id];
    }
    cur->endpoint=true;
}


bool search(char* str,int len)
{
    node* cur=root;
    for(int i=0;i<len;i++)
    {
        int id=str[i]-'a';
        if(cur->next[id]==NULL)
        {
            return false;
        }
        cur=cur->next[id];
    }
    return cur->endpoint;
}

bool del(node* cur)
{
    for(int i=0;i<26;i++)
    {
        if(cur->next[i]!=NULL)
        {
            del(cur->next[i]);
        }
    }
    delete(cur);
}


int main()
{
    root=new node();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char str[50];
        cin>>str;
        insert(str,strlen(str));
    }
    cout<<"The number of Quires"<<endl;
    int query;
    cin>>query;

    for(int i=1;i<=query;i++)
    {
        char str1[50];
        cin>>str1;
        if(search(str1,strlen(str1)))
        {
            cout<<"Found"<<endl;
        }
        else
            cout<<"Not Found"<<endl;
    }
    return 0;
}
