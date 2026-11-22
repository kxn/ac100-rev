// func rrm_acs_timeout @ 004aa7a0 size=256

void rrm_acs_timeout(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = get_acs_process_state();
  if (iVar1 == 1) {
    if (rrm_acs_time < 10) {
      rrm_acs_time = rrm_acs_time + 1;
      iVar1 = get_acs_timeout();
      rrm_acs_timer = FUN_00408340(iVar1 + 6,0,rrm_acs_timeout,0,0,"rrm_acs_timeout",0x5f0);
      if (rrm_acs_timer != -1) {
        return;
      }
      rrm_db_state_set(8);
      goto LAB_004aa7f0;
    }
    rrm_db_state_set(8);
    uVar3 = 0x397a;
    uVar2 = 0x3974;
  }
  else {
    rrm_db_state_set(8);
    uVar3 = 0x3979;
    uVar2 = 0x3973;
  }
  if (rrm_type != 1) {
    uVar2 = uVar3;
  }
  loggerk_reg(0x55,uVar2,0);
LAB_004aa7f0:
  FUN_004081c0(rrm_signal);
  return;
}

