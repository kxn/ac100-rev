// func FUN_004212c8 @ 004212c8 size=268

void FUN_004212c8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_180 [372];
  
  memset(auStack_180,0,0x16c);
  iVar1 = wportal_db_ssid_rdt_get(param_1,auStack_180);
  if (iVar1 == 0) {
    wserv_db_entry_for_each_rd(param_1,_wportal_wserv_del_rdt_ftt,auStack_180);
    iVar1 = json_object_new_object();
    if (iVar1 != 0) {
      uVar2 = json_object_new_int(param_1);
      json_object_object_add(iVar1,"serv_id",uVar2);
      uVar2 = json_object_new_int(0xff);
      json_object_object_add(iVar1,"auth_type",uVar2);
      _wportal_authed_user_del_by_mode_id(iVar1);
      _wportal_nsa_del_by_mode_id(iVar1);
      json_object_put(iVar1);
    }
    wportal_db_ssid_rdt_del(param_1);
  }
  else if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Not get rdt entry: %d\n","_wportal_wserv_del_notify",0x2e81,param_1
          );
  }
  return;
}

