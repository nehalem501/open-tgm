#!/usr/bin/env python3

class GlyphEntry:
    def __init__(self, name, key):
        self.name = str(name)
        self.key = str(key)

ALL_GLYPHS = [
    GlyphEntry("NUL", "NUL"),
    GlyphEntry("SOH", "SOH"),
    GlyphEntry("STX", "STX"),
    GlyphEntry("ETX", "ETX"),
    GlyphEntry("EOT", "EOT"),
    GlyphEntry("ENQ", "ENQ"),
    GlyphEntry("ACK", "ACK"),
    GlyphEntry("BEL", "BEL"),

    GlyphEntry(" BS", "BS"),
    GlyphEntry(" HT", "HT"),
    GlyphEntry(" LF", "LF"),
    GlyphEntry(" VT", "VT"),
    GlyphEntry(" FF", "FF"),
    GlyphEntry(" CR", "CR"),
    GlyphEntry(" SO", "SO"),
    GlyphEntry(" SI", "SI"),

    GlyphEntry("DLE", "DLE"),
    GlyphEntry("DC1", "DC1"),
    GlyphEntry("DC2", "DC2"),
    GlyphEntry("DC3", "DC3"),
    GlyphEntry("DC4", "DC4"),
    GlyphEntry("NAK", "NAK"),
    GlyphEntry("SYN", "SYN"),
    GlyphEntry("ETB", "ETB"),

    GlyphEntry("CAN", "CAN"),
    GlyphEntry(" EM", "EM"),
    GlyphEntry("SUB", "SUB"),
    GlyphEntry("ESC", "ESC"),
    GlyphEntry(" FS", "FS"),
    GlyphEntry(" GS", "GS"),
    GlyphEntry(" RS", "RS"),
    GlyphEntry(" US", "US"),

    GlyphEntry("' '", "' '"),
    GlyphEntry("  !", "'!'"),
    GlyphEntry("  \"", "'\"'"),
    GlyphEntry("  #", "'#'"),
    GlyphEntry("  $", "'$'"),
    GlyphEntry("  %", "'%'"),
    GlyphEntry("  &", "'&'"),
    GlyphEntry("  '", "'''"),

    GlyphEntry("  (", "'('"),
    GlyphEntry("  )", "')'"),
    GlyphEntry("  *", "'*'"),
    GlyphEntry("  +", "'+'"),
    GlyphEntry("  ,", "','"),
    GlyphEntry("  -", "'-'"),
    GlyphEntry("  .", "'.'"),
    GlyphEntry("  /", "'/'"),

    GlyphEntry("  0", "'0'"),
    GlyphEntry("  1", "'1'"),
    GlyphEntry("  2", "'2'"),
    GlyphEntry("  3", "'3'"),
    GlyphEntry("  4", "'4'"),
    GlyphEntry("  5", "'5'"),
    GlyphEntry("  6", "'6'"),
    GlyphEntry("  7", "'7'"),

    GlyphEntry("  8", "'8'"),
    GlyphEntry("  9", "'9'"),
    GlyphEntry("  :", "':'"),
    GlyphEntry("  ;", "';'"),
    GlyphEntry("  <", "'<'"),
    GlyphEntry("  =", "'='"),
    GlyphEntry("  >", "'>'"),
    GlyphEntry("  ?", "'?'"),

    GlyphEntry("  @", "'@'"),
    GlyphEntry("  A", "'A'"),
    GlyphEntry("  B", "'B'"),
    GlyphEntry("  C", "'C'"),
    GlyphEntry("  D", "'D'"),
    GlyphEntry("  E", "'E'"),
    GlyphEntry("  F", "'F'"),
    GlyphEntry("  G", "'G'"),

    GlyphEntry("  H", "'H'"),
    GlyphEntry("  I", "'I'"),
    GlyphEntry("  J", "'J'"),
    GlyphEntry("  K", "'K'"),
    GlyphEntry("  L", "'L'"),
    GlyphEntry("  M", "'M'"),
    GlyphEntry("  N", "'N'"),
    GlyphEntry("  O", "'O'"),

    GlyphEntry("  P", "'P'"),
    GlyphEntry("  Q", "'Q'"),
    GlyphEntry("  R", "'R'"),
    GlyphEntry("  S", "'S'"),
    GlyphEntry("  T", "'T'"),
    GlyphEntry("  U", "'U'"),
    GlyphEntry("  V", "'V'"),
    GlyphEntry("  W", "'W'"),

    GlyphEntry("  X", "'X'"),
    GlyphEntry("  Y", "'Y'"),
    GlyphEntry("  Z", "'Z'"),
    GlyphEntry("  [", "'['"),
    GlyphEntry("  \\", "'\\'"),
    GlyphEntry("  ]", "']'"),
    GlyphEntry("  ^", "'^'"),
    GlyphEntry("  _", "'_'"),

    GlyphEntry("  `", "'`'"),
    GlyphEntry("  a", "'a'"),
    GlyphEntry("  b", "'b'"),
    GlyphEntry("  c", "'c'"),
    GlyphEntry("  d", "'d'"),
    GlyphEntry("  e", "'e'"),
    GlyphEntry("  f", "'f'"),
    GlyphEntry("  g", "'g'"),

    GlyphEntry("  h", "'h'"),
    GlyphEntry("  i", "'i'"),
    GlyphEntry("  j", "'j'"),
    GlyphEntry("  k", "'k'"),
    GlyphEntry("  l", "'l'"),
    GlyphEntry("  m", "'m'"),
    GlyphEntry("  n", "'n'"),
    GlyphEntry("  o", "'o'"),

    GlyphEntry("  p", "'p'"),
    GlyphEntry("  q", "'q'"),
    GlyphEntry("  r", "'r'"),
    GlyphEntry("  s", "'s'"),
    GlyphEntry("  t", "'t'"),
    GlyphEntry("  u", "'u'"),
    GlyphEntry("  v", "'v'"),
    GlyphEntry("  w", "'w'"),

    GlyphEntry("  x", "'x'"),
    GlyphEntry("  y", "'y'"),
    GlyphEntry("  z", "'z'"),
    GlyphEntry("  {", "'{'"),
    GlyphEntry("  |", "'|'"),
    GlyphEntry(" )", "'}'"),
    GlyphEntry("  ~", "'~'"),
    GlyphEntry("DEL", "DEL"),

    GlyphEntry("PAD", "PAD"),
    GlyphEntry("HOP", "HOP"),
    GlyphEntry("BPH", "BPH"),
    GlyphEntry("NBH", "NBH"),
    GlyphEntry("IND", "IND"),
    GlyphEntry("NEL", "NEL"),
    GlyphEntry("SSA", "SSA"),
    GlyphEntry("ESA", "ESA"),

    GlyphEntry("HTS", "HTS"),
    GlyphEntry("HTJ", "HTJ"),
    GlyphEntry("LTS", "LTS"),
    GlyphEntry("PLD", "PLD"),
    GlyphEntry("PLU", "PLU"),
    GlyphEntry(" RI", "RI"),
    GlyphEntry("SS2", "SS2"),
    GlyphEntry("SS3", "SS3"),

    GlyphEntry("DCS", "DCS"),
    GlyphEntry("PU1", "PU1"),
    GlyphEntry("PU2", "PU2"),
    GlyphEntry("STS", "STS"),
    GlyphEntry("CCH", "CCH"),
    GlyphEntry(" MW", "MW"),
    GlyphEntry("SPA", "SPA"),
    GlyphEntry("EPA", "EPA"),

    GlyphEntry("SOS", "SOS"),
    GlyphEntry("SGI", "SGI"),
    GlyphEntry("SCI", "SCI"),
    GlyphEntry("CSI", "CSI"),
    GlyphEntry(" ST", "ST"),
    GlyphEntry("OSC", "OSC"),
    GlyphEntry(" PM", "PM"),
    GlyphEntry("APC", "APC"),

    GlyphEntry("NSP", "NSP"),
    GlyphEntry("  ¡", "'¡'"),
    GlyphEntry("  ¢", "'¢'"),
    GlyphEntry("  £", "'£'"),
    GlyphEntry("  ¤", "'¤'"),
    GlyphEntry("  ¥", "'¥'"),
    GlyphEntry("  ¦", "'¦'"),
    GlyphEntry("  §", "'§'"),

    GlyphEntry("  ¨", "'¨'"),
    GlyphEntry("  ©", "'©'"),
    GlyphEntry("  ª", "'ª'"),
    GlyphEntry("  «", "'«'"),
    GlyphEntry("  ¬", "'¬'"),
    GlyphEntry("SHY", "SHY"),
    GlyphEntry("  ®", "'®'"),
    GlyphEntry("  ¯", "'¯'"),

    GlyphEntry("  °", "'°'"),
    GlyphEntry("  ±", "'±'"),
    GlyphEntry("  ²", "'²'"),
    GlyphEntry("  ³", "'³'"),
    GlyphEntry("  ´", "'´'"),
    GlyphEntry("  µ", "'µ'"),
    GlyphEntry("  ¶", "'¶'"),
    GlyphEntry("  ·", "'·'"),

    GlyphEntry("  ¸", "'¸'"),
    GlyphEntry("  ¹", "'¹'"),
    GlyphEntry("  º", "'º'"),
    GlyphEntry("  »", "'»'"),
    GlyphEntry("  ¼", "'¼'"),
    GlyphEntry("  ½", "'½'"),
    GlyphEntry("  ¾", "'¾'"),
    GlyphEntry("  ¿", "'¿'"),

    GlyphEntry("  À", "'À'"),
    GlyphEntry("  Á", "'Á'"),
    GlyphEntry("  Â", "'Â'"),
    GlyphEntry("  Ã", "'Ã'"),
    GlyphEntry("  Ä", "'Ä'"),
    GlyphEntry("  Å", "'Å'"),
    GlyphEntry("  Æ", "'Æ'"),
    GlyphEntry("  Ç", "'Ç'"),

    GlyphEntry("  È", "'È'"),
    GlyphEntry("  É", "'É'"),
    GlyphEntry("  Ê", "'Ê'"),
    GlyphEntry("  Ë", "'Ë'"),
    GlyphEntry("  Ì", "'Ì'"),
    GlyphEntry("  Í", "'Í'"),
    GlyphEntry("  Î", "'Î'"),
    GlyphEntry("  Ï", "'Ï'"),

    GlyphEntry("  Ð", "'Ð'"),
    GlyphEntry("  Ñ", "'Ñ'"),
    GlyphEntry("  Ò", "'Ò'"),
    GlyphEntry("  Ó", "'Ó'"),
    GlyphEntry("  Ô", "'Ô'"),
    GlyphEntry("  Õ", "'Õ'"),
    GlyphEntry("  Ö", "'Ö'"),
    GlyphEntry("  ×", "'×'"),

    GlyphEntry("  Ø", "'Ø'"),
    GlyphEntry("  Ù", "'Ù'"),
    GlyphEntry("  Ú", "'Ú'"),
    GlyphEntry("  Û", "'Û'"),
    GlyphEntry("  Ü", "'Ü'"),
    GlyphEntry("  Ý", "'Ý'"),
    GlyphEntry("  Þ", "'Þ'"),
    GlyphEntry("  ß", "'ß'"),

    GlyphEntry("  à", "'à'"),
    GlyphEntry("  á", "'á'"),
    GlyphEntry("  â", "'â'"),
    GlyphEntry("  ã", "'ã'"),
    GlyphEntry("  ä", "'ä'"),
    GlyphEntry("  å", "'å'"),
    GlyphEntry("  æ", "'æ'"),
    GlyphEntry("  ç", "'ç'"),

    GlyphEntry("  è", "'è'"),
    GlyphEntry("  é", "'é'"),
    GlyphEntry("  ê", "'ê'"),
    GlyphEntry("  ë", "'ë'"),
    GlyphEntry("  ì", "'ì'"),
    GlyphEntry("  í", "'í'"),
    GlyphEntry("  î", "'î'"),
    GlyphEntry("  ï", "'ï'"),

    GlyphEntry("  ð", "'ð'"),
    GlyphEntry("  ñ", "'ñ'"),
    GlyphEntry("  ò", "'ò'"),
    GlyphEntry("  ó", "'ó'"),
    GlyphEntry("  ô", "'ô'"),
    GlyphEntry("  õ", "'õ'"),
    GlyphEntry("  ö", "'ö'"),
    GlyphEntry("  ÷", "'÷'"),

    GlyphEntry("  ø", "'ø'"),
    GlyphEntry("  ù", "'ù'"),
    GlyphEntry("  ú", "'ú'"),
    GlyphEntry("  û", "'û'"),
    GlyphEntry("  ü", "'ü'"),
    GlyphEntry("  ý", "'ý'"),
    GlyphEntry("  þ", "'þ'"),
    GlyphEntry("  ÿ", "'ÿ'")
]
