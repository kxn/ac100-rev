// func wsta_db_get_entry_by_mac @ 00639510 size=204

undefined4 wsta_db_get_entry_by_mac(undefined4 param_1,void *param_2)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> entry is null!\r\n","wsta_db_get_entry_by_mac",0xbe0);
    }
  }
  else {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    uVar2 = 0xffffffff;
    __src = (void *)FUN_00407fa0(DAT_007cc6cc,param_1);
    if (__src != (void *)0x0) {
      uVar2 = 0;
      memcpy(param_2,__src,0x80);
    }
    FUN_00407f30(DAT_007cc6bc);
  }
  return uVar2;
}

