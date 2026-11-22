// func FUN_0060ee8c @ 0060ee8c size=144

void FUN_0060ee8c(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_10 [2];
  
  local_10[0] = 0;
  puVar1 = (undefined4 *)cw_msg_ele_val_get(param_1,0x21);
  if (puVar1 == (undefined4 *)0x0) {
    local_10[0] = 1;
    iVar2 = cw_service_msg_add(param_1,0x21,local_10,0);
    if ((iVar2 == -1) && (apdb_err_switch != 0)) {
      printf("[APDB_ERROR]%s()/line %d : add result code failed.\n","_apdb_pkt_result_code_set_err",
             0x1a3);
    }
  }
  else {
    *puVar1 = 1;
  }
  return;
}

