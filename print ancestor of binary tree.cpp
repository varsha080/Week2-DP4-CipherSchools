bool printAncestors(struct node *root, int target)
{

  if (root == NULL)
     return false;
 
  if (root->data == target)
     return true;
 
 
  if ( printAncestors(root->left, target) ||
       printAncestors(root->right, target) )
  {
    cout << root->data << " ";
    return true;
  }
 

  return false;
}
 
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}