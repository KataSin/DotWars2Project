//���f���`�ʃN���X
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
	//�V���O���g��
	static Model &GetInstance() {
		static Model m;
		return m;
	}

};