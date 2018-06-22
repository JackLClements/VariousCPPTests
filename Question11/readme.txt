11.

For the suggestions of my own questions, I wish to add two, covering topics I feel are not represented in this test
- Recursion
- Inheritance

Question 11.

Given the class "Animal" below, please create two subclasses "Human" and "Tiger" that inherit from "Animal".
You should seek to override the methods "speak()" as well as implementing a type-specific method for each example (e.g. a tiger has a tail, humans have opposable thumbs, etc.)

class Animal {
protected:
    int legs;
    int arms;
    std::string name;

public:
    Animal(){
        
    };
    Animal(int legs, int arms, std::string name) {
        this->legs = legs;
        this->arms = arms;
        this->name = "Animal";
    };
    virtual std::string speak()=0;

};

Question 12.

Given the struct below, please write a method height(TreeNode node, int depth) that returns the height of the Tree given the root and a depth of 0. 

struct TreeNode {
              TreeNode *left;   // Left subtree.
              TreeNode *right;  // Right subtree.
};

When called, your method height(&node, 0) should return 3 when presented with the tree below:

		1
	  /	  \
	2		3
		   /  \
		  4    5
			    \
				 6

(Hint - remember that tree heights don't include the root and think about what your base case should be to facilitate that)