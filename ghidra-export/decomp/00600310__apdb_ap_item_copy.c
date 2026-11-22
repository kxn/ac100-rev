// func _apdb_ap_item_copy @ 00600310 size=500

void _apdb_ap_item_copy(void *param_1,void *param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  char *__format;
  int iVar4;
  
  if (((param_1 == (void *)0x0) || (param_2 == (void *)0x0)) || (iVar4 = 0, param_3 < 1)) {
    if (apdb_debug_switch != 0) {
      __format = "[APDB_DEBUG]%s()/line %d : input para is NULL!\n";
      uVar3 = 0x412;
LAB_006004d8:
      printf(__format,"_apdb_ap_item_copy",uVar3);
      return;
    }
  }
  else {
    uVar3 = *(undefined4 *)((int)param_1 + 0x50);
    pvVar2 = param_1;
    while( true ) {
      iVar4 = iVar4 + 1;
      _apdb_ap_fwid_hash_free(uVar3);
      _apdb_ap_free(*(undefined4 *)((int)pvVar2 + 0x54),*(undefined4 *)((int)pvVar2 + 0x4c));
      if (iVar4 == param_3) break;
      uVar3 = *(undefined4 *)((int)pvVar2 + 0xa8);
      pvVar2 = (void *)((int)pvVar2 + 0x58);
    }
    iVar4 = 0;
    memcpy(param_1,param_2,param_3 * 0x58);
    do {
      iVar1 = _apdb_fwid_hash_init((int)param_1 + 0x50);
      if (iVar1 != 0) {
        if (apdb_err_switch == 0) {
          return;
        }
        __format = "[APDB_ERROR]%s()/line %d : init hash failed!\n";
        uVar3 = 0x426;
        goto LAB_006004d8;
      }
      FUN_00408570(*(undefined4 *)((int)param_2 + 0x50),_apdb_ap_fwid_hash_copy,
                   *(undefined4 *)((int)param_1 + 0x50));
      if (0 < *(int *)((int)param_1 + 0x4c)) {
        pvVar2 = (void *)FUN_00408450(*(int *)((int)param_1 + 0x4c) * 0x168,0x42f);
        *(void **)((int)param_1 + 0x54) = pvVar2;
        if (pvVar2 == (void *)0x0) {
          if (apdb_err_switch == 0) {
            *(undefined4 *)((int)param_1 + 0x4c) = 0;
          }
          else {
            printf("[APDB_ERROR]%s()/line %d : apdb malloc error.\n","_apdb_ap_item_copy",0x432);
            *(undefined4 *)((int)param_1 + 0x4c) = 0;
          }
        }
        else {
          memset(pvVar2,0,*(int *)((int)param_1 + 0x4c) * 0x168);
          _apdb_ap_copy(*(undefined4 *)((int)param_1 + 0x54),*(undefined4 *)((int)param_2 + 0x54),
                        *(undefined4 *)((int)param_1 + 0x4c));
        }
      }
      iVar4 = iVar4 + 1;
      param_1 = (void *)((int)param_1 + 0x58);
      param_2 = (void *)((int)param_2 + 0x58);
    } while (iVar4 != param_3);
  }
  return;
}

