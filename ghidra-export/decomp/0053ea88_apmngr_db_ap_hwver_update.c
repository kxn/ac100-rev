// func apmngr_db_ap_hwver_update @ 0053ea88 size=684

undefined4 apmngr_db_ap_hwver_update(ushort param_1,ushort *param_2,char *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  
  uVar3 = (uint)param_1;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_40 = 0;
  if ((apmngr_ap_num_max + apmngr_template_num_max <= (int)uVar3) &&
     ((uVar3 < 50000 || (apmngr_sensor_num_max + 50000 <= (int)uVar3)))) {
    if (apmngr_err_switch == '\0') {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_hwver_update",0xb08,uVar3);
    return 0xffffffff;
  }
  if (param_2 == (ushort *)0x0) {
    if (param_3 == (char *)0x0) goto LAB_0053ebb8;
    sscanf(param_3,"%hd.%hd",&local_40,(int)&local_40 + 2);
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar2 = uVar3;
    if (49999 < uVar3) {
      uVar2 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 1) {
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      iVar1 = g_apmngr_entry_array + uVar3 * 0x2d8;
      *(undefined2 *)(iVar1 + 0x44) = local_40._0_2_;
      *(undefined2 *)(iVar1 + 0x46) = local_40._2_2_;
    }
  }
  else {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar2 = uVar3;
    if (49999 < uVar3) {
      uVar2 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 1) {
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      iVar1 = g_apmngr_entry_array + uVar3 * 0x2d8;
      *(ushort *)(iVar1 + 0x44) = *param_2;
      *(ushort *)(iVar1 + 0x46) = param_2[1];
    }
  }
  FUN_00407f30(apmngr_db_mutex);
LAB_0053ebb8:
  local_3c = CONCAT22(param_1,local_3c._2_2_);
  if (param_3 == (char *)0x0) {
    if (param_2 == (ushort *)0x0) {
      return 0xffffffff;
    }
    snprintf((char *)((int)&local_3c + 2),0x14,"%u.%u",(uint)*param_2,(uint)param_2[1]);
  }
  else {
    strncpy((char *)((int)&local_3c + 2),param_3,0x13);
  }
  uVar4 = 0xffffffff;
  iVar1 = apmngr_db_sqlite_notify_msg(4,&local_3c,0x16);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  return uVar4;
}

