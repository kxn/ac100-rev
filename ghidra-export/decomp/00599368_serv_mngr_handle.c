// func serv_mngr_handle @ 00599368 size=392

int serv_mngr_handle(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar2 = -1;
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","serv_mngr_handle",0x11c,
           "(NULL != parsed_pkt) && (NULL != basic)");
  }
  else {
    iVar2 = serv_msg_mngr_get(*(undefined4 *)(param_1 + 0x10));
    if (iVar2 == 0) {
      iVar2 = -1;
      if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[CW_ERROR]%32s():%4d get message manager of message type[%d] failed\n",
               "serv_mngr_handle",0x122,*(undefined4 *)(param_1 + 0x10));
      }
    }
    else {
      if (*(int *)(param_1 + 0x10) == 3) {
        if (param_3 == 0) {
          return -1;
        }
        iVar1 = add_rslt_code_to_parsed_pkt(param_3);
        if (iVar1 == -1) {
          if (capwap_err_switch == 0) {
            return -1;
          }
          iVar2 = is_target_debug_ap();
          if (iVar2 == 0) {
            return -1;
          }
          printf("[CW_ERROR]%32s():%4d add result code failed\n","serv_mngr_handle",0x12f);
          return -1;
        }
      }
      else {
        serv_mngr_handle_for_child(param_1,param_2,param_3);
      }
      for (iVar2 = FUN_004081b0(iVar2 + 4); iVar2 != 0; iVar2 = FUN_00408680(iVar2)) {
        if (*(code **)(iVar2 + 0x10) != (code *)0x0) {
          (**(code **)(iVar2 + 0x10))(param_1,param_2,param_3);
        }
      }
    }
  }
  return iVar2;
}

