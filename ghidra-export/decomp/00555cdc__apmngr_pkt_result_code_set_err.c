// func _apmngr_pkt_result_code_set_err @ 00555cdc size=164

void _apmngr_pkt_result_code_set_err(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_18 [3];
  
  local_18[0] = 0;
  puVar1 = (undefined4 *)cw_msg_ele_val_get(param_1,0x21);
  if (puVar1 == (undefined4 *)0x0) {
    local_18[0] = param_2;
    iVar2 = cw_service_msg_add(param_1,0x21,local_18,0);
    if (((iVar2 == -1) && (apmngr_err_switch != '\0')) && (iVar2 = is_target_debug_ap(), iVar2 != 0)
       ) {
      printf("[APMNGR_ERROR]%s()/%d add result code failed.\n","_apmngr_pkt_result_code_set_err",
             0x14f);
    }
  }
  else {
    *puVar1 = param_2;
  }
  return;
}

