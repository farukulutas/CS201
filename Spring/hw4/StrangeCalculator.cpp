// Ahmet Faruk Ulutas - 21803717
#include "StrangeCalculator.h"

// default constructor
template <typename StackItemType>
StrangeCalculator<StackItemType>::StrangeCalculator() : topPtr(NULL){

}

// copy constructor
template <typename StackItemType>
StrangeCalculator<StackItemType>::StrangeCalculator(const StrangeCalculator& aStack){

   if (aStack.topPtr == NULL)
      topPtr = NULL;  // original stack is empty

   else {
      // copy first node
      topPtr = new StackNode;
      topPtr->item = aStack.topPtr->item;

      // copy rest of stack
      StackNode *newPtr = topPtr;
      for (StackNode *origPtr = aStack.topPtr->next;
                      origPtr != NULL;
                      origPtr = origPtr->next){
         newPtr->next = new StackNode;
         newPtr = newPtr->next;
         newPtr->item = origPtr->item;
      }
      newPtr->next = NULL;
   }
}

// destructor
template <typename StackItemType>
StrangeCalculator<StackItemType>::~StrangeCalculator(){

   // pop until stack is empty
   while (!isEmpty())
      pop();

}

template <typename StackItemType>
bool StrangeCalculator<StackItemType>::isEmpty() const {

   return topPtr == NULL;

}

template <typename StackItemType>
bool StrangeCalculator<StackItemType>::push(StackItemType newItem) {

   // create a new node
   StackNode *newPtr = new StackNode;

   // set data portion  of new node
   newPtr->item = newItem;

   // insert the new node
   newPtr->next = topPtr;
   topPtr = newPtr;

   return true;
}

template <typename StackItemType>
bool StrangeCalculator<StackItemType>::pop() {

   if (isEmpty())
      return false;

   // stack is not empty; delete top
   else{
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
      return true;
   }
}

template <typename StackItemType>
bool StrangeCalculator<StackItemType>::pop(StackItemType& stackTop) {

   if (isEmpty())
      return false;

   // not empty; retrieve and delete top
   else{
      stackTop = topPtr->item;
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
      return true;
   }
}

template <typename StackItemType>
bool StrangeCalculator<StackItemType>::getTop(StackItemType& stackTop)
             const {

   if (isEmpty())
      return false;

   // stack is not empty; retrieve top
   else {
      stackTop = topPtr->item;
      return true;
   }

}

string infix2prefix( const string exp ) {
    string infix = exp;
    int n = infix.length();
    string prefix = "";
    StrangeCalculator<char> aStack;
    char stackTop;
    char poppedItem;

    for (int i = 0; i < n / 2; i++)
        swap(infix[i], infix[n - i - 1]);

    for (int j = 0; j < infix.length(); j++) {
        if ( checkOperand( infix[j] ) ) {
            prefix = infix[j] + prefix;
        }
        else if ( infix[j] == ')' ) {
            aStack.push( infix[j]);
        }
        else if ( infix[j] == '(' ) {
            while ( aStack.getTop( stackTop) && stackTop != ')' ) {
                aStack.pop( poppedItem);
                prefix = poppedItem + prefix;
            }

            aStack.pop();
        }
        else {
            aStack.getTop( stackTop);
            while ( aStack.getTop( stackTop) && precedence(infix[j]) < precedence( stackTop) ) {
                aStack.pop( poppedItem);
                prefix = poppedItem + prefix;
            }
            aStack.push( infix[j]);
        }
    }

    while ( !aStack.isEmpty() ) {
        aStack.pop( poppedItem);
        prefix = poppedItem + prefix;
    }

    return prefix;
}

int checkOperand (char ch) {
  return ( (int)ch >= 48 && (int)ch < 58 );
}

int precedence (char ch) {
  switch (ch) {
    case '+':
    case '-':
      return 1;

    case '*':
    case '/':
      return 2;
    }

  return -1;
}

double evaluatePrefix( const string exp ) {
    StrangeCalculator<double> aStack;
    double o1, o2, result;

    for (int i = exp.length() - 1; i >= 0; i--) {
        if ( checkOperand( exp[i])) {
            aStack.push( exp[i] - '0');
        }
        else {
            aStack.pop( o1);
            aStack.pop( o2);

            switch ( exp[i]) {
            case '+':
                aStack.push(o1 + o2);
                break;
            case '-':
                aStack.push(o1 - o2);
                break;
            case '*':
                aStack.push(o1 * o2);
                break;
            case '/':
                aStack.push(o1 / o2);
                break;
            }
        }
    }

    aStack.getTop( result);
    return result;
}

bool isBalancedInfix( const string exp ) {
    StrangeCalculator<char> aStack;
    char top;

    for (int i = 0; i < exp.length(); i++) {
        if ( exp[i] == '(') {
            aStack.push(exp[i]);
            continue;
        }

        if ( exp[i] == ')' && aStack.isEmpty() )
            return false;

        switch (exp[i]) {
        case ')':
            aStack.pop( top);
        }
    }

    return ( aStack.isEmpty() );
}

void evaluateInputPrefixExpression( ) {
    string input = "";
    string infix = "";

    cout << "Enter an prefix input:";
    getline (cin, input);

    for (int i = 0; i < input.length(); i++) {
        if ( input[i] != ' ' ) {
            infix = infix + input[i];
        }
    }

    if ( !isBalancedInfix( infix) ) {
        cout << "The input prefix is not balanced!" << endl;
    }
    else {
        cout << "prefix of: " << infix << " is " << infix2prefix( infix) << endl;
        cout << "result of: " << infix << " is " << evaluatePrefix( infix2prefix( infix)) << endl;
    }
}
