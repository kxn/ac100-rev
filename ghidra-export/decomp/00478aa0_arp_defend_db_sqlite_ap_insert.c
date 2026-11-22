// func arp_defend_db_sqlite_ap_insert @ 00478aa0 size=552

undefined4 arp_defend_db_sqlite_ap_insert(undefined4 *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *__format;
  undefined1 auStack_418 [1032];
  
  memset(auStack_418,0,0x401);
  iVar3 = g_arp_defend_db_ptr;
  if (param_1 == (undefined4 *)0x0) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar3 = is_target_debug_ap();
    if (iVar3 == 0) {
      return 0xffffffff;
    }
    printf("[ARP_DEFEND_ERROR]%s()/%d Wrong value, failed to insert ap entry into ap table.\n",
           "arp_defend_db_sqlite_ap_insert",0x287);
    return 0xffffffff;
  }
  if (g_arp_defend_db_ptr == 0) {
    iVar3 = -1;
    if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_00478b78;
    __format = "[ARP_DEFEND_ERROR]%s()/%d open db failed.\n";
    uVar4 = 0x28d;
  }
  else if (((int)param_1[2] < 1) ||
          (iVar1 = FUN_00478638(param_1[3],DAT_007670f0,auStack_418), -1 < iVar1)) {
    memset(&arp_defend_cmd_str,0,0x401);
    if (param_1[2] == 0) {
      puVar2 = &DAT_00688af8;
    }
    else {
      puVar2 = auStack_418;
    }
    snprintf(&arp_defend_cmd_str,0x401,"INSERT INTO %s VALUES( %d, %d, \'%s\', null);","arpDefendAp"
             ,*param_1,(uint)*(byte *)(param_1 + 1),puVar2);
    iVar3 = FUN_00407d60(iVar3,&arp_defend_cmd_str);
    if (iVar3 != 0) {
      iVar1 = FUN_00408410();
      if (iVar1 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
               "arp_defend_db_sqlite_ap_insert",0x2a5,iVar3,&arp_defend_cmd_str,
               "Failed to insert into ap table in flash.");
      }
      goto LAB_00478b78;
    }
    if ((arp_defend_debug_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_00478b78;
    __format = "[ARP_DEFEND_DEBUG]%s()/%d arp_defend_db_sqlite_ap_insert() OK.\n";
    uVar4 = 0x2a7;
  }
  else {
    iVar3 = -1;
    if ((arp_defend_err_switch == 0) || (iVar1 = is_target_debug_ap(), iVar1 == 0))
    goto LAB_00478b78;
    __format = "[ARP_DEFEND_ERROR]%s()/%d _arp_defend_arpids2str() fail\n";
    uVar4 = 0x297;
  }
  printf(__format,"arp_defend_db_sqlite_ap_insert",uVar4);
LAB_00478b78:
  FUN_00407df0(param_1);
  uVar4 = 0xffffffff;
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  return uVar4;
}

