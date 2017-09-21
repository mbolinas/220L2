/*
 * Marc Bolinas
 * Brian Philips
 *
 * TA: Eeshita Biswas
 *
 * 9/14/17
 * LAB 2
 *
 *
 *
 */



#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


//PART 1

string reverse_string(string str); //returns the reverse of the string passed

int sum_digit(int i); //returns sum of all the individual 'digits' from int passed

int find_min(int array[], int array_size); //gets minimum value out of passed array
int find_min_helper(int array[], int array_size, int current); //recursively finds the minimum value in an array for find_min()

bool is_elfish(string str); //true if passed string contains "e" "l" and "f" in any order
bool is_in_string(string str, string key); //recursively finds 'key' in 'str', returns true if found. helper function for is_elfish()

bool is_perfect_number(int i);
int is_perfect_number_helper(int i, int current);
bool is_divisor(int top, int bottom); //true if numerator is perfectly divisible by denominator

void print_x(int i); //prints out an X made of X's whose size depends on passed int
void x_helper(int start, int end, int offset, int spacing); //recursive helper function for print_x()
void print_space(int spacing); //recursively prints spaces for x_helper()



//PART 2

bool order1(int *i, int *j); //true if i < j, otherwise false and switches i and j. done via pass by pointer

bool order2(int &k, int &l); //true if k < l, otherwise false and switches k and l. done via pass by reference

void order3(int *i); //prints out value, memory address of parameter, and memory address of variable via pass by pointer

void order4(int &i); //prints out value, memory address of parameter, and memory address of variable via pass by reference

void array_filler(int *array, int array_size); //fills given array with randomly generated numbers from 0 to 100

void array_printer(int *array, int array_size); //prints out all values in the array

void problem7(int *array, int array_size, int &k, int &j); //finds smallest value in array, sets k to that value and j to the index in its array

void array_address_printer(int *array, int array_size); //prints out all addresses in an int array
//gotta love function overloading
void array_address_printer(double *array, int array_size); //prints out all addresses in a double array

int p10(int *a1, int *a2, int size1, int size2, int &sum1, int &sum2); //calculates sum of arrays 1 & 2, sets their sums to sum1 and sum2. returns 1 if sum1 > sum2, 0 if =, and -1 if sum1 < sum2









int main(){
	srand(time(NULL));



	cout << "PROBLEM 1" << endl;
	cout << reverse_string("olleh") << endl;
	cout << reverse_string("marc bolinas") << endl;
	cout << reverse_string("brian philips") << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 2" << endl;
	cout << sum_digit(123) << endl;
	cout << sum_digit(0) << endl;
	cout << sum_digit(420) << endl;
	cout << "********************************************************" << endl
			<< endl;


	cout << "PROBLEM 3" << endl;
	int a1[5] = {1,2,3,4,5};
	int a2[5] = {7,2,5,2,6};
	int a3[5] = {3,9,4,7,3};
	cout << find_min(a1,5) << endl;
	cout << find_min(a2,5) << endl;
	cout << find_min(a3,5) << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 4" << endl;
	cout << is_elfish("hello") << endl;
	cout << is_elfish("elfy boy") << endl;
	cout << is_elfish("a;ldfgh;rheglk") << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 5" << endl;
	cout << is_perfect_number(496) << endl;
	cout << is_perfect_number(497) << endl;
	cout << is_perfect_number(23425) << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 6" << endl;
	print_x(3);
	cout << endl;
	print_x(5);
	cout << endl;
	print_x(2);
	cout << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 1" << endl;
	int x = rand() % 51;
	int y = rand() % 51;
	cout << "X is " << x << endl;
	cout << "Y is " << y << endl;
	cout << order1(&x, &y) << endl;
	cout << "X is now " << x << endl;
	cout << "Y is now " << y << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 2" << endl;
	int x2 = rand() % 51;
	int y2 = rand() % 51;
	cout << "X2 is " << x << endl;
	cout << "Y2 is " << y << endl;
	cout << order2(x2, y2) << endl;
	cout << "X2 is now " << x << endl;
	cout << "Y2 is now " << y << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 3" << endl;
	int z = 34;
	cout << &z << endl;
	order3(&z);
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 4" << endl;
	int a = 23;
	cout << "Value is " << a << " and address is " << &a << endl;
	order4(a);
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 5" << endl;
	int arr20[20];
	array_filler(arr20,20);
	cout << arr20[10] << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 6" << endl;
	array_printer(arr20,20);
	array_printer(a1,5);
	array_printer(a2,5);
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 7" << endl;
	int g = -1;
	int h = -1;
	problem7(a1,5,g,h);
	cout << "Smallest value is " << g << " and it's index is " << h << endl;
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 8" << endl;
	array_address_printer(a1,5);
	array_address_printer(a2,5);
	array_address_printer(a3,5);
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 9" << endl;
	double da1[5] = {1.1,2.2,3.3,4.4,5.5};
	double da2[5] = {5.5,3.3,2.2,6.6,4.4};
	double da3[5] = {8.8,2.2,5.5,3.3,7.7};
	array_address_printer(da1,5);
	array_address_printer(da2,5);
	array_address_printer(da3,5);
	cout << "********************************************************" << endl
			<< endl;



	cout << "PROBLEM 10" << endl;
	cout << p10(a1,a2,5,5,g,h) << endl;
	cout << "Sum1 is " << g << " and sum2 is " << h << endl;
	cout << p10(a2,a3,5,5,g,h) << endl;
	cout << "Sum1 is " << g << " and sum2 is " << h << endl;
	cout << p10(a3,a1,5,5,g,h) << endl;
	cout << "Sum1 is " << g << " and sum2 is " << h << endl;
	cout << "********************************************************" << endl
			<< endl;


	return 0;
}


//Problem 1
string reverse_string(string str){
	if(str.length() <= 0){
		return "";
	}
	else{
		string temp = str.substr(str.length() - 1, 1);	//last character in str
		str.pop_back(); //remove last character from string
		return temp + reverse_string(str);
	}
}


//Problem 2
int sum_digit(int i){
	if(i == 0){
		return 0;
	}
	else{
		return (i % 10) + sum_digit(i / 10); //i % 10 gets rightmost digit, i / 10 shifts all digits to the right. repeat until 0
	}
}


//Problem 3
int find_min(int array[], int array_size){
	return find_min_helper(array, array_size, array[0]); //calls helper function where the recursion is
}

int find_min_helper(int *array, int array_size, int current){
	if(array_size <= 1){
		return current;
	}
	else{
		find_min_helper(&array[1], array_size - 1, min(current, array[0]));
	}
}


//Problem 4
bool is_elfish(string str){ //calls helper function where the recursion is
	return (is_in_string(str, "e") &&
			is_in_string(str, "l") &&
			is_in_string(str, "f"));
}

bool is_in_string(string str, string key){ //generalized recursive version of is_elfish() - true if 'key' is in 'str'
	if(str.substr(str.length() - 1, key.length()) == key){
		return true;
	}
	else if(str.length() <= 1){
		return false;
	}
	else{
		str.pop_back();
		return is_in_string(str, key);
	}
}


//Problem 5
bool is_perfect_number(int i){ //calls helper function where recursion is
	return (i == is_perfect_number_helper(i, 1));
}


int is_perfect_number_helper(int i, int current){ //goes through all numbers from 1 to i
	if(current >= i){
		return 0;
	}
	else{
		if(is_divisor(i, current)){ //if current is a divisor, then add it to sum and keep recursing
			return current + is_perfect_number_helper(i, current + 1);
		}
		else{ //otherwise just recurse and don't add to sum
			return is_perfect_number_helper(i, current + 1);
		}
	}
}

bool is_divisor(int top, int bottom){ //true if numerator is perfectly divisble by denominator
	return !(top % bottom);
}


//Problem 6
void print_x(int i){ //calls helper function
	int start = i - 1;
	int end = start - (2 * start);
	int spacing = start * 2 - 1;
	x_helper(start, end, 0, spacing);
}

void x_helper(int start, int end, int offset, int spacing){
	if(start >= end){

		print_space(offset); //amount of spaces before the first x
		cout << "x";
		print_space(spacing); //amount of spaces between the two x's
		if(spacing != 0){ //in the middle there is only one x. is space = 0 we only need one x
			cout << "x";
		}
		cout << endl;


		if(start > 0){
			offset++; //as we go towards the middle, offset increases
		}
		else if(start <= 0){
			offset--; //if we're past the middle x, offset decreases instead
		}
		start--;


		if(start == 0){ //if we're in the middle x, spacing is 0
			spacing = 0;
		}
		else if(start == -1){ //spacing specifically decrements by 1 for this
			spacing = -1;
		}
		else{ //normally spacing decrements by 2 each time
			spacing -= 2;
		}
		x_helper(start, end, offset, spacing);
	}
}

void print_space(int spacing){ //prints a space, recursively gets count to 0 (whether from negative of positive)
	if(spacing > 0){
		cout << " ";
		print_space(spacing - 1);
	}
	else if(spacing < 0){
		cout << " ";
		print_space(spacing + 1);
	}
}







//Problem 1
bool order1(int *i, int *j){ //true if i < j, else false and switch values via call by pointer
	if(*i < *j){
		return true;
	}
	else{
		int temp = *j;
		*j = *i;
		*i = temp;
		return false;
	}
}


//Problem 2
bool order2(int &k, int &l){ //true if k < l, else false and switch values via call by reference
	if(k < l){
		return true;
	}
	else{
		int temp = l;
		l = k;
		k = temp;
		return false;
	}
}


//Problem 3
void order3(int *i){ //prints out value, address of parameter, and address of variable via call by pointer
	cout << *i << endl;
	cout << i << endl;
	cout << &i << endl;
}


//Problem 4
void order4(int &i){ //prints out value, and address of parameter via call by reference
	cout << i << endl;
	cout << &i << endl;
}


//Problem 5
void array_filler(int *array, int array_size){ //fills array with random ints from 0 to 100
	for(int i = 0; i < array_size; i++){
		array[i] = (rand() % 100);
	}
}


//Problem 6
void array_printer(int *array, int array_size){ //prints out all values of array
	for(int i = 0; i < array_size; i++){
		cout << array[i];
		if(i < array_size - 1){ //don't want to print a comma if there's nothing else in the array
			cout << ", ";
		}
	}
	cout << endl;
}


//Problem 7
void problem7(int *array, int array_size, int &k, int &j){  //finds smallest value in array, sets k to that value and j to the index in its array
	int smallest = array[0];
	int index = 0;
	int i = 0;
	for(; i < array_size; i++){
		if(smallest > array[i]){
			smallest = array[i];
			index = i;
		}
	}

	k = smallest;
	j = index;
}


//Problem 8
void array_address_printer(int *array, int array_size){ //prints out all addresses in an int array
	for(int i = 0; i < array_size; i++){
		cout << "Element #" << i << ": " << &array[i] << endl;
	}
}


//Problem 9
void array_address_printer(double *array, int array_size){ //prints out all addresses in a double array
	for(int i = 0; i < array_size; i++){
		cout << "Element #" << i << ": " << &array[i] << endl;
	}
}


//Problem 10
int p10(int *a1, int *a2, int size1, int size2, int &sum1, int &sum2){ //calculates sum of arrays 1 & 2, sets their sums to sum1 and sum2. returns 1 if sum1 > sum2, 0 if =, and -1 if sum1 < sum2
	for(int i = 0; i < size1; i++){
		sum1 = sum1 + a1[i];
	}

	for(int i = 0; i < size2; i++){
		sum2 = sum2 + a2[i];
	}

	if(sum1 == sum2){
		return 0;
	}
	else if(sum1 > sum2){
		return 1;
	}
	else{
		return -1;
	}
}






