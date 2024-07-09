// ====================================================
// Comparing runtimes - vector insert() vs list push_front()
// vs deque push_front()
// (300,000 values)
// ====================================================
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<deque>
#include<ctime>
using namespace std;
int main()
{
clock_t start;
clock_t end;
list<int>numbers;
vector<int>values;
deque<int>amounts;
start = clock();
for (int i = 0; i < 300000; i++)
{
numbers.push_front(i);
}
end = clock();
cout << "list time: " << (end - start) / CLK_TCK << " seconds.\n\n";
start = clock();
for (int i = 0; i < 300000; i++)
{
values.insert(values.begin(), i);
}
end = clock();
cout << "vector time: " << (end - start) / CLK_TCK << " seconds.\n\n";
start = clock();
for (int i = 0; i < 300000; i++)
{
amounts.push_front(i);
}
end = clock();
cout << "deque time: " << (end - start) / CLK_TCK << " seconds.\n\n";
return 0;
}
/* OUTPUT:
list time: 0 seconds.

vector time: 3 seconds.

deque time: 0 seconds.
*/
