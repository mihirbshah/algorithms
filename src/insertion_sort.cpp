#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
void insertion_sort(T& cont)
{
	size_t n = cont.size();
	for (size_t i = 1; i < n; ++i)
	{
		for (size_t j = i; (j > 0) && (cont[j] < cont[j-1]); --j)
		{
			swap(cont[j], cont[j-1]);
		}
	}
}

template <class RandomIt>
void insertion_sort_generic(RandomIt begin, RandomIt end)
{
	for (RandomIt i = begin + 1; i != end; ++i)
		for (RandomIt j = i; (j > begin) && ( (*j) < (*(j-1)) ); --j)
			swap(*j, *(j-1));
}


/*int main()
{
  vector<int> nums{3, 1, 10, 2, 90, 36, 24};
  vector <string> str{"hello", "world", "moon", "sun"};

  cout << "\nBefore sort:\n";
  copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
  cout << "\n";
  copy(str.begin(), str.end(), ostream_iterator<string>(cout, " "));

  insertion_sort_generic(nums.begin(), nums.end());
  insertion_sort_generic(str.begin(), str.end());

  cout << "\nAfter sort:\n";
  copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
  cout << "\n";
  copy(str.begin(), str.end(), ostream_iterator<string>(cout, " "));

  return 0;
}*/
