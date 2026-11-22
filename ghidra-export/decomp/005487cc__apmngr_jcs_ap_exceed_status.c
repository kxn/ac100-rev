// func _apmngr_jcs_ap_exceed_status @ 005487cc size=60

void _apmngr_jcs_ap_exceed_status(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = apmngr_exceed_status_get();
  uVar1 = json_object_new_int(uVar1);
  json_object_object_add(param_2,"status",uVar1);
  return;
}

