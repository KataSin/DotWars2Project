#pragma once
#include <DxLib.h>
#include <string>
#include <vector>
#include <unordered_map>
//�O���t�B�b�NID
#include "../GraphicID.h"
//Math�֌W
#include "../../Math/Vector2.h"
#include "../../Math/Vector4.h"

class SpriteAnim {

private:
	//�A�j���[�V�������
	struct AnimState
	{
		//�摜�n���h��
		std::vector<int>handles;
		//�A�j���[�V�����t���[���ԍ�
		int frame = 0;
		//�A�j���[�V�����^�C��
		float time = 0.0f;
		//�A�j���[�V�����X�s�[�h
		float animSpeed = 1.0f;
		//�A�j���[�V�����Đ�����Ă��邩�H
		bool isPlayAnim = false;
		//�A�j���[�V���������[�v���邩�H
		bool isLoopAnim = false;
	};
private:
	SpriteAnim() = default;
	~SpriteAnim();
public:
	/// <summary>
	/// �C���X�^���X���擾����
	/// </summary>
	/// <returns>�X�v���C�g�A�j���[�V�����C���X�^���X</returns>
	static SpriteAnim &GetInstance() {
		static SpriteAnim sa;
		return sa;
	}
public:
	/// <summary>
	/// 2D�A�j���[�V�����X�v���C�g��ǂݍ���(�t�@�C�����A�X�v���C�g�A�j���[�V����ID�A���ׂẲ摜�̕������A�c�Ɖ��̕������A��̉摜�̑傫��)
	/// </summary>
	/// <param name="fileName">�t�@�C����</param>
	/// <param name="id">�X�v���C�g�A�j���[�V����ID</param>
	/// <param name="allNum">�S�Ẳ摜�̕�����</param>
	/// <param name="num">�c�Ɖ��̕�����</param>
	/// <param name="size">��̉摜�̑傫��</param>
	void Load(const std::string& fileName, const SPRITE_ANIM_ID& id, int allNum, const Vector2& num, const Vector2& size);
	/// <summary>
	/// �w�肵���A�j���[�V�����X�v���C�g���폜����
	/// </summary>
	/// <param name="id">�X�v���C�g�A�j���[�V����ID</param>
	void Delete(const SPRITE_ANIM_ID& id);
	/// <summary>
	/// �w�肵���A�j���[�V�����̍Đ�(�A�j���[�V�����X�v���C�gID�A�A�j���[�V�����X�s�[�h�A���[�v�����邩�A�ŏ�����Đ������邩)
	/// </summary>
	/// <param name="id">�A�j���[�V�����X�v���C�gID</param>
	/// <param name="speed">�A�j���[�V�����Đ��X�s�[�h</param>
	/// <param name="first">�ŏ�����Đ������邩(true:�A�j���[�V�����̍ŏ����� false:�O��X�g�b�v�����Ƃ��납��)</param>
	void Start(const SPRITE_ANIM_ID& id, float speed, bool loop, bool first);
	/// <summary>
	/// �w�肵���A�j���[�V�������X�g�b�v(�A�j���[�V�����X�v���C�gID)
	/// </summary>
	/// <param name="id">�X�v���C�g�A�j���[�V����ID</param>
	void Stop(const SPRITE_ANIM_ID& id);
	/// <summary>
	/// �A�j���[�V������\��������
	/// </summary>
	/// <param name="id">�A�j���[�V�����X�v���C�gID</param>
	/// <param name="position">�\�����W</param>
	/// <param name="alpha">���l</param>
	/// <param name="angle">��]��</param>
	/// <param name="scale">�g���</param>
	/// <param name="color">�J���[</param>
	void Draw(const SPRITE_ANIM_ID& id, const Vector2& position, float alpha, float angle, const Vector2& scale = Vector2::One, const Vector4& color = Vector4(255, 255, 255, 255));
	/// <summary>
	/// �A�j���[�V�����A�b�v�f�[�g
	/// </summary>
	void Update();
	/// <summary>
	/// �Đ�����t���[����ݒ�
	/// </summary>
	/// <param name="id">�A�j���[�V�����X�v���C�gID</param>
	/// <param name="frame">�t���[����</param>
	void SetFrame(const SPRITE_ANIM_ID& id,int frame);

private:
	//�A�j���[�V�������
	std::unordered_map<SPRITE_ANIM_ID, AnimState> mAnimSprites;
};