// func mesh_jcs_discover_status_get @ 004bdb58 size=192

void mesh_jcs_discover_status_get(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int local_20;
  char *local_1c [4];
  
  local_1c[0] = "init";
  local_1c[1] = "scanning";
  local_20 = 0;
  local_1c[2] = "finished";
  iVar2 = mesh_db_discover_state_get();
  uVar3 = json_object_new_string(local_1c[iVar2]);
  json_object_object_add(param_2,"status",uVar3);
  mesh_db_re_auto_add_state_get(&local_20);
  if (local_20 == 1) {
    pcVar1 = "Led on";
  }
  else {
    pcVar1 = "Led off";
  }
  uVar3 = json_object_new_string(pcVar1 + 4);
  json_object_object_add(param_2,"auto_add_status",uVar3);
  return;
}

