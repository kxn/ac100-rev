// func wsta_db_get_mac_entry_by_peer @ 0063a540 size=576

undefined4 wsta_db_get_mac_entry_by_peer(byte *param_1,void *param_2)

{
  void *__src;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_1 == (byte *)0x0) || (param_2 == (void *)0x0)) {
    uVar3 = 0xffffffff;
    if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[error]%s(): %d  -> peer mac val is null!\r\n","wsta_db_get_mac_entry_by_peer",
             0xf13);
    }
  }
  else {
    FUN_004082d0(DAT_007cc6bc,0xffffffff);
    iVar1 = FUN_00407fa0(DAT_007cc72c,param_1);
    if (iVar1 == 0) {
      if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wsta>[debug]%s(): %d  -> sta peer mac[%02x:%02x:%02x:%02x:%02x:%02x] hash get failed!\r\n"
               ,"wsta_db_get_mac_entry_by_peer",0xf1a,(uint)*param_1,(uint)param_1[1],
               (uint)param_1[2],(uint)param_1[3],(uint)param_1[4],(uint)param_1[5]);
      }
      uVar3 = 0xffffffff;
      FUN_00407f30(DAT_007cc6bc);
    }
    else {
      if ((g_wsta_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("<wsta>[debug]%s(): %d  -> peer hash mld mac:%02x:%02x:%02x:%02x:%02x:%02x \r\n",
               "wsta_db_get_mac_entry_by_peer",0xf1e,(uint)*(byte *)(iVar1 + 6),
               (uint)*(byte *)(iVar1 + 7),(uint)*(byte *)(iVar1 + 8),(uint)*(byte *)(iVar1 + 9),
               (uint)*(byte *)(iVar1 + 10),(uint)*(byte *)(iVar1 + 0xb));
      }
      uVar3 = 0xffffffff;
      __src = (void *)FUN_00407fa0(DAT_007cc728,iVar1 + 6);
      if (__src != (void *)0x0) {
        if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("<wsta>[debug]%s(): %d  -> hash mac:%02x:%02x:%02x:%02x:%02x:%02x \r\n",
                 "wsta_db_get_mac_entry_by_peer",0xf22,(uint)*(byte *)((int)__src + 0xc),
                 (uint)*(byte *)((int)__src + 0xd),(uint)*(byte *)((int)__src + 0xe),
                 (uint)*(byte *)((int)__src + 0xf),(uint)*(byte *)((int)__src + 0x10),
                 (uint)*(byte *)((int)__src + 0x11));
        }
        uVar3 = 0;
        memcpy(param_2,__src,0x38);
      }
      FUN_00407f30(DAT_007cc6bc);
    }
  }
  return uVar3;
}

