//=============================================================================
// ファイル: controller.h
//=============================================================================
// スライダコントローラの設定
//=============================================================================

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

// ヘッダファイルのインクルード
#include "modelerapp.h"

// フレーム番号の最大値
extern int max_frame_count;

// コントローラ識別用の列挙子
enum CONTROLLERS {

	FRAME_CONTROLS,   // フレームコントローラ（変更しないこと)
    // ～～～列挙子を追加～～～
	X_POSITION,
	Y_POSITION,
	Z_POSITION,
	UMB_CNT_ANGLE,//傘の動かす部分の座標
	UMB_POSITION,//傘の動かす部分の座標
	UMB_ANGLE1,
	UMB_ANGLE2,
	UMB_ANGLE3,
	UMB_ANGLE4,
    NUM_CONTROLS,   // コントローラ数（必ず末尾に追加）
};

// コントローラの設定
//（NUM_CONTROLSを除くCONTROLLERS列挙子と１：１に対応付ける）
void SetController( ModelerControl* controls )
{
	// フレーム番号の制御用スライダ
    controls[FRAME_CONTROLS] = ModelerControl( "Frame Number", 0, (float)max_frame_count, 1, 0 );

    // ～～～スライダを追加～～～
	controls[X_POSITION] = ModelerControl( "X-Position", -100.0f, 100.0f, 2.0f, 0.0f );
	controls[Y_POSITION] = ModelerControl( "Y-Position", -100.0f, 100.0f, 2.0f, 0.0f );
	controls[Z_POSITION] = ModelerControl( "Z-Position", -100.0f, 100.0f, 2.0f, 0.0f );
	controls[UMB_CNT_ANGLE] = ModelerControl( "UMB_CNT_ANGLE", 0.0f, 360.0f, 2.0f, 0.0f );
	controls[UMB_POSITION] = ModelerControl( "UMB-Position", 14.0f, 40.0f, 1.0f, 20.0f );
	controls[UMB_ANGLE1] = ModelerControl( "UMB-Angle1", 0.0f, 360.0f, 1.0f, 35.0f );
	controls[UMB_ANGLE2] = ModelerControl( "UMB-Angle2", 0.0f, 360.0f, 1.0f, 150.0f );
	controls[UMB_ANGLE3] = ModelerControl( "UMB-Angle3", -140.0f, 360.0f, 1.0f, -140.0f );
	controls[UMB_ANGLE4] = ModelerControl( "UMB-Angle4", 0.0f, 360.0f, 1.0f, 160.0f );
	
}

// __CONTROLLER_H__
#endif
