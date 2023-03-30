#include <stdio.h>
#include <stdbool.h>

int length_of_last_word(char* str){
	int count = 0;
	bool reset = false;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z'){
			count++;
		}
		
		if(str[i] == ' '){
			reset = true;
		}
		
		if(reset && str[i] >= 'A' && str[i] <= 'Z' || reset && str[i] >= 'a' && str[i] <= 'z'){
			count = 1;
			reset = false;
		}
	}
	return count;
}

void test_equals_int(int result, int actual, int line){
	if(result == actual){
		printf("Test pass in Line %d.\n", line);
	} else {
		printf("expected [%d] differs from [%d] in Line %d.\n", actual, result, line);
	}
}

void main(){
	char a[] = "Hello World";	
	int result = length_of_last_word(a);
	int actual = 5;
	test_equals_int(result, actual, __LINE__);
	
	char b[] = " gonna catch them all  ";
	result = length_of_last_word(b);
	actual = 3;
	test_equals_int(result, actual, __LINE__);
	
	char c[] = "The best programmer ";
	result = length_of_last_word(c);
	actual = 10;
	test_equals_int(result, actual, __LINE__);
}