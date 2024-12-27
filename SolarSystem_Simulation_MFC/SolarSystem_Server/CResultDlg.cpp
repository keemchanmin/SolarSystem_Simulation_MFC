// CResultDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Term_Project.h"
#include "CResultDlg.h"
#include "afxdialogex.h"


// CResultDlg 대화 상자

IMPLEMENT_DYNAMIC(CResultDlg, CDialog)

CResultDlg::CResultDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_Result, pParent)
	, Mer_speed(0)
	, V_speed(0)
	, E_speed(0)
	, Mer_life(0)
	, V_life(0)
	, E_life(0)
	, Mer_spin(_T(""))
	, V_spin(_T(""))
	, E_spin(_T(""))
	, Mars_speed(0)
	, Mars_life(0)
	, Mars_spin(_T(""))
	, Ju_speed(0)
	, Ju_life(0)
	, Ju_spin(_T(""))
	, Sa_speed(0)
	, Sa_life(0)
	, Sa_spin(_T(""))
	, Ur_speed(0)
	, Ur_life(0)
	, Ur_spin(_T(""))
	, Ne_speed(0)
	, Ne_life(0)
	, Ne_spin(_T(""))
	, Moon_flag(_T(""))
{

}

CResultDlg::~CResultDlg()
{
}

void CResultDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Mer_speed_Result, Mer_speed);
	DDX_Text(pDX, IDC_m_V_speed_Result, V_speed);
	DDX_Text(pDX, IDC_m_E_speed_Result, E_speed);
	DDX_Text(pDX, IDC_Mer_life, Mer_life);
	DDX_Text(pDX, IDC_V_life, V_life);
	DDX_Text(pDX, IDC_E_life, E_life);
	DDX_Text(pDX, IDC_EDIT3, Mer_spin);
	DDX_Text(pDX, IDC_EDIT17, V_spin);
	DDX_Text(pDX, IDC_EDIT6, E_spin);
	DDX_Text(pDX, IDC_m_E_speed_Result2, Mars_speed);
	DDX_Text(pDX, IDC_E_life2, Mars_life);
	DDX_Text(pDX, IDC_EDIT20, Mars_spin);
	DDX_Text(pDX, IDC_m_E_speed_Result3, Ju_speed);
	DDX_Text(pDX, IDC_E_life3, Ju_life);
	DDX_Text(pDX, IDC_EDIT21, Ju_spin);
	DDX_Text(pDX, IDC_m_E_speed_Result4, Sa_speed);
	DDX_Text(pDX, IDC_E_life4, Sa_life);
	DDX_Text(pDX, IDC_EDIT22, Sa_spin);
	DDX_Text(pDX, IDC_m_E_speed_Result5, Ur_speed);
	DDX_Text(pDX, IDC_E_life5, Ur_life);
	DDX_Text(pDX, IDC_EDIT23, Ur_spin);
	DDX_Text(pDX, IDC_m_E_speed_Result6, Ne_speed);
	DDX_Text(pDX, IDC_E_life6, Ne_life);
	DDX_Text(pDX, IDC_EDIT24, Ne_spin);
	DDX_Text(pDX, IDC_EDIT9, Moon_flag);


	
}


BEGIN_MESSAGE_MAP(CResultDlg, CDialog)
	
END_MESSAGE_MAP()


// CResultDlg 메시지 처리기



