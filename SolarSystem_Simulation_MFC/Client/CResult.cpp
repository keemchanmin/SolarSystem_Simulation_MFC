// CResult.cpp: 구현 파일
//

#include "pch.h"
#include "TermProject_TCP_Client.h"
#include "CResult.h"
#include "afxdialogex.h"


// CResult 대화 상자

IMPLEMENT_DYNAMIC(CResult, CDialog)

CResult::CResult(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG2, pParent)
	, Mer_speed(0)
	, Mer_life(0)
	, Mer_spin(_T(""))
	, V_speed(0)
	, V_life(0)
	, V_spin(_T(""))
	, E_speed(0)
	, E_life(0)
	, E_spin(_T(""))
	, Mars_speed(0)
	, Mars_life(0)
	, Mars_spin(_T(""))
	, J_speed(0)
	, J_life(0)
	, J_spin(_T(""))
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

CResult::~CResult()
{
}

void CResult::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Mer_speed);
	DDX_Text(pDX, IDC_EDIT3, Mer_life);
	DDX_Text(pDX, IDC_EDIT2, Mer_spin);
	DDX_Text(pDX, IDC_EDIT7, V_speed);
	DDX_Text(pDX, IDC_EDIT9, V_life);
	DDX_Text(pDX, IDC_EDIT8, V_spin);
	DDX_Text(pDX, IDC_EDIT10, E_speed);
	DDX_Text(pDX, IDC_EDIT12, E_life);
	DDX_Text(pDX, IDC_EDIT11, E_spin);
	DDX_Text(pDX, IDC_EDIT25, Mars_speed);
	DDX_Text(pDX, IDC_EDIT27, Mars_life);
	DDX_Text(pDX, IDC_EDIT26, Mars_spin);
	DDX_Text(pDX, IDC_EDIT28, J_speed);
	DDX_Text(pDX, IDC_EDIT30, J_life);
	DDX_Text(pDX, IDC_EDIT29, J_spin);
	DDX_Text(pDX, IDC_EDIT31, Sa_speed);
	DDX_Text(pDX, IDC_EDIT33, Sa_life);
	DDX_Text(pDX, IDC_EDIT32, Sa_spin);
	DDX_Text(pDX, IDC_EDIT34, Ur_speed);
	DDX_Text(pDX, IDC_EDIT36, Ur_life);
	DDX_Text(pDX, IDC_EDIT35, Ur_spin);
	DDX_Text(pDX, IDC_EDIT19, Ne_speed);
	DDX_Text(pDX, IDC_EDIT21, Ne_life);
	DDX_Text(pDX, IDC_EDIT20, Ne_spin);
	DDX_Text(pDX, IDC_EDIT4, Moon_flag);
	
}


BEGIN_MESSAGE_MAP(CResult, CDialog)
END_MESSAGE_MAP()


// CResult 메시지 처리기
