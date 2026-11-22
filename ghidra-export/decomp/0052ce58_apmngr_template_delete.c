// func apmngr_template_delete @ 0052ce58 size=244

void apmngr_template_delete(undefined2 *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined1 auStack_2f8 [732];
  
  memset(auStack_2f8,0,0x2d8);
  if ((param_1 != (undefined2 *)0x0) && (0 < param_2)) {
    iVar3 = 0;
    puVar2 = param_1;
    do {
      iVar1 = apmngr_db_entry_get_by_id(*puVar2,auStack_2f8);
      if (iVar1 == 0) {
        apmngr_evt_notify(1,auStack_2f8);
        apmngr_evt_notify(3,auStack_2f8);
        apmngr_db_template_delete(*puVar2);
        apmngr_db_id_free(0,*puVar2);
      }
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 != param_2);
    if (param_3 != 0) {
      apmngr_db_sync_ap_entry_del(param_1,iVar3,1);
      apmngr_db_datasync_ap_entry_del(param_1,iVar3,1);
    }
  }
  return;
}

