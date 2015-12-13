//=============================================================================
// �t�@�C��: controller.h
//=============================================================================
// �X���C�_�R���g���[���̐ݒ�
//=============================================================================

#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

// �w�b�_�t�@�C���̃C���N���[�h
#include "modelerapp.h"

// �t���[���ԍ��̍ő�l
extern int max_frame_count;

// �R���g���[�����ʗp�̗񋓎q
enum CONTROLLERS {

	FRAME_CONTROLS,   // �t���[���R���g���[���i�ύX���Ȃ�����)
    // �`�`�`�񋓎q��ǉ��`�`�`
	X_POSITION,
	Y_POSITION,
	Z_POSITION,
	UMB_CNT_ANGLE,//�P�̓����������̍��W
	UMB_POSITION,//�P�̓����������̍��W
	UMB_ANGLE1,
	UMB_ANGLE2,
	UMB_ANGLE3,
	UMB_ANGLE4,
    NUM_CONTROLS,   // �R���g���[�����i�K�������ɒǉ��j
};

// �R���g���[���̐ݒ�
//�iNUM_CONTROLS������CONTROLLERS�񋓎q�ƂP�F�P�ɑΉ��t����j
void SetController( ModelerControl* controls )
{
	// �t���[���ԍ��̐���p�X���C�_
    controls[FRAME_CONTROLS] = ModelerControl( "Frame Number", 0, (float)max_frame_count, 1, 0 );

    // �`�`�`�X���C�_��ǉ��`�`�`
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
