#include <stdio.h>

#ifdef RUN_TESTS // TEST FLAG
int run_all_tests();   
#endif

int main()
{
#ifdef RUN_TESTS
    printf("Running tests...\n");
    return run_all_tests();
#else
    printf("Running application...\n");

    // ton code temporaire ici
    printf("Hello world\n");

    return 0;
#endif
}
