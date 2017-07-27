//--------------------------------//
//--------���f���`�ʃN���X--------//
//---------�쐬:�Љ��C��----------//
//--------------------------------//
#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
//�O���t�B�b�NID
#include "../GraphicID.h"
//Math�֌W
#include "../../Math/Vector3.h"
#include "../../Math/Matrix4.h"
#include "../../Math/Vector4.h"
class Model
{
private:
	Model() = default;
	~Model();
public:
	/// <summary>
	/// �C���X�^���X���擾����
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static Model &GetInstance() {
		static Model m;
		return m;
	}

public:
	/// <summary>
	/// 3D���f���̓ǂݍ���(�t�@�C�����A���f��ID)
	/// </summary>
	/// <param name="name">�t�@�C����</param>
	/// <param name="id">���f��ID</param>
	void Load(const std::string& name, const MODEL_ID& id);
	/// <summary>
	/// <summary>
	/// 3D���f���̓ǂݍ���(���f���̂����蔻����g�������ꍇ)
	/// </summary>
	/// <param name="name">�t�@�C����</param>
	/// <param name="id">���f��ID</param>
	void LoadCollision(const std::string& name, const MODEL_ID& id);
	/// <summary>
	/// 3D���f���̍폜
	/// </summary>
	/// <param name="id">���f��ID</param>
	void Delete(const MODEL_ID& id);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A���W)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="position">���W</param>
	void Draw(const MODEL_ID& id, const Vector3& position);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A���W�A���l)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	void Draw(const MODEL_ID& id, const Vector3& position, float alpha);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A���W�A��]��)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="position">���W</param>
	/// <param name="rotate">��]��</param>
	void Draw(const MODEL_ID& id, const Vector3& position, const Vector3& rotate);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A���W�A���l�A��]��)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="rotate">��]��</param>
	void Draw(const MODEL_ID& id, const Vector3& position, float alpha, const Vector3& rotate);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A���W�A��]�ʁA�g���)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="position">���W</param>
	/// <param name="rotate">��]��</param>
	/// <param name="scale">�g���</param>
	void Draw(const MODEL_ID& id, const Vector3& position, const Vector3& rotate, const Vector3& scale);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A���W�A���l�A��]�ʁA�g���)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="rotate">��]��</param>
	/// <param name="scale">�g���</param>
	void Draw(const MODEL_ID& id, const Vector3& position, float alpha, const Vector3& rotate, const Vector3& scale);
	/// <summary>
	///  3D���f���̕`��(���f��ID�A���W�A���l�A��]�ʁA�g��ʁA�f�B�t���[�Y�J���[)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="rotate">��]��</param>
	/// <param name="scale">�g�嗦</param>
	/// <param name="diffusecolor">�f�B�t�F�[�Y�J���[</param>
	void Draw(const MODEL_ID& id, const Vector3& position, float alpha, const Vector3& rotate, const Vector3& scale, const Vector4& diffusecolor);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A�}�g���N�X)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="mat">�}�g���N�X</param>
	void Draw(const MODEL_ID& id, const Matrix4& mat);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A�}�g���N�X�A���l)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="mat">�}�g���N�X</param>
	/// <param name="alpha">���l</param>
	void Draw(const MODEL_ID& id, const Matrix4& mat, float alpha);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A�}�g���N�X�A�f�B�t���[�Y�J���[)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="mat">�}�g���N�X</param>
	/// <param name="diffusecolor">�f�B�t�F�[�Y�J���[</param>
	void Draw(const MODEL_ID& id, const Matrix4& mat, const Vector4& diffusecolor);
	/// <summary>
	/// 3D���f���̕`��(���f��ID�A�}�g���N�X�A���l�A�f�B�t���[�Y�J���[)
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="mat">�}�g���N�X</param>
	/// <param name="alpha">���l</param>
	/// <param name="diffusecolor">�f�B�t�F�[�Y�J���[</param>
	void Draw(const MODEL_ID& id, const Matrix4& mat, float alpha, const Vector4& diffusecolor);

	/// <summary>
	/// �r���{�[�h�`�ʂ�����
	/// </summary>
	void DrawBillboard(const SPRITE_ID& id, const Vector3& position);


	//���f���̃n���h�����
	class ModelHandle {
	public:
		ModelHandle();
		~ModelHandle();
	public:
		/// <summary>
		/// �n���h�����擾
		/// </summary>
		int GetHandle();
		/// <summary>
		/// ���f����ǂݍ���
		/// </summary>
		/// <param name="fileName">�t�@�C����</param>
		void Load(const std::string fileName);
		/// <summary>
		/// �폜
		/// </summary>
		void Delete();
		/// <summary>
		/// ���f���̂����蔻����g���ꍇ�Ă�
		/// </summary>
		void CollisionInitialize();
		/// <summary>
		/// ���f���̂����蔻����X�V
		/// </summary>
		void CollisionUpdate();

	private:
		//���f���n���h��
		int handle;
	};

private:
	//�X�}�[�g�|�C���^�[
	using HandlePtr = std::shared_ptr<ModelHandle>;
	//���f���n���h�����
	std::unordered_map<MODEL_ID, HandlePtr> mModels;



public:
	/// <summary>
	/// ID���烂�f���n���h�����擾
	/// </summary>
	HandlePtr GetModelHandle(const MODEL_ID& id);

};