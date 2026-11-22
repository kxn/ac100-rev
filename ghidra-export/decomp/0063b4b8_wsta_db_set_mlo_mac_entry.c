// func wsta_db_set_mlo_mac_entry @ 0063b4b8 size=896

undefined4
wsta_db_set_mlo_mac_entry
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  int iVar1;
  void *__s;
  byte *__s_00;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 *__src;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 local_70 [3];
  undefined1 auStack_64 [60];
  
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memset(auStack_64,0,0x38);
  iVar1 = wsta_db_get_mac_entry_by_mld(&local_resc,auStack_64);
  if (iVar1 == 0) {
    wsta_db_free_mlo_mac_entry(auStack_64);
  }
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(0x38), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> set mlo entry hash\r\n","wsta_db_set_mlo_mac_entry",0xedd);
  }
  __s = (void *)FUN_00408450(0x38,0xede);
  memset(__s,0,0x38);
  memcpy(__s,&local_res0,0x38);
  if ((g_wsta_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("<wsta>[debug]%s(): %d  -> mac mld:%02x:%02x:%02x:%02x:%02x:%02x \r\n",
           "wsta_db_set_mlo_mac_entry",0xee1,(uint)*(byte *)((int)__s + 0xc),
           (uint)*(byte *)((int)__s + 0xd),(uint)*(byte *)((int)__s + 0xe),
           (uint)*(byte *)((int)__s + 0xf),(uint)*(byte *)((int)__s + 0x10),
           (uint)*(byte *)((int)__s + 0x11));
  }
  puVar5 = local_70;
  __src = &stack0x00000016;
  puVar4 = puVar5;
  for (iVar1 = 0; iVar1 < (int)(uint)param_5._2_1_; iVar1 = iVar1 + 1) {
    __s_00 = (byte *)FUN_00408450(0xc,0xee5);
    *puVar4 = __s_00;
    memset(__s_00,0,0xc);
    memcpy(__s_00,__src,6);
    memcpy(__s_00 + 6,&local_resc,6);
    if ((g_wsta_debug != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("<wsta>[debug]%s(): %d  -> mac peer:%02x:%02x:%02x:%02x:%02x:%02x \r\n",
             "wsta_db_set_mlo_mac_entry",0xee9,(uint)*__s_00,(uint)__s_00[1],(uint)__s_00[2],
             (uint)__s_00[3],(uint)__s_00[4],(uint)__s_00[5]);
    }
    puVar4 = puVar4 + 1;
    __src = __src + 0xc;
  }
  FUN_004082d0(DAT_007cc6bc,0xffffffff);
  iVar1 = FUN_00408380(DAT_007cc728,__s);
  if (iVar1 == 0) {
    puVar4 = puVar5;
    for (iVar1 = 0; iVar1 < (int)(uint)param_5._2_1_; iVar1 = iVar1 + 1) {
      uVar3 = *puVar4;
      puVar4 = puVar4 + 1;
      iVar2 = FUN_00408380(DAT_007cc72c,uVar3);
      if (iVar2 != 0) {
        if ((g_wsta_error == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) goto LAB_0063b6f8;
        __format = "<wsta>[error]%s(): %d  -> sta peer mac hash add failed!\r\n";
        uVar3 = 0xef7;
        goto LAB_0063b7f8;
      }
    }
    FUN_00407f30(DAT_007cc6bc);
    uVar3 = 0;
  }
  else {
    if ((g_wsta_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      __format = "<wsta>[error]%s(): %d  -> sta mld mac hash add failed!\r\n";
      uVar3 = 0xeef;
LAB_0063b7f8:
      printf(__format,"wsta_db_set_mlo_mac_entry",uVar3);
    }
LAB_0063b6f8:
    FUN_00407df0(__s);
    for (iVar1 = 0; iVar1 < (int)(uint)param_5._2_1_; iVar1 = iVar1 + 1) {
      uVar3 = *puVar5;
      puVar5 = puVar5 + 1;
      FUN_00407df0(uVar3);
    }
    FUN_00407f30(DAT_007cc6bc);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

