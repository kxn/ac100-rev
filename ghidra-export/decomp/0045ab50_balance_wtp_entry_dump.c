// func balance_wtp_entry_dump @ 0045ab50 size=136

void balance_wtp_entry_dump(undefined4 *param_1)

{
  if ((param_1 != (undefined4 *)0x0) && (param_1[1] != 0)) {
    printf("wtp index: %d\n",*param_1);
    printf("wtp mac: %02x:%02x:%02x:%02x:%02x:%02x\n",(uint)*(byte *)(param_1 + 2),
           (uint)*(byte *)((int)param_1 + 9),(uint)*(byte *)((int)param_1 + 10),
           (uint)*(byte *)((int)param_1 + 0xb),(uint)*(byte *)(param_1 + 3),
           (uint)*(byte *)((int)param_1 + 0xd));
    printf("station size: %u\n\n",param_1[4]);
    return;
  }
  return;
}

