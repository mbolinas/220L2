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



string reverseString(string str);

int sumDigit(int i);

int find_min(int array[], int array_size);

int find_min_helper(int array[], int array_size, int current);

bool is_elfish(string str);

bool is_elfish_helper(string str, string key);

bool is_perfect_number(int i);

int is_perfect_number_helper(int i, int current);

bool is_divisor(int top, int bottom);

void gon_give_x_to_ya(int i);

void x_helper(int start, int end, int offset, int spacing);

void print_space(int spacing);





bool order1(int *i, int *j);

bool order2(int &k, int &l);

void order3(int *i);

void order4(int &i);

void array_filler(int *array, int array_size);

void array_printer(int *array, int array_size);

void problem7(int *array, int array_size, int &k, int &j);

void array_address_printer(int *array, int array_size);

void array_address_printer(double *array, int array_size);

int p10(int *a1, int *a2, int size1, int size2, int &sum1, int &sum2);









int main(){

//	int arr[5] = {1,2,0,4,5};
//
//	cout << find_min(arr, 5);
//
//	string s = "hello";
//
//	cout << s.substr(0,1);
//
//	cout << (s.substr(0,1) == "h");

//	cout << is_perfect_number(8128);

	gon_give_x_to_ya(5);


	int x = 3;
	int y = 2;
	cout << &x << endl;
	order4(x);

	return 0;
}

string reverseString(string str){
	if(str.length() <= 0){
		return "";
	}
	else{
		string temp = str.substr(str.length() - 1, 1);
		str.pop_back();
		return temp + reverseString(str);
	}
}


int sumDigit(int i){
	if(i == 0){
		return 0;
	}
	else{
		return (i % 10) + sumDigit(i / 10);
	}
}


int find_min(int array[], int array_size){
	return find_min_helper(array, array_size, array[0]);
}

int find_min_helper(int *array, int array_size, int current){
	if(array_size <= 1){
		return current;
	}
	else{
		find_min_helper(&array[1], array_size - 1, min(current, array[0]));
	}
}


bool is_elfish(string str){
	return (is_elfish_helper(str, "e") &&
			is_elfish_helper(str, "l") &&
			is_elfish_helper(str, "f"));
}

bool is_elfish_helper(string str, string key){
	if(str.substr(str.length() - 1,1) == key){
		return true;
	}
	else if(str.length() <= 1){
		return false;
	}
	else{
		str.pop_back();
		return is_elfish_helper(str, key);
	}
}


bool is_perfect_number(int i){
	return (i == is_perfect_number_helper(i, 1));
}


int is_perfect_number_helper(int i, int current){
	if(current >= i){
		return 0;
	}
	else{
		if(is_divisor(i, current)){
			return current + is_perfect_number_helper(i, current + 1);
		}
		else{
			return is_perfect_number_helper(i, current + 1);
		}
	}
}

bool is_divisor(int top, int bottom){
	return !(top % bottom);
}


void gon_give_x_to_ya(int i){
	int start = i - 1;
	int end = start - (2 * start);
	int spacing = start * 2 - 1;
	x_helper(start, end, 0, spacing);
}

void x_helper(int start, int end, int offset, int spacing){
	if(start >= end){
		print_space(offset);
		cout << "x";
		print_space(spacing);
		if(spacing != 0){
			cout << "x";
		}
		cout << endl;
		if(start > 0){
			offset++;
		}
		else if(start <= 0){
			offset--;
		}
		start--;
		if(start == 0){
			spacing = 0;
		}
		else if(start == -1){
			spacing = -1;
		}
		else{
			spacing -= 2;
		}
		x_helper(start, end, offset, spacing);
	}
}

void print_space(int spacing){
	if(spacing > 0){
		cout << " ";
		print_space(spacing - 1);
	}
	else if(spacing < 0){
		cout << " ";
		print_space(spacing + 1);
	}
}









bool order1(int *i, int *j){
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


bool order2(int &k, int &l){
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


void order3(int *i){
	cout << *i << endl;
	cout << i << endl;
	cout << &i << endl;
}


void order4(int &i){
	cout << i << endl;
	cout << &i << endl;
}


void array_filler(int *array, int array_size){
	srand(time(NULL));
	for(int i = 0; i < array_size; i++){
		array[i] = (rand() % 100);
	}
}


void array_printer(int *array, int array_size){
	for(int i = 0; i < array_size; i++){
		cout << array[i];
		if(i < array_size - 1){
			cout << ", ";
		}
	}
	cout << endl;
}


void problem7(int *array, int array_size, int &k, int &j){
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


void array_address_printer(int *array, int array_size){
	for(int i = 0; i < array_size; i++){
		cout << "Element #" << i << ": " << &array[i] << endl;
	}
}


void array_address_printer(double *array, int array_size){
	for(int i = 0; i < array_size; i++){
		cout << "Element #" << i << ": " << &array[i] << endl;
	}
}


int p10(int *a1, int *a2, int size1, int size2, int &sum1, int &sum2){
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






