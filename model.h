//=============================================================================
// ファイル: model.h
//=============================================================================
// モデルの設定・描画を制御
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// ヘッダファイルのインクルード
#include "animator.h"

// フレーム番号の最大値
int max_frame_count = 450;

// Modelクラスの定義（ModelerViewクラスを継承）
class Model : public ModelerView {
private:
    //〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
	//第3週課題
    //---------------------------------------------------------------------

	// フレーム番号
    int frame_count;
    
    //-------------------------------------------------------------------------
    // 制御変数
    //-------------------------------------------------------------------------

       // 〜〜〜変数を追加〜〜〜
	double r,posX,posY;
    //〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜


public:

	//ラジアンを度に変換する関数
	double RadianToAngle(double radian){
		return radian*180*M_PI;
	}

	//度をラジアンに変換する関数
	double AngleToRadian(double angle){
		return angle*M_PI/180;
	}

	//軸を描画する
	void DrawAxis(){
		//xは赤色
		setAmbientColor(1, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3d(-100,0,0);
		glVertex3d(100,0,0);
		glEnd();
		

		//yは緑
		setAmbientColor(0, 1, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3d(0,100,0);
		glVertex3d(0,-100,0);
		glEnd();
		

		//zは青
		setAmbientColor(0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex3d(0,0,100);
		glVertex3d(0,0,-100);
		glEnd();
	}

    // コンストラクタ（スーパークラスのコンストラクタを呼び出す）
    Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
    {
        //〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
		//第3週課題
        //---------------------------------------------------------------------

        // フレーム番号の初期化
        frame_count = 0;
        
        //---------------------------------------------------------------------
        // 初期化
        //---------------------------------------------------------------------

            // 〜〜〜変数を初期化〜〜〜
			r    = 4.0;
			posX = r;   // r * cos( 0 )
			posY = 0.0;   // r * sin( 0 )

		//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
    }

    //〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
	//第3週課題
	//---------------------------------------------------------------------

    // 自動アニメーションの設定
    void SetAutomaticAnimation()
    {
        //-----------------------------------------------------------------
        // アニメーション
        //-----------------------------------------------------------------

            // 〜〜〜プログラムを記述〜〜〜
		double th = frame_count*M_PI/50; 
		posX = r * cos( th );
		posY = r * sin( th );

        //-----------------------------------------------------------------
    }

	// 手動アニメーションの設定
    void SetManualAnimation()
    {
        //-----------------------------------------------------------------
        // アニメーション
        //-----------------------------------------------------------------

            // 〜〜〜プログラムを記述〜〜〜
		double th = frame_count*M_PI/50; 
		posX = r * cos( th );
		posY = r * sin( th );

		//-----------------------------------------------------------------
    }

    //〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜


    // 描画の前処理
    void BeginPaint()
    {
        // 半透明処理を有効化
        glEnable( GL_BLEND );
        // 混合方法の指定
        glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    }

    // 描画の後処理
    void EndPaint()
    {
        // 半透明処理を無効化
        glDisable( GL_BLEND );
    }


    // オブジェクトの描画
    void draw()
    {
		//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜
		//第3週課題
		//---------------------------------------------------------------------
        // 自動アニメーションの処理
        if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
            // フレーム番号の更新
            SetSliderValue( FRAME_CONTROLS, ++frame_count );
            // 自動アニメーション
            SetAutomaticAnimation();
        }
        // 手動アニメーションの処理
        else {
            // フレーム番号を取得
            frame_count = (int)GetSliderValue( FRAME_CONTROLS );
            // 手動アニメーション
            SetManualAnimation();            
        }
		//〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜〜


        // スーパークラスの描画メソッドをコール（必須）
        ModelerView::draw();
		ParticleSystem *ps = ModelerApplication::Instance()->GetParticleSystem();
		Mat4f CameraTransforms = ps->getModelViewMatrix();


        // 描画開始
        BeginPaint();
		glPushMatrix();             // 初期座標系を保存

		//軸を描画
		DrawAxis();
		
		

		setAmbientColor(0, 0.5f, 0.5f);
		setDiffuseColor( 0.8, 0.8 ,0.8 ,1 );
		//傘の取っ手部分を描画
		glTranslated(0,0,-10);
		glScaled(0.3,0.3,0.3);
		glPushMatrix();  
	
		drawCylinder( 3, 3, 2 );

		//傘の主軸部分を描画
		drawCylinder( 60, 1, 1 );

		//傘の太い部分を描画
		drawCylinder( 20, 2, 2 );

		//動く部分を描画
		glTranslated(0,0,20);
		drawCylinder( 3, 2.5, 2.5 );

		//細骨１
		glRotated(30,0,1,0);
		glBegin( GL_POLYGON);
			glNormal3d(  0,  1, 0 );
			glVertex3d(  0,  0, 0 );
			glVertex3d(  0, 0, 20 );
			glVertex3d(  1,  0, 20 );
			glVertex3d(  1, 0, 18 );
			glVertex3d(  1.5, 0, 16 );
			glVertex3d(  1.5, 0, 12 );
			glVertex3d(  1.5, 0, 0 );
		glEnd();

		//細骨１の先へ
		glTranslated(0,0,20);

		//細骨２の描画
		glRotated(-60,0,1,0);
		glBegin( GL_POLYGON);
			glNormal3d(  0,  1, 0 );
			glVertex3d(  -0.5,  0, 0 );
			glVertex3d(  -0.3, 0, -1 );
			glVertex3d(  0,  0, -2 );
			glVertex3d(  0, 0, -20 );
			glVertex3d(  1, 0, -20 );
			glVertex3d(  1, 0, 20 );
			glVertex3d(  0, 0, 20 );
		glEnd();

		//細骨２の先へ
		glTranslated(0,0,-20);
		glRotated(30,0,1,0);

		//細骨3の描画
		glBegin( GL_POLYGON);
			glNormal3d(  0,  1, 0 );
			glVertex3d(  0,  0, 0 );
			glVertex3d(  0.5, 0, 4 );
			glVertex3d(  0.5,  0, 35 );
			glVertex3d(  1, 0, 35 );
			glVertex3d(  1, 0, -5 );
			glVertex3d(  0.5, 0, -5 );
			glVertex3d(  0.5, 0, -2 );
		glEnd();

		//細骨３の先へ
		glTranslated(0,0,40);
		glRotated(160,0,1,0);

		//細骨4の描画
		glBegin( GL_POLYGON);
			glNormal3d(  0,  1, 0 );
			glVertex3d(  0,  0, -2 );
			glVertex3d(  1.5, 0, -2 );
			glVertex3d(  1.5,  0, 30 );
			glVertex3d(  1, 0, 5 );
			glVertex3d(  0, 0, 0 );
		glEnd();

		glPopMatrix();    
		glPopMatrix();    

		//

		/*
		//傘の動く場所を作成（座標系を保存）
		glPushMatrix();
		drawCylinder(3,2,2);

	
		//原点を傘の端っこに移動
		glTranslated(0,0,20);

		//傘の末端を描画
		drawCylinder(1,3,1);

		//動く場所の座標系を復元
		glPopMatrix();
		
		//小骨を作成

		glRotated(30,0,1,0);
		drawCylinder(10,1,1);
		
		glRotated(-30,0,1,0);
		glTranslated(sin(AngleToRadian(30))*10,0,cos(AngleToRadian(30))*10);
		//一本目の大骨を作成
		glPushMatrix();
		glRotated(-30,0,1,0);
		


		glBegin(GL_LINE_STRIP);
			glVertex3d(0,0,10);
			glVertex3d(0,0,-10);
		glEnd();
		

		//二本目の大骨を作成	
		glTranslated(0,0,-10);
		glRotated(40,0,1,0);
		
		drawCylinder(20,1,1);
		glBegin(GL_LINE_STRIP);
			glVertex3d(0,0,20);
			glVertex3d(0,0,0);
		glEnd();

		*/


  
		 // 〜〜〜プログラムを記述〜〜〜

        //---------------------------------------------------------------------

        // 描画終了
        EndPaint();
    }
};

// __MODEL_H__
#endif