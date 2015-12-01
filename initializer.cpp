#include <iostream>

class X
{
public:
	X(int val): j(val), i(j) { }

	void pValue() const 
	{
		std::cout << i << " " << j << std::endl;
	};
private:
	int i;
	int j;
};

int main(int argc, char **argv)
{
	X x(1);
	x.pValue();
	return 0;
}
