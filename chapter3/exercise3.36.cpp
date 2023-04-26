#include <iostream>
#include <vector>

int compare_array(int *a1, int *a2, int size1, int size2) { 
	int *p1 = a1, *p2 = a2, *last1 = a1 + size1, *last2 = a2 + size2;

	while (p1 < last1 && p2 < last2) {
		if (*p1 > *p2)
			return 1;
		else if (*p1 < *p2)
			return -1;
		p1++;
		p2++;
	} 
	if (p1 < last1)
		return 1;
	if (p2 < last2)
		return -1;
	return 0;
}

int compare_vector(std::vector<int> v1, std::vector<int> v2) {
	auto iter1 = v1.begin(), last1 = v1.end(), iter2 = v2.begin(), last2 = v2.end();
	for (; iter1 != last1 && iter2 != last2; iter1++, iter2++) {
		if (*iter1 > *iter2)
			return 1;
		else if (*iter1 < *iter2)
			return -1;
	}
	if (iter1 != last1)
		return 1;
	if (iter2 != last2)
		return -1;
	return 0;
}

int main(int argc, char const *argv[])
{
	int nums1[] = {9, 2, 3, 4};
	int nums2[] = {1, 2, 5};
	std::vector<int> v1{1, 2, 3, 4, 6};
	std::vector<int> v2{1, 2, 3, 4, 5};

	char signs[] = {0, '<', '=', '>'};

	std::cout << "nums1 " << signs[compare_array(nums1, nums2, sizeof(nums1) / sizeof(int),
		sizeof(nums2) / sizeof(int))] << " nums2" << std::endl;
	std::cout << "v1 " << signs[compare_vector(v1, v2)] << " v2" << std::endl;

	return 0;
}