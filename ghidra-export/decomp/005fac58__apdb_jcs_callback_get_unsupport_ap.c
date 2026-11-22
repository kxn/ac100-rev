// func _apdb_jcs_callback_get_unsupport_ap @ 005fac58 size=96

void _apdb_jcs_callback_get_unsupport_ap(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  get_unsupport_ap(0);
  FUN_00407f30(l_apdb_mutex);
  uVar1 = json_object_new_int(0xffffffff);
  json_object_object_add(param_2,&DAT_00676a24,uVar1);
  return;
}

