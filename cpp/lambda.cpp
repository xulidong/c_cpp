#include <iostream>

using namespace std;

int main() {
	auto res = [] (int x, int y) ->int {
		return x + y;
	}(1, 2);
	cout << res << endl;

	auto x = 1;
	[] (int &x, int &y) -> void {
		auto tmp = x;
		x = y;
		y = tmp;
	}(res, x);
	cout << res << "," << x << endl;

	[&] {
		res += 1;
	}(); 
	cout << res << endl;

	[=] () mutable -> void {
		res += 1;
	}(); 
	cout << res << endl;

	return 0;
}
