// func wsta_db_update_nego_rate @ 0063a454 size=236

undefined4 wsta_db_update_nego_rate(char *param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((((*param_1 == '\0') && (param_1[1] == '\0')) && (param_1[2] == '\0')) &&
      ((param_1[3] == '\0' && (param_1[4] == '\0')))) && (param_1[5] == '\0')) {
    uVar2 = 0xffffffff;
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(param_1,0xffffffff), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> invalid mac addr!\r\n","wsta_db_update_nego_rate",0xec2);
    }
  }
  else {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    iVar1 = FUN_00407fa0(DAT_007cc6cc,param_1);
    if (iVar1 != 0) {
      *(undefined2 *)(iVar1 + 0x7c) = param_2;
    }
    uVar2 = 0;
    FUN_00407f30(DAT_007cc6bc);
  }
  return uVar2;
}

