// func apmngr_db_ap_led_update @ 0053c1f0 size=456

undefined4 apmngr_db_ap_led_update(ushort param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  
  uVar3 = (uint)param_1;
  local_20 = 0;
  local_1c = 0;
  if (((int)uVar3 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < uVar3 && ((int)uVar3 < apmngr_sensor_num_max + 50000)))) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar2 = uVar3;
    if (49999 < uVar3) {
      uVar2 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar2 * 0x2d8 + 0x1c) == 1) {
      if (49999 < uVar3) {
        uVar3 = (uVar3 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x288) = param_2;
    }
    FUN_00407f30(apmngr_db_mutex);
    if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(0xb), iVar1 != 0)) {
      printf("[APMNGR_DEBUG]%s()/%d msg.led = %d\n","apmngr_db_ap_led_update",0x907,param_2);
    }
    local_20 = CONCAT22(param_1,local_20._2_2_);
    uVar4 = 0xffffffff;
    local_1c = param_2;
    iVar1 = apmngr_db_sqlite_notify_msg(0xb,&local_20,8);
    if (iVar1 == 0) {
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_led_update",0x8fc,uVar3);
    }
  }
  return uVar4;
}

