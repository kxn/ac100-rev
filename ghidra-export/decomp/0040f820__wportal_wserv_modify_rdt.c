// func _wportal_wserv_modify_rdt @ 0040f820 size=260

undefined4 _wportal_wserv_modify_rdt(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((wportal_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Del rdt for: rdid: %d, wlanid: %d\n\n","_wportal_wserv_modify_rdt",
           0x1e01,*param_1,(uint)*(byte *)(param_1 + 1));
  }
  uVar2 = rdmngr_db_generate_ap_id(*param_1);
  if (*param_3 == 0) {
    iVar3 = _wportal_db_support_new_portal_by_id(uVar2);
    if (iVar3 != 0) {
      if (wportal_debug_switch == 0) {
        return 0;
      }
      iVar3 = is_target_debug_ap();
      if (iVar3 == 0) {
        return 0;
      }
      printf("[WPORTAL_DBG]%s()/%d new portal ap not need to add\n","_wportal_wserv_modify_rdt",
             0x1e07);
      return 0;
    }
    bVar1 = *(byte *)((int)param_1 + 3);
  }
  else {
    bVar1 = *(byte *)((int)param_1 + 3);
  }
  wsta_db_wlan_sta_foreach
            (uVar2,bVar1 & 0xf,*(undefined1 *)(param_1 + 1),_wportal_wserv_modify_rdt_wsta_manage,
             param_3);
  return 0;
}

