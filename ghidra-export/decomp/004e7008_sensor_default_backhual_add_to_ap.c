// func sensor_default_backhual_add_to_ap @ 004e7008 size=872

/* WARNING: Removing unreachable block (ram,0x004e7100) */

undefined4 sensor_default_backhual_add_to_ap(int param_1,int param_2,int *param_3,int *param_4)

{
  uint uVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_738;
  undefined4 local_734;
  undefined4 local_730;
  undefined4 local_72c;
  undefined4 local_728;
  int local_724;
  int local_720;
  int local_71c;
  undefined4 local_718;
  char local_714 [20];
  char local_700 [28];
  char acStack_6e4 [52];
  char acStack_6b0 [64];
  char acStack_670 [68];
  undefined1 auStack_62c [283];
  undefined4 local_511;
  undefined4 local_50d;
  undefined4 local_500;
  char acStack_4fc [50];
  undefined4 local_4ca;
  undefined4 local_4c6;
  undefined4 local_4c2;
  undefined4 local_4be;
  undefined4 local_4ba;
  char acStack_4b2 [124];
  undefined1 local_436;
  char acStack_424 [1028];
  
  memset(auStack_62c,0,0x205);
  local_724 = 0;
  local_720 = 0;
  local_71c = 0;
  iVar7 = 0;
  local_718 = 0;
  memset(acStack_6e4,0,0x32);
  memset(acStack_670,0,0x41);
  local_738 = 0;
  local_714[0] = '\0';
  local_714[1] = '\0';
  local_714[2] = '\0';
  local_714[3] = '\0';
  local_714[4] = '\0';
  local_714[5] = '\0';
  local_714[6] = '\0';
  local_714[7] = '\0';
  local_714[8] = '\0';
  local_714[9] = '\0';
  local_714[10] = '\0';
  local_714[0xb] = '\0';
  local_714[0xc] = '\0';
  local_714[0xd] = '\0';
  local_714[0xe] = '\0';
  local_714[0xf] = '\0';
  local_714[0x10] = 0;
  memcpy(acStack_6b0,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789",0x3e);
  memcpy(acStack_424,&DAT_006b0db4,0x401);
  local_734 = 0;
  local_730 = 0;
  local_72c = 0;
  local_728 = 0;
  local_700[0] = '\0';
  local_700[1] = '\0';
  local_700[2] = '\0';
  local_700[3] = '\0';
  local_700[4] = '\0';
  local_700[5] = '\0';
  local_700[6] = '\0';
  local_700[7] = '\0';
  local_700[8] = '\0';
  local_700[9] = '\0';
  local_700[10] = '\0';
  local_700[0xb] = '\0';
  local_700[0xc] = '\0';
  local_700[0xd] = '\0';
  local_700[0xe] = '\0';
  local_700[0xf] = '\0';
  local_700[0x10] = '\0';
  local_700[0x11] = '\0';
  local_700[0x12] = '\0';
  local_700[0x13] = '\0';
  local_700[0x14] = '\0';
  local_700[0x15] = '\0';
  local_700[0x16] = '\0';
  local_700[0x17] = '\0';
  local_700[0x18] = 0;
  do {
    uVar1 = random();
    pcVar5 = local_714 + iVar7;
    iVar7 = iVar7 + 1;
    *pcVar5 = acStack_6b0[uVar1 % 0x3e];
  } while (iVar7 != 0x10);
  snprintf(acStack_6e4,0x32,"TP-SENSOR-%s",local_714);
  sVar2 = strlen(local_714);
  sVar3 = strlen(acStack_424);
  FUN_00407d50(local_714,sVar2,acStack_424,sVar3,&local_734);
  FUN_00408260(&local_734,0x10,local_700,&local_738);
  strncpy(acStack_670,local_700,0x10);
  local_511 = 1;
  local_500 = 1;
  local_50d = 0;
  local_4c6 = 1;
  local_4ca = 0;
  local_4c2 = 1;
  local_436 = 0;
  strcpy(acStack_4fc,acStack_6e4);
  local_4ba = 2;
  local_4be = 3;
  strcpy(acStack_4b2,acStack_670);
  iVar7 = uac_wservice_entry_add(auStack_62c);
  if (iVar7 == -1) {
    if (sensor_warning_switch == '\0') {
      return 0xffffffff;
    }
    pcVar5 = "[SENSOR_WARNING]%s()/%d Add default wserv entry failed\n";
    uVar6 = 0x904;
  }
  else {
    iVar4 = apmngr_db_get_ap_max();
    uVar1 = apmngr_db_get_ap_max();
    local_71c = FUN_004082a0((iVar4 >> 5) + (uint)((uVar1 & 0x1f) != 0),4,0x907);
    if (local_71c != 0) {
      local_724 = iVar7;
      if ((param_1 == 0) || (param_2 < 1)) {
        apmngr_db_foreach_proc(0x15f0000,_bind_default_ssid_to_online_ap,&local_724);
      }
      else {
        iVar4 = 0;
        do {
          iVar4 = iVar4 + 1;
          apmngr_db_foreach_proc_by_group
                    (*(undefined2 *)(param_1 + 2),0x15f0000,_bind_default_ssid_to_online_ap,
                     &local_724);
          param_1 = param_1 + 4;
        } while (iVar4 != param_2);
      }
      uac_wserv_update_aps_md5(local_71c,local_718);
      FUN_00407df0(local_71c);
      if (param_4 != (int *)0x0) {
        *param_4 = -1;
      }
      if (param_3 != (int *)0x0) {
        *param_3 = local_720;
      }
      if (local_720 != 0) {
        if (param_4 == (int *)0x0) {
          return 0;
        }
        *param_4 = iVar7;
        return 0;
      }
      uac_wservice_entry_delete_by_id(iVar7);
      return 0;
    }
    if (sensor_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar5 = "[SENSOR_ERROR]%s()/%d uac_mem_calloc() fail\n";
    uVar6 = 0x90a;
    local_71c = 0;
  }
  printf(pcVar5,"sensor_default_backhual_add_to_ap",uVar6);
  return 0xffffffff;
}

