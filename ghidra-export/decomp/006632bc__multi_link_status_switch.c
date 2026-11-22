// func _multi_link_status_switch @ 006632bc size=404

uint _multi_link_status_switch
               (uint param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  
  if (multi_link_debug_switch != '\0') {
    if (param_2 == 1) {
      pcVar4 = "Master";
    }
    else {
      pcVar4 = "Standby";
    }
    printf("[MULTI_LINK_DEBUG]%s()/%d AP(%d) switch to %s status.\n","_multi_link_status_switch",
           0x84,param_1,pcVar4);
  }
  iVar1 = g_multi_link_array;
  uVar5 = param_1;
  if (49999 < param_1) {
    iVar3 = apmngr_db_get_ap_max();
    uVar5 = (param_1 - 50000) + iVar3;
  }
  *(char *)(iVar1 + uVar5) = (char)param_2;
  if ((param_2 == 1) &&
     (iVar1 = apmngr_pkt_ac_ipaddr_pkt_send(param_1,param_4,param_5,param_6), iVar1 != 0)) {
    return 0xffffffff;
  }
  uVar5 = 0;
  for (iVar1 = FUN_004081b0(&g_multi_link_reg_list); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
    if (param_2 == 1) {
      if (*(code **)(iVar1 + 0x14) != (code *)0x0) {
        uVar2 = (**(code **)(iVar1 + 0x14))(param_1,param_3);
        uVar5 = uVar5 | uVar2;
      }
    }
    else if ((param_2 == 0) && (*(code **)(iVar1 + 0x18) != (code *)0x0)) {
      uVar2 = (**(code **)(iVar1 + 0x18))(param_1);
      uVar5 = uVar5 | uVar2;
    }
  }
  if (param_2 == 1) {
    apmngr_db_active_ap_inc(param_1);
  }
  else {
    apmngr_db_active_ap_dec();
  }
  return uVar5;
}

