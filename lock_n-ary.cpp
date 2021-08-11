#include<bits/stdc++.h>
using namespace std;

class nary
{
public:
	string val;
	bool islock;
	bool canlock;
	int uid;
	nary *parent;
	vector<nary*> child;
};

bool islockk(nary* root)
{
	return root->islock;
}

nary* newnode(string val)
{
	nary* temp=new nary();
	temp->val=val;
	temp->uid=-1;
	temp->islock=false;
	temp->canlock=true;
	return temp;
}

nary* create_nary(nary* root,vector<string> v,int m,int n)
{
	if(n<=0||m<=0)return root;
    
    nary* temp=NULL;
    queue<nary*> q;
	for(int i=0;i<n;)
	{
		int p=0;
		if(i==0)
		{
			root=newnode(v[i]);
			root->parent=NULL;
			i=1;
			temp=root;
		}
		else
		{
			for(int k=i;k<min(i+m,n-i+1);k++)
			{
				temp->child.push_back(newnode(v[k]));
				temp->child[p]->parent=temp;
				q.push(temp->child[p]);
				p++;
			}
			temp=q.front();
			q.pop();
			i+=m;	
		}
	}

	return root;

}


bool lock(nary* root,int uid,string s,int m)
{
	if(root==NULL)return false;
	if(root->canlock==false) return false;

	nary* temp=root;
	nary* temp1=NULL;
	if(root->val==s)
		{
			if(islockk(root)||!root->canlock) return false;
			else 
			{
			  root->uid=uid;
			  root->canlock=false;
			  root->islock=true;
			  return true;                     
		    }
		}

	else
	{
		queue<nary*> q;
		q.push(temp);
		int flag=0;
	while(!q.empty())
	{
	 temp=q.front();
	 q.pop();
	for(int k=0;k<m;k++)
	{
			if(temp->child[k]->val==s)
			{
				temp1=temp->child[k];
				flag=1;
			    break;
			}
			q.push(temp->child[k]);
	}
       if(flag==1)
       {
       	break;
       }
    }
     nary* temp2=temp1;
    while(temp1!=NULL)
    {
     
      if(islockk(temp1)&&!temp1->canlock)
       { 
    	return false;
       }
       temp1=temp1->parent;
    }
      
     temp2->uid=uid;
     temp2->islock=true;
     temp2->canlock=false;
     temp2=temp2->parent;
    while(temp2!=NULL)
    {
     temp2->islock=false;
     temp2->canlock=false;
     temp2=temp2->parent;
    }
     return true;

    }
}

bool unlock(nary* root,string s,int m,int uid)
{
	if(root==NULL)return false;

    if(root->val==s)
		{
			if(islockk(root)==false||root->uid!=uid) return false;
			else 
			{
			  root->uid=-1;
			  root->canlock=true;
			  root->islock=false;
			  return true;                     
		    }
		}


	nary* temp=root;
	nary* temp1=NULL;
    queue<nary*> q;
	q.push(temp);
	int flag=0;
	while(!q.empty())
	{
	 temp=q.front();
	 q.pop();
	for(int k=0;k<m;k++)
	{
			if(temp->child[k]->val==s)
			{
				temp1=temp->child[k];
				flag=1;
			    break;
			}
			q.push(temp->child[k]);
	}
       if(flag==1)
       {
       	break;
       }
    }


    if(islockk(temp1)==false||temp1->uid!=uid) return false;

     temp1->islock=false;
     temp1->canlock=true;
     temp1->uid=-1;
    nary* temp2=temp1;
    temp2=temp2->parent;
    while(temp2!=NULL)
    {
    	temp2->canlock=true;
    	temp2=temp2->parent;
    }
     
     return true;
}
 


int main()
{

        nary* root=NULL;
        vector<string> v{"rah","guh","asd","asdf","sdfg","sddfff","sds"};
        root=create_nary(root,v,2,7);
        lock(root,2,"rah",2);
        cout<<unlock(root,"rah",2,2);
        cout<<lock(root,3,"guh",2);
        
        return 0;
}
