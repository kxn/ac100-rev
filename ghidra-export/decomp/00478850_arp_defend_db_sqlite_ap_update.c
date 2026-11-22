// func arp_defend_db_sqlite_ap_update @ 00478850 size=592

undefined4 arp_defend_db_sqlite_ap_update(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined1 auStack_420 [1032];
  
  memset(auStack_420,0,0x401);
  iVar2 = g_arp_defend_db_ptr;
  if (param_1 == (undefined4 *)0x0) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[ARP_DEFEND_ERROR]%s()/%d Wrong value, failed to insert ap entry into ap table.\n",
           "arp_defend_db_sqlite_ap_update",699);
    return 0xffffffff;
  }
  if (g_arp_defend_db_ptr == 0) {
    iVar2 = -1;
    if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_00478944;
    __format = "[ARP_DEFEND_ERROR]%s()/%d open db failed.\n";
    uVar3 = 0x2c1;
  }
  else {
    iVar1 = FUN_00478638(param_1[3],DAT_007670f0,auStack_420);
    if (iVar1 < 0) {
      iVar2 = -1;
      if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_00478944;
      __format = "[ARP_DEFEND_ERROR]%s()/%d _arp_defend_arpids2str() fail\n";
      uVar3 = 0x2c8;
    }
    else {
      memset(&arp_defend_cmd_str,0,0x401);
      snprintf(&arp_defend_cmd_str,0x400,
               "UPDATE arpDefendAp SET bind_id_list = \'%s\' WHERE ap_id = \'%d\';",auStack_420,
               *param_1);
      if ((arp_defend_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        printf("[ARP_DEFEND_DEBUG]%s()/%d sql:%s, ap_id:%d\n","arp_defend_db_sqlite_ap_update",0x2d5
               ,&arp_defend_cmd_str,*param_1);
      }
      iVar2 = FUN_00407d60(iVar2,&arp_defend_cmd_str);
      if (iVar2 != 0) {
        iVar1 = FUN_00408410();
        if (iVar1 != 0) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "arp_defend_db_sqlite_ap_update",0x2d6,iVar2,&arp_defend_cmd_str,
                 "Failed to update bind_id_list.");
        }
        goto LAB_00478944;
      }
      if ((arp_defend_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
      goto LAB_00478944;
      __format = "[ARP_DEFEND_DEBUG]%s()/%d arp_defend_db_sqlite_ap_update() OK.\n";
      uVar3 = 0x2d8;
    }
  }
  printf(__format,"arp_defend_db_sqlite_ap_update",uVar3);
LAB_00478944:
  FUN_00407df0(param_1);
  uVar3 = 0xffffffff;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  return uVar3;
}

