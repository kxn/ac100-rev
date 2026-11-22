// func _wsta_roam_pkt_chnl_scan_report @ 00489024 size=860

undefined4 _wsta_roam_pkt_chnl_scan_report(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  void *__s;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  char *__s_00;
  int iVar4;
  undefined1 auStack_2e8 [72];
  byte local_2a0;
  byte local_29f;
  byte local_29e;
  byte local_29d;
  byte local_29c;
  byte local_29b;
  
  memset(auStack_2e8,0,0x2d8);
  iVar1 = get_acs_process_state();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = apmngr_db_entry_get_by_mac(param_3,auStack_2e8);
  if (iVar1 == 0) {
    __s_00 = (char *)FUN_00408450(0x1c,0x736);
    if (__s_00 == (char *)0x0) {
      iVar1 = iRam00000018;
      if (wsta_roam_warning_switch == '\0') goto LAB_004890a0;
      __format = "[WSTA_ROAM_WARNING]%s()/%d mallco fail.\n";
      uVar3 = 0x738;
    }
    else {
      memset(__s_00,0,0x1c);
      snprintf(__s_00,0x12,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)local_2a0,(uint)local_29f,
               (uint)local_29e,(uint)local_29d,(uint)local_29c,(uint)local_29b);
      memcpy(__s_00 + 0x12,&local_2a0,6);
      __s = (void *)FUN_00408450(8,0x740);
      *(void **)(__s_00 + 0x18) = __s;
      if (__s == (void *)0x0) {
        if (wsta_roam_warning_switch == '\0') {
          iVar1 = *(int *)(__s_00 + 0x18);
          goto LAB_004890a0;
        }
        __format = "[WSTA_ROAM_WARNING]%s()/%d mallco fail.\n";
        uVar3 = 0x742;
      }
      else {
        memset(__s,0,8);
        **(byte **)(__s_00 + 0x18) = *param_1;
        if (*param_1 == 0) {
LAB_004892f0:
          uVar3 = FUN_00408290(begin_acs_container,__s_00);
          return uVar3;
        }
        iVar4 = *(int *)(__s_00 + 0x18);
        iVar1 = FUN_00408450((uint)*param_1 << 3,0x749);
        *(int *)(iVar4 + 4) = iVar1;
        if (iVar1 != 0) {
          memset(*(void **)(*(int *)(__s_00 + 0x18) + 4),0,(uint)*param_1 << 3);
          for (iVar1 = 0; iVar4 = iVar1 * 9, iVar1 < (int)(uint)*param_1; iVar1 = iVar1 + 1) {
            iVar2 = iVar1 * 8;
            *(undefined1 *)(*(int *)(*(int *)(__s_00 + 0x18) + 4) + iVar2) =
                 *(undefined1 *)(*(int *)(param_1 + 4) + iVar4);
            *(undefined1 *)(*(int *)(*(int *)(__s_00 + 0x18) + 4) + iVar2 + 1) =
                 *(undefined1 *)(*(int *)(param_1 + 4) + iVar4 + 1);
            *(undefined1 *)(*(int *)(*(int *)(__s_00 + 0x18) + 4) + iVar2 + 2) =
                 *(undefined1 *)(*(int *)(param_1 + 4) + iVar4 + 2);
            *(undefined1 *)(*(int *)(*(int *)(__s_00 + 0x18) + 4) + iVar2 + 3) =
                 *(undefined1 *)(*(int *)(param_1 + 4) + iVar4 + 3);
            *(undefined1 *)(*(int *)(*(int *)(__s_00 + 0x18) + 4) + iVar2 + 4) =
                 *(undefined1 *)(*(int *)(param_1 + 4) + iVar4 + 4);
            *(undefined1 *)(*(int *)(*(int *)(__s_00 + 0x18) + 4) + iVar2 + 5) =
                 *(undefined1 *)(*(int *)(param_1 + 4) + iVar4 + 5);
            *(undefined1 *)(*(int *)(*(int *)(__s_00 + 0x18) + 4) + iVar2 + 6) =
                 *(undefined1 *)(*(int *)(param_1 + 4) + iVar4 + 6);
            *(undefined1 *)(*(int *)(*(int *)(__s_00 + 0x18) + 4) + iVar2 + 7) =
                 *(undefined1 *)(*(int *)(param_1 + 4) + iVar4 + 7);
          }
          goto LAB_004892f0;
        }
        if (wsta_roam_warning_switch == '\0') {
          iVar1 = *(int *)(__s_00 + 0x18);
          goto LAB_004890a0;
        }
        __format = "[WSTA_ROAM_WARNING]%s()/%d mallco fail.\n";
        uVar3 = 0x74b;
      }
    }
  }
  else {
    __s_00 = (char *)0x0;
    iVar1 = iRam00000018;
    if (wsta_roam_warning_switch == '\0') goto LAB_004890a0;
    __format = "[WSTA_ROAM_WARNING]%s()/%d apmngr_db_entry_get_by_mac() fail.\n";
    uVar3 = 0x733;
  }
  printf(__format,"_wsta_roam_pkt_chnl_scan_report",uVar3);
  iVar1 = *(int *)(__s_00 + 0x18);
LAB_004890a0:
  if (*(int *)(iVar1 + 4) == 0) {
    iVar1 = *(int *)(__s_00 + 0x18);
  }
  else {
    FUN_00407df0();
    *(undefined4 *)(*(int *)(__s_00 + 0x18) + 4) = 0;
    iVar1 = *(int *)(__s_00 + 0x18);
  }
  if (iVar1 != 0) {
    FUN_00407df0();
    __s_00[0x18] = '\0';
    __s_00[0x19] = '\0';
    __s_00[0x1a] = '\0';
    __s_00[0x1b] = '\0';
  }
  if (__s_00 != (char *)0x0) {
    FUN_00407df0(__s_00);
  }
  return 0;
}

