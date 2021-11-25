// Ahmet Faruk Ulutas - 21803717
#include <iostream>
using namespace std;

string infix2prefix( const string exp );
double evaluatePrefix( const string exp );
bool isBalancedInfix( const string exp );
void evaluateInputPrefixExpression( );

int precedence (char ch);
int checkOperand (char ch);

template <typename StackItemType>
class StrangeCalculator{

public:
   StrangeCalculator();
   StrangeCalculator(const StrangeCalculator& aStack);
   ~StrangeCalculator();

   bool isEmpty() const;
   bool push(StackItemType newItem);
   bool pop();
   bool pop(StackItemType& stackTop);
   bool getTop(StackItemType& stackTop) const;

private:
   struct StackNode {            // a node on the stack
      StackItemType item;        // a data item on the stack
      StackNode    *next;        // pointer to next node
   };

   StackNode *topPtr;     // pointer to first node in the stack
};
