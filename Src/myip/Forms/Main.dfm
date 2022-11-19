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
  OldCreateOrder = False
  Position = poScreenCenter
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
  object PublicIPPopupMenu: TPopupMenu
    Left = 384
    Top = 48
    object BtnCopyPublicIP: TMenuItem
      Caption = '&Copy'
      OnClick = BtnCopyPublicIPClick
    end
  end
end
