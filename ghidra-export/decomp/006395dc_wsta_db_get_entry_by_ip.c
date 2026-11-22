// func wsta_db_get_entry_by_ip @ 006395dc size=264

undefined4
wsta_db_get_entry_by_ip
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,void *param_6)

{
  int iVar1;
  void *__src;
  undefined4 uVar2;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if (param_6 == (void *)0x0) {
    if (g_wsta_warning == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("<wsta>[warning]%s(): %d  -> entry is null!\r\n","wsta_db_get_entry_by_ip",0xbf5);
    return 0xffffffff;
  }
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  if (local_res0._0_1_ == '\x01') {
    __src = (void *)FUN_00407fa0(DAT_007cc6d0,&local_res0);
  }
  else {
    uVar2 = 0xffffffff;
    if (local_res0._0_1_ != '\x02') goto LAB_00639640;
    __src = (void *)FUN_00407fa0(DAT_007cc6d4,&local_res0);
  }
  uVar2 = 0xffffffff;
  if (__src != (void *)0x0) {
    memcpy(param_6,__src,0x80);
    uVar2 = 0;
  }
LAB_00639640:
  FUN_00407f30(DAT_007cc6bc);
  return uVar2;
}

