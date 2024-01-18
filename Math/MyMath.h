#pragma once
#include "Matrix4x4.h"
#include "Vector3.h"

struct Matrix3x3 {
	float m[3][3];
};

// 加算
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

// 積
Vector3 Multiply(const Vector3& v1, const Vector3& v2);

// スカラー倍
Vector3 Multiply(const Vector3& m, float scale);

// スカラー倍
Matrix4x4 Multiply(Matrix4x4 m, float scale);

// 行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

// 長さ(ノルム)
float Length(const Vector3& v);

// 正規化
Vector3 Normalize(const Vector3& v);

// 内積
float Dot(const Vector3& v1, const Vector3& v2);

Vector3 Cross(const Vector3& v1, const Vector3& v2);

Vector3 Transform(const Vector3& vector, const Matrix4x4& matrix);

// 最近接点
Vector3 ClosestPoint(const Vector3& point, const Segment& segment);

// 正射影ベクトル
Vector3 Project(const Vector3& v1, const Vector3& v2);

// 透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);

// 正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

// ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

// 任意軸回転行列
Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);

Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);


const int kRowHeight = 20;
const int kColumnWidth = 60;
// 4x4行列の数値表示
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);
// 三次元ベクトルの数値表示
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label);