// func stats_db_ap_global_update @ 0066e710 size=824

undefined4 stats_db_ap_global_update(uint param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  int iVar6;
  undefined1 auStack_2f8 [453];
  char local_133;
  
  param_1 = param_1 & 0xffff;
  memset(auStack_2f8,0,0x2d8);
  iVar2 = apmngr_db_get_ap_max();
  if ((int)param_1 < iVar2) {
    if (param_2 != (byte *)0x0) {
      iVar2 = apmngr_db_entry_get_by_id(param_1,auStack_2f8);
      iVar6 = param_1 * 0x1e0;
      FUN_004082d0(l_stats_data,0xffffffff);
      pbVar5 = (byte *)(DAT_007cc8ec + iVar6);
      bVar1 = *pbVar5;
      if ((bVar1 & 1) != 0) {
        pbVar5[0x18] = *param_2;
        memcpy(pbVar5 + 0x19,param_2 + 1,8);
        uVar4 = *(uint *)(pbVar5 + 0x2c);
        pbVar5[0x21] = param_2[9];
        *(undefined2 *)(pbVar5 + 0x22) = *(undefined2 *)(param_2 + 10);
        uVar3 = uVar4 + *(int *)(param_2 + 0xc);
        *(uint *)(pbVar5 + 0x2c) = uVar3;
        *(uint *)(pbVar5 + 0x28) = (uint)(uVar3 < uVar4) + *(int *)(pbVar5 + 0x28);
        uVar4 = *(uint *)(pbVar5 + 0x34);
        uVar3 = uVar4 + *(int *)(param_2 + 0x10);
        *(uint *)(pbVar5 + 0x34) = uVar3;
        *(uint *)(pbVar5 + 0x30) = (uint)(uVar3 < uVar4) + *(int *)(pbVar5 + 0x30);
        uVar4 = *(uint *)(pbVar5 + 0x3c);
        uVar3 = uVar4 + *(int *)(param_2 + 0x14);
        *(uint *)(pbVar5 + 0x3c) = uVar3;
        *(uint *)(pbVar5 + 0x38) = (uint)(uVar3 < uVar4) + *(int *)(pbVar5 + 0x38);
        uVar4 = *(uint *)(pbVar5 + 0x44);
        uVar3 = uVar4 + *(int *)(param_2 + 0x18);
        *(uint *)(pbVar5 + 0x44) = uVar3;
        *(uint *)(pbVar5 + 0x40) = (uint)(uVar3 < uVar4) + *(int *)(pbVar5 + 0x40);
        uVar4 = *(uint *)(pbVar5 + 0x4c);
        uVar3 = uVar4 + *(int *)(param_2 + 0x1c);
        *(uint *)(pbVar5 + 0x4c) = uVar3;
        *(uint *)(pbVar5 + 0x48) = (uint)(uVar3 < uVar4) + *(int *)(pbVar5 + 0x48);
        if (*(int *)(pbVar5 + 0x74) == -1) {
          *(int *)(pbVar5 + 0x74) = *(int *)(param_2 + 0xc);
        }
        else {
          *(int *)(pbVar5 + 0x74) = *(int *)(param_2 + 0xc) + *(int *)(pbVar5 + 0x74);
        }
        if (*(int *)(pbVar5 + 0x78) == -1) {
          *(int *)(pbVar5 + 0x78) = *(int *)(param_2 + 0x10);
        }
        else {
          *(int *)(pbVar5 + 0x78) = *(int *)(param_2 + 0x10) + *(int *)(pbVar5 + 0x78);
        }
        if (*(int *)(pbVar5 + 0x7c) == -1) {
          *(int *)(pbVar5 + 0x7c) = *(int *)(param_2 + 0x14);
        }
        else {
          *(int *)(pbVar5 + 0x7c) = *(int *)(param_2 + 0x14) + *(int *)(pbVar5 + 0x7c);
        }
        if (*(int *)(pbVar5 + 0x80) == -1) {
          *(int *)(pbVar5 + 0x80) = *(int *)(param_2 + 0x18);
        }
        else {
          *(int *)(pbVar5 + 0x80) = *(int *)(param_2 + 0x18) + *(int *)(pbVar5 + 0x80);
        }
        if (*(int *)(pbVar5 + 0x84) == -1) {
          *(int *)(pbVar5 + 0x84) = *(int *)(param_2 + 0x1c);
        }
        else {
          *(int *)(pbVar5 + 0x84) = *(int *)(param_2 + 0x1c) + *(int *)(pbVar5 + 0x84);
        }
        *pbVar5 = bVar1 | 2;
        *(byte *)(DAT_007cc8ec + iVar6) = *(byte *)(DAT_007cc8ec + iVar6) & 0xf7;
        *(byte *)(DAT_007cc8ec + iVar6) = *(byte *)(DAT_007cc8ec + iVar6) | 4;
        *(byte *)(DAT_007cc8ec + iVar6) = *(byte *)(DAT_007cc8ec + iVar6) & 0xf7;
        *(byte *)(DAT_007cc8ec + iVar6) = *(byte *)(DAT_007cc8ec + iVar6) | 0x10;
        *(undefined4 *)(DAT_007cc8ec + iVar6 + 4) = 0;
        if ((iVar2 == 0) && (local_133 != '\0')) {
          *(undefined1 *)(DAT_007cc8ec + iVar6 + 0x16) = 1;
        }
        else {
          *(undefined1 *)(DAT_007cc8ec + iVar6 + 0x16) = 0;
        }
      }
      FUN_00407f30(l_stats_data);
      return 0;
    }
    if (stats_err_switch != '\0') {
      printf("[STATISTICS_ERROR]%s()/%d input NULL!\n","stats_db_ap_global_update",0xd3b);
      return 0xffffffff;
    }
  }
  else if (stats_warning_switch != '\0') {
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u]!\n","stats_db_ap_global_update",0xd36,param_1
          );
    return 0xffffffff;
  }
  return 0xffffffff;
}

