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

		setAmbientColor(0, 0.5f, 0.5f);
		//�P�̎���蕔����`��
		drawCylinder( 3, 3, 2 );

		//�P�̎厲������`��
		drawCylinder( 40, 1, 1 );

		//�P�̓���������`��




		/*
		//�P�̓����ꏊ���쐬�i���W�n��ۑ��j
		glPushMatrix();
		drawCylinder(3,2,2);

	
		//���_���P�̒[�����Ɉړ�
		glTranslated(0,0,20);

		//�P�̖��[��`��
		drawCylinder(1,3,1);

		//�����ꏊ�̍��W�n�𕜌�
		glPopMatrix();
		
		//�������쐬

		glRotated(30,0,1,0);
		drawCylinder(10,1,1);
		
		glRotated(-30,0,1,0);
		glTranslated(sin(AngleToRadian(30))*10,0,cos(AngleToRadian(30))*10);
		//��{�ڂ̑卜���쐬
		glPushMatrix();
		glRotated(-30,0,1,0);
		


		glBegin(GL_LINE_STRIP);
			glVertex3d(0,0,10);
			glVertex3d(0,0,-10);
		glEnd();
		

		//��{�ڂ̑卜���쐬	
		glTranslated(0,0,-10);
		glRotated(40,0,1,0);
		
		drawCylinder(20,1,1);
		glBegin(GL_LINE_STRIP);
			glVertex3d(0,0,20);
			glVertex3d(0,0,0);
		glEnd();

		*/


  
		 // �`�`�`�v���O�������L�q�`�`�`

        //---------------------------------------------------------------------

        // �`��I��
        EndPaint();
    }
};

// __MODEL_H__
#endif