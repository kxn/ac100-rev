// func cloud_mngt_client_handle @ 0049c058 size=544

void cloud_mngt_client_handle(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  int *piVar5;
  int local_28 [2];
  
  local_28[0] = 0;
  if (cloud_mngt_debug_switch != '\0') {
    printf("[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_client_handle start\n\n","cloud_mngt_client_handle"
           ,0xaf2);
  }
  if (param_1 == 0) {
    return;
  }
  iVar1 = FUN_00407fe0(param_1);
  if (iVar1 == 0) {
    return;
  }
  iVar1 = json_object_new_object();
  iVar2 = FUN_004081b0(param_1);
  if (iVar2 != 0) {
    piVar5 = *(int **)(iVar2 + 0xc);
    while( true ) {
      if ((piVar5 != (int *)0x0) &&
         (((iVar3 = *piVar5, iVar3 == 1 || (iVar3 == 3)) || (iVar3 == 4)))) {
        if (local_28[0] == 0) {
          uVar4 = apmngr_db_get_ap_max();
          local_28[0] = FUN_004080a0(client_handle_hash_obj,client_handle_hash_key,
                                     client_handle_hash_cmp,uVar4);
        }
        _cloud_mngt_online_client_info_object_add(local_28[0],piVar5);
      }
      iVar2 = FUN_00408680(iVar2);
      if (iVar2 == 0) break;
      piVar5 = *(int **)(iVar2 + 0xc);
    }
  }
  if ((local_28[0] == 0) || (iVar2 = FUN_00407ed0(), iVar2 < 1)) {
LAB_0049c218:
    if (cloud_mngt_debug_switch == '\0') goto LAB_0049c1b4;
    __format = "[CLOUD_MNGT_DEBUG]%s()/%d client cloud_mngt_obj_send_to_cloud success\n";
    uVar4 = 0xb1f;
  }
  else {
    uVar4 = json_object_new_array();
    FUN_00408570(local_28[0],add_client_hash_node,uVar4);
    cloud_mngt_update_devstatus_param_add(iVar1);
    json_object_object_add(iVar1,"subDevice",uVar4);
    free_ac_cloud_mngt_hash(local_28,0);
    iVar2 = cloud_mngt_obj_send_to_cloud(2,iVar1);
    if (iVar2 == 0) goto LAB_0049c218;
    if (cloud_mngt_debug_switch == '\0') goto LAB_0049c1b4;
    __format = "[CLOUD_MNGT_DEBUG]%s()/%d cloud_mngt_obj_send_to_cloud failed\n";
    uVar4 = 0xb19;
  }
  printf(__format,"cloud_mngt_client_handle",uVar4);
LAB_0049c1b4:
  if (iVar1 != 0) {
    json_object_put(iVar1);
  }
  free_ac_cloud_mngt_hash(local_28,1);
  return;
}

