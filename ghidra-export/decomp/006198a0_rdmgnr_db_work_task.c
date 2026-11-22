// func rdmgnr_db_work_task @ 006198a0 size=1144

undefined4 rdmgnr_db_work_task(void)

{
  undefined4 *puVar1;
  int iVar2;
  char *__format;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 *local_b0;
  char acStack_ac [132];
  
  local_b4 = 0;
  local_b0 = (undefined4 *)0x0;
  local_b8 = 0;
  iVar2 = FUN_00408130("/etc/nouci_config/dbs/rdmngr.db",&g_rdmngr_db_ptr,
                       uac_cfg_trigger_changed_by_restore);
  if (iVar2 != 0) {
    if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[RDMNGR_ERROR]%s()/%d open database failed.\n","rdmgnr_db_work_task",0x1235);
    }
    return 0;
  }
LAB_00619958:
  do {
    iVar2 = FUN_00408250(g_rdmngr_msgq,&local_b4,8,0xffffffff,&local_b8);
    if (iVar2 == -1) break;
    switch(local_b4) {
    case 0:
      if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d RDMNGR_DB_INSERT msg.\n","rdmgnr_db_work_task",0x1246);
      }
      rdmngr_db_sqlite_rd_insert(local_b0);
      break;
    case 1:
      if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d RDMNGR_DB_LINKED_UPDATE msg.\n","rdmgnr_db_work_task",0x124a);
      }
      rdmngr_db_sqlite_rd_linked_update(local_b0);
      break;
    case 2:
      if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d RDMNGR_DB_MULTI_UPDATE msg.\n","rdmgnr_db_work_task",0x124e);
      }
      rdmngr_db_sqlite_rd_cfg_update(local_b0);
      break;
    case 3:
      if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d RDMNGR_DB_STATUS_UPDATE msg.\n","rdmgnr_db_work_task",0x1252);
      }
      rdmngr_db_sqlite_rd_status_update(local_b0);
      break;
    case 4:
      if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d RDMNGR_DB_DELETE msg.\n","rdmgnr_db_work_task",0x1256);
      }
      puVar1 = local_b0;
      memset(acStack_ac,0,0x80);
      iVar2 = g_rdmngr_db_ptr;
      if (puVar1 == (undefined4 *)0x0) {
        if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
          __format = "[RDMNGR_ERROR]%s()/%d Wrong value, failed to delete entry.\n";
          pcVar3 = "rdmngr_db_sqlite_rd_delete";
          uVar4 = 0x35e;
          goto LAB_00619afc;
        }
      }
      else {
        if (g_rdmngr_db_ptr == 0) {
          if ((rdmngr_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
            printf("[RDMNGR_ERROR]%s()/%d open db failed.\n","rdmngr_db_sqlite_rd_delete",0x364);
          }
        }
        else {
          if ((rdmngr_debug_switch != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
            printf("[RDMNGR_DEBUG]%s()/%d rd_id:%d, isFirm:%d\n","rdmngr_db_sqlite_rd_delete",0x368,
                   *puVar1,puVar1[1]);
          }
          iVar5 = puVar1[1];
          snprintf(acStack_ac,0x80,"DELETE FROM %s WHERE rf_id = %d","rdmngrTable",*puVar1);
          if (((iVar5 != 0) && (iVar2 = FUN_00407d60(iVar2,acStack_ac), iVar2 != 0)) &&
             (iVar5 = FUN_00408410(), iVar5 != 0)) {
            printf("[UAC_QLITE_ERROR]%s()/line %d : ret:%d, sql:%s, \"%s\"\n",
                   "rdmngr_db_sqlite_rd_delete",0x372,iVar2,acStack_ac,
                   "Failed to delete ap entry from table in flash");
          }
        }
        FUN_00407df0(puVar1);
      }
      break;
    default:
      if ((rdmngr_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
        printf("[RDMNGR_DEBUG]%s()/%d unknown msg type:%d.\n","rdmgnr_db_work_task",0x125a,local_b4)
        ;
      }
    }
  } while( true );
  perror("");
  if ((rdmngr_warning_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
    __format = "[RDMNGR_WARNING]%s()/%d receive msgs error\n\n";
    pcVar3 = "rdmgnr_db_work_task";
    uVar4 = 0x123f;
LAB_00619afc:
    printf(__format,pcVar3,uVar4);
  }
  goto LAB_00619958;
}

