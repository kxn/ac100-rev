// func _wportal_wserv_modify_rdt_for_escape_exit @ 0040f784 size=156

undefined4
_wportal_wserv_modify_rdt_for_escape_exit(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((wportal_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Do escape strategy kick/pass rdt for: rdid: %d, wlanid: %d\n\n",
           "_wportal_wserv_modify_rdt_for_escape_exit",0x1e64,*param_1,(uint)*(byte *)(param_1 + 1))
    ;
  }
  uVar1 = rdmngr_db_generate_ap_id(*param_1);
  wsta_db_wlan_sta_foreach
            (uVar1,*(byte *)((int)param_1 + 3) & 0xf,*(undefined1 *)(param_1 + 1),
             _wportal_wserv_modify_rdt_unauth_wsta_manage,param_3);
  return 0;
}

