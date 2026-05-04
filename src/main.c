int main(int argc, char **argv)
{
    printf("Running application...\n");

#ifdef RUN_TESTS
    printf("Running tests...\n");
    return run_all_tests();
#endif

    printf("Hello world\n");
    return 0;
}
