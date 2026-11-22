// func uac_wservice_igmp_white_list_change @ 005e6264 size=300

undefined4 uac_wservice_igmp_white_list_change(void)

{
  void *__s;
  int iVar1;
  undefined4 uVar2;
  byte local_20 [4];
  void *local_1c;
  undefined4 local_18;
  
  local_20[0] = 0;
  local_1c = (void *)0x0;
  local_18 = 0;
  __s = (void *)FUN_00408450(0x380,0x18a9);
  if (__s == (void *)0x0) {
    uVar2 = 0xffffffff;
    if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wserv>[debug]%s(): %d  -> malloc fail\r\n","uac_wservice_igmp_white_list_change",
             0x18ab);
    }
  }
  else {
    memset(__s,0,0x380);
    iVar1 = uac_wservice_igmp_white_list_collect(__s,local_20);
    if (iVar1 == 0) {
      if ((g_wserv_debug != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("<wserv>[debug]%s(): %d  -> ip_num = %d\r\n","uac_wservice_igmp_white_list_change",
               0x18b4,(uint)local_20[0]);
      }
      local_18 = CONCAT13(local_20[0],local_18._1_3_);
      local_1c = __s;
      uVar2 = apmngr_db_foreach_proc
                        (0x15f0000,_uac_wserv_send_igmp_white_list_to_all_ap_cb,&local_1c);
      FUN_00407df0(__s);
    }
    else {
      FUN_00407df0(__s);
      uVar2 = 0xffffffff;
    }
  }
  return uVar2;
}

