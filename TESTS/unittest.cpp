#include <UnitTest++.h>

TEST(CheckMacrosHaveNoSideEffects)
{
    int i = 4;
    CHECK_EQUAL(5, ++i); // succeeds
    CHECK_EQUAL(5, i); // succeeds
}

TEST(similarity)
{
    CHECK_CLOSE(1.34,1.343,0.01);
}

int main()
{
    return UnitTest::RunAllTests();
}
