// func mesh_jcs_trigger_pair_all @ 004bbfb8 size=468

void mesh_jcs_trigger_pair_all(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  void *__s;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  void *local_24;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = (void *)0x0;
  iVar1 = mesh_db_discover_state_get();
  if (iVar1 == 1) {
    iVar1 = apmngr_db_get_ap_max();
    uVar3 = 0xffffffff;
    __s = (void *)FUN_00408450(iVar1 * 0x140,0x63f);
    local_24 = __s;
    if (__s != (void *)0x0) {
      iVar1 = apmngr_db_get_ap_max();
      memset(__s,0,iVar1 * 0x140);
      FUN_0051ad88(&local_30);
      mesh_db_discover_list_foreach_proc(_mesh_collect_pair_list,&local_30);
      for (iVar1 = FUN_004081b0(&local_30); iVar1 != 0; iVar1 = FUN_00408680(iVar1)) {
        iVar2 = mesh_pkt_re_operation_request_send
                          (*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10),iVar1 + 0x14,0
                          );
        if (iVar2 == 0) {
          iVar2 = mesh_db_discover_pair_state_update(iVar1 + 0x14,*(undefined4 *)(iVar1 + 0x10),1);
          if ((iVar2 != 0) && (mesh_err_switch != '\0')) {
            printf("[MESH_ERROR]%s()/%d Refresh discover pair state failed!\n",
                   "mesh_jcs_trigger_pair_all",0x651);
          }
        }
        else if (mesh_err_switch != '\0') {
          printf("[MESH_ERROR]%s()/%d Send pair request to AP(%d) failed!\n",
                 "mesh_jcs_trigger_pair_all",0x64c,*(undefined4 *)(iVar1 + 0xc));
        }
      }
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xfffffffe;
    if (mesh_debug_switch != '\0') {
      printf("[MESH_DEBUG]%s()/%d You can\'t do dev pair in state(%d),please trigger discover first\n"
             ,"mesh_jcs_trigger_pair_all",0x63a,iVar1);
    }
  }
  if (local_24 != (void *)0x0) {
    FUN_00407df0();
  }
  uVar3 = json_object_new_int(uVar3);
  json_object_object_add(param_2,&DAT_00676a24,uVar3);
  return;
}

