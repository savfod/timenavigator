; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTimeControlDoc
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TimeControl.h"
LastPage=0

ClassCount=9
Class1=CTimeControlApp
Class2=CTimeControlDoc
Class3=CTimeControlView
Class4=CMainFrame

ResourceCount=10
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TIMECONTROL_FORM
Resource4=IDD_ERROR
Resource5=IDD_ABOUTBOX (English (U.S.))
Class5=CAboutDlg
Resource6=IDD_TIMECONTROL_FORM (English (U.S.))
Class6=CDlgAdding
Resource7=IDD_ADDING
Class7=CDlgError
Resource8=IDD_SURE
Class8=CDlgSure
Resource9=IDR_MAINFRAME (English (U.S.))
Class9=CDlgCorrect
Resource10=IDD_CORRECT

[CLS:CTimeControlApp]
Type=0
HeaderFile=TimeControl.h
ImplementationFile=TimeControl.cpp
Filter=N

[CLS:CTimeControlDoc]
Type=0
HeaderFile=TimeControlDoc.h
ImplementationFile=TimeControlDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CTimeControlDoc

[CLS:CTimeControlView]
Type=0
HeaderFile=TimeControlView.h
ImplementationFile=TimeControlView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=CTimeControlView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=TimeControl.cpp
ImplementationFile=TimeControl.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
CommandCount=16
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command16=ID_APP_ABOUT

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
CommandCount=14
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE

[DLG:IDD_TIMECONTROL_FORM]
Type=1
Class=CTimeControlView

[DLG:IDD_TIMECONTROL_FORM (English (U.S.))]
Type=1
Class=CTimeControlView
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631429

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_Stop_Time
Command11=ID_add_task
Command12=ID_Delete
Command13=ID_correct
Command14=ID_EDIT_UNDO
Command15=ID_EDIT_CUT
Command16=ID_EDIT_COPY
Command17=ID_EDIT_PASTE
Command18=ID_VIEW_TOOLBAR
Command19=ID_VIEW_STATUS_BAR
Command20=ID_APP_ABOUT
CommandCount=20

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_add_task
Command2=ID_correct
Command3=ID_EDIT_COPY
Command4=ID_FILE_NEW
Command5=ID_FILE_OPEN
Command6=ID_FILE_PRINT
Command7=ID_FILE_SAVE
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_Delete
Command11=ID_EDIT_CUT
Command12=ID_Stop_Time
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_EDIT_COPY
Command16=ID_EDIT_PASTE
Command17=ID_EDIT_CUT
Command18=ID_EDIT_UNDO
CommandCount=18

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_ADDING]
Type=1
Class=CDlgAdding
ControlCount=7
Control1=IDC_EDIT1,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_TYPE,button,1342308361
Control7=IDC_RADIO2,button,1342177289

[CLS:CDlgAdding]
Type=0
HeaderFile=DlgAdding.h
ImplementationFile=DlgAdding.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgAdding
VirtualFilter=dWC

[DLG:IDD_ERROR]
Type=1
Class=CDlgError
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352

[CLS:CDlgError]
Type=0
HeaderFile=DlgError.h
ImplementationFile=DlgError.cpp
BaseClass=CDialog
Filter=D

[DLG:IDD_SURE]
Type=1
Class=CDlgSure
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CDlgSure]
Type=0
HeaderFile=DlgSure.h
ImplementationFile=DlgSure.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgSure

[DLG:IDD_CORRECT]
Type=1
Class=CDlgCorrect
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_TYPE,button,1342308361
Control6=IDC_RADIO2,button,1342177289
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PLUS,button,1342308361
Control9=IDC_RADIO4,button,1342177289
Control10=IDC_EDIT2,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT3,edit,1350631552
Control15=IDC_EDIT4,edit,1350631552
Control16=IDC_STATIC,static,1342308352

[CLS:CDlgCorrect]
Type=0
HeaderFile=DlgCorrect.h
ImplementationFile=DlgCorrect.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgCorrect
VirtualFilter=dWC

