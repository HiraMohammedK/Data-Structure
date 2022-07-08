#include<iostream>
using namespace std;

class Node
{
  public:
    int value;
	Node *left_node;
	Node *right_node;

  Node()
  {
    value = 0;
    left_node = NULL;
    right_node = NULL;
  }
  Node(int v)
  {
    value = v;
    left_node = NULL;
    right_node = NULL;
  }
};

class BinarySearchTree
{
  public:
    Node * root;
    BinarySearchTree()
    {
    root = NULL;
  }

  void InsertNode(Node * new_node)
  {
      if (root == NULL)
      {
        root = new_node;
        cout << "Node inserted successfully" << endl;
        cout<< "It is now the root node" <<endl;
      }
      else
      {
        Node * temp = root;
        while (temp != NULL)
        {
          if (new_node -> value == temp -> value)
          {
        	  cout<<"Insertion failed,entered value already exists"<<endl;
        	  cout<<"Enter another value for insertion"<<endl;
            return;
          }
          else if ((new_node -> value < temp -> value) && (temp -> left_node == NULL))
          {
            temp -> left_node = new_node;
            cout << "Node inserted successfully" << endl;
            break;
          }
          else if (new_node -> value < temp -> value)
          {
            temp = temp -> left_node;
          }
          else if ((new_node -> value > temp -> value) && (temp -> right_node == NULL))
          {
            temp -> right_node = new_node;
            cout << "Node inserted successfully" << endl;
            break;
          }
          else
          {
            temp = temp -> right_node;
          }
        }
      }
    }
  Node * SearchNode(int v) {
      if (root == NULL) {
        return root;
      } else {
        Node * temp = root;
        while (temp != NULL) {
          if (v == temp -> value) {
            return temp;
          } else if (v < temp -> value) {
            temp = temp -> left_node;
          } else {
            temp = temp -> right_node;
          }
        }
        return NULL;
      }
    }
  void PreorderTraversal(Node * r) //(DLR)
    {
      if (r == NULL)
        return;
      cout << r -> value << " ";
      PreorderTraversal(r -> left_node);
      PreorderTraversal(r -> right_node);
    }
  void InorderTraversal(Node * r) //  (LDR)
  {
    if (r == NULL)
      return;
    InorderTraversal(r -> left_node);
    cout << r -> value << " ";
    InorderTraversal(r -> right_node);
  }
  void PostorderTraversal(Node * r) //(LRD)
  {
    if (r == NULL)
      return;
    PostorderTraversal(r -> left_node);
    PostorderTraversal(r -> right_node);
    cout << r -> value << " ";
  }
  Node * MinValueNode(Node * node) {
      Node * curr = node;
      while (curr -> left_node != NULL) {
        curr = curr -> left_node;
      }
      return curr;
    }
  Node * deleteNode(Node * r, int v) {
    if (r == NULL) {
      return NULL;
    }
    else if (v < r -> value) {
      r -> left_node = deleteNode(r -> left_node, v);
    }
    else if (v > r -> value) {
      r -> right_node = deleteNode(r -> right_node, v);
    }
    else {
      if (r -> left_node == NULL) {
        Node * temp = r -> right_node;
        delete r;
        return temp;
      } else if (r -> right_node == NULL) {
        Node * temp = r -> left_node;
        delete r;
        return temp;
      }
      else
      {
        Node * temp = MinValueNode(r -> right_node);
        r -> value = temp -> value;
        r -> right_node = deleteNode(r -> right_node, temp -> value);
      }
    }
    return r;
  }


 };
int main()
{
  BinarySearchTree bst;
  int val,choice;
  do
  {
	cout<<"\tWELCOME\t"<<endl;
	cout<<"\n";
	cout<<"Select an option among the following"<<endl;
    cout << "1.Insert Node" << endl;
    cout << "2.Search Node" << endl;
    cout << "3.Preorder Traversal"<<endl;
    cout << "4.Inorder Traversal"<<endl;
    cout << "5.Postorder Traversal"<<endl;
    cout << "6.Delete Node"<<endl;
    cout<< "7.Exit"<<endl;
    cout<<"Enter your choice:";
    cin >> choice;
    Node * new_node = new Node();
    cout<<"\n";
    switch (choice)
    {

    case 1:
	      cout <<"Enter the value of the node to be inserted:";
	      cin >> val;
	      new_node->value = val;
	      bst.InsertNode(new_node);
	      cout<<endl;
    		break;
    case 2:
          cout << "Enter the value of node to be searched:";
          cin >> val;
          new_node = bst.SearchNode(val);
          if (new_node != NULL) {
            cout << "Search successful" << endl;
            cout << "The value found in the binary search tree"<<endl;
          } else
          {
            cout << "Value not found in binary search tree" << endl;
          }
          break;
    case 3:
    	cout<<"Preorder Traversal of the binary search tree gives"<<endl;
    	bst.PreorderTraversal(bst.root);
    	 cout<<endl;

      break;
    case 4:
    	cout<<"Inorder Traversal of the binary search tree gives"<<endl;
    	bst.InorderTraversal(bst.root);
    	 cout<<endl;
      break;
    case 5:
    	cout<<"Postorder Traversal of the binary search tree gives"<<endl;
    	bst.PostorderTraversal(bst.root);
    	cout<<endl;
      break;
    case 6:
      cout << "Enter the value of the node to be deleted:";
      cin >> val;
      new_node = bst.SearchNode(val);
      if (new_node != NULL) {
    	  bst.deleteNode(bst.root, val);
        cout << "Deletion successful" << endl;
      } else
      {
        cout << "Deletion failed" << endl;
      }
      break;
    case 7:
          break;
    default:
      cout << "Invalid option " << endl;
    }

  } while (choice!=7);
  return 0;
}
