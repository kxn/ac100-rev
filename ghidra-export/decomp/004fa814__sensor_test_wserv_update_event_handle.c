// func _sensor_test_wserv_update_event_handle @ 004fa814 size=464

/* WARNING: Type propagation algorithm not settling */

undefined4
_sensor_test_wserv_update_event_handle
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 local_res0;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 in_stack_00000080;
  int local_800 [3];
  byte bStack_7f2;
  undefined4 local_7f4;
  int local_7f0;
  int local_7ec;
  undefined4 local_7e8 [501];
  
  local_res0 = param_1;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  if (sensor_test_debug_switch != '\0') {
    printf("[SENSOR_TEST_DEBUG]%s()/%d wserv_update_event_handle ENTER\n",
           "_sensor_test_wserv_update_event_handle",0x8ed);
  }
  memset(local_7e8,0,2000);
  local_800[0] = 0;
  local_800[1] = 0;
  local_800[2] = 0;
  local_7f4 = 0;
  local_7f0 = 0;
  local_7ec = 0;
  iVar1 = sensor_test_db_get_case_id_list_by_serv(in_stack_00000080,local_7e8,local_800);
  if (iVar1 != -1) {
    puVar4 = local_7e8;
    sensor_test_db_wserv_id_update(&local_res0,local_7e8,local_800[0]);
    iVar1 = 0;
    while (iVar1 < local_800[0]) {
      iVar2 = sensor_test_db_get_case_brief_info(*puVar4,local_800 + 1);
      if (iVar2 == -1) {
        if (local_7ec != 0) {
          FUN_00407df0();
          local_7ec = 0;
        }
        if (local_7f0 == 0) goto LAB_004fa968;
        FUN_00407df0();
        local_7f0 = 0;
        puVar4 = puVar4 + 1;
        iVar1 = iVar1 + 1;
      }
      else {
        if ((bStack_7f2 != '\0') && (iVar2 = 0, local_7f0 != 0)) {
          do {
            while( true ) {
              if ((int)(uint)bStack_7f2 <= iVar2) goto LAB_004fa928;
              puVar3 = (undefined2 *)(local_7f0 + iVar2 * 4);
              if (*(char *)(puVar3 + 1) == '\0') break;
              iVar2 = iVar2 + 1;
              _sensor_test_sync_case_config_to_sensor(*puVar3,*puVar4,2);
            }
            iVar2 = iVar2 + 1;
          } while( true );
        }
LAB_004fa928:
        if (local_7ec != 0) {
          FUN_00407df0();
          local_7ec = 0;
        }
        if (local_7f0 != 0) {
          FUN_00407df0();
        }
        local_800[1] = 0;
        local_800[2] = 0;
        local_7f4 = 0;
        local_7f0 = 0;
        local_7ec = 0;
LAB_004fa968:
        puVar4 = puVar4 + 1;
        iVar1 = iVar1 + 1;
      }
    }
  }
  return 0;
}

