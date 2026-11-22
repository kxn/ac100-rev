// func mesh_jcs_trigger_discover @ 004bf2e4 size=160

void mesh_jcs_trigger_discover(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_10 [2];
  
  local_10[0] = 0;
  iVar1 = mesh_db_re_auto_add_state_get(local_10);
  uVar2 = 0xffffffff;
  if (iVar1 != -1) {
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d mesh_jcs_trigger_discover re_auto_add_state=%d\n",
             "mesh_jcs_trigger_discover",0x558,local_10[0]);
    }
    uVar2 = 0;
    if (local_10[0] != 1) {
      uVar2 = mesh_start_discover(0);
    }
  }
  uVar2 = json_object_new_int(uVar2);
  json_object_object_add(param_2,&DAT_00676a24,uVar2);
  return;
}

