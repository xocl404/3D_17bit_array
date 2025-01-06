#include <lib/matrix.h>
#include <gtest/gtest.h>

TEST(ConvertingTestsSuite, EqualTest) {
    Array arr = Array::MakeArray(32, 10, 17);

    arr[4][0][4] = 52;

    ASSERT_EQ(static_cast<uint32_t>(arr[4][0][4]), 52);
}

TEST(ConvertingTestsSuite, EquaLTest) {
    Array arr = Array::MakeArray(2, 2, 2);

    arr[0][0][0] = 1;
    arr[0][0][1] = 2;
    arr[0][1][0] = 3;
    arr[0][1][1] = 4;
    arr[1][0][0] = 5;
    arr[1][0][1] = 6;
    arr[1][1][0] = 7;
    arr[1][1][1] = 8;

    ASSERT_EQ(static_cast<uint32_t>(arr[1][0][0]), 5);
}

TEST(ConvertingTestsSuite, EquAlTest) {
    Array arr = Array::MakeArray(2, 2, 2);

    arr[1][1][0] = 52;

    ASSERT_EQ(static_cast<uint32_t>(arr[1][1][1]), 0);
}

TEST(ConvertingTestsSuite, Sum) {
    Array arr1 = Array::MakeArray(2, 2, 2);
    arr1[0][0][0] = 1;
    arr1[0][0][1] = 2;
    arr1[0][1][0] = 3;
    arr1[0][1][1] = 4;
    arr1[1][0][0] = 5;
    arr1[1][0][1] = 6;
    arr1[1][1][0] = 7;
    arr1[1][1][1] = 8;

    Array arr2 = Array::MakeArray(2, 2, 2);
    arr2[0][0][0] = 87;
    arr2[0][0][1] = 74;
    arr2[0][1][0] = 69;
    arr2[0][1][1] = 52;
    arr2[1][0][0] = 404;
    arr2[1][0][1] = 333;
    arr2[1][1][0] = 300;
    arr2[1][1][1] = 10;

    Array result = arr1 + arr2;
    EXPECT_EQ(static_cast<uint32_t>(result[0][0][0]), 88);
    EXPECT_EQ(static_cast<uint32_t>(result[0][0][1]), 76);
    EXPECT_EQ(static_cast<uint32_t>(result[0][1][0]), 72);
    EXPECT_EQ(static_cast<uint32_t>(result[0][1][1]), 56);
    EXPECT_EQ(static_cast<uint32_t>(result[1][0][0]), 409);
    EXPECT_EQ(static_cast<uint32_t>(result[1][0][1]), 339);
    EXPECT_EQ(static_cast<uint32_t>(result[1][1][0]), 307);
    EXPECT_EQ(static_cast<uint32_t>(result[1][1][1]), 18);
}

TEST(ArrayTest, Subtraction) {
    Array arr1 = Array::MakeArray(2, 2, 2);

    arr1[0][0][0] = 1;
    arr1[0][0][1] = 2;
    arr1[0][1][0] = 3;
    arr1[0][1][1] = 4;
    arr1[1][0][0] = 5;
    arr1[1][0][1] = 6;
    arr1[1][1][0] = 7;
    arr1[1][1][1] = 8;

    Array arr2 = Array::MakeArray(2, 2, 2);

    arr2[0][0][0] = 87;
    arr2[0][0][1] = 74;
    arr2[0][1][0] = 69;
    arr2[0][1][1] = 52;
    arr2[1][0][0] = 404;
    arr2[1][0][1] = 333;
    arr2[1][1][0] = 300;
    arr2[1][1][1] = 10;

    Array result = arr2 - arr1;
    EXPECT_EQ(static_cast<uint32_t>(result[0][0][0]), 86);
    EXPECT_EQ(static_cast<uint32_t>(result[0][0][1]), 72);
    EXPECT_EQ(static_cast<uint32_t>(result[0][1][0]), 66);
    EXPECT_EQ(static_cast<uint32_t>(result[0][1][1]), 48);
    EXPECT_EQ(static_cast<uint32_t>(result[1][0][0]), 399);
    EXPECT_EQ(static_cast<uint32_t>(result[1][0][1]), 327);
    EXPECT_EQ(static_cast<uint32_t>(result[1][1][0]), 293);
    EXPECT_EQ(static_cast<uint32_t>(result[1][1][1]), 2);
}



TEST(ArrayTest, Multiplication) {
    Array arr = Array::MakeArray(2, 2, 2);

    arr[0][0][0] = 1;
    arr[0][0][1] = 2;
    arr[0][1][0] = 3;
    arr[0][1][1] = 4;
    arr[1][0][0] = 5;
    arr[1][0][1] = 6;
    arr[1][1][0] = 7;
    arr[1][1][1] = 8;

    Array result = arr * 3;

    EXPECT_EQ(static_cast<uint32_t>(result[0][0][0]), 3);
    EXPECT_EQ(static_cast<uint32_t>(result[0][0][1]), 6);
    EXPECT_EQ(static_cast<uint32_t>(result[0][1][0]), 9);
    EXPECT_EQ(static_cast<uint32_t>(result[0][1][1]), 12);
    EXPECT_EQ(static_cast<uint32_t>(result[1][0][0]), 15);
    EXPECT_EQ(static_cast<uint32_t>(result[1][0][1]), 18);
    EXPECT_EQ(static_cast<uint32_t>(result[1][1][0]), 21);
    EXPECT_EQ(static_cast<uint32_t>(result[1][1][1]), 24);
}
