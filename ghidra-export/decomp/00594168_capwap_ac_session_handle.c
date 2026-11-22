// func capwap_ac_session_handle @ 00594168 size=1036

/* WARNING: Type propagation algorithm not settling */

undefined4 capwap_ac_session_handle(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int local_40 [4];
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  
  local_40[0] = 0;
  if (param_2 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","capwap_ac_session_handle",0x724,
           "NULL != ac_session");
    return 0xffffffff;
  }
  iVar2 = *(int *)(param_2 + 0x7c);
  local_40[1] = 0;
  local_40[2] = 0;
  if (iVar2 == 0) {
    if (capwap_dtls_enable_switch == 0) {
      iVar2 = ac_msg_pretreat(param_1,param_2,local_40);
      if (iVar2 == -1) {
        uVar5 = 0xffffffff;
        if (capwap_warning_switch == 0) {
          return 0xffffffff;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        __format = "[CW_WARNING]%32s():%4d failed to pretreat packet buffer\n";
        uVar4 = 0x77b;
        goto LAB_00594330;
      }
      if (local_40[0] == 0) {
        uVar5 = 0;
        if (capwap_debug_switch == 0) {
          return 0;
        }
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          return 0;
        }
        __format = "[CW_DEBUG]%32s():%4d recived frag packet.\n";
        uVar4 = 0x780;
        goto LAB_00594330;
      }
      iVar2 = ac_msg_handle(param_1,param_2);
      if (iVar2 != -1) {
        cw_parsed_pkt_destroy(local_40[0]);
        return 0;
      }
      if ((capwap_warning_switch == 0) || (iVar2 = is_target_debug_ap(local_40[0]), iVar2 == 0))
      goto LAB_005944fc;
      uVar5 = 0x787;
      goto LAB_00594530;
    }
  }
  else if (capwap_dtls_enable_switch != 0) {
    iVar6 = *(int *)(iVar2 + 0x60);
    cVar1 = *(char *)(iVar2 + 0x5c);
    iVar2 = FUN_004081b0(*(undefined4 *)(iVar2 + 0x40));
    if (iVar2 == 0) {
      local_2c = 0;
      local_30 = 0;
      local_24 = 0;
      local_28 = 0;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0xc);
      local_24 = *(int *)(iVar2 + 0x1c);
      local_28 = *(undefined4 *)(iVar2 + 0x18);
      local_2c = *(int *)(iVar2 + 0x14);
      local_30 = *(undefined4 *)(iVar2 + 0x10);
    }
    iVar2 = (**(code **)(*(int *)(param_2 + 0x7c) + 100))();
    if (iVar2 == 1) {
      local_40[1] = 8;
      uVar5 = cw_fsm_ac_process_event(param_2,local_40 + 1);
      return uVar5;
    }
    if (iVar2 != 2) {
      iVar3 = is_store_snapshot();
      if (iVar3 == 0) {
        return 0;
      }
      if ((iVar6 != 1) || (iVar2 != -1)) {
        if (cVar1 != '\0') {
          return 0;
        }
        if (iVar6 != 0) {
          return 0;
        }
        if (*(char *)(*(int *)(param_2 + 0x7c) + 0x5c) != '\0') {
          return 0;
        }
        if (iVar2 != 0) {
          return 0;
        }
      }
      iVar2 = create_new_pkt_snapshot(5,param_1);
      memcpy((void *)(iVar2 + 0x18),(void *)(*(int *)(param_2 + 0x7c) + 8),0x14);
      if (*(undefined1 **)(iVar2 + 0x54) != (undefined1 *)0x0) {
        **(undefined1 **)(iVar2 + 0x54) = 0;
        *(undefined1 *)(*(int *)(iVar2 + 0x54) + 1) = 0;
        *(undefined1 *)(*(int *)(iVar2 + 0x54) + 2) = 1;
        *(int *)(*(int *)(iVar2 + 0x54) + 4) = local_24 - local_2c;
        *(undefined4 *)(*(int *)(iVar2 + 0x54) + 8) = 0;
        *(undefined4 *)(*(int *)(iVar2 + 0x54) + 0xc) = 0;
      }
      *(int *)(iVar2 + 0x14) = local_2c;
      *(undefined4 *)(iVar2 + 0x10) = local_30;
      return 0;
    }
    iVar2 = ac_msg_pretreat(param_1,param_2,local_40);
    if (iVar2 == -1) {
      uVar5 = 0xffffffff;
      if (capwap_warning_switch == 0) {
        return 0xffffffff;
      }
      iVar2 = is_target_debug_ap();
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      __format = "[CW_WARNING]%32s():%4d failed to pretreat packet buffer\n";
      uVar4 = 0x73f;
      goto LAB_00594330;
    }
    if (local_40[0] == 0) {
      return 0;
    }
    iVar2 = ac_msg_handle(param_1,param_2);
    if (iVar2 != -1) {
      cw_parsed_pkt_destroy(local_40[0]);
      return 0;
    }
    if ((capwap_warning_switch == 0) || (iVar2 = is_target_debug_ap(local_40[0]), iVar2 == 0))
    goto LAB_005944fc;
    uVar5 = 0x74a;
LAB_00594530:
    printf("[CW_WARNING]%32s():%4d failed to handle capwap message\n","capwap_ac_session_handle",
           uVar5);
LAB_005944fc:
    cw_parsed_pkt_destroy(local_40[0]);
    return 0xffffffff;
  }
  uVar5 = 0xffffffff;
  if (capwap_err_switch == 0) {
    return 0xffffffff;
  }
  iVar2 = is_target_debug_ap();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  __format = "[CW_ERROR]%32s():%4d some error occured.\n";
  uVar4 = 0x792;
LAB_00594330:
  printf(__format,"capwap_ac_session_handle",uVar4);
  return uVar5;
}

