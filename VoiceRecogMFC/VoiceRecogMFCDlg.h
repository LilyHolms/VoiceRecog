
// VoiceRecogMFCDlg.h : ͷ�ļ�
//

#pragma once


// CVoiceRecogMFCDlg �Ի���
class CVoiceRecogMFCDlg : public CDialogEx
{
// ����
public:
	CVoiceRecogMFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_VOICERECOGMFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonMic();
	afx_msg void OnBnClickedButtonEnd();
	afx_msg void OnBnClickedButtonQuit();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnEnChangeEditResult();
	void CVoiceRecogMFCDlg::MyMain();
};
