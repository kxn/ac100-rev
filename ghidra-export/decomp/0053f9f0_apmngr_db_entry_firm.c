// func apmngr_db_entry_firm @ 0053f9f0 size=628

undefined4 apmngr_db_entry_firm(uint param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_300 [732];
  
  param_1 = param_1 & 0xffff;
  memset(auStack_300,0,0x2d8);
  if (((int)param_1 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < param_1 && ((int)param_1 < apmngr_sensor_num_max + 50000)))) {
    uVar4 = param_1;
    if (49999 < param_1) {
      uVar4 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    iVar5 = g_apmngr_entry_array + uVar4 * 0x2d8;
    iVar2 = -1;
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    if (((*(int *)(iVar5 + 0x1c) == 1) && (*(int *)(iVar5 + 0x3c) == 0)) &&
       ((uVar1 = g_apmngr_firm_sensor_num, *(int *)(iVar5 + 0x14) != 7 ||
        (uVar1 = g_apmngr_firm_sensor_num + 1,
        (int)(uint)g_apmngr_firm_sensor_num < apmngr_firm_sensor_num_max)))) {
      g_apmngr_firm_sensor_num = uVar1;
      *(undefined4 *)(iVar5 + 0x3c) = 1;
      iVar2 = 0;
      FUN_00408500(iVar5);
      FUN_004086b0(g_apmngr_group_array + (uint)*(ushort *)(iVar5 + 0x12) * 0x84 + 0x78,iVar5);
      if (param_2 != 0) {
        if (49999 < param_1) {
          param_1 = (param_1 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        iVar2 = 0;
        memcpy(auStack_300,(void *)(g_apmngr_entry_array + param_1 * 0x2d8),0x2d8);
      }
    }
    FUN_00407f30(apmngr_db_mutex);
    if (iVar2 == 0) {
      uVar3 = 0;
      if ((((param_2 != 0) && (iVar2 = apmngr_db_sqlite_notify_msg(2,auStack_300,0x2d8), iVar2 != 0)
           ) && (uVar3 = 0xffffffff, apmngr_err_switch != '\0')) &&
         (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[APMNGR_ERROR]%s()/%d Failed to notify daemon thread.\n","apmngr_db_entry_firm",
               0xc2c);
      }
    }
    else {
      uVar3 = 0xffffffff;
    }
  }
  else {
    uVar3 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_entry_firm",0xc0a,param_1);
    }
  }
  return uVar3;
}

