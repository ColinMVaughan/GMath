#include <gtest/gtest.h>

int main(int ac, wchar_t* av[])
{

	testing::InitGoogleTest(&ac, av);
	RUN_ALL_TESTS();

	system("pause");
	return 0;
}