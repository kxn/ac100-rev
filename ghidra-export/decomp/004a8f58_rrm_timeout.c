// func rrm_timeout @ 004a8f58 size=72

void rrm_timeout(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = rrm_db_state_get();
  uVar2 = 5;
  if (iVar1 == 1) {
    uVar2 = 2;
  }
  rrm_db_state_set(uVar2);
  FUN_004081c0(rrm_signal);
  rrm_collect_timer = 0xffffffff;
  return;
}

