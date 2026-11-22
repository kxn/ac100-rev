// func arp_defend_sqlite_load_arp_service @ 00479488 size=500

undefined4 arp_defend_sqlite_load_arp_service(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_818;
  char acStack_814 [1024];
  char acStack_414 [1028];
  
  memset(acStack_414,0,0x400);
  memset(acStack_814,0,0x400);
  snprintf(acStack_814,0x400,
           "CREATE TABLE IF NOT EXISTS %s(arp_id\t\t\t\t\tINTEGER,ip\t\t\t\t    VARCHAR(40),mac\t\t\t\t    VARCHAR(17),description\t\t        VARCHAR(128),key\t\t\t\t\tINTEGER PRIMARY KEY AUTOINCREMENT)"
           ,"arpDefendArp");
  iVar1 = FUN_00479080("arpDefendArp",acStack_814,"arp_id");
  if (iVar1 == 0) {
    iVar1 = FUN_00408130("/etc/nouci_config/dbs/arp_defend.db",&local_818,0);
    if (iVar1 == 0) {
      snprintf(acStack_414,0x400,"select * from %s","arpDefendArp");
      iVar1 = FUN_00407fb0(local_818,acStack_414,arp_defend_sqlite_arp_cb,0);
      if (iVar1 == 0) {
        if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[ARP_DEFEND_DEBUG]%s()/%d arp_defend_sqlite_load_arp_service() OK.\n",
                 "arp_defend_sqlite_load_arp_service",0x275);
        }
      }
      else {
        iVar2 = FUN_00408410();
        if (iVar2 != 0) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "arp_defend_sqlite_load_arp_service",0x273,iVar1,acStack_414,
                 "Failed to read database, select failed.");
        }
      }
    }
    uVar3 = 0xffffffff;
    if (local_818 != 0) {
      FUN_004080b0();
    }
    if (iVar1 == 0) {
      uVar3 = 0;
    }
  }
  else if (arp_defend_err_switch == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    iVar1 = is_target_debug_ap();
    if (iVar1 != 0) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Create table %s failed.\n",
             "arp_defend_sqlite_create_arp_table",0x25a,"arpDefendArp");
    }
    uVar3 = 0xffffffff;
    if ((arp_defend_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d Create table failed.\n","arp_defend_sqlite_load_arp_service"
             ,0x269);
    }
  }
  return uVar3;
}

