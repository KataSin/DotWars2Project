//モデル描写クラス
#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Model
{
private:
	Model() = default;
	~Model();



public:
	//シングルトン
	static Model &GetInstance() {
		static Model m;
		return m;
	}

};