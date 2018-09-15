#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int Gra;
	void Test();
	void ButtonOver();

	if (DxLib_Init() == -1)    // �c�w���C�u��������������
	{
		return -1;    // �G���[���N�����璼���ɏI��
	}
	//�𑜓x�擾
	int WinX = GetSystemMetrics(SM_CXSCREEN);
	int WinY = GetSystemMetrics(SM_CYSCREEN);

	//�𑜓x�Z�b�g
	SetGraphMode(WinX, WinY, 32, 60);

	//�^�C�g���摜�\��
	Gra = LoadGraph("Resouce/BG_Title.jpg");

	DrawExtendGraph(0, 0, WinX, WinY, Gra, TRUE);

	//�}�E�X
	SetMouseDispFlag(TRUE);

	//�֐�
	ButtonOver();

	Test();

	// �ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	DeleteGraph(Gra);

	WaitKey();        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

	DxLib_End();        // �c�w���C�u�����g�p�̏I������

	return 0;        // �\�t�g�̏I��
}


//�{�^��
void ButtonOver() {
	int GraBtn1;
	int MouseX, MouseY;

	GraBtn1 = LoadGraph("Resouce/T_Btn1.png");

	DrawGraph(870, 800, GraBtn1, TRUE);
	while (CheckHitKeyAll() == 0) {
		while (CheckHitKeyAll() == 0) {
			GetMousePoint(&MouseX, &MouseY);
			if (MouseX >= 870 && MouseX <= 870 + 180) {
				if (MouseY >= 800 && MouseY <= 800 + 42) {
					GraphFilter(GraBtn1, DX_GRAPH_FILTER_INVERT);
					DrawGraph(870, 800, GraBtn1, TRUE);
					break;
				}
			}
			WaitTimer(100);
		}
		while (CheckHitKeyAll() == 0) {
			GetMousePoint(&MouseX, &MouseY);
			if (MouseX >= 870 && MouseX <= 870 + 180) {
				if (MouseY >= 800 && MouseY <= 800 + 42) {
				}
				else {
					GraphFilter(GraBtn1, DX_GRAPH_FILTER_INVERT);
					DrawGraph(870, 800, GraBtn1, TRUE);
					break;
				}
			}
			else {
				GraphFilter(GraBtn1, DX_GRAPH_FILTER_INVERT);
				DrawGraph(870, 800, GraBtn1, TRUE);
				break;
			}
			WaitTimer(100);
		}
	}
}

void Test()
{
	char StrBuf[128], StrBuf2[32];
	int StringCr, BoxCr;
	int MouseX, MouseY;

	// ���F�̒l���擾
	StringCr = GetColor(255, 255, 255);

	// ���̒l���擾
	BoxCr = GetColor(0, 0, 0);

	// �L�[���������܂Ń��[�v
	while (CheckHitKeyAll() == 0)
	{
		// �}�E�X�̈ʒu���擾
		GetMousePoint(&MouseX, &MouseY);

		// �\�����镶������쐬
		{
			lstrcpy(StrBuf, "���W �w"); // ������"���W �w"��StrBuf�ɃR�s�[	
			_itoa_s(MouseX, StrBuf2, 10); // MouseX�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
			lstrcat(StrBuf, StrBuf2); // StrBuf�̓��e��StrBuf2�̓��e��t������
			lstrcat(StrBuf, "�@�x "); // StrBuf�̓��e�ɕ�����"�x"��t������
			_itoa_s(MouseY, StrBuf2, 10); // MouseY�̒l�𕶎���ɂ���StrBuf2�Ɋi�[
			lstrcat(StrBuf, StrBuf2); // StrBuf�̓��e��StrBuf2�̓��e��t������
		}

		// ��ʍ���̗̈�ɍ����l�p��`���O�ɕ`���Ă�����
		// �����������
		DrawBox(0, 0, 200, 32, BoxCr, TRUE);

		// ���W�������`��
		DrawString(0, 0, StrBuf, StringCr);

		// ���b�Z�[�W����
		if (ProcessMessage() == -1)
		{
			break;    // �G���[���N�����烋�[�v�𔲂���
		}

		// ��莞�ԑ҂�
		WaitTimer(100);
	}
}