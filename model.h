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
		//DrawAxis();
		glTranslated(GetSliderValue(X_POSITION),GetSliderValue(Y_POSITION),GetSliderValue(Z_POSITION));
		glRotated(300 , 1,0,0);
		

		setAmbientColor(0, 0.5f, 0.5f);
		setDiffuseColor( 0.8, 0.8 ,0.8 ,1 );
		//P‚Ìæ‚Áè•”•ª‚ğ•`‰æ
		setAmbientColor(0.5f, 0, 0);
		glTranslated(0,0,0);
		glScaled(0.1,0.1,0.1);
		glPushMatrix(); 
			drawCylinder( 3, 3, 2 );

			//P‚Ìå²•”•ª‚ğ•`‰æ
			setAmbientColor(0.2f, 0.2f, 0.2f);
			drawCylinder( 55, 1, 1 );
			setAmbientColor(0.8f, 0.8f, 0.8f);
			//P‚Ì‘¾‚¢•”•ª‚ğ•`‰æ
			drawCylinder( 20, 2, 2 );

			//“®‚­•”•ª‚ğ•`‰æ
			setAmbientColor(0.9f, 0.9f, 0.9f);
			glTranslated(0,0,GetSliderValue(UMB_POSITION));
			glPushMatrix();  
				drawCylinder( 3, 2.5, 2.5 );
					//×œ‚P
				setAmbientColor(0.8f, 0.8f, 0.8f);
				for(int j = 1; j < 360;j++){
					glPushMatrix();
						if(j%60 == 0)
							glRotated(j , 0,0,1);

						glRotated(GetSliderValue(UMB_ANGLE1),0,1,0);
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
					glPopMatrix(); 
					
				}				

			glPopMatrix();  
		glPopMatrix();
		//P‚Ìæ‚Ö

		  
		glTranslated(0,0,55);
		setDiffuseColor( 0.8, 0.8 ,0.8 ,0.8 );
			setAmbientColor(0, 0.9f, 0.9f);
		glPushMatrix();
			glTranslated(0,0,100);
			
			ps->SpawnParticles( CameraTransforms );
		glPopMatrix();
		//‰J‚ğ~‚ç‚·

		for(double i = 0; i < 360;i+= 0.1){

			setAmbientColor( 1.0f, 0,0);
			setDiffuseColor( 1.0, 0.8 ,0.8 ,0.8 );
			glPushMatrix();
		
				/*
				if( i == 0||60||120||180||240||300 ){
					glLineWidth(3);
					setAmbientColor(0, 0.5f, 0.5f);
					setDiffuseColor( 0.8, 0.8 ,0.8 ,1 );
				}else{
					glLineWidth(1);
					setAmbientColor(0, 0, 1.0f);
					setDiffuseColor( 0.8, 0.8 ,0.8 ,0.8 );
				}
				*/
				glRotated(i , 0,0,1);
				//×œ‚Q‚Ìæ‚Ö
				//×œ‚Q‚Ì•`‰æ
					glRotated(GetSliderValue(UMB_ANGLE2),0,1,0);
					glBegin( GL_POLYGON);
						glNormal3d(  0,  1, 0 );
						glVertex3d(  0,  0, 0 );
						glVertex3d(  1, 0, 0 );
						glVertex3d(  1, 0, 40 );
						glVertex3d(  0, 0, 40 );
					glEnd();
				glTranslated(0,0,40);
				glRotated(GetSliderValue(UMB_ANGLE3),0,1,0);



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
				glRotated(GetSliderValue(UMB_ANGLE4),0,1,0);

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
		}
		setDiffuseColor( 0.8, 0.8 ,0.8 ,0.8 );
			setAmbientColor(0, 0.9f, 0.9f);
		glPopMatrix();    

		//



  
		 // ```ƒvƒƒOƒ‰ƒ€‚ğ‹Lq```

        //---------------------------------------------------------------------

        // •`‰æI—¹
        EndPaint();
    }
};

// __MODEL_H__
#endif