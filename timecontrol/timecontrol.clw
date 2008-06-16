; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTimecontrolView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "timecontrol.h"
LastPage=0

ClassCount=10
Class1=CTimecontrolApp
Class2=CTimecontrolDoc
Class3=CTimecontrolView
Class4=CMainFrame

ResourceCount=11
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_TIMECONTROL_FORM
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=IDD_TIMECONTROL_FORM (English (U.S.))
Class6=CMainList
Resource6=IDD_SureNew
Class7=CAddingDialog
Resource7=IDD_DIALOG1
Class8=CSureDlg
Resource8=IDD_Suse
Class9=CCorrectDlg
Resource9=IDD_CorrectDlg
Class10=NewList
Resource10=IDR_ContextMenu
Resource11=IDR_MAINFRAME (English (U.S.))

[CLS:CTimecontrolApp]
Type=0
HeaderFile=timecontrol.h
ImplementationFile=timecontrol.cpp
Filter=N
LastObject=ID_FILE_OPEN

[CLS:CTimecontrolDoc]
Type=0
HeaderFile=timecontrolDoc.h
ImplementationFile=timecontrolDoc.cpp
Filter=N
LastObject=CTimecontrolDoc

[CLS:CTimecontrolView]
Type=0
HeaderFile=timecontrolView.h
ImplementationFile=timecontrolView.cpp
Filter=D
LastObject=CTimecontrolView
BaseClass=CFormView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_NEW
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=timecontrol.cpp
ImplementationFile=timecontrol.cpp
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
Class=CTimecontrolView

[DLG:IDD_TIMECONTROL_FORM (English (U.S.))]
Type=1
Class=CTimecontrolView
ControlCount=1
Control1=IDC_LIST1,SysListView32,1350631437

[TB:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_Stop_Time
Command6=ID_add_task
Command7=ID_Delete
Command8=ID_correct
Command9=ID_APP_ABOUT
CommandCount=9

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_Stop_Time
Command9=ID_add_task
Command10=ID_Delete
Command11=ID_correct
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=?
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

[CLS:CMainList]
Type=0
HeaderFile=MainList.h
ImplementationFile=MainList.cpp
BaseClass=CListCtrl
Filter=W
LastObject=ID_FILE_OPEN

[DLG:IDD_DIALOG1]
Type=1
Class=CAddingDialog
ControlCount=4
Control1=IDC_EDIT3,edit,1350631552
Control2=IDOK,button,1342242817
Control3=IDCANCEL,button,1342242816
Control4=IDC_STATIC,static,1342308352

[CLS:CAddingDialog]
Type=0
HeaderFile=AddingDialog.h
ImplementationFile=AddingDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=CAddingDialog
VirtualFilter=dWC

[DLG:IDD_Suse]
Type=1
Class=CSureDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

[CLS:CSureDlg]
Type=0
HeaderFile=SureDlg.h
ImplementationFile=SureDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSureDlg
VirtualFilter=dWC

[DLG:IDD_CorrectDlg]
Type=1
Class=CCorrectDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_EDIT4,edit,1350631552
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT6,edit,1350566016
Control11=IDC_STATIC,static,1342308352

[CLS:CCorrectDlg]
Type=0
HeaderFile=CorrectDlg.h
ImplementationFile=CorrectDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT2
VirtualFilter=dWC

[DLG:IDD_SureNew]
Type=1
Class=NewList
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352

[CLS:NewList]
Type=0
HeaderFile=NewList.h
ImplementationFile=NewList.cpp
BaseClass=CDialog
Filter=D
LastObject=IDCANCEL

[MNU:IDR_ContextMenu]
Type=1
Class=?
Command1=ID_MENUITEM32785
Command2=ID_Delete
Command3=ID_correct
CommandCount=3

