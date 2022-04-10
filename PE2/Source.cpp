#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
/*lets try to sort this vectorand then we will store this inside a stack so we will have a organized stack
* example::
* vec1:30,40,22,4,6
* stack(empty)
* after the program runs*
* vec1:4,6,22,30,40
* stack:4,22,30,40
* 
* 
* 
*/

void printStack(stack<int>stackParam) {
	while(!stackParam.empty()) {
		cout << stackParam.top() << endl;
		stackParam.pop();
	}
}
void vecToStack(vector<int>&vecParam, stack<int>&stackParam) {
	//here you are going to sort your vector 
	sort(vecParam.begin(), vecParam.end(), [](int a, int b) {return a > b; });
	//output this vector so you know it is sorted from beggining to the end of the vector
	for_each(vecParam.begin(), vecParam.end(), [](int a) {cout << a << endl; });
	for (auto vecIter = vecParam.begin(); vecIter != vecParam.end(); vecIter++)
	{
		stackParam.push(*vecIter);
	}
}
/*Now that i have my vector organized what i want to do is throw the numbers into the with even numbers list and the odd into the queue starting from the back 
* and using the queue as your value and the list as your key in a multimap
example::
vec1:4,6,22,30,40,5
list:(list is empty)
queue:(this is not empty)
multimap(this is empty)
after the program runs 
vec1:4,6,22,30,40
list:4,6,22,30,40
queue:5
multimap:{40,5},{30,0},{22,0},{6,0},{4,0}

not to sure if this will work out or not yet have not had time to play around with it yet
*/

void someFunction(vector<int>& vecParam, list<int>& listParam, queue<int>& queueParam, multimap<int, int>multiMapParam) {
	for (auto vectorIter = vecParam.begin(); vectorIter != vecParam.end(); vectorIter++)
	{
		if (*vectorIter % 2 == 0) {
			listParam.push_front(*vectorIter);
		}
		else {
			queueParam.push(*vectorIter);
		}
	}

}

void workingWithVectors(vector<int>&vector1,vector<int>vector2){
	vector2.resize(vector1.size());
	auto it = copy_if(vector1.begin(), vector1.end(), vector2.begin(), [](int i) {
		return (i > 0);
		});
	vector2.resize(distance(vector2.begin(), it));



}
int main() {
	vector<int>vec1 {30,40,22,4,6};
	stack<int>stack1;


	vecToStack(vec1, stack1);
	printStack(stack1);
	list<int>list1;
	vector<int>vec2{ 30,4,2,5,6,4 };
	queue<int>queue1;
	multimap<int, int>map1;
	workingWithVectors(vec1, vec2);

	return 0;
	system("pause");
}