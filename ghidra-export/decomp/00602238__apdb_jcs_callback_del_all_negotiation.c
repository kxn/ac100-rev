// func _apdb_jcs_callback_del_all_negotiation @ 00602238 size=104

void _apdb_jcs_callback_del_all_negotiation(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  disableLearning = 1;
  usleep(1000000);
  apdb_entry_sync_clear();
  apdb_entry_datasync_clear();
  uVar1 = apdb_nego_clear();
  uVar1 = json_object_new_int(uVar1);
  json_object_object_add(param_2,"status",uVar1);
  return;
}

