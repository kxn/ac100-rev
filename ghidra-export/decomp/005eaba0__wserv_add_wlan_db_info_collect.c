// func _wserv_add_wlan_db_info_collect @ 005eaba0 size=628

void _wserv_add_wlan_db_info_collect(undefined4 *param_1,uint *param_2)

{
  byte bVar1;
  short sVar2;
  void *__src;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint local_28 [3];
  
  local_28[0] = 0xffffffff;
  bVar1 = *(byte *)(param_1 + 1);
  uVar6 = *param_1;
  __src = (void *)_wserv_get_entry(uVar6,(uint)bVar1);
  if (__src == (void *)0x0) {
    if (g_wserv_warning == 0) {
      return;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return;
    }
    printf("<wserv>[warning]%s(): %d  -> _wserv_get_entry() fail, rf/wlan[%d/%d]!\r\n",
           "_wserv_add_wlan_db_info_collect",0x549,*param_1,(uint)*(byte *)(param_1 + 1));
    return;
  }
  local_28[0] = rdmngr_db_generate_ap_id(uVar6);
  iVar3 = apmngr_db_capacity_support(local_28[0] & 0xffff,1,0x3f);
  if ((iVar3 == 0) && (*(int *)((int)__src + 0x11b) == 0)) {
    if (g_wserv_warning == 0) {
      return;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return;
    }
    printf("<wserv>[warning]%s(): %d  -> wserv[%d] is disable now!\r\n",
           "_wserv_add_wlan_db_info_collect",0x551,*(undefined4 *)((int)__src + 0x80));
    return;
  }
  iVar3 = wserv_calloc(1,0x220);
  if (iVar3 == 0) {
    if (g_wserv_warning == 0) {
      return;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return;
    }
    printf("<wserv>[warning]%s(): %d  -> no memory!!\r\n","_wserv_add_wlan_db_info_collect",0x558);
    return;
  }
  memcpy((void *)(iVar3 + 0x1a),__src,0x205);
  *(byte *)(iVar3 + 0x14) = bVar1;
  *(undefined4 *)(iVar3 + 0x10) = uVar6;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  iVar7 = DAT_007cbf04;
  iVar4 = rdmngr_db_generate_rd_idx_by_rd_id(uVar6);
  sVar2 = *(short *)(*(int *)(iVar7 + iVar4 * 0xc + 8) + (bVar1 - 1) * 6 + 4);
  uVar5 = *(uint *)(iVar3 + 0xc);
  if (sVar2 == -1) goto LAB_005ead14;
  *(short *)(iVar3 + 0x18) = sVar2;
  *(uint *)(iVar3 + 0xc) = uVar5 | 1;
  if ((*param_2 & 1) != 0) {
    local_28[0] = rdmngr_db_generate_ap_id(uVar6);
    iVar7 = sVar2 * 4;
    FUN_00407fa0(*(undefined4 *)(DAT_007cbf08 + iVar7),local_28);
    iVar7 = *(int *)(DAT_007cbf08 + iVar7);
    if (iVar7 == 0) {
      uVar5 = *(uint *)(iVar3 + 0xc);
      goto LAB_005ead14;
    }
    iVar7 = FUN_00407fa0(iVar7,local_28);
    if (iVar7 == 0) {
      uVar5 = *(uint *)(iVar3 + 0xc);
      goto LAB_005ead14;
    }
    *(char *)(iVar7 + 4) = *(char *)(iVar7 + 4) + '\x01';
  }
  uVar5 = *(uint *)(iVar3 + 0xc);
LAB_005ead14:
  *(uint *)(iVar3 + 0xc) = uVar5 | 4;
  FUN_004086b0(param_2 + 1,iVar3);
  return;
}

