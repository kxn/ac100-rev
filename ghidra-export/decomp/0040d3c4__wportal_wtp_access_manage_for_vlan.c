// func _wportal_wtp_access_manage_for_vlan @ 0040d3c4 size=1456

undefined4 _wportal_wtp_access_manage_for_vlan(int param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined1 *__dest;
  char local_190 [128];
  char local_110 [180];
  int local_5c;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  
  iVar5 = 0xfff;
  if (param_1 != 0) {
    iVar5 = param_1;
  }
  memset(local_190,0,0x16c);
  memset(local_190,0,0x16c);
  iVar1 = wportal_db_rdt_get_by_vlan(iVar5,local_190);
  if (iVar1 != 0) {
    return 0;
  }
  if (local_5c == 0) {
    return 0;
  }
  if (param_2 == (undefined2 *)0x0) {
    return 0xffffffff;
  }
  piVar2 = (int *)FUN_00408450(0x10,0x2869);
  if (piVar2 == (int *)0x0) {
    return 0xffffffff;
  }
  puVar7 = param_2 + 2;
  memset(piVar2,0,0x10);
  iVar1 = FUN_004081b0(puVar7);
  iVar3 = FUN_00407fe0(puVar7);
  for (iVar6 = 0; iVar6 < iVar3; iVar6 = iVar6 + 1) {
    if (*(int *)(iVar1 + 0xc) == iVar5) goto LAB_0040d5f4;
  }
  piVar2[3] = iVar5;
  FUN_004086b0(puVar7,piVar2);
  iVar1 = apmngr_db_capacity_support(*param_2,1,0x38);
  if (iVar1 != 0) {
    return 0;
  }
  if (local_190[0] != '\0') {
    puVar4 = (undefined1 *)FUN_00408450(0xb8,0x288b);
    if (puVar4 == (undefined1 *)0x0) {
      return 0xffffffff;
    }
    memset(puVar4,0,0xb8);
    piVar2 = (int *)_wportal_url_parser(local_190);
    if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_INFO]%s()/%d Download fail url: %s\n\n","_wportal_wtp_access_manage_for_vlan"
             ,0x2893,local_190);
    }
    if (piVar2 == (int *)0x0) {
      if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d unknown rdtEntry.fail_url: %s\n\n",
               "_wportal_wtp_access_manage_for_vlan",0x28c6,local_190);
      }
      *puVar4 = 2;
      memcpy(puVar4 + 0x2a,local_190,0x80);
      *(int *)(puVar4 + 0x20) = iVar5;
      puVar4[0x14] = 1;
      *(undefined4 *)(puVar4 + 0x10) = local_3c;
      FUN_004086b0(param_2 + 8,puVar4 + 4);
    }
    else {
      if (*piVar2 == 0) {
        *puVar4 = 0;
        puVar4[0x14] = 0;
        *(int *)(puVar4 + 0x2c) = piVar2[2];
        *(undefined4 *)(puVar4 + 0x30) = 0xffffffff;
        if ((local_34 != 0x10) && (local_34 != 0x20)) {
          *(int *)(puVar4 + 0x3c) = piVar2[6];
          *(int *)(puVar4 + 0x40) = piVar2[6];
        }
        *(undefined4 *)(puVar4 + 0x44) = 6;
LAB_0040d714:
        *(int *)(puVar4 + 0x20) = iVar5;
      }
      else {
        if (*piVar2 != 1) {
          *puVar4 = 2;
          memcpy(puVar4 + 0x2a,piVar2 + 7,0x80);
          puVar4[0x14] = 1;
          goto LAB_0040d714;
        }
        *puVar4 = 1;
        puVar4[0x14] = 0;
        memcpy(puVar4 + 0x36,piVar2 + 2,0x10);
        *(undefined4 *)(puVar4 + 0x48) = 0x80;
        if ((local_34 != 0x10) && (local_34 != 0x20)) {
          *(int *)(puVar4 + 0x54) = piVar2[6];
          *(int *)(puVar4 + 0x58) = piVar2[6];
        }
        *(int *)(puVar4 + 0x2c) = iVar5;
        *(undefined4 *)(puVar4 + 0x5c) = 6;
        FUN_00408480(puVar4 + 0x36,*(undefined4 *)(puVar4 + 0x48),puVar4 + 0x36);
      }
      *(undefined4 *)(puVar4 + 0x10) = local_3c;
      FUN_004086b0(param_2 + 8,puVar4 + 4);
      FUN_00407df0(piVar2);
    }
  }
  if (local_110[0] == '\0') {
    return 0;
  }
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d  rdtEntry->auth_type is: %d cloud cloud_server_num is %d \n\n",
           "_wportal_wtp_access_manage_for_vlan",0x28da,local_34,cloud_server_num);
  }
  if (local_34 == 0x40) {
    if (wportal_info_switch == 0) {
      return 0;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return 0;
    }
    printf("[WPORTAL_INFO]%s()/%d no need to send cloud free to ap!!\n",
           "_wportal_wtp_access_manage_for_vlan",0x28dd);
    return 0;
  }
  puVar4 = (undefined1 *)FUN_00408450(0xb8,0x28e1);
  if (puVar4 == (undefined1 *)0x0) {
    return 0xffffffff;
  }
  memset(puVar4,0,0xb8);
  piVar2 = (int *)_wportal_url_parser(local_110);
  if ((wportal_info_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_INFO]%s()/%d Download portal url: %s\n\n","_wportal_wtp_access_manage_for_vlan"
           ,0x28e8,local_110);
  }
  if (piVar2 == (int *)0x0) {
    if ((wportal_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d unknown portal url: %s\n\n","_wportal_wtp_access_manage_for_vlan"
             ,0x2915,local_110);
    }
    *puVar4 = 2;
    memcpy(puVar4 + 0x2a,local_110,0x80);
    *(int *)(puVar4 + 0x20) = iVar5;
    puVar4[0x14] = 1;
    *(undefined4 *)(puVar4 + 0x10) = local_38;
    FUN_004086b0(param_2 + 8,puVar4 + 4);
    return 0;
  }
  if (*piVar2 == 0) {
    *puVar4 = 0;
    puVar4[0x14] = 0;
    *(int *)(puVar4 + 0x2c) = piVar2[2];
    *(undefined4 *)(puVar4 + 0x30) = 0xffffffff;
    *(int *)(puVar4 + 0x3c) = piVar2[6];
    *(int *)(puVar4 + 0x40) = piVar2[6];
    *(undefined4 *)(puVar4 + 0x44) = 6;
  }
  else {
    if (*piVar2 == 1) {
      __dest = puVar4 + 0x36;
      *puVar4 = 1;
      puVar4[0x14] = 0;
      memcpy(__dest,piVar2 + 2,0x10);
      *(undefined4 *)(puVar4 + 0x48) = 0x80;
      *(int *)(puVar4 + 0x54) = piVar2[6];
      iVar1 = piVar2[6];
      *(int *)(puVar4 + 0x2c) = iVar5;
      *(int *)(puVar4 + 0x58) = iVar1;
      *(undefined4 *)(puVar4 + 0x5c) = 6;
      FUN_00408480(__dest,0x80,__dest);
      goto LAB_0040d584;
    }
    *puVar4 = 2;
    memcpy(puVar4 + 0x2a,piVar2 + 7,0x80);
    puVar4[0x14] = 1;
  }
  *(int *)(puVar4 + 0x20) = iVar5;
LAB_0040d584:
  *(undefined4 *)(puVar4 + 0x10) = local_38;
  FUN_004086b0(param_2 + 8,puVar4 + 4);
LAB_0040d5f4:
  FUN_00407df0(piVar2);
  return 0;
}

