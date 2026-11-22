// func wsta_roam_db_pmk_free @ 00481da4 size=1

undefined4 wsta_roam_db_pmk_free(int param_1,code *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *__src;
  int iVar2;
  undefined1 auStack_68 [80];
  
  if ((param_1 < 0) || (max_roam_sta <= param_1)) {
    uVar1 = 0xffffffff;
    if (wsta_roam_warning_switch != '\0') {
      printf("[WSTA_ROAM_WARNING]%s()/%d invalid wsta_id[%d]!\n","wsta_roam_db_pmk_free",0x28f,
             param_1);
    }
  }
  else {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    __src = (int *)(DAT_00767548 + param_1 * 0x4c);
    if (*__src == 0) {
      iVar2 = -1;
      if (wsta_roam_warning_switch != '\0') {
        printf("[WSTA_ROAM_WARNING]%s()/%d wsta_id[%d] is not used!\n","wsta_roam_db_pmk_free",0x296
               ,param_1);
      }
    }
    else {
      if (param_2 != (code *)0x0) {
        memcpy(auStack_68,__src,0x4c);
      }
      iVar2 = 0;
      _wsta_roam_free_pmk(__src);
    }
    FUN_00407f30(l_wsta_roam_data);
    if (iVar2 == 0) {
      uVar1 = 0;
      if (param_2 != (code *)0x0) {
        (*param_2)(auStack_68,param_3);
      }
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  return uVar1;
}

