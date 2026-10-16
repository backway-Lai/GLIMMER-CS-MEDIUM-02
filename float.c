#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int trans(char input[]) {
	int value = 0;

	for (int i = 0;i <= 7;i++) {
		value = value * 2 + (input[i] - '0');
	}
	
	return value;
}

int function1(int x) {                         //求阶码
	x = x >> 3;
	x &= 15;
	return x;
}

int function2(int x) {
	x &= 7;                                    //求尾数
	return x;
}

int main() {
	char inputA[9], inputB[9];

	scanf("%8s %8s", inputA, inputB);

	int A = trans(inputA);                       //AB是十进制数
	int B = trans(inputB);

	int a = function1(A);                        //ab是阶码值
	int b = function1(B);

	int i = function2(A);                        //ij是尾数值
	int j = function2(B);

	int I = i | 8;                               //IJ是有效数字（乘以八）
	int J = j | 8;

	if (a <= b) {                                 //对阶
		I = I >> (b - a);
		a = b;
	}
	else {
		J = J >> (a - b);
		b = a;
	}

	int f = I + J;                               //尾数运算

	if (f >= 16) {
		f = f >> 1;
		a++;
	}

	int result = (a << 3) | (f & 7);

	for (int k = 7;k >= 0;k--) {
		printf("%d", (result >> k) & 1);
	}

	printf("\n");

	return 0;

}