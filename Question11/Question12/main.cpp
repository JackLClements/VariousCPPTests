/*
 */

/* 
 * File:   main.cpp
 * Author: Jack L. Clements
 *
 * Created on 21 June 2018, 23:11
 */

#include <cstdlib>
#include <iostream>
using namespace std;

struct TreeNode {
    TreeNode *left; // Left subtree.
    TreeNode *right; // Right subtree.
};

int height(TreeNode* node, int depth) {
    if(node == 0){
        return -1; //Make sure root node doesn't contribute to height
    }
    else{
        int depthLeft = height(node->left, depth);
        int depthRight = height(node->right, depth);
        
        if(depthLeft > depthRight){
            return depthLeft+1;
        }
        else{
            return depthRight+1;
        }
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    //I could use a struct constructor here too
    TreeNode a, b, c, d, e, f;
    a.left = &b;
    a.right = &c;
    b.left = 0;
    b.right = 0;
    c.left = &d;
    c.right = &e;
    d.left = 0;
    d.right = 0;
    e.left = 0;
    e.right = &f;
    f.left = 0;
    f.right = 0;

    cout << "Value - " << height(&a, 0) << endl;

    return 0;
}

