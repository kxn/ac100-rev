// func stats_db_fail_sta_add @ 006712d4 size=660

undefined4 stats_db_fail_sta_add(void *param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  void *__dest;
  char *__format;
  undefined4 uVar6;
  undefined4 local_3f0;
  int local_3ec;
  undefined1 auStack_3e8 [8];
  byte local_3e0;
  undefined1 auStack_3df [247];
  undefined1 auStack_2e8 [72];
  undefined1 auStack_2a0 [656];
  
  memset(auStack_3e8,0,0x100);
  memset(auStack_2e8,0,0x2d8);
  local_3f0 = 0;
  local_3ec = -1;
  if (param_1 == (void *)0x0) {
    if (stats_err_switch != '\0') {
      __format = "[STATISTICS_ERROR]%s()/%d entry is null!\n";
      uVar6 = 0x11c9;
      goto LAB_00671428;
    }
  }
  else {
    uVar2 = *(ushort *)((int)param_1 + 0xc);
    iVar4 = apmngr_db_get_ap_max();
    if (((((int)(uint)uVar2 < iVar4) && (bVar1 = *(byte *)((int)param_1 + 0xe), bVar1 != 0)) &&
        (uVar5 = rdmngr_profile_get_max_rd_per_ap(), bVar1 <= uVar5)) &&
       ((bVar1 = *(byte *)((int)param_1 + 0xf), bVar1 != 0 &&
        (uVar5 = rdmngr_profile_get_max_wlan_per_rd(), bVar1 <= uVar5)))) {
      iVar4 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)param_1 + 0xc),auStack_2e8);
      if (iVar4 == 0) {
        __dest = (void *)FUN_00408450(0x34,0x11d8);
        if (__dest == (void *)0x0) {
          if (stats_err_switch != '\0') {
            __format = "[STATISTICS_ERROR]%s()/%d memory is overflow!\n";
            uVar6 = 0x11db;
            goto LAB_00671428;
          }
        }
        else {
          memcpy(__dest,param_1,0x34);
          memset(auStack_3e8,0,0x100);
          *(undefined1 *)((int)__dest + 0x1c) = 0;
          iVar4 = stats_db_ssid_get(*(undefined2 *)((int)param_1 + 0xc),
                                    *(undefined1 *)((int)param_1 + 0xe),
                                    *(undefined1 *)((int)param_1 + 0xf),auStack_3e8);
          if (iVar4 == 0) {
            if ((local_3e0 & 3) == 3) {
              memcpy((void *)((int)__dest + 0x1d),auStack_3df,6);
              *(undefined1 *)((int)__dest + 0x1c) = 1;
            }
            uVar3 = *(undefined2 *)((int)param_1 + 0xc);
          }
          else {
            uVar3 = *(undefined2 *)((int)param_1 + 0xc);
          }
          uVar6 = rdmngr_db_generate_rd_id(uVar3,*(undefined1 *)((int)param_1 + 0xe));
          iVar4 = rdmngr_db_get_freq_band_idx(uVar6,&local_3ec,&local_3f0);
          if ((iVar4 == 0) && (local_3ec != -1)) {
            *(int *)((int)__dest + 0x24) = local_3ec;
            *(undefined4 *)((int)__dest + 0x28) = local_3f0;
          }
          *(undefined4 *)((int)__dest + 0x2c) = stats_consumer_bit_mask;
          memcpy((void *)((int)__dest + 6),auStack_2a0,6);
          iVar4 = FUN_00408540(DAT_007cc8f8,__dest);
          if (iVar4 == 0) {
            return 0;
          }
          FUN_00407df0(__dest);
        }
      }
      else if (stats_err_switch != '\0') {
        __format = "[STATISTICS_ERROR]%s()/%d apmngr_db_entry_get_by_id failed!\n";
        uVar6 = 0x11d4;
LAB_00671428:
        printf(__format,"stats_db_fail_sta_add",uVar6);
        return 0xffffffff;
      }
    }
    else if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_fail_sta_add",0x11cf,
             (uint)*(ushort *)((int)param_1 + 0xc),(uint)*(byte *)((int)param_1 + 0xe),
             (uint)*(byte *)((int)param_1 + 0xf));
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

