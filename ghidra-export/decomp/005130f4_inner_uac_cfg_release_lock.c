// func inner_uac_cfg_release_lock @ 005130f4 size=424

void inner_uac_cfg_release_lock(int param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  char *__format;
  undefined4 uVar4;
  undefined4 uVar5;
  
  pvVar1 = uac_thread_get_tsd(cfg_tsd_key);
  if (uac_cfg_dbg_switch != 0) {
    printf("[UAC_CFG_DEBUG]%s()/line %d : [%s]Release lock\n","inner_uac_cfg_release_lock",0x18c,
           param_2);
  }
  if ((_cfg_run != 0) && (param_1 != 0)) {
    if (param_1 == 2) {
      uac_cfg_trigger_save(3);
    }
    else {
      cfg_modify = 1;
    }
  }
  if (pvVar1 == (void *)0x0) {
    if (uac_cfg_err_switch != 0) {
      printf("[UAC_CFG_ERROR]%s()/line %d : Release lock without tsd.\n",
             "inner_uac_cfg_release_lock",0x1ae);
      return;
    }
  }
  else {
    iVar2 = *(int *)((int)pvVar1 + 0x14);
    if (iVar2 < 1) {
      if (uac_cfg_err_switch == 0) {
        return;
      }
      uVar3 = *(undefined4 *)((int)pvVar1 + 0x10);
      uVar4 = 0x1aa;
      uVar5 = *(undefined4 *)((int)pvVar1 + 0xc);
      __format = "[UAC_CFG_ERROR]%s()/line %d : Count error: Tid: %p, Lock state: %d, count: %d\n";
    }
    else {
      iVar2 = iVar2 + -1;
      *(int *)((int)pvVar1 + 0x14) = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)((int)pvVar1 + 0x10) = 0;
      }
      if (uac_cfg_dbg_switch == 0) {
        return;
      }
      uVar4 = 0x1a6;
      uVar3 = *(undefined4 *)((int)pvVar1 + 0x10);
      __format = "[UAC_CFG_DEBUG]%s()/line %d : Tid: %p, Lock state: %d, count: %d\n";
      uVar5 = *(undefined4 *)((int)pvVar1 + 0xc);
    }
    printf(__format,"inner_uac_cfg_release_lock",uVar4,uVar5,uVar3,iVar2);
  }
  return;
}

