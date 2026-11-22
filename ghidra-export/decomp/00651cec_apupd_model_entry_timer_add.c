// func apupd_model_entry_timer_add @ 00651cec size=372

undefined4 apupd_model_entry_timer_add(int param_1)

{
  time_t tVar1;
  time_t tVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  tm tStack_48;
  
  memset(&tStack_48,0,0x2c);
  apupd_local_time_get(&tStack_48);
  tVar1 = mktime((tm *)(param_1 + 0x150));
  tVar2 = mktime(&tStack_48);
  puVar3 = (undefined4 *)FUN_00408450(4,0xac9);
  if (puVar3 == (undefined4 *)0x0) {
    uVar5 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: malloc failed.\r\n","apupd_model_entry_timer_add",0xacc);
    }
  }
  else {
    *(undefined1 *)puVar3 = 0;
    *(undefined1 *)((int)puVar3 + 1) = 0;
    *(undefined1 *)((int)puVar3 + 2) = 0;
    *(undefined1 *)((int)puVar3 + 3) = 0;
    *puVar3 = *(undefined4 *)(param_1 + 0x58);
    iVar4 = 1;
    if (tVar2 < tVar1) {
      iVar4 = tVar1 - tVar2;
    }
    iVar4 = FUN_00408340(iVar4,0,apupd_update_model_timer_callback,puVar3,
                         apupd_update_model_timer_argv_callback,"apupd_model_entry_timer_add",0xad9)
    ;
    *(int *)(param_1 + 0x13c) = iVar4;
    uVar5 = 0;
    if (iVar4 == -1) {
      if ((g_apupd_error != 0) && (iVar4 = is_target_debug_ap(), iVar4 != 0)) {
        printf("[APUPD_ERROR]%32s() %05d: add timer failed.\r\n","apupd_model_entry_timer_add",0xadc
              );
      }
      FUN_00407df0(puVar3);
      uVar5 = 0xffffffff;
    }
  }
  return uVar5;
}

