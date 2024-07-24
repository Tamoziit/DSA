#include <stdio.h>
#include <stdlib.h>
#define MAXROWS 100

struct complex {
    int real;
    int img;
};

typedef struct complex Complex;

Complex multiply2_Complex(Complex x, Complex y) {
    Complex res;
    res.real = (x.real * y.real) - (x.img * y.img);
    res.img = (x.real * y.img) + (x.img * y.real);
    return res;
}

Complex multiply_array_Complex(Complex arr[], int size) {
    Complex res;
    res.real = 1;
    res.img = 0;
    int i;
    for(i=0; i<size; i++) {
        res=multiply2_Complex(res, arr[i]);
    }
    return res;
}

int main() {
    Complex x, y, res1, res2;
    printf("Enter 1st complex no.\n");
    scanf("%d%d", &x.real, &x.img);
    printf("Enter 2nd complex no.\n");
    scanf("%d%d", &y.real, &y.img);
    res1 = multiply2_Complex(x, y);
    if(res1.img>0) {
        printf("Result 1 = %d + %di\n", res1.real, res1.img);
    } else {
        printf("Result 1 = %d %di\n", res1.real, res1.img);
    }

    Complex* arr = (Complex*)malloc(MAXROWS * sizeof(Complex));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    int i, ch=0;
    printf("Enter a group of complex nos. Enter -1 to stop, any other no. to continue when prompted.\n");
    while(1) {
        scanf("%d%d", &arr[i].real, &arr[i].img);
        printf("Continue?\n");
        scanf("%d", &ch);
        if(ch == -1)
            break;
        else
            i++;
    }
    res2=multiply_array_Complex(arr, i+1);
    if(res2.img>0) {
        printf("Result 2 = %d + %di\n", res2.real, res2.img);
    } else {
        printf("Result 2 = %d %di\n", res2.real, res2.img);
    }
    free(arr);
    return 0;
}