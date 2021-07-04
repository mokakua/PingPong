object Form1: TForm1
  Left = 243
  Top = 138
  Width = 1288
  Height = 685
  Caption = 'Form1'
  Color = clBtnFace
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object Shape1: TShape
    Left = 0
    Top = 0
    Width = 1272
    Height = 646
    Align = alClient
    Brush.Color = clMoneyGreen
  end
  object gameArea: TShape
    Left = 0
    Top = 0
    Width = 1272
    Height = 646
    Align = alClient
    Brush.Color = clMoneyGreen
  end
  object countdownLabel: TLabel
    Left = 528
    Top = 104
    Width = 222
    Height = 447
    Alignment = taCenter
    Caption = '3'
    Color = clMoneyGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -400
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Transparent = True
    Layout = tlCenter
    Visible = False
  end
  object rPointsLabel: TLabel
    Left = 1216
    Top = 320
    Width = 55
    Height = 125
    Alignment = taCenter
    Caption = '0'
    Color = clMoneyGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clOlive
    Font.Height = -107
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object lPointsLabel: TLabel
    Left = 120
    Top = 320
    Width = 55
    Height = 125
    Alignment = taCenter
    Caption = '0'
    Color = clMoneyGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clOlive
    Font.Height = -107
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Transparent = True
  end
  object ball: TShape
    Left = 520
    Top = 560
    Width = 30
    Height = 30
    Brush.Color = clPurple
    Shape = stCircle
    Visible = False
  end
  object paddleLeft: TShape
    Left = 58
    Top = 312
    Width = 30
    Height = 150
    Brush.Color = clGreen
  end
  object paddleRight: TShape
    Left = 1304
    Top = 312
    Width = 30
    Height = 150
    Brush.Color = clAqua
  end
  object Label4: TLabel
    Left = 728
    Top = 536
    Width = 150
    Height = 36
    Alignment = taCenter
    AutoSize = False
    Caption = 'Hits'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -31
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object hitsLabel: TLabel
    Left = 728
    Top = 584
    Width = 150
    Height = 36
    Alignment = taCenter
    AutoSize = False
    Caption = 'Hits'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -31
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object perkShape: TShape
    Left = 584
    Top = 48
    Width = 80
    Height = 80
    Brush.Color = clRed
    Shape = stCircle
    Visible = False
  end
  object Label5: TLabel
    Left = 408
    Top = 536
    Width = 150
    Height = 36
    Alignment = taCenter
    AutoSize = False
    Caption = 'BSpeed'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -31
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object BSpeedLabel: TLabel
    Left = 408
    Top = 584
    Width = 150
    Height = 36
    Alignment = taCenter
    AutoSize = False
    Caption = 'BSpeed'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -31
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object perkTimeLabel: TLabel
    Left = 632
    Top = 352
    Width = 18
    Height = 37
    Alignment = taCenter
    Caption = '8'
    Color = clRed
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Transparent = True
    Visible = False
  end
  object startButton: TButton
    Left = 480
    Top = 232
    Width = 305
    Height = 73
    Caption = 'START(Enter)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -40
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = startButtonClick
  end
  object dalejButton: TButton
    Left = 504
    Top = 152
    Width = 257
    Height = 73
    Caption = 'GRAJ DALEJ'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -40
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
    OnClick = dalejButtonClick
  end
  object koniecButton: TButton
    Left = 504
    Top = 432
    Width = 257
    Height = 73
    Caption = 'KONIEC GRY'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -40
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Visible = False
    OnClick = koniecButtonClick
  end
  object mainTimer: TTimer
    Enabled = False
    Interval = 15
    OnTimer = mainTimerTimer
    Left = 40
    Top = 8
  end
  object paddleLeftUpTimer: TTimer
    Enabled = False
    Interval = 15
    OnTimer = paddleLeftUpTimerTimer
    Left = 8
    Top = 48
  end
  object paddleLeftDownTimer: TTimer
    Enabled = False
    Interval = 15
    OnTimer = paddleLeftDownTimerTimer
    Left = 8
    Top = 80
  end
  object paddleRightUpTimer: TTimer
    Enabled = False
    Interval = 15
    OnTimer = paddleRightUpTimerTimer
    Left = 80
    Top = 48
  end
  object paddleRightDownTimer: TTimer
    Enabled = False
    Interval = 15
    OnTimer = paddleRightDownTimerTimer
    Left = 80
    Top = 80
  end
  object perkTimer: TTimer
    Enabled = False
    OnTimer = perkTimerTimer
    Left = 40
    Top = 120
  end
  object cannonTimer: TTimer
    Enabled = False
    OnTimer = cannonTimerTimer
    Left = 40
    Top = 152
  end
end
