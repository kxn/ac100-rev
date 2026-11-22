// func stats_db_sta_update @ 0066c750 size=800

undefined4 stats_db_sta_update(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  
  if (param_1 == 0) {
    if (stats_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_ERROR]%s()/%d entry is null!\n","stats_db_sta_update",0x8bb);
    return 0xffffffff;
  }
  uVar3 = *(ushort *)(param_1 + 6);
  iVar4 = apmngr_db_get_ap_max();
  if ((((iVar4 <= (int)(uint)uVar3) || (bVar2 = *(byte *)(param_1 + 8), bVar2 == 0)) ||
      (uVar5 = rdmngr_profile_get_max_rd_per_ap(), uVar5 < bVar2)) ||
     ((bVar2 = *(byte *)(param_1 + 9), bVar2 == 0 ||
      (uVar5 = rdmngr_profile_get_max_wlan_per_rd(), uVar5 < bVar2)))) {
    if (stats_warning_switch == '\0') {
      return 0xffffffff;
    }
    printf("[STATISTICS_WARNING]%s()/%d invalid id[%u,%u,%u]!\n","stats_db_sta_update",0x8c2,
           (uint)*(ushort *)(param_1 + 6),(uint)*(byte *)(param_1 + 8),(uint)*(byte *)(param_1 + 9))
    ;
    return 0xffffffff;
  }
  FUN_004082d0(l_stats_data,0xffffffff);
  uVar10 = 1;
  iVar4 = FUN_00407fa0(DAT_007cc8e0,param_1);
  if ((iVar4 == 0) || ((*(byte *)(iVar4 + 0xc) & 1) == 0)) goto LAB_0066c96c;
  uVar8 = *(uint *)(iVar4 + 0x34);
  uVar5 = uVar8 + *(int *)(param_1 + 0x20);
  *(uint *)(iVar4 + 0x34) = uVar5;
  *(uint *)(iVar4 + 0x30) = (uint)(uVar5 < uVar8) + *(int *)(iVar4 + 0x30);
  uVar8 = *(uint *)(iVar4 + 0x3c);
  uVar5 = uVar8 + *(int *)(param_1 + 0x24);
  *(uint *)(iVar4 + 0x3c) = uVar5;
  *(uint *)(iVar4 + 0x38) = (uint)(uVar5 < uVar8) + *(int *)(iVar4 + 0x38);
  if (*(int *)(iVar4 + 0x60) == -1) {
    *(int *)(iVar4 + 0x60) = *(int *)(param_1 + 0x20);
  }
  else {
    *(int *)(iVar4 + 0x60) = *(int *)(param_1 + 0x20) + *(int *)(iVar4 + 0x60);
  }
  if (*(int *)(iVar4 + 100) == -1) {
    *(int *)(iVar4 + 100) = *(int *)(param_1 + 0x24);
  }
  else {
    *(int *)(iVar4 + 100) = *(int *)(param_1 + 0x24) + *(int *)(iVar4 + 100);
  }
  *(undefined1 *)(iVar4 + 0xd) = *(undefined1 *)(param_1 + 10);
  *(undefined1 *)(iVar4 + 0xe) = *(undefined1 *)(param_1 + 0xb);
  *(undefined1 *)(iVar4 + 0xf) = *(undefined1 *)(param_1 + 0xc);
  *(undefined1 *)(iVar4 + 0x10) = *(undefined1 *)(param_1 + 0xd);
  *(undefined2 *)(iVar4 + 0x14) = *(undefined2 *)(param_1 + 0xe);
  if (param_2 == 0) {
    cVar1 = *(char *)(param_1 + 0xd);
    if (-1 < cVar1) {
      if (*(char *)(iVar4 + 0x11) == -1) {
        *(char *)(iVar4 + 0x11) = cVar1;
      }
      else if (*(char *)(iVar4 + 0x11) < cVar1) {
        *(char *)(iVar4 + 0x11) = cVar1;
      }
    }
    iVar6 = *(int *)(iVar4 + 0x18);
    iVar9 = *(int *)(param_1 + 0x10);
    if (iVar6 != 0) {
      if (iVar9 == 0) {
        *(int *)(iVar4 + 0x18) = iVar6;
        goto LAB_0066c918;
      }
      iVar9 = FUN_0040a270(iVar6);
    }
    *(int *)(iVar4 + 0x18) = iVar9;
LAB_0066c918:
    uVar7 = *(undefined2 *)(param_1 + 0x14);
  }
  else {
    if (param_2 == 1) {
      cVar1 = *(char *)(param_1 + 0xd);
      if (-1 < cVar1) {
        if (*(char *)(iVar4 + 0x12) == -1) {
          *(char *)(iVar4 + 0x12) = cVar1;
        }
        else if (*(char *)(iVar4 + 0x12) < cVar1) {
          *(char *)(iVar4 + 0x12) = cVar1;
        }
      }
      iVar6 = *(int *)(iVar4 + 0x1c);
      if (iVar6 == 0) {
        *(int *)(iVar4 + 0x1c) = *(int *)(param_1 + 0x10);
      }
      else if (*(int *)(param_1 + 0x10) == 0) {
        *(int *)(iVar4 + 0x1c) = iVar6;
      }
      else {
        uVar10 = FUN_0040a270(iVar6);
        *(undefined4 *)(iVar4 + 0x1c) = uVar10;
      }
      goto LAB_0066c918;
    }
    uVar7 = *(undefined2 *)(param_1 + 0x14);
  }
  uVar10 = 0;
  *(undefined2 *)(iVar4 + 0x20) = uVar7;
  *(undefined1 *)(iVar4 + 0x22) = *(undefined1 *)(param_1 + 0x16);
  *(undefined1 *)(iVar4 + 0x23) = *(undefined1 *)(param_1 + 0x17);
  *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(param_1 + 0x1c);
  stats_callback_proc(0,param_1);
  *(undefined4 *)(iVar4 + 0x40) = 0;
  *(byte *)(iVar4 + 0xc) = *(byte *)(iVar4 + 0xc) & 0xf7 | 0x16;
LAB_0066c96c:
  FUN_00407f30(l_stats_data);
  wsta_db_update_nego_rate(param_1,*(undefined2 *)(param_1 + 0xe));
  return uVar10;
}

