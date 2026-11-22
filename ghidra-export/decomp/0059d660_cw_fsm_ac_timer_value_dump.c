// func cw_fsm_ac_timer_value_dump @ 0059d660 size=1

void cw_fsm_ac_timer_value_dump(void)

{
  undefined **ppuVar1;
  int iVar2;
  int iVar3;
  
  ppuVar1 = &PTR_s__TIMER_NONE__006e4ae8;
  iVar2 = 0;
  do {
    iVar3 = iVar2 + 4;
    printf("timer[%s]:\t%d\n",ppuVar1[1],*(undefined4 *)(iVar2 + 0x74cfb0));
    ppuVar1 = (undefined **)((int)&PTR_s_WAIT_DTLS_006e4aec + iVar2);
    iVar2 = iVar3;
  } while (iVar3 != 0x28);
  return;
}

