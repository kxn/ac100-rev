// func _apmngr_db_sqlite_hdap_insert @ 00546fb0 size=824

undefined4 _apmngr_db_sqlite_hdap_insert(ushort *param_1)

{
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  ushort *__dest;
  char acStack_818 [1024];
  undefined1 auStack_418 [1024];
  
  __dest = param_1 + 0x2f;
  puVar7 = param_1 + 8;
  memset(acStack_818,0,0x800);
  param_1[0x10] = *param_1;
  param_1[0x154] = param_1[1];
  pcVar1 = (char *)apmngr_hdap_postfix_get(1);
  pcVar2 = (char *)apmngr_hdap_postfix_get(1);
  sVar3 = strlen(pcVar2);
  strncat((char *)__dest,pcVar1,sVar3);
  iVar4 = _apmngr_ap_cfg_insert_sql_gene(acStack_818,0x400,puVar7);
  if (-1 < iVar4) {
    param_1[0x10] = param_1[1];
    param_1[0x154] = *param_1;
    sVar3 = strlen((char *)__dest);
    *(undefined1 *)((int)param_1 + sVar3 + 0x5b) = 0;
    pcVar1 = (char *)apmngr_hdap_postfix_get(2);
    pcVar2 = (char *)apmngr_hdap_postfix_get(2);
    sVar3 = strlen(pcVar2);
    strncat((char *)__dest,pcVar1,sVar3);
    memcpy(param_1 + 0x2c,param_1 + 2,6);
    param_1[0x9a] = 0xffff;
    param_1[0x9b] = 0xffff;
    param_1[0xe4] = 0xffff;
    param_1[0xe5] = 0xffff;
    iVar4 = _apmngr_ap_cfg_insert_sql_gene(auStack_418,0x400,puVar7);
    if (-1 < iVar4) {
      puVar6 = &g_apmngr_db + (*(int *)(param_1 + 0x26) != 1);
      iVar4 = FUN_00408230(*puVar6);
      if ((((iVar4 == 0) && (iVar4 = FUN_00407d60(*puVar6,acStack_818), iVar4 == 0)) &&
          (iVar4 = FUN_00407d60(*puVar6,auStack_418), iVar4 == 0)) &&
         (iVar4 = FUN_00408320(*puVar6), iVar4 == 0)) {
        param_1[0x10] = *param_1;
        iVar4 = _apmngr_ap_run_insert_sql_gene(acStack_818,0x400,puVar7);
        if (-1 < iVar4) {
          param_1[0x10] = param_1[1];
          iVar4 = _apmngr_ap_run_insert_sql_gene(auStack_418,0x400,puVar7);
          if (((-1 < iVar4) && (iVar4 = FUN_00408230(DAT_007c58e8), iVar4 == 0)) &&
             ((iVar4 = FUN_00407d60(DAT_007c58e8,acStack_818), iVar4 == 0 &&
              ((iVar4 = FUN_00407d60(DAT_007c58e8,auStack_418), iVar4 == 0 &&
               (iVar4 = FUN_00408320(DAT_007c58e8), iVar4 == 0)))))) {
            return 0;
          }
        }
        if (apmngr_err_switch == '\0') {
          iVar4 = *(int *)(param_1 + 0x26);
        }
        else {
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            iVar4 = *(int *)(param_1 + 0x26);
          }
          else {
            printf("[APMNGR_ERROR]%s()/%d Failed to insert the run-entries for hd_ap, roll back.\n",
                   "_apmngr_db_sqlite_hdap_insert",0x408);
            iVar4 = *(int *)(param_1 + 0x26);
          }
        }
        if (iVar4 == 1) {
          pcVar1 = "ApEntryCfg_table";
        }
        else {
          pcVar1 = "ApEntryTmpCfg_table";
        }
        snprintf(acStack_818,0x400,"DELETE FROM %s WHERE entry_id = %d or entry_id = %d;",pcVar1,
                 (uint)*param_1,(uint)param_1[1]);
        iVar4 = FUN_00407d60((&g_apmngr_db)[iVar4 != 1],acStack_818);
        if (iVar4 != 0) {
          if (apmngr_err_switch == '\0') {
            return 0xffffffff;
          }
          iVar4 = is_target_debug_ap();
          if (iVar4 == 0) {
            return 0xffffffff;
          }
          pcVar1 = 
          "[APMNGR_ERROR]%s()/%d Severe Error: delete ap-cfg-entry failed even when roll back.\n";
          uVar5 = 0x40f;
LAB_00547258:
          printf(pcVar1,"_apmngr_db_sqlite_hdap_insert",uVar5);
          return 0xffffffff;
        }
      }
      else if ((apmngr_err_switch != '\0') && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        pcVar1 = "[APMNGR_ERROR]%s()/%d Failed to insert the cfg-entries for hd_ap.\n";
        uVar5 = 0x3ec;
        goto LAB_00547258;
      }
    }
  }
  return 0xffffffff;
}

