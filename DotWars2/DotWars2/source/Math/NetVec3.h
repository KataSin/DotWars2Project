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
	/// コンストラクタ
	///</summary>
	NetVec3();
	///<summary>
	/// コンストラクタ
	///</summary>
	NetVec3(float s);
	///<summary>
	/// コンストラクタ
	///</summary>
	NetVec3(float x, float y);
	///<summary>
	/// コンストラクタ
	///</summary>
	NetVec3(float x, float y, float z);
	///<summary>
	/// コンストラクタ
	///</summary>
	NetVec3(int s);
	///<summary>
	/// コンストラクタ
	///</summary>
	NetVec3(int x, int y);
	///<summary>
	/// コンストラクタ
	///</summary>
	NetVec3(int x, int y, int z);
	///<summary>
	/// コンストラクタ
	///</summary>
	NetVec3(const NetVec3& vector);
	///<summary>
	/// コンストラクタ
	///</summary>
	NetVec3(const VECTOR& vector);


public:
	///<summary>
	/// NetVec3をVector3に変換する
	///</summary>
	static Vector3 ToVector3(const NetVec3& vec);
	
	static NetVec3 ToNetVec3(const Vector3& vec);
};