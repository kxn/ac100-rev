// func apmngr_ap_add @ 0052cf4c size=1092

undefined2 apmngr_ap_add(int param_1,void *param_2,int param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  size_t sVar8;
  undefined4 uVar9;
  char *pcVar10;
  uint local_518;
  undefined4 local_514;
  int local_510;
  undefined1 *local_50c;
  undefined4 local_508;
  char acStack_504 [156];
  undefined1 auStack_468 [218];
  char acStack_38e [65];
  char local_34d [77];
  undefined1 auStack_300 [16];
  ushort local_2f0;
  undefined2 local_2ee;
  char acStack_2b2 [154];
  undefined1 auStack_218 [496];
  
  memset(acStack_504,0,0x9a);
  memset(auStack_300,0,0x2d8);
  local_510 = 0;
  local_50c = (undefined1 *)0x0;
  local_508 = 0;
  memset(auStack_468,0,0x168);
  local_514 = 0;
  if (param_1 == 0) {
    if (apmngr_warning_switch == '\0') {
      return 0xffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffff;
    }
    pcVar10 = "[APMNGR_WARNING]%s()/%d Input ap entry is NULL.\n";
    uVar9 = 0x6b7;
    goto LAB_0052d1e4;
  }
  iVar5 = 3;
  if (*(int *)(param_1 + 0x14) != 7) {
    iVar5 = 1;
  }
  if (param_3 != 0) {
    iVar6 = apmngr_db_template_get(*(undefined4 *)(param_1 + 0x40),auStack_300);
    if (iVar6 == 0) {
      if (apmngr_debug_switch == '\0') {
        uVar7 = *(uint *)(param_1 + 0x14);
      }
      else {
        iVar6 = is_target_debug_ap();
        if (iVar6 == 0) {
          uVar7 = *(uint *)(param_1 + 0x14);
        }
        else {
          printf("[APMNGR_DEBUG]%s()/%d Matched template(%d).\n","apmngr_ap_add",0x6c3,
                 (uint)local_2f0);
          uVar7 = *(uint *)(param_1 + 0x14);
        }
      }
      if (((uVar7 < 2) || (uVar7 == 3)) || (uVar7 == 2)) {
        uVar1 = *(undefined1 *)(param_1 + 0x131);
        uVar2 = *(undefined1 *)(param_1 + 0x1b4);
        uVar3 = *(undefined1 *)(param_1 + 0x206);
        uVar4 = *(undefined1 *)(param_1 + 0x207);
        memcpy((void *)(param_1 + 0xe8),auStack_218,0x120);
        *(undefined1 *)(param_1 + 0x131) = uVar1;
        *(undefined1 *)(param_1 + 0x1b4) = uVar2;
        *(undefined2 *)(param_1 + 0x12) = local_2ee;
        local_50c = auStack_300;
        *(undefined1 *)(param_1 + 0x206) = uVar3;
        *(undefined1 *)(param_1 + 0x207) = uVar4;
        local_510 = param_1;
      }
      if (param_4 == 0) {
        pcVar10 = acStack_2b2;
LAB_0052d034:
        strncpy((char *)(param_1 + 0x4e),pcVar10,0x99);
      }
    }
    else {
      local_514 = *(undefined4 *)(param_1 + 0x44);
      iVar6 = apdb_hwver_exist_by_id(*(undefined4 *)(param_1 + 0x40),&local_514);
      if ((iVar6 != 1) ||
         (iVar6 = apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_2,auStack_468), iVar6 != 0
         )) {
        if (apmngr_warning_switch == '\0') {
          return 0xffff;
        }
        iVar5 = is_target_debug_ap();
        if (iVar5 == 0) {
          return 0xffff;
        }
        pcVar10 = "[APMNGR_WARNING]%s()/%d Failed to find entry in AP database, join failed.\n";
        uVar9 = 0x6e5;
        goto LAB_0052d1e4;
      }
      if (param_4 == 0) {
        pcVar10 = local_34d;
        if (local_34d[0] == '\0') {
          pcVar10 = acStack_38e;
        }
        goto LAB_0052d034;
      }
    }
  }
  local_518 = apmngr_db_id_alloc(iVar5);
  if ((int)local_518 < 0) {
    if (apmngr_warning_switch == '\0') {
      return 0xffff;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0xffff;
    }
    pcVar10 = "[APMNGR_WARNING]%s()/%d Failed to alloc id for ap entry.\n";
    uVar9 = 0x6f2;
LAB_0052d1e4:
    printf(pcVar10,"apmngr_ap_add",uVar9);
    return 0xffff;
  }
  uVar7 = local_518 & 0xffff;
  *(int *)(param_1 + 0xc) = iVar5;
  *(short *)(param_1 + 0x10) = (short)local_518;
  if ((param_3 != 0) && (param_4 == 0)) {
    pcVar10 = (char *)(param_1 + 0x4e);
    sVar8 = strlen(pcVar10);
    if (0x94 < sVar8) {
      *(undefined1 *)(param_1 + 0xe2) = 0;
    }
    if (iVar5 == 3) {
      uVar7 = uVar7 - 50000;
    }
    snprintf(acStack_504,0x9a,"%s-%.4d",pcVar10,uVar7);
    strncpy(pcVar10,acStack_504,0x99);
    *(undefined1 *)(param_1 + 0xe7) = 0;
  }
  *(undefined4 *)(param_1 + 0x290) = 0xffffffff;
  memcpy((void *)(param_1 + 0x218),param_2,0x10);
  iVar6 = apmngr_db_entry_add(param_1);
  if (iVar6 != 0) {
    apmngr_db_id_free(iVar5,local_518 & 0xffff);
    return 0xffff;
  }
  apmngr_db_sync_ap_entry(param_1,0,0,param_3);
  apmngr_db_datasync_ap_entry(param_1,0,0,param_3);
  if (param_5 == 0) {
    iVar6 = *(int *)(param_1 + 0x3c);
  }
  else {
    iVar6 = apmngr_evt_notify(0,param_1);
    if (iVar6 != 0) goto LAB_0052d2d0;
    if (local_510 == 0) {
      iVar6 = *(int *)(param_1 + 0x3c);
    }
    else {
      iVar6 = apmngr_evt_notify(4,&local_510);
      if (iVar6 != 0) goto LAB_0052d2d0;
      iVar6 = *(int *)(param_1 + 0x3c);
    }
  }
  if (iVar6 == 0) {
    return *(undefined2 *)(param_1 + 0x10);
  }
  iVar6 = apmngr_evt_notify(2,param_1);
  if (iVar6 == 0) {
    return *(undefined2 *)(param_1 + 0x10);
  }
LAB_0052d2d0:
  apmngr_evt_notify(3,param_1);
  apmngr_db_entry_delete(local_518 & 0xffff);
  apmngr_db_id_free(iVar5,local_518 & 0xffff);
  apmngr_db_sync_ap_entry_del(&local_518,1,0);
  apmngr_db_datasync_ap_entry_del(&local_518,1,0);
  return 0xffff;
}

