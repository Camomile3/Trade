#include "DxLib.h"
#include "class.h"

FUN fun;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	void Test();

	if (DxLib_Init() == -1)    // �c�w���C�u��������������
	{
		return -1;    // �G���[���N�����璼���ɏI��
	}


	//�֐�
	fun.main();



	WaitKey();        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

	DxLib_End();        // �c�w���C�u�����g�p�̏I������

	return 0;        // �\�t�g�̏I��
}