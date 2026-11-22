// func FUN_0050c0e0 @ 0050c0e0 size=884

undefined4 FUN_0050c0e0(ushort *param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  void *__s;
  uint uVar7;
  uint local_300 [2];
  undefined1 auStack_2f8 [16];
  ushort local_2e8;
  
  memset(auStack_2f8,0,0x2d8);
  iVar2 = *(int *)(param_1 + 2);
  if ((3 < *param_1 - 1) || (0x18fff < iVar2 - 1U)) {
    if (iVar2 - 1U < 0x19000) {
      return 0;
    }
    if (ac_passthrough_err_switch == '\0') {
      return 0;
    }
    printf("[AC_PASSTHROUGH_ERROR]%s()/%d Receive error len: %d\n",
           "_sub_device_report_response_request",0x636,iVar2);
    return 0;
  }
  if (ac_passthrough_debug_switch == '\0') {
    uVar1 = *param_1;
  }
  else {
    printf("[AC_PASSTHROUGH_DEBUG]%s()/%d type:%d data_handler:%d len:%d data:%s\r\n\n",
           "_sub_device_report_response_request",0x5fe,(uint)*param_1,(uint)param_1[1],iVar2,
           *(undefined4 *)(param_1 + 4));
    uVar1 = *param_1;
  }
  iVar2 = FUN_00407fe0(&g_reg_sub_device_report_handle + (uint)uVar1 * 0xc);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = apmngr_db_entry_get_by_mac(param_2,auStack_2f8);
  if (iVar2 == 0) {
    uVar7 = *(uint *)(param_1 + 2);
    if ((param_1[1] & 2) == 0) {
      __s = *(void **)(param_1 + 4);
      if (ac_passthrough_debug_switch == '\0') {
        uVar4 = (uint)*param_1;
      }
      else {
        pcVar5 = "[AC_PASSTHROUGH_DEBUG]%s()/%d Receive json: %s\n";
        uVar6 = 0x624;
LAB_0050c394:
        printf(pcVar5,"_sub_device_report_response_request",uVar6,__s);
        uVar4 = (uint)*param_1;
      }
    }
    else {
      local_300[0] = uVar7 * 100;
      if (0x19000 < uVar7 * 100) {
        local_300[0] = 0x19000;
      }
      __s = (void *)FUN_00408450(local_300[0] + 1,0x60d);
      if (__s == (void *)0x0) {
        if (ac_passthrough_err_switch == '\0') {
          return 0xffffffff;
        }
        pcVar5 = "[AC_PASSTHROUGH_ERROR]%s()/%d Malloc failed.\n";
        uVar6 = 0x610;
        goto LAB_0050c2e8;
      }
      memset(__s,0,local_300[0] + 1);
      iVar2 = uncompress(__s,local_300,*(undefined4 *)(param_1 + 4),uVar7);
      if ((iVar2 != 0) || (0x18fff < local_300[0] - 1)) {
        if (ac_passthrough_debug_switch != '\0') {
          printf("[AC_PASSTHROUGH_DEBUG]%s()/%d Receive compress failed json: %s\n",
                 "_sub_device_report_response_request",0x617,__s);
        }
        FUN_00407df0(__s);
        if (ac_passthrough_err_switch == '\0') {
          return 0xffffffff;
        }
        printf("[AC_PASSTHROUGH_ERROR]%s()/%d Uncompress data failed val->data_handler:%d src_len:%d ap_id:%d.\n"
               ,"_sub_device_report_response_request",0x61a,(uint)param_1[1],uVar7,(uint)local_2e8);
        return 0xffffffff;
      }
      uVar7 = local_300[0];
      if (ac_passthrough_debug_switch != '\0') {
        pcVar5 = "[AC_PASSTHROUGH_DEBUG]%s()/%d Receive compress json: %s\n";
        uVar6 = 0x61e;
        goto LAB_0050c394;
      }
      uVar4 = (uint)*param_1;
    }
    for (iVar2 = FUN_004081b0(&g_reg_sub_device_report_handle + uVar4 * 0xc); iVar2 != 0;
        iVar2 = FUN_00408680(iVar2)) {
      (**(code **)(iVar2 + 0xc))(__s,uVar7,auStack_2f8,param_2);
    }
    uVar3 = 0;
    if (((param_1[1] & 2) != 0) && (__s != (void *)0x0)) {
      FUN_00407df0(__s);
    }
  }
  else {
    if (ac_passthrough_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar5 = "[AC_PASSTHROUGH_ERROR]%s()/%d apmngr_db_entry_get_by_mac() fail.\n";
    uVar6 = 0x604;
LAB_0050c2e8:
    uVar3 = 0xffffffff;
    printf(pcVar5,"_sub_device_report_response_request",uVar6);
  }
  return uVar3;
}

