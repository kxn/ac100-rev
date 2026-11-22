// func _uac_wserv_ap_copy @ 005d76c4 size=112

undefined4 _uac_wserv_ap_copy(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  iVar1 = wserv_db_ap_sync_bind_list
                    (*(undefined2 *)(param_2 + 0x10),*(undefined2 *)(param_1 + 0x10),0,0,0,0);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    local_20 = CONCAT22(*(undefined2 *)(param_1 + 0x10),local_20._2_2_);
    wserv_db_sync_wlan_to_re(&local_20);
    uVar2 = 0;
  }
  return uVar2;
}

