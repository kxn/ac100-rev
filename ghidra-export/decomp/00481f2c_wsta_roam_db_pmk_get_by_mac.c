// func wsta_roam_db_pmk_get_by_mac @ 00481f2c size=184

undefined4 wsta_roam_db_pmk_get_by_mac(int param_1,void *param_2)

{
  void *__src;
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    uVar1 = 0xffffffff;
    if (wsta_roam_warning_switch != '\0') {
      printf("[WSTA_ROAM_WARNING]%s()/%d entry is null!\n","wsta_roam_db_pmk_get_by_mac",0x2cf);
    }
  }
  else {
    FUN_004082d0(l_wsta_roam_data,0xffffffff);
    uVar1 = 0xffffffff;
    __src = (void *)FUN_00407fa0(DAT_0076754c,param_1);
    if (__src != (void *)0x0) {
      uVar1 = 0;
      memcpy(param_2,__src,0x4c);
    }
    FUN_00407f30(l_wsta_roam_data);
  }
  return uVar1;
}

