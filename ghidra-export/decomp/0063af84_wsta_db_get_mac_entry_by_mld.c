// func wsta_db_get_mac_entry_by_mld @ 0063af84 size=320

undefined4 wsta_db_get_mac_entry_by_mld(int param_1,void *param_2)

{
  void *__src;
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == (void *)0x0)) {
    uVar2 = 0xffffffff;
    if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[error]%s(): %d  -> peer mac val is null!\r\n","wsta_db_get_mac_entry_by_mld",
             0xf32);
    }
  }
  else {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    uVar2 = 0xffffffff;
    __src = (void *)FUN_00407fa0(DAT_007cc728,param_1);
    if (__src != (void *)0x0) {
      if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wsta>[debug]%s(): %d  -> mld hash mac:%02x:%02x:%02x:%02x:%02x:%02x \r\n",
               "wsta_db_get_mac_entry_by_mld",0xf39,(uint)*(byte *)((int)__src + 0xc),
               (uint)*(byte *)((int)__src + 0xd),(uint)*(byte *)((int)__src + 0xe),
               (uint)*(byte *)((int)__src + 0xf),(uint)*(byte *)((int)__src + 0x10),
               (uint)*(byte *)((int)__src + 0x11));
      }
      uVar2 = 0;
      memcpy(param_2,__src,0x38);
    }
    FUN_00407f30(DAT_007cc6bc);
  }
  return uVar2;
}

