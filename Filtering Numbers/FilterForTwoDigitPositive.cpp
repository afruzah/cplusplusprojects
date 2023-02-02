#include "FilterForTwoDigitPositive.h"

bool FilterForTwoDigitPositive::g(int num) {
	if (num > 9 && num < 100) {
		return true;
	} else {
		return false;
	}
}
