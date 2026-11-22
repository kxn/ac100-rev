// func mac_auth_mac_parse @ 00452738 size=212

undefined4 mac_auth_mac_parse(byte *param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  undefined4 uVar5;
  
  if ((param_1 == (byte *)0x0) || (param_2 == (char *)0x0)) {
    uVar5 = 0xffffffff;
    if (macauth_err_switch != 0) {
      printf("[MACAUTH_ERROR]%s()/%d Invalid params.\n","mac_auth_mac_parse",0xd3);
    }
  }
  else {
    iVar1 = 0;
    do {
      uVar3 = *param_1 - 0x31 & 0xff;
      cVar2 = '\0';
      if (uVar3 < 0x36) {
        cVar2 = (&DAT_00686e54)[uVar3];
      }
      *param_2 = cVar2 * '\x10';
      uVar3 = param_1[1] - 0x31 & 0xff;
      cVar4 = '\0';
      if (uVar3 < 0x36) {
        cVar4 = (&DAT_00686e54)[uVar3];
      }
      iVar1 = iVar1 + 1;
      *param_2 = cVar4 + cVar2 * '\x10';
      param_1 = param_1 + 3;
      param_2 = param_2 + 1;
    } while (iVar1 != 6);
    uVar5 = 0;
  }
  return uVar5;
}

