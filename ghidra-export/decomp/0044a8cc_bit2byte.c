// func bit2byte @ 0044a8cc size=204

void bit2byte(byte *param_1,undefined1 *param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar2 = 0;
  do {
    puVar3 = param_2 + iVar2;
    iVar2 = iVar2 + 1;
    *puVar3 = 0;
  } while (iVar2 != 0x40);
  iVar2 = 0;
  do {
    if ((char)*param_1 < '\0') {
      *param_2 = 1;
      bVar1 = *param_1;
    }
    else {
      bVar1 = *param_1;
    }
    if ((bVar1 & 0x40) != 0) {
      param_2[1] = 1;
    }
    if ((*param_1 & 0x20) != 0) {
      param_2[2] = 1;
    }
    if ((*param_1 & 0x10) != 0) {
      param_2[3] = 1;
    }
    if ((*param_1 & 8) != 0) {
      param_2[4] = 1;
    }
    if ((*param_1 & 4) != 0) {
      param_2[5] = 1;
    }
    if ((*param_1 & 2) != 0) {
      param_2[6] = 1;
    }
    if ((*param_1 & 1) != 0) {
      param_2[7] = 1;
    }
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 8;
  } while (iVar2 != 8);
  return;
}

