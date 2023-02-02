#include "FilterNonPositive.h"

bool FilterNonPositive::g(int num) {
	if (num > -1) {
		return false;
	} else {
		return true;
	}
}
