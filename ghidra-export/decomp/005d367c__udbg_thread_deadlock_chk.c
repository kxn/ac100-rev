// func _udbg_thread_deadlock_chk @ 005d367c size=220

undefined4 _udbg_thread_deadlock_chk(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_48 [24];
  void *local_30;
  undefined4 local_28;
  
  memset(auStack_48,0,0x34);
  iVar1 = tnp_cnt;
  iVar2 = *(int *)(param_1 + 0x30);
  if ((*(int *)(param_1 + 0x38) == 0) || (iVar2 != *(int *)(param_1 + 0x38))) {
    *(int *)(param_1 + 0x38) = iVar2;
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x34);
  }
  else if ((*(int *)(param_1 + 0x34) == *(int *)(param_1 + 0x3c)) &&
          (iVar2 = FUN_004085f0(iVar2,auStack_48), iVar2 == 0)) {
    _udbg_thread_tnp_insert(*(undefined4 *)(param_1 + 0x2c));
    _udbg_thread_tnp_insert(local_28);
    if ((iVar1 == 0) && (0 < tnp_cnt)) {
      puts("\n===================Warning: Possible Deadlock Detected==================");
    }
    printf("Thread \"%s\" pend due to take Mutex [\"%s\", owner=%p]\n",param_1 + 4,local_30,local_28
          );
    free(local_30);
  }
  return 0;
}

