
// C++ program to delete a node from AVL Tree
#include<bits/stdc++.h>


// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get height
// of the tree
int height(bank* b)
{
	if (b == NULL)
		return 0;
	return b->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}


bank *rightRotate(bank *y)
{
	bank *x = y->left;
	bank *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
bank *leftRotate(bank *x)
{
	bank *y = x->right;
	bank *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(bank *b)
{
	if (b == NULL)
		return 0;
	return height(b->left) -
		height(b->right);
}

bank* avlinsert(bank* node,bank* b)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(b);

	if (b->e_id < node->e_id)
		node->left = avlinsert(node->left, b);
	else if (b->e_id > node->e_id)
		node->right = avlinsert(node->right, b);
	else // Equal keys not allowed
		return node;


	node->height = 1 + max(height(node->left),
						height(node->right));


	int balance = getBalance(node);


	if (balance > 1 && b->e_id < node->left->e_id)
		return rightRotate(node);

	if (balance < -1 && b->e_id > node->right->e_id)
		return leftRotate(node);

	if (balance > 1 && b->e_id > node->left->e_id)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}


	if (balance < -1 && b->e_id < node->right->e_id)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}


	return node;
}


/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
bank * minValueNode(bank* node)
{
    bank* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

  void copy(bank* b,bank* b1)
  {
  	bank* temp=b;
  	b=b1;
  	b->left=temp->left;
  	b->right=temp->right;
  	b->height=temp->height;
  }


// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
bank* deleteavl(bank* root, int key)
{

	// STEP 1: PERFORM STANDARD BST DELETE
	if (root == NULL)
	{
		cout<<"\nEmployee not found...\n";
		return root;
		}

	// If the key to be deleted is smaller
	// than the root's key, then it lies
	// in left subtree
	if ( key < root->e_id )
		root->left = deleteavl(root->left, key);

	// If the key to be deleted is greater
	// than the root's key, then it lies
	// in right subtree
	else if( key > root->e_id )
		root->right = deleteavl(root->right, key);

	// if key is same as root's key, then
	// This is the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) ||
			(root->right == NULL) )
		{
			bank *temp = root->left ?
						root->left :
						root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
						// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			bank* temp = minValueNode(root->right);

			// Copy the inorder successor's
			// data to this node
			copy(root,temp);

			// Delete the inorder successor
			root->right = deleteavl(root->right,
									temp->e_id);
		}
	}

	// If the tree had only one node
	// then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),
						height(root->right));

	// STEP 3: GET THE BALANCE FACTOR OF
	// THIS NODE (to check whether this
	// node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced,
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 &&
		getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 &&
		getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 &&
		getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 &&
		getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void displayavl(bank* root)
{
	if(root != NULL)
	{
		displayavl(root->left);
		root->display();
		displayavl(root->right);
	}
}



bank* searchavl(bank* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->e_id == key)
       return root;

    // Key is greater than root's key
    if (root->e_id < key)
       return searchavl(root->right, key);

    // Key is smaller than root's key
    return searchavl(root->left, key);
}


