#include<iostream>
#include<conio>
using namespace std;
class Node
{
	public:
	int data;
	Node *left;
	Node *right;
};	
   void insert(int);
   Node* delele(Node *,int);
   Node* deltree(Node *);

   void preorder(Node *);
   void inorder(Node *);
   void postorder(Node *);

   Node* small(Node *);
   Node* large(Node *);

   int totnode(Node *);
   int extnode(Node *);
   int intnode(Node *);
   int height(Node *);

   Node* mirror(Node *);
   
Node *tree;   
int main()
{
	tree=NULL;
	int val, option;
	Node *ptr;
    do
    {
	    printf("\n *****MAIN MENU*****");
		printf("\n 1. INSERT AN ELEMENT");
		printf("\n 2. PREORDER TRAVERSAL");
		printf("\n 3. INORDER TRAVERSAL");
		printf("\n 4. POSTORDER TRAVERSAL");
		printf("\n 5. FIND SAMLLEST ELEMENT");
		printf("\n 6. FIND LARGEST ELEMENT");
		printf("\n 7. DELETE AN ELEMENT");
		printf("\n 8. COUNT TOTAL NO OF NODES");
		printf("\n 9. COUNT TOTAL EXTERNAL NODES");
		printf("\n 10. COUNT TOTAL INTERNAL NODES");
		printf("\n 11. DETERMINE HEIGHT IF A TREE");
		printf("\n 12. FIND MIRROR IMAGE OF TREE");
		printf("\n 13. DELETE THE TREE");
		printf("\n 14. EXIT");
		printf("\n Enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
		case 1:
			printf("\n Enter the number to be INSERTED ");
			scanf("%d", &val);
			insert(val);
			break;
		case 2:
		    cout<<"\n Elements in preorder are:"<<endl;
			preorder(tree);
			break;
		case 3:
		    cout<<"\n Elements in inorder are:"<<endl;
			inorder(tree);
			break;
		case 4:
		    cout<<"\n Elements in postorder are:"<<endl;
			postorder(tree);
			break;
		case 5:
			ptr=small(tree);
		    cout<<"\n Smallest element is "<<ptr->data<<endl;
			break;
		case 6:
			ptr=large(tree);
		    cout<<"\n Largest element is "<<ptr->data<<endl;
			break;
		case 7:
		    cout<<"\n Elements to be deleted:"<<endl;
			cin>>val;
			tree=delele(tree,val);
			break;
		case 8:
			val=totnode(tree);
		    cout<<"\n Total no of nodes:"<<val<<endl;
			break;
		case 9:
			val=extnode(tree);
		    cout<<"\n Total no of exterior node:"<<val<<endl;
			break;
		case 10:
			val=intnode(tree);
		    cout<<"\n total no of internal node:"<<val<<endl;
			break;
		case 11:
			cout<<"\nThe height of the tree is:"<<height(tree)<<endl;
			break;
		case 12:
			tree=mirror(tree);
			break;
		case 13:
			tree=deltree(tree);
			break;
		}
	}while(option != 14);
	return 0;
}
void insert(int x)
{
	Node *newnode=new Node();
	newnode->data=x;
	newnode->left=NULL;
	newnode->right=NULL;
	if(tree==NULL)
	{
		tree=newnode;
	}
	else
	{
		parptr=NULL;
		nodeptr=tree;
		while(nodeptr!=NULL)
		{
			parptr=nodeptr;
			if(x<nodeptr->data)
				nodeptr=nodeptr->left;
			else
				nodeptr=nodeptr->right;
		}
		if(x<parptr->data)
			parptr->left=newnode;
		else
			parptr->right=newnode;
	}
}
void preorder(Node *tree)
{
	if(tree!=NULL)
	{
		cout<<"\t"<<tree->data;
		preorder(tree->left);
		preorder(tree->right);
	}
}
void inorder(Node *tree)
{
	if(tree!=NULL)
	{
		inorder(tree->left);
		cout<<"\t"<<tree->data;
		inorder(tree->right);
	}
}
void postorder(Node *tree)
{
	if(tree!=NULL)
	{
		postorder(tree->left);
		postorder(tree->right);
		cout<<"\t"<<tree->data;
	}
}
Node* small(Node *tree)
{
	
	if(tree==NULL || tree->left==NULL)
		return tree;
	else
		return small(tree->left);
}
Node* large(Node *tree)
{
	
	if(tree==NULL ||tree->right==NULL)
		return tree;
	else
		return large(tree->right);
}
void delele(Node *tree,int val)
{
	if(tree==NULL)
	{
		cout<<"\nTree is empty"<<endl;
		return tree;
	}
	
	if(val<tree->data)
	tree->left=del(tree->left,val);
	else if(val>tree->data)
	tree->right=del(tree->right,val);
	else //val==tree->data
	{
		//node with only one child or no child
		if(tree->left==NULL)
		{
			Node* temp=tree->right;
			free(tree);
			return temp;
		}
		else if(tree->right==NULL)
		{
			Node* temp=tree->left;
			free(tree);
			return temp;
		}
		else
		{
			
		}

	}
}
int totnode(tree)
{
	if(tree==NULL)
		return 0;
	else
		return(totnode(tree->left)+totnode(tree->right)+1);
}
int extnode(tree)
{
	if(tree==NULL)
		return 0;
	else if(tree->left==NULL && tree->right==NULL)
		return 1;
	else
		return(extnode(tree->left)+extnode(tree->right));
}
int intnode(tree)
{
	if((tree==NULL) ||((tree->left==NULL) && (tree->right==NULL)))
		return 0;
	else
		return(extnode(tree->left)+extnode(tree->right)+1);
}
int height(tree)
{
	int leftheight,rightheight;
	if(tree==NULL)
		return 0;
	else
	{
		leftheight=height(tree->left);
		rightheight=height(tree->right);
		if(leftheight>=rightheight)
			return(leftheight+1);
		else
			return(rightheight+1);
	}
}
Node* deltree(Node *tree)				
{
	if(tree!=NULL)
	{
		deltree(tree->left);
		deltree(tree->right);
		free(tree)
	}
	else
		return tree;
}


	
	
			
		
