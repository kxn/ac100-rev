// func FUN_00413e94 @ 00413e94 size=1652

void FUN_00413e94(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *__dest;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *__format;
  int *piVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 in_stack_00000100;
  undefined4 in_stack_00000104;
  int in_stack_00000108;
  undefined4 in_stack_0000010c;
  int in_stack_00000110;
  int in_stack_00000114;
  undefined1 *in_stack_00000118;
  int iVar9;
  undefined4 uVar10;
  undefined1 *local_1d0;
  undefined4 local_1cc;
  int local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined1 auStack_1b0 [64];
  undefined1 auStack_170 [152];
  undefined4 local_d8;
  undefined4 local_d4;
  byte local_d0;
  undefined1 *local_c4;
  undefined1 auStack_ba [2];
  undefined1 *local_b8;
  undefined4 local_b4;
  undefined1 auStack_ae [2];
  undefined4 local_ac;
  int local_a8;
  int local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  
  puVar7 = in_stack_00000118;
  iVar1 = in_stack_00000114;
  iVar9 = in_stack_00000110;
  uVar10 = in_stack_0000010c;
  iVar4 = in_stack_00000108;
  uVar8 = in_stack_00000100;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memset(auStack_170,0,0x144);
  local_1d0 = (undefined1 *)0x0;
  local_1cc = 0;
  local_1c8 = 0;
  __dest = (int *)FUN_00408450(0x80,0x1b85);
  if (__dest == (int *)0x0) {
    if (wportal_err_switch == 0) {
      return;
    }
    iVar4 = is_target_debug_ap();
    if (iVar4 == 0) {
      return;
    }
    printf("[WPORTAL_ERR]%s()/%d Malloc free_url error\n",
           "_wportal_construct_free_auth_strategy_for_ssid",0x1b88);
    return;
  }
  if (iVar9 == 1) {
    memcpy(__dest,&local_res0,0x80);
  }
  else {
    uVar8 = 0xffffffff;
    if (iVar9 == 2) {
      memcpy(__dest,&stack0x00000080,0x80);
      uVar8 = in_stack_00000104;
    }
  }
  piVar2 = (int *)_wportal_url_parser(__dest);
  if ((iVar9 == 2) && (iVar4 == 0x40)) {
    if (piVar2 == (int *)0x0) goto LAB_00413f68;
    iVar3 = *piVar2;
    if (iVar3 == 2) goto LAB_0041409c;
LAB_00413f50:
    if (iVar3 == 0) {
      memset(auStack_170,0,0x144);
      local_d8 = 1;
      local_b8 = (undefined1 *)piVar2[2];
      local_b4 = 0xffffffff;
      if ((iVar4 != 0x10) && (iVar4 != 0x20)) {
        local_a8 = piVar2[6];
        local_a4 = piVar2[6];
      }
      local_1cc = 0;
      if (puVar7 == (undefined1 *)0xffffffff) {
        puVar7 = (undefined1 *)0x0;
      }
      local_a0 = 6;
      uVar6 = 6;
      local_d4 = uVar8;
      local_c4 = puVar7;
      if ((iVar1 != 1) && (uVar6 = local_1cc, iVar1 == 2)) {
        local_1cc = 7;
        uVar6 = local_1cc;
      }
    }
    else {
      if (iVar3 != 1) goto LAB_00413f68;
      memset(auStack_170,0,0x144);
      local_d8 = 2;
      local_d4 = uVar8;
      memcpy(auStack_ae,piVar2 + 2,0x10);
      local_9c = 0x80;
      if ((iVar4 != 0x10) && (iVar4 != 0x20)) {
        local_90 = piVar2[6];
        local_8c = piVar2[6];
      }
      local_88 = 6;
      if (puVar7 == (undefined1 *)0xffffffff) {
        puVar7 = (undefined1 *)0x0;
      }
      local_b8 = puVar7;
      FUN_00408480(auStack_ae,0x80,auStack_ae);
      local_1cc = 0;
      if (iVar1 == 1) {
        local_1cc = 0x11;
        uVar6 = local_1cc;
      }
      else {
        uVar6 = local_1cc;
        if (iVar1 == 2) {
          uVar6 = 0x12;
        }
      }
    }
    local_1cc = uVar6;
    local_1d0 = auStack_170;
    local_1c8 = iVar9;
    _wportal_update_free_strategy_cb(uVar10,&local_1d0);
    iVar4 = *piVar2;
LAB_0041406c:
    if (iVar4 == 0) {
      if (((local_d0 != 0) || (wportal_info_switch == 0)) ||
         (iVar4 = is_target_debug_ap(), iVar4 == 0)) goto LAB_0041409c;
      __format = 
      "[WPORTAL_INFO]%s()/%d Set ftt tuple entry: %s type: %d dst_ip: %x/%x vlan: %d dst_port: %d-%d protocol: %d\n"
      ;
      uVar6 = 0x1c45;
      puVar7 = local_b8;
      uVar8 = local_b4;
      iVar4 = local_a8;
      iVar9 = local_a4;
      uVar10 = local_a0;
    }
    else {
      if (iVar4 != 1) goto LAB_0041410c;
      if (local_d0 != 0) goto LAB_0041409c;
      memset(auStack_1b0,0,0x40);
      local_1c4 = 0;
      local_1c0 = 0;
      local_1bc = 0;
      local_1b8 = 0;
      local_1b4 = 0;
      FUN_00408560(auStack_ae,2,&local_1c4);
      FUN_00408190(local_1c4,local_1c0,local_1bc,local_1b8,local_1b4,auStack_1b0,0x40,"---");
      if ((wportal_info_switch == 0) || (iVar4 = is_target_debug_ap(), iVar4 == 0))
      goto LAB_0041409c;
      puVar7 = auStack_1b0;
      __format = 
      "[WPORTAL_INFO]%s()/%d Set ftt tuple entry: %s type: %d dst_ip: %s/%x vlan: %d dst_port: %d-%d protocol: %d\n"
      ;
      uVar6 = 0x1c57;
      uVar8 = local_9c;
      local_ac = local_94;
      iVar4 = local_90;
      iVar9 = local_8c;
      uVar10 = local_88;
    }
    printf(__format,"_wportal_construct_free_auth_strategy_for_ssid",uVar6,auStack_170,
           (uint)local_d0,puVar7,uVar8,local_ac,iVar4,iVar9,uVar10);
  }
  else {
    if (piVar2 != (int *)0x0) {
      iVar3 = *piVar2;
      goto LAB_00413f50;
    }
LAB_00413f68:
    if ((wportal_debug_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[WPORTAL_DBG]%s()/%d Unkonwn free_url: %s \n",
             "_wportal_construct_free_auth_strategy_for_ssid",0x1bef,__dest);
    }
    memset(auStack_170,0,0x144);
    local_d8 = 1;
    local_d0 = 1;
    if (piVar2 == (int *)0x0) {
      piVar5 = __dest;
      local_d4 = uVar8;
      if ((wportal_err_switch != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d Unkonwn free_url: %s \n",
               "_wportal_construct_free_auth_strategy_for_ssid",0x1bf7,__dest);
      }
    }
    else {
      piVar5 = piVar2 + 7;
      local_d4 = uVar8;
    }
    memcpy(auStack_ba,piVar5,0x80);
    local_1cc = 0;
    local_c4 = (undefined1 *)0x0;
    if (puVar7 != (undefined1 *)0xffffffff) {
      local_c4 = puVar7;
    }
    local_1d0 = auStack_170;
    if (iVar1 == 1) {
      local_1cc = 6;
    }
    else if (iVar1 == 2) {
      local_1cc = 7;
    }
    local_1c8 = iVar9;
    _wportal_update_free_strategy_cb(uVar10,&local_1d0);
    memset(auStack_170,0,0x144);
    local_d8 = 2;
    local_d0 = 1;
    piVar5 = __dest;
    if (piVar2 != (int *)0x0) {
      piVar5 = piVar2 + 7;
    }
    local_d4 = uVar8;
    memcpy(auStack_ae,piVar5,0x80);
    if (puVar7 != (undefined1 *)0xffffffff) {
      local_b8 = puVar7;
    }
    local_1d0 = auStack_170;
    local_1cc = 0;
    if (iVar1 == 1) {
      local_1cc = 0x11;
    }
    else if (iVar1 == 2) {
      local_1cc = 0x12;
    }
    local_1c8 = iVar9;
    _wportal_update_free_strategy_cb(uVar10,&local_1d0);
    if (piVar2 != (int *)0x0) {
      iVar4 = *piVar2;
      goto LAB_0041406c;
    }
LAB_0041410c:
    if ((local_d0 == 1) && (wportal_info_switch != 0)) {
      iVar4 = is_target_debug_ap();
      if (iVar4 != 0) {
        printf("[WPORTAL_INFO]%s()/%d Set ftt url entry: %s type: %d vlan: %d  url: %s\n",
               "_wportal_construct_free_auth_strategy_for_ssid",0x1c62,auStack_170,(uint)local_d0,
               local_c4,auStack_ba);
      }
    }
  }
LAB_0041409c:
  FUN_00407df0(__dest);
  if (piVar2 != (int *)0x0) {
    FUN_00407df0(piVar2);
  }
  return;
}

