// func uac_cfg_tsd_dump @ 005132b8 size=1

void uac_cfg_tsd_dump(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_t9;
  
  iVar3 = *(int *)(in_t9 + 0x2460f4);
  (**(code **)(in_t9 + 0x2465f4))(iVar3 + 0x1a48);
  iVar1 = uac_list_first(*(int *)(in_t9 + 0x2460f4) + 0x1a60);
  iVar4 = *(int *)(in_t9 + 0x245e70);
  while (iVar1 != 0) {
    iVar2 = uac_list_next(iVar1);
    (**(code **)(in_t9 + 0x246618))
              (iVar4 + 0xac4,*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10),
               *(undefined4 *)(iVar1 + 0x14));
    iVar1 = iVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x00513370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(in_t9 + 0x246514))(iVar3 + 0x1a48);
  return;
}

