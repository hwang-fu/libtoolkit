{
    printf("Testing module " CRAYON_TO_BOLD(CRAYON_TO_YELLOW("s")) "...\n");

    u64 cases = 1;

    {
        OWNED char * s = strdup_safe("abcdef");
        ASSERT_EXPR(strcmp_safe(s, "abcdef"));
        ASSERT_EXPR(strncmp_safe(s, "a", 1));
        ASSERT_EXPR(strncmp_safe(s, "ab", 2));
        ASSERT_EXPR(strncmp_safe(s, "abc", 3));
        ASSERT_EXPR(strncmp_safe(s, "abcd", 4));
        ASSERT_EXPR(strncmp_safe(s, "abcde", 5));
        ASSERT_EXPR(strncmp_safe(s, "abcdef", 6));
        dispose(s);
        pass(cases++);
    }

    {
    }

    {
    }
}
