#include "Quaternion.h"
#include "MyMath.h"
#include <cmath>
#include <Novice.h>

Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs){
	// 内積
	float dot = Dot(Vector3(lhs.x, lhs.y, lhs.z), Vector3(rhs.x, rhs.y, rhs.z));
	// 外積
	Vector3 cross = Cross(Vector3(lhs.x, lhs.y, lhs.z), Vector3(rhs.x, rhs.y, rhs.z));

	// 計算結果
	Quaternion result;
	result.x = cross.x + rhs.w * lhs.x + lhs.w * rhs.x;
	result.y = cross.y + rhs.w * lhs.y + lhs.w * rhs.y;
	result.z = cross.z + rhs.w * lhs.z + lhs.w * rhs.z;
	result.w = lhs.w * rhs.w - dot;

	return result;
}

Quaternion IdentityQuaternion(){
	return Quaternion{ 0,0,0,1 };
}

Quaternion Conjugate(const Quaternion& quaternion){
	Quaternion result = { -quaternion.x,-quaternion.y ,-quaternion.z ,quaternion.w };
	return result;
}

float Norm(const Quaternion& quaternion){
	float x = quaternion.x;
	float y = quaternion.y;
	float z = quaternion.z;
	float w = quaternion.w;
	return sqrt(x * x + y * y + z * z + w * w);
}

Quaternion Normalize(const Quaternion& quaternion){
	// ノルム
	float norm = Norm(quaternion);
	// 計算結果
	Quaternion result;
	if (norm != 0.0f) {		
		result.x = quaternion.x / norm;
		result.y = quaternion.y / norm;
		result.z = quaternion.z / norm;
		result.w = quaternion.w / norm;
	}
	return result;
}

Quaternion Inverse(const Quaternion& quaternion) {
	// 共役
	Quaternion conjugate = Conjugate(quaternion);
	// ノルム
	float norm = Norm(quaternion);

	// 計算結果
	Quaternion result;
	result.x = conjugate.x / (norm * norm);
	result.y = conjugate.y / (norm * norm);
	result.z = conjugate.z / (norm * norm);
	result.w = conjugate.w / (norm * norm);

	return result;
}

Quaternion MakeRotateAxisAngleQuaternion(const Vector3& axis, float angle) {
	Quaternion result;
	result.x = axis.x * sinf(angle / 2.0f);
	result.y = axis.y * sinf(angle / 2.0f);
	result.z = axis.z * sinf(angle / 2.0f);
	result.w = cosf(angle / 2.0f);

	return result;
}

Vector3 RotateVector(const Vector3& vector, Quaternion quaternion) {
	// 三次元ベクトルをQuaternionに変換
	Quaternion quaternionVec = { vector.x,vector.y,vector.z,0.0f };
	// 単位Quaternion
	Quaternion conjugate = Conjugate(quaternion);
	// 回転の計算
	Quaternion rotation = Multiply(quaternion, Multiply(quaternionVec, conjugate));
	
	// 返り値に合わせる
	Vector3 result;
	result.x = rotation.x;
	result.y = rotation.y;
	result.z = rotation.z;

	return result;
}

Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion) {
	Matrix4x4 result;
	result.m[0][0] = (quaternion.w * quaternion.w) + (quaternion.x * quaternion.x) - (quaternion.y * quaternion.y) - (quaternion.z * quaternion.z);
	result.m[0][1] = 2 * ((quaternion.x * quaternion.y) + (quaternion.w * quaternion.z));
	result.m[0][2] = 2 * ((quaternion.x * quaternion.z) - (quaternion.w * quaternion.y));
	result.m[0][3] = 0;

	result.m[1][0] = 2 * ((quaternion.x * quaternion.y) - (quaternion.w * quaternion.z));
	result.m[1][1] = (quaternion.w * quaternion.w) - (quaternion.x * quaternion.x) + (quaternion.y * quaternion.y) - (quaternion.z * quaternion.z);
	result.m[1][2] = 2 * ((quaternion.y * quaternion.z) + (quaternion.w * quaternion.x));
	result.m[1][3] = 0;

	result.m[2][0] = 2 * ((quaternion.x * quaternion.z) + (quaternion.w * quaternion.y));
	result.m[2][1] = 2 * ((quaternion.y * quaternion.z) - (quaternion.w * quaternion.x));
	result.m[2][2] = (quaternion.w * quaternion.w) - (quaternion.x * quaternion.x) - (quaternion.y * quaternion.y) + (quaternion.z * quaternion.z);
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}

void QuaternionScreenPrintf(int x, int y, const Quaternion& quaternion, const char* label) {
	Novice::ScreenPrintf(x, y, "%.02f",	quaternion.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%.02f", quaternion.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%.02f", quaternion.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%.02f", quaternion.w);
	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}