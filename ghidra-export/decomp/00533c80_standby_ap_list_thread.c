// func standby_ap_list_thread @ 00533c80 size=300

void standby_ap_list_thread(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 auStack_38 [16];
  undefined8 local_28;
  
  do {
    FUN_004082d0(apmngr_standby_list_mutex,0xffffffff);
    while (iVar1 = FUN_00407ed0(g_apmngr_standby_hash), iVar1 < 1) {
      FUN_004086c0(apmngr_standby_list_cond,apmngr_standby_list_mutex,0xffffffff);
    }
    uVar2 = FUN_00407e70();
    local_28 = uVar2;
    FUN_0051ad88(auStack_38);
    FUN_00408570(g_apmngr_standby_hash,standby_ap_list_hash_node,auStack_38);
    iVar1 = FUN_004081b0(auStack_38);
    while (iVar1 != 0) {
      FUN_00407f40(g_apmngr_standby_hash,*(undefined4 *)(iVar1 + 0x14));
      FUN_00407df0(*(undefined4 *)(iVar1 + 0x14));
      *(undefined4 *)(iVar1 + 0x14) = 0;
      iVar1 = FUN_00408680(iVar1);
    }
    FUN_00407f30(apmngr_standby_list_mutex);
    while (iVar1 = FUN_004081b0(auStack_38), iVar1 != 0) {
      FUN_00408500(iVar1);
      multi_link_status_switch_by_inner(*(undefined2 *)(iVar1 + 0x12),1,1,0,0,0);
      FUN_00407df0(iVar1);
    }
    sleep(10);
  } while( true );
}

