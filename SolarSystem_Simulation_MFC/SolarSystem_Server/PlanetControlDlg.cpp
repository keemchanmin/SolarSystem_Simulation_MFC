// PlanetControlDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Term_Project.h"
#include "PlanetControlDlg.h"
#include "afxdialogex.h"


// PlanetControlDlg 대화 상자

IMPLEMENT_DYNAMIC(PlanetControlDlg, CDialog)

PlanetControlDlg::PlanetControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SIMUL, pParent)
	, m_V_speed(0)
	, m_E_speed(0)
	, m_Mer_life(0)
	, m_V_life(0)
	, m_E_life(0)
	, Mer_spin(0)
	, V_spin(0)
	, E_spin(0)
	, m_Mars_speed(0)
	, m_Mars_life(0)
	, Mars_spin(0)
	, m_J_speed(0)
	, m_J_life(0)
	, Ju_spin(0)
	, m_Sa_speed(0)
	, m_Sa_life(0)
	, Sa_spin(0)
	, m_Ur_speed(0)
	, m_Ur_life(0)
	, Ur_spin(0)
	, m_Ne_speed(0)
	, m_Ne_life(0)
	, Ne_spin(0)
{

}

PlanetControlDlg::~PlanetControlDlg()
{
}

void PlanetControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MER_SPEED, m_Mer_speed);
	DDX_Text(pDX, IDC_V_SPEED, m_V_speed);
	DDX_Text(pDX, IDC_E_SPEED, m_E_speed);
	DDX_Text(pDX, IDC_EDIT9, m_Mer_life);
	DDX_Text(pDX, IDC_EDIT10, m_V_life);
	DDX_Text(pDX, IDC_EDIT11, m_E_life);
	DDX_Text(pDX, IDC_EDIT2, Mer_spin);
	DDX_Text(pDX, IDC_EDIT1, V_spin);
	DDX_Text(pDX, IDC_EDIT5, E_spin);
	DDX_Text(pDX, IDC_MA_SPEED, m_Mars_speed);
	DDX_Text(pDX, IDC_EDIT12, m_Mars_life);
	DDX_Text(pDX, IDC_EDIT7, Mars_spin);
	DDX_Text(pDX, IDC_JU_SPEED, m_J_speed);
	DDX_Text(pDX, IDC_EDIT13, m_J_life);
	DDX_Text(pDX, IDC_EDIT4, Ju_spin);
	DDX_Text(pDX, IDC_SA_SPEED, m_Sa_speed);
	DDX_Text(pDX, IDC_EDIT14, m_Sa_life);
	DDX_Text(pDX, IDC_EDIT8, Sa_spin);
	DDX_Text(pDX, IDC_UR_SPEED, m_Ur_speed);
	DDX_Text(pDX, IDC_EDIT15, m_Ur_life);
	DDX_Text(pDX, IDC_EDIT18, Ur_spin);
	DDX_Text(pDX, IDC_NE_SPEED, m_Ne_speed);
	DDX_Text(pDX, IDC_EDIT16, m_Ne_life);
	DDX_Text(pDX, IDC_EDIT19, Ne_spin);
}


BEGIN_MESSAGE_MAP(PlanetControlDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON2, &PlanetControlDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// PlanetControlDlg 메시지 처리기


void PlanetControlDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}
