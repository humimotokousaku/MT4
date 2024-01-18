#include "Vector3.h"
#include "Matrix4x4.h"
#include <Novice.h>

#pragma region �`��̍\����

struct Triangle {
	Vector3 vertices[3];
};

struct Sphere {
	Vector3 center;
	float radius;
	unsigned int color;
};

struct Segment {
	Vector3 origin;	//!< �n�_
	Vector3 diff;	//!< �I�_�ւ̍����x�N�g��
};

struct Ray {
	Vector3 origin;	//!< �n�_
	Vector3 diff;	//!< �I�_�ւ̍����x�N�g��
};

struct Line {
	Vector3 origin;	//!< �n�_
	Vector3 diff;	//!< �I�_�ւ̍����x�N�g��
};

struct Plane {
	Vector3 normal; //!< �@��
	float distance; //!< ����
};

struct AABB {
	Vector3 min;
	Vector3 max;
};

#pragma endregion

#pragma region �`�揈���̊֐�

// �O���b�h
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);
// ����
void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, unsigned int color);
// ����
void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
// �O�p�`
void DrawTriangle(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
// AABB
void DrawAABB(const AABB& aabb, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

#pragma endregion