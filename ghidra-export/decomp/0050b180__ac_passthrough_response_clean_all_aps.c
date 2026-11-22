// func _ac_passthrough_response_clean_all_aps @ 0050b180 size=184

undefined4 _ac_passthrough_response_clean_all_aps(undefined4 param_1)

{
  undefined4 local_18 [2];
  
  local_18[0] = 0;
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d lock ac_passthrough_get_reponse_mutex\n",
           "_ac_passthrough_response_clean_all_aps",0x5eb);
  }
  FUN_004082d0(ac_passthrough_get_reponse_mutex,0xffffffff);
  local_18[0] = param_1;
  FUN_00408570(ac_passthrough_response_result_hash,
               _ac_passthrough_response_clean_all_aps_one_hash_node,local_18);
  if (ac_passthrough_info_switch != '\0') {
    printf("[AC_PASSTHROUGH_INFO]%s()/%d unlock ac_passthrough_get_reponse_mutex\n",
           "_ac_passthrough_response_clean_all_aps",0x5ee);
  }
  FUN_00407f30(ac_passthrough_get_reponse_mutex);
  return 0;
}

