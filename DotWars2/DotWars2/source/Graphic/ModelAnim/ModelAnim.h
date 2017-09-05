//----------------------------------------------//
//--------���f���A�j���[�V�����`�ʃN���X--------//
//---------------�쐬:�Љ��C��------------------//
//----------------------------------------------//
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
class ModelAnim {

private:
	ModelAnim() = default;
	~ModelAnim() {};
public:
	/// <summary>
	/// �C���X�^���X���擾����
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static ModelAnim &GetInstance() {
		static ModelAnim m;
		return m;
	}
public:
	/// <summary>
	/// 3D���f���̓ǂݍ���(�t�@�C�����A�A�j�����f��ID�A�ŏ��̃��[�V����ID)
	/// </summary>
	/// <param name="name">�t�@�C����</param>
	/// <param name="id">�A�j�����f��ID</param>
	void Load(const std::string& name, const MODEL_ANIM_ID& id,const MODEL_MOTION_ID& motionId);
	/// <summary>
	/// 3D���f���̍폜
	/// </summary>
	/// <param name="id">���f��ID</param>
	void Delete(const MODEL_ANIM_ID& id);
	/// <summary>
	/// �A�j���[�V�������A�^�b�`����(�A�j���[�V�������f��ID�A���[�V����ID)
	/// </summary>
	/// <param name="id">�A�j���[�V�������f��ID</param>
	/// <param name="motionID">���[�V����ID</param>
	void AttachAnim(const MODEL_ANIM_ID&id, const MODEL_MOTION_ID& motionID);
	/// <summary>
	/// �A�j���[�V�������f�^�b�`����(�A�j���[�V�������f��ID�A���[�V����ID)
	/// </summary>
	/// <param name="id">�A�j���[�V�������f��ID</param>
	/// <param name="motionID">���[�V����ID</param>
	void DetachAnim(const MODEL_ANIM_ID& id, const MODEL_MOTION_ID& motionID);
	/// <summary>
	/// ���[�V�������`�F���W����
	/// </summary>
	/// <param name="id">���f��ID</param>
	/// <param name="motionId">���[�V����ID</param>
	void ChangeAnim(const MODEL_ANIM_ID& id, const MODEL_MOTION_ID& motionId);
	/// <summary>
	/// �A�j���[�V�������Đ�����(���f���A�j���[�V����ID)
	/// </summary>
	/// <param name="id">���f���A�j���[�V����ID</param>
	void StartAnim(const MODEL_ANIM_ID& id);
	/// <summary>
	/// �A�j���[�V�������~������(���f���A�j���[�V����ID)
	/// </summary>
	/// <param name="id">���f���A�j���[�V����ID</param>
	void StopAnim(const MODEL_ANIM_ID& id);

	/// <summary>
	/// �A�b�v�f�[�g
	/// </summary>
	void Update();
	/// <summary>
	/// �A�j���[�V�������f����`��(�A�j���[�V�������f��ID�A�}�g���b�N�X�A���l�A�f�B�t�F�[�Y�J���[)
	/// </summary>
	/// <param name="id">�A�j���[�V�������f��ID</param>
	/// <param name="mat">�}�g���b�N�X</param>
	/// <param name="alpha">���l</param>
	/// <param name="color">�f�B�t�F�[�Y�J���[</param>
	void Draw(const MODEL_ANIM_ID& id, const Matrix4& mat, float alpha = 1.0f, const Vector4& diffuse = Vector4(255, 255, 255, 1));
	/// <summary>

private:




	/// ���f���n���h�����
	/// </summary>
	class ModelAnimHandle {
	public:
		struct AttachState
		{
			int index;
			float animTime;
			float animAllTime;
		};
	public:
		ModelAnimHandle();
		~ModelAnimHandle();
	public:
		/// <summary>
		/// �n���h�����擾
		/// </summary>
		int GetHandle();
		/// <summary>
		/// ���f����ǂݍ���
		/// </summary>
		/// <param name="fileName">�t�@�C����</param>
		/// <param name="motionId">�ŏ��ɍĐ������郂�[�V����ID</param>
		void Load(const std::string fileName, const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// �폜
		/// </summary>
		void Delete();
		/// <summary>
		/// <summary>
		/// �A�j���[�V�������A�^�b�`����(���[�V����ID)
		/// </summary>
		/// <param name="motionId">���[�V����ID</param>
		void Attach(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// �A�j���[�V�������f�^�b�`����(���[�V����ID)
		/// </summary>
		/// <param name="motionId">���[�V����ID</param>
		void Detach(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// �A�^�b�`�C���f�b�N�X���擾����(���[�V����ID)
		/// </summary>
		/// <param name="motionId">���[�V����ID</param>
		/// <returns></returns>
		int GetAttachIndex(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// �A�j���[�V�����̑����Ԃ�Ԃ�
		/// </summary>
		/// <param name="motionId">���[�V����ID</param>
		/// <returns>�A�j���[�V����������</returns>
		float GetAllAnimTime(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// �A�j���[�V�����^�C����ݒ肷��
		/// </summary>
		/// <param name="motionId">���[�V����ID</param>
		/// <param name="time">�A�j���^�C��</param>
		void SetAnimTime(const MODEL_MOTION_ID& motionId, float time);
		/// <summary>
		/// �A�j���[�V�������X�^�[�g������
		/// </summary>
		void StartAnim();
		/// <summary>
		/// �A�j���[�V�������X�g�b�v������
		/// </summary>
		void StopAnim();
		/// <summary>
		/// �A�j���[�V�������`�F���W
		/// </summary>
		/// <param name="motionId"></param>
		void ChangeAnim(const MODEL_MOTION_ID& motionId);
		/// <summary>
		/// �A�b�v�f�[�g
		/// </summary>
		void Update();
	private:
		//�Đ����Ă��邩
		bool isPlay;
		//���ݍĐ�����Ă��郂�[�V����
		MODEL_MOTION_ID CurMotionId;
		//�O�ɍĐ�����Ă������[�V����
		MODEL_MOTION_ID PreMotionId;
		//�ڍs��Ԓ���
		bool isLerpAnim;
	private:
		int handle;
		float animAllTime;
		//��ԗp�^�C��
		float lerpAnimTime;
		//�A�^�b�`����Ă��郂�[�V��������
		std::unordered_map<MODEL_MOTION_ID, AttachState >mAttachNums;
	};

private:

	//�X�}�[�g�|�C���^�[
	using HandlePtr = std::shared_ptr<ModelAnimHandle>;
	//���f���n���h�����
	std::unordered_map<MODEL_ANIM_ID, HandlePtr> mModels;
};