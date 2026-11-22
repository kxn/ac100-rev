// func wserv_db_rd_unbind_due_to_freq_change @ 005f3ec8 size=580

undefined4 wserv_db_rd_unbind_due_to_freq_change(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  uint uVar4;
  undefined4 local_238;
  byte local_234;
  undefined3 uStack_233;
  undefined1 auStack_230 [287];
  int local_111;
  
  uVar4 = 1;
  local_238 = 0;
  uStack_233 = 0;
  local_234 = 0;
  memset(auStack_230,0,0x205);
LAB_005f3f34:
  do {
    while( true ) {
      uVar1 = rdmngr_profile_get_max_wlan_per_rd();
      if (uVar1 < uVar4) {
        return 0;
      }
      uVar1 = wserv_db_rd_get_wserv_id(param_1,uVar4 & 0xff);
      if ((-1 < (int)uVar1) && (uVar1 < l_wserv_profile)) break;
      if (g_wserv_debug == 0) {
        uVar4 = uVar4 + 1;
      }
      else {
        iVar2 = is_target_debug_ap();
        if (iVar2 == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          uVar3 = 0xebc;
          __format = "<wserv>[debug]%s(): %d  -> invalid wserv_id[%d]!\r\n";
LAB_005f3fd0:
          printf(__format,"wserv_db_rd_unbind_due_to_freq_change",uVar3,uVar1);
          uVar4 = uVar4 + 1;
        }
      }
    }
    if (param_2 != 0) {
LAB_005f3f74:
      if ((g_wserv_debug != 0) && (iVar2 = is_target_debug_ap(param_1), iVar2 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> unbind rd rd_id[%d] wserv_id[%d]\r\n",
               "wserv_db_rd_unbind_due_to_freq_change",0xec2,param_1,uVar1);
      }
      iVar2 = wserv_db_wlanid_get_by_wservid(param_1,uVar1);
      if (iVar2 == -1) {
        if (g_wserv_warning == 0) {
          uVar4 = uVar4 + 1;
        }
        else {
          iVar2 = is_target_debug_ap();
          if (iVar2 != 0) {
            uVar3 = 0xec6;
            __format = 
            "<wserv>[warning]%s(): %d  -> wserv_db_wlanid_get_by_wservid() fail. wserv_id[%d]\r\n";
            goto LAB_005f3fd0;
          }
          uVar4 = uVar4 + 1;
        }
      }
      else {
        local_234 = (byte)iVar2;
        local_238 = param_1;
        iVar2 = wserv_sqlite_notify(3,&local_238,8);
        if (((iVar2 != 0) && (g_wserv_error != 0)) &&
           (iVar2 = is_target_debug_ap(param_1), iVar2 != 0)) {
          printf("<wserv>[error]%s(): %d  -> wserv_sqlite_notify() unbind fail. rd_id=%d, wlan_id=%d!\r\n"
                 ,"wserv_db_rd_unbind_due_to_freq_change",0xecf,local_238,(uint)local_234);
        }
        wserv_db_rd_unbind(param_1,uVar1,param_3);
        uVar4 = uVar4 + 1;
      }
      goto LAB_005f3f34;
    }
    iVar2 = wserv_db_get_entry_by_id(uVar1,auStack_230);
    if (iVar2 == 0) {
      if (local_111 != 0) goto LAB_005f3f74;
      uVar4 = uVar4 + 1;
    }
    else {
      uVar4 = uVar4 + 1;
    }
  } while( true );
}

