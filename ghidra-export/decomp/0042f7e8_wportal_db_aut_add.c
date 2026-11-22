// func wportal_db_aut_add @ 0042f7e8 size=1188

int wportal_db_aut_add(int param_1)

{
  int iVar1;
  uint uVar2;
  char cVar7;
  int iVar3;
  void *pvVar4;
  int iVar5;
  size_t sVar6;
  undefined4 uVar8;
  char *pcVar9;
  undefined1 auStack_98 [104];
  undefined1 auStack_30 [16];
  
  if (param_1 == 0) {
    if (wportal_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    pcVar9 = "[WPORTAL_ERR]%s()/%d NULL == autEntry\n";
    uVar8 = 0x102d;
LAB_0042f8dc:
    printf(pcVar9,"wportal_db_aut_add",uVar8);
    return -1;
  }
  iVar1 = wportal_get_mode();
  if ((iVar1 == 0) &&
     ((*(int *)(param_1 + 0x14) < 0 ||
      (uVar2 = wserv_profile_get_max_wservice(), uVar2 <= *(uint *)(param_1 + 0x14))))) {
    if (wportal_err_switch == 0) {
      return -1;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return -1;
    }
    pcVar9 = "[WPORTAL_ERR]%s()/%d Wserv id error\n";
    uVar8 = 0x1035;
    goto LAB_0042f8dc;
  }
  FUN_004082d0(wportal_aut_mutex,0xffffffff);
  if (g_max_session <= aut_count) {
    FUN_00407f30(wportal_aut_mutex);
    return 10;
  }
  iVar1 = FUN_00407e20(aut_tree,param_1);
  if (iVar1 != 0) {
    if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Add aut tree error for %d\n","wportal_db_aut_add",0x1060,iVar1);
    }
    goto LAB_0042f950;
  }
  FUN_004086b0(aut_list,param_1);
  iVar3 = wportal_get_mode();
  if (iVar3 == 1) {
    iVar3 = *(int *)(param_1 + 0x14);
    iVar5 = vlan_list_array_for_aut;
LAB_0042fb08:
    FUN_004086b0(iVar5 + iVar3 * 0xc,param_1 + 0x110);
    cVar7 = *(char *)(param_1 + 0xa3);
  }
  else {
    iVar3 = wportal_get_mode();
    if (iVar3 == 0) {
      iVar3 = *(int *)(param_1 + 0x14);
      iVar5 = ssid_list_array_for_aut;
      goto LAB_0042fb08;
    }
    cVar7 = *(char *)(param_1 + 0xa3);
  }
  if (cVar7 == '\0') {
LAB_0042f9a0:
    iVar3 = *(int *)(param_1 + 0xc);
  }
  else {
    pcVar9 = (char *)(param_1 + 0xa3);
    memset(auStack_98,0,0x74);
    FUN_0051ad88(auStack_30);
    memcpy(auStack_98,pcVar9,0x65);
    pvVar4 = (void *)FUN_00407fa0(username_hash_for_aut,auStack_98);
    if (pvVar4 == (void *)0x0) {
      pvVar4 = (void *)FUN_00408450(0x74,0x7a9);
      if (pvVar4 == (void *)0x0) goto LAB_0042f9a0;
      sVar6 = strlen(pcVar9);
      memcpy(pvVar4,pcVar9,sVar6 + 1);
      FUN_0051ad88((int)pvVar4 + 0x68);
      iVar3 = FUN_00408380(username_hash_for_aut,pvVar4);
      if (iVar3 == 0) goto LAB_0042fad4;
      FUN_00407df0(pvVar4);
      iVar3 = *(int *)(param_1 + 0xc);
    }
    else {
LAB_0042fad4:
      FUN_004086b0((int)pvVar4 + 0x68,param_1 + 0x11c);
      iVar3 = *(int *)(param_1 + 0xc);
    }
  }
  if ((iVar3 == 0) && ((*(uint *)(param_1 + 0x10) & 0xffff0000) == 0)) {
    iVar3 = *(int *)(param_1 + 0x160);
  }
  else {
    pvVar4 = (void *)FUN_00407fa0(dm_calling_station_hash,(void *)(param_1 + 0xc));
    if (pvVar4 == (void *)0x0) {
      pvVar4 = (void *)FUN_00408450(0x14,0xa4f);
      if (pvVar4 != (void *)0x0) {
        memcpy(pvVar4,(void *)(param_1 + 0xc),6);
        FUN_0051ad88((int)pvVar4 + 8);
        iVar3 = FUN_00408380(dm_calling_station_hash,pvVar4);
        if (iVar3 == 0) goto LAB_0042f9dc;
        FUN_00407df0(pvVar4);
      }
    }
    else {
LAB_0042f9dc:
      FUN_004086b0((int)pvVar4 + 8,param_1 + 0x128);
    }
    iVar3 = *(int *)(param_1 + 0x160);
  }
  if (iVar3 == 0 && *(int *)(param_1 + 0x164) == 0) {
    cVar7 = *(char *)(param_1 + 0x58);
  }
  else {
    FUN_00407e20(dm_sessid_rbtree,param_1);
    cVar7 = *(char *)(param_1 + 0x58);
  }
  if (cVar7 == '\0') {
    if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d autEntry is empty string!!!\n","_wportal_db_framed_ip_hash_add",
             0xa7d);
    }
  }
  else {
    if ((wportal_info_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d _wportal_db_framed_ip_hash_add ip:%s \n",
             "_wportal_db_framed_ip_hash_add",0xa81,param_1 + 0x58);
    }
    pvVar4 = (void *)FUN_00407fa0(dm_framed_ip_hash,(void *)(param_1 + 0x58));
    if (pvVar4 == (void *)0x0) {
      pvVar4 = (void *)FUN_00408450(0x34,0xa85);
      if (pvVar4 != (void *)0x0) {
        memcpy(pvVar4,(void *)(param_1 + 0x58),0x28);
        FUN_0051ad88((int)pvVar4 + 0x28);
        iVar3 = FUN_00408380(dm_framed_ip_hash,pvVar4);
        if (iVar3 == 0) goto LAB_0042fa80;
        FUN_00407df0(pvVar4);
      }
    }
    else {
LAB_0042fa80:
      FUN_004086b0((int)pvVar4 + 0x28,param_1 + 0x134);
    }
  }
  aut_count = aut_count + 1;
LAB_0042f950:
  FUN_00407f30(wportal_aut_mutex);
  return iVar1;
}

