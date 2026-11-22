// func apmngr_hdap_add @ 0052fdfc size=1564

ushort apmngr_hdap_add(int param_1,void *param_2,void *param_3,int param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined2 uVar6;
  size_t sVar3;
  int iVar4;
  int iVar5;
  char *pcVar7;
  undefined4 uVar8;
  ushort *puVar9;
  void *__src;
  void *__src_00;
  undefined4 local_7f8;
  ushort local_7f4 [2];
  undefined4 local_7f0;
  undefined2 local_7ec;
  int local_7e8;
  undefined1 *local_7e4;
  undefined4 local_7e0;
  char acStack_7dc [156];
  undefined1 auStack_740 [218];
  char acStack_666 [65];
  char local_625 [77];
  undefined1 auStack_5d8 [728];
  undefined1 auStack_300 [16];
  ushort local_2f0;
  undefined2 local_2ee;
  char acStack_2b2 [154];
  undefined1 auStack_218 [496];
  
  local_7f4[0] = 0xffff;
  local_7f4[1] = 0xffff;
  memset(acStack_7dc,0,0x9a);
  memset(auStack_300,0,0x2d8);
  local_7e8 = 0;
  local_7e4 = (undefined1 *)0x0;
  local_7e0 = 0;
  memset(auStack_740,0,0x168);
  local_7f8 = 0;
  memset(auStack_5d8,0,0x2d8);
  local_7f0 = 0;
  local_7ec = 0;
  if ((param_1 == 0) || (param_3 == (void *)0x0)) {
    if (apmngr_err_switch == '\0') {
      return 0xffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffff;
    }
    pcVar7 = "[APMNGR_ERROR]%s()/%d Input ap entry is NULL.\n";
    uVar8 = 0xb1a;
    goto LAB_0052ff38;
  }
  iVar1 = memcmp(param_3,&local_7f0,6);
  if (iVar1 == 0) {
    if (apmngr_warning_switch == '\0') {
      return 0xffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffff;
    }
    pcVar7 = "[APMNGR_WARNING]%s()/%d Failed to create hd_ap because peer_mac is zero.\n";
    uVar8 = 0xb21;
    goto LAB_0052ff38;
  }
  iVar1 = apmngr_db_entry_get_by_mac(param_3,auStack_5d8);
  if (iVar1 == 0) {
    if (apmngr_warning_switch == '\0') {
      return 0xffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffff;
    }
    pcVar7 = "[APMNGR_WARNING]%s()/%d Failed to create ap entry because peer ap is already exist.\n"
    ;
    uVar8 = 0xb28;
    goto LAB_0052ff38;
  }
  if (param_4 != 0) {
    uVar2 = *(uint *)(param_1 + 0x14);
    if ((uVar2 < 2) || (uVar2 == 3)) {
      uVar8 = *(undefined4 *)(param_1 + 0x40);
LAB_00530044:
      iVar1 = apmngr_db_template_get(uVar8,auStack_300);
      if (iVar1 == 0) {
        if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[APMNGR_DEBUG]%s()/%d Matched template(%d).\n","apmngr_hdap_add",0xb30,
                 (uint)local_2f0);
        }
        *(undefined2 *)(param_1 + 0x12) = local_2ee;
        memcpy((void *)(param_1 + 0xe8),auStack_218,0x120);
        strncpy((char *)(param_1 + 0x4e),acStack_2b2,0x99);
        local_7e4 = auStack_300;
        local_7e8 = param_1;
        goto LAB_00530098;
      }
      uVar6 = *(undefined2 *)(param_1 + 0x44);
    }
    else {
      if (uVar2 == 2) {
        uVar8 = *(undefined4 *)(param_1 + 0x40);
        goto LAB_00530044;
      }
      uVar6 = *(undefined2 *)(param_1 + 0x44);
    }
    local_7f8 = CONCAT22(uVar6,*(undefined2 *)(param_1 + 0x46));
    iVar1 = apdb_hwver_exist_by_id(*(undefined4 *)(param_1 + 0x40),&local_7f8);
    if ((iVar1 != 1) ||
       (iVar1 = apdb_get_ap_by_id(*(undefined4 *)(param_1 + 0x40),param_2,auStack_740), iVar1 != 0))
    {
      if (apmngr_warning_switch == '\0') {
        return 0xffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffff;
      }
      pcVar7 = "[APMNGR_WARNING]%s()/%d Failed to find entry in AP database, join failed.\n";
      uVar8 = 0xb3f;
LAB_0052ff38:
      printf(pcVar7,"apmngr_hdap_add",uVar8);
      return 0xffff;
    }
    pcVar7 = local_625;
    if (local_625[0] == '\0') {
      pcVar7 = acStack_666;
    }
    strncpy((char *)(param_1 + 0x4e),pcVar7,0x99);
  }
LAB_00530098:
  local_7f4[0] = apmngr_db_id_alloc(2);
  if ((local_7f4[0] == 0xffff) || (local_7f4[1] = apmngr_db_id_alloc(2), local_7f4[1] == 0xffff)) {
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_00530174;
    pcVar7 = "[APMNGR_ERROR]%s()/%d Failed to alloc id for ap entry.\n";
    uVar8 = 0xb4b;
  }
  else {
    *(undefined4 *)(param_1 + 0xc) = 2;
    if (param_4 != 0) {
      pcVar7 = (char *)(param_1 + 0x4e);
      sVar3 = strlen(pcVar7);
      if (0x91 < sVar3) {
        *(undefined1 *)(param_1 + 0xdf) = 0;
      }
      snprintf(acStack_7dc,0x9a,"%s-%.4d",pcVar7,(uint)local_7f4[0]);
      strncpy(pcVar7,acStack_7dc,0x99);
      *(undefined1 *)(param_1 + 0xe7) = 0;
    }
    __src = (void *)(param_1 + 0x48);
    iVar1 = apmngr_hdap_get_direct(__src,param_3);
    if (iVar1 == 2) {
      memcpy(&local_7f0,__src,6);
      memcpy(__src,param_3,6);
      memcpy(param_3,&local_7f0,6);
    }
    *(undefined4 *)(param_1 + 0x290) = 0xffffffff;
    memcpy((void *)(param_1 + 0x218),param_2,0x10);
    iVar4 = apmngr_db_hdap_add(param_1,local_7f4,param_3);
    if (iVar4 == 0) {
      apmngr_db_sync_ap_entry(param_1,param_3,0,param_4);
      puVar9 = local_7f4;
      iVar4 = 0;
      __src_00 = (void *)(param_1 + 0x48);
      apmngr_db_datasync_ap_entry(param_1,param_3,0,param_4);
      while( true ) {
        *(ushort *)(param_1 + 0x10) = *puVar9;
        if (iVar4 == 1) {
          memcpy(&local_7f0,__src_00,6);
          memcpy(__src_00,param_3,6);
        }
        if ((((param_5 != 0) && (iVar5 = apmngr_evt_notify(0,param_1), iVar5 != 0)) ||
            ((local_7e8 != 0 && (iVar5 = apmngr_evt_notify(4,&local_7e8), iVar5 != 0)))) ||
           ((*(int *)(param_1 + 0x3c) != 0 && (iVar5 = apmngr_evt_notify(2,param_1), iVar5 != 0))))
        break;
        if (iVar4 == 1) {
          memcpy(__src_00,&local_7f0,6);
        }
        iVar4 = iVar4 + 1;
        puVar9 = puVar9 + 1;
        if (iVar4 == 2) {
          iVar4 = apmngr_hdap_get_direct(__src,param_3);
          if (iVar4 == 2) {
            memcpy(&local_7f0,(void *)(param_1 + 0x48),6);
            memcpy((void *)(param_1 + 0x48),param_3,6);
            memcpy(param_3,&local_7f0,6);
          }
          if (iVar1 != 1) {
            return local_7f4[1];
          }
          return local_7f4[0];
        }
      }
      apmngr_evt_notify(3,param_1);
      goto LAB_00530174;
    }
    if ((apmngr_err_switch == '\0') || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_00530174;
    pcVar7 = "[APMNGR_ERROR]%s()/%d Failed to create HDAP.\n";
    uVar8 = 0xb6a;
  }
  printf(pcVar7,"apmngr_hdap_add",uVar8);
LAB_00530174:
  if (local_7f4[0] != 0xffff) {
    apmngr_db_id_free(2);
  }
  if (local_7f4[1] == 0xffff) {
    return 0xffff;
  }
  apmngr_db_id_free(2);
  return 0xffff;
}

