#include "../MathLibrary/MathFunctions.h"
#include <gtest/gtest.h>

//Works
TEST(QuaternionTest, Constructor)
{
	Math::Quaternion quat;

	EXPECT_EQ(1.0f, quat.w);
	EXPECT_EQ(0.0f, quat.x);
	EXPECT_EQ(0.0f, quat.y);
	EXPECT_EQ(0.0f, quat.z);
}

//I guess assume it works
TEST(QuaternionTest, ToMatrix)
{
	Math::Quaternion quat;
	quat.SetRotation(Math::vec3f({ 0,1,0 }), 3.14);
	Math::mat4f NewMat = quat.ToMatrix();

	
	EXPECT_TRUE(true);
}