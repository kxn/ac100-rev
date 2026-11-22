// func rrc_rate_set_set @ 0055e6d4 size=180

int rrc_rate_set_set(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = -1;
  if ((((param_1 != (undefined4 *)0x0) && (param_2 != (undefined4 *)0x0)) && (param_3 < 0x10)) &&
     (-1 < param_3)) {
    iVar1 = 0;
    if (param_3 != 0) {
      puVar2 = param_2 + 1;
      do {
        if (puVar2[-1] == 0) {
          return -1;
        }
        iVar1 = iVar1 + 1;
        puVar2 = puVar2 + 1;
      } while (iVar1 != param_3);
    }
    memset(param_1,0,0x40);
    iVar1 = 0;
    if (param_3 != 0) {
      do {
        uVar3 = *param_2;
        iVar1 = iVar1 + 1;
        param_2 = param_2 + 1;
        *param_1 = uVar3;
        param_1 = param_1 + 1;
      } while (iVar1 != param_3);
      iVar1 = 0;
    }
  }
  return iVar1;
}

