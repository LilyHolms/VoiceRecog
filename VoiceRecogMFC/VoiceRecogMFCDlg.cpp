
// VoiceRecogMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "VoiceRecogMFC.h"
#include "VoiceRecogMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//lilystart

#include "VoiceMain.h"

//lilyend

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CVoiceRecogMFCDlg �Ի���



CVoiceRecogMFCDlg::CVoiceRecogMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CVoiceRecogMFCDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVoiceRecogMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVoiceRecogMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_MIC, &CVoiceRecogMFCDlg::OnBnClickedButtonMic)
	ON_BN_CLICKED(IDC_BUTTON_END, &CVoiceRecogMFCDlg::OnBnClickedButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON_QUIT, &CVoiceRecogMFCDlg::OnBnClickedButtonQuit)
	ON_BN_CLICKED(IDC_BUTTON_START, &CVoiceRecogMFCDlg::OnBnClickedButtonStart)
	ON_EN_CHANGE(IDC_EDIT_RESULT, &CVoiceRecogMFCDlg::OnEnChangeEditResult)
END_MESSAGE_MAP()


// CVoiceRecogMFCDlg ��Ϣ�������

BOOL CVoiceRecogMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CVoiceRecogMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CVoiceRecogMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CVoiceRecogMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CVoiceRecogMFCDlg::OnBnClickedButtonMic()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	VoiceMain::MyMain();
}

void CVoiceRecogMFCDlg::OnBnClickedButtonStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	const char *pc = "a character array";
	GetDlgItem(IDC_EDIT_RESULT)->SetWindowTextW(CString(pc));
	
}

void CVoiceRecogMFCDlg::OnBnClickedButtonEnd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	VoiceMain::MyMain();
}

void CVoiceRecogMFCDlg::OnBnClickedButtonQuit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	char *myresult = VoiceMain::MyEnd();
	GetDlgItem(IDC_EDIT_RESULT)->SetWindowTextW(CString(myresult));
	GetDlgItem(IDC_STATIC_RESULT)->SetWindowTextW(CString("zaishiyishi"));
}

void CVoiceRecogMFCDlg::OnEnChangeEditResult()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



//lilystart-voice-part
