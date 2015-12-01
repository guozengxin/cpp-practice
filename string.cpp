#include <string>
#include <iostream>
#include <stack>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::stack;
using std::vector;

int main(int argc, char **argv)
{
	string numerics("0123456789");
	string name("r2d2");
	string::size_type pos = name.find_first_of(numerics);
	cout << "pos: " << pos << " element is " << name[pos] << endl;

	stack<string, vector<string> > str_stk;
}
