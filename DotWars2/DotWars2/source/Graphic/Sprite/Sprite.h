//--------------------------------//
//-----�X�v���C�g�`�ʃN���X-------//
//---------�쐬:�Љ��C��----------//
//--------------------------------//
#pragma once

#include <unordered_map>
#include <string>
//Math�n
#include "../../Math/Math.h"
#include "../../Math/Vector2.h"
#include "../../Math/Vector4.h"
//ID
#include "../GraphicID.h"


class Sprite
{
private:
	Sprite() = default;
	~Sprite();
public:
	static Sprite &GetInstance() {
		static Sprite s;
		return s;
	}

	/// <summary>
	/// �摜�����[�h����(�t�@�C�����A�X�v���C�gID)
	/// </summary>
	/// <param name="fileName">�t�@�C����</param>
	/// <param name="id">�X�v���C�gID</param>
	void Load(const std::string& fileName, const SPRITE_ID& id);

	/// <summary>
	/// �w�肵���摜���폜����(�X�v���C�gID)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	void Delete(const SPRITE_ID& id);
	/// <summary>
	/// �S�Ă̓ǂݍ��񂾉摜���폜����
	/// </summary>
	void AllDelete();
	/// <summary>
	/// �摜��\������(�X�v���C�gID�A���W)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	void Draw(const SPRITE_ID& id, const Vector2& position);
	/// <summary>
	/// �摜��\������(�X�v���C�gID�A���W�A���l)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha);
	/// <summary>
	/// �摜��\������(�X�v���C�gID�A���W�A���l�A�g��ʁA���_)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="scale">�g���</param>
	/// <param name="origin">���_</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, const Vector2& scale, const Vector2& origin = Vector2::Zero);
	/// <summary>
	/// �摜��\������(�X�v���C�gID�A���W�A���l�A�g��ʁA�J���[�A���_)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="scale">�g���</param>
	/// <param name="color">�J���[</param>
	/// <param name="origin">���_</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, const Vector2& scale, const Vector4& color, const Vector2& origin = Vector2::Zero);

	/// <summary>
	/// �摜��\������(�X�v���C�gID�A���W�A���l�A��]��(�x���@)�A���_)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="angle">��]��(�x���@)</param>
	/// <param name="origin">���_</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, float angle, const Vector2& origin = Vector2::Zero);
	/// <summary>
	/// �摜��\������(�X�v���C�gID�A���W�A���l�A��]��(�x���@)�A�J���[�A���_)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="angle">��]��(�x���@)</param>
	/// <param name="color">�J���[</param>
	/// <param name="origin">���_</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, float angle, const Vector4& color, const Vector2& origin = Vector2::Zero);

	/// <summary>
	/// �摜��\������(�X�v���C�gID�A���W�A���l�A�X�P�[���A���_)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="angle">��]��</param>
	/// <param name="scale">�g���</param>
	/// <param name="origin">���_</param>
	void Draw(const SPRITE_ID& id, const Vector2& position, float alpha, float angle, const Vector2& scale, const Vector2& origin = Vector2::Zero);


	/// <summary>
	/// �~�O���t�I�ȃQ�[�W��\������(�X�v���C�gID�A���W�A���l�A�J���[�A�Q�[�W�J�E���g(0�`100))
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	/// <param name="alpha">���l</param>
	/// <param name="color">�J���[</param>
	/// <param name="gaugeCount">�Q�[�W�J�E���g(0�`100)</param>
	void DrawGaugeCircle(const SPRITE_ID & id, const Vector2 & position, float alpha, const Vector4 & color, float gaugeCount);

	/// <summary>
	/// �Q�[�W��\������(��������)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <param name="position">���W</param>
	/// <param name="color">�J���[</param>
	/// <param name="scale">�g���</param>
	/// <param name="alpha">���l</param>
	/// <param name="gaugeCount">�Q�[�W�J�E���g(0�`100)</param>
	void DrawGauge(const SPRITE_ID & id, const Vector2 & position, const Vector4& color, Vector2 & scale, float alpha, float gaugeCount);

	/// <summary>
	/// �X�v���C�g�̒��S���W���擾����(�X�v���C�gID)
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <returns>�X�v���C�g�̒��S���W</returns>
	Vector2 GetSpriteCenter(const SPRITE_ID& id);

	/// <summary>
	/// �X�v���C�g�̃T�C�Y���擾
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <returns>�X�v���C�g�̃T�C�Y</returns>
	Vector2 GetSpriteSize(const SPRITE_ID& id);

	/// <summary>
	/// �X�v���C�g�̃n���h�����擾
	/// </summary>
	/// <param name="id">�X�v���C�gID</param>
	/// <returns>�X�v���C�g�n���h��</returns>
	int GetSpriteHandle(const SPRITE_ID& id);

	private:
		/// <summary>
		/// ���u�����h�ɂ���
		/// </summary>
		/// <param name="alpha">���l</param>
		void AlphaBlend(float alpha);
		/// <summary>
		/// �ŏ��̏�Ԃɖ߂�
		/// </summary>
		void DefaultSprite();
		/// <summary>
		/// �J���[��ݒ�
		/// </summary>
		/// <param name="color">�J���[</param>
		void SetColor(const Vector4& color);

private:
	//�摜����
	std::unordered_map<SPRITE_ID, int> mSprites;
};
