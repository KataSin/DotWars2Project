#include "NetVec3.h"
#include "Math.h"
#include <cmath>
#include <sstream>

NetVec3::NetVec3()
	: x(0), y(0), z(0)
{

}

NetVec3::NetVec3(float s)
	: x((short int)s), y((short int)s), z((short int)s)
{

}

NetVec3::NetVec3(float x, float y)
	: x(x), y(y), z(0)
{

}

NetVec3::NetVec3(float x, float y, float z)
	: x((short int)x), y((short int)y), z((short int)z)
{

}

NetVec3::NetVec3(int s)
	: x(s), y(s), z(s)
{

}

NetVec3::NetVec3(int x, int y)
	: x(x), y(y), z(0)
{

}

NetVec3::NetVec3(int x, int y, int z)
	: x(x), y(y), z(z)
{

}

NetVec3::NetVec3(const NetVec3& vector)
	: x(vector.x), y(vector.y), z(vector.z)
{

}

NetVec3::NetVec3(const VECTOR& vector)
	: x((short int)vector.x), y((short int)vector.y), z((short int)vector.z)
{

}


NetVec3 NetVec3::ToNetVec3(const Vector3 & vec)
{
	NetVec3 result;
	result.x = (short int)vec.x;
	result.y = (short int)vec.y;
	result.z = (short int)vec.z;
	return result;
}

Vector3 NetVec3::ToVector3(const NetVec3& vec)
{
	Vector3 result;
	result.x = (float)vec.x;
	result.y = (float)vec.y;
	result.z = (float)vec.z;
	return result;
}
