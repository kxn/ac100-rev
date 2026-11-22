// func _bind_ap_to_wserv @ 005dbe60 size=192

undefined4 _bind_ap_to_wserv(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_220;
  code *local_21c;
  undefined1 auStack_218 [524];
  
  uVar2 = *param_2;
  memset(auStack_218,0,0x205);
  local_220 = 0;
  local_21c = (code *)0x0;
  iVar1 = wserv_db_get_entry_by_id(uVar2,auStack_218);
  if (iVar1 == 0) {
    local_21c = _uac_wserv_add_cb;
    uVar2 = 0;
    local_220 = param_1;
    _wserv_db_entry_auto_bind(auStack_218,&local_220);
  }
  else {
    uVar2 = 0xffffffff;
    if ((g_wserv_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[warning]%s(): %d  -> wserv_db_get_entry_by_id() fail.\r\n","_bind_ap_to_wserv"
             ,0x1127);
    }
  }
  return uVar2;
}

