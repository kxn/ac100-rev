// func _str2mac @ 004eb2a0 size=124

void _str2mac(byte *param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  
  iVar1 = 0;
  do {
    uVar3 = *param_1 - 0x31 & 0xff;
    cVar2 = '\0';
    if (uVar3 < 0x36) {
      cVar2 = (&DAT_006b79bc)[uVar3];
    }
    *param_2 = cVar2 * '\x10';
    uVar3 = param_1[1] - 0x31 & 0xff;
    cVar4 = '\0';
    if (uVar3 < 0x36) {
      cVar4 = (&DAT_006b79bc)[uVar3];
    }
    iVar1 = iVar1 + 1;
    *param_2 = cVar4 + cVar2 * '\x10';
    param_1 = param_1 + 3;
    param_2 = param_2 + 1;
  } while (iVar1 != 6);
  return;
}

