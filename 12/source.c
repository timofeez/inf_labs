#include <stdio.h>

int length(int n) {
	if (n < 0) n = -n;
    if (n == 0) return 1;
    int l = 0;
    while(n) {
        l++;
        n /= 10;
        }
    return l;
    }

int main() {
	int number;
	scanf("%d", &number);
	int sign = number < 0;
	if (sign) number = -number;
	int len = length(number);
	if (len <= 2) {
		return 1;
	}	
	int temp = number;
	int digits[len];
	for (int i = len - 1; i >= 0; i--) {
        digits[i] = temp % 10;
        temp /= 10;
    }
	digits[len - 2] = -1;
	digits[1] = -1;
	if (sign) printf("-");	
	for (int i = 0; i < len; i++) {
		if (digits[i] != -1) {
			printf("%d", digits[i]);
		}
	}
	printf("\n");
	return 0;

}
