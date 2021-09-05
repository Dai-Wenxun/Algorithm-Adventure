#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

#define endl '\n'


int Priority(char c) {
	if (c == '#') {
		return 0;
 	} else if (c == '$') {
 		return 1;
	} else if (c == '+' || c == '-') {
		return 2;
	} else {
		return 3;
	}
}

double GetNumber(string str, int &index) {
	double number = 0;
	
	while (isdigit(str[index])) {
		number = number * 10 + str[index] - '0';
		index++;
	}
	return number;
}

double Calculate(double x, double y, char op) {
	if (op == '+')
		return x + y;
	else if (op == '-')
		return x - y;
	else if (op == '*')
		return x * y;
	else if (op == '/')
		return x / y;
}

int main() {
	string str;
	
	while(getline(cin, str)) {
		if (str == "0")
			break;
		int index = 0;
		stack<char> oper;
		stack<double> data;
		
		str += "$";
		oper.push('#');
		
		while(index < str.size()) {
			if (str[index] == ' ') {
				index++;
			} else if (isdigit(str[index])) {
				data.push(GetNumber(str, index));
			} else {
				if (Priority(oper.top()) < Priority(str[index])) {
					oper.push(str[index]);
					index++;
				} else {
					double y = data.top();
					data.pop();
					double x = data.top();
					data.pop();
					
					data.push(Calculate(x, y, oper.top()));
					oper.pop(); 
				} 
			}
		}
		
		printf("%.2f\n", data.top());
		
	}
	return 0;
}



//struct ASTnode {
//	int op;
//	double value;
//	struct ASTnode *left;
//	struct ASTnode *right;
//};
//
//struct token {
//	int token; 
//	double value;
//};
//
//int op_precedence[] = {
//	0, 0, 1, 1, 2, 2
//};
//
//enum {
//	A_EOF, A_INTLIT, A_ADD, A_SUBTRACT, 
//	A_MULTIPLY, A_DIVIDE
//};
//
//struct token Token;
//string str;
//int index = 0;
//
//
//int scanint() {
//	int val = 0;
//	
//	while(isdigit(str[index])) {
//		val = 10 * val + (str[index] - '0');
//		index++;
//	}
//	
//	return val;
//}
//
//char next() {
//	if (str[index] == ' ') {
//		index++; 
//		next();
//	} else {
//		return str[index];
//	}
//}
//
//void scan() {
//	int c;
//	
//	if (index < str.size()) {
//		c = next();
//	
//		if (isdigit(c)) {
//			Token.value = scanint();
//			Token.token = A_INTLIT;
//		} else {
//			switch (c) {
//				case '+':
//					Token.token = A_ADD;
//					break;
//				case '-':
//					Token.token = A_SUBTRACT; 
//					break;
//				case '*':
//					Token.token = A_MULTIPLY;
//					break;
//				case '/':
//					Token.token = A_DIVIDE;
//					break;
//			}
//			index++;
//		}
//	} else {
//		Token.token = A_EOF;
//	}
//}
//
//struct ASTnode *mkastnode(int op, double value, 
//						struct ASTnode *left, struct ASTnode *right) {
//	struct ASTnode *node;
//	
//	node = (struct ASTnode *) malloc (sizeof(struct ASTnode));
//	
//	node->op = op;
//	node->value = value;
//	node->left = left;
//	node->right = right;
//	
//	return node;
//};
//
//
//struct ASTnode *primary() {
//	struct ASTnode *n; 
//	n = mkastnode(A_INTLIT, Token.value, NULL, NULL);
//	scan();
//	return n;
//};
//
//
//struct ASTnode *binexpr(int ptp) {
//	struct ASTnode *left, *right;
//	int op, token;
//	left = primary();
//	
//	if (Token.token == A_EOF)
//		return left;
//		
//	op = Token.token;
//	
//	while(op_precedence[op] > ptp) {
//		
//		scan();
//		right = binexpr(op_precedence[op]);
//		
//		left = mkastnode(op, 0, left, right);
//		
//		op = Token.token;
//		if (Token.token == A_EOF)
//			return left;
//	}
//	
//	return left;
//}
//
//double genAST(struct ASTnode *tree) {
//	double leftval, rightval;
//	
//	if (tree->left) 
//		leftval = genAST(tree->left);
//	if (tree->right)
//		rightval = genAST(tree->right); 
//	
//	switch(tree->op) {
//		case A_INTLIT:
//			return tree->value;
//		case A_ADD:
//			return leftval + rightval;
//		case A_SUBTRACT:
//			return leftval - rightval;
//		case A_MULTIPLY:
//			return leftval * rightval;
//		case A_DIVIDE:
//			return leftval / rightval;	 
//	}
//	
//}
//
//
//int main() {
//	struct ASTnode *tree;
//	while(getline(cin, str)) {
//		if (str == "0")
//			break;
//		scan();
//		tree = binexpr(0); 
//		printf("%.2f\n", genAST(tree));
//	}
//	return 0;
//}
