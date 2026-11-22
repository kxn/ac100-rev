// func apmngr_db_ap_led_timer_start @ 0053d160 size=808

undefined4
apmngr_db_ap_led_timer_start
          (ushort param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  ushort *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar5 = (uint)param_1;
  if (((int)uVar5 < apmngr_ap_num_max + apmngr_template_num_max) ||
     ((49999 < uVar5 && ((int)uVar5 < apmngr_sensor_num_max + 50000)))) {
    FUN_004082d0(apmngr_db_mutex,0xffffffff);
    uVar3 = uVar5;
    if (49999 < uVar5) {
      uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
    }
    if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x1c) == 1) {
      uVar3 = uVar5;
      if (49999 < uVar5) {
        uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      if (*(int *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x290) != -1) {
        uVar3 = uVar5;
        if (49999 < uVar5) {
          uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        FUN_00408060(*(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x290));
        uVar3 = uVar5;
        if (49999 < uVar5) {
          uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
        }
        *(undefined4 *)(g_apmngr_entry_array + uVar3 * 0x2d8 + 0x290) = 0xffffffff;
      }
      puVar2 = (ushort *)FUN_00408450(2,0x9f9);
      iVar1 = g_apmngr_entry_array;
      if (puVar2 == (ushort *)0x0) {
        FUN_00407f30(apmngr_db_mutex);
        return 0xffffffff;
      }
      *puVar2 = param_1;
      uVar3 = uVar5;
      if (49999 < uVar5) {
        uVar3 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      *(undefined1 *)(iVar1 + uVar3 * 0x2d8 + 0x294) = param_4;
      if ((apmngr_debug_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[APMNGR_DEBUG]%s()/%d Start led timer(%d secs) for ap %d\n",
               "apmngr_db_ap_led_timer_start",0xa01,param_2,uVar5);
      }
      if (49999 < uVar5) {
        uVar5 = (uVar5 - 50000) + apmngr_ap_num_max + apmngr_template_num_max;
      }
      iVar1 = g_apmngr_entry_array + uVar5 * 0x2d8;
      uVar4 = FUN_00408340(param_2,0,param_3,puVar2,uac_mem_free_my,"apmngr_db_ap_led_timer_start",
                           0xa02);
      *(undefined4 *)(iVar1 + 0x290) = uVar4;
    }
    uVar4 = 0;
    FUN_00407f30(apmngr_db_mutex);
  }
  else {
    uVar4 = 0xffffffff;
    if ((apmngr_err_switch != '\0') && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APMNGR_ERROR]%s()/%d Invalid ap id[%d].\n","apmngr_db_ap_led_timer_start",0x9ed,uVar5
            );
    }
  }
  return uVar4;
}

