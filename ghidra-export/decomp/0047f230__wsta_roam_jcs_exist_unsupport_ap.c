// func _wsta_roam_jcs_exist_unsupport_ap @ 0047f230 size=84

void _wsta_roam_jcs_exist_unsupport_ap(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  apmngr_db_foreach_proc(0x15f0000,_wstat_roam_check_exist_unsupport_ap,local_10);
  uVar1 = json_object_new_int(local_10[0]);
  json_object_object_add(param_2,"exist_unsupport_ap",uVar1);
  return;
}

