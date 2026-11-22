// func uac_unicode_is_str_utf8 @ 00526544 size=168

bool uac_unicode_is_str_utf8(byte *param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    while( true ) {
      bVar1 = *param_1;
      if (bVar1 == 0) {
        return iVar2 == 0;
      }
      if (iVar2 == 0) break;
      if ((bVar1 & 0xc0) != 0x80) {
        return false;
      }
      iVar2 = iVar2 + -1;
LAB_005265b4:
      param_1 = param_1 + 1;
    }
    if ((char)bVar1 < '\0') {
      if ((byte)(bVar1 + 4) < 2) {
        iVar2 = 5;
      }
      else {
        iVar2 = 5;
        if (((bVar1 < 0xf8) && (iVar2 = 4, bVar1 < 0xf0)) && (iVar2 = 3, bVar1 < 0xe0)) {
          if (bVar1 < 0xc0) {
            return false;
          }
          iVar2 = 2;
        }
        iVar2 = iVar2 + -1;
      }
      goto LAB_005265b4;
    }
    param_1 = param_1 + 1;
  } while( true );
}

