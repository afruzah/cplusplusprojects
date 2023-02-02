#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> sorted, int num) {
	int len = sorted.size();
	int start = 0;
	int end = len-1;
	int mid = 0;
	
	if (start <= end) {
		if (end == 0) {
			mid = 0;
		}
		if (end > 0) {
			mid = (start+end)/2;
		}
		if (sorted[mid] == num) {
			return true;
		}
		if (sorted[mid] < num) {
			std::vector<int> toSearch;
			toSearch.insert(toSearch.end(), sorted.begin() + mid + 1, sorted.end());
			return search(toSearch, num);
		}
		if (sorted[mid] > num) {
			std::vector<int> toSearch;
			toSearch.insert(toSearch.end(), sorted.begin(), sorted.begin()+ mid-1);
			return search(toSearch, num);
		}
	}
	
	return false;
}
