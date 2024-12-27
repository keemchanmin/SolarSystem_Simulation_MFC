
// TermProject_TCP_ClientDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "TermProject_TCP_Client.h"
#include "TermProject_TCP_ClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTermProjectTCPClientDlg 대화 상자



CTermProjectTCPClientDlg::CTermProjectTCPClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TERMPROJECT_TCP_CLIENT_DIALOG, pParent)
	, Mer_speed(0)
	, Mer_life(0)
	, Mer_spin(0)
	, V_speed(0)
	, V_life(0)
	, V_spin(0)
	, E_speed(0)
	, E_life(0)
	, E_spin(0)
	, Mars_speed(0)
	, Mars_life(0)
	, Mars_spin(0)
	, J_speed(0)
	, J_life(0)
	, J_spin(0)
	, Sa_speed(0)
	, Sa_life(0)
	, Sa_spin(0)
	, Ur_speed(0)
	, Ur_life(0)
	, Ur_spin(0)
	, Ne_speed(0)
	, Ne_life(0)
	, Ne_spin(0)
{

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTermProjectTCPClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Mer_speed);
	DDX_Text(pDX, IDC_EDIT2, Mer_life);
	DDX_Text(pDX, IDC_EDIT3, Mer_spin);
	DDX_Text(pDX, IDC_EDIT4, V_speed);
	DDX_Text(pDX, IDC_EDIT5, V_life);
	DDX_Text(pDX, IDC_EDIT6, V_spin);
	DDX_Text(pDX, IDC_EDIT7, E_speed);
	DDX_Text(pDX, IDC_EDIT8, E_life);
	DDX_Text(pDX, IDC_EDIT9, E_spin);
	DDX_Text(pDX, IDC_EDIT10, Mars_speed);
	DDX_Text(pDX, IDC_EDIT11, Mars_life);
	DDX_Text(pDX, IDC_EDIT12, Mars_spin);
	DDX_Text(pDX, IDC_EDIT13, J_speed);
	DDX_Text(pDX, IDC_EDIT14, J_life);
	DDX_Text(pDX, IDC_EDIT15, J_spin);
	DDX_Text(pDX, IDC_EDIT16, Sa_speed);
	DDX_Text(pDX, IDC_EDIT17, Sa_life);
	DDX_Text(pDX, IDC_EDIT18, Sa_spin);
	DDX_Text(pDX, IDC_EDIT19, Ur_speed);
	DDX_Text(pDX, IDC_EDIT20, Ur_life);
	DDX_Text(pDX, IDC_EDIT21, Ur_spin);
	DDX_Text(pDX, IDC_EDIT22, Ne_speed);
	DDX_Text(pDX, IDC_EDIT23, Ne_life);
	DDX_Text(pDX, IDC_EDIT24, Ne_spin);
}

BEGIN_MESSAGE_MAP(CTermProjectTCPClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CTermProjectTCPClientDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON1, &CTermProjectTCPClientDlg::OnBnClickedButtonSend)
	ON_BN_CLICKED(IDC_BUTTON2, &CTermProjectTCPClientDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON3, &CTermProjectTCPClientDlg::OnBnClickedButtonStop)
	ON_EN_CHANGE(IDC_EDIT6, &CTermProjectTCPClientDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON5, &CTermProjectTCPClientDlg::OnBnClickedButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON6, &CTermProjectTCPClientDlg::OnBnClickedButtonFirstStartSimul)
END_MESSAGE_MAP()


// CTermProjectTCPClientDlg 메시지 처리기

BOOL CTermProjectTCPClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
//	UpdateData(FALSE);
	PD.Mer_speed = Mer_speed = 5;
	PD.Mer_life = Mer_life = 5;
	PD.Mer_spin = Mer_spin = 1;
	PD.V_speed = V_speed = 5;
	PD.V_life = V_life = 5;
	PD.V_spin = V_spin = 1;
	PD.E_speed = E_speed = 5;
	PD.E_life = E_life = 5;
	PD.E_spin = E_spin = 1;
	PD.Mars_speed =	Mars_speed = 5;
	PD.Mars_life = Mars_life = 5;
	PD.Mars_spin = Mars_spin = 1;
	PD.J_speed = J_speed = 5;
	PD.J_life = J_life = 5;
	PD.J_spin = J_spin = 1;
	PD.Sa_speed = Sa_speed = 5;
	PD.Sa_life = Sa_life = 5;
	PD.Sa_spin = Sa_spin = 1;
	PD.Ur_speed = Ur_speed = 5;
	PD.Ur_life = Ur_life = 5;
	PD.Ur_spin = Ur_spin = 1;
	PD.Ne_speed = Ne_speed = 5;
	PD.Ne_life = Ne_life = 5;
	PD.Ne_spin = Ne_spin = 1;

	UpdateData(FALSE);


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CTermProjectTCPClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTermProjectTCPClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTermProjectTCPClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTermProjectTCPClientDlg::OnBnClickedButtonConnect()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CConnectDlg dlg;
	if (dlg.DoModal() == IDOK) {
		m_Socket.Create();
		m_Socket.Connect(dlg.m_strAddress, 7000);
		m_Socket.Send(&PD, sizeof(PD));
	}
}


void CTermProjectTCPClientDlg::OnBnClickedButtonSend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	PD.Mer_speed = Mer_speed;
	PD.Mer_life	=	Mer_life;
	PD.Mer_spin	=	Mer_spin;
	PD.V_speed	=	V_speed;
	PD.V_life	=	V_life;
	PD.V_spin	=	V_spin;
	PD.E_speed	=	E_speed;
	PD.E_life	=	E_life;
	PD.E_spin	=	E_spin;
	PD.Mars_speed = Mars_speed;
	PD.Mars_life =	Mars_life;
	PD.Mars_spin =	Mars_spin;
	PD.J_speed	=	J_speed;
	PD.J_life	=	 J_life;
	PD.J_spin	=	 J_spin;
	PD.Sa_speed	=	 Sa_speed;
	PD.Sa_life	=	 Sa_life;
	PD.Sa_spin	=	 Sa_spin;
	PD.Ur_speed	=	 Ur_speed;
	PD.Ur_life	=	 Ur_life;
	PD.Ur_spin	=	 Ur_spin;
	PD.Ne_speed	=	 Ne_speed;
	PD.Ne_life	=	 Ne_life;
	PD.Ne_spin	=	 Ne_spin;
	PD.TCP_flag = -1;
	PD.stop_simul_flag = -1;
	PD.Open_flag = -1;
	strcpy_s(PD.Moon_flag,"");
	m_Socket.Send(&PD, sizeof(PD));
	UpdateData(FALSE);
}

void CTermProjectTCPClientDlg::OnBnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PD.TCP_flag = 1;
	PD.Open_flag = -1;
	PD.stop_simul_flag = -1;
	m_Socket.Send(&PD, sizeof(PD));
}


void CTermProjectTCPClientDlg::OnBnClickedButtonStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PD.TCP_flag = 0;
	PD.Open_flag = -1;
	PD.stop_simul_flag = -1;
	m_Socket.Send(&PD, sizeof(PD));
}


CString CTermProjectTCPClientDlg::spin2string(int spin)
{
	// TODO: 여기에 구현 코드 추가.
	if (spin==1)
		return _T("CK");
	else if (spin==-1)
		return _T("CCK");
	return CString();
}


void CTermProjectTCPClientDlg::OnEnChangeEdit6()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CTermProjectTCPClientDlg::OnBnClickedButtonEnd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PD.stop_simul_flag = 1;
	m_Socket.Send(&PD, sizeof(PD));
}


void CTermProjectTCPClientDlg::OnBnClickedButtonFirstStartSimul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	PD.Open_flag = 1;
	PD.TCP_flag = -1;
	PD.stop_simul_flag = -1;
	m_Socket.Send(&PD, sizeof(PD));
}
