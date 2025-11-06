{
    u64 cases = 1;

    {
        Dequeue * dq = mk_dq(0);
        if (EQ(dq, NIL))
        {
            fail(cases);
        }
        dq_dispose(dq);
        pass(cases++);
    }

    {
        Dequeue * dq = mk_dq(0);
        dq_pushback(dq, 1);
        dq_pushback(dq, 2);
        dq_pushback(dq, 3);
        dq_pushback(dq, 4);
        dq_pushback(dq, 5);

        ASSERT_EXPR(EQ(
                    dq_popback(dq),
                    5
        ));
        ASSERT_EXPR(EQ(
                    dq_popback(dq),
                    4
        ));
        ASSERT_EXPR(EQ(
                    dq_popback(dq),
                    3
        ));
        ASSERT_EXPR(EQ(
                    dq_popback(dq),
                    2
        ));
        ASSERT_EXPR(EQ(
                    dq_popback(dq),
                    1
        ));

        dq_dispose(dq);
        pass(cases++);
    }

    {
        Dequeue * dq = mk_dq(0);
        dq_pushback(dq, 1);
        dq_pushback(dq, 2);
        dq_pushback(dq, 3);
        dq_pushback(dq, 4);
        dq_pushback(dq, 5);

        ASSERT_EXPR(EQ(
                    dq_popfront(dq),
                    1
        ));
        ASSERT_EXPR(EQ(
                    dq_popfront(dq),
                    2
        ));
        ASSERT_EXPR(EQ(
                    dq_popfront(dq),
                    3
        ));
        ASSERT_EXPR(EQ(
                    dq_popfront(dq),
                    4
        ));
        ASSERT_EXPR(EQ(
                    dq_popfront(dq),
                    5
        ));

        dq_dispose(dq);
        pass(cases++);
    }

    {
        Dequeue * dq = mk_dq(2, dispose);
        dq_pushback(dq, strdup_safe("A"));
        dq_pushback(dq, strdup_safe("B"));
        dq_pushback(dq, strdup_safe("C"));
        dq_pushback(dq, strdup_safe("D"));
        dq_dispose(dq);

        pass(cases++);
    }

    {
        Dequeue * dq = mk_dq(3, 0, dispose);
        dq_pushback(dq, strdup_safe("A"));
        dq_pushback(dq, strdup_safe("B"));
        dq_pushback(dq, strdup_safe("C"));
        dq_pushback(dq, strdup_safe("D"));

        dq_dispose(dq);
        pass(cases++);
    }

    {
        Dequeue * dq = mk_dq(3, 2, dispose);
        dq_pushback(dq, strdup_safe("A"));
        dq_pushback(dq, strdup_safe("B"));
        dq_pushback(dq, strdup_safe("C"));
        dq_pushback(dq, strdup_safe("D"));
        dq_pushback(dq, strdup_safe("a"));
        dq_pushback(dq, strdup_safe("b"));
        dq_pushback(dq, strdup_safe("c"));
        dq_pushback(dq, strdup_safe("d"));

        dq_dispose(dq);
        pass(cases++);
    }
}
