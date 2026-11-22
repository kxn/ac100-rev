// func uac_cfg_trigger_modify @ 00512fc0 size=1

void uac_cfg_trigger_modify(void)

{
  int iVar1;
  int iVar2;
  int in_t9;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar2 = *(int *)(in_t9 + 0x2463ec);
  if (*(int *)(iVar2 + 0x1a74) != 0) {
    if (**(int **)(in_t9 + 0x2463e4) != 0) {
      (**(code **)(in_t9 + 0x246910))
                (*(int *)(in_t9 + 0x246168) + 0x950,*(int *)(in_t9 + 0x246168) + 0xbe4,0x1b9);
    }
    iVar1 = *(int *)(in_t9 + 0x246168);
    UNRECOVERED_JUMPTABLE = *(code **)(in_t9 + 0x24677c);
    *(undefined4 *)(iVar2 + 0x1a74) = 0;
                    /* WARNING: Could not recover jumptable at 0x00513010. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(iVar1 + 0x7c0);
    return;
  }
  return;
}

