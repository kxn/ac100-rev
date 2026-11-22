// func cw_priv_ap_working_channel_list_dump @ 005aab5c size=200

undefined4 cw_priv_ap_working_channel_list_dump(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0x10);
  printf("\t\tType: (t=%d,l=%d) ap working channel list\r\n",(uint)*(ushort *)(param_1 + 0xc),
         (uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tType: ap working channel list(%d) \r\n",(uint)*(ushort *)(param_1 + 0xc));
  iVar2 = 0;
  printf("\t\t\tLength: %d \r\n",(uint)*(ushort *)(param_1 + 0xe));
  printf("\t\t\tValue: %08x... \r\n",*puVar3);
  printf("\t\t\tchannel list: ");
  puVar1 = puVar3;
  do {
    iVar2 = iVar2 + -4;
    printf("%08x",puVar1[5]);
    puVar1 = (undefined4 *)((int)puVar3 + iVar2);
  } while (iVar2 != -0x18);
  puts("\r");
  return 0;
}

