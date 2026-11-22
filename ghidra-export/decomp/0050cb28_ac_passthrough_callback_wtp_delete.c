// func ac_passthrough_callback_wtp_delete @ 0050cb28 size=612

undefined4 ac_passthrough_callback_wtp_delete(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    return 0xffffffff;
  }
  if (ac_passthrough_response_result_hash == 0) {
    return 0;
  }
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
           "ac_passthrough_node_delete",0x427);
  }
  FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
  iVar1 = FUN_00407fa0(ac_passthrough_response_result_hash,param_1 + 0x48);
  if (iVar1 == 0) {
    if (ac_passthrough_debug_switch != '\0') {
      printf("[AC_PASSTHROUGH_DEBUG]%s()/%d param mac:%02x-%02x-%02x-%02x-%02x -%02x \n",
             "ac_passthrough_node_delete",0x42d,(int)*(char *)(param_1 + 0x48),
             (int)*(char *)(param_1 + 0x49),(int)*(char *)(param_1 + 0x4a),
             (int)*(char *)(param_1 + 0x4b),(int)*(char *)(param_1 + 0x4c),
             (int)*(char *)(param_1 + 0x4d));
    }
    if (ac_passthrough_info_switch == '\0') goto LAB_0050cc58;
    uVar3 = 0x42e;
  }
  else {
    if (ac_passthrough_response_result_hash == 0) {
      if (ac_passthrough_err_switch != '\0') {
        printf("[AC_PASSTHROUGH_ERROR]%s()/%d inputs error.\n","ac_passthrough_node_entry_delete",
               0x407);
      }
    }
    else {
      iVar2 = FUN_00407f40(ac_passthrough_response_result_hash,iVar1);
      if (iVar2 == 0) {
        if (ac_passthrough_debug_switch != '\0') {
          printf("[AC_PASSTHROUGH_DEBUG]%s()/%d remove  ap: :%02x-%02x-%02x-%02x-%02x -%02x from hash success.\n"
                 ,"ac_passthrough_node_entry_delete",0x413,(uint)*(byte *)(iVar1 + 0x10),
                 (uint)*(byte *)(iVar1 + 0x11),(uint)*(byte *)(iVar1 + 0x12),
                 (uint)*(byte *)(iVar1 + 0x13),(uint)*(byte *)(iVar1 + 0x14),
                 (uint)*(byte *)(iVar1 + 0x15));
        }
        free_reponse_from_list(iVar1);
        FUN_00407df0(iVar1);
        if (ac_passthrough_info_switch == '\0') goto LAB_0050cc58;
        uVar3 = 0x43b;
        goto LAB_0050cc50;
      }
      if (ac_passthrough_err_switch != '\0') {
        printf("[AC_PASSTHROUGH_ERROR]%s()/%d remove  ap: :%02x-%02x-%02x-%02x-%02x -%02x from hash failed.\n"
               ,"ac_passthrough_node_entry_delete",0x40e,(uint)*(byte *)(iVar1 + 0x10),
               (uint)*(byte *)(iVar1 + 0x11),(uint)*(byte *)(iVar1 + 0x12),
               (uint)*(byte *)(iVar1 + 0x13),(uint)*(byte *)(iVar1 + 0x14),
               (uint)*(byte *)(iVar1 + 0x15));
      }
    }
    if (ac_passthrough_info_switch == '\0') goto LAB_0050cc58;
    uVar3 = 0x434;
  }
LAB_0050cc50:
  printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
         "ac_passthrough_node_delete",uVar3);
LAB_0050cc58:
  FUN_00407f30(ac_passthrough_get_reponse_mutex);
  return 0;
}

