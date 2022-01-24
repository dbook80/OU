#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& list, int first, int last) 
{
  // The pivot should be the median of the
  // first, middle, and last elements.
  int median = (first + last) / 2;
  int pivot = list[(first + median + last) / 3];
  
  while (first <= last)
  {
    while (list[first] <= pivot) 
    {
      first++; //move to next element if the first element is already smaller
    } 
    while (pivot < list[last]) last--;
    int tmp = list[last];
    list[last] = list[first];//swapping to sort elements
    list[first] = tmp;
    first++;//traversing from one element to the next
    last--;
  }
  
  if (list[first]>pivot) 
  {
    first--;
  } 
  list[first] = list[first];
  list[first] = pivot;

  return (pivot);
}

void quicksort(vector<int>& list, int first, int last) 
{
  if (first <= last) 
  {
    int split = partition(list, first, last);
    quicksort(list, first, split - 1); //recursive call to create sublists
    quicksort(list, split + 1, last);
  }
}

void multiway_merge(
  vector<vector<int> >& input_lists, vector<int>& output_list
) 
{
  int n,i;
  make_heap(input_lists.begin(), input_lists.end());
  for(i = 1; i < n; i++)
  {
    pop_heap(input_lists.begin(), input_lists.end());//extracting min element
    //output_list.insert();   //inserting to output list
    push_heap(input_lists.begin() + 1, input_lists.end());//starting with successor element
    if(input_lists.begin() > input_lists.begin()+1)
    {
      n++; //larger element, move to next one
    }
    if(i > input_lists[n].size())//checking if list is empty
    {
      push_heap(input_lists.begin(), input_lists.end());
    }
  }

} 

int main(int argc, char** argv) {
  int n, i;
  cin >> n >> i;

  vector<vector<int> > input_lists(n, vector<int>(i));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      cin >> input_lists[i][j];
    }
  }

  // Quicksort k sublists
  for (int i = 0; i < input_lists.size(); ++i)
    quicksort(input_lists[i], 0, i-1);

  // Merge n input sublists into one sorted list
  vector<int> output_list(n * i);
  multiway_merge(input_lists, output_list);

  for (int i = 0; i < output_list.size(); ++i)
    cout << output_list[i] << " ";
  cout << endl;
}
