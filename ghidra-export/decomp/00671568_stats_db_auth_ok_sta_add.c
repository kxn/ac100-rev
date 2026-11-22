// func stats_db_auth_ok_sta_add @ 00671568 size=476

undefined4 stats_db_auth_ok_sta_add(void *param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  void *__dest;
  char *__format;
  undefined4 uVar5;
  undefined1 auStack_2e8 [72];
  undefined1 auStack_2a0 [656];
  
  memset(auStack_2e8,0,0x2d8);
  if (param_1 == (void *)0x0) {
    if (stats_err_switch != '\0') {
      __format = "[STATISTICS_ERROR]%s()/%d entry is null!\n";
      uVar5 = 0x1205;
      goto LAB_006716a0;
    }
  }
  else {
    uVar2 = *(ushort *)((int)param_1 + 0xc);
    iVar3 = apmngr_db_get_ap_max();
    if (((((int)(uint)uVar2 < iVar3) && (bVar1 = *(byte *)((int)param_1 + 0xe), bVar1 != 0)) &&
        (uVar4 = rdmngr_profile_get_max_rd_per_ap(), bVar1 <= uVar4)) &&
       ((bVar1 = *(byte *)((int)param_1 + 0xf), bVar1 != 0 &&
        (uVar4 = rdmngr_profile_get_max_wlan_per_rd(), bVar1 <= uVar4)))) {
      iVar3 = apmngr_db_entry_get_by_id(*(undefined2 *)((int)param_1 + 0xc),auStack_2e8);
      if (iVar3 == 0) {
        __dest = (void *)FUN_00408450(0x20,0x1214);
        if (__dest == (void *)0x0) {
          if (stats_err_switch != '\0') {
            __format = "[STATISTICS_ERROR]%s()/%d memory is overflow!\n";
            uVar5 = 0x1217;
            goto LAB_006716a0;
          }
        }
        else {
          memcpy(__dest,param_1,0x20);
          *(undefined4 *)((int)__dest + 0x18) = stats_consumer_bit_mask;
          memcpy((void *)((int)__dest + 6),auStack_2a0,6);
          iVar3 = FUN_00408540(client_auth_success_container,__dest);
          if (iVar3 == 0) {
            return 0;
          }
          FUN_00407df0(__dest);
        }
      }
      else if (stats_err_switch != '\0') {
        __format = "[STATISTICS_ERROR]%s()/%d apmngr_db_entry_get_by_id failed!\n";
        uVar5 = 0x1210;
LAB_006716a0:
        printf(__format,"stats_db_auth_ok_sta_add",uVar5);
        return 0xffffffff;
      }
    }
    else if (stats_warning_switch != '\0') {
      printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_auth_ok_sta_add",0x120b
             ,(uint)*(ushort *)((int)param_1 + 0xc),(uint)*(byte *)((int)param_1 + 0xe),
             (uint)*(byte *)((int)param_1 + 0xf));
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

