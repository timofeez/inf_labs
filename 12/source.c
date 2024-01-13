#include <stdio.h>

#define ABS(a) ((a) >= 0 ? (a) : -(a))

int power(int a, int b) {
	int result = a;
	for (int i = 0; i < b - 1; ++i) {
		result *= a;
	}
	return result;
}
int main(void){
    int ans;
    scanf("%d", &ans);

        int ans1 = ABS(ans);
        int q = 0;

        while (ans1 != 0){
            q += 1;
            ans1 /= 10;
        }
		if (q == 2){
            printf("0\n");
			return 0;
        }
		ans = (ans / 100) * 10 + ans % 10;
		printf("%d\n", (ans / (power(10, q-2)) * power(10, q-3)) + ans % (power(10, q - 3)));

}