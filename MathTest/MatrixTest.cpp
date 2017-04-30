#include <gtest/gtest.h>
#include "../MathLibrary/MathLibrary.h"

#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

void OutputMatrix(GMath::mat4f &matrix)
{

	std::cout << "\n\n";
	std::cout << "Matrix Output: \n";
	std::cout << matrix(0, 0) << " " << matrix(1, 0) << " " << matrix(2, 0) << " " << matrix(3, 0) << "\n";
	std::cout << matrix(0, 1) << " " << matrix(1, 1) << " " << matrix(1, 1) << " " << matrix(3, 1) << "\n";
	std::cout << matrix(0, 2) << " " << matrix(1, 2) << " " << matrix(2, 2) << " " << matrix(3, 2) << "\n";
	std::cout << matrix(0, 3) << " " << matrix(1, 3) << " " << matrix(2, 3) << " " << matrix(3, 3) << "\n";
}


TEST(MatrixTest, DefaultConstructor)
{
	GMath::mat4f test;
	for(int y = 0; y< 4; ++y)
	{
		for (int x = 0; x< 4; ++x)
		{
			EXPECT_EQ(0, test(x, y));
		}
	}
}

TEST(MatrixTest, SecondConstructor)
{
	GMath::mat4f test(1);
	for (int y = 0; y< 4; ++y)
	{
		for (int x = 0; x< 4; ++x)
		{
			EXPECT_EQ(1, test(x, y));
		}
	}
}


TEST(MatrixTest, Indexing)
{
	GMath::mat4f mat;

	mat(3, 0) = 1.0f;
	mat(3, 1) = 1.0f;
	mat(3, 2) = 1.0f;
	mat(3, 3) = 1.0f;


	EXPECT_EQ(1, mat(15));
	EXPECT_EQ(1, mat(14));
	EXPECT_EQ(1, mat(13));
	EXPECT_EQ(1, mat(12));
}

TEST(MatrixTest, Equality)
{
	GMath::mat4f mat1;
	GMath::mat4f mat2;

	mat1(0, 0) = 1.0f;

	EXPECT_FALSE(mat1 == mat2);
}

TEST(MatrixTest, Assignment)
{
	GMath::mat4f mat1;
	GMath::mat4f mat2;

	mat1(0, 0) = 1.0f;
	mat1(1, 0) = 2.0f;
	mat1(2, 0) = 3.0f;
	mat1(3, 0) = 4.0f;

	mat2 = mat1;

	EXPECT_EQ(1.0f, mat2(0, 0));
	EXPECT_EQ(2.0f, mat2(1, 0));
	EXPECT_EQ(3.0f, mat2(2, 0));
	EXPECT_EQ(4.0f, mat2(3, 0));
}

TEST(MatrixTest, Multiply)
{

	GMath::mat4f mat;
	mat(0, 0) = 1.0f;
	mat(1, 1) = 1.0f;
	mat(2, 2) = 1.0f;
	mat(3, 3) = 1.0f;

	mat(3, 0) = 5.0f;
	mat(3, 1) = 5.0f;
	mat(3, 2) = 5.0f;

	GMath::mat4f mat2;
	mat2(0, 0) = 1.0f;
	mat2(1, 1) = 1.0f;
	mat2(2, 2) = 1.0f;
	mat2(3, 3) = 1.0f;

	mat2(3, 0) = 5.0f;
	mat2(3, 1) = 5.0f;
	mat2(3, 2) = 5.0f;

	GMath::mat4f result = mat * mat2;
	


	OutputMatrix(result);
	EXPECT_TRUE(true);
}

TEST(MatrixTest, IdentityMatrix)
{
	
}

TEST(MatrixTest, VectorMultiply)
{
	GMath::mat4f mat;
	mat(0, 0) = 1.0f;
	mat(1, 1) = 1.0f;
	mat(2, 2) = 1.0f;
	mat(3, 3) = 1.0f;

	mat(3, 0) = 5.0f;
	mat(3, 1) = 5.0f;
	mat(3, 2) = 5.0f;

	GMath::vec4f vec({1,2,3,1});
	GMath::vec4f result;

	result = mat * vec;


	std::cout << "Vector Output: \n" << result[0] << "," << result[1] << "," << result[2] << "\n";
	EXPECT_EQ(6, result[0]);
	EXPECT_EQ(7, result[1]);
	EXPECT_EQ(8, result[2]);
}

TEST(MatrixTest, Projection)
{
	GMath::mat4f TestMat;
	glm::mat4x4 CorrectMat;

	GMath::SetFrustumProjection(TestMat, 90, (16.0 / 9.0), 0.01, 1000);
	CorrectMat = glm::perspective(90.0, (16.0 / 9.0), 0.01, 1000.0);


	EXPECT_TRUE(true);
}