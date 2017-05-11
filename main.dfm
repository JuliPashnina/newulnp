object Fnewulnp: TFnewulnp
  Left = 215
  Top = 103
  Width = 678
  Height = 489
  Caption = 'Добавление новых населенных пунктов и улиц'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = [fsBold]
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 649
    Height = 234
  end
  object Bevel2: TBevel
    Left = 8
    Top = 252
    Width = 650
    Height = 154
  end
  object Label1: TLabel
    Left = 16
    Top = 41
    Width = 140
    Height = 16
    Caption = 'Населенный пункт'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clPurple
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 160
    Top = 69
    Width = 28
    Height = 16
    Caption = 'Код'
  end
  object Label4: TLabel
    Left = 270
    Top = 19
    Width = 221
    Height = 16
    Caption = 'Образец для поиска по названию'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 16
    Top = 182
    Width = 97
    Height = 16
    Caption = 'Для квитанции'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 36
    Top = 155
    Width = 75
    Height = 16
    Caption = 'Название'
  end
  object Label7: TLabel
    Left = 522
    Top = 184
    Width = 55
    Height = 16
    Caption = 'Индекс'
  end
  object Label8: TLabel
    Left = 24
    Top = 212
    Width = 43
    Height = 16
    Caption = 'NRES'
  end
  object Label9: TLabel
    Left = 120
    Top = 212
    Width = 54
    Height = 16
    Caption = 'NTERR'
  end
  object Label10: TLabel
    Left = 327
    Top = 213
    Width = 52
    Height = 16
    Caption = 'OKATO'
  end
  object Label11: TLabel
    Left = 122
    Top = 311
    Width = 28
    Height = 16
    Caption = 'Код'
  end
  object Label2: TLabel
    Left = 499
    Top = 204
    Width = 89
    Height = 32
    Caption = 'Для CC&B: CM_POSELOK'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    WordWrap = True
  end
  object Enaspunkt: TEdit
    Left = 119
    Top = 152
    Width = 385
    Height = 24
    Enabled = False
    TabOrder = 0
    OnExit = EnaspunktExit
  end
  object ChBnewnp: TCheckBox
    Left = 19
    Top = 131
    Width = 150
    Height = 17
    Caption = 'Добавить новый'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = ChBnewnpClick
  end
  object Eulitsa: TEdit
    Left = 121
    Top = 370
    Width = 385
    Height = 24
    Enabled = False
    TabOrder = 2
  end
  object CBsocrul: TComboBox
    Left = 521
    Top = 371
    Width = 89
    Height = 24
    Enabled = False
    ItemHeight = 16
    TabOrder = 3
    Items.Strings = (
      'ул'
      'пер'
      'пр-кт'
      'кв-л'
      'мкр'
      'б-р'
      'тракт'
      'туп'
      'уч-к'
      'ш'
      'сад'
      'рзд'
      'пл'
      'ст'
      'парк'
      'п'
      'км'
      'линия'
      'район'
      'тер'
      'проезд')
  end
  object BBadd: TBitBtn
    Left = 128
    Top = 416
    Width = 210
    Height = 25
    Caption = 'Формировать скрипт'
    TabOrder = 4
    OnClick = BBaddClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
      5555555FFFFFFFFFF5555550000000000555557777777777F5555550FFFFFFFF
      0555557F5FFFF557F5555550F0000FFF0555557F77775557F5555550FFFFFFFF
      0555557F5FFFFFF7F5555550F000000F0555557F77777757F5555550FFFFFFFF
      0555557F5FFFFFF7F5555550F000000F0555557F77777757F5555550FFFFFFFF
      0555557F5FFF5557F5555550F000FFFF0555557F77755FF7F5555550FFFFF000
      0555557F5FF5777755555550F00FF0F05555557F77557F7555555550FFFFF005
      5555557FFFFF7755555555500000005555555577777775555555555555555555
      5555555555555555555555555555555555555555555555555555}
    NumGlyphs = 2
  end
  object BBexit: TBitBtn
    Left = 392
    Top = 416
    Width = 153
    Height = 25
    Caption = 'Выход'
    TabOrder = 5
    OnClick = BBexitClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000120B0000120B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00330000000000
      03333377777777777F333301BBBBBBBB033333773F3333337F3333011BBBBBBB
      0333337F73F333337F33330111BBBBBB0333337F373F33337F333301110BBBBB
      0333337F337F33337F333301110BBBBB0333337F337F33337F333301110BBBBB
      0333337F337F33337F333301110BBBBB0333337F337F33337F333301110BBBBB
      0333337F337F33337F333301110BBBBB0333337F337FF3337F33330111B0BBBB
      0333337F337733337F333301110BBBBB0333337F337F33337F333301110BBBBB
      0333337F3F7F33337F333301E10BBBBB0333337F7F7F33337F333301EE0BBBBB
      0333337F777FFFFF7F3333000000000003333377777777777333}
    NumGlyphs = 2
  end
  object CBsocrnp: TComboBox
    Left = 519
    Top = 152
    Width = 98
    Height = 24
    Enabled = False
    ItemHeight = 16
    TabOrder = 6
    Items.Strings = (
      'г'
      'п'
      'с'
      'д'
      'рп'
      'х'
      'ст'
      'ж/д рзд'
      'пст'
      'сад')
  end
  object BBfindnp: TBitBtn
    Left = 254
    Top = 65
    Width = 171
    Height = 25
    Caption = 'Найти по коду'
    TabOrder = 7
    OnClick = BBfindnpClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000130B0000130B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      333333333333333333FF33333333333330003FF3FFFFF3333777003000003333
      300077F777773F333777E00BFBFB033333337773333F7F33333FE0BFBF000333
      330077F3337773F33377E0FBFBFBF033330077F3333FF7FFF377E0BFBF000000
      333377F3337777773F3FE0FBFBFBFBFB039977F33FFFFFFF7377E0BF00000000
      339977FF777777773377000BFB03333333337773FF733333333F333000333333
      3300333777333333337733333333333333003333333333333377333333333333
      333333333333333333FF33333333333330003333333333333777333333333333
      3000333333333333377733333333333333333333333333333333}
    NumGlyphs = 2
  end
  object CBnaspunkt: TComboBox
    Left = 161
    Top = 38
    Width = 384
    Height = 24
    Style = csDropDownList
    ItemHeight = 16
    TabOrder = 8
  end
  object Epattern1: TEdit
    Left = 161
    Top = 17
    Width = 104
    Height = 21
    CharCase = ecUpperCase
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MaxLength = 30
    ParentFont = False
    TabOrder = 9
    OnChange = Epattern1Change
  end
  object Ennaspunkt: TEdit
    Left = 192
    Top = 64
    Width = 60
    Height = 24
    TabOrder = 10
    OnKeyPress = EnnaspunktKeyPress
  end
  object Epost: TEdit
    Left = 120
    Top = 180
    Width = 385
    Height = 24
    Enabled = False
    TabOrder = 11
  end
  object Eindex: TEdit
    Left = 582
    Top = 180
    Width = 34
    Height = 24
    Enabled = False
    TabOrder = 12
    OnKeyPress = EnnaspunktKeyPress
  end
  object Eres: TEdit
    Left = 73
    Top = 209
    Width = 34
    Height = 24
    Enabled = False
    TabOrder = 13
    OnKeyPress = EnnaspunktKeyPress
  end
  object Eter: TEdit
    Left = 178
    Top = 210
    Width = 133
    Height = 24
    Enabled = False
    TabOrder = 14
    OnKeyPress = EnnaspunktKeyPress
  end
  object Eokato: TEdit
    Left = 382
    Top = 210
    Width = 99
    Height = 24
    Enabled = False
    TabOrder = 15
    OnKeyPress = EnnaspunktKeyPress
  end
  object ChBupdnp: TCheckBox
    Left = 19
    Top = 101
    Width = 97
    Height = 17
    Caption = 'Обновить'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 16
    OnClick = ChBupdnpClick
  end
  object Enewnazvnp: TEdit
    Left = 119
    Top = 98
    Width = 385
    Height = 24
    Enabled = False
    TabOrder = 17
  end
  object CBnewsocrnp: TComboBox
    Left = 519
    Top = 98
    Width = 98
    Height = 24
    Enabled = False
    ItemHeight = 16
    TabOrder = 18
    Items.Strings = (
      'г'
      'п'
      'с'
      'д'
      'рп'
      'х'
      'ст'
      'ж/д рзд'
      'пст'
      'сад')
  end
  object Epattern: TEdit
    Left = 123
    Top = 259
    Width = 104
    Height = 21
    CharCase = ecUpperCase
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MaxLength = 30
    ParentFont = False
    TabOrder = 19
    OnChange = EpatternChange
  end
  object CBulitsa: TComboBox
    Left = 123
    Top = 280
    Width = 384
    Height = 24
    Style = csDropDownList
    Enabled = False
    ItemHeight = 16
    TabOrder = 20
  end
  object Enulitsaid: TEdit
    Left = 154
    Top = 306
    Width = 119
    Height = 24
    Enabled = False
    TabOrder = 21
    OnKeyPress = EnnaspunktKeyPress
  end
  object BBfindul: TBitBtn
    Left = 278
    Top = 305
    Width = 171
    Height = 25
    Caption = 'Найти по коду'
    Enabled = False
    TabOrder = 22
    OnClick = BBfindulClick
    Glyph.Data = {
      76010000424D7601000000000000760000002800000020000000100000000100
      04000000000000010000130B0000130B00001000000000000000000000000000
      800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
      FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
      333333333333333333FF33333333333330003FF3FFFFF3333777003000003333
      300077F777773F333777E00BFBFB033333337773333F7F33333FE0BFBF000333
      330077F3337773F33377E0FBFBFBF033330077F3333FF7FFF377E0BFBF000000
      333377F3337777773F3FE0FBFBFBFBFB039977F33FFFFFFF7377E0BF00000000
      339977FF777777773377000BFB03333333337773FF733333333F333000333333
      3300333777333333337733333333333333003333333333333377333333333333
      333333333333333333FF33333333333330003333333333333777333333333333
      3000333333333333377733333333333333333333333333333333}
    NumGlyphs = 2
  end
  object RGactionul: TRadioGroup
    Left = 121
    Top = 333
    Width = 488
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 23
  end
  object RBnewul: TRadioButton
    Left = 136
    Top = 344
    Width = 145
    Height = 17
    Caption = 'Добавить новую'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 24
    OnClick = RBnewulClick
  end
  object RBupdul: TRadioButton
    Left = 294
    Top = 345
    Width = 311
    Height = 17
    Caption = 'Обновить название и/или сокращение'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 25
    OnClick = RBupdulClick
  end
  object BBdelch: TBitBtn
    Left = 15
    Top = 342
    Width = 102
    Height = 25
    Caption = 'Убрать выбор'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 26
    OnClick = BBdelchClick
  end
  object ChBulitsa: TCheckBox
    Left = 36
    Top = 281
    Width = 78
    Height = 17
    Caption = 'Улица'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clPurple
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 27
    OnClick = ChBulitsaClick
  end
  object Epos: TEdit
    Left = 596
    Top = 212
    Width = 49
    Height = 24
    Enabled = False
    TabOrder = 28
    Text = '0'
    OnKeyPress = EnnaspunktKeyPress
  end
end
