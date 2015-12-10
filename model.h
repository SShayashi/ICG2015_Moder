//=============================================================================
// �t�@�C��: model.h
//=============================================================================
// ���f���̐ݒ�E�`��𐧌�
//=============================================================================

#ifndef __MODEL_H__
#define __MODEL_H__

// �w�b�_�t�@�C���̃C���N���[�h
#include "animator.h"

// �t���[���ԍ��̍ő�l
int max_frame_count = 450;

// Model�N���X�̒�`�iModelerView�N���X���p���j
class Model : public ModelerView {
private:
    //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
	//��3�T�ۑ�
    //---------------------------------------------------------------------

	// �t���[���ԍ�
    int frame_count;
    
    //-------------------------------------------------------------------------
    // ����ϐ�
    //-------------------------------------------------------------------------

       // �`�`�`�ϐ���ǉ��`�`�`
	double r,posX,posY;
    //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


public:

	//���W�A����x�ɕϊ�����֐�
	double RadianToAngle(double radian){
		return radian*180*M_PI;
	}

	//�x�����W�A���ɕϊ�����֐�
	double AngleToRadian(double angle){
		return angle*M_PI/180;
	}

	//����`�悷��
	void DrawAxis(){
		//x�͐ԐF
		setAmbientColor(1, 0, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3d(-100,0,0);
		glVertex3d(100,0,0);
		glEnd();
		

		//y�͗�
		setAmbientColor(0, 1, 0);
		glBegin(GL_LINE_STRIP);
		glVertex3d(0,100,0);
		glVertex3d(0,-100,0);
		glEnd();
		

		//z�͐�
		setAmbientColor(0, 0, 1);
		glBegin(GL_LINE_STRIP);
		glVertex3d(0,0,100);
		glVertex3d(0,0,-100);
		glEnd();
	}

    // �R���X�g���N�^�i�X�[�p�[�N���X�̃R���X�g���N�^���Ăяo���j
    Model( int x, int y, int w, int h, char* label ) : ModelerView( x, y, w, h, label )
    {
        //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
		//��3�T�ۑ�
        //---------------------------------------------------------------------

        // �t���[���ԍ��̏�����
        frame_count = 0;
        
        //---------------------------------------------------------------------
        // ������
        //---------------------------------------------------------------------

            // �`�`�`�ϐ����������`�`�`
			r    = 4.0;
			posX = r;   // r * cos( 0 )
			posY = 0.0;   // r * sin( 0 )

		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
    }

    //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
	//��3�T�ۑ�
	//---------------------------------------------------------------------

    // �����A�j���[�V�����̐ݒ�
    void SetAutomaticAnimation()
    {
        //-----------------------------------------------------------------
        // �A�j���[�V����
        //-----------------------------------------------------------------

            // �`�`�`�v���O�������L�q�`�`�`
		double th = frame_count*M_PI/50; 
		posX = r * cos( th );
		posY = r * sin( th );

        //-----------------------------------------------------------------
    }

	// �蓮�A�j���[�V�����̐ݒ�
    void SetManualAnimation()
    {
        //-----------------------------------------------------------------
        // �A�j���[�V����
        //-----------------------------------------------------------------

            // �`�`�`�v���O�������L�q�`�`�`
		double th = frame_count*M_PI/50; 
		posX = r * cos( th );
		posY = r * sin( th );

		//-----------------------------------------------------------------
    }

    //�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


    // �`��̑O����
    void BeginPaint()
    {
        // ������������L����
        glEnable( GL_BLEND );
        // �������@�̎w��
        glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    }

    // �`��̌㏈��
    void EndPaint()
    {
        // �����������𖳌���
        glDisable( GL_BLEND );
    }


    // �I�u�W�F�N�g�̕`��
    void draw()
    {
		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`
		//��3�T�ۑ�
		//---------------------------------------------------------------------
        // �����A�j���[�V�����̏���
        if ( IsAutomaticAnimation() && frame_count<max_frame_count ) {
            // �t���[���ԍ��̍X�V
            SetSliderValue( FRAME_CONTROLS, ++frame_count );
            // �����A�j���[�V����
            SetAutomaticAnimation();
        }
        // �蓮�A�j���[�V�����̏���
        else {
            // �t���[���ԍ����擾
            frame_count = (int)GetSliderValue( FRAME_CONTROLS );
            // �蓮�A�j���[�V����
            SetManualAnimation();            
        }
		//�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`�`


        // �X�[�p�[�N���X�̕`�惁�\�b�h���R�[���i�K�{�j
        ModelerView::draw();
		ParticleSystem *ps = ModelerApplication::Instance()->GetParticleSystem();
		Mat4f CameraTransforms = ps->getModelViewMatrix();


        // �`��J�n
        BeginPaint();
		glPushMatrix();             // �������W�n��ۑ�

		//����`��
		DrawAxis();
		
		glRotated(-90 , 1,0,0);
		

		setAmbientColor(0, 0.5f, 0.5f);
		//�P�̎���蕔����`��
		setAmbientColor(0.5f, 0, 0);
		glTranslated(0,0,-10);
		glScaled(0.1,0.1,0.1);
		glPushMatrix(); 
			drawCylinder( 3, 3, 2 );

			//�P�̎厲������`��
			setAmbientColor(0.8f, 0.8f, 0.8f);
			drawCylinder( 55, 1, 1 );

			//�P�̑���������`��
			drawCylinder( 20, 2, 2 );

			//����������`��
			setAmbientColor(0.9f, 0.9f, 0.9f);
			glTranslated(0,0,GetSliderValue(UMB_POSITION));
			glPushMatrix();  
				drawCylinder( 3, 2.5, 2.5 );
		


				
					//�׍��P
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
		//�P�̐��

		  
		glTranslated(0,0,55);
		
		glPushMatrix();
			glTranslated(0,0,100);
			setAmbientColor(0, 0.9f, 0.9f);
			ps->SpawnParticles( CameraTransforms );
		glPopMatrix();
		//�J���~�炷

		/*
		glPushMatrix();
			// �P�̕`��
			Vec3d A( 0, 0, 0 );
			Vec3d B(  20, 0, -40*0.886 );
			Vec3d C(  0,  40*0.886, -40 );
			// �@���x�N�g��
			Vec3d N = ( A-C) ^ ( B-C );

			glBegin( GL_TRIANGLES );
			glNormal3d( N[0], N[1], N[2] );
			glVertex3d( A[0], A[1], A[2] );
			glVertex3d( B[0], B[1], B[2] );
			glVertex3d( C[0], C[1], C[2] );
			glEnd();

			setDiffuseColor( 0.8, 0.8 ,0.8 ,1 );
			setAmbientColor(0, 0.5f, 0.5f);


		glPopMatrix();
		*/

		for(double i = 0; i < 360;i+= 0.1){

			setAmbientColor(0, 0, 0.8f);
			setDiffuseColor( 0.8, 0.8 ,0.8 ,0.8 );
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
			//�׍��Q�̐��
			//�׍��Q�̕`��
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



			//�׍�3�̕`��
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

			//�׍��R�̐��
			glTranslated(0,0,40);
			glRotated(GetSliderValue(UMB_ANGLE4),0,1,0);

			//�׍�4�̕`��
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

		glPopMatrix();   
		glPopMatrix();   
		glPopMatrix();    

		//



  
		 // �`�`�`�v���O�������L�q�`�`�`

        //---------------------------------------------------------------------

        // �`��I��
        EndPaint();
    }
};

// __MODEL_H__
#endif