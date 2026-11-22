// func mesh_jcs_topology_get @ 004be0c8 size=560

void mesh_jcs_topology_get(undefined4 param_1,undefined4 param_2)

{
  char *__s;
  size_t sVar1;
  FILE *__s_00;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_2c = apmngr_db_get_ap_max();
  local_24 = 0;
  local_20 = 0;
  local_1c = json_object_new_array();
  local_28 = 0;
  if (local_1c == 0) {
    if (mesh_err_switch != '\0') {
      printf("[MESH_ERROR]%s()/%d Failed to create json array.\n","_mesh_topology_get",0x6c0);
    }
  }
  else {
    apmngr_db_foreach_proc(0xe0000,_mesh_ap_entry_travesal,&local_30);
    mesh_db_ap_entry_child_foreach_proc(0xffff,0,_mesh_ap_entry_topology_get,&local_30);
    __s = (char *)json_object_to_json_string_ext(local_1c,0);
    if (__s == (char *)0x0) {
      if (mesh_err_switch == '\0') {
        __s_00 = (FILE *)0x0;
        iVar3 = 0;
      }
      else {
        __s_00 = (FILE *)0x0;
        printf("[MESH_ERROR]%s()/%d translate json to string failed.\n","_mesh_topology_get",0x6c8);
        iVar3 = 0;
      }
    }
    else {
      sVar1 = strlen(__s);
      __s_00 = fopen("/tmp/mesh_topology","w+");
      if (__s_00 == (FILE *)0x0) {
        iVar3 = 0;
        if (mesh_err_switch != '\0') {
          printf("[MESH_ERROR]%s()/%d open file failed.\n","_mesh_topology_get",0x6d1);
          iVar3 = 0;
        }
      }
      else {
        sVar1 = fwrite(__s,sVar1,1,__s_00);
        iVar3 = local_28;
        if ((sVar1 != 1) && (iVar3 = 0, mesh_err_switch != '\0')) {
          printf("[MESH_ERROR]%s()/%d write to file failed.\n","_mesh_topology_get",0x6d8);
        }
      }
    }
    if (local_1c != 0) {
      json_object_put();
    }
    if (__s_00 != (FILE *)0x0) {
      fclose(__s_00);
    }
    if (0 < iVar3) {
      uVar2 = json_object_new_string("/tmp/mesh_topology");
      json_object_object_add(param_2,"file_name",uVar2);
      uVar2 = json_object_new_int(iVar3);
      json_object_object_add(param_2,"total_num",uVar2);
    }
  }
  return;
}

