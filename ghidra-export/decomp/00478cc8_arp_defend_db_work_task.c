// func arp_defend_db_work_task @ 00478cc8 size=952

undefined4 arp_defend_db_work_task(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  char *__format;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 local_b8;
  int local_b4;
  undefined4 *local_b0;
  char acStack_ac [132];
  
  local_b4 = 0;
  local_b0 = (undefined4 *)0x0;
  local_b8 = 0;
  iVar2 = FUN_00408130("/etc/nouci_config/dbs/arp_defend.db",&g_arp_defend_db_ptr,0);
  if (iVar2 != 0) {
    if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[ARP_DEFEND_ERROR]%s()/%d open database failed.\n","arp_defend_db_work_task",0x8d7);
    }
    return 0;
  }
LAB_00478d84:
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          while( true ) {
            iVar2 = FUN_00408250(g_arp_defend_msgq,&local_b4,8,0xffffffff,&local_b8);
            if (iVar2 == -1) goto LAB_00478eb4;
            if (local_b4 != 1) break;
            if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
              printf("[ARP_DEFEND_DEBUG]%s()/%d ARP_DEFEND_DB_UPDATE msg.\n",
                     "arp_defend_db_work_task",0x8ed);
            }
            arp_defend_db_sqlite_ap_update(local_b0);
          }
          if (local_b4 != 0) break;
          if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[ARP_DEFEND_DEBUG]%s()/%d ARP_DEFEND_DB_INSERT msg.\n","arp_defend_db_work_task"
                   ,0x8e8);
          }
          arp_defend_db_sqlite_ap_insert(local_b0);
        }
        if (local_b4 == 4) break;
        if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[ARP_DEFEND_DEBUG]%s()/%d unknown msg type:%d.\n","arp_defend_db_work_task",0x8f7,
                 local_b4);
        }
      }
      if ((arp_defend_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[ARP_DEFEND_DEBUG]%s()/%d ARP_DEFEND_DB_DELETE msg.\n","arp_defend_db_work_task",
               0x8f2);
      }
      puVar1 = local_b0;
      memset(acStack_ac,0,0x80);
      iVar2 = g_arp_defend_db_ptr;
      if (puVar1 == (undefined4 *)0x0) break;
      if (g_arp_defend_db_ptr == 0) {
        if ((arp_defend_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          printf("[ARP_DEFEND_ERROR]%s()/%d open db failed.\n","arp_defend_db_sqlite_ap_delete",
                 0x2f2);
        }
      }
      else {
        if ((arp_defend_debug_switch != 0) && (iVar3 = is_target_debug_ap(), iVar3 != 0)) {
          printf("[ARP_DEFEND_DEBUG]%s()/%d ap_id:%d\n","arp_defend_db_sqlite_ap_delete",0x2f6,
                 *puVar1);
        }
        snprintf(acStack_ac,0x80,"DELETE FROM %s WHERE ap_id = %d","arpDefendAp",*puVar1);
        iVar2 = FUN_00407d60(iVar2,acStack_ac);
        if ((iVar2 != 0) && (iVar3 = FUN_00408410(), iVar3 != 0)) {
          printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                 "arp_defend_db_sqlite_ap_delete",0x2fc,iVar2,acStack_ac,
                 "Failed to delete ap entry from table in flash.");
        }
      }
      FUN_00407df0(puVar1);
    }
  } while ((arp_defend_err_switch == 0) || (iVar2 = is_target_debug_ap(), iVar2 == 0));
  __format = "[ARP_DEFEND_ERROR]%s()/%d Wrong value, failed to delete entry.\n";
  uVar5 = 0x2ec;
  pcVar4 = "arp_defend_db_sqlite_ap_delete";
  goto LAB_00478eec;
LAB_00478eb4:
  perror("");
  if ((arp_defend_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    uVar5 = 0x8e1;
    __format = "[ARP_DEFEND_WARNING]%s()/%d receive msgs error\n\n";
    pcVar4 = "arp_defend_db_work_task";
LAB_00478eec:
    printf(__format,pcVar4,uVar5);
  }
  goto LAB_00478d84;
}

