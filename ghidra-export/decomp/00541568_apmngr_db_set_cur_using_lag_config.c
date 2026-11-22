// func apmngr_db_set_cur_using_lag_config @ 00541568 size=392

undefined4
apmngr_db_set_cur_using_lag_config
          (undefined1 param_1,undefined1 param_2,undefined1 param_3,char *param_4,ushort param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  uVar3 = (uint)param_5;
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  if (49999 < uVar3) {
    uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  iVar1 = g_apmngr_entry_array + uVar3 * 0x2d8;
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
    FUN_00407f30(apmngr_db_mutex);
  }
  else {
    *(undefined1 *)(iVar1 + 0x2b1) = param_1;
    *(undefined1 *)(iVar1 + 0x2b3) = param_3;
    *(undefined1 *)(iVar1 + 0x2b2) = param_2;
    strncpy((char *)(iVar1 + 0x2b4),param_4,0x14);
    uVar2 = 0;
    local_40 = CONCAT22(param_5,CONCAT11((char)*(undefined4 *)(iVar1 + 0xc),param_1));
    local_3c = CONCAT13(param_2,CONCAT12(param_3,local_3c._2_2_));
    strncpy((char *)((int)&local_3c + 2),param_4,0x14);
    FUN_00407f30(apmngr_db_mutex);
    iVar1 = apmngr_db_sqlite_notify_msg(0x12,&local_40,0x1a);
    if (((iVar1 != 0) && (uVar2 = 0xffffffff, apmngr_err_switch != '\0')) &&
       (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Failed to notify sql daemon to update lag config.\n",
             "apmngr_db_set_cur_using_lag_config",0x1026);
    }
  }
  return uVar2;
}

