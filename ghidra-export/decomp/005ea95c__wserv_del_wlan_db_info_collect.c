// func _wserv_del_wlan_db_info_collect @ 005ea95c size=580

void _wserv_del_wlan_db_info_collect(undefined4 *param_1,uint *param_2)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint local_30 [3];
  
  iVar4 = DAT_007cbf04;
  iVar6 = DAT_007cbefc;
  local_30[0] = 0xffffffff;
  uVar7 = *param_1;
  bVar1 = *(byte *)(param_1 + 1);
  iVar3 = rdmngr_db_generate_rd_idx_by_rd_id(uVar7);
  iVar8 = (bVar1 - 1) * 6;
  sVar2 = *(short *)(*(int *)(iVar4 + iVar3 * 0xc + 8) + iVar8 + 2);
  local_30[0] = rdmngr_db_generate_ap_id(uVar7);
  iVar4 = apmngr_db_capacity_support(local_30[0] & 0xffff,1,0x3f);
  iVar6 = iVar6 + sVar2 * 0x21c;
  if ((iVar4 == 0) && (*(int *)(iVar6 + 299) == 0)) {
    if (g_wserv_warning == 0) {
      return;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return;
    }
    printf("<wserv>[warning]%s(): %d  -> wserv[%d] is disable now!\r\n",
           "_wserv_del_wlan_db_info_collect",0x505,*(undefined4 *)(iVar6 + 0x90));
    return;
  }
  iVar4 = wserv_calloc(1,0x220);
  if (iVar4 == 0) {
    if (g_wserv_warning == 0) {
      return;
    }
    iVar6 = is_target_debug_ap();
    if (iVar6 == 0) {
      return;
    }
    printf("<wserv>[warning]%s(): %d  -> no memory!!\r\n","_wserv_del_wlan_db_info_collect",0x50c);
    return;
  }
  memcpy((void *)(iVar4 + 0x1a),(void *)(iVar6 + 0x10),0x205);
  *(undefined4 *)(iVar4 + 0x10) = uVar7;
  *(byte *)(iVar4 + 0x14) = bVar1;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  iVar6 = DAT_007cbf04;
  iVar3 = rdmngr_db_generate_rd_idx_by_rd_id(uVar7);
  sVar2 = *(short *)(*(int *)(iVar6 + iVar3 * 0xc + 8) + iVar8 + 4);
  uVar5 = *(uint *)(iVar4 + 0xc);
  if (sVar2 == -1) goto LAB_005eab00;
  *(short *)(iVar4 + 0x18) = sVar2;
  *(uint *)(iVar4 + 0xc) = uVar5 | 2;
  if ((*param_2 & 1) != 0) {
    local_30[0] = rdmngr_db_generate_ap_id(uVar7);
    iVar6 = *(int *)(DAT_007cbf08 + sVar2 * 4);
    if (iVar6 == 0) {
      uVar5 = *(uint *)(iVar4 + 0xc);
      goto LAB_005eab00;
    }
    iVar6 = FUN_00407fa0(iVar6,local_30);
    if (iVar6 == 0) {
      uVar5 = *(uint *)(iVar4 + 0xc);
      goto LAB_005eab00;
    }
    *(char *)(iVar6 + 4) = *(char *)(iVar6 + 4) + '\x01';
  }
  uVar5 = *(uint *)(iVar4 + 0xc);
LAB_005eab00:
  *(uint *)(iVar4 + 0xc) = uVar5 | 8;
  FUN_004086b0(param_2 + 1,iVar4);
  return;
}

