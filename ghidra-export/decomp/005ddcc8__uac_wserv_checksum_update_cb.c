// func _uac_wserv_checksum_update_cb @ 005ddcc8 size=616

undefined4 _uac_wserv_checksum_update_cb(int param_1,code *param_2,int param_3)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 uVar3;
  code *local_20;
  int local_1c;
  
  local_20 = (code *)0x0;
  local_1c = 0;
  if (((param_1 == 0) || (param_2 == (code *)0x0)) || (param_3 == 0)) {
    uVar3 = 2;
    if (g_wserv_error == 0) {
      return 2;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 2;
    }
    __format = "<wserv>[error]%s(): %d  -> invalid args.\r\n";
    uVar2 = 0x1401;
  }
  else if (*(int *)(param_1 + 0x14) == 5) {
    uVar3 = 0;
    if (g_wserv_debug == 0) {
      return 0;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0;
    }
    __format = "<wserv>[debug]%s(): %d  -> Sub dev do not need to calculate wservice.\r\n";
    uVar2 = 0x1406;
  }
  else {
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> ap_id=%d, calc checksum begin.\r\n",
             "_uac_wserv_checksum_update_cb",0x140a,(uint)*(ushort *)(param_1 + 0x10));
    }
    local_20 = param_2;
    local_1c = param_3;
    iVar1 = uac_wservice_for_each_entry_bind_ap
                      (*(undefined2 *)(param_1 + 0x10),_uac_wserv_for_each_entry_checksum_calc,
                       &local_20);
    if (iVar1 == 0) {
      iVar1 = wserv_db_ip_checksum_calc(*(undefined2 *)(param_1 + 0x10),param_2,param_3);
      if (iVar1 == 0) {
        iVar1 = apmngr_db_capacity_support(*(undefined2 *)(param_1 + 0x10),1,0x41);
        if (iVar1 != 0) {
          if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
            printf("<wserv>[debug]%s(): %d  -> region code calc\r\n","_uac_wserv_checksum_update_cb"
                   ,0x141c);
          }
          (*param_2)(param_3,param_1 + 0x2d1,1);
        }
        if (g_wserv_debug == 0) {
          return 0;
        }
        iVar1 = is_target_debug_ap();
        if (iVar1 == 0) {
          return 0;
        }
        printf("<wserv>[debug]%s(): %d  -> ap_id=%d, calc checksum finish.\r\n",
               "_uac_wserv_checksum_update_cb",0x1421,(uint)*(ushort *)(param_1 + 0x10));
        return 0;
      }
      uVar3 = 2;
      if (g_wserv_error == 0) {
        return 2;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 2;
      }
      __format = "<wserv>[error]%s(): %d  -> wserv_db_ip_checksum_calc() fail.\r\n";
      uVar2 = 0x1416;
    }
    else {
      uVar3 = 2;
      if (g_wserv_error == 0) {
        return 2;
      }
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        return 2;
      }
      __format = "<wserv>[error]%s(): %d  -> uac_wservice_for_each_entry_bind_ap() fail.\r\n";
      uVar2 = 0x1410;
    }
  }
  printf(__format,"_uac_wserv_checksum_update_cb",uVar2);
  return uVar3;
}

