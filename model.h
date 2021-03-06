//=============================================================================
// t@C: model.h
//=============================================================================
// fÌÝèE`æð§ä
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// wb_t@CÌCN[h
#include "animator.h"

// t[ÔÌÅål
int max_frame_count = 450;

// ModelNXÌè`iModelerViewNXðp³j
class Model : public ModelerView {
private:
    //```````````````````````````````````
	//æ3TÛè
    //---------------------------------------------------------------------

	// t[Ô
    int frame_count;
    
    //-------------------------------------------------------------------------
    // §äÏ
    //-------------------------------------------------------------------------

       // ```ÏðÇÁ```
	double r,posX,posY;
    //```````````````````````````````````


public:

	//WAðxÉÏ··éÖ
	double RadianToAngle(double radian){
		return radian*180*M_PI;
	}

	//xðWAÉÏ··éÖ
	double AngleToRadian(double angle){
		return angle*M_PI/180;
	}

	//²ð`æ·é
	void DrawAxis(){
		//xÍÔF
		setAmbientColor(1, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3d(-100,0,0);
		glVertex3d(100,0,0);
		glEnd();
		

		//yÍÎ
		setAmbientColor(0, 1, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3d(0,100,0);
		glVertex3d(0,-100,0);
		glEnd();
		

		//zÍÂ
		setAmbientColor(0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex3d(0,0,100);
		glVertex3d(0,0,-100);
		glEnd();
	}

    // RXgN^iX[p[NXÌRXgN^ðÄÑo·j
    Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
    {
        //```````````````````````````````````
		//æ3TÛè
        //---------------------------------------------------------------------

        // t[ÔÌú»
        frame_count = 0;
        
        //---------------------------------------------------------------------
        // ú»
        //---------------------------------------------------------------------

            // ```Ïðú»```
			r    = 4.0;
			posX = r;   // r * cos( 0 )
			posY = 0.0;   // r * sin( 0 )

		//```````````````````````````````````
    }

    //```````````````````````````````````
	//æ3TÛè
	//---------------------------------------------------------------------

    // ©®Aj[VÌÝè
    void SetAutomaticAnimation()
    {
        //-----------------------------------------------------------------
        // Aj[V
        //-----------------------------------------------------------------

            // ```vOðLq```
		double th = frame_count*M_PI/50; 
		posX = r * cos( th );
		posY = r * sin( th );

        //-----------------------------------------------------------------
    }

	// è®Aj[VÌÝè
    void SetManualAnimation()
    {
        //-----------------------------------------------------------------
        // Aj[V
        //-----------------------------------------------------------------

            // ```vOðLq```
		double th = frame_count*M_PI/50; 
		posX = r * cos( th );
		posY = r * sin( th );

		//-----------------------------------------------------------------
    }

    //```````````````````````````````````


    // `æÌO
    void BeginPaint()
    {
        // ¼§¾ðLø»
        glEnable( GL_BLEND );
        // ¬û@Ìwè
        glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    }

    // `æÌã
    void EndPaint()
    {
        // ¼§¾ð³ø»
        glDisable( GL_BLEND );
    }


    // IuWFNgÌ`æ
    void draw()
    {
		//```````````````````````````````````
		//æ3TÛè
		//---------------------------------------------------------------------
        // ©®Aj[VÌ
        if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
            // t[ÔÌXV
            SetSliderValue( FRAME_CONTROLS, ++frame_count );
            // ©®Aj[V
            SetAutomaticAnimation();
        }
        // è®Aj[VÌ
        else {
            // t[Ôðæ¾
            frame_count = (int)GetSliderValue( FRAME_CONTROLS );
            // è®Aj[V
            SetManualAnimation();            
        }
		//```````````````````````````````````


        // X[p[NXÌ`æ\bhðR[iK{j
        ModelerView::draw();
		ParticleSystem *ps = ModelerApplication::Instance()->GetParticleSystem();
		Mat4f CameraTransforms = ps->getModelViewMatrix();


        // `æJn
        BeginPaint();
		glPushMatrix();             // úÀWnðÛ¶

		//²ð`æ
		//DrawAxis();
		glTranslated(GetSliderValue(X_POSITION),GetSliderValue(Y_POSITION),GetSliderValue(Z_POSITION));
		glRotated(300 , 1,0,0);
		

		setAmbientColor(0, 0.5f, 0.5f);
		setDiffuseColor( 0.8, 0.8 ,0.8 ,1 );
		//PÌæÁèªð`æ
		setAmbientColor(0.5f, 0, 0);
		glTranslated(0,0,0);
		glScaled(0.1,0.1,0.1);
		glPushMatrix(); 
			drawCylinder( 3, 3, 2 );

			//PÌå²ªð`æ
			setAmbientColor(0.2f, 0.2f, 0.2f);
			drawCylinder( 55, 1, 1 );
			setAmbientColor(0.8f, 0.8f, 0.8f);
			//PÌ¾¢ªð`æ
			drawCylinder( 20, 2, 2 );

			//®­ªð`æ
			setAmbientColor(0.9f, 0.9f, 0.9f);
			glTranslated(0,0,GetSliderValue(UMB_POSITION));
			glPushMatrix();  
				drawCylinder( 3, 2.5, 2.5 );
					//×P
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
		//PÌæÖ

		  
		glTranslated(0,0,55);
		setDiffuseColor( 0.8, 0.8 ,0.8 ,0.8 );
			setAmbientColor(0, 0.9f, 0.9f);
		glPushMatrix();
			glTranslated(0,0,100);
			
			ps->SpawnParticles( CameraTransforms );
		glPopMatrix();
		//Jð~ç·

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
				//×QÌæÖ
				//×QÌ`æ
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



				//×3Ì`æ
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

				//×RÌæÖ
				glTranslated(0,0,40);
				glRotated(GetSliderValue(UMB_ANGLE4),0,1,0);

				//×4Ì`æ
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



  
		 // ```vOðLq```

        //---------------------------------------------------------------------

        // `æI¹
        EndPaint();
    }
};

// __MODEL_H__
#endif