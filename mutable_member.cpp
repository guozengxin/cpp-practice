#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cin;
using std::cout;

class Screen
{
public:
	typedef std::string::size_type index;

public:
	Screen() { }
	~Screen() { }
	Screen& display(std::ostream &os) {
		do_display(os);
		return *this;
	}

	const Screen& display(std::ostream &os) const {
		do_display(os);
		return *this;
	}

	void showAccess() const {
		cout << access_ctr << endl;
	}

private:
	void do_display(std::ostream &os) const {
		access_ctr ++;
		os << contents;
	}

private:
	string contents;
	index cursor;
	index height, width;

	mutable size_t access_ctr;
};

int main(int argc, char **argv)
{
	Screen myScreen;
	const Screen &blank = myScreen;
	myScreen.display(cout);
	blank.display(cout);
	myScreen.showAccess();
}
