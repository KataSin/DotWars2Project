#pragma once
#include "Vector3.h"
#include <Dxlib.h>
#include <string>
class NetVec3
{
public:
	short int x;
	short int y;
	short int z;

public:
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3();
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3(float s);
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3(float x, float y);
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3(float x, float y, float z);
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3(int s);
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3(int x, int y);
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3(int x, int y, int z);
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3(const NetVec3& vector);
	///<summary>
	/// �R���X�g���N�^
	///</summary>
	NetVec3(const VECTOR& vector);


public:
	///<summary>
	/// NetVec3��Vector3�ɕϊ�����
	///</summary>
	static Vector3 ToVector3(const NetVec3& vec);
	
	static NetVec3 ToNetVec3(const Vector3& vec);
};