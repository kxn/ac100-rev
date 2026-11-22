// func stats_db_radio_update @ 0066f68c size=896

undefined4 stats_db_radio_update(uint param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  void *__s;
  undefined4 uVar3;
  uint uVar4;
  byte *pbVar5;
  
  param_1 = param_1 & 0xffff;
  param_2 = param_2 & 0xff;
  iVar1 = apmngr_db_get_ap_max();
  if ((((int)param_1 < iVar1) && (param_2 != 0)) &&
     (uVar2 = rdmngr_profile_get_max_rd_per_ap(), param_2 <= uVar2)) {
    if ((param_3 == (undefined4 *)0x0) ||
       (__s = (void *)FUN_00408450(0x54,0xf4f), __s == (void *)0x0)) {
      if (stats_err_switch != '\0') {
        printf("[STATISTICS_ERROR]%s()/%d input or malloc NULL!\n","stats_db_radio_update",0xf51);
        return 0xffffffff;
      }
    }
    else {
      memset(__s,0,0x54);
      uVar3 = rdmngr_db_generate_rd_id(param_1,param_2);
      iVar1 = rdmngr_db_rd_entry_get(uVar3,__s);
      if (iVar1 == 0) {
        FUN_004082d0(l_stats_data,0xffffffff);
        iVar1 = (param_2 - 1) * 8;
        pbVar5 = *(byte **)(*(int *)(DAT_007cc8ec + param_1 * 0x1e0 + 0x1d8) + iVar1 + 4);
        FUN_00407f30(l_stats_data);
        if (((*pbVar5 & 1) == 0) && (*(char *)((int)__s + 0x48) == '\x01')) {
          if (stats_err_switch != '\0') {
            printf("[STATISTICS_ERROR]%s()/%d ap_id:%d radio_id:%d, self to active radio.\n",
                   "stats_db_radio_update",0xf64,param_1,param_2);
          }
          stats_db_radio_active(param_1,param_2,0);
        }
        FUN_00407df0(__s);
        FUN_004082d0(l_stats_data,0xffffffff);
        pbVar5 = *(byte **)(*(int *)(DAT_007cc8ec + param_1 * 0x1e0 + 0x1d8) + iVar1 + 4);
        if ((pbVar5 != (byte *)0x0) && ((*pbVar5 & 1) != 0)) {
          *(undefined4 *)(pbVar5 + 4) = *param_3;
          pbVar5[8] = *(byte *)(param_3 + 1);
          *(undefined2 *)(pbVar5 + 10) = *(undefined2 *)((int)param_3 + 6);
          *(undefined2 *)(pbVar5 + 0xc) = *(undefined2 *)(param_3 + 2);
          *(undefined2 *)(pbVar5 + 0xe) = *(undefined2 *)((int)param_3 + 10);
          pbVar5[0x10] = *(byte *)(param_3 + 3);
          pbVar5[0x11] = *(byte *)((int)param_3 + 0xd);
          pbVar5[0x12] = *(byte *)((int)param_3 + 0xe);
          pbVar5[0x13] = *(byte *)((int)param_3 + 0xf);
          *(undefined4 *)(pbVar5 + 0x14) = param_3[4];
          *(undefined4 *)(pbVar5 + 0x18) = param_3[5];
          pbVar5[0x30] = *(byte *)(param_3 + 8);
          pbVar5[0x31] = *(byte *)((int)param_3 + 0x21);
          pbVar5[0x32] = *(byte *)((int)param_3 + 0x22);
          pbVar5[0x33] = *(byte *)((int)param_3 + 0x23);
          uVar2 = *(uint *)(pbVar5 + 0x24) + param_3[6];
          *(uint *)(pbVar5 + 0x20) =
               (uint)(uVar2 < *(uint *)(pbVar5 + 0x24)) + *(int *)(pbVar5 + 0x20);
          *(uint *)(pbVar5 + 0x24) = uVar2;
          uVar4 = *(uint *)(pbVar5 + 0x2c);
          uVar2 = uVar4 + param_3[7];
          *(uint *)(pbVar5 + 0x2c) = uVar2;
          *(uint *)(pbVar5 + 0x28) = (uint)(uVar2 < uVar4) + *(int *)(pbVar5 + 0x28);
          if (*(int *)(pbVar5 + 0x70) == -1) {
            *(undefined4 *)(pbVar5 + 0x70) = param_3[6];
          }
          else {
            *(int *)(pbVar5 + 0x70) = param_3[6] + *(int *)(pbVar5 + 0x70);
          }
          if (*(int *)(pbVar5 + 0x74) == -1) {
            *(undefined4 *)(pbVar5 + 0x74) = param_3[7];
          }
          else {
            *(int *)(pbVar5 + 0x74) = param_3[7] + *(int *)(pbVar5 + 0x74);
          }
          pbVar5[0x34] = 0;
          pbVar5[0x35] = 0;
          pbVar5[0x36] = 0;
          pbVar5[0x37] = 0;
          *pbVar5 = *pbVar5 & 0xf7 | 0x16;
        }
        FUN_00407f30(l_stats_data);
        return 0;
      }
      if (stats_err_switch != '\0') {
        printf("[STATISTICS_ERROR]%s()/%d ap_id:%d radio_id:%d, rdmngr_db_rd_entry_get() failed.\n",
               "stats_db_radio_update",0xf57,param_1,param_2);
      }
      FUN_00407df0(__s);
    }
  }
  else if (stats_warning_switch != '\0') {
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u:%u]!\n","stats_db_radio_update",0xf4a,param_1,
           param_2);
    return 0xffffffff;
  }
  return 0xffffffff;
}

