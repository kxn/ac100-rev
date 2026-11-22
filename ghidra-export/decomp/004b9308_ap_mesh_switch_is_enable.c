// func ap_mesh_switch_is_enable @ 004b9308 size=272

undefined4 ap_mesh_switch_is_enable(uint param_1)

{
  int iVar1;
  int local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = 0;
  iVar1 = mesh_db_mesh_enable_get(&local_14);
  if (iVar1 == 0) {
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d enable %d.\n","ap_mesh_switch_is_enable",0x509,local_14);
    }
    iVar1 = apmngr_db_ap_mesh_switch_get(param_1 & 0xffff,&local_18);
    if (((iVar1 == 0) && (local_14 != 0)) && (local_18 != 0)) {
      return 1;
    }
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d ap %d mesh switch no get,cur switch %d\n",
             "ap_mesh_switch_is_enable",0x510,param_1,local_18);
      return 0;
    }
  }
  else if (mesh_err_switch != '\0') {
    printf("[MESH_ERROR]%s()/%d mesh_db_mesh_enable_get failed\n","ap_mesh_switch_is_enable",0x505);
    return 0;
  }
  return 0;
}

