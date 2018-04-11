#pragma once
//Math�֌W
#include "../Math/Vector3.h"
#include "../Math/Matrix4.h"

class Camera
{
private:
	Camera() = default;
	~Camera();
public:
	/// <summary>
	/// �C���X�^���X���擾����
	/// </summary>
	/// <returns></returns>
	static Camera &GetInstance() {
		static Camera m;
		return m;
	}

public:
	/// <summary>
	/// �J�����̒����_��ݒ�( �^�[�Q�b�g���W )
	/// </summary>
	/// <param name="target">�^�[�Q�b�g���W</param>
	void SetTarget(const Vector3& target);
	/// <summary>
	/// �J�����̍��W��ݒ�( �J�������W )
	/// </summary>
	/// <param name="position">�J�������W</param>
	void SetPosition(const Vector3& position);
	/// <summary>
	/// �J�����̏������ݒ�( �J�����̏�x�N�g�� )
	/// </summary>
	/// <param name="vec">�J������x�N�g��</param>
	void SetCameraVec(const Vector3& vec);
	/// <summary>
	/// �J���������A�b�v�f�[�g
	/// </summary>
	void Update();

	/// <summary>
	/// �J�����̕`�ʋ�����ݒ�(��O�A��)
	/// </summary>
	/// <param name="Near">��O</param>
	/// <param name="Far">��</param>
	void SetRange(float Near, float Far);
	/// <summary>
	/// �J�����̎���p��ݒ�(�p�x (�x���@) )
	/// </summary>
	/// <param name="angle">�p�x</param>
	void SetView(float angle);
	/// <summary>
	/// �����_���擾����
	/// </summary>
	/// <returns>�����_</returns>
	Vector3 GetTarget() const;
	/// <summary>
	/// �J�����̍��W���擾����
	/// </summary>
	/// <returns></returns>
	Vector3 GetPosition()const;
private:
	//�����_
	Vector3 mTarget;
	//���W
	Vector3 mPosition;
	//�J������x�N�g��
	Vector3 mCameraVec;
};