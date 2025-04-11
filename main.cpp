#include <Novice.h>
#include <math.h>

const char kWindowTitle[] = "LD2A_04_トヨダヤヤ_MT3_00_01";

//================================================================
	// 構造体を宣言する
	//================================================================

struct Vector3
{
	float x, y, z;
};

//================================================================
// 変数、関数の宣言
//================================================================

// 加算の関数
Vector3 Add(const Vector3& v1, const Vector3& v2);

// 減算の関数
Vector3 Subtract(const Vector3& v1, const Vector3& v2);

// スカラー倍の関数
Vector3 Multiply(float scalar, const Vector3& v);

// 内積の関数
float Dot(const Vector3& v1, const Vector3& v2);

// ノルン(長さ)の関数
float Length(const Vector3& v);

// 正規化の関数
Vector3 Normalize(const Vector3& v);

// 数値表示用の関数
void VectorScreenPrintf(int x, int y, const Vector3& Vector, const char* label);
static const int kColumnWidth = 60;
static const int kRowHeight = 20;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//================================================================
    // 変数の宣言と初期化
    //================================================================

	Vector3 v1{ 1.0f,3.0f,-5.0f };
	Vector3 v2{ 4.0f,-1.0f,2.0f };
	float k = 4.0f;

	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubtract = Subtract(v1, v2);
	Vector3 resultMultiply = Multiply(k, v1);
	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v2);

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

		//================================================================
	    // 数値を表示
	    //================================================================

		VectorScreenPrintf(0, 0, resultAdd, " : Add");
		VectorScreenPrintf(0, kRowHeight, resultSubtract, " : Subtract");
		VectorScreenPrintf(0, kRowHeight * 2, resultMultiply, " : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%0.2f : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%0.2f : Length", resultLength);
		VectorScreenPrintf(0, kRowHeight * 5, resultNormalize, " : Normalize");

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

Vector3 Add(const Vector3& v1, const Vector3& v2)
{
	Vector3 ret;
	ret.x = v1.x + v2.x;
	ret.y = v1.y + v2.y;
	ret.z = v1.z + v2.z;
	return ret;
}

Vector3 Subtract(const Vector3& v1, const Vector3& v2)
{
	Vector3 ret;
	ret.x = v1.x - v2.x;
	ret.y = v1.y - v2.y;
	ret.z = v1.z - v2.z;
	return ret;
}

Vector3 Multiply(float scalar, const Vector3& v)
{
	Vector3 ret;
	ret.x = scalar * v.x;
	ret.y = scalar * v.y;
	ret.z = scalar * v.z;
	return ret;
}

float Dot(const Vector3& v1, const Vector3& v2)
{
	float ret;
	ret = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return ret;
}

float Length(const Vector3& v)
{
	float ret;
	ret = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return ret;
}

Vector3 Normalize(const Vector3& v)
{
	Vector3 ret;
	float length = Length(v);

	if (length != 0)
	{
		ret.x = v.x / length;
		ret.y = v.y / length;
		ret.z = v.z / length;
	}
	else
	{
		ret.x = 0;
		ret.y = 0;
		ret.z = 0;
	}

	return ret;
}

void VectorScreenPrintf(int x, int y, const Vector3& Vector, const char* label)
{
	Novice::ScreenPrintf(x, y, "%0.2f", Vector.x);
	Novice::ScreenPrintf(x + kColumnWidth, y, "%0.2f", Vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%0.2f", Vector.z);
	Novice::ScreenPrintf(x + kColumnWidth * 3, y, "%s", label);
}
