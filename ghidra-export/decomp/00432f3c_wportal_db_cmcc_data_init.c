// func wportal_db_cmcc_data_init @ 00432f3c size=512

undefined4 wportal_db_cmcc_data_init(void)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  
  wportal_cmcc_serialno_mutex = FUN_00407f00("wportal_cmcc_serialno_mutex",1);
  if (wportal_cmcc_serialno_mutex == 0) {
    if (wportal_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    __format = "[WPORTAL_ERR]%s()/%d Create wportal_cmcc_mutex failed.\n";
    uVar2 = 0x1958;
  }
  else {
    cmcc_serialno_tree =
         FUN_00407dc0(_cmcc_serial_sort_func,_cmcc_serial_compare_func,_cmcc_serial_destroy_func);
    if (cmcc_serialno_tree == 0) {
      if (wportal_err_switch == 0) {
        return 0xffffffff;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 0xffffffff;
      }
      __format = "[WPORTAL_ERR]%s()/%d Create cmcc_serialno_tree failed.\n";
      uVar2 = 0x195f;
    }
    else {
      cmcc_serialno_list = FUN_00408450(0xc,0x1963);
      if (cmcc_serialno_list == 0) {
        if (wportal_err_switch == 0) {
          return 0xffffffff;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0xffffffff;
        }
        __format = "[WPORTAL_ERR]%s()/%d Create cmcc_serialno_list failed.\n";
        uVar2 = 0x1966;
      }
      else {
        FUN_0051ad88(cmcc_serialno_list);
        cmcc_serialno_node_num = 0;
        wportal_cmcc_waitque_mutex = FUN_00407f00("wportal_cmcc_serialno_wq_mutex",1);
        if (wportal_cmcc_waitque_mutex == 0) {
          if (wportal_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "[WPORTAL_ERR]%s()/%d Create wportal_cmcc_waitque_mutex failed.\n";
          uVar2 = 0x1972;
        }
        else {
          cmcc_wq_tree = FUN_00407dc0(_cmcc_wq_sort_func,_cmcc_wq_compare_func,_cmcc_wq_destroy_func
                                     );
          if (cmcc_wq_tree != 0) {
            cmcc_wq_node_num = 0;
            return 0;
          }
          if (wportal_err_switch == 0) {
            return 0xffffffff;
          }
          iVar1 = is_target_debug_ap();
          if (iVar1 == 0) {
            return 0xffffffff;
          }
          __format = "[WPORTAL_ERR]%s()/%d Create cmcc_wq_tree failed.\n";
          uVar2 = 0x1979;
        }
      }
    }
  }
  printf(__format,"wportal_db_cmcc_data_init",uVar2);
  return 0xffffffff;
}

