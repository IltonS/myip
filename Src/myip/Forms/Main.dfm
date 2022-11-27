object FrmMain: TFrmMain
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'What'#39's My IP'
  ClientHeight = 568
  ClientWidth = 475
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GbPublicIP: TGroupBox
    Left = 16
    Top = 24
    Width = 441
    Height = 81
    Caption = '  Your public IP address:  '
    PopupMenu = PublicIPPopupMenu
    TabOrder = 0
    object LblPublicIP: TLabel
      Left = 3
      Top = 28
      Width = 128
      Height = 29
      Caption = '  127.0.0.1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      PopupMenu = PublicIPPopupMenu
    end
  end
  object GbIPConfig: TGroupBox
    Left = 16
    Top = 232
    Width = 441
    Height = 281
    Caption = '  IP Config:  '
    TabOrder = 1
    object IPConfigMemo: TMemo
      Left = 13
      Top = 22
      Width = 412
      Height = 246
      ScrollBars = ssVertical
      TabOrder = 0
    end
  end
  object BtnClose: TButton
    Left = 382
    Top = 528
    Width = 75
    Height = 25
    Action = ActClose
    TabOrder = 2
  end
  object GbPrivateIP: TGroupBox
    Left = 16
    Top = 128
    Width = 441
    Height = 81
    Caption = '  Your private IP address:  '
    TabOrder = 3
    object LblPrivateIP: TLabel
      Left = 3
      Top = 28
      Width = 128
      Height = 29
      Caption = '  127.0.0.1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object PublicIPPopupMenu: TPopupMenu
    Left = 384
    Top = 48
    object BtnCopyPublicIP: TMenuItem
      Action = ActCopyPublicIP
    end
  end
  object MainMenu: TMainMenu
    Left = 304
    Top = 48
    object MyIP1: TMenuItem
      Caption = 'My IP'
      object MniSetDefaultAdapter: TMenuItem
        Action = ActSetDefaultAdapter
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object MniExit: TMenuItem
        Action = ActClose
      end
    end
    object Edit1: TMenuItem
      Caption = '&Edit'
      object CopyPublicIP1: TMenuItem
        Action = ActCopyPublicIP
      end
      object Close1: TMenuItem
        Action = ActCopyPrivateIP
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
      object mniAbout: TMenuItem
        Action = ActAbout
      end
    end
  end
  object ActionList: TActionList
    Left = 243
    Top = 48
    object ActSetDefaultAdapter: TAction
      Category = 'MyIP'
      Caption = 'ActSetDefaultAdapter'
    end
    object ActClose: TAction
      Category = 'MyIP'
      Caption = '&Close'
      OnExecute = ActCloseExecute
    end
    object ActCopyPublicIP: TAction
      Category = 'Edit'
      Caption = 'Copy Public IP'
      OnExecute = ActCopyPublicIPExecute
    end
    object ActCopyPrivateIP: TAction
      Category = 'Edit'
      Caption = 'ActCopyPrivateIP'
    end
    object ActAbout: TAction
      Category = 'Help'
      Caption = 'ActAbout'
    end
  end
end
