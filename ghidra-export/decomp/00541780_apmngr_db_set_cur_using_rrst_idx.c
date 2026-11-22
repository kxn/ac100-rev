// func apmngr_db_set_cur_using_rrst_idx @ 00541780 size=276

undefined4 apmngr_db_set_cur_using_rrst_idx(undefined1 param_1,ushort param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_18;
  
  uVar3 = (uint)param_2;
  local_18 = 0;
  FUN_004082d0(apmngr_db_mutex,0xffffffff);
  uVar1 = apmngr_db_mutex;
  if (49999 < uVar3) {
    uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
  }
  iVar2 = g_apmngr_entry_array + uVar3 * 0x2d8;
  if (iVar2 == 0) {
    uVar4 = 0xffffffff;
    FUN_00407f30(apmngr_db_mutex);
  }
  else {
    *(undefined1 *)(iVar2 + 0x2d0) = param_1;
    uVar4 = 0;
    local_18 = CONCAT22(param_2,CONCAT11((char)*(undefined4 *)(iVar2 + 0xc),param_1));
    FUN_00407f30(uVar1);
    iVar2 = apmngr_db_sqlite_notify_msg(0x16,&local_18,4);
    if (((iVar2 != 0) && (uVar4 = 0xffffffff, apmngr_err_switch != '\0')) &&
       (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Failed to notify sql daemon to update rrst_idx.\n",
             "apmngr_db_set_cur_using_rrst_idx",0x1056);
    }
  }
  return uVar4;
}

