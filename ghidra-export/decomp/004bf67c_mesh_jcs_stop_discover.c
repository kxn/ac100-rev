// func mesh_jcs_stop_discover @ 004bf67c size=68

void mesh_jcs_stop_discover(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  mesh_stop_re_auto_add_proc();
  uVar1 = mesh_stop_discover();
  uVar1 = json_object_new_int(uVar1);
  json_object_object_add(param_2,&DAT_00676a24,uVar1);
  return;
}

