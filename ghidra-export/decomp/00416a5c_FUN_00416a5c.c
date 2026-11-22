// func FUN_00416a5c @ 00416a5c size=1656

void FUN_00416a5c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *__dest;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  char *__format;
  int *piVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined4 uVar9;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined1 *in_stack_00000100;
  undefined4 in_stack_00000104;
  undefined4 in_stack_00000108;
  int in_stack_0000010c;
  int in_stack_00000110;
  int in_stack_00000114;
  int iVar10;
  undefined4 uVar11;
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
  
  iVar1 = in_stack_00000114;
  iVar10 = in_stack_00000110;
  iVar5 = in_stack_0000010c;
  uVar9 = in_stack_00000104;
  puVar8 = in_stack_00000100;
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memset(auStack_170,0,0x144);
  local_1d0 = (undefined1 *)0x0;
  local_1cc = 0;
  local_1c8 = 0;
  __dest = (int *)FUN_00408450(0x80,0x1a93);
  if (__dest == (int *)0x0) {
    if (wportal_err_switch == 0) {
      return;
    }
    iVar5 = is_target_debug_ap();
    if (iVar5 == 0) {
      return;
    }
    printf("[WPORTAL_ERR]%s()/%d Malloc free_url error\n",
           "_wportal_construct_free_auth_strategy_for_vlan",0x1a96);
    return;
  }
  if (iVar10 == 1) {
    memcpy(__dest,&local_res0,0x80);
  }
  else {
    uVar9 = 0xffffffff;
    if (iVar10 == 2) {
      memcpy(__dest,&stack0x00000080,0x80);
      uVar9 = in_stack_00000108;
    }
  }
  piVar2 = (int *)_wportal_url_parser(__dest);
  if ((iVar10 == 2) && (iVar5 == 0x40)) {
    if (piVar2 == (int *)0x0) goto LAB_00416b2c;
    iVar3 = *piVar2;
    if (iVar3 == 2) goto LAB_00416c84;
LAB_00416b18:
    if (iVar3 == 0) {
      memset(auStack_170,0,0x144);
      local_d8 = 1;
      local_b8 = (undefined1 *)piVar2[2];
      local_b4 = 0xffffffff;
      if ((iVar5 != 0x10) && (iVar5 != 0x20)) {
        local_a8 = piVar2[6];
        local_a4 = piVar2[6];
      }
      local_c4 = puVar8;
      local_1cc = 0;
      local_a0 = 6;
      uVar11 = 6;
      local_d4 = uVar9;
      if ((iVar1 != 1) && (uVar11 = local_1cc, iVar1 == 2)) {
        local_1cc = 7;
        uVar11 = local_1cc;
      }
    }
    else {
      if (iVar3 != 1) goto LAB_00416b2c;
      memset(auStack_170,0,0x144);
      local_d8 = 2;
      local_d4 = uVar9;
      memcpy(auStack_ae,piVar2 + 2,0x10);
      local_9c = 0x80;
      if ((iVar5 != 0x10) && (iVar5 != 0x20)) {
        local_90 = piVar2[6];
        local_8c = piVar2[6];
      }
      local_b8 = puVar8;
      local_88 = 6;
      FUN_00408480(auStack_ae,0x80,auStack_ae);
      local_1cc = 0;
      if (iVar1 == 1) {
        local_1cc = 0x11;
        uVar11 = local_1cc;
      }
      else {
        uVar11 = local_1cc;
        if (iVar1 == 2) {
          uVar11 = 0x12;
        }
      }
    }
    local_1cc = uVar11;
    local_1d0 = auStack_170;
    local_1c8 = iVar10;
    if (puVar8 == (undefined1 *)0xfff) {
      puVar8 = (undefined1 *)0x0;
    }
    uac_wservice_for_each_ap_bind_vlan(puVar8,_wportal_update_free_strategy_cb,&local_1d0);
    uac_wservice_for_each_ap_unbind_vlan(puVar8,_wportal_update_free_strategy_cb,&local_1d0);
    iVar5 = *piVar2;
LAB_00416c54:
    if (iVar5 == 0) {
      if (((local_d0 != 0) || (wportal_info_switch == 0)) ||
         (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00416c84;
      __format = 
      "[WPORTAL_INFO]%s()/%d Set ftt tuple entry: %s type: %d dst_ip: %x/%x vlan: %d dst_port: %d-%d protocol: %d\n"
      ;
      uVar7 = 0x1b3f;
      puVar8 = local_b8;
      uVar9 = local_b4;
      iVar5 = local_a8;
      iVar10 = local_a4;
      uVar11 = local_a0;
    }
    else {
      if (iVar5 != 1) goto LAB_00416cf8;
      if (local_d0 != 0) goto LAB_00416c84;
      memset(auStack_1b0,0,0x40);
      local_1c4 = 0;
      local_1c0 = 0;
      local_1bc = 0;
      local_1b8 = 0;
      local_1b4 = 0;
      FUN_00408560(auStack_ae,2,&local_1c4);
      FUN_00408190(local_1c4,local_1c0,local_1bc,local_1b8,local_1b4,auStack_1b0,0x40,"---");
      if ((wportal_info_switch == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0))
      goto LAB_00416c84;
      __format = 
      "[WPORTAL_INFO]%s()/%d Set ftt tuple entry: %s type: %d dst_ip: %s/%x vlan: %d dst_port: %d-%d protocol: %d\n"
      ;
      puVar8 = auStack_1b0;
      uVar7 = 0x1b51;
      uVar9 = local_9c;
      local_ac = local_94;
      iVar5 = local_90;
      iVar10 = local_8c;
      uVar11 = local_88;
    }
    printf(__format,"_wportal_construct_free_auth_strategy_for_vlan",uVar7,auStack_170,
           (uint)local_d0,puVar8,uVar9,local_ac,iVar5,iVar10,uVar11);
  }
  else {
    if (piVar2 != (int *)0x0) {
      iVar3 = *piVar2;
      goto LAB_00416b18;
    }
LAB_00416b2c:
    memset(auStack_170,0,0x144);
    local_d8 = 1;
    local_d0 = 1;
    piVar6 = __dest;
    if (piVar2 != (int *)0x0) {
      piVar6 = piVar2 + 7;
    }
    local_d4 = uVar9;
    memcpy(auStack_ba,piVar6,0x80);
    local_1d0 = auStack_170;
    local_c4 = puVar8;
    local_1cc = 0;
    if (iVar1 == 1) {
      local_1cc = 6;
    }
    else if (iVar1 == 2) {
      local_1cc = 7;
    }
    local_1c8 = iVar10;
    puVar4 = (undefined1 *)0x0;
    if (puVar8 != (undefined1 *)0xfff) {
      puVar4 = puVar8;
    }
    uac_wservice_for_each_ap_bind_vlan(puVar4,_wportal_update_free_strategy_cb,&local_1d0);
    uac_wservice_for_each_ap_unbind_vlan(puVar4,_wportal_update_free_strategy_cb,&local_1d0);
    memset(auStack_170,0,0x144);
    local_d8 = 2;
    local_d0 = 1;
    if (piVar2 == (int *)0x0) {
      piVar6 = __dest;
      local_d4 = uVar9;
      if ((wportal_err_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
        printf("[WPORTAL_ERR]%s()/%d Unkonwn free_url: %s \n",
               "_wportal_construct_free_auth_strategy_for_vlan",0x1b1b,__dest);
      }
    }
    else {
      piVar6 = piVar2 + 7;
      local_d4 = uVar9;
    }
    memcpy(auStack_ae,piVar6,0x80);
    local_1d0 = auStack_170;
    local_b8 = puVar8;
    local_1cc = 0;
    if (iVar1 == 1) {
      local_1cc = 0x11;
    }
    else if (iVar1 == 2) {
      local_1cc = 0x12;
    }
    local_1c8 = iVar10;
    if (puVar8 == (undefined1 *)0xfff) {
      puVar8 = (undefined1 *)0x0;
    }
    uac_wservice_for_each_ap_bind_vlan(puVar8,_wportal_update_free_strategy_cb,&local_1d0);
    uac_wservice_for_each_ap_unbind_vlan(puVar8,_wportal_update_free_strategy_cb,&local_1d0);
    if (piVar2 != (int *)0x0) {
      iVar5 = *piVar2;
      goto LAB_00416c54;
    }
LAB_00416cf8:
    if ((local_d0 == 1) && (wportal_info_switch != 0)) {
      iVar5 = is_target_debug_ap();
      if (iVar5 != 0) {
        printf("[WPORTAL_INFO]%s()/%d Set ftt url entry: %s type: %d vlan: %d  url: %s\n",
               "_wportal_construct_free_auth_strategy_for_vlan",0x1b5c,auStack_170,(uint)local_d0,
               local_c4,auStack_ba);
      }
    }
  }
LAB_00416c84:
  FUN_00407df0(__dest);
  if (piVar2 != (int *)0x0) {
    FUN_00407df0(piVar2);
  }
  return;
}

