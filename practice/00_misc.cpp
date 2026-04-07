// gcc -o lambda --std=gnu99 lambda.c

#define lambda(lambda$_ret, lambda$_args, lambda$_body) \
    (                                                   \
        {                                               \
            lambda$_ret lambda$__anon$ lambda$_args     \
                lambda$_body                            \
                    &amp;                               \
            lambda$__anon$;                             \
        })

#ifdef _TEST_LAMBDA

#include <stdio.h>

float average_apply(float (*fn)(float inp))
{
    int i, n = sizeof(thelist) / sizeof(thelist[0]);
    float avg = 0.0;
    for (i = 0; i < n; i++)
    {
        avg += fn(thelist[i]);
        printf("Running sum=%f\n", avg);
    }

    return avg / n;
}

int main(void)
{
    printf("%f\n", average_apply(lambda(float, (float x), { return 2 * x; })));
    printf("%f\n", average_apply(lambda(float, (float x), { return x / 3.0; })));
    return 0;
}

#endif
