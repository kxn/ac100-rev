// func arp_defend_sqlite_load_ap_service @ 0047918c size=764

undefined4 arp_defend_sqlite_load_ap_service(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *__format;
  undefined4 uVar4;
  int local_830;
  char acStack_82c [1024];
  char acStack_42c [1032];
  
  memset(acStack_42c,0,0x400);
  memset(acStack_82c,0,0x400);
  snprintf(acStack_82c,0x400,
           "CREATE TABLE IF NOT EXISTS %s(ap_id\t\t\t\t\tINTEGER,enable\t\t\t    INTEGER,bind_id_list\t\t\t\tVARCHAR(%d),key  \t\t\t\tINTEGER PRIMARY KEY AUTOINCREMENT)"
           ,"arpDefendAp",DAT_007670f0 * 6);
  iVar1 = FUN_00479080("arpDefendAp",acStack_82c,"ap_id");
  if (iVar1 != 0) {
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Create table %s failed.\n",
             "arp_defend_sqlite_create_ap_table",0x1ad,"arpDefendAp");
    }
    if (arp_defend_err_switch == 0) {
      return 0xffffffff;
    }
    iVar1 = is_target_debug_ap();
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    printf("[ARP_DEFEND_ERROR]%s()/%d Create table failed.\n","arp_defend_sqlite_load_ap_service",
           0x1bd);
    return 0xffffffff;
  }
  iVar2 = FUN_00408130("/etc/nouci_config/dbs/arp_defend.db",&local_830,0);
  iVar1 = 0;
  if (iVar2 != 0) goto LAB_004792bc;
  iVar1 = FUN_004082a0(DAT_007670f0,4,0x1c4);
  if (iVar1 == 0) {
    if ((arp_defend_err_switch == 0) ||
       (iVar3 = is_target_debug_ap(&g_invalid_arp_ap_id), iVar3 == 0)) goto LAB_004792bc;
    __format = "[ARP_DEFEND_ERROR]%s()/%d Not enough memory.\n";
    uVar4 = 0x1c7;
  }
  else {
    iVar2 = apmngr_db_get_ap_max();
    iVar3 = apmngr_db_get_template_max();
    FUN_00408300(&g_invalid_arp_ap_id,&g_invalid_arp_ap_id_pos,iVar2 + iVar3);
    snprintf(acStack_42c,0x400,"select * from %s","arpDefendAp");
    iVar2 = FUN_00407fb0(local_830,acStack_42c,arp_defend_sqlite_ap_cb,iVar1);
    if (iVar2 != 0) {
      iVar3 = FUN_00408410();
      if (iVar3 != 0) {
        printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
               "arp_defend_sqlite_load_ap_service",0x1cf,iVar2,acStack_42c,
               "Failed to read database, select failed.");
      }
      goto LAB_004792bc;
    }
    iVar2 = FUN_00408490(g_invalid_arp_ap_id,g_invalid_arp_ap_id_pos,local_830,"arpDefendAp","ap_id"
                        );
    if (((iVar2 != 0) || (arp_defend_debug_switch == 0)) ||
       (iVar3 = is_target_debug_ap(&g_invalid_arp_ap_id), iVar3 == 0)) goto LAB_004792bc;
    __format = "[ARP_DEFEND_DEBUG]%s()/%d arp_defend_sqlite_load_ap_service() OK.\n";
    uVar4 = 0x1d7;
  }
  printf(__format,"arp_defend_sqlite_load_ap_service",uVar4);
LAB_004792bc:
  FUN_00407de0(&g_invalid_arp_ap_id,&g_invalid_arp_ap_id_pos);
  if (local_830 != 0) {
    FUN_004080b0();
    local_830 = 0;
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  uVar4 = 0xffffffff;
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  return uVar4;
}

