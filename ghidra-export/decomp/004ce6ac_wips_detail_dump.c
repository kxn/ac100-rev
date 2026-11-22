// func wips_detail_dump @ 004ce6ac size=120

void wips_detail_dump(int param_1)

{
  undefined1 auStack_48 [28];
  undefined1 auStack_2c [32];
  
  wips_time2str(*(undefined4 *)(param_1 + 0x20),auStack_2c);
  wips_time2str(*(undefined4 *)(param_1 + 0x24),auStack_48);
  printf("\t%s %d\t[%s - %s]\t%ddBm\t%d\t%d\n",param_1 + 0xc,*(undefined4 *)(param_1 + 0x28),
         auStack_2c,auStack_48,*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34),
         (uint)*(ushort *)(param_1 + 0x38));
  return;
}

