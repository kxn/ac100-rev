// func apdb_get_radio_mutex_channel @ 00609048 size=980

uint * apdb_get_radio_mutex_channel
                 (undefined *param_1,int param_2,uint param_3,undefined2 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined **ppuVar6;
  uint uVar7;
  int local_28 [3];
  
  param_3 = param_3 & 0xff;
  local_28[0] = 0;
  if (param_3 == 0) {
    if (apdb_err_switch == 0) {
      return (uint *)0x0;
    }
    pcVar3 = "[APDB_ERROR]%s()/line %d : input radio id error.\n";
    uVar4 = 0x2612;
LAB_0060912c:
    printf(pcVar3,"apdb_get_radio_mutex_channel",uVar4);
    return (uint *)0x0;
  }
  if (param_2 == 0) {
    if (apdb_err_switch == 0) {
      return (uint *)0x0;
    }
    pcVar3 = "[APDB_ERROR]%s()/line %d : the fwid is NULL\n";
    uVar4 = 0x2617;
    goto LAB_0060912c;
  }
  iVar1 = apdb_get_model_by_id(param_1,param_2,local_28);
  if (iVar1 != 0) {
    if (apdb_warning_switch == 0) {
      return (uint *)0x0;
    }
    pcVar3 = "[APDB_WARNING]%s()/line %d : get model failed\n";
    uVar4 = 0x261d;
    goto LAB_0060912c;
  }
  uVar7 = param_3 - 1 & 0xff;
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  if ((*(int *)(local_28[0] + 0x10) - 1U & 0xff) < uVar7) {
    FUN_00407f30(l_apdb_mutex);
    if (apdb_warning_switch == 0) {
      return (uint *)0x0;
    }
    printf("[APDB_WARNING]%s()/line %d : radios_id[%d] out of range[1,%d].\n",
           "apdb_get_radio_mutex_channel",0x2626,param_3,*(undefined4 *)(local_28[0] + 0x10));
    return (uint *)0x0;
  }
  FUN_00407f30(l_apdb_mutex);
  if ((*(int *)(local_28[0] + 4) == 0) || (*(int *)(local_28[0] + 0x34) == 0)) {
    puVar5 = (uint *)(*(int *)(local_28[0] + 0x28) + uVar7 * 0x114);
    if (1 < param_5) {
LAB_00609240:
      return puVar5 + 0xe;
    }
    if (*puVar5 == param_5) {
      return puVar5 + 0xe;
    }
    puVar5 = (uint *)puVar5[0x44];
    if ((puVar5 != (uint *)0x0) && (*puVar5 == param_5)) goto LAB_00609240;
    if (apdb_warning_switch == 0) {
      return (uint *)0x0;
    }
    ppuVar6 = &PTR_s_2_4GHz_00702480 + param_5;
    uVar4 = 0x2664;
  }
  else if (1 < param_5) {
    if (apdb_warning_switch == 0) {
      return (uint *)0x0;
    }
    ppuVar6 = &PTR_s_2_4GHz_00702480 + param_5;
    uVar4 = 0x2652;
  }
  else {
    iVar1 = uVar7 * 0x114;
    puVar5 = (uint *)(*(int *)(local_28[0] + 0x28) + iVar1);
    if (*puVar5 == param_5) {
      iVar2 = apmngr_get_linkage_mutex_channl(param_4,param_3,puVar5 + 0x27);
      if (iVar2 == 0) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : model_id=%d has rrst, return mutex_channel:%s\n",
                 "apdb_get_radio_mutex_channel",0x2633,param_1,
                 *(int *)(local_28[0] + 0x28) + iVar1 + 0x9c);
        }
        return (uint *)(*(int *)(local_28[0] + 0x28) + iVar1 + 0x9c);
      }
      if (apdb_debug_switch == 0) {
        return (uint *)0x0;
      }
      pcVar3 = "[APDB_DEBUG]%s()/line %d : model_id=%d has rrst, but get mutex_channel fail\n";
      uVar4 = 0x2638;
      goto LAB_0060921c;
    }
    puVar5 = (uint *)puVar5[0x44];
    if ((puVar5 != (uint *)0x0) && (*puVar5 == param_5)) {
      iVar2 = apmngr_get_linkage_mutex_channl(param_4,param_3,puVar5 + 0x27);
      if (iVar2 == 0) {
        if (apdb_debug_switch != 0) {
          printf("[APDB_DEBUG]%s()/line %d : model_id=%d has rrst, return mutex_channel:%s\n",
                 "apdb_get_radio_mutex_channel",0x2640,param_1,
                 *(int *)(*(int *)(local_28[0] + 0x28) + iVar1 + 0x110) + 0x9c);
        }
        return (uint *)(*(int *)(*(int *)(local_28[0] + 0x28) + iVar1 + 0x110) + 0x9c);
      }
      if (apdb_debug_switch == 0) {
        return (uint *)0x0;
      }
      pcVar3 = "[APDB_DEBUG]%s()/line %d : model_id=%d has rrst, but get mutex_channel fail\n";
      uVar4 = 0x2645;
      goto LAB_0060921c;
    }
    if (apdb_warning_switch == 0) {
      return (uint *)0x0;
    }
    ppuVar6 = &PTR_s_2_4GHz_00702480 + param_5;
    uVar4 = 0x264c;
  }
  pcVar3 = "[APDB_WARNING]%s()/line %d : Illegal freq %s.\n";
  param_1 = *ppuVar6;
LAB_0060921c:
  printf(pcVar3,"apdb_get_radio_mutex_channel",uVar4,param_1);
  return (uint *)0x0;
}

