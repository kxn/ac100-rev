// func collect_recover_rdentry_from_ap @ 005dcef0 size=380

int collect_recover_rdentry_from_ap(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  undefined2 local_20;
  undefined2 local_1e;
  
  iVar5 = 1;
  if ((param_1 != 0) && (iVar5 = 0, *(int *)(param_1 + 0x3c) != 0)) {
    local_20 = *(undefined2 *)(param_1 + 0x44);
    iVar5 = 1;
    local_1e = *(undefined2 *)(param_1 + 0x46);
    iVar1 = uac_wservice_get_ap_radio_cnt(*(undefined4 *)(param_1 + 0x40),param_1 + 0x218,&local_20)
    ;
    if (iVar1 < 0) {
      if ((g_wserv_error != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
        printf("<wserv>[error]%s(): %d  -> uac_wservice_get_ap_radio_cnt() fail, ret=%d.\r\n",
               "collect_recover_rdentry_from_ap",0x16d5,iVar1);
      }
    }
    else {
      for (; iVar5 <= iVar1; iVar5 = iVar5 + 1) {
        uVar2 = rdmngr_db_generate_rd_id(*(undefined2 *)(param_1 + 0x10),iVar5);
        iVar3 = wserv_db_is_rd_entry_firm(uVar2);
        if (iVar3 == 0) {
          if (g_wserv_error == 0) {
            uVar4 = *(undefined2 *)(param_1 + 0x10);
          }
          else {
            iVar5 = is_target_debug_ap();
            if (iVar5 == 0) {
              uVar4 = *(undefined2 *)(param_1 + 0x10);
            }
            else {
              printf("<wserv>[error]%s(): %d  -> AP %d\'s rdentry %d missed,need to fix.\r\n",
                     "collect_recover_rdentry_from_ap",0x16dd,(uint)*(ushort *)(param_1 + 0x10),
                     uVar2);
              uVar4 = *(undefined2 *)(param_1 + 0x10);
            }
          }
          wserv_db_ap_del(uVar4,iVar1);
          wserv_db_ap_connect(*(undefined2 *)(param_1 + 0x10),iVar1);
          _uac_wserv_ap_firm_cb(param_1);
          if (param_2 == (undefined4 *)0x0) {
            return 0;
          }
          *param_2 = 1;
          return 0;
        }
      }
      iVar5 = 0;
    }
  }
  return iVar5;
}

