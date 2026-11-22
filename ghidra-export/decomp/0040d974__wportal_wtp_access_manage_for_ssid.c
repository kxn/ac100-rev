// func _wportal_wtp_access_manage_for_ssid @ 0040d974 size=1472

undefined4 _wportal_wtp_access_manage_for_ssid(int param_1,int param_2)

{
  void *__s;
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  int *piVar4;
  char local_188 [128];
  char local_108 [183];
  undefined1 local_51;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined1 local_1d;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  __s = (void *)FUN_00408450(0x10,0x294c);
  if (__s == (void *)0x0) {
    return 0xffffffff;
  }
  memset(__s,0,0x10);
  memset(local_188,0,0x16c);
  iVar1 = wportal_db_ssid_rdt_get(*(undefined4 *)(param_1 + 0x80),local_188);
  if (iVar1 != 0) {
    FUN_00407df0(__s);
    return 0xffffffff;
  }
  uVar2 = 0xfff;
  if (*(ushort *)(param_1 + 0x1f8) != 0) {
    uVar2 = (uint)*(ushort *)(param_1 + 0x1f8);
  }
  *(uint *)((int)__s + 0xc) = uVar2;
  FUN_004086b0(param_2 + 4,__s);
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d  noti_node->vlan: %d\n\n","_wportal_wtp_access_manage_for_ssid",
           0x2960,*(undefined4 *)((int)__s + 0xc));
  }
  if (local_188[0] != '\0') {
    puVar3 = (undefined1 *)FUN_00408450(0xb8,0x2965);
    if (puVar3 == (undefined1 *)0x0) {
      return 0;
    }
    memset(puVar3,0,0xb8);
    piVar4 = (int *)_wportal_url_parser(local_188);
    if ((wportal_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0)) {
      if (piVar4 == (int *)0x0) goto LAB_0040dd58;
      iVar1 = *piVar4;
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d Download fail url: %s\n\n","_wportal_wtp_access_manage_for_ssid",
             0x296d,local_188);
      if (piVar4 == (int *)0x0) {
LAB_0040dd58:
        if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
          printf("[WPORTAL_ERR]%s()/%d unknown rdtEntry.fail_url: %s\n\n",
                 "_wportal_wtp_access_manage_for_ssid",0x29a0,local_188);
        }
        *puVar3 = 2;
        memcpy(puVar3 + 0x2a,local_188,0x80);
        *(undefined4 *)(puVar3 + 0x20) = 0;
        puVar3[0x14] = 1;
        *(undefined4 *)(puVar3 + 0x10) = local_34;
        FUN_004086b0(param_2 + 0x10,puVar3 + 4);
        goto LAB_0040da2c;
      }
      iVar1 = *piVar4;
    }
    if (iVar1 == 0) {
      *puVar3 = 0;
      puVar3[0x14] = 0;
      *(int *)(puVar3 + 0x2c) = piVar4[2];
      *(undefined4 *)(puVar3 + 0x30) = 0xffffffff;
      if ((local_2c != 0x10) && (local_2c != 0x20)) {
        *(int *)(puVar3 + 0x3c) = piVar4[6];
        *(int *)(puVar3 + 0x40) = piVar4[6];
      }
      *(undefined4 *)(puVar3 + 0x44) = 6;
LAB_0040dc10:
      *(undefined4 *)(puVar3 + 0x20) = 0;
    }
    else {
      if (iVar1 != 1) {
        *puVar3 = 2;
        memcpy(puVar3 + 0x2a,piVar4 + 7,0x80);
        puVar3[0x14] = 1;
        goto LAB_0040dc10;
      }
      *puVar3 = 1;
      puVar3[0x14] = 0;
      memcpy(puVar3 + 0x36,piVar4 + 2,0x10);
      *(undefined4 *)(puVar3 + 0x48) = 0x80;
      if ((local_2c != 0x10) && (local_2c != 0x20)) {
        *(int *)(puVar3 + 0x54) = piVar4[6];
        *(int *)(puVar3 + 0x58) = piVar4[6];
      }
      *(undefined4 *)(puVar3 + 0x2c) = 0;
      *(undefined4 *)(puVar3 + 0x5c) = 6;
      FUN_00408480(puVar3 + 0x36,*(undefined4 *)(puVar3 + 0x48),puVar3 + 0x36);
    }
    *(undefined4 *)(puVar3 + 0x10) = local_34;
    FUN_004086b0(param_2 + 0x10,puVar3 + 4);
    FUN_00407df0(piVar4);
  }
LAB_0040da2c:
  if (local_108[0] == '\0') goto LAB_0040db08;
  if (local_2c == 0x40) {
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(local_51), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d no need to send cloud free to ap!!\n",
             "_wportal_wtp_access_manage_for_ssid",0x29b6);
    }
    goto LAB_0040db08;
  }
  puVar3 = (undefined1 *)FUN_00408450(0xb8,0x29bb);
  if (puVar3 == (undefined1 *)0x0) {
    return 0;
  }
  memset(puVar3,0,0xb8);
  piVar4 = (int *)_wportal_url_parser(local_108);
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Download portal url: %s\n\n","_wportal_wtp_access_manage_for_ssid",
           0x29c2,local_108);
  }
  if (piVar4 == (int *)0x0) {
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d unknown rdtEntry.portal_url: %s\n\n",
             "_wportal_wtp_access_manage_for_ssid",0x29f5,local_108);
    }
    *puVar3 = 2;
    memcpy(puVar3 + 0x2a,local_108,0x80);
    *(undefined4 *)(puVar3 + 0x20) = 0;
    puVar3[0x14] = 1;
    *(undefined4 *)(puVar3 + 0x10) = local_30;
    FUN_004086b0(param_2 + 0x10,puVar3 + 4);
    goto LAB_0040db08;
  }
  if (wportal_debug_switch == 0) {
    iVar1 = *piVar4;
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      iVar1 = *piVar4;
    }
    else {
      printf("[WPORTAL_DBG]%s()/%d free_para->para_type: %d\n\n",
             "_wportal_wtp_access_manage_for_ssid",0x29c6,*piVar4);
      iVar1 = *piVar4;
    }
  }
  if (iVar1 == 0) {
    *puVar3 = 0;
    puVar3[0x14] = 0;
    *(int *)(puVar3 + 0x2c) = piVar4[2];
    *(undefined4 *)(puVar3 + 0x30) = 0xffffffff;
    if ((local_2c != 0x10) && (local_2c != 0x20)) {
      *(int *)(puVar3 + 0x3c) = piVar4[6];
      *(int *)(puVar3 + 0x40) = piVar4[6];
    }
    *(undefined4 *)(puVar3 + 0x44) = 6;
LAB_0040dae4:
    *(undefined4 *)(puVar3 + 0x20) = 0;
  }
  else {
    if (iVar1 != 1) {
      *puVar3 = 2;
      memcpy(puVar3 + 0x2a,piVar4 + 7,0x80);
      puVar3[0x14] = 1;
      goto LAB_0040dae4;
    }
    *puVar3 = 1;
    puVar3[0x14] = 0;
    memcpy(puVar3 + 0x36,piVar4 + 2,0x10);
    *(undefined4 *)(puVar3 + 0x48) = 0x80;
    if ((local_2c != 0x10) && (local_2c != 0x20)) {
      *(int *)(puVar3 + 0x54) = piVar4[6];
      *(int *)(puVar3 + 0x58) = piVar4[6];
    }
    *(undefined4 *)(puVar3 + 0x2c) = 0;
    *(undefined4 *)(puVar3 + 0x5c) = 6;
    FUN_00408480(puVar3 + 0x36,*(undefined4 *)(puVar3 + 0x48),puVar3 + 0x36);
  }
  *(undefined4 *)(puVar3 + 0x10) = local_30;
  FUN_004086b0(param_2 + 0x10,puVar3 + 4);
  FUN_00407df0(piVar4);
LAB_0040db08:
  wserv_db_entry_set_ssid_portal_switch(local_51,local_1d);
  return 0;
}

