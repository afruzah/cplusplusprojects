#include "FilterOdd.h"

bool FilterOdd::g(int num) {
	if (num % 2 == 0) {
		return false;
	} else {
		return true;
	}
}
