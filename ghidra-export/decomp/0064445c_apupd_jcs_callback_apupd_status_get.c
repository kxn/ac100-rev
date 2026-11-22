// func apupd_jcs_callback_apupd_status_get @ 0064445c size=200

void apupd_jcs_callback_apupd_status_get(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18 [3];
  
  local_18[0] = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_jcs_callback_apupd_status_get",
             0xb8e);
    }
  }
  else {
    iVar1 = apupd_db_status_get_by_state(local_18);
    if (iVar1 != -1) {
      uVar2 = json_object_new_int(local_18[0]);
      json_object_object_add(param_2,"status",uVar2);
    }
    uVar2 = json_object_new_int(iVar1 == -1);
    json_object_object_add(param_2,&DAT_00676a24,uVar2);
  }
  return;
}

