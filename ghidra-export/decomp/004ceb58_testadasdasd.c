// func testadasdasd @ 004ceb58 size=1

void testadasdasd(void)

{
  byte bStack_58;
  byte bStack_57;
  byte bStack_56;
  byte bStack_55;
  byte bStack_54;
  byte bStack_53;
  undefined1 auStack_50 [12];
  char acStack_44 [20];
  int iStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_20;
  undefined2 uStack_18;
  
  memcpy(&bStack_58,&UNK_006a806c,6);
  printf("mac: %02x:%02x:%02x:%02x:%02x:%02x\n",(uint)bStack_58,(uint)bStack_57,(uint)bStack_56,
         (uint)bStack_55,(uint)bStack_54,(uint)bStack_53);
  memset(auStack_50,0,0x3c);
  strcpy(acStack_44,"455CFFFFFFD0FFFF");
  uStack_18 = 0;
  uStack_28 = 0x13157fd;
  uStack_20 = 0xffffffe2;
  iStack_30 = wips_local_time_get();
  iStack_2c = iStack_30 + 3;
  wips_entry_add(&bStack_58,&UNK_006a7df0,1,auStack_50,&UNK_006a7df8);
  strcpy(acStack_44,"455CFFFFFFD0FFFE");
  iStack_30 = iStack_30 + -10;
  wips_entry_add(&bStack_58,&UNK_006a7df0,1,auStack_50,&UNK_006a7df8);
  strcpy(acStack_44,"455CFFFFFFD0FFFD");
  uStack_28 = 0x1315804;
  wips_entry_add(&bStack_58,&UNK_006a7df0,1,auStack_50,&UNK_006a7e34);
  return;
}

