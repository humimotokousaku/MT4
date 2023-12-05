#include <Novice.h>
#include "MyMath.h"
#include "Quaternion.h"
#include "ImGuiManager.h"

const char kWindowTitle[] = "LE2B_16_フミモト_コウサク";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Quaternion p1 = { 2.0f,3.0f,4.0f,1.0f };
	Quaternion p2 = { 1.0f,3.0f,5.0f,2.0f };
	Quaternion identity = IdentituQuaternion();
	Quaternion conj = Conjugate(p1);
	Quaternion inv = Inverse(p1);
	Quaternion normal = Normalize(p1);
	Quaternion mul1 = Multiply(p1, p2);
	Quaternion mul2 = Multiply(p2, p1);
	float norm = Norm(p1);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		ImGui::Begin("Quaternion");
		ImGui::Text("Identity         : %f  %f  %f  %f", identity.x, identity.y, identity.z, identity.w);
		ImGui::Text("Conjugate        : %f  %f  %f  %f", conj.x, conj.y, conj.z, conj.w);
		ImGui::Text("Inverse          : %f  %f  %f  %f", inv.x, inv.y, inv.z, inv.w);
		ImGui::Text("Normalize        : %f  %f  %f  %f", normal.x, normal.y, normal.z, normal.w);
		ImGui::Text("Multiply(q1, q2) : %f  %f  %f  %f", mul1.x, mul1.y, mul1.z, mul1.w);
		ImGui::Text("Multiply(q2, q1) : %f  %f  %f  %f", mul2.x, mul2.y, mul2.z, mul2.w);
		ImGui::Text("Norm             : %f", norm);
		ImGui::End();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
