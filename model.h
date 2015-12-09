//=============================================================================
// ƒtƒ@ƒCƒ‹: model.h
//=============================================================================
// ƒ‚ƒfƒ‹‚Ìİ’èE•`‰æ‚ğ§Œä
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// ƒwƒbƒ_ƒtƒ@ƒCƒ‹‚ÌƒCƒ“ƒNƒ‹[ƒh
#include "animator.h"

// ƒtƒŒ[ƒ€”Ô†‚ÌÅ‘å’l
int max_frame_count = 450;

// ModelƒNƒ‰ƒX‚Ì’è‹`iModelerViewƒNƒ‰ƒX‚ğŒp³j
class Model : public ModelerView {
private:
    //```````````````````````````````````
	//‘æ3T‰Û‘è
    //---------------------------------------------------------------------

	// ƒtƒŒ[ƒ€”Ô†
    int frame_count;
    
    //-------------------------------------------------------------------------
    // §Œä•Ï”
    //-------------------------------------------------------------------------

       // ```•Ï”‚ğ’Ç‰Á```
	double r,posX,posY;
    //```````````````````````````````````


public:

	//ƒ‰ƒWƒAƒ“‚ğ“x‚É•ÏŠ·‚·‚éŠÖ”
	double RadianToAngle(double radian){
		return radian*180*M_PI;
	}

	//“x‚ğƒ‰ƒWƒAƒ“‚É•ÏŠ·‚·‚éŠÖ”
	double AngleToRadian(double angle){
		return angle*M_PI/180;
	}

	//²‚ğ•`‰æ‚·‚é
	void DrawAxis(){
		//x‚ÍÔF
		setAmbientColor(1, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3d(-100,0,0);
		glVertex3d(100,0,0);
		glEnd();
		

		//y‚Í—Î
		setAmbientColor(0, 1, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3d(0,100,0);
		glVertex3d(0,-100,0);
		glEnd();
		

		//z‚ÍÂ
		setAmbientColor(0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex3d(0,0,100);
		glVertex3d(0,0,-100);
		glEnd();
	}

    // ƒRƒ“ƒXƒgƒ‰ƒNƒ^iƒX[ƒp[ƒNƒ‰ƒX‚ÌƒRƒ“ƒXƒgƒ‰ƒNƒ^‚ğŒÄ‚Ño‚·j
    Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
    {
        //```````````````````````````````````
		//‘æ3T‰Û‘è
        //---------------------------------------------------------------------

        // ƒtƒŒ[ƒ€”Ô†‚Ì‰Šú‰»
        frame_count = 0;
        
        //---------------------------------------------------------------------
        // ‰Šú‰»
        //---------------------------------------------------------------------

            // ```•Ï”‚ğ‰Šú‰»```
			r    = 4.0;
			posX = r;   // r * cos( 0 )
			posY = 0.0;   // r * sin( 0 )

		//```````````````````````````````````
    }

    //```````````````````````````````````
	//‘æ3T‰Û‘è
	//---------------------------------------------------------------------

    // ©“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìİ’è
    void SetAutomaticAnimation()
    {
        //-----------------------------------------------------------------
        // ƒAƒjƒ[ƒVƒ‡ƒ“
        //-----------------------------------------------------------------

            // ```ƒvƒƒOƒ‰ƒ€‚ğ‹Lq```
		double th = frame_count*M_PI/50; 
		posX = r * cos( th );
		posY = r * sin( th );

        //-----------------------------------------------------------------
    }

	// è“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìİ’è
    void SetManualAnimation()
    {
        //-----------------------------------------------------------------
        // ƒAƒjƒ[ƒVƒ‡ƒ“
        //-----------------------------------------------------------------

            // ```ƒvƒƒOƒ‰ƒ€‚ğ‹Lq```
		double th = frame_count*M_PI/50; 
		posX = r * cos( th );
		posY = r * sin( th );

		//-----------------------------------------------------------------
    }

    //```````````````````````````````````


    // •`‰æ‚Ì‘Oˆ—
    void BeginPaint()
    {
        // ”¼“§–¾ˆ—‚ğ—LŒø‰»
        glEnable( GL_BLEND );
        // ¬‡•û–@‚Ìw’è
        glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    }

    // •`‰æ‚ÌŒãˆ—
    void EndPaint()
    {
        // ”¼“§–¾ˆ—‚ğ–³Œø‰»
        glDisable( GL_BLEND );
    }


    // ƒIƒuƒWƒFƒNƒg‚Ì•`‰æ
    void draw()
    {
		//```````````````````````````````````
		//‘æ3T‰Û‘è
		//---------------------------------------------------------------------
        // ©“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìˆ—
        if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
            // ƒtƒŒ[ƒ€”Ô†‚ÌXV
            SetSliderValue( FRAME_CONTROLS, ++frame_count );
            // ©“®ƒAƒjƒ[ƒVƒ‡ƒ“
            SetAutomaticAnimation();
        }
        // è“®ƒAƒjƒ[ƒVƒ‡ƒ“‚Ìˆ—
        else {
            // ƒtƒŒ[ƒ€”Ô†‚ğæ“¾
            frame_count = (int)GetSliderValue( FRAME_CONTROLS );
            // è“®ƒAƒjƒ[ƒVƒ‡ƒ“
            SetManualAnimation();            
        }
		//```````````````````````````````````


        // ƒX[ƒp[ƒNƒ‰ƒX‚Ì•`‰æƒƒ\ƒbƒh‚ğƒR[ƒ‹i•K{j
        ModelerView::draw();
		ParticleSystem *ps = ModelerApplication::Instance()->GetParticleSystem();
		Mat4f CameraTransforms = ps->getModelViewMatrix();


        // •`‰æŠJn
        BeginPaint();
		glPushMatrix();             // ‰ŠúÀ•WŒn‚ğ•Û‘¶

		//²‚ğ•`‰æ
		DrawAxis();
		
		

		setAmbientColor(0, 0.5f, 0.5f);
		setDiffuseColor( 0.8, 0.8 ,0.8 ,1 );
		//P‚Ìæ‚Áè•”•ª‚ğ•`‰æ
		glTranslated(0,0,-10);
		glScaled(0.3,0.3,0.3);
		glPushMatrix();  
	
		drawCylinder( 3, 3, 2 );

		//P‚Ìå²•”•ª‚ğ•`‰æ
		drawCylinder( 60, 1, 1 );

		//P‚Ì‘¾‚¢•”•ª‚ğ•`‰æ
		drawCylinder( 20, 2, 2 );

		//“®‚­•”•ª‚ğ•`‰æ
		glTranslated(0,0,20);
		drawCylinder( 3, 2.5, 2.5 );

		//×œ‚P
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

		//P‚Ìæ‚Ö
		glRotated(-30,0,1,0);
		glTranslated(0,0,35);

		setDiffuseColor( 0.8, 0.8 ,0.8 ,0.7 );
		setAmbientColor(0, 0.2f, 0.8f);
		// ’¸“_À•W‚Ìw’è
		Vec3d A( 0, 0, 0 );
		Vec3d B(  20, 0, -40*0.886 );
		Vec3d C(  0,  40*0.886, -40 );
		// –@üƒxƒNƒgƒ‹
		Vec3d N = ( A-C) ^ ( B-C );

		glBegin( GL_TRIANGLES );
		glNormal3d( N[0], N[1], N[2] );
		glVertex3d( A[0], A[1], A[2] );
		glVertex3d( B[0], B[1], B[2] );
		glVertex3d( C[0], C[1], C[2] );
		glEnd();

		setDiffuseColor( 0.8, 0.8 ,0.8 ,1 );
		setAmbientColor(0, 0.5f, 0.5f);

		//×œ‚Q‚Ì•`‰æ
		glRotated(150,0,1,0);
		glBegin( GL_POLYGON);
			glNormal3d(  0,  1, 0 );
			glVertex3d(  0,  0, 0 );
			glVertex3d(  1, 0, 0 );
			glVertex3d(  1, 0, 40 );
			glVertex3d(  0, 0, 40 );
		glEnd();

		//×œ‚Q‚Ìæ‚Ö
		glTranslated(0,0,40);
		glRotated(-140,0,1,0);

		//×œ3‚Ì•`‰æ
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

		//×œ‚R‚Ìæ‚Ö
		glTranslated(0,0,40);
		glRotated(160,0,1,0);

		//×œ4‚Ì•`‰æ
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
		//P‚Ì“®‚­êŠ‚ğì¬iÀ•WŒn‚ğ•Û‘¶j
		glPushMatrix();
		drawCylinder(3,2,2);

	
		//Œ´“_‚ğP‚Ì’[‚Á‚±‚ÉˆÚ“®
		glTranslated(0,0,20);

		//P‚Ì––’[‚ğ•`‰æ
		drawCylinder(1,3,1);

		//“®‚­êŠ‚ÌÀ•WŒn‚ğ•œŒ³
		glPopMatrix();
		
		//¬œ‚ğì¬

		glRotated(30,0,1,0);
		drawCylinder(10,1,1);
		
		glRotated(-30,0,1,0);
		glTranslated(sin(AngleToRadian(30))*10,0,cos(AngleToRadian(30))*10);
		//ˆê–{–Ú‚Ì‘åœ‚ğì¬
		glPushMatrix();
		glRotated(-30,0,1,0);
		


		glBegin(GL_LINE_STRIP);
			glVertex3d(0,0,10);
			glVertex3d(0,0,-10);
		glEnd();
		

		//“ñ–{–Ú‚Ì‘åœ‚ğì¬	
		glTranslated(0,0,-10);
		glRotated(40,0,1,0);
		
		drawCylinder(20,1,1);
		glBegin(GL_LINE_STRIP);
			glVertex3d(0,0,20);
			glVertex3d(0,0,0);
		glEnd();

		*/


  
		 // ```ƒvƒƒOƒ‰ƒ€‚ğ‹Lq```

        //---------------------------------------------------------------------

        // •`‰æI—¹
        EndPaint();
    }
};

// __MODEL_H__
#endif